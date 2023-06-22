// ********************************************** //
// File name:                     buttonsEvents.c //
// File description:     This file implements the //
//          interruptions callbacks from pressing //
//                                     a button   //
//                                                //
// Author names: Gabriel Haj and Luccas Yonei     //
// Creation date: 18/04/2023                      //
// Revision date: 21/06/2023					  //
// ********************************************** //






#include "buttons.h"
#include "help.h"
#include "buttonsEvents.h"
#include "tim.h"
#include "lcd.h"


//Pointer for Debouncer
TIM_HandleTypeDef *pTimDebouncer;
//Pointer for long press
TIM_HandleTypeDef *pTimPressedTime;
//Flag that stores information about which button is being debounced
char cFlagDebouncer[5];
//Time counter for each button, remember that each button is associated to a number (Enter = 0, Up = 1 ...)
unsigned int  uiCounterButtons[5];
//Flag for long press timer
char cFlagLongPressTimer = 0;
//Variable that holds the next screen information to be updated on display
extern screens xScreen;

/* ************************************************ */
/* Method name:        vButtonsEventsInit           */
/* Method description: Stores Debouncer and Pressed */
/*					   pointer localy               */
/* Input params:       TIM_HandleTypeDef pointers   */
/*                    for debouncer and pressed time*/
/*                    handlers                      */
/* Output params:                                   */
/* ************************************************ */
void vButtonsEventsInit(TIM_HandleTypeDef *pTimDebouncerParam, TIM_HandleTypeDef *pTimPressedTimeParam) {
	pTimDebouncer = pTimDebouncerParam;
	pTimPressedTime = pTimPressedTimeParam;
}

/* ************************************************ */
/* Method name:        HAL_GPIO_EXIT_Callback       */
/* Method description: Callback from gpio           */
/*					   exti module where we         */
/*                     turn on debouncer timer      */
/*                     and off exti interruption    */
/*                     and set their flag on        */
/*                     Also turn on timer from      */
/*                     pressed time if it is not yet*/
/* Input params:       GPIO_Pin                     */
/* Output params:                                   */
/* ************************************************ */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
	if(GPIO_Pin == GPIO_PIN_0){
		HAL_NVIC_DisableIRQ(EXTI0_IRQn);
		pTimDebouncer->Instance->CNT = 0; //Force timer go to zero, but it still working
		cFlagDebouncer[0] = 1;
	} else if(GPIO_Pin == GPIO_PIN_1){
		HAL_NVIC_DisableIRQ(EXTI1_IRQn);
		pTimDebouncer->Instance->CNT = 0;
		cFlagDebouncer[1] = 1;
	}else if(GPIO_Pin == GPIO_PIN_2){
		HAL_NVIC_DisableIRQ(EXTI2_IRQn);
		pTimDebouncer->Instance->CNT = 0;
		cFlagDebouncer[2] = 1;
	}else if(GPIO_Pin == GPIO_PIN_3){
		HAL_NVIC_DisableIRQ(EXTI3_IRQn);
		pTimDebouncer->Instance->CNT = 0;
		cFlagDebouncer[3] = 1;
	}else if(GPIO_Pin == GPIO_PIN_4){
		HAL_NVIC_DisableIRQ(EXTI4_IRQn);
		pTimDebouncer->Instance->CNT = 0;
		cFlagDebouncer[4] = 1;
	}

	if(cFlagLongPressTimer == 0){
		HAL_TIM_Base_Start_IT(pTimPressedTime);
		cFlagLongPressTimer = 1;
	}

	HAL_TIM_Base_Start_IT(pTimDebouncer);

}

/* ***************************************************************** */
/* Method name:        vButtonsEventsDebouncingPeriodElapsedCallback */
/* Method description: Enable Interruption                            */
/*					   exti module where we                          */
/*                     turn on debouncer timer                       */
/*                     and off exti interruption                     */
/*                     and set their flag on                         */
/*                     Also turn on timer from                       */
/*                     pressed time if it is not yet                 */
/* Input params:       GPIO_Pin                                      */
/* Output params:                                                    */
/* ***************************************************************** */
void vButtonsEventsDebouncingPeriodElapsedCallback(void){
	for(int i = 0; i < 5; i++){
		if(cFlagDebouncer[i] == 1){
			HAL_NVIC_EnableIRQ(EXTI0_IRQn + i);//EXTI0_IRQn equals 6, and then EXTI1_IRQn == 7 and so on
			cFlagDebouncer[i] = 0;
			HAL_TIM_Base_Stop_IT(pTimDebouncer);
			if(xButtonsReadStatus(i)){ //buttons are enum that goes from 0 to 4, and they are related to their pins as button enter is 0 and his pin is 0
				vButtonsEventCallbackPressedEvent(i);
			} else {
				vButtonsEventCallbackReleasedEvent(i);
			}
		}
	}

}

/* ***************************************************************** */
/* Method name:        vButtonsEventsLongPressPeriodElapsedCallback  */
/* Method description: Callback for LongPress timer                  */
/*                     Check each buttons state and increment their  */
/*					   counter for 500ms and 3s.If the button is not */
/*                     on restart the counter                        */
/* Input params:                                                     */
/* Output params:                                                    */
/* ***************************************************************** */
void vButtonsEventsLongPressPeriodElapsedCallback(void){
	for(int i = 0; i < 5; i++) {
		//increase the counter of the timers if the buttons are pressed
		if(xButtonsReadStatus(i)){
			uiCounterButtons[i] += 10;
			if(((int)uiCounterButtons[i] % 500) == 0){
				vButtonsEventCallback500msPressedEvent(i);
			}
			if(uiCounterButtons[i] == 3000 ){
				vButtonsEventCallback3sPressedEvent(i);
			}
		} else {
			uiCounterButtons[i] = 0;
		}
	}
}

/* ***************************************************************** */
/* Method name:        vButtonsEventsChangeScreen                    */
/* Method description: Change LCD screen value to update screen      */
/*                     LCD display. Also allows user to increment    */
/*					   temperature setpoint in the first screen and  */
/*                     to turn on/off backlight screen by Enter button*/
/* Input params:  xBt buttons                                        */
/* Output params:                                                    */
/* ***************************************************************** */
void vButtonsEventChangeScreen(buttons xBt){
	if(xBt == up){
			switch(xScreen){
				case screen1:
					vPIDSetSetPointTemperature(fPIDGetSetPointTemperature() + 1);
					break;
				case screen2:
					break;
				case screen3:
					break;
				case screen4:
					break;
			}
		} else if(xBt == down){
			switch(xScreen){
				case screen1:
					vPIDSetSetPointTemperature(fPIDGetSetPointTemperature() - 1);
					break;
				case screen2:
					break;
				case screen3:
					break;
				case screen4:
					break;
			}
		} else if(xBt == right) {
			xScreen ++;
			if(xScreen > screen4){
				xScreen = screen1;
			}
		} else if(xBt == left) {
			if(xScreen == screen1){
				xScreen = screen4;
			} else {
				xScreen --;
			}
		} else if(xBt == enter) {
			if(cLcdGetBackLight()) {
				vLcdBackLightOff();
			} else {
				vLcdBackLightOn();
			}
		}
}
__weak void vButtonsEventCallbackPressedEvent(buttons xBt){}
__weak void vButtonsEventCallbackReleasedEvent(buttons xBt){}
__weak void vButtonsEventCallback500msPressedEvent(buttons xBt){}



