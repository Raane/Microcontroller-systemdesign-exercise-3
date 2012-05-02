#ifndef TOWER_H
#define TOWER_H

#define TOWER_NORMAL      0
#define TOWER_FAST        1
#define TOWER_EXPENSIVE   2

typedef struct{
   int x;
   int y;
   int type;
   int cooldown;
} Tower;

Tower* create_tower(int tower_type);
int tower_fire(Tower*t);
void tower_update(Tower*);
#endif

