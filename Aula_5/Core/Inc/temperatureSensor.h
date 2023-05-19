// ********************************************** //
// File name:                 temperatureSensor.h //
// File description:    This file is the header   //
//                 of heater and cooler functions //
//                                                //
//                                                //
// Author names: Gabriel Haj and Luccas Yonei     //
// Creation date: 11/05/2023                      //
// Revision date: 11/05/2023					  //
// ********************************************** //

#ifndef TEMPERATURESENSOR_H
#define TEMPERATURESENSOR_H

#include "adc.h"

void vTemperatureSensorInit(ADC_HandleTypeDef *hadc);
float fTemperatureSensorGetTemperature(void);

#endif
