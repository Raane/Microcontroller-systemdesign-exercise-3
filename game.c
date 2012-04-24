#include <stdlib.h>
#include <stdio.h>
#include "game.h"
#include "Level.h"

Level* test_level;

void init(){
    test_level = load_level("test.lvl");
    screen = (char*) malloc(sizeof(char)*SCREEN_W*SCREEN_H);
    buffer = (char*) malloc(sizeof(char)*SCREEN_W*SCREEN_H);
    int i;
    for(i=0;i<SCREEN_H*SCREEN_W;i++){
        screen[i] =  '.';
        buffer[i] =  ' ';
    }
}

void render(){ 
    render_rect(buffer, 0, 0,SCREEN_H, SCREEN_H, ' '); //clear screen
    level_render(test_level,buffer);
    flip_buffers();
}
