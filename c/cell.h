#ifndef CELL_H
#define CELL_H

typedef unsigned char cell_t;

#define cell_is_alive(c)  (c & 0x1u)
#define cell_neighbors(c) (c >> 1)
#define set_cell_live(c) (c |= 0x1u)
#define kill_cell(c) (c &= 0x30u)

#endif
