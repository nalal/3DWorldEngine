main: prep main.o render.o
	g++ stage/main.o stage/render.o -o bin/game

prep:
	mkdir -p stage bin

main.o: main.cpp main.h
	g++ -c main.cpp -o stage/main.o

render.o: render.cpp render.h
	g++ -c render.cpp -o stage/render.o

clean:
	rm -rf bin stage
