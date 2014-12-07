/*
 * Copyright 2007 Matthias Hopf <mhopf@suse.de>
 *
 * AtomBIOS disassembler + data structure dumper
 *
 * indices.h:
 * Symbol indices creation + access functions.
 *
 * License: GPL Version 2.0
 */

#ifndef INDICES_H_
#define INDICES_H_

enum IndexName {
    INDEX_NONE = 0, INDEX_COMMAND_TABLE, INDEX_DATA_TABLE, INDEX_ATI_PORT,
    INDEX_WORK_REG,
    /* INDEX_REG_MM .. INDEX_REG_PCIE have to match SET_ATI_PORT operands */
    INDEX_REG_MM, INDEX_REG_PLL, INDEX_REG_MC, INDEX_REG_PCIE,
    INDEX_REG_PCICONFIG, INDEX_REG_SYSTEMIO,
    INDEXTABLE_SIZEOF
} ;

typedef struct index_table_s {
    const char  *name;
    const char **tab;
    int          len;
} index_table_t;

extern index_table_t index_tables[];

extern const char *get_index (int type, int val);

extern void index_load_registers (const char *file);

#endif
