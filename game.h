#ifndef GAME_H
#define GAME_H

#include "Monster.h"
#include "Tower.h"

#define SCREEN_W 320
#define SCREEN_H 240

#define TIME_TO_NEXT_MONSTER 200


Tower*towers[128];
int number_of_towers;
void add_tower();
void remove_tower();
void update_towers();

Monster*monsters[128];
int number_of_monsters;
void add_monster();
void remove_monster();
void update_monsters();

float lerp(int value0, int value1, float progression);

void game_init();
void game_update();
void game_render();
void game_deinit();
void game_pause();
void game_resume();

#endif
