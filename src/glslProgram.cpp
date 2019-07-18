#include "glslProgram.h"

using std::ifstream;

glslProgram::glslProgram() : _programID(0), _vertID(0), _fragID(0)
{
	
}

glslProgram::~glslProgram()
{
	
}

void glslProgram::compileShader(const string& path, GLuint id)
{

	ifstream vertFile(path);
	if(vertFile.fail())
	{
		errLog("Vertex file failed to load at:");
		errLog(path);
	}
	string vertString = "";
	string vertBuff;
	
	while(std::getline(vertFile, vertBuff))
	{
		vertString += vertBuff;
	}
	vertFile.close();
	const char* vertChar = vertString.c_str();
	glShaderSource(id, 1, &vertChar, NULL);
	glCompileShader(id);
	
	GLint pass = 0;
	glGetShaderiv(id, GL_COMPILE_STATUS, &pass);
	if(pass == GL_FALSE)
	{
		errLog("Vertex failed to compile from:");
		errLog(path);
		GLint logLength = 0;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &logLength);
		GLchar * log[logLength];
		glGetShaderInfoLog(id, logLength, &logLength, log[0]);
		glDeleteShader(id);
		printf("%s\n", &log[0]);
	}
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
	compileShader(vert, _vertID);
	compileShader(frag, _fragID);
}

void glslProgram::linkShaders()
{
	
}
