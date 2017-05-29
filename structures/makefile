targets = test

objects = heap.o

CC=g++
CFLAGS=-g

test: test.o heap.o

test.o: test.cpp heap.h
	$(CC) -c test.cpp heap.h $(CFLAGS)

heap.o: heap.cpp heap.h
	$(CC) -c heap.cpp heap.h $(CFLAGS)


clean :
				rm $(targets) $(objects)
