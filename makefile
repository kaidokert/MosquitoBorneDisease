CC=g++
CFLAGS=-I "/Volumes/OS X EL CAPITAN/Dropbox/Useful_C++/eigen-eigen-b9cd8366d4e8/" -std=c++14 -Wall
SOURCES=src/*.c*
OBJECTS=*.o

everything:
	$(CC) $(CFLAGS) -c $(SOURCES)
	$(CC) $(OBJECTS) -o bin/run
	rm -rf *.o

all: $(OBJECTS)
	$(CC) $(OBJECTS) -o bin/run

main.o: src/main.cpp
	$(CC) $(CFLAGS) -c src/main.cpp

agent.o: src/agent.cpp src/agent.hpp
	$(CC) $(CFLAGS) -c src/agent.cpp

nonparasite.o: src/world.cpp src/nonparasite.hpp
		$(CC) $(CFLAGS) -c src/nonparasite.cpp

world.o: src/world.cpp src/world.hpp
	$(CC) $(CFLAGS) -c src/world.cpp

simulation.o: src/simulation.cpp src/simulation.hpp
	$(CC) $(CFLAGS) -c src/simulation.cpp

location.o: src/location.cpp src/location.hpp
	$(CC) $(CFLAGS) -c src/location.cpp

clean:
	rm -rf *.o
