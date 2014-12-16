#ifndef __REPLAY_H
#define __REPLAY_H

#include <stdint.h>

void run_replay(uint8_t skip);
void replay_int10_c1(void);
void replay_int10_c2(void);
void replay_int10_c3(void);

#endif		/* __REPLAY_H */
