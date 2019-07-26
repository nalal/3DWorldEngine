#include "err.h"

void errLog(string err, int errCode)
{
	cout << "!FATAL ERROR!\n";
	string errType = "UNDEFINED ERROR CODE";
	if(errCode == 1001)
	{
		errType = "GLSL ERROR.";
	}
	cout << err << "\n";
}

