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
void vTachometerInit(TIM_HandleTypeDef *htim, unsigned int uiPeriod);

/* ************************************************ */
/* Method name:        vTachometerUpdate            */
/* Method description: Retrieves tachometer extern  */
/*                     timer counter value and      */
/*                     properly updates cooler speed*/
/*                     global variable              */
/* Input params:                                    */
/* Output params:                                   */
/* ************************************************ */
void vTachometerUpdate(void);


#endif
