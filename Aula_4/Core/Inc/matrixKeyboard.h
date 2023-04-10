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


typedef struct {
	char c1;
	char c2;
	char c3;
	char cA;
	char c4;
	char c5;
	char c6;
	char cB;
	char c7;
	char c8;
	char c9;
	char cC;
	char cStar;
	char c0;
	char cHashtag;
	char cD;
} Keyboard;

void matrixKeyboardInit(void);
Keyboard matrixKeyboardGetKeys(void);
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim);
