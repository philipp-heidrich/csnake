/**
 *	Includes
 **/
#include <stdio.h>
#include <conio.h>
#include <windows.h>

#include "snake.h"
#include "field.h"
#include "pause.h"
#include "fruits.h"


/**
 *	Definition
 **/
#include "game.h"


/**
 *	Optionen
 **/
#define FIELDHEIGHT 10
#define FIELDWIDTH 25


/**
 *	Variables
 **/
int game_playStatus = 0;

int game_length = 1;
int game_points = 0;
int game_lives = 0;
int game_sleepTimer = 150;
int pressedChar;

int boradLengthY = FIELDHEIGHT;
int boradLengthX = FIELDWIDTH;
int board[FIELDWIDTH][FIELDHEIGHT] = { 0 };

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77


/**
 *
 *	Functions
 *
 **/
/**
 *	Get play status
 **/
int game_getPlayStatus()
{
	return game_playStatus;
}

/**
 *	Get Points
 **/
int game_getPoints()
{
	return game_points;
}


/**
 *	Get Length
 **/
int game_getLength()
{
	return game_length;
}

/**
 *	Get Length
 **/
int game_getLives()
{
	return game_lives;
}


/**
 *	Set new game status
 **/
void game_setPlayStatus(int newPlayStatus)
{
	game_playStatus = newPlayStatus;
}


/**
 *	Add points
 **/
void game_addPoints()
{
	// Add points to game points
	game_points = game_points + 100;
}


/**
 *	Add +1 to length
 **/
void game_addOneLength()
{
	game_length++;
}


/**
 *	Set new process
 **/
void game_setNewLives(int newProcess)
{
	game_lives = newProcess;
}


void game_start()
{
	while(!kbhit() && game_getPlayStatus())
	{
		// Set new fruit icon
		fruitsSetItem(&boradLengthY, &boradLengthX, &board);

		// Set snake
		snakeSetItem(&boradLengthY, &boradLengthX, &board);

		// Print display
		fieldInit(&boradLengthY, &boradLengthX, &board);

		// Delay
		Sleep(game_sleepTimer);
	}

	if(kbhit())
	{
		pressedChar = getch();

		// Up
		if(pressedChar == UP)
		{
			snakeEditDirection(0);
		}

		// Right
		else if(pressedChar == RIGHT)
		{
			snakeEditDirection(1);
		}

		// Down
		else if(pressedChar == DOWN)
		{
			snakeEditDirection(2);
		}

		// Left
		else if(pressedChar == LEFT)
		{
			snakeEditDirection(3);
		}

		// ESC
		else if(pressedChar == 27)
		{
			pause_setStatus(1);
			game_playStatus = 0;
		}
	}
}


/**
 *	Reset game
 **/
void game_reset()
{
	game_length = 1;
	game_points = 0;
	game_lives = 0;

	for(int i = 0; i < boradLengthY; i++)
	{
		for(int e = 0; e < boradLengthX; e++)
		{
			board[i][e] = 0;
		}
	}
}
