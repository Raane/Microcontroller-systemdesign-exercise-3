#include <stdio.h>
#include <stdlib.h>
#include <Tower.h>

Tower* create_tower(int tower_type){
    Tower* tower = (Tower*) malloc(sizeof(Tower));
    tower->x = 0;
    tower->y = 0;
    tower->type = tower_type;
    tower->cooldown = 0;
    return tower;
}


