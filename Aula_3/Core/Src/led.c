// ********************************************** //
// File name:                               led.h //
// File description:       This file declares the //
//                    functions needed to turn on //
//                          the leds in the system//
// Author names: Gabriel Haj and Luccas Yonei     //
// Creation date: 23/03/2023                      //
// Revision date: ----------					  //
// ********************************************** //
#ifndef LED_C
#define LED_C

void ledInitLed(void){
	/*Initializing all the buttons registers, as knowns as: PC and PB*/
	RCC->AHB2ENR |= PB;
	RCC->AHB2ENR |= PC; /*There is a define with the values of PB and PC in the header buttons.h*/
	/*Alternative way: SET_BIT(RCC->AHB2ENR,PB)*/
	/*Clock initialized*/

	/*Setting mode for BT_Enter - PB0 - positions 0 and 1 = 3dec*/
	CLEAR_BIT(GPIOB->MODER,3); /*00 = input mode*/
	/*Setting mode for BT_UP - PC1 - positions 2 and 3 = 12 (3*4)dec and 0xC*/
	CLEAR_BIT(GPIOC->MODER,0xC); /*00 = input mode*/
	/*Setting mode for BT_DOWN - PC2 - positions 4 and 5 = 48(3*4^2)dec and 0x30*/
	CLEAR_BIT(GPIOC->MODER,0x30); /*00 = input mode*/
	/*Setting mode for BT_LEFT - PC3 - positions 6 and 7 = 192(3*4^3)dec and  0xC0*/
	CLEAR_BIT(GPIOC->MODER,0xC0); /*00 = input mode*/
	/*Setting mode for BT_RIGHT - PC4 - positions 8 and 9 = 192(3*4^4)dec and 0x300*/
	CLEAR_BIT(GPIOC->MODER,0x300); /*00 = input mode*/

	/*Setting Pull-up Pull-down config (Same logic as before)*/
	CLEAR_BIT(GPIOB->PUPDR,3); /*00 = No pull-up or pull-down*/
	CLEAR_BIT(GPIOC->PUPDR,0xC);
	CLEAR_BIT(GPIOC->PUPDR,0x30);
	CLEAR_BIT(GPIOC->PUPDR,0xC0);
	CLEAR_BIT(GPIOC->PUPDR,0x300);
}

// body of automaticPilotControl.h file
#endif // AUTOPILOTCONTROL_H
