#include <stdio.h>
#include <windows.h>

void snakeSetItem();
void snakeDeletePosition();
void snakeNewPosition();
void snakeEditDirection();

int snakeLength = 1;
int snakePositionY = -1;
int snakePositionX = -1;
int snakeDirection = 2;		// 0 - top
							// 1 - right
							// 2 - bottom
							// 3 - left

void snakeSetItem(int *boardLengthX, int *boardLengthY, int * board[*boardLengthX][*boardLengthY])
{
	if(
		snakePositionY == -1 &&
		snakePositionX == -1
	)
	{
		snakePositionX = *boardLengthX / 2;
		snakePositionY = *boardLengthY / 2;
	}
	else
	{
		snakeDeletePosition(boardLengthY, boardLengthX, board);
		snakeNewPosition(boardLengthY, boardLengthX);
	}

	board[snakePositionY][snakePositionX] = (int*) 2;
}


/**
 *	Edit snake direction
 **/
void snakeEditDirection(int direction)
{
	snakeDirection = direction;
}


void snakeDeletePosition(int *boardLengthX, int *boardLengthY, int * board[*boardLengthX][*boardLengthY])
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
	if(snakeDirection == 0)
	{
		snakePositionY--;
	}
	else if(snakeDirection == 1)
	{
		snakePositionX++;
	}
	else if(snakeDirection == 2)
	{
		snakePositionY++;
	}
	else if(snakeDirection == 3)
	{
		snakePositionX--;
	}

	// Check if snake over the top
	if(snakePositionY < 0)
	{
		snakePositionY = *boardLengthY - 1;
	}
	else if(snakePositionY > *boardLengthY - 1)
	{
		snakePositionY = 0;
	}
	else if(snakePositionX < 0)
	{
		snakePositionX = *boardLengthX - 1;
	}
	else if(snakePositionX > *boardLengthX - 1)
	{
		snakePositionX = 0;
	}
}
