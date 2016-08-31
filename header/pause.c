/**
 *	Includes
 **/
#include <stdio.h>
#include <conio.h>
#include <windows.h>

#include "console.h"
#include "snake.h"
#include "fruits.h"
#include "game.h"


/**
 *	Definition
 **/
#include "pause.h"


/**
 *	Variables
 **/
int pause_status = 0;
int pause_pressedChar;
int pause_selectedMenuNr = 0;
char pause_charSelected;



/**
 *
 *	Public functions
 *
 **/
/**
 *	Get status
 **/
int pause_getStatus()
{
	return pause_status;
}


/**
 *	Set new status
 **/
void pause_setStatus(int newStatus)
{
	pause_status = newStatus;
}


/**
 *	Print pause menu
 **/
void pause_start()
{
	// Clear console
	consoleClear();

	printf("\n\n\n");
	printf("\tPause\n\n");
	printf("\t[%c] Continue\n", pause_printBtn(0));
	printf("\t[%c] Restart\n", pause_printBtn(1));
	printf("\t[%c] Exit\n", pause_printBtn(2));

	// Get pressed character
	pause_pressedChar = getch();

	// Press enter button
	if(pause_pressedChar == 13)
	{
		pause_pressEnter();
	}

	// Press up button
	else if(pause_pressedChar == 72)
	{
		pause_moveSelection(0);
	}

	// Press down button
	else if(pause_pressedChar == 80)
	{
		pause_moveSelection(1);
	}
}




/**
 *
 *	Private functions
 *
 **/

/**
*	Print Button
**/
char pause_printBtn(int menuNr)
{
	if(menuNr == pause_selectedMenuNr)
	{
		pause_charSelected = 'x';
	}
	else
	{
		pause_charSelected = ' ';
	}

	return pause_charSelected;
}


/**
 *	Move Selection
 **/
void pause_moveSelection(int direction)
{
	if(
		!(pause_selectedMenuNr == 0 && direction == 0) &&
		!(pause_selectedMenuNr == 2 && direction == 1) &&
		(pause_selectedMenuNr >= 0 || pause_selectedMenuNr <= 2)
	)
	{
		if(direction == 0)
		{
			pause_selectedMenuNr--;
		}
		else
		{
			pause_selectedMenuNr++;
		}
	}
}


/**
 *	Press enter button
 **/
void pause_pressEnter()
{
	// Continue
	if(pause_selectedMenuNr == 0)
	{
		game_setPlayStatus(1);
		pause_setStatus(0);
	}

	// Reset
	else if(pause_selectedMenuNr == 1)
	{
		// Reset settings
		game_reset();
		snake_reset();
		fruits_reset();

		// Start new game
		game_setPlayStatus(1);
		pause_setStatus(0);
	}

	// Exit
	else if(pause_selectedMenuNr == 2)
	{
		console_quit();
	}
}
