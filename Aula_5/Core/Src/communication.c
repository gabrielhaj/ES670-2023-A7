// ********************************************** //
// File name:                     communication.c //
// File description:     This file implements the //
//                   functions and callbacks used //
//             	        to make the communication //
//                   between the computer and the //
//                 system, receiving a number and //
//                      transmitting its inverse. //
//                                                //
// Author names: Gabriel Haj and Luccas Yonei     //
// Creation date: 24/04/2023                      //
// Revision date: 25/04/2023		          //
// ********************************************** //



#include "communication.h"
#include "usart.h"


/* Initializing global variables */
extern char cData;
char cVector[64] = {0};
int iCounter = 0;
char cFlagEnter = 0;
double fNumber = 0;
char cEnter[2] = "\n\r";
char sInstrucaoUsuario2[58] = "\n\rInsert a number between -1000 and 1000 and press enter\n\r";
char sMensagem[87] = "Número fora do intervalo!\n\rInsert a number between -1000 and 1000 and press enter\n\r";
int iCounterComma = 0;
char cFlagComma = 0;
char sZero[61] = "inf\n\rInsert a number between -1000 and 1000 and press enter\n\r";
xBusyLine xFlag[] = {0};
int iBusyQueue = 0;
char cFlagBusy = 0;

/* This callback takes the input and treats it. Then it waits for another input */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef * huart){
	if(huart == &hlpuart1){
		if(cData == 13){
			if((HAL_UART_Transmit_IT(huart,(uint8_t*)cEnter,sizeof(cEnter))) == HAL_BUSY){
				iBusyQueue ++;
				xFlag[iBusyQueue].pAdress = (uint8_t*)cEnter;
				xFlag[iBusyQueue].iSize = sizeof(cEnter);
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
			if(fNumber == 0) {
				if((HAL_UART_Transmit_IT(huart, (uint8_t*)sZero, sizeof(sZero))) == HAL_BUSY){
					iBusyQueue ++;
					xFlag[iBusyQueue].pAdress = (uint8_t*)sZero;
					xFlag[iBusyQueue].iSize = sizeof(sZero);
					if(!cFlagBusy) {
						cFlagBusy = 1;
					}
				}
			} else if(fNumber <= 1000 && fNumber >= -1000){
				vFtoa(cVector, 1/fNumber, 3);
				strcat(cVector,sInstrucaoUsuario2);
				if((HAL_UART_Transmit_IT(huart, (uint8_t*)cVector, sizeof(cVector))) == HAL_BUSY){
					iBusyQueue ++;
					xFlag[iBusyQueue].pAdress = (uint8_t*)cVector;
					xFlag[iBusyQueue].iSize = sizeof(cVector);
					if(!cFlagBusy) {
						cFlagBusy = 1;
					}
				}
			} else {
				if((HAL_UART_Transmit_IT(huart, (uint8_t*)sMensagem, sizeof(sMensagem))) == HAL_BUSY){
					iBusyQueue ++;
					xFlag[iBusyQueue].pAdress = (uint8_t*)sMensagem;
					xFlag[iBusyQueue].iSize = sizeof(sMensagem);
					if(!cFlagBusy) {
						cFlagBusy = 1;
					}
				}
			}
			iCounter = 0;
			cFlagComma = 0;
			iCounterComma = 0;
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
			iBusyQueue ++;
			xFlag[iBusyQueue].pAdress = (uint8_t*)&cData;
			xFlag[iBusyQueue].iSize = sizeof(cData);
			if(!cFlagBusy) {
				cFlagBusy = 1;
			}
		}
		HAL_UART_Receive_IT(huart, (uint8_t*)&cData, 1);
	}
}

/* This callback checks if the queue is busy and transmits the next, then receives data */
void HAL_UART_TxCpltCallback(UART_HandleTypeDef * huart) {
	if(iBusyQueue == 0){
		cFlagBusy = 0;
	}
	if(cFlagBusy) {
		HAL_UART_Transmit_IT(huart, xFlag[iBusyQueue].pAdress,xFlag[iBusyQueue].iSize);
		iBusyQueue --;
	}
	HAL_UART_Receive_IT(huart, (uint8_t*)&cData, 1);
}

/* This function transforms a double number into a string */
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

