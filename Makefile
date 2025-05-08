CXX = g++
SOURCES = $(wildcard *.cpp)
INCLUDES = $(shell pkg-config --cflags --libs libcryptopp)
FLAGS = -std=c++17

main: $(SOURCES)
	$(CXX) $(INCLUDES) $(FLAGS) $(SOURCES) -o main

clean:
	rm -r .jgit
