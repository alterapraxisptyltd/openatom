sed "s/.*\0125.*MOVE.*reg\[\([0-9,a-f]*\)][^0-9,a-f]*\([0-9,a-f]*\)/\tmy_radeon_write8\(0x\1, BYTE_0, 0x\2\);/g" $1 |
sed "s/.*\0165.*MOVE.*reg\[\([0-9,a-f]*\)][^0-9,a-f]*\([0-9,a-f]*\)/\tmy_radeon_write8\(0x\1, BYTE_1, 0x\2\);/g" |
sed "s/.*\01a5.*MOVE.*reg\[\([0-9,a-f]*\)][^0-9,a-f]*\([0-9,a-f]*\)/\tmy_radeon_write8\(0x\1, BYTE_2, 0x\2\);/g" |
sed "s/.*\010d.*MOVE.*reg\[\([0-9,a-f]*\)][^0-9,a-f]*\([0-9,a-f]*\)/\tmy_radeon_write16\(0x\1, BYTES_01, 0x\2\);/g" |
sed "s/.*\018d.*MOVE.*reg\[\([0-9,a-f]*\)][^0-9,a-f]*\([0-9,a-f]*\)/\tmy_radeon_write16\(0x\1, BYTES_23, 0x\2\);/g" |
sed "s/.*\0105.*MOVE.*reg\[\([0-9,a-f]*\)][^0-9,a-f]*\([0-9,a-f]*\)/\tmy_radeon_write32\(0x\1, 0x\2\);/g" |
sed "s/.*52.*CALL_TABLE.*(\([0-9,a-z,_,/,A-Z]*\))/\tmy_exec_table(\1);/g" |
sed "s/.*51.*DELAY_MicroSec[^0-9,a-f]*\([0-9,a-f]*\)/\tmy_udelay(0x\1);/g" |
sed "s/.*5b.*EOT.*/\treturn;\n}/g" |
sed "s/.*0d25.*OR.*reg\[\([0-9,a-f]*\)][^0-9,a-f]*\([0-9,a-f]*\)/\tmy_radeon_or8\(0x\1, BYTE_0, 0x\2\);/g" |
sed "s/.*0d65.*OR.*reg\[\([0-9,a-f]*\)][^0-9,a-f]*\([0-9,a-f]*\)/\tmy_radeon_or8\(0x\1, BYTE_1, 0x\2\);/g" |
sed "s/.*0da5.*OR.*reg\[\([0-9,a-f]*\)][^0-9,a-f]*\([0-9,a-f]*\)/\tmy_radeon_or8\(0x\1, BYTE_2, 0x\2\);/g" |
sed "s/.*0de5.*OR.*reg\[\([0-9,a-f]*\)][^0-9,a-f]*\([0-9,a-f]*\)/\tmy_radeon_or8\(0x\1, BYTE_3, 0x\2\);/g" |
sed "s/.*0d0d.*OR.*reg\[\([0-9,a-f]*\)][^0-9,a-f]*\([0-9,a-f]*\)/\tmy_radeon_or16\(0x\1, BYTES_01, 0x\2\);/g" |
sed "s/.*0d05.*OR.*reg\[\([0-9,a-f]*\)][^0-9,a-f]*\([0-9,a-f]*\)/\tmy_radeon_or32\(0x\1, 0x\2\);/g" |
sed "s/.*0725.*AND.*reg\[\([0-9,a-f]*\)][^0-9,a-f]*\([0-9,a-f]*\)/\tmy_radeon_and8\(0x\1, BYTE_0, 0x\2\);/g" |
sed "s/.*0765.*AND.*reg\[\([0-9,a-f]*\)][^0-9,a-f]*\([0-9,a-f]*\)/\tmy_radeon_and8\(0x\1, BYTE_1, 0x\2\);/g" |
sed "s/.*07a5.*AND.*reg\[\([0-9,a-f]*\)][^0-9,a-f]*\([0-9,a-f]*\)/\tmy_radeon_and8\(0x\1, BYTE_2, 0x\2\);/g" |
sed "s/.*07e5.*AND.*reg\[\([0-9,a-f]*\)][^0-9,a-f]*\([0-9,a-f]*\)/\tmy_radeon_and8\(0x\1, BYTE_3, 0x\2\);/g" |
sed "s/.*070d.*AND.*reg\[\([0-9,a-f]*\)][^0-9,a-f]*\([0-9,a-f]*\)/\tmy_radeon_and16\(0x\1, BYTES_01, 0x\2\);/g" |
sed "s/.*5420.*CLEAR.*reg\[\([0-9,a-f]*\)][^0-9,a-f]*/\tmy_radeon_write8\(0x\1, BYTE_0, 0);/g" |
sed "s/.*5428.*CLEAR.*reg\[\([0-9,a-f]*\)][^0-9,a-f]*/\tmy_radeon_write8\(0x\1, BYTE_1, 0);/g" |
sed "s/.*5430.*CLEAR.*reg\[\([0-9,a-f]*\)][^0-9,a-f]*/\tmy_radeon_write8\(0x\1, BYTE_2, 0);/g" |
sed "s/.*5408.*CLEAR.*reg\[\([0-9,a-f]*\)][^0-9,a-f]*/\tmy_radeon_write16\(0x\1, BYTES_01, 0);/g" |
sed "s/.*5400.*CLEAR.*reg\[\([0-9,a-f]*\)][^0-9,a-f]*/\tmy_radeon_write32\(0x\1, 0);/g"
