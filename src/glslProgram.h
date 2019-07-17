//C++ includes
#include <string>

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
		void lingShaders();
	private:
		GLuint _programID;
		GLuint _vertID;
		GLuint _fragID;
};
