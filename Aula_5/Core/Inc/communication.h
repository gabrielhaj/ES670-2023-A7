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

#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <string.h>
#include "main.h"

typedef struct {
	unsigned int uiBusyOrder;
	uint8_t * pAdress;
	int iSize;
} xBusyLine;
void HAL_UART_RxCpltCallback(UART_HandleTypeDef * huart);
void vFtoa(char* cStr, double fNum, int iNumCasaDec);
#endif
