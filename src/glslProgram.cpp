#include "glslProgram.h"

using std::ifstream;

glslProgram::glslProgram() : _numAttributes(0), _programID(0), _vertID(0), _fragID(0)
{
	
}

glslProgram::~glslProgram()
{
	
}

void glslProgram::linkShaders()
{
	glAttachShader(_programID, _vertID);
	glAttachShader(_programID, _fragID);
	glLinkProgram(_programID);
	GLint isLinked = 0;
	glGetProgramiv(_programID, GL_LINK_STATUS, &isLinked);
	if (isLinked == GL_FALSE)
	{
		GLint maxLength = 0;
		glGetProgramiv(_programID, GL_INFO_LOG_LENGTH, &maxLength);

		// The maxLength includes the NULL character
		std::vector<char> infoLog(maxLength);
		glGetProgramInfoLog(_programID, maxLength, &maxLength, &infoLog[0]);
		
		// The program is useless now. So delete it.
		glDeleteProgram(_programID);
		printf("%s\n", &(infoLog[0]));
		errLog("SHADER LINKING FAILED");
		// Provide the infolog in whatever manner you deem best.
		// Exit with failure.
		return;
	}
	glDetachShader(_programID, _vertID);
	glDetachShader(_programID, _fragID);
	glDeleteShader(_vertID);
	glDeleteShader(_fragID);
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
		//cout << vertBuff << "\n";
		vertString += vertBuff + "\n";
	}
	//cout << vertString << "\n";
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
		std::vector<char> log(logLength);
		glGetShaderInfoLog(id, logLength, &logLength, &log[0]);
		glDeleteShader(id);
		printf("%s\n", &log[0]);
	}
}

void glslProgram::compileShaders(const string& vert, const string& frag)
{
	_programID = glCreateProgram();
	_vertID = glCreateShader(GL_VERTEX_SHADER);
	if(_vertID == 0)
	{
		errLog("Could not assign _vertID.",1001);
	}
	_fragID = glCreateShader(GL_FRAGMENT_SHADER);
	if(_fragID == 0)
	{
		errLog("Could not assign _fragID.",1001);
	}
	compileShader(vert, _vertID);
	compileShader(frag, _fragID);
}

GLuint glslProgram::getUniformLocation(const string& uniformName)
{
	GLuint rVal = glGetUniformLocation(_programID, uniformName.c_str());
	if(rVal == GL_INVALID_INDEX)
	{
		errLog("UNIFORM  " + uniformName + " NOT FOUND.");
	}
	return rVal;
}

void glslProgram::use()
{
	glUseProgram(_programID);
	for(int i = 0; i < _numAttributes; i++)
	{
		glEnableVertexAttribArray(i);
	}
}

void glslProgram::unuse()
{
	glUseProgram(0);
	for(int i = 0; i < _numAttributes; i++)
	{
		glDisableVertexAttribArray(i);
	}
}

void glslProgram::addAttribute(const string& atribName)
{
	glBindAttribLocation(_programID, _numAttributes++, atribName.c_str());
}
