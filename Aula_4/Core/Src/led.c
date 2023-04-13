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

void ledInitLed(void){
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

void ledWrite(leds led, pinState state){
	if(led == green1){
		if(state == set){
			SET_BIT(LED_GREEN1_PORT->ODR,LED_GREEN1_PIN);
		}else{
			CLEAR_BIT(LED_GREEN1_PORT->ODR,LED_GREEN1_PIN);
		}
	}else if(led == green2){
		if(state == set) {
			SET_BIT(LED_GREEN2_PORT->ODR,LED_GREEN2_PIN);
		}else{
			CLEAR_BIT(LED_GREEN2_PORT->ODR,LED_GREEN2_PIN);
		}
	}else if(led == yellow){
		if(state == set){
			SET_BIT(LED_YELLOW_PORT->ODR,LED_YELLOW_PIN);
		}else {
			CLEAR_BIT(LED_YELLOW_PORT->ODR,LED_YELLOW_PIN);
		}
	}else if(led == red){
		if(state == set){
			SET_BIT(LED_RED_PORT->ODR,LED_RED_PIN);
		}else {
			CLEAR_BIT(LED_RED_PORT->ODR,LED_RED_PIN);
		}
	}else if(led == blue){
		if(state == set){
			SET_BIT(LED_BLUE_PORT->ODR,LED_BLUE_PIN);
		}else {
			CLEAR_BIT(LED_BLUE_PORT->ODR,LED_BLUE_PIN);
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
			//CLEAR_BIT(LED_GREEN1_PORT->ODR,LED_GREEN1_PIN);
			ledOff(led);
		}else{
			//SET_BIT(LED_GREEN1_PORT->ODR,LED_GREEN1_PIN);
			ledOn(led);
		}
	}else if(led == green2){
		if(READ_BIT(LED_GREEN2_PORT->ODR,LED_GREEN2_PIN)) {
			//CLEAR_BIT(LED_GREEN2_PORT->ODR,LED_GREEN2_PIN);
			ledOff(led);
		}else{
			//SET_BIT(LED_GREEN2_PORT->ODR,LED_GREEN2_PIN);
			ledOn(led);
		}
	}else if(led == yellow){
		if(READ_BIT(LED_YELLOW_PORT->ODR,LED_YELLOW_PIN)){
			//CLEAR_BIT(LED_YELLOW_PORT->ODR,LED_YELLOW_PIN);
			ledOff(led);
		}else {
			//SET_BIT(LED_YELLOW_PORT->ODR,LED_YELLOW_PIN);
			ledOn(led);
		}
	}else if(led == red){
		if(READ_BIT(LED_RED_PORT->ODR,LED_RED_PIN)){
			//CLEAR_BIT(LED_RED_PORT->ODR,LED_RED_PIN);
			ledOff(led);
		}else {
			//SET_BIT(LED_RED_PORT->ODR,LED_RED_PIN);
			ledOn(led);
		}
	}else if(led == blue){
		if(READ_BIT(LED_BLUE_PORT->ODR,LED_BLUE_PIN)){
			//CLEAR_BIT(LED_BLUE_PORT->ODR,LED_BLUE_PIN);
			ledOff(led);
		}else {
			//SET_BIT(LED_BLUE_PORT->ODR,LED_BLUE_PIN);
			ledOn(led);
		}
	}
}



// body of automaticPilotControl.h file
#endif // AUTOPILOTCONTROL_H
