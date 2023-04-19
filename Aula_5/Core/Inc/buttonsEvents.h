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

void vButtonsEventsInit(TIM_HandleTypeDef *pTimDebouncerParam, TIM_HandleTypeDef *pTimPressedTimeParam);
void vButtonsEventsLongPressPeriodElapsedCallback(void);
void vButtonsEventsDebouncingPeriodElapsedCallback(void);
void vButtonsEventCallback500msPressedEvent(buttons xBt);
void vButtonsEventCallback3sPressedEvent(buttons xBt);
void vButtonsEventCallbackPressedEvent(buttons xBt);
void vButtonsEventCallbackReleasedEvent(buttons xBt);



#endif
