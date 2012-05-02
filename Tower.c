#include <stdio.h>
#include <stdlib.h>
#include "Tower.h"

Tower* create_tower(int tower_type){
    Tower* tower = (Tower*) malloc(sizeof(Tower));
    tower->x = 0;
    tower->y = 0;
    tower->type = tower_type;
    tower->cooldown = 0;
    return tower;
}

void tower_render(Tower*t, char*buffer){
    render_rect(buffer, t->x, t->y,10,10, '|');
}

int tower_fire(Tower*t){
    if(t->cooldown == 0){
        t->cooldown = 100;
        return 0;
    }
    return t->cooldown;

}

void tower_update(Tower*t){
    if(t->cooldown > 0) t->cooldown--;
}
