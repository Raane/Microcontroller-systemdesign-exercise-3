#ifndef TOWER_H
#define TOWER_H

typedef struct{
   int x;
   int y;
   int type;
   int cooldown;
} Tower;

Tower* create_tower(int type);

#endif

