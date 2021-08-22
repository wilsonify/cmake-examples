# NQueens Makefile by Olivia Stone for Code Clinic: C++
CC		= g++
TARGET	= NQueens.out
LIBSRC  = NQueens.cpp
OBJS    = NQueensMain.o NQueens.o
SRC		= NQueensMain.cpp NQueens.cpp

build_dir:
	mkdir -p build

dist_dir:
	mkdir -p dist

build/Makefile: build_dir
	cd build && cmake ..

build/nqueens: build_dir
	cd build && make

dist/nqueens: dist_dir build/nqueens
	mv build/nqueens dist

NQueens.o:
	$(CC) -c NQueens.cpp

NQueensMain.o:
	$(CC) -c NQueensMain.cpp

NQueens.out: NQueensMain.o NQueens.o
	$(CC) -o $(TARGET) $(OBJS)

.PHONY: clean all

all: $(TARGET)

clean:
	rm -f *.out
	rm -f *.o
	rm -f *.o
	rm -rf build
	rm -rf dist
