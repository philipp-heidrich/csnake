/**
 *	Includes
 **/
#include <stdio.h>



/**
 *	Definition
 **/
#include "game.h"



/**
 *	Variables
 **/
int game_length 	= 1;
int game_points 	= 0;
int game_lives 		= 0;



/**
 *
 *	Functions
 *
 **/

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
