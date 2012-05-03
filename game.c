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
int time_to_next_monster;

void game_init(){
    level = load_level("test.lvl");
    time_to_next_monster = TIME_TO_NEXT_MONSTER;
    player = create_player();
    number_of_monsters = 0;
    number_of_towers = 0;
    screen = (char*) malloc(sizeof(char)*SCREEN_W*SCREEN_H);
    buffer = (char*) malloc(sizeof(char)*SCREEN_W*SCREEN_H);
    int i;
    add_monster(create_monster(MONSTER_MAGGOT));
    Tower*t = create_tower(TOWER_NORMAL);
    t->x = 60;
    t->y = 60;
    add_tower(t);
}

void game_render(){ 
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

void update_monsters(){
    int i;
    for(i=0;i<number_of_monsters;i++){
        if(!monster_update(monsters[i],level)){
            monsters[i--] = monsters[--number_of_monsters];
            monster_delete(monsters[number_of_monsters-1]);
        }
    }
}

void update_towers(){
    int i,j;
    for(i=0;i<number_of_towers;i++){
        tower_update(towers[i]);
        for(j=0;j<number_of_monsters;j++){
            if(pow(towers[i]->x -monsters[i]->x,2) + pow(towers[i]->y - monsters[i]->y,2) < 1000){
                if(tower_fire(towers[i]) == 0){
                    monster_take_hit(monsters[i],40);
                }
            }
        }
    }
}

void place_tower(){
    Tower* t = create_tower(TOWER_NORMAL);
    t->x = player->x;
    t->y = player->y;
    add_tower(t);
}

void button_pressed_down(){
    player->y++;
}

void button_pressed_up(){
    player->y--;
}

void button_pressed_left(){
    player->x--;
}

void button_pressed_right(){
    player->x++;
}

void button_pressed_place(){
    if(player->money > 10){
        player->money-=10;
        place_tower();
    }
}


void game_update(){
    time_to_next_monster--;
    if(time_to_next_monster <= 0){
        time_to_next_monster = TIME_TO_NEXT_MONSTER;
        add_monster(create_monster(MONSTER_MAGGOT));
    }
    update_monsters();
    update_towers();
}

void game_deinit(){}
void game_resume(){}
void game_pause(){}



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
