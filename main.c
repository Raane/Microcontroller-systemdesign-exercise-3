#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Level.h"
#include "game.h"
#include "main.h"


int dt;
int main(int argc, char**argv){

    dt=0;
    init();

    while(1){

        while(dt > 0){
            tick();
            dt--;
        }
        dt+= 15;

        render();
        usleep(250000);
    }
    return 0;
}
