# Life Implementations

Implementations of Conway's Game of Life in different languages, just for fun!

## C Implementation

Uses bits within a `char` to represent the alive state and number of neighbors for any given cell. Glut is used for drawing even though it's deprecated, I just wanted quick 'n dirty graphics with C! Run `make` from the project directory and you should get a binary on Linux or macOS.

![Life in C](https://raw.githubusercontent.com/codehearts/cest-la-vie/master/screenshots/life-c.gif)

## Python Implementation

Much less efficient than the C version, but I added some rules for coloring cells to make things interesting (spoiler alert: future generations just get muddier and muddier). Uses `pyglet` (my favorite) and `python3`, so just `pip3 install pyglet` and then `python3 main.py`

![Life in Python](https://raw.githubusercontent.com/codehearts/cest-la-vie/master/screenshots/life-python.gif)
