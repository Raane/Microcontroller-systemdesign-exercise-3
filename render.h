#ifndef RENDER_H
#define RENDER_H
char*buffer;
char*screen;

void render_rect(char*buffer,int x0, int y0, int w, int h, char color);
void flip_buffers();

#endif
