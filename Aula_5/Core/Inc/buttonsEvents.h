













#ifndef BUTTONSEVENTS_H
#define BUTTONSEVENTS_H
#include "buttons.h"
#include "tim.h"

void vButtonsEventsInit(TIM_HandleTypeDef *pTimDebouncerParam, TIM_HandleTypeDef *pTimPressedTimeParam);
void timerButtonsEventsLongPressPeriodElapsedCallback(void);
void timerButtonsEventsDebouncingPeriodElapsedCallback(void);
void vButtonsEventCallback500msPressedEvent(buttons xBt);
void vButtonsEventCallback3sPressedEvent(buttons xBt);
void vButtonsEventCallbackPressedEvent(buttons xBt);
void vButtonsEventCallbackReleasedEvent(buttons xBt);









#endif
