# WeatherStatistics Makefile for Code Clinic: C++
.PHONY: clean all
all: clean dist/weather-statistics

ver_file = echo "1.0.0" > $(1) && date +%Y-%m-%d >> $(1)

clean:
	rm -f *.out
	rm -f *.o
	rm -f *.o
	rm -rf build
	rm -rf dist

build/VERSION.txt:
	mkdir -p build && $(call ver_file, $@)

dist/VERSION.txt:
	mkdir -p dist && $(call ver_file, $@)

build/Makefile: build/VERSION.txt
	cd build && cmake ..

build/weather-statistics: build/Makefile build/VERSION.txt
	cd build && make

dist/weather-statistics: dist/VERSION.txt build/weather-statistics
	cp build/weather-statistics dist

build/docker-base.txt: build/VERSION.txt
	docker build -t weather-statistics-base:latest -f Dockerfile-base . && $(call ver_file, $@)

build/docker-builder.txt: build/docker-base.txt
	docker build -t weather-statistics-builder:latest -f Dockerfile-builder . && $(call ver_file, $@)

build/docker-image.txt: build/docker-builder.txt
	docker build -t weather-statistics:latest -f Dockerfile . && $(call ver_file, $@)

dist/docker/tutorial: build/docker-builder.txt
	docker run --rm --name step01-builder -u 1000:1000 -v $(shell pwd):/usr/src/app weather-statistics-builder:latest make all
