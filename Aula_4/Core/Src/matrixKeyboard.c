// ********************************************** //
// File name:                    matrixKeyboard.h //
// File description:       This file implements   //
//                   functions needed to init the //
//                    clock to interrupt the sys  //
//                    the callback to read the    //
//                    keyboard and also to give   //
//                    the keyboard to the applica-//
//                    tion that call it           //
// Author names: Gabriel Haj and Luccas Yonei     //
// Creation date: 05/04/2023                      //
// Revision date: 05/04/2023					  //
// ********************************************** //
#ifndef MATRIXKEYBOARD_C
#define MATRIXKEYBOARD_C
#include "matrixKeyboard.h"


Keyboard xKB = {0};
char cCOL = 1;

void matrixKeyboardInit(void){
	HAL_TIM_Base_Start_IT(&htim6);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim){
	if(cCOL == 1){
		HAL_GPIO_WritePin(xKB_Col1_GPIO_PORT->ODR,xKB_Col1_Pin,GPIO_PIN_SET);
		if(HAL_GPIO_ReadPin(xKB_Lin1_GPIO_PORT->IDR,xKB_Lin1_Pin)){ 
			xKB.c1 = 1;
		} else{
			xKB.c1 = 0;
		}
		if(HAL_GPIO_ReadPin(xKB_Lin2_GPIO_PORT->IDR,xKB_Lin2_Pin)){
			xKB.c4 = 1;
		} else{
			xKB.c4 = 0;
		}
		if(HAL_GPIO_ReadPin(xKB_Lin3_GPIO_PORT->IDR,xKB_Lin3_Pin)){
			xKB.c7 = 1;
		} else{
			xKB.c7 = 0;
		}
		if(HAL_GPIO_ReadPin(xKB_Lin4_GPIO_PORT->IDR,xKB_Lin4_Pin)){
			xKB.cStar = 1;
		} else{
			xKB.cStar = 0;
		}
		HAL_GPIO_WritePin(xKB_Col1_GPIO_PORT->ODR,xKB_Col1_Pin,GPIO_PIN_RESET);
	} else if(cCOL == 2){
		HAL_GPIO_WritePin(xKB_Col2_GPIO_PORT->ODR,xKB_Col2_Pin,GPIO_PIN_SET);
		if(HAL_GPIO_ReadPin(xKB_Lin1_GPIO_PORT->IDR,xKB_Lin1_Pin)){
			xKB.c2 = 1;
		} else{
			xKB.c2 = 0;
		}
		if(HAL_GPIO_ReadPin(xKB_Lin2_GPIO_PORT->IDR,xKB_Lin2_Pin)){
			xKB.c5 = 1;
		} else{
			xKB.c5 = 0;
		}
		if(HAL_GPIO_ReadPin(xKB_Lin3_GPIO_PORT->IDR,xKB_Lin3_Pin)){
			xKB.c8 = 1;
		} else{
			xKB.c8 = 0;
		}
		if(HAL_GPIO_ReadPin(xKB_Lin4_GPIO_PORT->IDR,xKB_Lin4_Pin)){
			xKB.c0 = 1;
		} else{
			xKB.c0r = 0;
			}
		HAL_GPIO_WritePin(xKB_Col2_GPIO_PORT->ODR,xKB_Col2_Pin,GPIO_PIN_RESET);
	} else if(cCOL == 3){
		HAL_GPIO_WritePin(xKB_Col3_GPIO_PORT->ODR,xKB_Col3_Pin,GPIO_PIN_SET);
		if(HAL_GPIO_ReadPin(xKB_Lin1_GPIO_PORT->IDR,xKB_Lin1_Pin)){
			xKB.c3 = 1;
		} else{
			xKB.c3 = 0;
		}
		if(HAL_GPIO_ReadPin(xKB_Lin2_GPIO_PORT->IDR,xKB_Lin2_Pin)){
			xKB.c6 = 1;
		} else{
			xKB.c6 = 0;
		}
		if(HAL_GPIO_ReadPin(xKB_Lin3_GPIO_PORT->IDR,xKB_Lin3_Pin)){
			xKB.c9 = 1;
		} else{
			xKB.c9 = 0;
		}
		if(HAL_GPIO_ReadPin(xKB_Lin4_GPIO_PORT->IDR,xKB_Lin4_Pin)){
			xKB.cHashtag = 1;
		} else{
			xKB.cHashtag = 0;
		}
		HAL_GPIO_WritePin(xKB_Col3_GPIO_PORT->ODR,xKB_Col3_Pin,GPIO_PIN_RESET);
	} else {
		HAL_GPIO_WritePin(xKB_Col4_GPIO_PORT->ODR,xKB_Col4_Pin,GPIO_PIN_SET);
		if(HAL_GPIO_ReadPin(xKB_Lin1_GPIO_PORT->IDR,xKB_Lin1_Pin)){
			xKB.cA = 1;
		} else{
			xKB.cA = 0;
		}
		if(HAL_GPIO_ReadPin(xKB_Lin2_GPIO_PORT->IDR,xKB_Lin2_Pin)){
			xKB.cB = 1;
		} else{
			xKB.cB = 0;
		}
		if(HAL_GPIO_ReadPin(xKB_Lin3_GPIO_PORT->IDR,xKB_Lin3_Pin)){
			xKB.cC = 1;
		} else{
			xKB.cC = 0;
		}
		if(HAL_GPIO_ReadPin(xKB_Lin4_GPIO_PORT->IDR,xKB_Lin4_Pin)){
			xKB.cD = 1;
		} else{
			xKB.cD = 0;
		}
		HAL_GPIO_WritePin(xKB_Col4_GPIO_PORT->ODR,xKB_Col4_Pin,GPIO_PIN_RESET);
		cCOL = 1;
	}
	cCOL ++; // não precisa retornar pra coluna 1 quando cCOL = 5?
}

Keyboard matrixKeyboardGetKeys(void){
	return &xKB
}
