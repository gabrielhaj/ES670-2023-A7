// ********************************************** //
// File name:                    matrixKeyboard.h //
// File description:       This file declares the //
//                    functions needed to init the//
//                    clock to interrupt the sys  //
//                    the callback to read the    //
//                    keyboard and also to give   //
//                    the keyboard to the applica-//
//                    tion that call it           //
// Author names: Gabriel Haj and Luccas Yonei     //
// Creation date: 05/04/2023                      //
// Revision date: 05/04/2023					  //
// ********************************************** //
#ifndef MATRIXKEYBOARD_H
#define MATRIXKEYBOARD_H

#include <stm32g4xx.h>
#include <main.h>
#include <stm32g4xx_hal.h>


typedef struct {
	char c1;
	int	 i1;
	char c2;
	int  i2;
	char c3;
	int  i3;
	char cA;
	int  iA;
	char c4;
	int  i4;
	char c5;
	int  i5;
	char c6;
	int  i6;
	char cB;
	int  iB;
	char c7;
	int  i7;
	char c8;
	int  i8;
	char c9;
	int  i9;
	char cC;
	int  iC;
	char cStar;
	int  iStar;
	char c0;
	int  i0;
	char cHashtag;
	int  iHashtag;
	char cD;
	int  iD;
} Keyboard;

void matrixKeyboardInit(void);
Keyboard  matrixKeyboardGetKeys(void);
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim);
__weak void matrixKeyboard3sEvent(void);

#endif
