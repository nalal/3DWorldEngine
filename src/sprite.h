//C++ uncludes
#include <cstddef>
//C includes
#include <GL/glew.h>
//Local includes
#include "vert.h"
class Sprite
{
	public:
		Sprite();
		~Sprite();
		void init(float x, float y, float width, float height);
		void draw();
	private:
		float _x;
		float _y;
		float _width;
		float _height;
		GLuint _vboID;
};
