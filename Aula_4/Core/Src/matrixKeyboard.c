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
			xKB.i5001 ++;
		} else{
			xKB.c1 = 0;
			xKB.i1 = 0;
			xKB.i5001 = 0;
		}
		if(HAL_GPIO_ReadPin((GPIO_TypeDef*)KB_Lin2_GPIO_Port,KB_Lin2_Pin)){
			xKB.c4 = 1;
			xKB.i4 ++;
			xKB.i5004 ++;
		} else{
			xKB.c4 = 0;
			xKB.i4 = 0;
			xKB.i5001 = 0;
		}
		if(HAL_GPIO_ReadPin((GPIO_TypeDef*)KB_Lin3_GPIO_Port,KB_Lin3_Pin)){
			xKB.c7 = 1;
			xKB.i7 ++;
			xKB.i5007 ++;
		} else{
			xKB.c7 = 0;
			xKB.i7 = 0;
			xKB.i5007 = 0;
		}
		if(HAL_GPIO_ReadPin((GPIO_TypeDef*)KB_Lin4_GPIO_Port,KB_Lin4_Pin)){
			xKB.cStar = 1;
			xKB.iStar ++;
			xKB.i500Star ++;
		} else{
			xKB.cStar = 0;
			xKB.iStar = 0;
			xKB.i500Star = 0;
		}
		HAL_GPIO_WritePin((GPIO_TypeDef*)KB_Col1_GPIO_Port,KB_Col1_Pin,GPIO_PIN_RESET);
	} else if(cCOL == 2){
		HAL_GPIO_WritePin((GPIO_TypeDef*)KB_Col2_GPIO_Port,KB_Col2_Pin,GPIO_PIN_SET);
		if(HAL_GPIO_ReadPin((GPIO_TypeDef*)KB_Lin1_GPIO_Port,KB_Lin1_Pin)){
			xKB.c2 = 1;
			xKB.i2 ++;
			xKB.i5002 ++;
		} else{
			xKB.c2 = 0;
			xKB.i2 = 0;
			xKB.i5002 = 0;
		}
		if(HAL_GPIO_ReadPin((GPIO_TypeDef*)KB_Lin2_GPIO_Port,KB_Lin2_Pin)){
			xKB.c5 = 1;
			xKB.i5 ++ ;
			xKB.i5005 ++;
		} else{
			xKB.c5 = 0;
			xKB.i5 = 0;
			xKB.i5005 = 0;
		}
		if(HAL_GPIO_ReadPin((GPIO_TypeDef*)KB_Lin3_GPIO_Port,KB_Lin3_Pin)){
			xKB.c8 = 1;
			xKB.i8 ++;
			xKB.i5008 ++;
		} else{
			xKB.c8 = 0;
			xKB.i8 = 0;
			xKB.i5008 = 0;
		}
		if(HAL_GPIO_ReadPin((GPIO_TypeDef*)KB_Lin4_GPIO_Port,KB_Lin4_Pin)){
			xKB.c0 = 1;
			xKB.i0 ++;
			xKB.i5000 ++;
		} else{
			xKB.c0 = 0;
			xKB.i0 = 0;
			xKB.i5000 = 0;
			}
		HAL_GPIO_WritePin((GPIO_TypeDef*)KB_Col2_GPIO_Port,KB_Col2_Pin,GPIO_PIN_RESET);
	} else if(cCOL == 3){
		HAL_GPIO_WritePin((GPIO_TypeDef*)KB_Col3_GPIO_Port,KB_Col3_Pin,GPIO_PIN_SET);
		if(HAL_GPIO_ReadPin((GPIO_TypeDef*)KB_Lin1_GPIO_Port,KB_Lin1_Pin)){
			xKB.c3 = 1;
			xKB.i3 ++;
			xKB.i5003 ++;
		} else{
			xKB.c3 = 0;
			xKB.i3 = 0;
			xKB.i5003 =0;
		}
		if(HAL_GPIO_ReadPin((GPIO_TypeDef*)KB_Lin2_GPIO_Port,KB_Lin2_Pin)){
			xKB.c6 = 1;
			xKB.i6 ++;
			xKB.i5006 ++;
		} else{
			xKB.c6 = 0;
			xKB.i6 = 0;
			xKB.i5006 = 0;
		}
		if(HAL_GPIO_ReadPin((GPIO_TypeDef*)KB_Lin3_GPIO_Port,KB_Lin3_Pin)){
			xKB.c9 = 1;
			xKB.i9 ++;
			xKB.i5009 ++;
		} else{
			xKB.c9 = 0;
			xKB.i9 = 0;
			xKB.i5002 = 0;
		}
		if(HAL_GPIO_ReadPin((GPIO_TypeDef*)KB_Lin4_GPIO_Port,KB_Lin4_Pin)){
			xKB.cHashtag = 1;
			xKB.iHashtag ++;
			xKB.i500Hashtag ++;
		} else{
			xKB.cHashtag = 0;
			xKB.iHashtag = 0;
			xKB.i500Hashtag = 0;
		}
		HAL_GPIO_WritePin((GPIO_TypeDef*)KB_Col3_GPIO_Port,KB_Col3_Pin,GPIO_PIN_RESET);
	} else {
		HAL_GPIO_WritePin((GPIO_TypeDef*)KB_Col4_GPIO_Port,KB_Col4_Pin,GPIO_PIN_SET);
		if(HAL_GPIO_ReadPin((GPIO_TypeDef*)KB_Lin1_GPIO_Port,KB_Lin1_Pin)){
			xKB.cA = 1;
			xKB.iA ++ ;
			xKB.i500A ++;
		} else{
			xKB.cA = 0;
			xKB.iA = 0 ;
			xKB.i500A = 0;
		}
		if(HAL_GPIO_ReadPin((GPIO_TypeDef*)KB_Lin2_GPIO_Port,KB_Lin2_Pin)){
			xKB.cB = 1;
			xKB.iB ++;
			xKB.i500B ++;
		} else{
			xKB.cB = 0;
			xKB.iB = 0;
			xKB.i500B = 0;
		}
		if(HAL_GPIO_ReadPin((GPIO_TypeDef*)KB_Lin3_GPIO_Port,KB_Lin3_Pin)){
			xKB.cC = 1;
			xKB.iC ++;
			xKB.i500C ++;
		} else{
			xKB.cC = 0;
			xKB.iC = 0;
			xKB.i5002 = 0;
		}
		if(HAL_GPIO_ReadPin((GPIO_TypeDef*)KB_Lin4_GPIO_Port,KB_Lin4_Pin)){
			xKB.cD = 1;
			xKB.iD ++;
			xKB.i500D ++;
		} else{
			xKB.cD = 0;
			xKB.iD = 0;
			xKB.i500D = 0;
		}
		HAL_GPIO_WritePin((GPIO_TypeDef*)KB_Col4_GPIO_Port,KB_Col4_Pin,GPIO_PIN_RESET);
		cCOL = 0;
	}
	cCOL ++;
	if(xKb.i1 >= 75 & xKB.cFlag1== 0){
		matrixKeyboard3sEvent(&xKb.i1);
	} else if(xKb.i2 >= 75 & xKB.cFlag2== 0){
		matrixKeyboard3sEvent(&xKb.i2);
	} else if(xKb.i3 >= 75 & xKB.cFlag3== 0){
		matrixKeyboard3sEvent(&xKb.i3);
	}else if(xKb.iA >= 75 & xKB.cFlagA== 0){
		matrixKeyboard3sEvent(&xKb.iA);
	}else if(xKb.i4 >= 75 & xKB.cFlag4== 0){
		matrixKeyboard3sEvent(&xKb.i4);
	}else if(xKb.i5 >= 75 & xKB.cFlag5== 0){
		matrixKeyboard3sEvent(&xKb.i5);
	}else if(xKb.i6 >= 75 & xKB.cFlag6== 0){
		matrixKeyboard3sEvent(&xKb.i6);
	}else if(xKb.iB >= 75 & xKB.cFlagB== 0){
		matrixKeyboard3sEvent(&xKb.iB);
	}else if(xKb.i7 >= 75 & xKB.cFlag7== 0){
		matrixKeyboard3sEvent(&xKb.i7);
	}else if(xKb.i8 >= 75 & xKB.cFlag8== 0){
		matrixKeyboard3sEvent(&xKb.i8);
	}else if(xKb.i9 >= 75 & xKB.cFlag9== 0){
		matrixKeyboard3sEvent(&xKb.i9);
	}else if(xKb.iC >= 75 & xKB.cFlagC== 0){
		matrixKeyboard3sEvent(&xKb.iC);
	}else if(xKb.iStar >= 75 & xKB.cFlagStar== 0){
		matrixKeyboard3sEvent(&xKb.iStar);
	}else if(xKb.i0 >= 75 & xKB.cFlag0== 0){
		matrixKeyboard3sEvent(&xKb.i0);
	}else if(xKb.iHashtag >= 75 & xKB.cFlagHashtag== 0){
		matrixKeyboard3sEvent(&xKb.iHashtag);
	}else if(xKb.iD >= 75 & xKB.cFlagD== 0){
		matrixKeyboard3sEvent(&xKb.iD);
	}

	if(xKb.i1 >= 13){
		matrixKeyboard500msEvent(&xKb.i1);
	} else if(xKb.i2 >= 13){
		matrixKeyboard500msEvent(&xKb.i2);
	} else if(xKb.i3 >= 13){
		matrixKeyboard500msEvent(&xKb.i3);
	}else if(xKb.iA >= 13){
		matrixKeyboard500msEvent(&xKb.iA);
	}else if(xKb.i4 >= 13){
		matrixKeyboard500msEvent(&xKb.i4);
	}else if(xKb.i5 >= 13){
		matrixKeyboard500msEvent(&xKb.i5);
	}else if(xKb.i6 >= 13){
		matrixKeyboard500msEvent(&xKb.i6);
	}else if(xKb.iB >= 13){
		matrixKeyboard500msEvent(&xKb.iB);
	}else if(xKb.i7 >= 13){
		matrixKeyboard500msEvent(&xKb.i7);
	}else if(xKb.i8 >= 13){
		matrixKeyboard500msEvent(&xKb.i8);
	}else if(xKb.i9 >= 13){
		matrixKeyboard500msEvent(&xKb.i9);
	}else if(xKb.iC >= 13){
		matrixKeyboard500msEvent(&xKb.iC);
	}else if(xKb.iStar >= 13){
		matrixKeyboard500msEvent(&xKb.iStar);
	}else if(xKb.i0 >= 13){
		matrixKeyboard500msEvent(&xKb.i0);
	}else if(xKb.iHashtag >= 13){
		matrixKeyboard500msEvent(&xKb.iHashtag);
	}else if(xKb.iD >= 13){
		matrixKeyboard500msEvent(&xKb.iD);
	}



}

Keyboard  matrixKeyboardGetKeys(void){
	return xKB;
}

__weak void matrixKeyboard3sEvent(void);
__weak void matrixKeyboard500msEvent(void);
