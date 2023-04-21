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
char cVector[5];
int iCounter = 0;
char cFlagEnter = 0;
double fNumber = 0;
char sInstrucaoUsuario2[58] = "\n\rPress enter and insert a number between -1000 and 1000\n\r";
uint8_t *pMensagem;





void HAL_UART_RxCpltCallback(UART_HandleTypeDef * huart){
	if(huart == &hlpuart1){
		if(cData == 13){
			cFlagEnter = 1;
		} else if(cFlagEnter) {
			cVector[iCounter] = cData;
			iCounter ++;
			if((iCounter % 4) == 0) {
				fNumber = atof(cVector);
				if(fNumber <= 1000 || fNumber >= -1000){
					vFtoa(cVector, 1/fNumber, 3);
					HAL_UART_Transmit_IT(huart, (uint8_t *)cVector, sizeof(cVector));
					pMensagem = sInstrucaoUsuario2;
				}
			}
		}
		HAL_UART_Receive_IT(huart, (uint8_t*)&cData, 1);
	}
}

void HAL_UART_TxCpltCallback(UART_HandleTypeDef * huart) {
	HAL_UART_Transmit_IT(huart,pMensagem,sizeof(pMensagem));
}

void vFtoa(char* cStr, double fNum, int iNumCasaDec){
	int iInt, iDec;
	iInt = (int)fNum;
	iDec = (int)(fNum - iInt)*iNumCasaDec;
	sprintf(cStr, "%d,%03d", iInt, iDec);
}

