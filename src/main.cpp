//Includes
#include "main.h"

using std::cout;

int main(uint8_t argc, char *argv[])
{
	int h = 1024;
	int w = 768;
	cout << "Starting Program,\n";
	
	if(argc > 2)
	{
		cout << "Setting resolution to console specified.\n";
		char *p;
		long hl = strtol(argv[1], &p, 10);
		long wl = strtol(argv[2], &p, 10);
		h = hl;
		w = wl;
		cout << "Args:\n";
		for(uint8_t i = 1; i != argc; i++)
		{
			cout << unsigned(i) << ". " << argv[i] << ".\n";
		}
	}
	cout << "Rendering to resolution " << h << "x" << w << ".\n";
	uint8_t test = startRender(h,w);
	if(test == 0)
	{
		cout << "Render loop ran through.\n";
	}

	return 0;
}
