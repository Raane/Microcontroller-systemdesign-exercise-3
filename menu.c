#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

int menu_choice;

void menu_init(){
    menu_choice = MENU_CHOICE_PLAY; 
}

void menu_update(){

}

void menu_render(){
    printf("Menu selection: %i\n",menu_choice);
}

void menu_deinit(){

}

void menu_pause(){

}

void menu_resume(){

}


