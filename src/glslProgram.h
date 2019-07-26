//C++ includes
#include <string>
#include <fstream>
#include <vector>


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
		void addAttribute(const string& atribName);
		void compileShaders(const string& vert, const string& frag);
		void linkShaders();
		void use();
		void unuse();
		GLuint getUniformLocation(const string& uniformName);
	private:
		int _numAttributes;
		GLuint _programID;
		GLuint _vertID;
		GLuint _fragID;
		void compileShader(const string& path, GLuint id);
};
