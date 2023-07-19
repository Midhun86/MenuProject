//****************************** MENU PROJECT *********************************
// Copyright (c) 2023 Trenser Technology Solutions
// All Rights Reserved
//*****************************************************************************
//
// File		: utility.c
// Summary	: File management tool menu execution part of the menu application.
// Note		: None
// Author	: Midhun Raj
// Date		: 17-JUL-2023
//
//*****************************************************************************

//******************************* Include Files *******************************
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include "utility.h"

//******************************* Local Types *********************************
typedef unsigned char uint8;
typedef signed char int8;
typedef unsigned short uint16;

//***************************** Local Constants *******************************

//***************************** Local Variables *******************************

//****************************** Local Functions ******************************

//***************************** FUNCTION_HEADER *******************************
// Purpose	: Display file info
// Inputs	: None
// Outputs	: None
// Return	: None
// Notes	: None
//*****************************************************************************
void fileInfo()
{
	uint8 pcFilepath[UTILITY_PATH_MAX_BIT] = "";
	struct stat fileStat = {0};
	struct tm *pTimeinfo = NULL;
	uint8 ucCharacter = '0';

	printf(UTILITY_SCREEN_CLEAR);
	printf("File Info\n");
	printf("--------------------------------------\n");
	printf("Enter the file path: ");
	scanf("%s", pcFilepath);

	/* Get file information */
	if (stat(pcFilepath, &fileStat) == 0)
	{
		/* Print file information */
		printf("File Information :\n");
		printf("--------------------------------------\n");
		printf("File Location : %s\n", pcFilepath);
		printf("File Size     : %ld bytes\n", fileStat.st_size);
		printf("File inode    : %ld\n", fileStat.st_ino);

		/* Get time info */
		pTimeinfo = localtime(&fileStat.st_mtime);
		printf("Last Modified : %s", asctime(pTimeinfo));

		printf("Permissions   : ");
		printf((S_ISDIR(fileStat.st_mode)) ? "d" : "-");
		printf((fileStat.st_mode & S_IRUSR) ? "r" : "-");
		printf((fileStat.st_mode & S_IWUSR) ? "w" : "-");
		printf((fileStat.st_mode & S_IXUSR) ? "x" : "-");
		printf((fileStat.st_mode & S_IRGRP) ? "r" : "-");
		printf((fileStat.st_mode & S_IWGRP) ? "w" : "-");
		printf((fileStat.st_mode & S_IXGRP) ? "x" : "-");
		printf((fileStat.st_mode & S_IROTH) ? "r" : "-");
		printf((fileStat.st_mode & S_IWOTH) ? "w" : "-");
		printf((fileStat.st_mode & S_IXOTH) ? "x\n" : "-\n\n");
	}
	else
	{
		printf("Failed to get file information.\n");
	}
	scanf(" %c", &ucCharacter);

	return;
}

//***************************** FUNCTION_HEADER *******************************
// Purpose	: Display file hex view
// Inputs	: None
// Output	: None
// Return	: None
// Notes	: None
//*****************************************************************************
void fileHexView()
{
	uint8 pcFilepath[UTILITY_PATH_MAX_BIT] = "";
	FILE *pFile = NULL;
	uint8 pucReadBuffer[UTILITY_READ_BUFFER_MAX_SIZE] = "";
	uint16 unBytesRead = 0;
	uint8 ucCharacter = '0';
	uint16 unOffset = 0;

	printf(UTILITY_SCREEN_CLEAR);
	printf("Hex Viewer\n");
	printf("--------------------------------------\n");

	/* Get the file path from user */
	printf("Enter the file path: ");
	scanf("%s", pcFilepath);

	/* Open the file for reading */
	pFile = fopen(pcFilepath, "r");

	if (pFile != NULL) 
	{
		/* Print hex view of file */
		printf("Hex View of the File:\n");
		printf("--------------------------------------\n");

		while ((unBytesRead = fread(pucReadBuffer, sizeof(uint8), sizeof(pucReadBuffer), pFile)) > 0) 
		{
			printf("%02X ", unOffset);
			for(uint16 i = 0; i < unBytesRead; i++)
			{
				printf("%02X ", pucReadBuffer[i]);
			}
			printf("| ");

			for(uint16 i = 0; i < unBytesRead; i++)
			{
				if (pucReadBuffer[i] >= ASCII_LOWER_LIMIT && pucReadBuffer[i] <= ASCII_UPPER_LIMIT)
				{
					printf("%c", pucReadBuffer[i]);
				}
				else
				{
					printf(".");
				}
			}
			printf("\n");
			unOffset += unBytesRead;
		}
		/* Close the file */
		fclose(pFile);
	}
	else
	{
		printf("Failed to open the file.\n");
	}
	scanf(" %c", &ucCharacter);

	return;
}

//EOF