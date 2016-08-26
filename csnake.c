/********************************************************

 						cSNAKE
 			--------------------------------
 					Version: 0.0.1
 			--------------------------------

Compile with gcc:
Windows:
gcc -std=c99 csnake.c header/field.c header/console.c header/menu.c header/snake.c header/fruits.c -o build/build.exe && .\build\build.exe
*********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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

int boradLengthX = 20;
int boradLengthY = 20;
int board[20][20] = { 0 };

int sleepTimer = 200;
int pressedChar;


int main()
{
	// Clear console
	clearConsole();

	// Show menu
	// menuShow();

	while(1)
	{
		while(!kbhit())
		{
			// Delay
			Sleep(sleepTimer);

			// Set new fruit icon
			fruitsSetItem(&boradLengthX, &boradLengthY, &board);

			// Set snake
			snakeSetItem(&boradLengthX, &boradLengthY, &board);

			// Print display
			fieldDisplay(&boradLengthX, &boradLengthY, &board);
		}

		pressedChar = getch();

		// ESC
		if(pressedChar == 27)
		{
			system("cls");
			exit(0);
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
