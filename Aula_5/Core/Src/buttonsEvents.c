







#include "buttonsEvents.h"
#include "tim.h"



TIM_HandleTypeDef *pTimDebouncer;
TIM_HandleTypeDef *pTimPressedTime;
char cFlagDebouncer[5]; //Flag that stores information about which button is being debounced
unsigned int  uiCounterButtons[5]; //Time counter for each button, remember that each button is associated to a number (Enter = 0, Up = 1 ...)
char cFlagLongPressTimer = 0;


void vButtonsEventsInit(TIM_HandleTypeDef *pTimDebouncerParam, TIM_HandleTypeDef *pTimPressedTimeParam) {
	pTimDebouncer = pTimDebouncerParam;
	pTimPressedTime = pTimPressedTimeParam;
}


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

void timerButtonsEventsDebouncingPeriodElapsedCallback(void){
	for(int i = 0; i < 5; i++){
		if(cFlagDebouncer[i] == 1){
			HAL_NVIC_EnableIRQ(EXTI0_IRQn + i);//EXTI0_IRQn equals 6, and then EXTI1_IRQn == 7 and so on
			cFlagDebouncer[i] = 0;
			HAL_TIM_Base_Stop_IT(pTimDebouncer);
			if(xReadButtonStatus(i)){ //buttons are enum that goes from 0 to 4, and they are related to their pins as button enter is 0 and his pin is 0
				vButtonsEventCallbackPressedEvent(i);
			} else {
				vButtonsEventCallbackReleasedEvent(i);
			}
		}
	}

}

void timerButtonsEventsLongPressPeriodElapsedCallback(void){
	for(int i = 0; i < 5; i++) {
		//increase the counter of the timers if the buttons are pressed
		if(xReadButtonStatus(i)){
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
__weak void vButtonsEventCallbackPressedEvent(buttons xBt){}
__weak void vButtonsEventCallbackReleasedEvent(buttons xBt){}
__weak void vButtonsEventCallback500msPressedEvent(buttons xBt){}
__weak void vButtonsEventCallback3sPressedEvent(buttons xBt){}



