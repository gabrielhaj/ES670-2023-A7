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

#include "heaterAndCooler.h"
extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim8;
extern float fHeaterPWMDutyCycle;
TIM_HandleTypeDef *pPWMHeater;
TIM_HandleTypeDef *pPWMCooler;



void vHeaterAndCoolerCoolerInit(TIM_HandleTypeDef *pCooler){
	pPWMCooler = pCooler;
	HAL_TIM_PWM_Start(pPWMCooler, TIM_CHANNEL_1);
}
void vHeaterAndCoolerHeaterInit(TIM_HandleTypeDef *pHeater){
	pPWMHeater = pHeater;
	HAL_TIM_PWM_Start(pPWMHeater, TIM_CHANNEL_1);
}

void vHeaterAndCoolerCoolerStart(){
	HAL_TIM_PWM_Start(pPWMCooler, TIM_CHANNEL_1);
}

void vHeaterAndCoolerHeaterStop(){
	HAL_TIM_PWM_Stop(pPWMHeater, TIM_CHANNEL_1);
}

void vHeaterAndCoolerCoolerStop(){
	HAL_TIM_PWM_Stop(pPWMCooler, TIM_CHANNEL_1);
}

void vHeaterAndCoolerCoolerfanPWMDuty(float fCoolerDuty){
	if(fCoolerDuty > 1) {
		fCoolerDuty = 1;
	} else if(fCoolerDuty < 0) {
		fCoolerDuty = 0;
	}
	pPWMCooler->Instance->CCR1 = (uint32_t)(fCoolerDuty*1000);
}

void vHeaterAndCoolerHeaterPWMDuty(float fHeaterDuty) {
	if(fHeaterDuty > 1) {
		fHeaterDuty = 1;
	} else if(fHeaterDuty < 0) {
		fHeaterDuty = 0;
	}
	pPWMHeater->Instance->CCR1 = (uint32_t)(fHeaterDuty*1000);
	fHeaterPWMDutyCycle = pPWMHeater->Instance->CCR1;
}

