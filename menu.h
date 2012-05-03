#ifndef MENU_H
#define MENU_H

#define MENU_CHOICE_PLAY 0
#define MENU_CHOICE_CREDITS 1

#define MENU_NUMBER_OF_CHOICES 2;

void menu_init();
void menu_update();
void menu_render();
void menu_deinit();
void menu_pause();
void menu_resume();

#endif
