// ********************************************** //
// File name:                               led.c //
// File description:       This file declares the //
//                    functions needed to turn on //
//                    off, and toggles the leds   //
//                    in the system               //
// Author names: Gabriel Haj and Luccas Yonei     //
// Creation date: 23/03/2023                      //
// Revision date: 03/04/2023					  //
// ********************************************** //
#ifndef LED_C
#define LED_C
#include <led.h>
#include <stm32g4xx.h>
#include <main.h>

// Write led if its pin is SET
void vLedWriteLed(leds iLed, pinState iState){
	if(iLed == GREEN1){
		if(iState == SET){
			SET_BIT(LED_GREEN1_PORT->ODR,LED_GREEN1_PIN);
		}else{
			CLEAR_BIT(LED_GREEN1_PORT->ODR,LED_GREEN1_PIN);
		}
	}else if(iLed == GREEN2){
		if(iState == SET) {
			SET_BIT(LED_GREEN2_PORT->ODR,LED_GREEN2_PIN);
		}else{
			CLEAR_BIT(LED_GREEN2_PORT->ODR,LED_GREEN2_PIN);
		}
	}else if(iLed == YELLOW){
		if(iState == SET){
			SET_BIT(LED_YELLOW_PORT->ODR,LED_YELLOW_PIN);
		}else {
			CLEAR_BIT(LED_YELLOW_PORT->ODR,LED_YELLOW_PIN);
		}
	}else if(iLed == RED){
		if(iState == SET){
			SET_BIT(LED_RED_PORT->ODR,LED_RED_PIN);
		}else {
			CLEAR_BIT(LED_RED_PORT->ODR,LED_RED_PIN);
		}
	}else if(iLed == BLUE){
		if(iState == SET){
			SET_BIT(LED_BLUE_PORT->ODR,LED_BLUE_PIN);
		}else {
			CLEAR_BIT(LED_BLUE_PORT->ODR,LED_BLUE_PIN);
		}
	}
}

void vLedTurnLedOn(leds iLed){
	vLedWriteLed(iLed,SET);
}

void vLedTurnLedOff(leds iLed){
	vLedWriteLed(iLed,RESET);
}

// Turn led on if off and off if on
void vLedToggle(leds iLed){
	if(iLed == GREEN1){
		if(READ_BIT(LED_GREEN1_PORT->ODR,LED_GREEN1_PIN)){
			//CLEAR_BIT(LED_GREEN1_PORT->ODR,LED_GREEN1_PIN);
			vLedTurnLedOff(iLed);
		}else{
			//SET_BIT(LED_GREEN1_PORT->ODR,LED_GREEN1_PIN);
			vLedTurnLedOn(iLed);
		}
	}else if(iLed == GREEN2){
		if(READ_BIT(LED_GREEN2_PORT->ODR,LED_GREEN2_PIN)) {
			//CLEAR_BIT(LED_GREEN2_PORT->ODR,LED_GREEN2_PIN);
			vLedTurnLedOff(iLed);
		}else{
			//SET_BIT(LED_GREEN2_PORT->ODR,LED_GREEN2_PIN);
			vLedTurnLedOn(iLed);
		}
	}else if(iLed == YELLOW){
		if(READ_BIT(LED_YELLOW_PORT->ODR,LED_YELLOW_PIN)){
			//CLEAR_BIT(LED_YELLOW_PORT->ODR,LED_YELLOW_PIN);
			vLedTurnLedOff(iLed);
		}else {
			//SET_BIT(LED_YELLOW_PORT->ODR,LED_YELLOW_PIN);
			vLedTurnLedOn(iLed);
		}
	}else if(iLed == RED){
		if(READ_BIT(LED_RED_PORT->ODR,LED_RED_PIN)){
			//CLEAR_BIT(LED_RED_PORT->ODR,LED_RED_PIN);
			vLedTurnLedOff(iLed);
		}else {
			//SET_BIT(LED_RED_PORT->ODR,LED_RED_PIN);
			vLedTurnLedOn(iLed);
		}
	}else if(iLed == BLUE){
		if(READ_BIT(LED_BLUE_PORT->ODR,LED_BLUE_PIN)){
			//CLEAR_BIT(LED_BLUE_PORT->ODR,LED_BLUE_PIN);
			vLedTurnLedOff(iLed);
		}else {
			//SET_BIT(LED_BLUE_PORT->ODR,LED_BLUE_PIN);
			vLedTurnLedOn(iLed);
		}
	}
}



// body of led.h file
#endif // LED_H
