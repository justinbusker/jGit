CXX = g++
SOURCES = $(wildcard *.cpp)
FLAGS = -std=c++17 -lssl -lcrypto

main: $(SOURCES)
	$(CXX) -std=c++17 $(SOURCES) -o main

clean:
	rm -r .jgit
