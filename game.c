#include <stdlib.h>
#include <stdio.h>
#include "game.h"
#include "Level.h"
#include "Monster.h"
#include "Tower.h"
#include "Tower.h"
#include "render.h"

Level* level;
Player* player;

void init(){
    level = load_level("test.lvl");
    number_of_monsters = 0;
    number_of_towers = 0;
    screen = (char*) malloc(sizeof(char)*SCREEN_W*SCREEN_H);
    buffer = (char*) malloc(sizeof(char)*SCREEN_W*SCREEN_H);
    int i;
    add_monster(create_monster(MONSTER_MAGGOT));
    add_tower(create_tower(TOWER_NORMAL));
    for(i=0;i<SCREEN_H*SCREEN_W;i++){
        screen[i] =  ' ';
        buffer[i] =  ' ';
    }
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
    flip_buffers();
}

void tick(){
    int i;
    for(i=0;i<number_of_monsters;i++){
        monsters[i]->progression++;

        if(monsters[i]->progression > (1+monsters[i]->path_step)*256 /*level->path[monsters[i]->path_step*3+2]*/){
            monsters[i]->path_step++;
        }
        monsters[i]->x = lerp(level->path[monsters[i]->path_step*2], level->path[(monsters[i]->path_step+1)*2], (monsters[i]->progression%256)/256.0);
        monsters[i]->y = lerp(level->path[monsters[i]->path_step*2+1], level->path[(monsters[i]->path_step+1)*2+1], (monsters[i]->progression%256)/256.0);
    }
    for(i=0;i<number_of_towers;i++){
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
