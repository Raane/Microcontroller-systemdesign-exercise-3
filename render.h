#ifndef RENDER_H
#define RENDER_H

#define RENDER_GLOBAL_SCALING_FACTOR 8
char*buffer;
char*screen;

void render_rect(char*buffer,int x0, int y0, int w, int h, char color);
void flip_buffers();

#endif
