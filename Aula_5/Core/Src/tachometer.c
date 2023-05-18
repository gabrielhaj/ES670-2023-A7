// ********************************************** //
// File name:                        tachometer.c //
// File description:    This file is the header   //
//                 of heater and cooler functions //
//                                                //
//                                                //
// Author names: Gabriel Haj and Luccas Yonei     //
// Creation date: 11/05/2023                      //
// Revision date: 11/05/2023					  //
// ********************************************** //


#include "tachometer.h"
#include "tim.h"

TIM_HandleTypeDef *pTachometerWindow;
TIM_HandleTypeDef *pTachometer;
unsigned short int usCoolerSpeed = 0;
unsigned int uiPeriodTachometer;


void vTachometerInit(TIM_HandleTypeDef *htim, unsigned int uiPeriod){
	pTachometerWindow = htim;
	pTachometer = &htim3;
	uiPeriodTachometer = uiPeriod;
	pTachometerWindow->Instance->ARR = ((uint32_t)uiPeriodTachometer*10) - 1;
	HAL_TIM_Base_Start_IT(pTachometerWindow);
	HAL_TIM_Base_Start(pTachometer);



}

void vTachometerUpdate(void){
	float iRotations = (float)pTachometer->Instance->CNT/9.0;
	usCoolerSpeed = (unsigned short int)((iRotations*60)/((float)uiPeriodTachometer/1000.0));
}


