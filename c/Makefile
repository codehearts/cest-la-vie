CC=gcc
CFLAGS=-Wall -Wno-deprecated-declarations
LFLAGS=-framework OpenGL -framework GLUT

SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=.o)
TARGETS=life

life: $(OBJS)
	$(CC) $(CFLAGS) $(LFLAGS) -o $@ $^

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *~ *.o $(TARGETS)
