#ifndef MONSTER_H
#define MONSTER_H

#define MONSTER_MAGGOT 0
#define MONSTER_MAGGOT_HEALTH 100

#define MONSTER_RAT 1
#define MOSNTER_RAT_HEALTH 200

#define MONSTER_BEAR 2
#define MONSTER_BEAR_HEALTH 300

#define MONSTER_GIRAFFE 3
#define MONSTER_GIRAFFE_HEALTH 400

#define MONSTER_DRAGON 4
#define MONSTER_DRAGON_HEALTH 500

typedef struct{
    float x;
    float y;
    float velocity;
    float progression;
    int health;
    int attack;
    int monster_type;
} Monster;

Monster* create_monster(int monster_type);
void monster_render(Monster* m);

#endif
