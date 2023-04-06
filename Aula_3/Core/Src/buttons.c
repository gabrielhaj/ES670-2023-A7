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



pinState iButtonsReadStatus(buttons iButton){
	if(iButton == UP){
		if(READ_BIT(BT_UP_PORT->IDR,BT_UP_PIN)){
			return SET;
		} else {
			return RESET;
		}
	}else if(iButton == DOWN){
		if(READ_BIT(BT_DOWN_PORT->IDR,BT_DOWN_PIN)){
			return SET;
		} else {
			return RESET;
		}
	}else if(iButton == LEFT){
		if(READ_BIT(BT_LEFT_PORT->IDR,BT_LEFT_PIN)){
			return SET;
		} else {
			return RESET;
		}
	}else if(iButton == RIGHT){
		if(READ_BIT(BT_RIGHT_PORT->IDR,BT_RIGHT_PIN)){
			return SET;
		} else {
			return RESET;
		}
	}else{
		if(READ_BIT(BT_ENTER_PORT->IDR,BT_ENTER_PIN)){
			return SET;
		} else {
			return RESET;
		}
	}
}



