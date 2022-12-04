.PHONY: clean all

ver_file = echo "1.0.0" > $(1) && date +%Y-%m-%d >> $(1)
all: clean dist/n-queens

clean:
	rm -rf build
	rm -rf dist

build/VERSION.txt:
	mkdir -p build && $(call ver_file, $@)

dist/VERSION.txt:
	mkdir -p dist && $(call ver_file, $@)

build/Makefile: build/VERSION.txt
	cd build && cmake ..

build/n-queens: build/Makefile build/VERSION.txt
	cd build && make

dist/n-queens: dist/VERSION.txt build/n-queens
	cp build/n-queens dist

run: dist/n-queens
	cd dist && ./n-queens 10

build/docker-base.txt: build/VERSION.txt
	docker build -t n-queens-base:latest -f Dockerfile-base . && $(call ver_file, $@)

build/docker-builder.txt: build/docker-base.txt
	docker build -t n-queens-builder:latest -f Dockerfile-builder . && $(call ver_file, $@)

build/docker-image.txt: build/docker-builder.txt
	docker build -t n-queens:latest -f Dockerfile . && $(call ver_file, $@)

dist/docker/n-queens: build/docker-builder.txt
	docker run --rm --name n-queens -u 1000:1000 -v $(shell pwd):/usr/src/app n-queens-builder:latest make all
