#pragma once
//C++ includes
#include <iostream>
#include <thread>
#include <chrono>

//C includes
#include <stdio.h>
#include <stdint.h>
#include <SDL2/SDL.h> 
//#include <SDL2/SDL_image.h> 
//#include <SDL2/SDL_timer.h> 
#include <GL/glew.h>
#include <string>
#include <unistd.h>

//Local includes
#include "sprite.h"
#include "glslProgram.h"
#include "err.h"

//Functions
uint8_t startRender(short int w, short int h);

extern float fTime;
