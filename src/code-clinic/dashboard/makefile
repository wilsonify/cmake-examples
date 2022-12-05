all: clean dist/tutorial

.phony: all clean

ver_file = echo "1.0.0" > $(1) && date +%Y-%m-%d >> $(1)

clean:
	rm -rf build
	rm -rf MathFunctions/build
	rm -rf dist

build/VERSION.txt:
	mkdir -p build && $(call ver_file, $@)

dist/VERSION.txt:
	mkdir -p dist && $(call ver_file, $@)

build/tutorial: build/VERSION.txt
	cd build && cmake .. && make

test: build/tutorial
	cd build && ctest

build/tutorial-1.0.1-Linux.tar.gz: test
	cd build && cpack -C CPackConfig.cmake

dist/tutorial: test dist/VERSION.txt build/tutorial-1.0.1-Linux.tar.gz
	cp build/tutorial dist
	cp build/tutorial-1.0.1-Linux.tar.gz dist

run: dist/tutorial
	cd dist && ./tutorial 1000

build/docker-base.txt: build/VERSION.txt
	docker build -t dashboard-base:latest -f Dockerfile-base . && $(call ver_file, $@)

build/docker-builder.txt: build/docker-base.txt
	docker build -t dashboard-builder:latest -f Dockerfile-builder . && $(call ver_file, $@)

build/docker-image.txt: build/docker-builder.txt
	docker build -t dashboard:latest -f Dockerfile . && $(call ver_file, $@)

docker-run: build/docker-image.txt
	docker run --rm --name dashboard dashboard:latest 10000

dist/docker/tutorial: build/docker-builder.txt
	docker run --rm --name dashboard -u 1000:1000 -v $(shell pwd):/usr/src/app dashboard-builder:latest make all
