#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Level.h"
#include "game.h"

char colors[] = {'.','#'};

Level* load_level(char*filename){
    Level*level = (Level*) malloc(sizeof(Level));
    FILE*fp = fopen(filename, "rb");
    int x;int y;
    for(y=0;y<MAP_HEIGHT;y++){
        for(x=0;x<MAP_WIDTH;x++){
            level->map[x][y] = fgetc(fp); 
        }
    }
    for(x=0;x<MAP_MAX_PATH_LENGTH;x++){
        level->path[x] = fgetc(fp); 
    }
    fclose(fp);
    return level;
}

void level_render(Level*l, char*buffer){// debugging
    int x, y;
    for(y=0;y<MAP_HEIGHT;y++){
        for(x=0;x<MAP_WIDTH;x++){
            render_rect(buffer, x*20, y*20, 1*20, 1*20, colors[l->map[x][y]]);
        }
    }
    return;
}
