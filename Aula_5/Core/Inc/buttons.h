// ********************************************** //
// File name:                           buttons.h //
// File description:    This file is the header   //
//                    of the file that implements //
//                    the functions to read a     //
//                    button                      //
// Author names: Gabriel Haj and Luccas Yonei     //
// Creation date: 23/03/2023                      //
// Revision date: 20/06/2023					  //
// ********************************************** //
#ifndef BUTTONS_H
#define BUTTONS_H
#include "help.h"


typedef enum {enter,up ,down,left,right} buttons;

/* ************************************************ */
/* Method name:        xButtonsReadStatus           */
/* Method description: Read Buttons registers status*/
/* Input params:       xButton -> Button enum struct*/
/* Output params:      pinState -> set/reset        */
/*                                                  */
/* ************************************************ */
pinState xButtonsReadStatus(buttons xButton);

/* ************************************************ */
/* Method name:        xButtonsInit                 */
/* Method description: Init Buttons setting         */
/* 					   registers properly           */
/* Input params:                                    */
/* Output params:                                   */
/*                                                  */
/* ************************************************ */
void vButtonsInit(void);

#endif
