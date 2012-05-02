#include <stdlib.h>
#include "Monster.h"
#include "render.h"
#include "Level.h"
#include "utils.h"


Monster* create_monster(int monster_type){
    Monster* monster = (Monster*) malloc(sizeof(Monster));
    monster->x = 0;
    monster->y = 0;
    monster->progression = 0;
    monster->path_step = 0;
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

void monster_render(Monster* m, char*buffer){
    render_rect(buffer, m->x, m->y,10,10, 'x');
}

int monster_update(Monster*m, Level *l){
    m->progression++;
    if(m->progression > (1+m->path_step)*256){
        m->path_step++;
    }
    m->x = lerp(l->path[m->path_step*2],l->path[(m->path_step+1)*2], (m->progression%256)/256.0);
    m->y = lerp(l->path[m->path_step*2+1],l->path[(m->path_step+1)*2+1], (m->progression%256)/256.0);
    return m->health;
}

void monster_take_hit(Monster* m, int hit){
    m->health -= hit;
    if(m->health < 0) m->health = 0;
}

void monster_delete(Monster*m){
    free(m);
}
