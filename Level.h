#ifndef LEVEL_H
#define LEVEL_H

#define MAP_WIDTH 16
#define MAP_HEIGHT 12

#define MAP_MAX_PATH_LENGTH 128

#define MAP_TILE_GRASS 0
#define MAP_TILE_ROAD 1

typedef struct{
    unsigned char map[MAP_WIDTH][MAP_HEIGHT]; 
    int path[MAP_MAX_PATH_LENGTH]; /* an array of x, y co-ordinates */ 
} Level;

Level* load_level(char*filename);
void level_print(Level*l);

#endif
