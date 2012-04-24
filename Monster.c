#include "Monster.h"

Monster* create_monster(int monster_type){
    Monster* monster = (Monster*) malloc(sizeof(Monster));
    monster->x = 0;
    monster->y = 0;
    monster->velocity = 0;
    monster->monster_type = monster_type;
    switch(monster_type){
        case MONSTER_MAGGOT:
            monster->health = MONSTER_MAGGOT_HEALTH;
            break;
        case MONSTER_RAT:
            monster->health = MONSTER_BEAR_HEALTH;
            break;
        case MONSTER_BEAR:
            monster->health = MONSTER_BEAR_HEALTH;
            break;
        case MONSTER_GIRAFFE:
            monster->health = MONSTER_GIRAFFE_HEALTH;
            break;
        case MONSTER_DRAGON:
            monster->health = MONSTER_DRAGON_HEALTH;
            break;
        default:
            monster->health = MONSTER_MAGGOT_HEALTH;
            break;
    }
    return monster;
}

void monster_render(Monster* m){
    return;
}
