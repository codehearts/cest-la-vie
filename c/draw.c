#include "draw.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

/**
 * Prepares for drawing with a double buffer and RGB components.
 *
 * @param int *argc The number of arguments, as passed to main.
 * @param char **argv The arguments, as passed to main.
 */
void draw_init(int *argc, char **argv) {
	glutInit(argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
}

/**
 * Finalizes the drawing environment, and enters the main loop.
 */
void draw_finalize() {
	// Use white to clear the window
	glClearColor(1, 1, 1, 1);

	glutMainLoop();
}

/**
 * Creates a new window to be drawn to.
 *
 * @param const char *title The title of the window.
 * @param int width The width of the window, in pixels.
 * @param int height The height of the window, in pixels.
 */
void draw_new_window(const char *title, int width, int height) {
	glutInitWindowSize(width, height);
	glutCreateWindow(title);

	// Allow a 1-to-1 mapping of OpenGL units and pixels
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, 0, 10);
	glScalef(1, -1, 1);
	glTranslatef(0, -height, 0);
	glMatrixMode(GL_MODELVIEW);
	
	// Register callbacks for the window
	glutDisplayFunc(draw);
	glutKeyboardFunc(draw_window_keypress);
	glutTimerFunc(1000 * (1.0/FPS), draw_timer, 0);

	// Draw with black
	glColor3f(0,0,0);
}

/**
 * Callback for when a key is pressed.
 * Pressing Q or ESC will close the window.
 * All other keys do nothing.
 *
 * @param unsigned char key The key that was pressed.
 * @param int x The x coordinate of the mouse when the key was pressed.
 * @param int y The y coordinate of the mouse when the key was pressed.
 */
static void draw_window_keypress(unsigned char key, int x, int y) {
	switch (key) {
		case 'q':
		case 27: // Escape
			exit(0);
			break;
		default:
			break;
	}
}

/**
 * Called each frame to trigger a redraw.
 *
 * @param int delta The value passed to the timer function.
 *                  This can be used to store the time that the
 *                  timer function was called to determine the
 *                  frame rate.
 */
static void draw_timer(int delta) {
	glutPostRedisplay();

	// Restart the timer
	glutTimerFunc(1000 * (1.0/FPS), draw_timer, 0);
}

/**
 * Draws the next state of the world by preparing OpenGL
 * for drawing quads and then making the call for the next state.
 */
static void draw() {
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	glBegin(GL_QUADS);
		next_world_state();
    glEnd();
	
	// Swap the buffers
    glutSwapBuffers();
}

/**
 * Draws a rectangle at the given coordinates.
 *
 * @param int x The x coordinate of the top left corner.
 * @param int y The y coordinate of the top left corner.
 * @param int width The width of the rectangle.
 * @param int height The height of the rectangle.
 */
void draw_rectangle(int x, int y, int width, int height) {
	glVertex2i(x + width, y + height);
	glVertex2i(x,         y + height);
	glVertex2i(x,         y);
	glVertex2i(x + width, y);
}

#pragma GCC diagnostic pop
