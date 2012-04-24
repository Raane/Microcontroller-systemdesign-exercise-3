#ifndef MONSTER_H
#define MONSTER_H

#define MONSTER_MAGGOT 0
#define MONSTER_RAT 1
#define MONSTER_BEAR 2
#define MONSTER_GIRAFFE 3
#define MONSTER_DRAGON 4

typedef struct{
    float x;
    float y;
    float velocity;
    int health;
    int attack;
    int monster_type;
} Monster;

Monster* create_monster(int monster_type);
void monster_render(Monster* m);

#endif
