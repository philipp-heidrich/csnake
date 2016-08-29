/********************************************************

 						cSNAKE
 			--------------------------------
 					Version: 0.0.1
 			--------------------------------

Compile with gcc:
Windows:
gcc -std=c99 csnake.c header/field.c header/console.c header/menu.c header/snake.c header/fruits.c header/game.c -o build/build.exe && .\build\build.exe
*********************************************************/
#include <stdio.h>
#include <conio.h>
#include <windows.h>

#include "header/console.h"
#include "header/snake.h"
#include "header/field.h"
#include "header/fruits.h"
#include "header/menu.h"

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

int boradLengthX = 50;
int boradLengthY = 10;
int board[50][10] = { 0 };

int sleepTimer = 30;
int pressedChar;

int main()
{
	// Clear console
	consoleClear();

	// Show menu
	// menuShow();

	while(1)
	{
		while(!kbhit())
		{
			// Delay
			Sleep(sleepTimer);

			// Set new fruit icon
			fruitsSetItem(&boradLengthY, &boradLengthX, &board);

			// Set snake
			snakeSetItem(&boradLengthY, &boradLengthX, &board);

			// Print display
			fieldInit(&boradLengthY, &boradLengthX, &board);
		}

		pressedChar = getch();

		// ESC
		if(pressedChar == 27)
		{
			consoleQuit();
		}

		// Up
		else if(pressedChar == UP)
		{
			snakeEditDirection(0);
		}

		// Right
		else if(pressedChar == RIGHT)
		{
			snakeEditDirection(1);
		}

		// Down
		else if(pressedChar == DOWN)
		{
			snakeEditDirection(2);
		}

		// Left
		else if(pressedChar == LEFT)
		{
			snakeEditDirection(3);
		}
	}


	return 0;
}
