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
#include "matrixKeyboard.h"
#include "main.h"


Keyboard xKB = {0};
char cCOL = 1;
extern TIM_HandleTypeDef htim6;

void matrixKeyboardInit(void){
	HAL_TIM_Base_Start_IT(&htim6);
}


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim){
	if(cCOL == 1){
		HAL_GPIO_WritePin((GPIO_TypeDef*)KB_Col1_GPIO_Port,KB_Col1_Pin,GPIO_PIN_SET);
		if(HAL_GPIO_ReadPin((GPIO_TypeDef*)KB_Lin1_GPIO_Port,KB_Lin1_Pin)){
			xKB.c1 = 1;
			xKB.i1++;
		} else{
			xKB.c1 = 0;
			xKb.c1 = 0;
		}
		if(HAL_GPIO_ReadPin((GPIO_TypeDef*)KB_Lin2_GPIO_Port,KB_Lin2_Pin)){
			xKB.c4 = 1;
			xKB.i4 ++;
		} else{
			xKB.c4 = 0;
			xKB.i4 = 0;
		}
		if(HAL_GPIO_ReadPin((GPIO_TypeDef*)KB_Lin3_GPIO_Port,KB_Lin3_Pin)){
			xKB.c7 = 1;
			xKB.i7 ++;
		} else{
			xKB.c7 = 0;
			xKB.i7 = 0;
		}
		if(HAL_GPIO_ReadPin((GPIO_TypeDef*)KB_Lin4_GPIO_Port,KB_Lin4_Pin)){
			xKB.cStar = 1;
			xKB.iStar ++;
		} else{
			xKB.cStar = 0;
			xKB.iStar = 0;
		}
		HAL_GPIO_WritePin((GPIO_TypeDef*)KB_Col1_GPIO_Port,KB_Col1_Pin,GPIO_PIN_RESET);
	} else if(cCOL == 2){
		HAL_GPIO_WritePin((GPIO_TypeDef*)KB_Col2_GPIO_Port,KB_Col2_Pin,GPIO_PIN_SET);
		if(HAL_GPIO_ReadPin((GPIO_TypeDef*)KB_Lin1_GPIO_Port,KB_Lin1_Pin)){
			xKB.c2 = 1;
			xKB.i2 ++;
		} else{
			xKB.c2 = 0;
			xKB.i2 = 0;
		}
		if(HAL_GPIO_ReadPin((GPIO_TypeDef*)KB_Lin2_GPIO_Port,KB_Lin2_Pin)){
			xKB.c5 = 1;
			xKB.i5 ++ ;
		} else{
			xKB.c5 = 0;
			xKB.i5 = 0;
		}
		if(HAL_GPIO_ReadPin((GPIO_TypeDef*)KB_Lin3_GPIO_Port,KB_Lin3_Pin)){
			xKB.c8 = 1;
			xKB.i8 ++;
		} else{
			xKB.c8 = 0;
			xKB.i8 = 0;
		}
		if(HAL_GPIO_ReadPin((GPIO_TypeDef*)KB_Lin4_GPIO_Port,KB_Lin4_Pin)){
			xKB.c0 = 1;
			xKB.i0 ++;
		} else{
			xKB.c0 = 0;
			xKB.i0 = 0;
			}
		HAL_GPIO_WritePin((GPIO_TypeDef*)KB_Col2_GPIO_Port,KB_Col2_Pin,GPIO_PIN_RESET);
	} else if(cCOL == 3){
		HAL_GPIO_WritePin((GPIO_TypeDef*)KB_Col3_GPIO_Port,KB_Col3_Pin,GPIO_PIN_SET);
		if(HAL_GPIO_ReadPin((GPIO_TypeDef*)KB_Lin1_GPIO_Port,KB_Lin1_Pin)){
			xKB.c3 = 1;
			xKB.i3 ++;
		} else{
			xKB.c3 = 0;
			xKB.i3 = 0;
		}
		if(HAL_GPIO_ReadPin((GPIO_TypeDef*)KB_Lin2_GPIO_Port,KB_Lin2_Pin)){
			xKB.c6 = 1;
			xKB.i6 ++;
		} else{
			xKB.c6 = 0;
			xKB.i6 = 0;
		}
		if(HAL_GPIO_ReadPin((GPIO_TypeDef*)KB_Lin3_GPIO_Port,KB_Lin3_Pin)){
			xKB.c9 = 1;
			xKB.i9 ++;
		} else{
			xKB.c9 = 0;
			xKB.i9 = 0;
		}
		if(HAL_GPIO_ReadPin((GPIO_TypeDef*)KB_Lin4_GPIO_Port,KB_Lin4_Pin)){
			xKB.cHashtag = 1;
			xKB.iHashtag ++;
		} else{
			xKB.cHashtag = 0;
			xKB.iHashtag = 0;
		}
		HAL_GPIO_WritePin((GPIO_TypeDef*)KB_Col3_GPIO_Port,KB_Col3_Pin,GPIO_PIN_RESET);
	} else {
		HAL_GPIO_WritePin((GPIO_TypeDef*)KB_Col4_GPIO_Port,KB_Col4_Pin,GPIO_PIN_SET);
		if(HAL_GPIO_ReadPin((GPIO_TypeDef*)KB_Lin1_GPIO_Port,KB_Lin1_Pin)){
			xKB.cA = 1;
			xKB.iA ++ ;
		} else{
			xKB.cA = 0;
			xKB.iA = 0 ;
		}
		if(HAL_GPIO_ReadPin((GPIO_TypeDef*)KB_Lin2_GPIO_Port,KB_Lin2_Pin)){
			xKB.cB = 1;
			xKB.iB ++;
		} else{
			xKB.cB = 0;
			xKB.iB = 0;
		}
		if(HAL_GPIO_ReadPin((GPIO_TypeDef*)KB_Lin3_GPIO_Port,KB_Lin3_Pin)){
			xKB.cC = 1;
			xKB.iC ++;
		} else{
			xKB.cC = 0;
			xKB.iC = 0;
		}
		if(HAL_GPIO_ReadPin((GPIO_TypeDef*)KB_Lin4_GPIO_Port,KB_Lin4_Pin)){
			xKB.cD = 1;
			xKB.iD ++;
		} else{
			xKB.cD = 0;
			xKB.iD = 0;
		}
		HAL_GPIO_WritePin((GPIO_TypeDef*)KB_Col4_GPIO_Port,KB_Col4_Pin,GPIO_PIN_RESET);
		cCOL = 0;
	}
	cCOL ++;
	if(xKb.i1 >= 75 ||xKb.i2 >= 75 || xKb.i3 >= 75 || xKb.iA >= 75 || xKb.i4 >= 75 || xKb.i5 >= 75 || xKb.i6 >= 75 || xKb.iB >= 75 ||
		xKb.i7 >= 75 ||xKb.i8 >= 75 || xKb.i9 >= 75 || xKb.iC >= 75 || xKb.iStar >= 75 || xKb.i0 >= 75 || xKb.iHashtag >= 75 || xKb.iD >= 75){
		matrixKeyboard3sEvent();
	  }

}

Keyboard  matrixKeyboardGetKeys(void){
	return xKB;
}

__weak void matrixKeyboard3sEvent(void){}
