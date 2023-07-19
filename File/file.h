//***************************** MENU PROJECT **********************************
// Copyright (c) 2023 Trenser Technology Solutions
// All Rights Reserved
//*****************************************************************************
//
// Summary	: Supporting functions for text editor.
// Note		: None
// Date		: 17-JUL-2023
// Author	: Midhun Raj
//
//*****************************************************************************

#ifndef _FILE_H_
#define _FILE_H_

//******************************* Include Files *******************************

//******************************* Global Types ********************************

//********************************** Macros ***********************************
#define FILE_SCREEN_CLEAR		("\033[2J\033[3J\033[H")
#define FILE_GREEN_TEXT		("\033[0;32m")
#define FILE_RESET_TEXT_COLOR		("\033[0m")
#define FILE_PATH_MAX_BIT		(128)


//***************************** Global Constants ******************************

//***************************** Global Variables ******************************

//**************************** Function Prototype *****************************
void fileOpen();
void fileCreate();

#endif // _FILE_H_
// EOF