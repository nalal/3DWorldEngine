#include "glslProgram.h"

glslProgram::glslProgram() : _programID(0), _vertID(0), _fragID(0)
{
	
}

glslProgram::~glslProgram()
{
	
}

void glslProgram::compileShaders(const string& vert, const string& frag)
{
	_vertID = glCreateShader(GL_VERTEX_SHADER);
	if(_vertID == 0)
	{
		errLog("Could not assign _vertID.");
	}
	_fragID = glCreateShader(GL_FRAGMENT_SHADER);
	if(_fragID == 0)
	{
		errLog("Could not assign _fragID.");
	}
}

void glslProgram::lingShaders()
{
	
}
