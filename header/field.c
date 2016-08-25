#include <stdio.h>

int fieldx = 20;
int fieldy = 20;

const char placeSign 	= ' ';
const char borderSign 	= '#';
const char fruitSign 	= 'x';

void fieldDisplay()
{
	// Clear console
	clearConsole();

	for(int rowCnt = 0; rowCnt < fieldy + 2; rowCnt++)
	{
		for(int columnCnt = 0; columnCnt < fieldx + 2; columnCnt++)
		{
			if(
				rowCnt == 0 ||
				rowCnt == fieldx + 1 ||
				columnCnt == 0 ||
				columnCnt == fieldx + 1
			)
			{
				printf("%c", borderSign);
			}
			else
			{
				printf("%c", placeSign);
			}
		}

		printf("\n");

		fflush(stdout);
	}
}
