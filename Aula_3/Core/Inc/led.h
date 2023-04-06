// ********************************************** //
// File name:                               led.h //
// File description:       This file declares the //
//                    functions needed to turn on,//
//                     off, and toggles the leds  //
//                     in the system              //
// Author names: Gabriel Haj and Luccas Yonei     //
// Creation date: 23/03/2023                      //
// Revision date: 03/04/2023					  //
// ********************************************** //
#ifndef LED_H
#define LED_H
#include "help.h"

typedef enum {GREEN1 = 1,YELLOW,RED,GREEN2,BLUE} leds;

void vLedWriteLed(leds iLed, pinState iState);
void vLedTurnLedOn(leds iLed);
void vLedTurnLedOff(leds iLed);
void vLedToggle(leds iLed);
// body of led.h file
#endif // LED_H
