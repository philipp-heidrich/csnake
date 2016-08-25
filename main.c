#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "header/console.h"
#include "header/field.h"
#include "header/menu.h"

/********************************************************
						cSNAKE
			--------------------------------
					Version: 0.0.1
			--------------------------------

Compile with gcc:
Windows:
gcc -std=c99 \
	main.c \
	header/field.c \
	header/console.c \
	header/menu.c \
	-o build/build.exe \
	&& ./build/build.exe
*********************************************************/

int main()
{
	// Clear console
	clearConsole();

	char pressedChar;

	// printf("1 - Start\n");
	// printf("x - Beenden\n");
	// fflush(stdout);

	menuShow();

	while(1)
	{
		// fieldDisplay();

		fflush(stdout);

		Sleep(500);
	}


	return 0;
}
