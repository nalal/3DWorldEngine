//Includes
#include "render.h"

using std::cout;
using std::cin;
using std::string;

enum class GameState {PLAY,STOP};
short int _screenWidth, _screenHeight;

GameState currentState;

void initSDL()
{
	cout << "Initializing SDL.\n";
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* _window = NULL;
	_window = SDL_CreateWindow(
		"3D World", 
		SDL_WINDOWPOS_CENTERED, 
		SDL_WINDOWPOS_CENTERED,
		_screenWidth, 
		_screenHeight,
		SDL_WINDOW_OPENGL
	);
	//cout << "Got command " << holder << ".\n";
}

void setRes(short int width, short int height)
{
	_screenWidth = width;
	_screenHeight = height;
}

void setState(uint8_t i)
{
	if(i == unsigned(0))
	{
		currentState = GameState::PLAY;
	}
	else
	{
		currentState = GameState::STOP;
	}
}

void killLoop()
{
	cout << "Got halt signal.\n";
	setState(1);
}

void getInput()
{
	SDL_Event getKillKey;
	while(SDL_PollEvent(&getKillKey))
	{
		switch(getKillKey.type)
		{
			case SDL_QUIT:
				killLoop();
				break;
		}
	}
}

uint8_t startRender(short int w, short int h)
{
	setRes(w,h);
	setState(unsigned(0));
	initSDL();
	while(currentState == GameState::PLAY)
	{
		getInput();
	}
	return 0;
}
