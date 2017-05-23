targets = test

objects = test.o core.o

CC=g++
CFLAGS=-g

test: test.o core.o

test.o: test.cpp core.h

core.o: core.cpp core.h


clean :
				rm $(targets) $(objects)
