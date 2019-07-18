//C++ includes
#include <string>
#include <fstream>
//C includes
#include <GL/glew.h>

//Local includes
#include "err.h"

//Funcitons
using std::string;

//Objects
class glslProgram
{
	public:
		glslProgram();
		~glslProgram();
		
		void compileShaders(const string& vert, const string& frag);
		void linkShaders();
	private:
		GLuint _programID;
		GLuint _vertID;
		GLuint _fragID;
		void compileShader(const string& path, GLuint id);
};
