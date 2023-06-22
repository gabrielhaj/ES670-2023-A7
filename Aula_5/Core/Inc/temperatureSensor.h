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
void vTemperatureSensorInit(ADC_HandleTypeDef *hadc);

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
float fTemperatureSensorGetTemperature(void);

#endif
