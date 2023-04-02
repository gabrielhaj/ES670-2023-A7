// ********************************************** //
// File name:                               led.h //
// File description:       This file declares the //
//                    functions needed to turn on,//
//                     off, and toggles the leds  //
//                     in the system              //
// Author names: Gabriel Haj and Luccas Yonei     //
// Creation date: 23/03/2023                      //
// Revision date: 02/04/2023					  //
// ********************************************** //
#ifndef LED_H
#define LED_H

typedef enum {reset,set} pinState;
typedef enum {green1,yellow,red,green2,blue} leds;

void ledWrite(leds led, pinState state);
void ledOn(leds led);
void ledOff(leds led);
void ledToggle(leds led);
// body of automaticPilotControl.h file
#endif // AUTOPILOTCONTROL_H
