#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int fruitPosY 	= -1;
int fruitPosX 	= -1;
int lastFruit 	= -1;
int fruitIs 	= 0;

int randr(int max)
{
	return rand() % (max);
}

void fruitsDeleteItem(int *boardLengthX, int *boardLengthY, int * board[*boardLengthX][*boardLengthY])
{
	// Set fruit to 0
	fruitIs = 0;

	// Set current timestamp
	lastFruit = (int)time(NULL);

	// Delete old fruit sign
	for(int i = 0; i < *boardLengthY; i++)
	{
		for(int e = 0; e < *boardLengthX; e++)
		{
			if(board[i][e] == (int*) 1)
			{
				board[i][e] = 0;
			}
		}
	}
}

void fruitsSetItem(int *boardLengthX, int *boardLengthY, int * board[*boardLengthX][*boardLengthY])
{
	// Set timestamp
	if(lastFruit == -1)
	{
		lastFruit = (int)time(NULL);
	}

	// Check is a valid fruit on the field
	if(
		fruitIs == 0 &&
		(int)time(NULL) - lastFruit > 4
	)
	{
		// Reset variables
		fruitIs = 1;

		fruitPosY = randr(*boardLengthY);
		fruitPosX = randr(*boardLengthX);

		// Set new fruit sign
		board[fruitPosY][fruitPosX] = (int*) 1;
	}
}
