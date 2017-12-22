#ifndef DRAW_H
#define DRAW_H

#include <stdlib.h>
#include <stdio.h>
#include "world.h"

#if __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

// Frames per second
#define FPS 30

void draw_init(int *argc, char **argv);
void draw_finalize();
void draw_new_window(const char *title, int width, int height);
void draw_rectangle(int x, int y, int width, int height);

static void draw();
static void draw_timer(int delta);
static void draw_window_keypress(unsigned char key, int x, int y);

#endif
