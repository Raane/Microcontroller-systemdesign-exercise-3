#ifndef PLAYER_H
#define PLAYER_H

typedef struct {
    int lives;
    int money;
    int x; /* grid coordinates for the player cursor */
    int y;
} Player;

Player* create_player();
void player_render(Player*p, char*buffer);

#endif
