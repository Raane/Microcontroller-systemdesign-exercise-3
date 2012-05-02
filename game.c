#include <stdlib.h>
#include <stdio.h>
#include "game.h"
#include "Level.h"
#include "Monster.h"
#include "Tower.h"
#include "Player.h"
#include "render.h"
#include <math.h>

Level* level;
Player* player;

void init(){
    level = load_level("test.lvl");
    player = create_player();
    number_of_monsters = 0;
    number_of_towers = 0;
    screen = (char*) malloc(sizeof(char)*SCREEN_W*SCREEN_H);
    buffer = (char*) malloc(sizeof(char)*SCREEN_W*SCREEN_H);
    int i;
    add_monster(create_monster(MONSTER_MAGGOT));
    add_tower(create_tower(TOWER_NORMAL));
}

void render(){ 
    render_rect(buffer, 0, 0,SCREEN_H, SCREEN_H, ' '); //clear screen
    level_render(level,buffer);
    int i;
    for(i=0;i<number_of_monsters;i++){
        monster_render(monsters[i], buffer);
    }
    for(i=0;i<number_of_towers;i++){
        tower_render(towers[i], buffer);
    }
    player_render(player, buffer);
    flip_buffers();
}

void tick(){
    int i,j;
    for(i=0;i<number_of_monsters;i++){
        if(!monster_update(monsters[i],level)){
            monsters[i--] = monsters[--number_of_monsters];
            monster_delete(monsters[number_of_monsters-1]);
        }
    }
    for(i=0;i<number_of_towers;i++){
        tower_update(towers[i]);
        for(j=0;j<number_of_monsters;j++){
            if(pow(towers[i]->x -monsters[i]->x,2) + pow(towers[i]->y - monsters[i]->y,2) < 100){
                if(tower_fire(towers[i])){
                    monster_take_hit(monsters[i],10);
                }
            }
        }
    }
}

float lerp(int value0, int value1, float progression){
    return value0 + (value1-value0)*progression;
}


void add_monster(Monster*m){
    monsters[number_of_monsters++] = m;
}

void remove_monster(Monster*m){
    int i;
    for(i=0;i<number_of_monsters;i++){
        if(m == monsters[i]){
            monsters[i] = monsters[number_of_monsters--];
            break;
        }
    }
}

void add_tower(Tower*t){
    towers[number_of_towers++] = t;
}


void remove_tower(Tower*t){
    int i;
    for(i=0;i<number_of_towers;i++){
        if(t == towers[i]){
            towers[i] = towers[number_of_towers--];
            break;
        }
    }
}
