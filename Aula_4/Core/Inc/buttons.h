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


typedef enum {up= 1, down,left,right,enter} buttons;

pinState buttonsReadStatus(buttons button);

#endif
