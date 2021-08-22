# WeatherStatistics Makefile by Olivia Stone for Code Clinic: C++
CC		= g++
TARGET	= WeatherStatistics.out
LIBSRC  = WeatherStatistics.cpp
SRC		= WeatherStatisticsMain.cpp
OBJS    = WeatherStatisticsMain.o WeatherStatistics.o

build_dir:
	mkdir -p build

dist_dir:
	mkdir -p dist

build/Makefile: build_dir
	cd build && cmake ..

build/weather-statistics: build_dir
	cd build && make

dist/weather-statistics: dist_dir build/weather-statistics
	mv build/weather-statistics dist

WeatherStatistics.o:
	$(CC) -c $(LIBSRC)

WeatherStatisticsMain.o:
	$(CC) -c WeatherStatisticsMain.cpp

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
