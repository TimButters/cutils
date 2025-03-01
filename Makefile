CC = gcc
CFLAGS = -fsanitize=address -Wall -O2 -Iinclude -g
BUILDDIR = build

bin/cutils: $(wildcard tests/*.c) build/tree.o build/hashset.o
	$(CC) $(CFLAGS) $^ -o $@

build/tree.o: src/tree.c include/tree.h
	$(CC) $(CFLAGS) -c $< -o $@
	
build/hashset.o: src/hashset.c include/hashset.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f build/tree.o
