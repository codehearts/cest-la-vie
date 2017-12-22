#ifndef WORLD_H
#define WORLD_H

#include <stdio.h>
#include <stdlib.h>
#include "cell.h"
#include "draw.h"

static int world_width, world_height, world_size, world_scale;
static cell_t *world;

void initialize_world(int width, int height, int scale, int seed);
void next_world_state();

#endif
