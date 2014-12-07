sed "s/.*\0105.*MOVE.*reg\[\([0-9,a-f]*\)][^0-9,a-f]*\([0-9,a-f]*\)/\tmy_radeon_write32\(0x\1, 0x\2\);/g" $1 |
sed "s/.*52.*CALL_TABLE.*(\([a-z,A-Z]*\))/\tmy_exec_table(\1);/g"
