CXX = g++
SOURCES = $(wildcard *.cpp)

main: $(SOURCES)
	$(CXX) -std=c++17 $(SOURCES) -o main
