CC = cc
CFLAGS = -std=c99 -Wall -Wextra -Wpedantic -Werror
SOURCES = bitset.c

install: libbitset.a
	cp libbitset.a /usr/lib

libbitset.a: bitset.o
	ar -rc libbitset.a bitset.o

bitset.o: bitset.c
	CC $(CFLAGS) -c bitset.c
