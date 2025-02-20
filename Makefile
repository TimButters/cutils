CC = gcc
CFLAGS = -fsanitize=address -Wall -O2 -Iinclude -g
BUILDDIR = build

bin/cutils: $(wildcard tests/*.c) $(wildcard build/*.o)
	$(CC) $(CFLAGS) $^ -o $@

build/tree.o: src/tree.c include/tree.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f build/tree.o
