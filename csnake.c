/********************************************************

 						cSNAKE
 			--------------------------------
 					Version: 1.0.0
 			--------------------------------

Compile with gcc:
Windows:
gcc -std=c99 cSnake.c \
	header/field.c \
	header/console.c \
	header/menu.c \
	header/snake.c \
	header/fruits.c \
	header/game.c \
	header/pause.c \
	header/lost.c \
	header/file.c \
	-o build/cSnake.exe
*********************************************************/

/**
 *	Includes
 **/
#include <stdio.h>

#include "header/menu.h"
#include "header/pause.h"
#include "header/game.h"
#include "header/lost.h"

int main()
{
	menu_start();

	while(1)
	{
		// Show menu
		if(menu_getShowStatus())
		{
			menu_start();
		}

		// Game
		else if(game_getPlayStatus())
		{
			game_start();
		}

		// Pause
		else if(pause_getStatus())
		{
			pause_start();
		}

		// Game over
		else if(lost_getStatus())
		{
			lost_start();
		}
	}

	return 0;
}
