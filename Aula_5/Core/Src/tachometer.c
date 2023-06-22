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

//Tim Handler TypeDef pointer to hold Tachometer measure Window timer pointer
TIM_HandleTypeDef *pTachometerWindow;

//Tim Handler typedef pointer to hold tachometer extern timer
TIM_HandleTypeDef *pTachometer;

//Global variable to hold cooler speed
unsigned short int usCoolerSpeed = 0;

//Measurement window period variable
unsigned int uiPeriodTachometer;


/* ************************************************ */
/* Method name:        vTachometerInit              */
/* Method description: Initialize the timers of the */
/*                     tachometer measurement       */
/*                     window and the extern timer  */
/*                     that is the tachometer       */
/*                     itself. Also defines the     */
/*                     window period                */
/* Input params:       *htim: window timer pointer  */
/*                     uiPeriod: window period      */
/* Output params:                                   */
/* ************************************************ */
void vTachometerInit(TIM_HandleTypeDef *htim, unsigned int uiPeriod){
	pTachometerWindow = htim;
	pTachometer = &htim3;
	uiPeriodTachometer = uiPeriod;
	pTachometerWindow->Instance->ARR = ((uint32_t)uiPeriodTachometer*10) - 1;
	HAL_TIM_Base_Start_IT(pTachometerWindow);
	HAL_TIM_Base_Start(pTachometer);



}

/* ************************************************ */
/* Method name:        vTachometerUpdate            */
/* Method description: Retrieves tachometer extern  */
/*                     timer counter value and      */
/*                     properly updates cooler speed*/
/*                     global variable              */
/* Input params:                                    */
/* Output params:                                   */
/* ************************************************ */
void vTachometerUpdate(void){
	float iRotations = (float)pTachometer->Instance->CNT/9.0;
	usCoolerSpeed = (unsigned short int)((iRotations*60)/((float)uiPeriodTachometer/1000.0));
}


