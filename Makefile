CC = gcc
CFLAGS = -fsanitize=address -Wall -O2

tree: main.c tree.o
	$(CC) $(CFLAGS) $^ -o tree

tree.o: tree.c tree.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f tree.o
