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
TIM_HandleTypeDef *pTimerMatrixKeyboard;

void vMatrixKeyboardInit(TIM_HandleTypeDef *pTimerMatrixKeyboardParam){
	pTimerMatrixKeyboard = pTimerMatrixKeyboardParam;
	HAL_TIM_Base_Start_IT(pTimerMatrixKeyboard);
}


void vTimerMatrixKeyboardPeriodElapsedCallback(){
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
	if(xKB.i1 >= 75 && xKB.cFlag1== 0){
		vMatrixKeyboard3sEvent(&xKB.i1);
	} else if(xKB.i2 >= 75 && xKB.cFlag2== 0){
		vMatrixKeyboard3sEvent(&xKB.i2);
	} else if(xKB.i3 >= 75 && xKB.cFlag3== 0){
		vMatrixKeyboard3sEvent(&xKB.i3);
	}else if(xKB.iA >= 75 && xKB.cFlagA== 0){
		vMatrixKeyboard3sEvent(&xKB.iA);
	}else if(xKB.i4 >= 75 && xKB.cFlag4== 0){
		vMatrixKeyboard3sEvent(&xKB.i4);
	}else if(xKB.i5 >= 75 && xKB.cFlag5== 0){
		vMatrixKeyboard3sEvent(&xKB.i5);
	}else if(xKB.i6 >= 75 && xKB.cFlag6== 0){
		vMatrixKeyboard3sEvent(&xKB.i6);
	}else if(xKB.iB >= 75 && xKB.cFlagB== 0){
		vMatrixKeyboard3sEvent(&xKB.iB);
	}else if(xKB.i7 >= 75 && xKB.cFlag7== 0){
		vMatrixKeyboard3sEvent(&xKB.i7);
	}else if(xKB.i8 >= 75 && xKB.cFlag8== 0){
		vMatrixKeyboard3sEvent(&xKB.i8);
	}else if(xKB.i9 >= 75 && xKB.cFlag9== 0){
		vMatrixKeyboard3sEvent(&xKB.i9);
	}else if(xKB.iC >= 75 && xKB.cFlagC== 0){
		vMatrixKeyboard3sEvent(&xKB.iC);
	}else if(xKB.iStar >= 75 && xKB.cFlagStar== 0){
		vMatrixKeyboard3sEvent(&xKB.iStar);
	}else if(xKB.i0 >= 75 && xKB.cFlag0== 0){
		vMatrixKeyboard3sEvent(&xKB.i0);
	}else if(xKB.iHashtag >= 75 && xKB.cFlagHashtag== 0){
		vMatrixKeyboard3sEvent(&xKB.iHashtag);
	}else if(xKB.iD >= 75 && xKB.cFlagD== 0){
		vMatrixKeyboard3sEvent(&xKB.iD);
	}

	if(xKB.i1 >= 13){
		vMatrixKeyboard500msEvent(&xKB.i1);
	} else if(xKB.i2 >= 13){
		vMatrixKeyboard500msEvent(&xKB.i2);
	} else if(xKB.i3 >= 13){
		vMatrixKeyboard500msEvent(&xKB.i3);
	}else if(xKB.iA >= 13){
		vMatrixKeyboard500msEvent(&xKB.iA);
	}else if(xKB.i4 >= 13){
		vMatrixKeyboard500msEvent(&xKB.i4);
	}else if(xKB.i5 >= 13){
		vMatrixKeyboard500msEvent(&xKB.i5);
	}else if(xKB.i6 >= 13){
		vMatrixKeyboard500msEvent(&xKB.i6);
	}else if(xKB.iB >= 13){
		vMatrixKeyboard500msEvent(&xKB.iB);
	}else if(xKB.i7 >= 13){
		vMatrixKeyboard500msEvent(&xKB.i7);
	}else if(xKB.i8 >= 13){
		vMatrixKeyboard500msEvent(&xKB.i8);
	}else if(xKB.i9 >= 13){
		vMatrixKeyboard500msEvent(&xKB.i9);
	}else if(xKB.iC >= 13){
		vMatrixKeyboard500msEvent(&xKB.iC);
	}else if(xKB.iStar >= 13){
		vMatrixKeyboard500msEvent(&xKB.iStar);
	}else if(xKB.i0 >= 13){
		vMatrixKeyboard500msEvent(&xKB.i0);
	}else if(xKB.iHashtag >= 13){
		vMatrixKeyboard500msEvent(&xKB.iHashtag);
	}else if(xKB.iD >= 13){
		vMatrixKeyboard500msEvent(&xKB.iD);
	}



}

Keyboard  xMatrixKeyboardGetKeys(void){
	return xKB;
}

__weak void vMatrixKeyboard3sEvent(int*);
__weak void vMatrixKeyboard500msEvent(int*);
