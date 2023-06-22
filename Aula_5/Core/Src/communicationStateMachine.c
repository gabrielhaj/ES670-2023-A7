/* ***************************************************************** */
/* File name:        communicationStateMachine.c                     */
/* File description: This file implements the state machine,         */
/*                   controlled by UART                              */
/* Author name:      Gabriel Haj, Luccas Yonei                       */
/* Creation date:    21jun2023                                       */
/* Revision date:    21jun2023                                       */
/* ***************************************************************** */
#include "usart.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "communicationStateMachine.h"

//Possible states of the state machine
#define IDDLE '0'
#define READY '1'
#define GET '2'
#define SET '3'
#define PARAM '4'
#define VALUE '5'

//Maximum lenght of string of values ("100,00")
#define MAX_VALUE_LENGHT 6

//Current state of the state machine
unsigned char ucMachineState = IDDLE;

//Counter for positioning on the string
unsigned char ucValueCount;

//The beggining of the answer string
char sData[5] = {"-a  \0"};

//The end of the answer string
char sData2[4] = {"!\n\r\0"};

//Variable to save the number cast to string
char cStr[7] = {0};


extern float fCurrentTemperature;
extern float fSetPointTemperature;
extern float fHeaterPWMDutyCycle;
extern float fCoolerPWMDutyCycle;

//Char sent via UART
unsigned char ucData;

//Variable to save the parameter received by the state machine
static unsigned char ucParam;

//String to save the char values to be send to vSetParam
static char cValue[MAX_VALUE_LENGHT+1];

//The whole answer string sent from successful GET
char sMessage[MAX_VALUE_LENGHT + 5 + 2] = {0};

//The whole answer string sent from successful GET (all parameters at once)
char sAllMessage[(MAX_VALUE_LENGHT+5+2)*6] = {0};

/* ************************************************************************************* */
/* Method name:        vCommunicationStateMachineProcessStateMachine                     */
/* Method description: The state machine logic and flow implementation                   */
/* Input params:       ucByte: byte received via UART                                    */
/* Output params:      n/a                                                               */
/* ************************************************************************************* */
void vCommunicationStateMachineProcessStateMachine(unsigned char ucByte) {
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
					if('t' == ucByte || 'h' == ucByte || 'c' == ucByte || 'a'== ucByte || 'p' == ucByte || 'i' == ucByte || 'd' == ucByte ) {
						ucParam = ucByte;
						ucMachineState = PARAM;
					} else {
						ucMachineState = IDDLE;
					}
					break;
				case SET:
					if('t' == ucByte ||'h' == ucByte || 'c' == ucByte || 'p' == ucByte || 'i' == ucByte || 'd' == ucByte ) {
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
					if((ucByte >= '0' && ucByte <= '9') || ',' == ucByte || '.' == ucByte) {
						if(',' == ucByte) {
							ucByte = '.';
						}
						if(ucValueCount < MAX_VALUE_LENGHT){
							cValue[ucValueCount++] = ucByte;
						}
					} else {
						if('!' == ucByte) {
							cValue[ucValueCount] = '\0';
							vSetParam(ucParam,cValue);
						}
						ucMachineState = IDDLE;
					}
					break;
			}

		}
	}
}

/* ************************************************************************************* */
/* Method name:        HAL_UART_RxCpltCallback                                           */
/* Method description: The callback to receive the data from pc keyboard                 */
/* Input params:       UART_HandleTypeDef pointer for UART handler                       */
/* Output params:      n/a                                                               */
/* ************************************************************************************* */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
	if(huart == &hlpuart1) {
		vCommunicationStateMachineProcessStateMachine(ucData);
		HAL_UART_Receive_IT(huart, (uint8_t*)&ucData, 1);
	}
}

/* ************************************************************************************* */
/* Method name:        vFtoa                                                             */
/* Method description: Transforms a float variable to a string variable                  */
/* Input params:       fNum: float number to be transformed;                             */
/* 					   ucType: parameter to select the correct output, depending on which*/
/* 							   input                                                     */
/* Output params:      n/a                                                               */
/* ************************************************************************************* */
char* vFtoa(float fNum, unsigned char ucType){
	int iInt, iDec;
	if(ucType == 'h' || ucType == 'c') {
		iInt = (int)fNum;
		sprintf(cStr, "%d", iInt);
		return cStr;
	} else {
		iInt = (int)fNum;
		iDec = (int)((fNum - iInt)*100);
		sprintf(cStr, "%d,%02d", iInt, iDec);
		return cStr;
	}

}

void vReturnParam(unsigned char ucParamReturn) {
	int iSize = 1;
	memset(sMessage,0,sizeof(sMessage));
	switch(ucParamReturn) {
		case 't':
			sData[2] = ucParamReturn;
			strcat(sMessage,sData);
			strcat(sMessage,vFtoa(fTemperatureSensorGetTemperature(),ucParamReturn));
			strcat(sMessage,sData2);
			while(sMessage[iSize] != '\0'){
				iSize ++;
			}
			HAL_UART_Transmit_IT(&hlpuart1, (uint8_t*)sMessage, (uint16_t)iSize);
			break;
		case 'h':
			sData[2] = ucParamReturn;
			strcat(sMessage,sData);
			strcat(sMessage,vFtoa(fHeaterPWMDutyCycle,ucParamReturn));
			strcat(sMessage,sData2);
			while(sMessage[iSize] != '\0'){
				iSize ++;
			}
			HAL_UART_Transmit_IT(&hlpuart1, (uint8_t*)sMessage, (uint16_t)iSize);
			break;
		case 'c':
			sData[2] = ucParamReturn;
			strcat(sMessage,sData);
			strcat(sMessage,vFtoa(fCoolerPWMDutyCycle,ucParamReturn));
			strcat(sMessage,sData2);
			while(sMessage[iSize] != '\0'){
				iSize ++;
			}
			HAL_UART_Transmit_IT(&hlpuart1, (uint8_t*)sMessage, (uint16_t)iSize);
			break;
		case 'p':
			sData[2] = ucParamReturn;
			strcat(sMessage,sData);
			strcat(sMessage,vFtoa(fPidGetKp(),ucParamReturn));
			strcat(sMessage,sData2);
			while(sMessage[iSize] != '\0'){
				iSize ++;
			}
			HAL_UART_Transmit_IT(&hlpuart1, (uint8_t*)sMessage, (uint16_t)iSize);
			break;
		case 'd':
			sData[2] = ucParamReturn;
			strcat(sMessage,sData);
			strcat(sMessage,vFtoa(fPidGetKd(),ucParamReturn));
			strcat(sMessage,sData2);
			while(sMessage[iSize] != '\0'){
				iSize ++;
			}
			HAL_UART_Transmit_IT(&hlpuart1, (uint8_t*)sMessage, (uint16_t)iSize);
			break;
		case 'i':
			sData[2] = ucParamReturn;
			strcat(sMessage,sData);
			strcat(sMessage,vFtoa(fPidGetKi(),ucParamReturn));
			strcat(sMessage,sData2);
			while(sMessage[iSize] != '\0'){
				iSize ++;
			}
			HAL_UART_Transmit_IT(&hlpuart1, (uint8_t*)sMessage, (uint16_t)iSize);
			break;
		case 'a':
			memset(sAllMessage,0,sizeof(sAllMessage));
			sData[2] = 't';
			strcat(sAllMessage,sData);
			strcat(sAllMessage,vFtoa(fTemperatureSensorGetTemperature(),ucParamReturn));
			strcat(sAllMessage,sData2);
			sData[2] = 'h';
			strcat(sAllMessage,sData);
			strcat(sAllMessage,vFtoa(fHeaterPWMDutyCycle,ucParamReturn));
			strcat(sAllMessage,sData2);
			sData[2] = 'c';
			strcat(sAllMessage,sData);
			strcat(sAllMessage,vFtoa(fCoolerPWMDutyCycle,ucParamReturn));
			strcat(sAllMessage,sData2);
			sData[2] = 'p';
			strcat(sAllMessage,sData);
			strcat(sAllMessage,vFtoa(fPidGetKp(),ucParamReturn));
			strcat(sAllMessage,sData2);
			sData[2] = 'i';
			strcat(sAllMessage,sData);
			strcat(sAllMessage,vFtoa(fPidGetKi(),ucParamReturn));
			strcat(sAllMessage,sData2);
			sData[2] = 'd';
			strcat(sAllMessage,sData);
			strcat(sAllMessage,vFtoa(fPidGetKd(),ucParamReturn));
			strcat(sAllMessage,sData2);
			while(sAllMessage[iSize] != '\0'){
				iSize ++;
			}
			HAL_UART_Transmit_IT(&hlpuart1, (uint8_t*)sAllMessage, (uint16_t)iSize);
			break;
	}
}

void vSetParam(unsigned char ucParamSet, char* cValue){
	switch(ucParamSet) {
		case 't':
			fSetPointTemperature = atof(cValue);
			break;
		case 'h':
			fHeaterPWMDutyCycle = atof(cValue); // it should be treated afterwards
			break;
		case 'c':
			fCoolerPWMDutyCycle = atof(cValue);
			break;
		case 'p':
			vPidSetKp(atof(cValue));
			break;
		case 'i':
			vPidSetKi(atof(cValue));
			break;
		case 'd':
			vPidSetKd(atof(cValue));
			break;
	}
}




