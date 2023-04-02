// ********************************************** //
// File name:                           buttons.c //
// File description:     This file implements the //
//                    functions needed to read    //
//                       a button                 //
//                                                //
// Author names: Gabriel Haj and Luccas Yonei     //
// Creation date: 23/03/2023                      //
// Revision date: 02/04/2023					  //
// ********************************************** //

#include <buttons.h>
#include <stm32g4xx.h>
#include <main.h>



pinState buttonsReadStatus(buttons button){
	if(button == up){
		if(READ_BIT(BT_ENTER_PORT,BT_ENTER_PIN)){
			return set;
		} else {
			return reset;
		}
	}else if(button == down){
		if(READ_BIT(BT_DOWN_PORT,BT_DOWN_PIN)){
			return set;
		} else {
			return reset;
		}
	}else if(button == left){
		if(READ_BIT(BT_LEFT_PORT,BT_LEFT_PIN)){
			return set;
		} else {
			return reset;
		}
	}else if(button == right){
		if(READ_BIT(BT_RIGHT_PORT,BT_RIGHT_PIN)){
			return set;
		} else {
			return reset;
		}
	}else{
		if(READ_BIT(BT_ENTER_PORT,BT_ENTER_PIN)){
			return set;
		} else {
			return reset;
		}
	}
}



