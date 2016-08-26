#include <stdio.h>
#include <string.h>

#include "console.h"

void printHr();

const char 	placeSign 	= ' ';
const char 	borderSign 	= '#';
const char 	fruitSign 	= 'x';
const char 	snakeSign	= 'O';

char strpoints[100] = "Points";
int intPoints	= 0;

int fieldLengthY = 0;
int fieldLengthX = 0;

void printHr()
{
	printf("\t");

	for(int i = 0; i < fieldLengthX + 2; i++)
	{
		printf("%c", borderSign);
	}

	printf("\n");
}

void fieldDisplay(int *boardLengthX, int *boardLengthY, int *board[fieldLengthX][fieldLengthY])
{
	if(
		!fieldLengthY ||
		!fieldLengthX
	)
	{
		fieldLengthY = *boardLengthY;
		fieldLengthX = *boardLengthX;
	}

	// Clear console
	clearConsole();

	printf("\n\n\n");

	// HR
	printHr();

	// Field area
	for(int rowCnt = 0; rowCnt < fieldLengthY; rowCnt++)
	{
		printf("\t%c", borderSign);

		for(int columnCnt = 0; columnCnt < fieldLengthX; columnCnt++)
		{
			// Fruits
			if(board[rowCnt][columnCnt] == (int*) 1)
			{
				printf("%c", fruitSign);
			}

			// Snake
			else if(board[rowCnt][columnCnt] == (int*) 2)
			{
				printf("%c", snakeSign);
			}

			// Empty space
			else
			{
				printf("%c", placeSign);
			}
		}

		printf("%c", borderSign);
		printf("\n");
	}

	// HR
	printHr();

	// Point block
	for(int rowCnt = 0; rowCnt < 2; rowCnt++)
	{
		printf("\t");

		for(int columnCnt = 0; columnCnt < fieldLengthX + 2; columnCnt++)
		{
			// String Points
			if(rowCnt == 0 && columnCnt == 2)
			{
				printf("%s", strpoints);
			}

			// Int Points
			else if(rowCnt == 1 && columnCnt == 2)
			{
				printf("%i", intPoints);
			}

			// Border Signs
			else if(
				rowCnt == 0 && (columnCnt == 0 || columnCnt == fieldLengthX - strlen(strpoints) + 2) ||
				rowCnt == 1 && (columnCnt == 0 || columnCnt == fieldLengthX - ((intPoints < 10) ? 1 : 2) + 2)
			)
			{
				printf("%c", borderSign);
			}

			// Whitespaces
			else
			{
				printf("%c", placeSign);
			}
		}

		printf("\n");
	}

	// HR
	printHr();

	// Clear flush
	fflush(stdout);
}
