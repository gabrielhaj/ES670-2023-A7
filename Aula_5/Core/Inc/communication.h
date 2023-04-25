// ********************************************** //
// File name:                     communication.h //
// File description:   This file is the header of //
//                   the file that implements the //
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

#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/* This struct is used to check and manage the queue */
typedef struct {
	unsigned int uiBusyOrder;
	uint8_t * pAdress;
	int iSize;
} xBusyLine;

void HAL_UART_RxCpltCallback(UART_HandleTypeDef * huart);

void HAL_UART_TxCpltCallback(UART_HandleTypeDef * huart);

void vFtoa(char* cStr, double fNum, int iNumCasaDec);

#endif
