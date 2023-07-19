//***************************** MENU PROJECT **********************************
// Copyright (c) 2023 Trenser Technology Solutions
// All Rights Reserved
//*****************************************************************************
//
// Summary	: Supporting functions for displaying menu
// Note		: None
// Date		: 10-JUL-2023
// Author	: Midhun Raj
//
//*****************************************************************************

#ifndef _MENU_H_
#define _MENU_H_

//******************************* Include Files *******************************

//******************************* Global Types ********************************

//********************************** Macros ***********************************
#define MENU_MAX_READ_BUFFER		(3)
#define MENU_SCREEN_CLEAR		("\033[2J\033[3J\033[H")

//***************************** Global Constants ******************************

//***************************** Global Variables ******************************

//**************************** Function Prototype *****************************
void menuMain();
void menuTextEditor();
void menuFileManagementTool();

#endif // _MENU_H_
// EOF