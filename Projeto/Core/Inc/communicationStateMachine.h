/* ***************************************************************** */
/* File name:        communicationStateMachine.h                     */
/* File description: This file is the header for the state machine   */
/* Author name:      Gabriel Haj, Luccas Yonei                       */
/* Creation date:    21jun2023                                       */
/* Revision date:    21jun2023                                       */
/* ***************************************************************** */

#ifndef INC_COMMUNICATIONSTATEMACHINE_H_
#define INC_COMMUNICATIONSTATEMACHINE_H_

/* ************************************************************************************* */
/* Method name:        vCommunicationStateMachineProcessStateMachine                     */
/* Method description: The state machine logic and flow implementation                   */
/* Input params:       ucByte: byte received via UART                                    */
/* Output params:      n/a                                                               */
/* ************************************************************************************* */
void vCommunicationStateMachineProcessStateMachine(unsigned char ucByte);

/* ************************************************************************************* */
/* Method name:        vFtoa                                                             */
/* Method description: Transforms a float variable to a string variable                  */
/* Input params:       fNum: float number to be transformed;                             */
/* 					   ucType: parameter to select the correct output format, depending  */
/* 							   on which input                                            */
/* Output params:      cStr: float transformed to string                                 */
/* ************************************************************************************* */
char* vFtoa(float fNum, unsigned char ucType);

/* ************************************************************************************* */
/* Method name:        vReturnParam                                                      */
/* Method description: Transmit via UART the parameters requested by GET. Those can be:  */
/* 						't' for current temperature;                                     */
/* 						'h' for current heater duty cycle;                               */
/* 						'c' for current cooler duty cycle;                               */
/* 						'p' for current controller kp;                                   */
/* 						'i' for current controller ki;                                   */
/* 						'd' for current controller kd;                                   */
/* 						'a' for all previous parameters.                                 */
/* Input params:       ucParamReturn: selector of which parameter is requested           */
/* Output params:      n/a                                                               */
/* ************************************************************************************* */
void vReturnParam(unsigned char ucParamReturn);

/* ************************************************************************************* */
/* Method name:        vSetParam                                                         */
/* Method description: Set parameters of the system                                      */
/* Input params:       ucParamSet: parameter to be set. They can be:                     */
/* 								't' for temperature;                                     */
/* 								'h' for heater duty cycle;                               */
/* 								'c' for cooler duty cycle;                               */
/* 								'p' for controller kp;                                   */
/* 								'i' for controller ki;                                   */
/* 								'd' for controller kd.                                   */
/* 					   cValue: pointer to the new value for the parameter                */
/* Output params:      n/a                                                               */
/* ************************************************************************************* */
void vSetParam(unsigned char ucParamSet,char* ucValue);

#endif /* INC_COMMUNICATIONSTATEMACHINE_H_ */

