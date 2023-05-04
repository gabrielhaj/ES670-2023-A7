/*
 * communicationStateMachine.h
 *
 *  Created on: Apr 27, 2023
 *      Author: aluno
 */

#ifndef INC_COMMUNICATIONSTATEMACHINE_H_
#define INC_COMMUNICATIONSTATEMACHINE_H_

void vCommunicationStateMachineProcessStateMachine(unsigned char ucByte);
char* vFtoa(float fNum, unsigned char ucParam);
void vReturnParam(unsigned char ucParam);
void vSetParam(unsigned char ucParam, unsigned char* ucValue);



#endif /* INC_COMMUNICATIONSTATEMACHINE_H_ */
