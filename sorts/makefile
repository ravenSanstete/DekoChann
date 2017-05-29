targets = test

objects = test.o core.o $(DSPATH)heap.o *.gch

CC=g++
CXXFLAGS=$(COMPILERFLAGS) -g $(INCDIRS)
DSPATH = ../structures/



test: test.o core.o $(DSPATH)heap.o

test.o: test.cpp core.h

core.o: core.cpp core.h $(DSPATH)heap.h

heap.o: $(DSPATH)heap.cpp $(DSPATH)heap.h

clean :
				rm -f $(targets) $(objects)
