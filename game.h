#ifndef GAME_H
#define GAME_H

#include "Monster.h"
#include "Tower.h"

#define SCREEN_W 320
#define SCREEN_H 240


Tower*towers[128];
int number_of_towers;
void add_tower();
void remove_tower();
void tick_towers();

Monster*monsters[128];
int number_of_monsters;
void add_monster();
void remove_monster();
void tick_monsters();

void init();
void tick();
void render();

#endif
