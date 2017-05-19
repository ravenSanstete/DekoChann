targets = main

objects = main.o tensor.o hub.o

CC=gcc
CFLAGS=-g

main: main.o tensor.o hub.o

main.o: main.c tensor.h

tensor.o: tensor.c tensor.h hub.h

hub.o: hub.c hub.h



clean :
				rm $(targets) $(objects)
