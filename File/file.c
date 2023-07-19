//****************************** MENU PROJECT *********************************
// Copyright (c) 2023 Trenser Technology Solutions
// All Rights Reserved
//*****************************************************************************
//
// File		: file.c
// Summary	: Text editor menu execution part of the menu application.
// Note		: None
// Author	: Midhun Raj
// Date		: 17-JUL-2023
//
//*****************************************************************************

//******************************* Include Files *******************************
#include <stdio.h>
#include <string.h>
#include "file.h"

//******************************* Local Types *********************************
typedef unsigned char uint8;
typedef signed char int8;

//***************************** Local Constants *******************************

//***************************** Local Variables *******************************

//****************************** Local Functions ******************************

//***************************** FUNCTION_HEADER *******************************
// Purpose	: Print contents of the required file
// Inputs	: None
// Outputs	: None
// Return	: None
// Notes	: None
//*****************************************************************************
void fileOpen()
{
	FILE *pFile = NULL;
	uint8 pcFilepath[FILE_PATH_MAX_BIT] = "";
	int8 cCharacters = '0';
	uint8 ucCharacter = '0';
	
	printf(FILE_SCREEN_CLEAR);
	printf("Open File\n");
	printf("--------------------------------------\n");

	/* Get path from the user */
	printf("Enter the path to the file : ");
	scanf("%s", pcFilepath);
	printf("\n");
	/* Open the file for reading */
	pFile = fopen(pcFilepath, "r");

	if(pFile != NULL)
	{
		/* Read and print the contents of the file */
		printf("Contents of the file : \n\n");
		printf(FILE_GREEN_TEXT);
		while ((cCharacters = fgetc(pFile)) != EOF)
		{
			putchar(cCharacters);
		}
		printf(FILE_RESET_TEXT_COLOR);
		
		/* Close the file */
		fclose(pFile);
	}
	else
	{
		printf("Error in opening the file \n");
	}

	scanf(" %c", &ucCharacter);

	return;
}

//***************************** FUNCTION_HEADER *******************************
// Purpose	: Create new file
// Inputs	: None
// Outputs	: None
// Return	: None
// Notes	: None
//*****************************************************************************
void fileCreate()
{
	FILE *pFile = NULL;
	uint8 pcFilepath[FILE_PATH_MAX_BIT] = "";
	uint8 pucContent[10000] = "";
	uint8 pucLine[500] = "";
	uint8 ucCharacter = '0';

	printf(FILE_SCREEN_CLEAR);
	printf("Create File\n");
	printf("--------------------------------------\n");

	/* Get path from the user */
	printf("Enter the path to the file : ");
	scanf("%s", pcFilepath);
	printf("\n");
	/* Open the file for writing */
	pFile = fopen(pcFilepath, "w");

	if(pFile != NULL)
	{
		/* Get content from the user */
		printf("Enter the content (max 9999 characters) and write only '.' in a line to end :\n");

		/* Read the content from the user line by line*/
		while(1)
		{
			fgets(pucLine,500,stdin);
			if(strcmp(pucLine, ".\n") == 0)
			{
				break;
			}
			/* Add the line to the content */
			strcat(pucContent, pucLine);
			strcat(pucContent, "\n");
		}
		/* Write the content to the created file */
		fprintf(pFile, "%s", pucContent);

		printf("File created and content added: %s\n", pcFilepath);

		/* Close the file */
		fclose(pFile);
	}
	else
	{
		printf("Error in creating the file\n");
	}

	scanf(" %c", &ucCharacter);

	return;
}

//EOF