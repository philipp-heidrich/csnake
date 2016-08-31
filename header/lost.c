/**
 *	Includes
 **/
#include <stdio.h>
#include <conio.h>
#include <windows.h>

#include "console.h"
#include "snake.h"
#include "fruits.h"
#include "file.h"
#include "game.h"


/**
 *	Defintions
 **/
#include "lost.h"


/**
 *	Variables
 **/
int lost_status = 0;
int lost_pressedChar;
int lost_selectedMenuNr = 0;
char lost_charSelected;


/**
 *
 *	Functions
 *
 **/

/**
 *	Get lost status
 **/
int lost_getStatus()
{
	return lost_status;
}


/**
 *	Set new lost status
 **/
void lost_setStatus(int newStatus)
{
	lost_status = newStatus;
}


/**
 *	Print lost menu
 **/
void lost_start()
{
	char name[100];
	char file[] = "hiscore";

	// Clear console
	consoleClear();

	printf("\n\n\n");
	printf("\tGAME OVER\n");
	printf("--------------------------\n");
	printf("\tPoints: %i", game_getPoints());
	printf("\n");

	// // Check if hiscore file exist
	// if(file_checkExist(&file))
	// {
	// 	lost_printHistory();
	// }

	// // Get pressed character
	// printf("\tEnter your name: ");
	// scanf("\t%s", name);
	//
	// // Write into file
	// char fileContent[100];
	// sprintf(fileContent, "%s|%i", name, game_getPoints());
	// file_writeInFile(&file, &fileContent);



	printf("\n");
	printf("\tPress ENTER to go main menu...");

	// Get pressed character
	lost_pressedChar = getch();

	// Press enter button
	if(lost_pressedChar == 13)
	{
		// Reset settings
		game_reset();
		snake_reset();
		fruits_reset();

		// Go to lost site
		console_goTo(0);
	}
}


/**
 *	Print history
 **/
// void lost_printHistory()
// {
// 	char fileContent[100] = "";
// 	char *ptr;
// 	char *ptrSeparator = "\n";
//
// 	// Read file content
// 	file_readFile("hiscore", &fileContent);
//
// 	int nToken = strtoken(&fileContent, &ptrSeparator, ptr);
// 	printf("%s\n", ptr);
//
// 	// for(int i = 0; i < nToken; i++)
// 	// {
// 	// 	printf("test\n");
// 	// 	// printf("%s\n", ptr[i]);
// 	// }
// }
