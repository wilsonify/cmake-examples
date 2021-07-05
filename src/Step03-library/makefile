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

dist: dist_dir Tutorial
	mv build/Tutorial dist

run: dist
	cd dist && ./Tutorial -25

all: clean run