// ********************************************** //
// File name:                   tachometer.h //
// File description:    This file is the header   //
//                 of heater and cooler functions //
//                                                //
//                                                //
// Author names: Gabriel Haj and Luccas Yonei     //
// Creation date: 11/05/2023                      //
// Revision date: 11/05/2023					  //
// ********************************************** //

#ifndef TACHOMETER_H
#define TACHOMETER_H
#include "buttons.h"
#include "tim.h"


void vTachometerInit(TIM_HandleTypeDef *htim, unsigned int uiPeriod);
void vTachometerUpdate(void);


#endif
