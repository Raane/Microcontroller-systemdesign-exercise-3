#include <stdio.h>
#include <stdlib.h>
#include "Player.h"
#include "render.h"

Player* create_player(){
    Player* player = (Player*) malloc(sizeof(Player));
    player->lives = 25;
    player->money = 100;
    player->x = 0;
    player->y = 0;
    return player;
}

void player_render(Player*p, char*buffer){
    render_rect(buffer,p->x, p->y, 10, 10, '@');
}
