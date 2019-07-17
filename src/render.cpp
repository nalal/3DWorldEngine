//Includes
#include "render.h"

using std::cout;
using std::cin;
using std::string;

Sprite _sprite;
enum class GameState {PLAY,STOP};
short int _screenWidth, _screenHeight;

SDL_Window* _window;
int frameRate;

GameState currentState;

void drawObj()
{

	glEnableClientState(GL_COLOR_ARRAY);
	glBegin(GL_TRIANGLES);
		glColor3f(0.0f,1.0f,0.0f);
		glVertex2f(0,0);
		glVertex2f(0,1);
		glVertex2f(1,1);
	glEnd();

}

void initSDL()
{
	cout << "Initializing SDL.\n";
	SDL_Init(SDL_INIT_EVERYTHING);
	_window = NULL;
	_window = SDL_CreateWindow(
		"3D World", 
		SDL_WINDOWPOS_CENTERED, 
		SDL_WINDOWPOS_CENTERED,
		_screenWidth, 
		_screenHeight,
		SDL_WINDOW_OPENGL
	);
	
	if(_window == NULL)
	{
		errLog("SLD_Window init failure.");
	}
	
	SDL_GLContext glContext = SDL_GL_CreateContext(_window);
	if(glContext == NULL)
	{
		errLog("SDL_GL_CreateContext failure.");
	}
	
	GLenum error = glewInit();
	if(error != GLEW_OK)
	{
		errLog("glewInit failure.");
	}
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
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
	SDL_Event getIn;
	while(SDL_PollEvent(&getIn))
	{
		switch(getIn.type)
		{
			case SDL_QUIT:
				killLoop();
				break;
			case SDL_MOUSEMOTION:
				cout << "X:" << getIn.motion.x << " Y:" << getIn.motion.y 
				<< "\n";
		}
	}
}

void printFrames()
{
	while(currentState == GameState::PLAY)
	{
		cout << "FPS: " << frameRate << "\n";
		frameRate = 0;
		sleep(1);
	}
}

uint8_t startRender(short int w, short int h)
{
	setRes(w,h);
	setState(unsigned(0));
	initSDL();
	_sprite.init(-1,-1,1,1);
	glClearDepth(1.0f);
	std::thread (printFrames).detach();
	while(currentState == GameState::PLAY)
	{
		frameRate = frameRate + 1;
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		getInput();
		//drawObj();
		_sprite.draw();
		SDL_GL_SwapWindow(_window);
	}
	return unsigned(0);
}
