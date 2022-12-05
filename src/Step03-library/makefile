all: clean dist/tutorial

.phony: all clean

ver_file = echo "1.0.0" > $(1) && date +%Y-%m-%d >> $(1)

clean:
	rm -rf build
	rm -rf dist

build/VERSION.txt:
	mkdir -p build && $(call ver_file, $@)

dist/VERSION.txt:
	mkdir -p dist && $(call ver_file, $@)

build/tutorial: build/VERSION.txt
	cd build && cmake .. && make

dist/tutorial: build/tutorial dist/VERSION.txt
	mv build/tutorial dist/tutorial

test: Tutorial
	cd build && ctest

run: dist/tutorial
	cd dist && ./tutorial 1000

build/docker-base.txt: build/VERSION.txt
	docker build -t step03-library-base:latest -f Dockerfile-base . && $(call ver_file, $@)

build/docker-builder.txt: build/docker-base.txt
	docker build -t step03-library-builder:latest -f Dockerfile-builder . && $(call ver_file, $@)

build/docker-image.txt: build/docker-builder.txt
	docker build -t step03-library:latest -f Dockerfile . && $(call ver_file, $@)

docker-run: build/docker-image.txt
	docker run --rm --name step03-library step03-library:latest 10000

dist/docker/tutorial: build/docker-builder.txt
	docker run --rm --name step03-library-builder -u 1000:1000 -v $(shell pwd):/usr/src/app step03-library-builder:latest make all
