/**
 *	Includes
 **/
#include <stdio.h>
#include <windows.h>

#include "menu.h"
#include "game.h"
#include "pause.h"
#include "lost.h"


/**
 *	Defintions
 **/
#include "console.h"


/**
 *	Functions
 **/
void consoleClear()
{
	#ifdef _WIN32
	    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	    COORD coord = {0, 0};
	    DWORD count;
	    CONSOLE_SCREEN_BUFFER_INFO csbi;
	    GetConsoleScreenBufferInfo(hStdOut, &csbi);
	    FillConsoleOutputCharacter(hStdOut, ' ',
	                               csbi.dwSize.X * csbi.dwSize.Y,
	                               coord, &count);
	    SetConsoleCursorPosition(hStdOut, coord);
	#else
	    cout << "\f";
	#endif
}

void console_quit()
{
	// Clear console
	consoleClear();

	// Quit program
	exit(0);
}


/**
 *	Clear program
 **/
void console_clearProgram()
{
	game_setPlayStatus(0);
	menu_setStatus(0);
	pause_setStatus(0);
	lost_setStatus(0);
}


/**
 *	Go to site
 **/
void console_goTo(int intNumber)
{
	// Clear all open sites
	console_clearProgram();

	// Menu
	if(intNumber == 0)
	{
		menu_setStatus(1);
	}

	// Game
	else if(intNumber == 1)
	{
		game_setPlayStatus(1);
	}

	// Pause
	else if(intNumber == 2)
	{
		pause_setStatus(1);
	}

	// Lost
	else if(intNumber == 3)
	{
		lost_setStatus(1);
	}
}
