#include <stdlib.h>
#include <stdio.h>
#include "game.h"
#include "Level.h"
#include "Monster.h"
#include "Tower.h"
#include "Tower.h"
#include "render.h"

Level* test_level;

void init(){
    test_level = load_level("test.lvl");
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
    level_render(test_level,buffer);
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
        monsters[i]->x += 1;
    }
    for(i=0;i<number_of_towers;i++){
    }
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
