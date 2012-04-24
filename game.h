#ifndef GAME_H
#define GAME_H

#include "Monster.h"

#define SCREEN_W 320
#define SCREEN_H 240


Monster*monsters[128];
int number_of_monsters;
void add_monster();
void remove_monster();
void tick_monsters();

void init();
void tick();
void render();

#endif
