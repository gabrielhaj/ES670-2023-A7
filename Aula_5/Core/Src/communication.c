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
#include <string.h>
#include "communication.h"
#include "usart.h"



extern char cData;
char cVector[64] = {0};
int iCounter = 0;
char cFlagEnter = 0;
double fNumber = 0;
char cEnter[2] = "\n\r";
char sInstrucaoUsuario2[58] = "\n\rInsert a number between -1000 and 1000 and press enter\n\r";
uint8_t *pMensagem;
char sMensagem[87] = "Número fora do intervalo!\n\rInsert a number between -1000 and 1000 and press enter\n\r";
int iCounterComma = 0;
char cFlagComma = 0;
char sZero[3] = "inf";
xBusyLine xFlag[] = {0};
int iBusyQueue = 0;
char cFlagBusy = 0;


void HAL_UART_RxCpltCallback(UART_HandleTypeDef * huart){
	if(huart == &hlpuart1){
		if(cData == 13){
			if((HAL_UART_Transmit_IT(huart,(uint8_t*)cEnter,sizeof(cEnter))) == HAL_BUSY){
				xFlag[iBusyQueue].pAdress = cEnter;
				xFlag[iBusyQueue].iSize = sizeof(cEnter);
				iBusyQueue ++;
				if(!cFlagBusy) {
					cFlagBusy = 1;
				}
			}
			if(cFlagComma == 0) {
				iCounterComma = iCounter -3;
			}
			if(cVector[0] == '-'){
				cVector[iCounterComma + 3] = '\0';
			}else {
				cVector[iCounterComma + 3] = '\0';
			}
			fNumber = atof(cVector);
			if(fNumber <= 1000 && fNumber >= -1000){
				vFtoa(cVector, 1/fNumber, 3);
				strcat(cVector,sInstrucaoUsuario2);
				if((HAL_UART_Transmit_IT(huart, (uint8_t*)cVector, sizeof(cVector))) == HAL_BUSY){
					xFlag[iBusyQueue].pAdress = cVector;
					xFlag[iBusyQueue].iSize = sizeof(cVector);
					iBusyQueue ++;
					if(!cFlagBusy) {
						cFlagBusy = 1;
					}
				}
				iCounter = 0;
				cFlagComma = 0;
				iCounterComma = 0;
			} else {
				if((HAL_UART_Transmit_IT(huart, (uint8_t*)sMensagem, sizeof(sMensagem))) == HAL_BUSY){
					xFlag[iBusyQueue].pAdress = sMensagem;
					xFlag[iBusyQueue].iSize = sizeof(sMensagem);
					iBusyQueue ++;
					if(!cFlagBusy) {
						cFlagBusy = 1;
					}
				}
				iCounter = 0;
			}
	} else if(cData == '0') {
		strcat(sZero,sInstrucaoUsuario2);
		if((HAL_UART_Transmit_IT(huart, (uint8_t*)sZero, sizeof(sZero))) == HAL_BUSY) {
			xFlag[iBusyQueue].pAdress = sZero;
			xFlag[iBusyQueue].iSize = sizeof(sZero);
			iBusyQueue ++;
			if(!cFlagBusy) {
				cFlagBusy = 1;
			}
		}
	} else {
		if(cData == ','){
			iCounterComma = iCounter;
			cFlagComma = 1;
			cData = '.';
		}
		cVector[iCounter] = cData;
		iCounter ++;
	}
		if((HAL_UART_Transmit_IT(huart, (uint8_t*)&cData,1)) == HAL_BUSY){
			xFlag[iBusyQueue].pAdress = &cData;
			xFlag[iBusyQueue].iSize = sizeof(cData);
			iBusyQueue ++;
			if(!cFlagBusy) {
				cFlagBusy = 1;
			}
		}
		HAL_UART_Receive_IT(huart, (uint8_t*)&cData, 1);
	}
}

void HAL_UART_TxCpltCallback(UART_HandleTypeDef * huart) {
	if(cFlagBusy) {
		HAL_UART_Transmit_IT(huart, xFlag[iBusyQueue].pAdress,xFlag[iBusyQueue].iSize);
		iBusyQueue --;
	}
	if(iBusyQueue == 0){
		cFlagBusy = 0;
	}
	HAL_UART_Receive_IT(huart, (uint8_t*)&cData, 1);
}

void vFtoa(char* cStr, double fNum, int iNumCasaDec){
	int iInt, iDec;
	if(fNum >= 0){
		iInt = (int)fNum;
		iDec = (int)((fNum - iInt)*1000);
		sprintf(cStr, "%d,%03d", iInt, iDec);
	} else if(fNum < 0){
		fNum = -fNum;
		iInt = (int)fNum;
		iDec = (int)((fNum - iInt)*1000);
		sprintf(cStr, "-%d,%03d", iInt, iDec);
	}
}

