#ifndef STATES_H
#define STATES_H

#define STATE_NO_STATE (-1)
#define STATE_MAIN_MENU 0
#define STATE_GAME 1

#define STATE_NUMBER_OF_STATES 2

void init_states();
void deinit_states();
void add_states();

void set_state(int state);

#endif
