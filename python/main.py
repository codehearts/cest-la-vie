from pyglet_world import PygletWorld
import pyglet

# General settings
settings = {
	'cell_size':  5,
	'height':     600,
	'width':      600,
	'frame_rate': 15,
}

window = pyglet.window.Window(settings['width'], settings['height'])
world  = PygletWorld(settings['width'], settings['height'], cell_size=settings['cell_size'])

@window.event
def on_draw():
	"""Clears the screen and draws the world."""
	pyglet.gl.glClear(pyglet.gl.GL_COLOR_BUFFER_BIT)

	world.draw()

def update(dt):
	"""Updates the state of the world."""
	world.next_state()

if __name__ == "__main__":
	# Clear the screen with white
	pyglet.gl.glClearColor(255, 255, 255, 255)

	pyglet.clock.schedule_interval(update, 1.0/settings['frame_rate'])
	pyglet.app.run()
