// ********************************************** //
// File name:                               led.h //
// File description:       This file declares the //
//                    functions needed to turn on //
//                    off, and toggles the leds   //
//                    in the system               //
// Author names: Gabriel Haj and Luccas Yonei     //
// Creation date: 23/03/2023                      //
// Revision date: 02/04/2023					  //
// ********************************************** //
#ifndef LED_C
#define LED_C
#include <led.h>
#include <stm32g4xx.h>
#include <main.h>


void ledWrite(leds led, pinState state){
	if(led == green1){
		if(state == set){
			SET_BIT(LED_GREEN1_PORT->ODR,LED_GREEN1_PIN);
		}else{
			RESET_BIT(LED_GREEN1_PORT->ODR,LED_GREEN1_PIN);
		}
	}else if(led == green2){
		if(state == set) {
			SET_BIT(LED_GREEN2_PORT->ODR,LED_GREEN2_PIN);
		}else{
			RESET_BIT(LED_GREEN2_PORT->ODR,LED_GREEN2_PIN);
		}
	}else if(led == yellow){
		if(state == set){
			SET_BIT(LED_YELLOW_PORT->ODR,LED_YELLOW_PIN);
		}else {
			RESET_BIT(LED_YELLOW_PORT->ODR,LED_YELLOW_PIN);
		}
	}else if(led == red){
		if(state == set){
			SET_BIT(LED_RED_PORT->ODR,LED_RED_PIN);
		}else {
			RESET_BIT(LED_RED_PORT->ODR,LED_RED_PIN);
		}
	}else{
		if(state == set){
			SET_BIT(LED_BLUE_PORT->ODR,LED_BLUE_PIN);
		}else {
			RESET_BIT(LED_BLUE_PORT->ODR,LED_BLUE_PIN);
		}
	}
}

void ledOn(leds led){
	ledWrite(led,set);
}
void ledOff(leds led){
	ledWrite(led,reset);
}
void ledToggle(leds led){
	if(led == green1){
		if(READ_BIT(LED_GREEN1_PORT->ODR,LED_GREEN1_PIN)){
			RESET_BIT(LED_GREEN1_PORT->ODR,LED_GREEN1_PIN);
		}else{
			SET_BIT(LED_GREEN1_PORT->ODR,LED_GREEN1_PIN);
		}
	}else if(led == green2){
		if(READ_BIT(LED_GREEN2_PORT->ODR,LED_GREEN2_PIN)) {
			RESET_BIT(LED_GREEN2_PORT->ODR,LED_GREEN2_PIN);
		}else{
			SET_BIT(LED_GREEN2_PORT->ODR,LED_GREEN2_PIN);
		}
	}else if(led == yellow){
		if(READ_BIT(LED_YELLOW_PORT->ODR,LED_YELLOW_PIN)){
			RESET_BIT(LED_YELLOW_PORT->ODR,LED_YELLOW_PIN);
		}else {
			SET_BIT(LED_YELLOW_PORT->ODR,LED_YELLOW_PIN);
		}
	}else if(led == red){
		if(READ_BIT(LED_RED_PORT->ODR,LED_RED_PIN)){
			RESET_BIT(LED_RED_PORT->ODR,LED_RED_PIN);
		}else {
			SET_BIT(LED_RED_PORT->ODR,LED_RED_PIN);
		}
	}else{
		if(READ_BIT(LED_BLUE_PORT->ODR,LED_BLUE_PIN)){
			RESET_BIT(LED_BLUE_PORT->ODR,LED_BLUE_PIN);
		}else {
			SET_BIT(LED_BLUE_PORT->ODR,LED_BLUE_PIN);
		}
	}
}



// body of automaticPilotControl.h file
#endif // AUTOPILOTCONTROL_H
