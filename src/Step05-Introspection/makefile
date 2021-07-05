.phony: all clean run

clean:
	rm -rf build
	rm -rf dist

build_dir:
	mkdir -p build

dist_dir:
	mkdir -p dist

Tutorial: build_dir
	cd build && cmake .. && make

test: Tutorial
	cd build && ctest

dist: dist_dir Tutorial
	mv build/Tutorial dist

run: dist
	cd dist && ./Tutorial 1000

all: clean test dist run