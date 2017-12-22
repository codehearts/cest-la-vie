#include "draw.h"
#include "world.h"

int width  = 800,
	height = 800,
	scale  = 1,
	seed   = 100;

int main(int argc, char *argv[]) {
	initialize_world(width/scale, height/scale, scale, seed);

	draw_init(&argc, argv);
	draw_new_window("Life", width, height);
	draw_finalize();
}
