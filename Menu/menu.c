//****************************** MENU PROJECT *********************************
// Copyright (c) 2023 Trenser Technology Solutions
// All Rights Reserved
//*****************************************************************************
//
// File		: menu.c
// Summary	: Menu operation part of the menu application.
// Note		: None
// Author	: Midhun Raj
// Date		: 10-JUL-2023
//
//*****************************************************************************

//******************************* Include Files *******************************
#include <stdio.h>
#include <string.h>
#include "menu.h"
#include "file.h"
#include "utility.h"

//******************************* Local Types *********************************
typedef unsigned char uint8;

//***************************** Local Constants *******************************

//***************************** Local Variables *******************************

//****************************** Local Functions ******************************

//***************************** FUNCTION_HEADER *******************************
// Purpose	: Displays main menu
// Inputs	: None
// Outputs	: None
// Return	: None
// Notes	: None
//*****************************************************************************
void menuMain()
{
	uint8 pucMenuSelect[MENU_MAX_READ_BUFFER] = "";
	uint8 ucCharacter = '0';

	do
	{
		printf(MENU_SCREEN_CLEAR);
		/* Print main menu list */
		printf("\nMain Menu\n");
		printf("--------------------------------------\n");
		printf("1.Text Editor\n");
		printf("2.File Management Tools\n");
		printf("0.Exit\n");
		printf("Please enter your choice : ");
		scanf(" %s", pucMenuSelect);
		printf("\n");

		if(strlen(pucMenuSelect) == 1)
		{
			/* Switch to selected menu */
			switch(pucMenuSelect[0])
			{
				case '0':
				{
					/* Exit */
					printf("Exit\n");
					break;
				}
				case '1':
				{
					/* Go to Text Editor Menu */
					menuTextEditor();
					break;
				}
				case '2':
				{
					/* Go to File Management Tools */
					menuFileManagementTool();
					break;
				}
				default:
				{
					printf("Error in selection\n");
					printf("Please select again\n\n");
					scanf(" %c", &ucCharacter);
					break;
				}
			}
		}
		else
		{
			printf("Error in selection\n");
			printf("Please select again\n");
			scanf(" %c", &ucCharacter);
		}
	} while (pucMenuSelect[0] != '0');

	return;
}

//***************************** FUNCTION_HEADER *******************************
// Purpose	: Displays text editor menu
// Inputs	: None
// Outputs	: None
// Return	: None
// Notes	: None
//*****************************************************************************
void menuTextEditor()
{
	uint8 pucMenuSelect[MENU_MAX_READ_BUFFER] = "";
	uint8 ucCharacter = '0';

	do
	{
		printf(MENU_SCREEN_CLEAR);
		/* Print text editor menu list */
		printf("\nText Editor Menu\n");
		printf("--------------------------------------\n");
		printf("1.Open file\n");
		printf("2.Create file\n");
		printf("0.Back\n");
		printf("Please enter your choice : ");
		/* Read selected value */
		scanf(" %s", pucMenuSelect);
		printf("\n");

		if(strlen(pucMenuSelect) == 1)
		{
			/* Switch to selected menu */
			switch(pucMenuSelect[0])
			{
				case '0':
				{
					/* Return to main menu */
					break;
				}
				case '1':
				{
					/* Open file */
					fileOpen();
					break;
				}
				case '2':
				{
					/* Create file */
					fileCreate();
					break;
				}
				default:
				{
					printf("Error in selection\n");
					printf("Please select again\n\n");
					scanf(" %c", &ucCharacter);
					break;
				}
			}
		}
		else
		{
			printf("Error in selection\n");
			printf("Please select again\n");
			scanf(" %c", &ucCharacter);
		}
	} while (pucMenuSelect[0] != '0');

	return;
}

//***************************** FUNCTION_HEADER *******************************
// Purpose	: Displays file management tools
// Inputs	: None
// Outputs	: None
// Return	: None
// Notes	: None
//*****************************************************************************
void menuFileManagementTool()
{
	uint8 pucMenuSelect[MENU_MAX_READ_BUFFER] = "";
	uint8 ucCharacter = '0';

	do
	{
		printf(MENU_SCREEN_CLEAR);
		/* Print file management tool list */
		printf("File Management Tools\n");
		printf("--------------------------------------\n");
		printf("1.File info\n");
		printf("2.Hex viewer\n");
		printf("0.Back\n");
		printf("Please enter your choice : ");
		/* Read selected value */
		scanf(" %s", pucMenuSelect);
		printf("\n");

		if(strlen(pucMenuSelect) == 1)
		{
			/* Switch to selected tool */
			switch(pucMenuSelect[0])
			{
				case '0':
				{
					/* Return to main menu */
					break;
				}
				case '1':
				{
					/* Print file info */
					fileInfo();
					break;
				}
				case '2':
				{
					/* Print hex view */
					fileHexView();
					break;
				}
				default:
				{
					printf("Error in selection\n");
					printf("Please select again\n");
					scanf(" %c", &ucCharacter);
					break;
				}
			}
		}
		else
		{
			printf("Error in selection\n");
			printf("Please select again\n");
			scanf(" %c", &ucCharacter);
		}
	} while (pucMenuSelect[0] != '0');

	return;
}

// EOF
