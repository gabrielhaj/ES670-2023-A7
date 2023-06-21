// ********************************************** //
// File name:                     buttonsEvents.h //
// File description:    This file is the header   //
//                    of buttons events function  //
//                                                //
//                                                //
// Author names: Gabriel Haj and Luccas Yonei     //
// Creation date: 13/04/2023                      //
// Revision date: 19/04/2023					  //
// ********************************************** //

#ifndef BUTTONSEVENTS_H
#define BUTTONSEVENTS_H
#include "buttons.h"
#include "tim.h"

/* ************************************************ */
/* Method name:        vButtonsEventsInit           */
/* Method description: Stores Debouncer and Pressed */
/*					   pointer localy               */
/* Input params:       TIM_HandleTypeDef pointers   */
/*                    for debouncer and pressed time*/
/*                    handlers                      */
/* Output params:                                   */
/* ************************************************ */
void vButtonsEventsInit(TIM_HandleTypeDef *pTimDebouncerParam, TIM_HandleTypeDef *pTimPressedTimeParam);

/* ***************************************************************** */
/* Method name:        vButtonsEventsDebouncingPeriodElapsedCallback */
/* Method description: Enable Interruption                            */
/*					   exti module where we                          */
/*                     turn on debouncer timer                       */
/*                     and off exti interruption                     */
/*                     and set their flag on                         */
/*                     Also turn on timer from                       */
/*                     pressed time if it is not yet                 */
/* Input params:       GPIO_Pin                                      */
/* Output params:                                                    */
/* ***************************************************************** */
void vButtonsEventsLongPressPeriodElapsedCallback(void);

/* ***************************************************************** */
/* Method name:        vButtonsEventsLongPressPeriodElapsedCallback  */
/* Method description: Callback for LongPress timer                  */
/*                     Check each buttons state and increment their  */
/*					   counter for 500ms and 3s.If the button is not */
/*                     on restart the counter                        */
/* Input params:                                                     */
/* Output params:                                                    */
/* ***************************************************************** */
void vButtonsEventsDebouncingPeriodElapsedCallback(void);

/* ***************************************************************** */
/* Method name:        vButtonsEventsChangeScreen                    */
/* Method description: Change LCD screen value to update screen      */
/*                     LCD display. Also allows user to increment    */
/*					   temperature setpoint in the first screen and  */
/*                     to turn on/off backlight screen by Enter button*/
/* Input params:  xBt buttons                                        */
/* Output params:                                                    */
/* ***************************************************************** */
void vButtonsEventChangeScreen(buttons xBt);


void vButtonsEventCallback500msPressedEvent(buttons xBt);
void vButtonsEventCallback3sPressedEvent(buttons xBt);
void vButtonsEventCallbackPressedEvent(buttons xBt);
void vButtonsEventCallbackReleasedEvent(buttons xBt);





#endif
