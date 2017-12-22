from world import World
import pyglet

class PygletWorld(World):
	"""
	Creates a 2 dimensional world of cells which can be drawn
	using Pyglet.
	"""

	def __init__(self, *args, **kwargs):
		"""
		Creates a new world which can be drawn using Pyglet.

		Kwargs:
			[int] cell_size: The width and height of a cell.
			                 (Defaults to 1)
		"""
		self._cell_size = int(kwargs.pop('cell_size', 1))

		# Adjust the width and height of the world by the cell size
		args = list(args)
		args[0] /= self._cell_size
		args[1] /= self._cell_size

		super(PygletWorld, self).__init__(*args, **kwargs)
		
	def draw(self):
		"""Draws a colored square for each live cell in the world."""
		live_batch = pyglet.graphics.Batch()

		for y in range(self.height):
			for x in range(self.width):
				cell = self.world[y][x]

				if cell.is_alive:
					x_1 = x * self._cell_size
					y_1 = y * self._cell_size
					x_2 = x_1 + self._cell_size
					y_2 = y_1 + self._cell_size
					colors = cell.color * 3

					live_batch.add(
						3, pyglet.gl.GL_TRIANGLES, None,
						('v2f', [x_1,y_1, x_1,y_2, x_2,y_2]),
						('c3B', colors))
					live_batch.add(
						3, pyglet.gl.GL_TRIANGLES, None,
						('v2f', [x_2,y_2, x_2,y_1, x_1,y_1]),
						('c3B', colors))

		live_batch.draw()
