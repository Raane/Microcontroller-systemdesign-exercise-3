#include <stdlib.h>
#include <stdio.h>
#include "Level.h"

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

void level_print(Level*l){ //debugging
    int x, y;
    for(y=0;y<MAP_HEIGHT;y++){
        for(x=0;x<MAP_WIDTH;x++){
            printf("%c ", l->map[x][y]+42);
        }
        printf("\n");
    }
    return;
}
