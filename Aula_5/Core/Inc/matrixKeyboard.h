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
	int  i5001;
	char cFlag1;
	char c2;
	int  i2;
	int  i5002;
	char cFlag2;
	char c3;
	int  i3;
	int  i5003;
	char cFlag3;
	char cA;
	int  iA;
	int  i500A;
	char cFlagA;
	char c4;
	int  i4;
	int  i5004;
	char cFlag4;
	char c5;
	int  i5;
	int  i5005;
	char cFlag5;
	char c6;
	int  i6;
	int  i5006;
	char cFlag6;
	char cB;
	int  iB;
	int  i500B;
	char cFlagB;
	char c7;
	int  i7;
	int  i5007;
	char cFlag7;
	char c8;
	int  i8;
	int  i5008;
	char cFlag8;
	char c9;
	int  i9;
	int  i5009;
	char cFlag9;
	char cC;
	int  iC;
	int  i500C;
	char cFlagC;
	char cStar;
	int  iStar;
	int  i500Star;
	char cFlagStar;
	char c0;
	int  i0;
	int  i5000;
	char cFlag0;
	char cHashtag;
	int  iHashtag;
	int  i500Hashtag;
	char cFlagHashtag;
	char cD;
	int  iD;
	int  i500D;
	char cFlagD;
} Keyboard;

void vMatrixKeyboardInit(TIM_HandleTypeDef *pTimerMatrixKeyboardParam);
Keyboard  xMatrixKeyboardGetKeys(void);
void vTimerMatrixKeyboardPeriodElapsedCallback(void);
void vMatrixKeyboard3sEvent(int*);
void vMatrixKeyboard500msEvent(int*);

#endif
