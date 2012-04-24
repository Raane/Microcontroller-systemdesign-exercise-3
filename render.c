#include <stdio.h>
#include "game.h"
#include "render.h"

void render_rect(char*buffer, int x0, int y0, int w, int h, char color){
   int x,y;
   for(y=y0;y<y0+w;y++){
       for(x=x0;x<x0+w;x++){
           buffer[x+y*SCREEN_W] = color;
       }
   }
}


void flip_buffers(){
    system("clear");
    int x, y;
    for(y=0;y<SCREEN_H/4;y++){
        for(x=0;x<SCREEN_W/4;x++){
            printf("%c ", buffer[4*(x + y * SCREEN_W)]);
        }
        printf("\n");
    }
    char* temp = screen;
    screen = buffer;
    buffer = temp;

}
