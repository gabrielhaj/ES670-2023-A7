// ********************************************** //
// File name:                           buttons.h //
// File description:    This file is the header   //
//                    of the file that implements //
//                    the functions to read a     //
//                    button                      //
// Author names: Gabriel Haj and Luccas Yonei     //
// Creation date: 23/03/2023                      //
// Revision date: 03/04/2023					  //
// ********************************************** //
#ifndef BUTTONS_H
#define BUTTONS_H
#include "help.h"


typedef enum {UP= 1, DOWN,LEFT,RIGHT,ENTER} buttons;

pinState iButtonsReadStatus(buttons iButton);

#endif
