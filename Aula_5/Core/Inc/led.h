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

//enum to travel through leds
typedef enum {green1 = 4,yellow = 3,red = 2,green2 = 1,blue = 0} leds;

/* ************************************************ */
/* Method name:        vLedInit                     */
/* Method description: Initialize the leds registers*/
/* Input params:                                    */
/* Output params:                                   */
/* ************************************************ */
void vLedInit(void);

/* ************************************************ */
/* Method name:        vLedWrite                    */
/* Method description: Write leds registers field to*/
/*                     turn on or turn off the led  */
/* Input params:       xLed: led to change value    */
/*                     xState: set or reset         */
/* Output params:                                   */
/* ************************************************ */
void vLedWrite(leds xLed, pinState xState);

/* ************************************************ */
/* Method name:        vLedTurnOn                   */
/* Method description: Call led write with set value*/
/* Input params:       xLed: led to change value    */
/* Output params:                                   */
/* ************************************************ */
void vLedTurnOn(leds xLed);

/* ************************************************ */
/* Method name:        vLedTurnOf                   */
/* Method description: Call led write with          */
/*                     reset value                  */
/* Input params:       xLed: led to change value    */
/* Output params:                                   */
/* ************************************************ */
void vLedTurnOff(leds xLed);

/* ************************************************ */
/* Method name:        vLedToogle                   */
/* Method description: Check led value and          */
/*                     toogles it                   */
/* Input params:       xLed: led to change value    */
/* Output params:                                   */
/* ************************************************ */
void vLedToggle(leds xLed);

#endif 
