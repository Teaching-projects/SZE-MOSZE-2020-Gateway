OBJS=main.o
CXXFLAGS = -g -std=c++17

all: $(OBJS)
	g++ -o Until_death $(OBJS)

main.o: main.cpp
	g++ -c main.cpp $(CXXFLAGS)

clean:
	rm -f*.o