// ********************************************** //
// File name:                               led.h //
// File description:       This file declares the //
//                    functions needed to turn on,//
//                     off, and toggles the leds  //
//                     in the system              //
// Author names: Gabriel Haj and Luccas Yonei     //
// Creation date: 23/03/2023                      //
// Revision date: 19/04/2023					  //
// ********************************************** //
#ifndef LED_H
#define LED_H
#include "help.h"

typedef enum {green1 = 4,yellow = 3,red = 2,green2 = 1,blue = 0} leds;

void vLedInit(void);
void vLedWrite(leds xLed, pinState xState);
void vLedTurnOn(leds xLed);
void vLedTurnOff(leds xLed);
void vLedToggle(leds xLed);

#endif 
