// ********************************************** //
// File name:                   heaterAndCooler.h //
// File description:    This file is the header   //
//                 of heater and cooler functions //
//                 Here we set the parameters of  //
//                 The cooler and the heater pwm  //
//                 timers                         //
//                                                //
//                                                //
// Author names: Gabriel Haj and Luccas Yonei     //
// Creation date: 11/05/2023                      //
// Revision date: 21/06/2023					  //
// ********************************************** //

#include "heaterAndCooler.h"

//Global variable to hold PWM Heater Duty Cycle
float fHeaterPWMDutyCycle = 0;

//Global variable to hold PWM Cooler Duty Cycle
float fCoolerPWMDutyCycle = 0;

//Heaters tim handler timer pointer
TIM_HandleTypeDef *pPWMHeater;

//Coolers tim handler timer pointer
TIM_HandleTypeDef *pPWMCooler;


/* ***************************************************************** */
/* Method name:        vHeaterAndCoolerCoolerInit                    */
/* Method description: Stores Cooler PWM tim handler pointer and     */
/*                     starts it                                     */
/* Input params:  TIM_HandleTypeDef* pCooler                         */
/* Output params:                                                    */
/* ***************************************************************** */
void vHeaterAndCoolerCoolerInit(TIM_HandleTypeDef *pCooler){
	pPWMCooler = pCooler;
	HAL_TIM_PWM_Start(pPWMCooler, TIM_CHANNEL_1);
}

/* ***************************************************************** */
/* Method name:        vHeaterAndCoolerHeaterInit                    */
/* Method description: Stores Heater PWM tim handler pointer and     */
/*                     starts it                                     */
/* Input params:  TIM_HandleTypeDef* pHeater                         */
/* Output params:                                                    */
/* ***************************************************************** */
void vHeaterAndCoolerHeaterInit(TIM_HandleTypeDef *pHeater){
	pPWMHeater = pHeater;
	HAL_TIM_PWM_Start(pPWMHeater, TIM_CHANNEL_1);
}

/* ***************************************************************** */
/* Method name:        vHeaterAndCoolerCoolerStart                   */
/* Method description: Starts Cooler PWM                             */
/* Input params:                                                     */
/* Output params:                                                    */
/* ***************************************************************** */
void vHeaterAndCoolerCoolerStart(){
	HAL_TIM_PWM_Start(pPWMCooler, TIM_CHANNEL_1);
}

/* ***************************************************************** */
/* Method name:        vHeaterAndCoolerCoolerStop                    */
/* Method description: Stops Cooler PWM                              */
/* Input params:                                                     */
/* Output params:                                                    */
/* ***************************************************************** */
void vHeaterAndCoolerCoolerStop(){
	HAL_TIM_PWM_Stop(pPWMCooler, TIM_CHANNEL_1);

}

/* ***************************************************************** */
/* Method name:        vHeaterAndCoolerHeaterStop                    */
/* Method description: Stops Heater PWM                              */
/* Input params:                                                     */
/* Output params:                                                    */
/* ***************************************************************** */
void vHeaterAndCoolerHeaterStop(){
	HAL_TIM_PWM_Stop(pPWMHeater, TIM_CHANNEL_1);
}

/* ***************************************************************** */
/* Method name:        vHeaterAndCoolerCoolerfanPWMDuty              */
/* Method description: Sets Cooler Fan PWM value in the register     */
/*                     It also avoids values greater or lower than   */
/*                     Permitted and updates Cooler PWM Duty          */
/*                     global variable                               */
/* Input params:       fCoolerDuty                                   */
/* Output params:                                                    */
/* ***************************************************************** */
void vHeaterAndCoolerCoolerfanPWMDuty(float fCoolerDuty){
	if(fCoolerDuty > 1) {
		fCoolerDuty = 1;
	} else if(fCoolerDuty < 0) {
		fCoolerDuty = 0;
	}
	pPWMCooler->Instance->CCR1 = (uint32_t)(fCoolerDuty*1000);
	fCoolerPWMDutyCycle = fCoolerDuty*100;
}

/* ***************************************************************** */
/* Method name:        vHeaterAndCoolerHeaterPWMDuty                 */
/* Method description: Sets Heater PWM value in the register         */
/*                     It also avoids values greater or lower than   */
/*                     permitted and updates Heater PWM Duty          */
/*                     global variable                               */
/* Input params:       fHeaterDuty                                   */
/* Output params:                                                    */
/* ***************************************************************** */
void vHeaterAndCoolerHeaterPWMDuty(float fHeaterDuty) {
	if(fHeaterDuty > 1) {
		fHeaterDuty = 1;
	} else if(fHeaterDuty < 0) {
		fHeaterDuty = 0;
	}
	pPWMHeater->Instance->CCR1 = (uint32_t)(fHeaterDuty*1000);
	fHeaterPWMDutyCycle = fHeaterDuty*100;
}

