#!/usr/bin/perl

#
# Copyright 2007 Matthias Hopf <mhopf@suse.de>
#
# AtomBIOS disassembler + data structure dumper
#
# datastructs_factory.pl:
# Datastruct dumper generator (using atombios.h).
#
# License: GPL Version 2.0
# License of generated code: Same as license of input source (atombios.h)
#


while (<>) {
    $l++;
    # #pragma count  ATOM_POWERPLAY_INFO_V4 asPowerIndexInfo (d->NumPowerIndexEntries)
    # #pragma offset ATOM_POWERPLAY_INFO_V4 asPowerIndexInfo (data + d->OffsetPowerIndexEntries + i*d->SizeOfPowerIndexEntry)
    # #pragma return ATOM_POWERPLAY_INFO_V4 -                (d->OffsetPowerUnknownEntries + ATOM_MAX_NUMBEROF_POWERUNKNOWN_BLOCK_V4*d->SizeOfPowerUnknownEntry)
    if (/^\s*#\s*pragma\s+(\S+)\s+(\S+)\s+(\S+)\s+(.*?)\s*$/) {
	$t = $1;
	$s = $2;
	$v = $3;
	$r = $4;
	if ($t eq "count") {
	    ${$count{$s}}{$v} = $r;
	    next;
	} elsif ($t eq "offset") {
	    ${$offset{$s}}{$v} = $r;
	    next;
	} elsif ($t eq "return") {
	    $return{$s} = $r;
	    next;
	} else {
	    chomp;
	    print STDERR "Unknown $_ in line $l\n";
	}
    }
    next if /^\s*#/;
    if (/^\s*typedef\s+(struct|union)\s+_(\w+)/) {
	$t = $1;
	$tv= $t eq "union" ? "(union) " : "";
	$s = $2;
	print STDERR "  $t $2\n";
	print "int ${s}_dumper (uint8_t *start, uint8_t *data, int indent) {\n";
	print "  $s *d = ($s *) data;\n";
	print "  int i;\n";
	print "  if (d) {\n";
	while (<>) {
	    $l++;
	    next if /^#/;
	    chomp;
	    s|\s*//.*||g;
	    next if /^\s*\{\s*$/ || /^\s*$/;
	    last if /\}/;
	    while (/\[([^\]]+)\]/g) {
	        $expr=$1;
		if ($expr !~ /^\d+$/) {
	            print STDERR "    Trying to evaluate $1...\n";
		    $res = eval $expr;
		    if (! defined $res) {
		        print STDERR "      $@\n";
		    } else {
		        print STDERR "      -> $res\n";
		        s/\[[^\]]+\]/[$res]/;
		    }
		}
	    }
	    if (/^\s*(\w+)\s+(\w+)(\s*(:\d+))?(\s*\[(\d+)\])?\s*;/) {
		$e = $1;
		$n = $2;
		$b = $4;
		$a = ${$count{$s}}{$n};
		$a = $6 if $a eq "";
		if ($a eq "" || $a eq "0") {
		    $loop_dst = ${$offset{$s}}{$n};
		    $loop_dst = "d->$n" if $loop_dst eq "";
		    $loop_beg = "    printf (\"%s";
		    $loop_beg.= "%04x:  " if $b eq "";
		    $loop_beg.= "       " if $b ne "";
		    $loop_beg.= "$tv$e $n$b%s";
		    $loop_arg = ", IND(indent)";
		    $loop_arg.= ", (int)(((uint8_t*)&$loop_dst)-start)" if $b eq "";
		    $loop_arg.= ", FILL(".length($tv.$e.$n.$b).")";
		    $loop_end = "";
		} else {
		    $loop_dst = ${$offset{$s}}{$n};
		    $loop_dst = "d->${n}[i]" if $loop_dst eq "";
		    $loop_beg = "    for (i = 0; i < $a; i++) {\n      printf (\"%s";
		    $loop_beg.= "%04x:  " if $b eq "";
		    $loop_beg.= "       " if $b ne "";
		    $loop_beg.= "$tv$e $n$b%s [%d]";
		    $loop_arg = ", IND(indent)";
		    $loop_arg.= ", (int)(((uint8_t*)&$loop_dst)-start)" if $b eq "";
		    $loop_arg.= ", FILL(".(length($tv.$e.$n.$b)+4)."+(i>9)), i";
		    $loop_end = " }";
		}
		if ($e eq "UCHAR") {
		    print "$loop_beg = 0x%02x       (%d)\\n\"$loop_arg, $loop_dst, $loop_dst);$loop_end\n";
		} elsif ($e eq "USHORT") {
		    print "$loop_beg = 0x%04x     (%d)\\n\"$loop_arg, $loop_dst, $loop_dst);$loop_end\n";
		} elsif ($e eq "U16") {
		    print "$loop_beg = 0x%04x     (%d)\\n\"$loop_arg, _U16($loop_dst), _U16($loop_dst));$loop_end\n";
		} elsif ($e eq "U24") {
		    print "$loop_beg = 0x%06x   (%d)\\n\"$loop_arg, _U24($loop_dst), _U24($loop_dst));$loop_end\n";
		} elsif ($e eq "ULONG") {
		    print "$loop_beg = 0x%08x (%d)\\n\"$loop_arg, $loop_dst, $loop_dst);$loop_end\n";
		} elsif ($e eq "char") {
		    print "$loop_beg = 0x%02x '%c'   (%d)\\n\"$loop_arg, $loop_dst, $loop_dst, $loop_dst);$loop_end\n";
		} else {
		    if ($b ne "") {
			s/"/''/g;
			print "    printf (\"%s  <unparsable> line $l: $_\\n%sskipping...\\n\", IND(indent), IND(indent));\n";
			last;
		    } else {
			print "$loop_beg :\\n\"$loop_arg); ${e}_dumper (start, (uint8_t*) &$loop_dst, indent+1);$loop_end\n";
		    }
		}
	    } else {
		s/"/''/g;
		print "    printf (\"%s  <unparsable> line $l: $_\\n%sskipping...\\n\", IND(indent), IND(indent));\n";
		last;
	    }
	}
	print "  }\n";
	if (defined $return{$s}) {
	    print "  return ".$return{$s}.";\n}\n";
	} else {
	    print "  return sizeof ($s);\n}\n";
	}
    }
}
