// ********************************************** //
// File name:                   heaterAndCooler.h //
// File description:    This file is the header   //
//                 of heater and cooler functions //
//                                                //
//                                                //
// Author names: Gabriel Haj and Luccas Yonei     //
// Creation date: 11/05/2023                      //
// Revision date: 21/06/2023					  //
// ********************************************** //

#ifndef HEATERANDCOOLER_H
#define HEATERANDCOOLER_H
#include "buttons.h"
#include "tim.h"


/* ***************************************************************** */
/* Method name:        vHeaterAndCoolerCoolerInit                    */
/* Method description: Stores Cooler PWM tim handler pointer and     */
/*                     starts it                                     */
/* Input params:  TIM_HandleTypeDef* pCooler                         */
/* Output params:                                                    */
/* ***************************************************************** */
void vHeaterAndCoolerCoolerInit(TIM_HandleTypeDef *pWMCooler);

/* ***************************************************************** */
/* Method name:        vHeaterAndCoolerHeaterInit                    */
/* Method description: Stores Heater PWM tim handler pointer and     */
/*                     starts it                                     */
/* Input params:  TIM_HandleTypeDef* pHeater                         */
/* Output params:                                                    */
/* ***************************************************************** */
void vHeaterAndCoolerHeaterInit(TIM_HandleTypeDef *pWMHeater);

/* ***************************************************************** */
/* Method name:        vHeaterAndCoolerCoolerStart                   */
/* Method description: Starts Cooler PWM                             */
/* Input params:                                                     */
/* Output params:                                                    */
/* ***************************************************************** */
void vHeaterAndCoolerCoolerStart(void);

/* ***************************************************************** */
/* Method name:        vHeaterAndCoolerCoolerStop                    */
/* Method description: Stops Cooler PWM                              */
/* Input params:                                                     */
/* Output params:                                                    */
/* ***************************************************************** */
void vHeaterAndCoolerCoolerStop(void);

/* ***************************************************************** */
/* Method name:        vHeaterAndCoolerHeaterStop                    */
/* Method description: Stops Heater PWM                              */
/* Input params:                                                     */
/* Output params:                                                    */
/* ***************************************************************** */
void vHeaterAndCoolerHeaterStop(void);

/* ***************************************************************** */
/* Method name:        vHeaterAndCoolerCoolerfanPWMDuty              */
/* Method description: Sets Cooler Fan PWM value in the register     */
/*                     It also avoids values greater or lower than   */
/*                     Permitted and updates Cooler PWM Duty         */
/*                     global variable                               */
/* Input params:       fCoolerDuty                                   */
/* Output params:                                                    */
/* ***************************************************************** */
void vHeaterAndCoolerCoolerfanPWMDuty(float fCoolerDuty);

/* ***************************************************************** */
/* Method name:        vHeaterAndCoolerHeaterPWMDuty                 */
/* Method description: Sets Heater PWM value in the register         */
/*                     It also avoids values greater or lower than   */
/*                     permitted and updates Heater PWM Duty         */
/*                     global variable                               */
/* Input params:       fHeaterDuty                                   */
/* Output params:                                                    */
/* ***************************************************************** */
void vHeaterAndCoolerHeaterPWMDuty(float fHeaterDuty);





#endif
