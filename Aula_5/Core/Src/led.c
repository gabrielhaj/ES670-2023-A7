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

void vInitLed(void){
	RCC->AHB2ENR |= 0x0; /*Enabling clock for GPIOA*/

	/*Setting operation mode for all the LEDS*/
	/*Output mode = 01*/
	/*Green Led 1 - Pin 5 */
	SET_BIT(LED_GREEN1_PORT->MODER,(1<<(5*2)));
	CLEAR_BIT(LED_GREEN1_PORT->MODER,(1<<((5*2)+1)));
	/*Yellow Led - Pin 4 */
	SET_BIT(LED_YELLOW_PORT->MODER,(1<<(4*2)));
	CLEAR_BIT(LED_YELLOW_PORT->MODER,(1<<((4*2)+1)));
	/*Green Led 2 - Pin 12*/
	SET_BIT(LED_GREEN2_PORT->MODER,(1<<(12*2)));
	CLEAR_BIT(LED_GREEN2_PORT->MODER,(1<<((12*2)+1)));
	/*Blue Led - Pin 5*/
	SET_BIT(LED_BLUE_PORT->MODER,(1<<(5*2)));
	CLEAR_BIT(LED_BLUE_PORT->MODER,(1<<((5*2)+1)));
	/*Red Led - Pino 14 */
	SET_BIT(LED_RED_PORT->MODER,(1<<(14*2)));
	CLEAR_BIT(LED_RED_PORT->MODER,(1<<((14*2)+1)));

	/*Setting Pull-up Pull-down config (Same logic as before)*/
	CLEAR_BIT(LED_GREEN1_PORT->PUPDR,3<<(5*2)); /*00 = No pull-up or pull-down*/
	CLEAR_BIT(LED_YELLOW_PORT->PUPDR,3<<(4*2));
	CLEAR_BIT(LED_RED_PORT->PUPDR,3<<(14*2));
	CLEAR_BIT(LED_GREEN2_PORT->PUPDR,3<<(12*2));
	CLEAR_BIT(LED_BLUE_PORT->PUPDR,3<<(5*2));

	/*Setting Speed config (Same logic as before)*/
	CLEAR_BIT(LED_GREEN1_PORT->OSPEEDR,3<<(5*2)); /*00 = Low Speed*/
	CLEAR_BIT(LED_YELLOW_PORT->OSPEEDR,3<<(4*2));
	CLEAR_BIT(LED_RED_PORT->OSPEEDR,3<<(15*2));
	CLEAR_BIT(LED_GREEN2_PORT->OSPEEDR,3<<(12*2));
	CLEAR_BIT(LED_BLUE_PORT->OSPEEDR,3<<(5*2));
}

void vWriteLed(leds xLed, pinState xState){
	if(xLed == green1){
		if(xState == set){
			SET_BIT(LED_GREEN1_PORT->ODR,LED_GREEN1_PIN);
		}else{
			CLEAR_BIT(LED_GREEN1_PORT->ODR,LED_GREEN1_PIN);
		}
	}else if(xLed == green2){
		if(xState == set) {
			SET_BIT(LED_GREEN2_PORT->ODR,LED_GREEN2_PIN);
		}else{
			CLEAR_BIT(LED_GREEN2_PORT->ODR,LED_GREEN2_PIN);
		}
	}else if(xLed == yellow){
		if(xState == set){
			SET_BIT(LED_YELLOW_PORT->ODR,LED_YELLOW_PIN);
		}else {
			CLEAR_BIT(LED_YELLOW_PORT->ODR,LED_YELLOW_PIN);
		}
	}else if(xLed == red){
		if(xState == set){
			SET_BIT(LED_RED_PORT->ODR,LED_RED_PIN);
		}else {
			CLEAR_BIT(LED_RED_PORT->ODR,LED_RED_PIN);
		}
	}else if(xLed == blue){
		if(xState == set){
			SET_BIT(LED_BLUE_PORT->ODR,LED_BLUE_PIN);
		}else {
			CLEAR_BIT(LED_BLUE_PORT->ODR,LED_BLUE_PIN);
		}
	}
}

void vTurnOnLed(leds xLed){
	vWriteLed(xLed,set);
}
void vTurnOffLed(leds xLed){
	vWriteLed(xLed,reset);
}
void vToggleLed(leds xLed){
	if(xLed == green1){
		if(READ_BIT(LED_GREEN1_PORT->ODR,LED_GREEN1_PIN)){
			//CLEAR_BIT(LED_GREEN1_PORT->ODR,LED_GREEN1_PIN);
			vTurnOffLed(xLed);
		}else{
			//SET_BIT(LED_GREEN1_PORT->ODR,LED_GREEN1_PIN);
			vTurnOnLed(xLed);
		}
	}else if(xLed == green2){
		if(READ_BIT(LED_GREEN2_PORT->ODR,LED_GREEN2_PIN)) {
			//CLEAR_BIT(LED_GREEN2_PORT->ODR,LED_GREEN2_PIN);
			vTurnOffLed(xLed);
		}else{
			//SET_BIT(LED_GREEN2_PORT->ODR,LED_GREEN2_PIN);
			vTurnOnLed(xLed);
		}
	}else if(xLed == yellow){
		if(READ_BIT(LED_YELLOW_PORT->ODR,LED_YELLOW_PIN)){
			//CLEAR_BIT(LED_YELLOW_PORT->ODR,LED_YELLOW_PIN);
			vTurnOffLed(xLed);
		}else {
			//SET_BIT(LED_YELLOW_PORT->ODR,LED_YELLOW_PIN);
			vTurnOnLed(xLed);
		}
	}else if(xLed == red){
		if(READ_BIT(LED_RED_PORT->ODR,LED_RED_PIN)){
			//CLEAR_BIT(LED_RED_PORT->ODR,LED_RED_PIN);
			vTurnOffLed(xLed);
		}else {
			//SET_BIT(LED_RED_PORT->ODR,LED_RED_PIN);
			vTurnOnLed(xLed);
		}
	}else if(xLed == blue){
		if(READ_BIT(LED_BLUE_PORT->ODR,LED_BLUE_PIN)){
			//CLEAR_BIT(LED_BLUE_PORT->ODR,LED_BLUE_PIN);
			vTurnOffLed(xLed);
		}else {
			//SET_BIT(LED_BLUE_PORT->ODR,LED_BLUE_PIN);
			vTurnOnLed(xLed);
		}
	}
}


#endif 
