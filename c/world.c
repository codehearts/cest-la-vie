#include "world.h"

void increment_neighbors(cell_t *w, int i) {
	int x = i % world_width,
		y = i / world_width,
		left  = (x == 0) ? world_width - 1           : -1,
		above = (y == 0) ? world_size  - world_width : -world_width,
		right = (x == (world_width  - 1)) ? -(world_width - 1) : 1,
		below = (y == (world_height - 1)) ? -(world_size - world_width) : world_width;

	// Top row
	w[i + above + left]  += 2;
	w[i + above]         += 2;
	w[i + above + right] += 2;

	// Middle edges
	w[i + left]  += 2;
	w[i + right] += 2;

	// Bottom row
	w[i + below + left]  += 2;
	w[i + below]         += 2;
	w[i + below + right] += 2;
}

void draw_cell(int i) {
	int x = i % world_width,
		y = i / world_width,
		scale = world_scale;
	draw_rectangle(x * scale, y * scale, scale, scale);
}

void initialize_world(int width, int height, int scale, int seed) {
	world_width  = width;
	world_height = height;
	world_scale  = scale;
	world_size   = height * width;

	world = calloc(world_size, sizeof(cell_t));
	int i;

	// Randomly create live and dead cells
	srand(seed);
	for (i = 0; i < world_size; i++) {
		if (rand() % 2) {
			world[i] |= 0x1;
			increment_neighbors(world, i);
		}
	}
}

void next_world_state() {
	cell_t *next_world = calloc(world_size, sizeof(cell_t));
	cell_t next_cell, cell;
	int i;

	for (i = 0; i < world_size; i++) {
		cell = world[i];

		if (cell) {
			if (cell_neighbors(cell) == 3 || ((cell & 0x1) && cell_neighbors(cell) == 2)) {
				next_world[i] |= 0x1;
				increment_neighbors(next_world, i);
				draw_cell(i);
			}
		}
	}
	
	free(world);
	world = next_world;
}
