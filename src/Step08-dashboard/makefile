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

run: Tutorial
	build/Tutorial 1000

test: Tutorial
	cd build && ctest

installer: Tutorial
	cd build && cpack -C CPackConfig.cmake

dist: dist_dir installer
	mv build/library-1.0.1-Linux.tar.gz dist

all: clean test dist

dash: dist
	cd build && ctest -D Experimental