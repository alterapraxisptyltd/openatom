
void shitmapants(void)
{
	#ifdef ZEEEROOOOOOOOO_PUSH_UPS_READY_MOVE
	uint8_t ldat[] = {
		/* PHY 0 */
		0x02, 0x20, 0x23, 0x01, 0x11, 0x00, 0x13, 0x01,
		0x48, 0x80, 0x33, 0x01, 0x00, 0x01, 0x02, 0x03,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x02, 0x06,
		/* PHY 1 */
		0x02, 0x20, 0x21, 0x01, 0x11, 0x00, 0x11, 0x01,
		0x49, 0x80, 0x31, 0x01, 0x00, 0x01, 0x02, 0x03,
		0x10, 0x00, 0x00, 0x00, 0x00, 0x02, 0x03, 0x01,
		/* PHY 2 */
		0x02, 0x20, 0x21, 0x02, 0x11, 0x00, 0x11, 0x02,
		0x4a, 0x80, 0x31, 0x01, 0x00, 0x01, 0x02, 0x03,
		0x20, 0x00, 0x00, 0x00, 0x00, 0x08, 0x04, 0x02,
		/* PHY 3 */
		0x02, 0x20, 0x21, 0x02, 0x11, 0x00, 0x11, 0x02,
		0x4b, 0x80, 0x31, 0x01, 0x00, 0x01, 0x02, 0x03,
		0x30, 0x00, 0x00, 0x00, 0x00, 0x08, 0x05, 0x03,
		/* PHY 4 */
		0x02, 0x20, 0x22, 0x01, 0x11, 0x00, 0x12, 0x01,
		0x4c, 0x80, 0x32, 0x01, 0x00, 0x01, 0x02, 0x03,
		0x40, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x04,
		/* PHY 5 */
		0x02, 0x20, 0x22, 0x01, 0x11, 0x00, 0x12, 0x01,
		0x4d, 0x80, 0x32, 0x01, 0x00, 0x01, 0x02, 0x03,
		0x50, 0x00, 0x00, 0x00, 0x00, 0x10, 0x01, 0x05,
		/* [0x90]  WS_DATAPTR [..XX]  <-  916 */
		0x05, 0x20, 0x21, 0x01, 0x10, 0x00, 0x02, 0x60,
		/* [0x98] */
		0x05, 0x20, 0x23, 0x01, 0x20, 0x00, 0x08, 0x40,
		0x05, 0x20, 0x22, 0x01, 0x00, 0x00, 0x10, 0x40,
		/* [0xa8] ] WS_DATAPTR [..XX]  <-  92e */
		0x0c, 0x00, 0xff, 0xff, 0x02, 0x0e, 0x00, 0x0b,
		0x00, 0x0b, 0x00, 0x0b, 0x00, 0x0b, 0xff, 0xff,
		/* [0xb8] */
		0x02, 0x31, 0x00, 0x0b, 0x00, 0x0b, 0x00, 0x0b,
		0x00, 0x0b, 0xff, 0xff, 0x03, 0x0e, 0x00, 0x2a,
		0x00, 0x2a, 0x00, 0x2a, 0x00, 0x2a, 0xff, 0xff,
		/* [0xd0] */
		0x03, 0x31, 0x00, 0x0b, 0x00, 0x0b, 0x00, 0x0b,
		0x00, 0x0b, /* start 960 */0x35, 0x0c, 0x00, 0x06, 0x1d, 0x10,
		/* [0xe0] */
		0x01, 0x06, 0x88, 0x13, 0x02, 0x06, 0x6a, 0x18,
		0x03, 0x06, 0xbd, 0x1f, 0x04, 0x06, 0x10, 0x27,
		/* [0xf0] */
		0x05, 0x06, 0xd4, 0x30, 0x06, 0x06, 0x74, 0x40,
		0x07, 0x06, 0xff, 0xff, 0x08, 0x06, 0x68, 0x42,
		/* [0x10x] */
		0x00, 0x04, 0x78, 0x69, 0x02, 0x04, 0xff, 0xff,
		0x01, 0x04, /* end 960 */ 0x0e, 0x00, 0x09, 0x00, 0x61, 0x00, /* 960 block ends becasue max_sym clock is 0xffff*/
		/* [0x110] : ADD    WS_DATAPTR [..XX]  <-  0996 */
		0x00, 0x55, 0x00, 0x55, 0x00, 0x55, 0x00, 0x55,
		0x00, 0x01, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00,
		0x40, 0x00, 0x02, 0x2a, 0x00, 0x2a, 0x00, 0x2a,
		0x00, 0x2a, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x08, 0x40, 0x15, 0x40,
		0x15, 0x40, 0x15, 0x40, 0x15, 0x09, 0x20, 0x20,
		0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x0a, 0x00,
		0x2a, 0x00, 0x2a, 0x00, 0x2a, 0x00, 0x2a, 0x10,
		0x2a, 0x2a, 0x2a, 0x2a, 0x2a, 0x2a, 0x2a, 0x2a,
		0x11, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00,
		0x40, 0x18, 0x00, 0x55, 0x00, 0x55, 0x00, 0x55,
		0x00, 0x55, 0xff, 0x31, 0x00, 0x09, 0x00, 0x61,
		0x00, 0x00, 0x55, 0x00, 0x55, 0x00, 0x55, 0x00,
		0x55, 0x00, 0x01, 0x40, 0x00, 0x40, 0x00, 0x40,
		0x00, 0x40, 0x00, 0x02, 0x2a, 0x00, 0x2a, 0x00,
		0x2a, 0x00, 0x2a, 0x00, 0x03, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x40, 0x15,
		0x40, 0x15, 0x40, 0x15, 0x40, 0x15, 0x09, 0x20,
		0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x0a,
		0x00, 0x2a, 0x00, 0x2a, 0x00, 0x2a, 0x00, 0x2a,
		0x10, 0x2a, 0x2a, 0x2a, 0x2a, 0x2a, 0x2a, 0x2a,
		0x2a, 0x11, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40,
		0x00, 0x40, 0x18, 0x00, 0x55, 0x00, 0x55, 0x00,
		0x55, 0x00, 0x55, 0xff};
		#endif
		// *tada;
		//uint8_t *dptr;
		//   0006: 370000            SET_ATI_PORT  0000  (INDIRECT_IO_MM)
		//   0009: 03014602          MOVE   WS_FB_WIN [XXXX]  <-  param[02]  [XXXX]
		//   000d: 561846            CLEAR  WS_FB_WIN [XX..]
		// FIXME win = ucDPLaneSet | ucDigEncoderSel;
		//   0010: 66ff              SET_DATA_BLOCK  ff  (this table)
		//   0012: 2d0d428608        ADD    WS_DATAPTR [..XX]  <-  0886
		//	dptr = ldat;
		//   0017: 560040            CLEAR  WS_QUOT/LOW32 [XXXX]
		//   001a: 20a50018          MUL    ucPhyId  <-  18
		//   001e: 2d0a4240          ADD    WS_DATAPTR [..XX]  <-  WS_QUOT/LOW32 [..XX]
		////dptr += ucPhyId * 0x18;
		//   0022: 038a4642          MOVE   WS_FB_WIN [XX..]  <-  WS_DATAPTR [..XX]
		//   0026: 423900630768066301520063006305630b93066303730763029d076304d90763
		//         0c6908630d7c085a5a
		//                           SWITCH  cfg->ucAction
		//         07->0668 01->0052 00->0563 0b->0693 03->0773 02->079d 04->07d9 0c->0869
		//         0d->087c
		switch (1/*action*/) {
			case ATOM_TRANSMITTER_ACTION_INIT:			// 7
				//aruba_encoder_init(ucConnObjId);
				return;
			case ATOM_TRANSMITTER_ACTION_ENABLE:			// 1
				//aruba_transmitter_enable();
				return;
			case ATOM_TRANSMITTER_ACTION_DISABLE:			// 0
				//goto l_0563;
			case ATOM_TRANSMITTER_ACTION_SETUP_VSEMPH:		// b
				//goto l_0693;
			case ATOM_TRANSMITTER_ACTION_LCD_BLON:			// 3
				//aruba_lcd_blon_old();
				return;
			case ATOM_TRANSMITTER_ACTION_LCD_BLOFF:			// 2
				//aruba_lcd_bloff_old();
				return;
			case ATOM_TRANSMITTER_ACTION_BL_BRIGHTNESS_CONTROL:	// 4
				//aruba_brightness_control(NULL, 0, 0);
				return;
			case ATOM_TRANSMITTER_ACTION_POWER_ON:			// c
				//goto l_0869;
			case ATOM_TRANSMITTER_ACTION_POWER_OFF:			// d
				//goto l_087c;
			default:
				//   004f: 436406            JUMP   0664
				/////goto l_664:
				return;
		}

		return;
		//   0563: 02310200          MOVE   cfg->ucDigEncoderSel  <-  ucPhyId
		//   0567: 5214              CALL_TABLE  14  (ASIC_StaticPwrMgtStatusChange/SetUniphyInstance)
		//   0569: 4a25511c01        TEST   reg[1c51]  [...X]  <-  01
		//   056e: 446406            JUMP_Equal  0664
		//   0571: 3ca5501c02        COMP   reg[1c50]  [.X..]  <-  02
		//   0576: 448105            JUMP_Equal  0581
		//   0579: 3ca5501c03        COMP   reg[1c50]  [.X..]  <-  03
		//   057e: 498a05            JUMP_NotEqual  058a
		//   0581: 5400511c          CLEAR  reg[1c51]  [XXXX]
		//   0585: 5002              DELAY_MilliSec  02
		//   0587: 43ab05            JUMP   05ab
		//   058a: 03314300          MOVE   WS_SHIFT [...X]  <-  ucPhyId
		//   058e: 4a62501c44        TEST   reg[1c50]  [..X.]  <-  WS_OR_MASK [...X]
		//   0593: 44ab05            JUMP_Equal  05ab
		//   0596: 5408c31c          CLEAR  reg[1cc3]  [..XX]
		//   059a: 51c8              DELAY_MicroSec  c8
		//   059c: 0d25c41c01        OR     reg[1cc4]  [...X]  <-  01
		//   05a1: 5132              DELAY_MicroSec  32
		//   05a3: 5420c01c          CLEAR  reg[1cc0]  [...X]
		//   05a7: 5420d11c          CLEAR  reg[1cd1]  [...X]
		//   05ab: 560848            CLEAR  WS_REGPTR [..XX]
		//   05ae: 031a4246          MOVE   WS_DATAPTR [..XX]  <-  WS_FB_WIN [XX..]
		//   05b2: 010438000800      MOVE   reg[0038]  [XXXX]  <-  data[0008] [XXXX]
		//   05b8: 370300            SET_ATI_PORT  0003  (INDIRECT_IO_PCIE)
		//   05bb: 03e0401480        MOVE   WS_QUOT/LOW32 [X...]  <-  reg[8014]  [...X]
		//   05c0: 07251480c3        AND    reg[8014]  [...X]  <-  c3
		//   05c5: 370000            SET_ATI_PORT  0000  (INDIRECT_IO_MM)
		//   05c8: 030c481000        MOVE   WS_REGPTR [..XX]  <-  data[0010] [..XX]
		//   05cd: 07658a19ef        AND    reg[198a]  [..X.]  <-  ef
		//   05d2: 02310200          MOVE   cfg->ucDigEncoderSel  <-  ucPhyId
		//   05d6: 5214              CALL_TABLE  14  (ASIC_StaticPwrMgtStatusChange/SetUniphyInstance)
		//   05d8: 0725511cfe        AND    reg[1c51]  [...X]  <-  fe
		//   05dd: 5428501c          CLEAR  reg[1c50]  [..X.]
		//   05e1: 54008d1c          CLEAR  reg[1c8d]  [XXXX]
		//   05e5: 560848            CLEAR  WS_REGPTR [..XX]
		//   05e8: 03314800          MOVE   WS_REGPTR [...X]  <-  ucPhyId
		//   05ec: 07256001fe        AND    reg[0160]  [...X]  <-  fe
		//   05f1: 031a4246          MOVE   WS_DATAPTR [..XX]  <-  WS_FB_WIN [XX..]
		//   05f5: 030c481000        MOVE   WS_REGPTR [..XX]  <-  data[0010] [..XX]
		//   05fa: 07258619fe        AND    reg[1986]  [...X]  <-  fe
		//   05ff: 3a0000            SET_REG_BLOCK  0000
		//   0602: 010438000800      MOVE   reg[0038]  [XXXX]  <-  data[0008] [XXXX]
		//   0608: 4a25390001        TEST   reg[0039]  [...X]  <-  01
		//   060d: 440806            JUMP_Equal  0608
		//   0610: 370300            SET_ATI_PORT  0003  (INDIRECT_IO_PCIE)
		//   0613: 013a148040        MOVE   reg[8014]  [...X]  <-  WS_QUOT/LOW32 [X...]
		//   0618: 370000            SET_ATI_PORT  0000  (INDIRECT_IO_MM)
		//   061b: 02310200          MOVE   cfg->ucDigEncoderSel  <-  ucPhyId
		//   061f: 5214              CALL_TABLE  14  (ASIC_StaticPwrMgtStatusChange/SetUniphyInstance)
		//   0621: 07a5001cfe        AND    reg[1c00]  [.X..]  <-  fe
		//   0626: 3a0000            SET_REG_BLOCK  0000
		//   0629: 031a4246          MOVE   WS_DATAPTR [..XX]  <-  WS_FB_WIN [XX..]
		//   062d: 02050223000000    MOVE   param[02]  [XXXX]  <-  00000023
		//   0634: 02a4021700        MOVE   cfg->ucReserved  <-  data[0017] [...X]
		//   0639: 5213              CALL_TABLE  13  (EnableASIC_StaticPwrMgt)
		//   063b: 0205021707000f    MOVE   param[02]  [XXXX]  <-  0f000717
		//   0642: 02a4021700        MOVE   cfg->ucReserved  <-  data[0017] [...X]
		//   0647: 5213              CALL_TABLE  13  (EnableASIC_StaticPwrMgt)
		//   0649: 3d650104          COMP   cfg->ucConnObjId  <-  04
		//   064d: 495606            JUMP_NotEqual  0656
		//   0650: 68a50201          XOR    cfg->ucReserved  <-  01
		//   0654: 5213              CALL_TABLE  13  (EnableASIC_StaticPwrMgt)
		//   0656: 02050222000000    MOVE   param[02]  [XXXX]  <-  00000022
		//   065d: 02a4021700        MOVE   cfg->ucReserved  <-  data[0017] [...X]
		//   0662: 5213              CALL_TABLE  13  (EnableASIC_StaticPwrMgt)
		////l_664:
		//   0664: 3a0000            SET_REG_BLOCK  0000
		//   0667: 5b                EOT
		return;

		//   0693: 02050223000000    MOVE   param[02]  [XXXX]  <-  00000023
		//   069a: 02a4021700        MOVE   cfg->ucReserved  <-  data[0017] [...X]
		//   069f: 5213              CALL_TABLE  13  (EnableASIC_StaticPwrMgt)
		//   06a1: 560040            CLEAR  WS_QUOT/LOW32 [XXXX]
		//   06a4: 0324401600        MOVE   WS_QUOT/LOW32 [...X]  <-  data[0016] [...X]
		//   06a9: 661e              SET_DATA_BLOCK  1e  (IntegratedSystemInfo)
		//   06ab: 2d0d428801        ADD    WS_DATAPTR [..XX]  <-  0188
		//   06b0: 210d401000        MUL    WS_QUOT/LOW32 [..XX]  <-  0010
		//   06b5: 2d0a4240          ADD    WS_DATAPTR [..XX]  <-  WS_QUOT/LOW32 [..XX]
		//   06b9: 0324400c00        MOVE   WS_QUOT/LOW32 [...X]  <-  data[000c] [...X]
		//   06be: 3e254002          COMP   WS_QUOT/LOW32 [...X]  <-  02
		//   06c2: 49cc06            JUMP_NotEqual  06cc
		//   06c5: 661e              SET_DATA_BLOCK  1e  (IntegratedSystemInfo)
		//   06c7: 036446fc01        MOVE   WS_FB_WIN [..X.]  <-  data[01fc] [...X]
		//   06cc: 031a4246          MOVE   WS_DATAPTR [..XX]  <-  WS_FB_WIN [XX..]
		//   06d0: 010438000000      MOVE   reg[0038]  [XXXX]  <-  data[0000] [XXXX]
		//   06d6: 66ff              SET_DATA_BLOCK  ff  (this table)
		//   06d8: 0965461b          AND    WS_FB_WIN [..X.]  <-  1b
		//   06dc: 2d0d429009        ADD    WS_DATAPTR [..XX]  <-  0990
		//   06e1: 03314300          MOVE   WS_SHIFT [...X]  <-  ucPhyId
		//   06e5: 03a24044          MOVE   WS_QUOT/LOW32 [.X..]  <-  WS_OR_MASK [...X]
		//   06e9: 030c400200        MOVE   WS_QUOT/LOW32 [..XX]  <-  data[0002] [..XX]
		//   06ee: 4ca4400000        TEST   WS_QUOT/LOW32 [.X..]  <-  data[0000] [...X]
		//   06f3: 49fe06            JUMP_NotEqual  06fe
		//   06f6: 2d0c420400        ADD    WS_DATAPTR [..XX]  <-  data[0004] [..XX]
		//   06fb: 43e906            JUMP   06e9
		//   06fe: 2d0d420600        ADD    WS_DATAPTR [..XX]  <-  0006
		//   0703: 3e64460000        COMP   WS_FB_WIN [..X.]  <-  data[0000] [...X]
		//   0708: 441e07            JUMP_Equal  071e
		//   070b: 0324410000        MOVE   WS_REMIND/HI32 [...X]  <-  data[0000] [...X]
		//   0710: 3e2541ff          COMP   WS_REMIND/HI32 [...X]  <-  ff
		//   0714: 441e07            JUMP_Equal  071e
		//   0717: 2d0a4240          ADD    WS_DATAPTR [..XX]  <-  WS_QUOT/LOW32 [..XX]
		//   071b: 430307            JUMP   0703
		//   071e: 370300            SET_ATI_PORT  0003  (INDIRECT_IO_PCIE)
		//   0721: 4ba50001          TEST   ucPhyId  <-  01
		//   0725: 494307            JUMP_NotEqual  0743
		//   0728: 010c06600100      MOVE   reg[6006]  [..XX]  <-  data[0001] [..XX]
		//   072e: 010c86600300      MOVE   reg[6086]  [..XX]  <-  data[0003] [..XX]
		//   0734: 010c06610500      MOVE   reg[6106]  [..XX]  <-  data[0005] [..XX]
		//   073a: 010c86610700      MOVE   reg[6186]  [..XX]  <-  data[0007] [..XX]
		//   0740: 435b07            JUMP   075b
		//   0743: 010c06620100      MOVE   reg[6206]  [..XX]  <-  data[0001] [..XX]
		//   0749: 010c86620300      MOVE   reg[6286]  [..XX]  <-  data[0003] [..XX]
		//   074f: 010c06630500      MOVE   reg[6306]  [..XX]  <-  data[0005] [..XX]
		//   0755: 010c86630700      MOVE   reg[6386]  [..XX]  <-  data[0007] [..XX]
		//   075b: 370000            SET_ATI_PORT  0000  (INDIRECT_IO_MM)
		//   075e: 031a4246          MOVE   WS_DATAPTR [..XX]  <-  WS_FB_WIN [XX..]
		//   0762: 02050222000000    MOVE   param[02]  [XXXX]  <-  00000022
		//   0769: 02a4021700        MOVE   cfg->ucReserved  <-  data[0017] [...X]
		//   076e: 5213              CALL_TABLE  13  (EnableASIC_StaticPwrMgt)
		//   0770: 436406            JUMP   0664

		return;

		return;
		//   07d9: 6606              SET_DATA_BLOCK  06  (LVDS_Info)
		//   07db: 560041            CLEAR  WS_REMIND/HI32 [XXXX]
		//   07de: 030c413200        MOVE   WS_REMIND/HI32 [..XX]  <-  data[0032] [..XX]
		//   07e3: 3e0d410000        COMP   WS_REMIND/HI32 [..XX]  <-  0000
		//   07e8: 446808            JUMP_Equal  0868
		//   07eb: 4aa59c0101        TEST   reg[019c]  [.X..]  <-  01
		//   07f0: 49f807            JUMP_NotEqual  07f8
		//   07f3: 0d25211901        OR     reg[1921]  [...X]  <-  01
		//   07f8: 03054640787d01    MOVE   WS_FB_WIN [XXXX]  <-  017d7840
		//   07ff: 210541ff0f0000    MUL    WS_REMIND/HI32 [XXXX]  <-  00000fff
		//   0806: 27024640          DIV    WS_FB_WIN [XXXX]  <-  WS_QUOT/LOW32 [XXXX]
		//   080a: 3e054100000000    COMP   WS_REMIND/HI32 [XXXX]  <-  00000000
		//   0811: 441908            JUMP_Equal  0819
		//   0814: 2d0d400100        ADD    WS_QUOT/LOW32 [..XX]  <-  0001
		//   0819: 018a1b1940        MOVE   reg[191b]  [XX..]  <-  WS_QUOT/LOW32 [..XX]
		//   081e: 560041            CLEAR  WS_REMIND/HI32 [XXXX]
		//   0821: 030c413200        MOVE   WS_REMIND/HI32 [..XX]  <-  data[0032] [..XX]
		//   0826: 21024041          MUL    WS_QUOT/LOW32 [XXXX]  <-  WS_REMIND/HI32 [XXXX]
		//   082a: 27024640          DIV    WS_FB_WIN [XXXX]  <-  WS_QUOT/LOW32 [XXXX]
		//   082e: 01a520190c        MOVE   reg[1920]  [.X..]  <-  0c
		//   0833: 010a201940        MOVE   reg[1920]  [..XX]  <-  WS_QUOT/LOW32 [..XX]
		//   0838: 15054004          SHIFT_LEFT  WS_QUOT/LOW32 [XXXX]  by  04
		//   083c: 560041            CLEAR  WS_REMIND/HI32 [XXXX]
		//   083f: 032841cb05        MOVE   WS_REMIND/HI32 [...X]  <-  reg[05cb]  [..X.]
		//   0844: 2d0d410100        ADD    WS_REMIND/HI32 [..XX]  <-  0001
		//   0849: 21024041          MUL    WS_QUOT/LOW32 [XXXX]  <-  WS_REMIND/HI32 [XXXX]
		//   084d: 1b054008          SHIFT_RIGHT  WS_QUOT/LOW32 [XXXX]  by  08
		//   0851: 010a1e1940        MOVE   reg[191e]  [..XX]  <-  WS_QUOT/LOW32 [..XX]
		//   0856: 0de51e19c0        OR     reg[191e]  [X...]  <-  c0
		//   085b: 07252119fe        AND    reg[1921]  [...X]  <-  fe
		//   0860: 4a65211901        TEST   reg[1921]  [..X.]  <-  01
		//   0865: 496008            JUMP_NotEqual  0860
		//   0868: 5b                EOT
		return;
		//   0869: 07a51919fd        AND    reg[1919]  [.X..]  <-  fd
		//   086e: 0d25191911        OR     reg[1919]  [...X]  <-  11
		//   0873: 3c651a1904        COMP   reg[191a]  [..X.]  <-  04
		//   0878: 497308            JUMP_NotEqual  0873
		//   087b: 5b                EOT
		return;
		//   087c: 5c251919ef01      MASK   reg[1919]  [...X]  &  ef  |  01
		//   0882: 5b                EOT
		return;
		//   0883: 7acc010220230111001301488033010001020300000000000802060220210111
		//         0011014980310100010203100000000002030102202102110011024a80310100
		//         010203200000000008040202202102110011024b803101000102033000000000
		//         08050302202201110012014c8032010001020340000000001000040220220111
		//         0012014d80320100010203500000000010010505202101100002600520230120
		//         00084005202201000010400c00ffff020e000b000b000b000bffff0231000b00
		//         0b000b000bffff030e002a002a002a002affff0331000b000b000b000b350c00
		//         061d100106881302066a180306bd1f040610270506d430060674400706ffff08
		//         066842000478690204ffff01040e000900610000550055005500550001400040
		//         0040004000022a002a002a002a00030000000000000000084015401540154015
		//         0920202020202020200a002a002a002a002a102a2a2a2a2a2a2a2a1100400040
		//         00400040180055005500550055ff310009006100005500550055005500014000
		//         400040004000022a002a002a002a000300000000000000000840154015401540
		//         150920202020202020200a002a002a002a002a102a2a2a2a2a2a2a2a11004000
		//         4000400040180055005500550055ff
		//                           CTB_DS  460 bytes

}

static void aruba_encoder_init_old(struct radeon_device *rdev, uint8_t connector_id)
{
	//   0668: 370000            SET_ATI_PORT  0000  (INDIRECT_IO_MM)
	//   066b: 010d1b199f0f      MOVE   reg[191b]  [..XX]  <-  0f9f
	aruba_mask(rdev, 0x191b, 0xffff, 0x0f9f);
	//   0671: 3d650114          COMP   cfg->ucConnObjId  <-  14
	//   0675: 496406            JUMP_NotEqual  0664
	if (connector_id != CONNECTOR_OBJECT_ID_eDP)
		return;
	//   0678: 6606              SET_DATA_BLOCK  06  (LVDS_Info)
	//   067a: 01051c1901000078  MOVE   reg[191c]  [XXXX]  <-  78000001
	aruba_write(rdev, 0x191c, 0x78000001);
	//   0682: 01251d197d        MOVE   reg[191d]  [...X]  <-  7d
	aruba_mask(rdev, 0x191d, 0xff, 0x74);
	//   0687: 014c1d193900      MOVE   reg[191d]  [.XX.]  <-  data[0039] [..XX] // UNKNOW == 0x0303
	//// FIXME FUXME FEXME TODO
	aruba_mask(rdev, 0x191d, 0xffff << 8, 0x0303 << 8);
	//   068d: 0de5191902        OR     reg[1919]  [X...]  <-  02
	aruba_mask(rdev, 0x1919, 0, 0x02 << 24);
	//   0692: 5b                EOT
}

void aruba_brightness_control_old( bl_pwm_freq_hz, uint8_t bl_level)
{
	uint32_t pwmctlres, ticks_per_cycle;
	uint32_t cycle_div, cycle_ctr, high_ctr, newf;
	//   07d9: 6606              SET_DATA_BLOCK  06  (LVDS_Info)
	//   07db: 560041            CLEAR  WS_REMIND/HI32 [XXXX]
	//   07de: 030c413200        MOVE   WS_REMIND/HI32 [..XX]  <-  data[0032] [..XX]
	/// FIXME
	//   07e3: 3e0d410000        COMP   WS_REMIND/HI32 [..XX]  <-  0000
	//   07e8: 446808            JUMP_Equal  0868
	if (bl_pwm_freq_hz == 0)
		return;
	//   07eb: 4aa59c0101        TEST   reg[019c]  [.X..]  <-  01
	//   07f0: 49f807            JUMP_NotEqual  07f8
	if (((radeon_reg_read(0x019c) >> 16) & 0xff) != 0x01)
		//   07f3: 0d25211901        OR     reg[1921]  [...X]  <-  01
		radeon_reg_mask(0x1921, 0, 0x01);

	//   07f8: 03054640787d01    MOVE   WS_FB_WIN [XXXX]  <-  017d7840
	/////win = PWM_MAGIC_CONST;
	//   07ff: 210541ff0f0000    MUL    WS_REMIND/HI32 [XXXX]  <-  00000fff
	/////quot = bl_pwm_freq_hz * PWM_RESOLUTION;
	//   0806: 27024640          DIV    WS_FB_WIN [XXXX]  <-  WS_QUOT/LOW32 [XXXX]
	/////quot = PWM_MAGIC_CONST / quot;
	/////rem = PWM_MAGIC_CONST & quot;
	USE_OLD_SHIT	//   080a: 3e054100000000    COMP   WS_REMIND/HI32 [XXXX]  <-  00000000
	//   0811: 441908            JUMP_Equal  0819
	/////if (rem != 0)
	//   0814: 2d0d400100        ADD    WS_QUOT/LOW32 [..XX]  <-  0001
	/////quot++;
	pwmctlres = PWM_MAGIC_CONST / PWM_RESOLUTION;
	ticks_per_cycle = bl_pwm_freq_hz * PWM_RESOLUTION;
	cycle_div = DIV_UP(PWM_MAGIC_CONST, ticks_per_cycle);
	//   0819: 018a1b1940        MOVE   reg[191b]  [XX..]  <-  WS_QUOT/LOW32 [..XX]
	radeon_reg_mask(0x191b, 0xffff << 16, cycle_div << 16);
	//   081e: 560041            CLEAR  WS_REMIND/HI32 [XXXX]
	//   0821: 030c413200        MOVE   WS_REMIND/HI32 [..XX]  <-  data[0032] [..XX]
	/* FIXME */
	//   0826: 21024041          MUL    WS_QUOT/LOW32 [XXXX]  <-  WS_REMIND/HI32 [XXXX]
	newf = cycle_div * bl_pwm_freq_hz;
	//   082a: 27024640          DIV    WS_FB_WIN [XXXX]  <-  WS_QUOT/LOW32 [XXXX]
	//parma = PWM_MAGIC_CONST / (div * bl_pwm_freq_hz);
	cycle_ctr = PWM_MAGIC_CONST / (cycle_div * bl_pwm_freq_hz);
	//   082e: 01a520190c        MOVE   reg[1920]  [.X..]  <-  0c
	radeon_reg_mask(0x1920, 0xff << 16, 0x0c << 16);
	//   0833: 010a201940        MOVE   reg[1920]  [..XX]  <-  WS_QUOT/LOW32 [..XX]
	radeon_reg_mask(0x1920, 0xffff, cycle_ctr & 0xffff);
	//   0838: 15054004          SHIFT_LEFT  WS_QUOT/LOW32 [XXXX]  by  04
	high_ctr = cycle_ctr << 4;
	//   083c: 560041            CLEAR  WS_REMIND/HI32 [XXXX]
	//   083f: 032841cb05        MOVE   WS_REMIND/HI32 [...X]  <-  reg[05cb]  [..X.]
	////rem = (radeon_reg_read(0x05cb) >> 8) & 0xff; <--- bl_level
	//   0844: 2d0d410100        ADD    WS_REMIND/HI32 [..XX]  <-  0001
	//   0849: 21024041          MUL    WS_QUOT/LOW32 [XXXX]  <-  WS_REMIND/HI32 [XXXX]
	high_ctr = high_ctr * (bl_level + 1);
	//   084d: 1b054008          SHIFT_RIGHT  WS_QUOT/LOW32 [XXXX]  by  08
	high_ctr >>= 8;
	//   0851: 010a1e1940        MOVE   reg[191e]  [..XX]  <-  WS_QUOT/LOW32 [..XX]
	radeon_reg_mask(0x191e, 0xffff, high_ctr & 0xffff);
	//   0856: 0de51e19c0        OR     reg[191e]  [X...]  <-  c0
	radeon_reg_mask(0x191e, 0, 0xc0 << 24);
	//   085b: 07252119fe        AND    reg[1921]  [...X]  <-  fe
	radeon_reg_mask(0x1921, (1 << 0), 0);
	//   0860: 4a65211901        TEST   reg[1921]  [..X.]  <-  01
	//   0865: 496008            JUMP_NotEqual  0860
	while (((radeon_reg_read(0x1921) >> 8) & 0xff) == 0x01);
	//   0868: 5b                EOT

	fprintf(stderr, "0x%x\t0x%x\t0x%x\n%u\t%u\t%u\t%u\n", cycle_div, cycle_ctr, high_ctr, cycle_div, cycle_ctr, high_ctr, pwmctlres);
	fprintf(stderr, "ticks_per_cycle vs cycle_ctr %u\t%u\n", ticks_per_cycle, cycle_ctr);
}

static void aruba_lcd_blon_old(void)
{
	//   0773: 4ae5191901        TEST   reg[1919]  [X...]  <-  01
	//   0778: 496406            JUMP_NotEqual  0664
	if ((radeon_reg_read(0x1919) >> 24) != 0x01)
		return;
	//   077b: 5032              DELAY_MilliSec  32
	radeon_udelay(0x32 * 1000);
	//   077d: 3c651d1900        COMP   reg[191d]  [..X.]  <-  00
	//   0782: 449707            JUMP_Equal  0797
	if (((radeon_reg_read(0x191d) >> 8) & 0xff) == 0) {
		//   0797: 0de5191903        OR     reg[1919]  [X...]  <-  03
		radeon_reg_mask(0x191d, 0, 0x03 << 24);
		//   079c: 5b                EOT
		return;
	}
	//   0785: 0da5401901        OR     reg[1940]  [.X..]  <-  01
	radeon_reg_mask(0x1940, 0, 0x01 << 16);
	//   078a: 0de5191903        OR     reg[1919]  [X...]  <-  03
	radeon_reg_mask(0x1919, 0, 0x03 << 24);
	//   078f: 5004              DELAY_MilliSec  04
	radeon_udelay(0x04 * 1000);
	//   0791: 07a54019fe        AND    reg[1940]  [.X..]  <-  fe
	radeon_reg_mask(0x1940, ~0xfffeffff, 0);
	//   0796: 5b                EOT

}

static void aruba_lcd_bloff_old(void)
{
	int rem;
	//   079d: 4ae5191901        TEST   reg[1919]  [X...]  <-  01
	//   07a2: 446406            JUMP_Equal  0664
	if ((radeon_reg_read(0x1919) >> 24) == 0x01)
		return;
	//   07a5: 6606              SET_DATA_BLOCK  06  (LVDS_Info)
	//   07a7: 0324414200        MOVE   WS_REMIND/HI32 [...X]  <-  data[0042] [...X]
	//// FIXME
	rem = 0;
	//   07ac: 3e254100          COMP   WS_REMIND/HI32 [...X]  <-  00
	//   07b0: 496406            JUMP_NotEqual  0664
	if (rem != 0)
		return;
	//   07b3: 3c651d1900        COMP   reg[191d]  [..X.]  <-  00
	//   07b8: 44d007            JUMP_Equal  07d0
	if (((radeon_reg_read(0x191d) >> 8) & 0xff) != 0) {
		//   07bb: 0da5401901        OR     reg[1940]  [.X..]  <-  01
		radeon_reg_mask(0x1940, 0, 0x01 << 16);
		//   07c0: 5004              DELAY_MilliSec  04
		radeon_udelay(0x04 * 1000);
		//   07c2: 5ce51919fe02      MASK   reg[1919]  [X...]  &  fe  |  02
		radeon_reg_mask(0x1919, ~0xfeffffff, 0x02 << 24);
		//   07c8: 07a54019fe        AND    reg[1940]  [.X..]  <-  fe
		radeon_reg_mask(0x1940, ~0xfffeffff, 0);
		//   07cd: 43d607            JUMP   07d6
	} else {
		//   07d0: 5ce51919fe02      MASK   reg[1919]  [X...]  &  fe  |  02
		radeon_reg_mask(0x1919, ~0xfeffffff << 24, 0x02 << 24);
	}
	//   07d6: 5001              DELAY_MilliSec  01
	radeon_udelay(1000);
	//   07d8: 5b                EOT
}
