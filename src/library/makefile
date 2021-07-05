.phony: all clean

clean:
	rm -rf build
	rm -rf dist

build_dir:
	mkdir -p build

dist_dir:
	mkdir -p dist

all: build_dir
	cd build && cmake .. && make

dist: all dist_dir
	mv build/Tutorial dist