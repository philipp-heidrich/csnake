/**
 *	Includes
 **/
#include <stdio.h>
#include <string.h>

#include "console.h"
#include "game.h"


/**
 *	Definition
 **/
#include "field.h"


/**
 *	Variables
 **/
#define	placeSign 	' '
#define	borderSign  '#'
#define	fruitSign 	'x'
#define	snakeSign	'O'

char strpoints[] 	= "Points";
int intPoints		= 0;

char strLength[] 	= "Length";
int intLength		= 0;

char strLives[]		= "Lives";
int intProcess		= 0;

int fieldLengthY 	= 0;
int fieldLengthX 	= 0;


/**
 *	Functions
 **/
int getIntLength(int intNumber)
{
	int intLength = (intNumber < 10) ? 1 :
						(intNumber < 100) ? 2 :
							(intNumber < 1000) ? 3 :
								(intNumber < 10000) ? 4 :
									(intNumber < 100000) ? 5 : 6;

	return intLength;
}

void fieldInit(int *boardLengthY, int *boardLengthX, int *board[*boardLengthY][*boardLengthX])
{
	if(
		!fieldLengthY ||
		!fieldLengthX
	)
	{
		fieldLengthY = *boardLengthY;
		fieldLengthX = *boardLengthX;
	}

	fieldDisplay(board);
}

void printHr()
{
	printf("\t");

	for(int i = 0; i < fieldLengthX + 2; i++)
	{
		printf("%c", borderSign);
	}

	printf("\n");
}

void fieldDisplay(int *board[fieldLengthY][fieldLengthX])
{
	// Clear console
	consoleClear();

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
			// ROW 1
			// String Points
			if(rowCnt == 0 && columnCnt == 2)
			{
				printf("%s", strpoints);
			}

			// String Length
			if(rowCnt == 0 && columnCnt == 6)
			{
				printf("%s", strLength);
			}

			// String Process
			if(rowCnt == 0 && columnCnt == 11)
			{
				printf("%s", strLives);
			}


			// ROW 2
			// Int Points
			else if(rowCnt == 1 && columnCnt == 2)
			{
				printf("%i", game_getPoints());
			}

			// Int Length
			else if(rowCnt == 1 && columnCnt == 13 - getIntLength(game_getPoints()))
			{
				printf("%i", game_getLength());
			}

			// Int Process
			else if(rowCnt == 1 && columnCnt == 25 -
				getIntLength(game_getPoints()) -
				getIntLength(game_getLength())
			)
			{
				printf("%i", game_getLives());
			}

			// Border Signs
			else if(
				rowCnt == 0 && (columnCnt == 0 || columnCnt == fieldLengthX - strlen(strpoints) - strlen(strLength) - strlen(strLives) + 2)
				||
				rowCnt == 1 && (columnCnt == 0 || columnCnt ==
					fieldLengthX -
					getIntLength(game_getPoints()) -
					getIntLength(game_getLength()) -
					getIntLength(game_getLives())
					+ 4
				)
			)
			{
				printf("%c", borderSign);
			}

			// Whitespaces
			else
			{
				printf("%c", ' ');
			}
		}

		printf("\n");
	}

	// HR
	printHr();

	// Clear flush
	fflush(stdout);
}
