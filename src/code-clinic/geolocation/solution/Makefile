# Geolocation Makefile by Olivia Stone for Code Clinic: C++
CC		= g++
TARGET	= Geolocation.out
LIBSRC  = GeolocationRequest.cpp GeolocationWifiPoints.cpp cJSON.c
OBJS    = GeolocationMain.o GeolocationRequest.o GeolocationWifiPoints.o cJSON.o
SRC		= GeolocationMain.cpp GeolocationRequest.cpp GeolocationWifiPoints.cpp cJSON.c
LDLIBS	= -lcurl -lwlanapi

ver_file = echo "1.0.0" > $(1) && date +%Y-%m-%d >> $(1)

build/VERSION.txt:
	mkdir -p build && $(call ver_file, $@)

dist/VERSION.txt:
	mkdir -p dist && $(call ver_file, $@)

build/Makefile: build/VERSION.txt
	cd build && cmake ..

build/geolocation: build/VERSION.txt
	cd build && make

dist/geolocation: dist/VERSION.txt build/geolocation
	mv build/geolocation dist

GeolocationRequest.o:
	$(CC) -I curl/include -c GeolocationRequest.cpp

GeolocationWifiPoints.o:
	$(CC) -c GeolocationWifiPoints.cpp

cJSON.o:
	$(CC) -c cJSON.c

GeolocationMain.o:
	$(CC) -c GeolocationMain.cpp

WeatherStatistics.o:
	g++ -c external/weather-statistics/WeatherStatistics.cpp

WeatherStatisticsMain.o:
	g++ -c external/weather-statistics/WeatherStatisticsMain.cpp

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
