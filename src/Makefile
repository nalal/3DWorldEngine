main: prep main.o render.o sprite.o
	g++ stage/main.o stage/sprite.o stage/render.o -lpthread -lSDL2 -lGLEW -lGL -o bin/game

prep:
	mkdir -p stage bin

main.o: main.cpp main.h
	g++ -c main.cpp -o stage/main.o

render.o: render.cpp render.h
	g++ -c render.cpp -o stage/render.o

sprite.o: sprite.cpp sprite.h
	g++ -c sprite.cpp -o stage/sprite.o

clean:
	rm -rf bin stage
