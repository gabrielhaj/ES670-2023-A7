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

extern uint16_t usTemperature;

void vTemperatureSensorInit(ADC_HandleTypeDef *hadc){
	//HAL_ADCEx_Calibration_Start(hadc, ADC_SINGLE_ENDED); //Calibração ta dando ruim parece
	HAL_ADC_Start_DMA(&hadc1, &usTemperature, 1);
}

float fTemperatureSensorGetTemperature(void) { //3.25*100/(2^12-1) = 0.155131
	return 0.0794*usTemperature;
}
