/**
 *	Includes
 **/
#include <stdio.h>
#include <conio.h>
#include <windows.h>

#include "game.h"
#include "console.h"


/**
 *	Definitions
 **/
#include "menu.h"


/**
 *	Variables
 **/
int maxMenuItems = 1;
int pressedChar;
int showStatus = 1;
int selectedMenuNr = 0;
char character;




/**
 *
 *	Functions
 *
 **/

/**
 *	Get show status
 **/
int menu_getShowStatus()
{
	return showStatus;
}


/**
 *	Set new menu status
 **/
void menu_setStatus(int status)
{
	showStatus = status;
}


/**
 *	Print Button
 **/
char menu_printBtn(int menuNr)
{
	if(menuNr == selectedMenuNr)
	{
		character = 'x';
	}
	else
	{
		character = ' ';
	}

	return character;
}


/**
 *	Move Selection
 **/
void menu_moveSelection(int direction)
{
	if(
		!(selectedMenuNr == 0 && direction == 0) &&
		!(selectedMenuNr == maxMenuItems && direction == maxMenuItems) &&
		(selectedMenuNr <= 0 || selectedMenuNr <= maxMenuItems)
	)
	{
		if(direction == 0)
		{
			selectedMenuNr--;
		}
		else
		{
			selectedMenuNr++;
		}
	}
}


void menu_start()
{
	// Print menu
	menu_print();

	pressedChar = getch();

	// Press enter button
	if(pressedChar == 13)
	{
		menu_pressEnter();
	}

	// Press up button
	else if(pressedChar == 72)
	{
		menu_moveSelection(0);
	}

	// Press down button
	else if(pressedChar == 80)
	{
		menu_moveSelection(1);
	}
}


void menu_print()
{
	// Clear console
	consoleClear();

	printf("\n\n\n");
	printf("\tcSnake\n\n");
	printf("\t[%c] Start\n", menu_printBtn(0));
	printf("\t[%c] Exit\n", menu_printBtn(1));
}


/**
 *	Press enter button
 **/
void menu_pressEnter()
{
	// Start
	if(selectedMenuNr == 0)
	{
		showStatus = 0;
		game_setPlayStatus(1);
	}

	// Exit
	if(selectedMenuNr == 1)
	{
		console_quit();
	}
}
