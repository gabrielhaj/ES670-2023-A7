/*
 * communicationStateMachine.c
 *
 *  Created on: Apr 27, 2023
 *      Author: aluno
 */

#include "usart.h"
#include <stdio.h>
#include <string.h>
#include "communicationStateMachine.h"

#define IDDLE '0'
#define READY '1'
#define GET '2'
#define SET '3'
#define PARAM '4'
#define VALUE '5'

#define MAX_VALUE_LENGHT 4

unsigned char ucMachineState = IDDLE;
unsigned char ucValueCount;
char sData[3] = {"-a "};
char sData2[3] = {"!\n\r"};
char cStr[5] = {0};
extern float fCurrentTemperature;
extern float fSetPointTemperature;
extern unsigned char ucButtonsBlocked;
extern unsigned char ucDutyHeater;
extern unsigned char ucDutyCooler;
extern unsigned char ucData;

void vCommunicationStateMachineProcessStateMachine(unsigned char ucByte) {
	static unsigned char ucParam;
	static unsigned char ucValue[MAX_VALUE_LENGHT+1];

	if('-' == ucByte) {
		ucMachineState = READY;
	} else {
		if(IDDLE != ucMachineState) {
			switch(ucMachineState) {
				case READY:
					switch(ucByte) {
						case 'g' :
							ucMachineState = GET;
							break;
						case 's':
							ucMachineState = SET;
							break;
						default:
							ucMachineState = IDDLE;
					}
					break;
				case GET:
					if('t' == ucByte || 'b' == ucByte || 'h' == ucByte || 'c' == ucByte || 'a'== ucByte) {
						ucParam = ucByte;
						ucMachineState = PARAM;
					} else {
						ucMachineState = IDDLE;
					}
					break;
				case SET:
					if('t' == ucByte || 'b' == ucByte || 'h' == ucByte || 'c' == ucByte) {
						ucParam = ucByte;
						ucValueCount = 0;
						ucMachineState = VALUE;
					} else {
						ucMachineState = IDDLE;
					}
					break;
				case PARAM:
					if('!' == ucByte) {
						vReturnParam(ucParam);
					}
					ucMachineState = IDDLE;
					break;
				case VALUE:
					if((ucByte >= '0' && ucByte <= '9') || ',' == ucByte) {
						if(ucValueCount < MAX_VALUE_LENGHT){
							ucValue[ucValueCount++] = ucByte;
						}
					} else {
						if('!' == ucByte) {
							ucValue[ucValueCount] = '\0';
							vSetParam(ucParam,ucValue);
						}
						ucMachineState = IDDLE;
					}
					break;
			}

		}
	}
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
	if(huart == &hlpuart1) {
		vCommunicationStateMachineProcessStateMachine(ucData);
		HAL_UART_Receive_IT(huart, (uint8_t*)&ucData, 1);
	}

}

char* vFtoa(float fNum, unsigned char ucParam){ //Colocar ucParam como global na hora de mandar o final
	int iInt, iDec;
	if(ucParam == 'h' || ucParam == 'c') {
		iInt = (int)fNum;
		sprintf(cStr, "%d", iInt);
		return cStr;
	} else {
		iInt = (int)fNum;
		iDec = (int)((fNum - iInt)*100);
		sprintf(cStr, "%d,%001d", iInt, iDec);
		return cStr;
	}

}

void vReturnParam(unsigned char ucParam) {
	char sMessage[MAX_VALUE_LENGHT + 5 + 2] = {0};
	switch(ucParam) {
		case 't':
			strcat(sMessage,sData);
			strcat(sMessage,vFtoa(fTemperatureSensorGetTemperature(),ucParam));
			strcat(sMessage,sData2);
			HAL_UART_Transmit_IT(&hlpuart1, sMessage, sizeof(sMessage));
			break;
		case 'b':
			strcat(sMessage,sData);
			if(ucButtonsBlocked) {
				strcat(sMessage,"1");
			} else {
				strcat(sMessage,"0");
			}
			strcat(sMessage,sData2);
			HAL_UART_Transmit_IT(&hlpuart1, sMessage, sizeof(sMessage));
			break;
		case 'h':
			strcat(sMessage,sData);
			strcat(sMessage,vFtoa(ucDutyHeater,ucParam));
			strcat(sMessage,sData2);
			HAL_UART_Transmit_IT(&hlpuart1, sMessage, sizeof(sMessage));
			break;
		case 'c':
			strcat(sMessage,sData);
			strcat(sMessage,vFtoa(ucDutyCooler,ucParam));
			strcat(sMessage,sData2);
			HAL_UART_Transmit_IT(&hlpuart1, sMessage, sizeof(sMessage));
			break;
		case 'a':
			vReturnParam('t');
			vReturnParam('b');
			vReturnParam('h');
			vReturnParam('c');
			break;
	}
}

void vSetParam(unsigned char ucParam, unsigned char* ucValue){
	switch(ucParam) {
		case 't':
			fSetPointTemperature = atof(ucValue);
			break;
		case 'b':
			ucButtonsBlocked = ucValue;
			break;
		case 'h':
			ucDutyHeater = ucValue; // it should be treated afterwards
			break;
		case 'c':
			ucDutyCooler = ucValue;
			break;
	}
}




