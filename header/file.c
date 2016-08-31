/**
 *	Includes
 **/
#include <stdio.h>
#include <string.h>


/**
 *	Defintions
 **/
#include "file.h"


/**
 *	Variables
 **/
FILE *file;


/**
 *
 *	Functions
 *
 **/
int file_writeInFile(char *filename, char *content)
{
	file = fopen(filename, "a");

	// Check if file exist
	if(file == NULL)
	{
		printf("File not found\n");
		return 1;
	}

	// Write text into data
	fprintf(file, "%s\n", content);

	// Close file
	fclose(file);

	return 0;
}


/**
 *	Read file
 **/
int file_readFile(char *filename, char *content)
{
	file = fopen(filename, "r");
	char line[256];

	while(fgets(line, sizeof(line), file))
	{
		strcat(content, line);
	}

	// Close file
	fclose(file);

	return 0;
}


/**
 *	Check if file exist
 **/
int file_checkExist(char *filename)
{
	// Check if file exist
	if(fopen(filename, "r"))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
