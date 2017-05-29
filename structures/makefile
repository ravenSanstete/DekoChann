targets = test

objects = heap.o test.o *.gch

CC=g++
CXXFLAGS=$(COMPILERFLAGS) -g $(INCDIRS)

test: test.o heap.o

test.o: test.cpp heap.h

heap.o: heap.cpp heap.h


clean :
				rm -f $(targets) $(objects)
