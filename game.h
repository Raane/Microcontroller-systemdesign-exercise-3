#ifndef GAME_H
#define GAME_H

#define SCREEN_W 320
#define SCREEN_H 240

char*buffer;
char*screen;

void flip_buffers();
void init();
void tick();
void render();

#endif
