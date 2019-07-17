main: prep main.o
	g++ stage/main.o -o bin/game

prep:
	mkdir -p stage bin

main.o: main.cpp main.h
	g++ -c main.cpp -o stage/main.o

clean:
	rm -rf bin stage
