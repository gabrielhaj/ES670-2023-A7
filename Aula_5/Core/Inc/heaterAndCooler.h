// ********************************************** //
// File name:                   heaterAndCooler.h //
// File description:    This file is the header   //
//                 of heater and cooler functions //
//                                                //
//                                                //
// Author names: Gabriel Haj and Luccas Yonei     //
// Creation date: 11/05/2023                      //
// Revision date: 11/05/2023					  //
// ********************************************** //

#ifndef HEATERANDCOOLER_H
#define HEATERANDCOOLER_H
#include "buttons.h"
#include "tim.h"

void vCoolerfanPWMDuty(float fCoolerDuty);
void vHeaterPWMDuty(float fHeaterDuty);
void vHeaterAndCoolerHeaterInit(TIM_HandleTypeDef *pWMHeater);
void vHeaterAndCoolerCoolerInit(TIM_HandleTypeDef *pWMCooler);

#endif
