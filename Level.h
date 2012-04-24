#ifndef LEVEL_H
#define LEVEL_H

#define MAP_WIDTH 16
#define MAP_HEIGHT 12

#define MAP_MAX_PATH_LENGTH 128

#define MAP_TILE_GRASS 0
#define MAP_TILE_ROAD 1

typedef struct{
    unsigned char[MAP_WIDTH][MAP_HEIGHT] map; 
    int[MAP_MAX_PATH_LENGTH] path; /* an array of x, y co-ordinates */ 
} Level;

Level* load_level(char*filename){
    Level*level = (Level*) malloc(sizeof(Level));
    FILE*fp = fopen(filename, "rb");
    int x, y;
    for(y=0;y<MAP_HEIGHT;y++){
        for(x=0;x<MAP_WIDTH;x++){
            level->map[x][y] = fgetc(fp); 
        }
    }
    for(x=0;x<MAP_MAX_PATH_LENGTH;x++){
            level->path[x] = fgetc(fp); 
        }
    }
    fclose(fp);
    return level;
}

void level_print(Level*l){ //debugging
    for(y=0;y<MAP_HEIGHT;y++){
        for(x=0;x<MAP_WIDTH;x++){
            printf("%c", l->map[x][y]+64);
        }
        printf("\n");
    }
    return;
}

#endif
