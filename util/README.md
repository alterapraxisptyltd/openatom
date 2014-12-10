Utilities
=========

## convert.sh ##

Converts AtomDis output to C code.

Usage:

> $ ./convert.sh inputfile > outputfile.c

## cb2replay.sh ##

Converts a coreboot VGABIOS backtrace to replay C code.

Any complete coreboot log may be used, as the script automatically trims out
lines not related to the replay. There is no need to manually trim the log.
cbmem -c output may be piped to this script.

In order for this to cork properly, coreboot must be compiled with the following
options:

* PCI_OPTION_ROM_RUN_YABEL
* YABEL_DIRECTHW

Usage:

> $ ./cb2replay.sh coreboot.log > replay.c
