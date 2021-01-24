
CC = gcc
CFLAGS = -std=c99 -pedantic -Wall -Wextra
LDFLAGS = -lm -lncurses



all:
	$(CC) $(CFLAGS) -o 2048.exe 2048.c $(LDFLAGS)
	./2048.exe
#	$(CC) $(CFLAGS) -o ex03.exe ex03.c