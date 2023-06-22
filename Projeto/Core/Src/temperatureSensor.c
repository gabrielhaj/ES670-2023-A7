// ********************************************** //
// File name:                 temperatureSensor.c //
// File description:    This file is the header   //
//                 of heater and cooler functions //
//                                                //
//                                                //
// Author names: Gabriel Haj and Luccas Yonei     //
// Creation date: 11/05/2023                      //
// Revision date: 11/05/2023					  //
// ********************************************** //

#include "temperatureSensor.h"
#include "adc.h"

//Stores the value from ADC module for measure the temperature
uint16_t usTemperature;


/* ************************************************ */
/* Method name:        vTemperatureSensorInit       */
/* Method description: Initialize AD converter      */
/*                     that receives the temperature*/
/*                     sensor values and store      */
/*                     directly in the memory       */
/*                     with DMA module              */
/* Input params:       *hadc: pointer to ADC_handler*/
/* Output params:                                   */
/* ************************************************ */
void vTemperatureSensorInit(ADC_HandleTypeDef *hadc){
	HAL_ADC_Start_DMA(hadc, &usTemperature, 1);
}


/* **************************************************** */
/* Method name:        fTemperatureSensorGetTemperature */
/* Method description: Return sensor temperature        */
/*                                                      */
/*                     sensor values and store          */
/*                     directly in the memory           */
/*                     with DMA module                  */
/* Input params:                                        */
/* Output params:      fTemperature: Actual Temperature */
/* **************************************************** */
float fTemperatureSensorGetTemperature(void) { //3.25*100/(2^12-1) = 0.155131
	return 0.0794*usTemperature;
}
