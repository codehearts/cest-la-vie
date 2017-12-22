from cell import Cell
import random

class World(object):
	"""
	Creates a 2 dimensional world of cells.

	Properties:
		[int] width: The width of the world.
		[int] height: The height of the world.
		[2d list] world: A 2d list of Cell objects.
	"""

	def __init__(self, width, height, initial_state=None):
		"""
		Creates a new world with the given dimensions.

		Arguments:
			[int] width: The width of the world.
			[int] height: The height of the world.

		Kwargs:
			[???] initial_state: Unimplemented.
		"""
		super(World, self).__init__()

		self.width  = int(width)
		self.height = int(height)

		# Create a random initial state
		if initial_state is None:
			# Create a world of dead cells
			self.world = [[Cell() for c in range(self.width)] for r in range(self.height)]

			# Randomly create live cells
			for y in range(self.height):
				for x in range(self.width):
					if random.getrandbits(1):
						self.world[y][x].set_alive()
						self.world[y][x].set_random_color()
						self.inform_neighbors(self.world, x, y)

	def inform_neighbors(self, world, x, y):
		"""
		Increments the neighbor count of all neighbors, and
		returns a tuple of the average color of the neighbors.
		
		Return:
			A tuple with the average colors for the neighbors,
			or None if there were no neighbors.
		"""
		x_coordinates = ((x + self.width  - 1) % self.width,  x, (x + 1) % self.width)
		y_coordinates = ((y + self.height - 1) % self.height, y, (y + 1) % self.height)
		red = green = blue = 0
		live_count = 0

		for n_y in y_coordinates:
			for n_x in x_coordinates:
				# Don't use the given coordinates for the count
				if n_x == x and n_y == y:
					continue

				world[n_y][n_x].neighbors += 1

				# Get colors from the current world
				cell = self.world[n_y][n_x]
				if cell.is_alive:
					red   += cell.color[0]
					green += cell.color[1]
					blue  += cell.color[2]
					live_count += 1

		# Return the average color of the neighbors.
		if live_count:
			return (int(red/live_count), int(green/live_count), int(blue/live_count))
		return None

	def next_state(self):
		"""Creates a new world from the current world state."""
		# Create a world of dead cells
		next_state = [[Cell() for c in range(self.width)] for r in range(self.height)]

		for y in range(self.height):
			for x in range(self.width):
				cell = self.world[y][x]

				if cell.neighbors == 0:
					continue

				if cell.neighbors == 3 or (cell.is_alive and cell.neighbors == 2):
					# A dead cell with 3 live neighbors is reborn
					# A live cell with 3 live neighbors continues to live
					# A live cell with 2 live neighbors continues to live
					next_state[y][x].set_alive()
					next_state[y][x].color = self.inform_neighbors(next_state, x, y)

		self.world = next_state
