#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Level.h"
#include "game.h"
#include "main.h"

clock_t t;
clock_t old_t;
clock_t dt;


int main(int argc, char**argv){

    dt = 0;
    init();

    while(1){
        old_t = t;
        t = clock();
        dt += t-old_t;

        while(dt > CLOCKS_PER_SEC/60){
            dt -= CLOCKS_PER_SEC/60;
            tick();
        }

        render();
        usleep(200000);
    }
    return 0;
}
