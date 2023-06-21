/*
 * communicationStateMachine.h
 *
 *  Created on: Apr 27, 2023
 *      Author: aluno
 */

#ifndef INC_COMMUNICATIONSTATEMACHINE_H_
#define INC_COMMUNICATIONSTATEMACHINE_H_

void vCommunicationStateMachineProcessStateMachine(unsigned char ucByte);
char* vFtoa(float fNum, unsigned char ucType);
void vReturnParam(unsigned char ucParamReturn);
void vSetParam(unsigned char ucParamSet, unsigned char* ucValue);



#endif /* INC_COMMUNICATIONSTATEMACHINE_H_ */

