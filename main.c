#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Level.h"
#include "game.h"
#include "menu.h"
#include "states.h"
#include "main.h"


int dt;

void( *init   [STATE_NUMBER_OF_STATES] ) ();
void( *update [STATE_NUMBER_OF_STATES] ) ();
void( *render [STATE_NUMBER_OF_STATES] ) ();
void( *deinit [STATE_NUMBER_OF_STATES] ) ();
void( *pause  [STATE_NUMBER_OF_STATES] ) ();
void( *resume [STATE_NUMBER_OF_STATES] ) ();

int state;

int main(int argc, char**argv){

    dt=0;

    add_states();
    init_states();
    set_state(STATE_MAIN_MENU);
    set_state(STATE_GAME);

    while(1){

        while(dt > 0){
            (*update[state])();
            dt--;
        }
        dt+= 15;

        (*render[state])();
        usleep(250000);
    }

    deinit_states_states();

    return 0;
}

void set_state(int _state){
    (*pause[state])();
    state = _state;
    (*resume[state])();
}

void init_states(){
    int i;
    for(i=0;i<STATE_NUMBER_OF_STATES;i++){
        (*init[i])(); 
    }
}

void deinit_states(){
    int i;
    for(i=0;i<STATE_NUMBER_OF_STATES;i++){
        (*deinit[i])(); 
    }
}

void add_states(){
    init[STATE_MAIN_MENU] = menu_init;
    update[STATE_MAIN_MENU] =menu_update;
    render[STATE_MAIN_MENU] =menu_render;
    deinit[STATE_MAIN_MENU] =menu_deinit;
    pause[STATE_MAIN_MENU] =menu_pause;
    resume[STATE_MAIN_MENU] =menu_resume;

    
    init[STATE_GAME] = game_init;
    update[STATE_GAME] =game_update;
    render[STATE_GAME] =game_render;
    deinit[STATE_GAME] =game_deinit;
    pause[STATE_GAME] =game_pause;
    resume[STATE_GAME] =game_resume;
}
