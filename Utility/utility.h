//***************************** MENU PROJECT **********************************
// Copyright (c) 2023 Trenser Technology Solutions
// All Rights Reserved
//*****************************************************************************
//
// Summary	: Supporting functions for file management menu.
// Note		: None
// Date		: 17-JUL-2023
// Author	: Midhun Raj
//
//*****************************************************************************

#ifndef _UTILITY_H_
#define _UTILITY_H_

//******************************* Include Files *******************************

//******************************* Global Types ********************************

//********************************** Macros ***********************************
#define UTILITY_SCREEN_CLEAR		("\033[2J\033[3J\033[H")
#define UTILITY_PATH_MAX_BIT		(128)
#define UTILITY_READ_BUFFER_MAX_SIZE		(16)
#define ASCII_LOWER_LIMIT		(32)
#define ASCII_UPPER_LIMIT		(126)

//***************************** Global Constants ******************************

//***************************** Global Variables ******************************

//**************************** Function Prototype *****************************
void fileInfo();
void fileHexView();

#endif // _UTILITY_H_
// EOF