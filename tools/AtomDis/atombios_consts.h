/*
 * Copyright 2007 Matthias Hopf <mhopf@suse.de>
 *
 * AtomBIOS disassembler + data structure dumper
 *
 * atombios_consts.h:
 * Constants not defined in atombios.h.
 *
 * License: GPL Version 2.0
 */

#ifndef ATOMBIOS_CONSTS_H_
#define ATOMBIOS_CONSTS_H_

enum { WS_QUOTIENT = 0x40, WS_PRODUCT_LOW32 = WS_QUOTIENT,
       WS_REMINDER, WS_PRODUCT_HI32_XXX = WS_REMINDER,
       WS_DATAPTR, WS_SHIFT, WS_OR_MASK, WS_AND_MASK, WS_FB_WINDOW,
       WS_ATTRIBUTES, WS_REGPTR } ;

#endif
