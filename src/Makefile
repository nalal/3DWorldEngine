main: prep main.o render.o sprite.o glslProgram.o err.o
	g++ stage/main.o stage/sprite.o stage/render.o stage/err.o stage/glslProgram.o -lpthread -lSDL2 -lGLEW -lGL -o bin/game

prep:
	mkdir -p stage bin

main.o: main.cpp main.h
	g++ -c main.cpp -o stage/main.o

render.o: render.cpp render.h
	g++ -c render.cpp -o stage/render.o

sprite.o: sprite.cpp sprite.h
	g++ -c sprite.cpp -o stage/sprite.o

glslProgram.o: glslProgram.cpp glslProgram.h
	g++ -c glslProgram.cpp -o stage/glslProgram.o

err.o: err.cpp err.h
	g++ -c err.cpp -o stage/err.o

clean:
	rm -rf bin stage
