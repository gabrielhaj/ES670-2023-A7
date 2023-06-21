/* ***************************************************************** */
/* File name:        pid.c                                           */
/* File description: This file has a couple of useful functions to   */
/*                   control the implemented PID controller          */
/* Author name:      julioalvesMS, IagoAF, rBacurau                  */
/* Creation date:    21jun2018                                       */
/* Revision date:    21mai2023                                       */
/* ***************************************************************** */

#include "pid.h"
#include "main.h"
#include "heaterandcooler.h"

// Struct used to store the PID configuration parameters
pid_data_type pidConfig;
// Counter used to control the integration error window
unsigned short usIntegratorCount = 0;
// Buffer used to store the errors to generate the integral error
float fIntegratorBuffer[INTEGRATOR_MAX_SIZE]={0};

float fError, fDifference, fOut;

extern float fSetPointTemperature;

/* ************************************************ */
/* Method name:        vPidInit                     */
/* Method description: Initialize the PID controller*/
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void vPidInit(float fKp, float fKi, float fKd, unsigned short usIntSizeMs, float fOutputSaturation)
{
	pidConfig.fKp = fKp;
	pidConfig.fKd = fKd;
	pidConfig.fKi = fKi;
	pidConfig.fError_previous = 0;
	pidConfig.fError_sum = 0.0;

	// Saturates Integrator size (up to 10 s)
	if((usIntSizeMs/UPDATE_RATE_MS)> INTEGRATOR_MAX_SIZE)
	  usIntSizeMs = INTEGRATOR_MAX_SIZE * UPDATE_RATE_MS;

	pidConfig.usIntegratorSize = usIntSizeMs/UPDATE_RATE_MS;

	pidConfig.fOutputSaturation = fOutputSaturation;
}

/* ************************************************** */
/* Method name:        vPidSetKp                      */
/* Method description: Set a new value for the PID    */
/*                     proportional constant          */
/* Input params:       fKp: New value                 */
/* Output params:      n/a                            */
/* ************************************************** */
void vPidSetKp(float fKp)
{
	pidConfig.fKp = fKp;
}


/* ************************************************** */
/* Method name:        fPidGetKp                      */
/* Method description: Get the value from the PID     */
/*                     proportional constant          */
/* Input params:       n/a                            */
/* Output params:      float: Value                   */
/* ************************************************** */
float fPidGetKp(void)
{
	return pidConfig.fKp;
}


/* ************************************************** */
/* Method name:        vPidSetKi                      */
/* Method description: Set a new value for the PID    */
/*                     integrative constant           */
/* Input params:       fKi: New value                 */
/* Output params:      n/a                            */
/* ************************************************** */
void vPidSetKi(float fKi)
{
	pidConfig.fKi = fKi;
}


/* ************************************************** */
/* Method name:        fPidGetKi                      */
/* Method description: Get the value from the PID     */
/*                     integrative constant           */
/* Input params:       n/a                            */
/* Output params:      float: Value                   */
/* ************************************************** */
float fPidGetKi(void)
{
	return pidConfig.fKi;
}


/* ************************************************** */
/* Method name:        vPidSetKd                      */
/* Method description: Set a new value for the PID    */
/*                     derivative constant            */
/* Input params:       fKd: New value                 */
/* Output params:      n/a                            */
/* ************************************************** */
void vPidSetKd(float fKd)
{
	pidConfig.fKd = fKd;
}


/* ************************************************** */
/* Method name:        fPidGetKd                      */
/* Method description: Get the value from the PID     */
/*                     derivative constant            */
/* Input params:       n/a                            */
/* Output params:      float: Value                   */
/* ************************************************** */
float fPidGetKd(void)
{
	return pidConfig.fKd;
}

/* ************************************************** */
/* Method name:        vPidSetIntegratorWindow        */
/* Method description: Set a new value for the        */
/*                     integrator window (in ms)      */
/* Input params:       usIntSizeMs: New value (in ms) */
/* Output params:      n/a                            */
/* ************************************************** */
void vPidSetIntegratorWindow (unsigned short usIntSizeMs)
{
	// Saturates Integrator size (10000 ms)
	if((usIntSizeMs/UPDATE_RATE_MS)> INTEGRATOR_MAX_SIZE)
	  usIntSizeMs = INTEGRATOR_MAX_SIZE * UPDATE_RATE_MS;

	pidConfig.usIntegratorSize = usIntSizeMs/UPDATE_RATE_MS;
}

/* ************************************************** */
/* Method name:        usPidGetIntegratorWindow        */
/* Method description: Get the value from the         */
/*                     integrator window (in ms)      */
/* Input params:       n/a                            */
/* Output params:      usIntSizeMs: Value (in ms)     */
/* ************************************************** */
unsigned short usPidGetIntegratorWindow (void)
{
	return (pidConfig.usIntegratorSize*UPDATE_RATE_MS);
}

/* ************************************************** */
/* Method name:        pid_updateData                 */
/* Method description: Update the control output      */
/*                     using the reference and sensor */
/*                     value                          */
/* Input params:       fSensorValue: Value read from  */
/*                     the sensor                     */
/*                     fReferenceValue: Value used as */
/*                     control reference              */
/* Output params:      float: New Control effort     */
/* ************************************************** */
float fPidUpdateData(float fSensorValue, float fSetValue)
{
	//float fError, fDifference, fOut;

	// Proportional error
	fError = fSetValue - fSensorValue;

	//Ingtegral error
	pidConfig.fError_sum = pidConfig.fError_sum - fIntegratorBuffer[usIntegratorCount] + fError;

	fIntegratorBuffer[usIntegratorCount] = fError;

	if(++usIntegratorCount >= pidConfig.usIntegratorSize)
		usIntegratorCount = 0;

	// Differential error
	fDifference = (fError - pidConfig.fError_previous);

	fOut = pidConfig.fKp * fError
		 + pidConfig.fKi * pidConfig.fError_sum *UPDATE_RATE_MS
		 + pidConfig.fKd * fDifference /UPDATE_RATE_MS;

	pidConfig.fError_previous = fError;

	//fOut = -fOut;

	if(fOut > pidConfig.fOutputSaturation)
	{
		fOut = pidConfig.fOutputSaturation;
	}
//	else if (fOut < -pidConfig.fOutputSaturation)
//	{
//		fOut = -pidConfig.fOutputSaturation;
//	}

	return fOut;
}

float fPIDGetSetPointTemperature() {
	return fSetPointTemperature;
}

void vPIDSetSetPointTemperature(float fNewSetPointTemperature) {
	fSetPointTemperature = fNewSetPointTemperature;
}

void vPIDActuatorSetValue(float fActuatorValue) {
	/*
	 * Controle utilizando tanto heater quanto o cooler */
	if(fActuatorValue < 0) {
		//vHeaterAndCoolerCoolerfanPWMDuty(-0.3-fActuatorValue);
		vHeaterAndCoolerCoolerfanPWMDuty(-fActuatorValue);
		vHeaterAndCoolerHeaterPWMDuty(0);
	} else if(fActuatorValue > 0) {
		vHeaterAndCoolerHeaterPWMDuty(fActuatorValue);
		vHeaterAndCoolerCoolerfanPWMDuty(0);
	} else {
		vHeaterAndCoolerCoolerfanPWMDuty(0);
		vHeaterAndCoolerHeaterPWMDuty(0);
	}

}

__weak void vPIDPeriodicControlTask() {}
