/**
 *	Includes
 **/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "game.h"


/**
 *	Definition
 **/
#include "fruits.h"


/**
 *	Variables
 **/
int fruitPosY 	= -1;
int fruitPosX 	= -1;
int lastFruit 	= -1;
int fruitIs 	= 0;

int fruitsDelay = 1;


/**
 *	Functions
 **/
int randr(int max)
{
	return rand() % (max);
}

void fruitsDeleteItem(int *boardLengthY, int *boardLengthX, int *board[*boardLengthY][*boardLengthX])
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

void fruitsSetItem(int *boardLengthY, int *boardLengthX, int *board[*boardLengthX][*boardLengthX])
{
	// Set timestamp
	if(lastFruit == -1)
	{
		lastFruit = (int)time(NULL);
	}

	// Check if fruit to old
	if(
		fruitIs == 1 &&
		(int)time(NULL) - lastFruit > 5
	)
	{
		fruits_reset();

		fruitIs = 0;
		lastFruit = (int)time(NULL);
	}

	// Check is a valid fruit on the field
	if(
		fruitIs == 0 &&
		(int)time(NULL) - lastFruit > fruitsDelay
	)
	{
		// Reset variables
		fruitIs = 1;

		fruitPosY = randr(*boardLengthY);
		fruitPosX = randr(*boardLengthX);

		// Set new fruit sign
		board[fruitPosY][fruitPosX] = (int*) 1;

		printf("%i\n", fruitPosY);
		printf("%i\n", fruitPosX);
	}
}


void fruits_touchedFruit(int fruitPosY, int fruitPosX)
{
	// Add 100 points to accouint
	game_addPoints();

	// Save current time
	lastFruit = (int)time(NULL);

	// Save fruit var to not in use
	fruitIs = 0;
}


/**
 *	Reset fruits
 **/
void fruits_reset()
{
	fruitPosY = -1;
	fruitPosX = -1;
	lastFruit = -1;
	fruitIs = 0;
}
