// ********************************************** //
// File name:                     buttonsEvents.h //
// File description:    This file is the header   //
//                    of buttons events function  //
//                                                //
//                                                //
// Author names: Gabriel Haj and Luccas Yonei     //
// Creation date: 13/04/2023                      //
// Revision date: 19/04/2023					  //
// ********************************************** //


#include <stdlib.h>
#include "communication.h"
#include "usart.h"



extern char cData;
char cVector[10];
int iCounter = 0;
char cFlagEnter = 0;
double fNumber = 0;





void HAL_UART_RxCpltCallback(UART_HandleTypeDef * huart){
	if(huart == &hlpuart1){
		if(cData == 13){
			cFlagEnter = 1;
		} else if(HAL_UART_Receive_IT(huart, (uint8_t*)&cData, 1) == HAL_OK && cFlagEnter) {
			cVector[iCounter] = cData;
			iCounter ++;
			if(iCounter == 10) {
				iCounter = 0;
				fNumber = atof(cVector);
				vFtoa(cVector, fNumber,3);
				HAL_UART_Transmit_IT(huart, (uint8_t *)cVector, 10);
			}
		}

		//vFtoa(cData, atof(cData), 3);



		HAL_UART_Receive_IT(huart, (uint8_t*)&cData, 1);
	}
}

void vFtoa(char* cStr, double fNum, int iNumCasaDec){
	int iInt, iDec;
	iInt = (int)fNum;
	iDec = (int)(fNum - iInt)*iNumCasaDec;
	sprintf(cStr, "%d,%03d", iInt, iDec);
}

