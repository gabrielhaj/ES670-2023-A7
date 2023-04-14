// ********************************************** //
// File name:                           buttons.c //
// File description:     This file implements the //
//                    functions needed to read    //
//                       a button                 //
//                                                //
// Author names: Gabriel Haj and Luccas Yonei     //
// Creation date: 23/03/2023                      //
// Revision date: 03/04/2023					  //
// ********************************************** //

#include <buttons.h>
#include <stm32g4xx.h>
#include <main.h>

void vInitButtons(void){
	/*Initializing all the buttons registers, as knowns as: PC and PB*/
	RCC->AHB2ENR |= 0x2;
	RCC->AHB2ENR |= 0x4;
	/*Alternative way: SET_BIT(RCC->AHB2ENR,PB)*/
	/*Clock initialized*/

	/*Setting mode for BT_Enter - PB0 - positions 0 and 1 = 3dec*/
	CLEAR_BIT(BT_ENTER_PORT->MODER,3); /*00 = input mode*/
	/*Setting mode for BT_UP - PC1 - positions 2 and 3 = 12 (3*4)dec and 0xC*/
	CLEAR_BIT(BT_UP_PORT->MODER,(3<<(1*2))); /*00 = input mode*/
	/*Setting mode for BT_DOWN - PC2 - positions 4 and 5 = 48(3*4^2)dec and 0x30*/
	CLEAR_BIT(BT_DOWN_PORT->MODER,(3<<(2*2))); /*00 = input mode*/
	/*Setting mode for BT_LEFT - PC3 - positions 6 and 7 = 192(3*4^3)dec and  0xC0*/
	CLEAR_BIT(BT_LEFT_PORT->MODER,(3<<(3*2))); /*00 = input mode*/
	/*Setting mode for BT_RIGHT - PC4 - positions 8 and 9 = 192(3*4^4)dec and 0x300*/
	CLEAR_BIT(BT_RIGHT_PORT->MODER,(3<<(4*2))); /*00 = input mode*/

	/*Setting Pull-up Pull-down config (Same logic as before)*/
	CLEAR_BIT(BT_ENTER_PORT->PUPDR,3); /*00 = No pull-up or pull-down*/
	CLEAR_BIT(BT_UP_PORT->PUPDR,(3<<(1*2)));
	CLEAR_BIT(BT_DOWN_PORT->PUPDR,(3<<(2*2)));
	CLEAR_BIT(BT_LEFT_PORT->PUPDR,(3<<(3*2)));
	CLEAR_BIT(BT_RIGHT_PORT->PUPDR,(3<<(4*2)));
}

pinState xReadButtonStatus(buttons xButton){
	if(xButton == up){
		if(READ_BIT(BT_UP_PORT->IDR,BT_UP_PIN)){
			return set;
		} else {
			return reset;
		}
	}else if(xButton == down){
		if(READ_BIT(BT_DOWN_PORT->IDR,BT_DOWN_PIN)){
			return set;
		} else {
			return reset;
		}
	}else if(xButton == left){
		if(READ_BIT(BT_LEFT_PORT->IDR,BT_LEFT_PIN)){
			return set;
		} else {
			return reset;
		}
	}else if(xButton == right){
		if(READ_BIT(BT_RIGHT_PORT->IDR,BT_RIGHT_PIN)){
			return set;
		} else {
			return reset;
		}
	}else{
		if(READ_BIT(BT_ENTER_PORT->IDR,BT_ENTER_PIN)){
			return set;
		} else {
			return reset;
		}
	}
}



