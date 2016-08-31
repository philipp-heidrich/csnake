/**
 *	Includes
 **/
#include <stdio.h>
#include <windows.h>

#include "console.h"
#include "fruits.h"
#include "game.h"


/**
 *	Definition
 **/
#include "snake.h"


/**
 *	Variables
 **/
int snakeDirection = 2;		// 0 - top | 1 - right | 2 - bottom | 3 - left
int snake_inUse = 0;

struct coordinate {
    int x;
    int y;
	int direction;
};

typedef struct coordinate coordinate;
int snake_arrayCnt = 0;
coordinate snakeArray[10000];
coordinate lastItem;


/**
 *	Functions
 **/
void snakeSetItem(int *boardLengthY, int *boardLengthX, int *board[*boardLengthY][*boardLengthX])
{
	if(!snake_inUse)
	{
		snakeArray[snake_arrayCnt].y = *boardLengthY / 2;
		snakeArray[snake_arrayCnt].x = *boardLengthX / 2;
		snakeArray[snake_arrayCnt].direction = snakeDirection;

		snake_inUse = 1;
	}
	else
	{
		// Delete old snake position
		snakeDeletePosition(boardLengthY, boardLengthX, board);

		// Set new snake position
		snakeNewPosition(boardLengthY, boardLengthX);

		// Check have the snake contact with a fruit
		snake_contactFruit(boardLengthY, boardLengthX, board);
	}

	// Check have the snake contact with oneself
	if(snake_contactSelf())
	{
		// Go to lost site
		console_goTo(3);
	}

	// Print snake
	else
	{
		snake_printSnake(boardLengthY, boardLengthX, board);
	}
}


/**
 *	Edit snake direction
 **/
void snakeEditDirection(int direction)
{
	snakeDirection = direction;
}


void snakeDeletePosition(int *boardLengthY, int *boardLengthX, int *board[*boardLengthY][*boardLengthX])
{
	// Delete old snake sign
	for(int i = 0; i < *boardLengthY; i++)
	{
		for(int e = 0; e < *boardLengthX; e++)
		{
			if(board[i][e] == (int*) 2)
			{
				board[i][e] = 0;
			}
		}
	}
}

void snakeNewPosition(int *boardLengthY, int *boardLengthX)
{
	for(int i = snake_arrayCnt; i > -1; i--)
	{
		// Save last element
		if(snake_arrayCnt == i)
		{
			lastItem.y = snakeArray[i].y;
			lastItem.x = snakeArray[i].x;
			lastItem.direction = snakeArray[i].direction;
		}

		if(!i)
		{
			if(snakeDirection == 0)
			{
				snakeArray[i].y--;
			}
			else if(snakeDirection == 1)
			{
				snakeArray[i].x++;
			}
			else if(snakeDirection == 2)
			{
				snakeArray[i].y++;
			}
			else if(snakeDirection == 3)
			{
				snakeArray[i].x--;
			}

			// Check if snake over the top
			if(snakeArray[i].y < 0)
			{
				snakeArray[i].y = *boardLengthY - 1;
			}
			else if(snakeArray[i].y > *boardLengthY - 1)
			{
				snakeArray[i].y = 0;
			}
			else if(snakeArray[i].x < 0)
			{
				snakeArray[i].x = *boardLengthX - 1;
			}
			else if(snakeArray[i].x > *boardLengthX - 1)
			{
				snakeArray[i].x = 0;
			}
		}
		else
		{
			snakeArray[i].y = snakeArray[i - 1].y;
			snakeArray[i].x = snakeArray[i - 1].x;
			snakeArray[i].direction = snakeArray[i - 1].direction;
		}
	}
}

/**
 *	Check if have the snake contact with a fruit
 **/
void snake_contactFruit(int *boardLengthY, int *boardLengthX, int *board[*boardLengthY][*boardLengthX])
{
	if(board[snakeArray[0].y][snakeArray[0].x] == (int*) 1)
	{
		// Add new process length
		game_setNewLives(0);

		// Add +1 to Length
		game_addOneLength();

		// Edit fruit
		fruits_touchedFruit(snakeArray[0].y, snakeArray[0].x);

		// Dublicate last element
		snake_arrayCnt++;
		snakeArray[snake_arrayCnt].y = lastItem.y;
		snakeArray[snake_arrayCnt].x = lastItem.x;
		snakeArray[snake_arrayCnt].direction = lastItem.direction;
	}
}


/**
 *	Check have the snake contact with oneself
 **/
int snake_contactSelf()
{
	int returnContact = 0;

	for(int e = 1; e <= snake_arrayCnt; e++)
	{
		if(
			snakeArray[0].y == snakeArray[e].y &&
			snakeArray[0].x == snakeArray[e].x
		)
		{
			returnContact = 1;
			break;
		}
	}

	return returnContact;
}


/**
 *	Print snake
 **/
void snake_printSnake(int *boardLengthY, int *boardLengthX, int *board[*boardLengthY][*boardLengthX])
{
	for(int i = 0; i <= snake_arrayCnt; i++)
	{
		board[snakeArray[i].y][snakeArray[i].x] = (int*) 2;
	}
}


/**
 *	Reset snake
 **/
void snake_reset()
{
	snake_inUse = 0;
	snake_arrayCnt = 0;
	snakeDirection = 2;
}
