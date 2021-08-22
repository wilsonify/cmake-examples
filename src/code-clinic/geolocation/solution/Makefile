# Geolocation Makefile by Olivia Stone for Code Clinic: C++
CC		= g++
TARGET	= Geolocation.out
LIBSRC  = GeolocationRequest.cpp GeolocationWifiPoints.cpp cJSON.c
OBJS    = GeolocationMain.o GeolocationRequest.o GeolocationWifiPoints.o cJSON.o
SRC		= GeolocationMain.cpp GeolocationRequest.cpp GeolocationWifiPoints.cpp cJSON.c
LDLIBS	= -lcurl -lwlanapi

build_dir:
	mkdir -p build

dist_dir:
	mkdir -p dist

build/Makefile: build_dir
	cd build && cmake ..

build/geolocation: build_dir
	cd build && make

dist/geolocation: dist_dir build/geolocation
	mv build/geolocation dist

GeolocationRequest.o:
	$(CC) -I curl/include -c GeolocationRequest.cpp

GeolocationWifiPoints.o:
	$(CC) -c GeolocationWifiPoints.cpp

cJSON.o:
	$(CC) -c cJSON.c

GeolocationMain.o:
	$(CC) -c GeolocationMain.cpp

$(TARGET): WeatherStatisticsMain.o WeatherStatistics.o
	$(CC) -o $(TARGET) $(OBJS)

.PHONY: clean all

all: $(TARGET)

clean:
	rm -f *.out
	rm -f *.o
	rm -f *.o
	rm -rf build
	rm -rf dist
