targets = main

objects = main.o matrix.o

CC=gcc
CFLAGS=-g

main: main.o matrix.o

main.o: main.c matrix.h

matrix.o: matrix.c matrix.h





clean :
				rm $(targets) $(objects)
