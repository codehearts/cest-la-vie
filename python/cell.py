import random

class Cell(object):
	"""
	Represents a cell in the game of life.

	A cell can be either alive or dead.

	Properties:
		[bool] is_alive: True if the cell is alive,
		                 False if it is dead.
		[int] neighbors: The number of live neighbors this cell has.
		[mixed] color: A tuple of 3 values between 0 and 255,
		               used to represent an RGB color. Dead cells
					   have their color set to None.
	"""

	def __init__(self, alive=False):
		"""
		Creates a new cell.
		
		Arguments:
			[bool] alive: True if the cell should be alive,
			              False otherwise. (Defaults to False)
		"""
		super(Cell, self).__init__()

		self.is_alive  = bool(alive)
		self.neighbors = 0
		self.color     = None

	def set_random_color(self):
		"""Returns a tuple of 3 integer values between 0 and 255."""
		self.color = tuple(random.randint(0, 255) for x in range(3))

	def set_dead(self):
		"""Marks this cell as dead."""
		self.is_alive = False

	def set_alive(self):
		"""Marks this cell as alive."""
		self.is_alive = True
