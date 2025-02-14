CC = gcc
CFLAGS = -fsanitize=address -Wall -O2 -Iinclude -g
BUILDDIR = build

bin/tree: tests/main.c build/tree.o
	$(CC) $(CFLAGS) $^ -o $@

build/tree.o: src/tree.c include/tree.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f build/tree.o
