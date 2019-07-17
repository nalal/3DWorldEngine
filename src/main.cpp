//Includes
#include "main.h"

using std::cout;

int main(uint8_t argc, char *argv[])
{
	cout << "Hello world!\n";
	uint8_t test = render();
	if(test == 0)
	{
		cout << "Render loaded.\n";
	}
	if(argc > 1)
	{
		cout << "Args:\n";
		for(uint8_t i = 1; i != argc; i++)
		{
			cout << argv[i] << "\n";
		}
	}
	return 0;
}
