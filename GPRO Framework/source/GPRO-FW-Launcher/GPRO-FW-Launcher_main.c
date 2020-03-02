// GPRO-FW-Launcher.c/.cpp

#include <stdio.h>
#include <Windows.h>
#include "_general/_macros.h"

//custom debug print
#if (defined _DEBUG || defined DEBUG)
#define LINE(line) line		\
	printf("\n TEXT: %s \n FILE: %s \n LINE: %u \n DATE: %s \n TIME: %s \n",	\
		token_str(line),	\
		__FILE__,			\
		__LINE__,			\
		__DATE__,			\
		__TIME__			\
	)

#else //NDEBUG
#define LINE(line) line

#endif //_DEBUG || DEBUG

int main()
{
	printf("\n--- BEGINNING OF MAIN --- \n\n");
	
	int test = 3;

	LINE(
		test = 7;
	);

	printf("\n %d \n", test);

	printf("\n\n END OF MAIN \n\n");
	return 0;
}
