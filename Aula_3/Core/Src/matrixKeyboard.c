// File name:                               led.h //
// File description:       This file declares the //
//                    functions needed to turn on,//
//                     off, and toggles the leds  //
//                     in the system              //
// Author names: Gabriel Haj and Luccas Yonei     //
// Creation date: 23/03/2023                      //
// Revision date: 03/04/2023					  //
// ********************************************** //
#ifndef LED_H
#define LED_H
#include "help.h"

void matrixKeyboardInit(void){
	HAL_TIM_Base_Start_IT(&htim6);
}
