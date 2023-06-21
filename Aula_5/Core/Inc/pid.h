/* ***************************************************************** */
/* File name:        pid.h                                           */
/* File description: Header file containing the functions/methods    */
/*                   interfaces for handling the PID                 */
/* Author name:      julioalvesMS, IagoAF, rBacurau                  */
/* Creation date:    21jun2018                                       */
/* Revision date:    21mai2023                                       */
/* ***************************************************************** */

#ifndef SOURCES_CONTROLLER_PID_H_
#define SOURCES_CONTROLLER_PID_H_

#define UPDATE_RATE_MS      100
#define INTEGRATOR_MAX_SIZE 100

typedef struct pid_data_type {
	float fKp, fKi, fKd;         		// PID gains
	float fError_previous;       		// used in the derivative
	float fError_sum;            		// integrator cumulative error
	unsigned short usIntegratorSize; 	//integrator window size
	float fOutputSaturation;            // output saturation
} pid_data_type;


/* ************************************************ */
/* Method name:        vPidInit                     */
/* Method description: Initialize the PID controller*/
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void vPidInit(float fKp, float fKi, float fKd, unsigned short usIntegratorSize, float fOutputSaturation);


/* ************************************************** */
/* Method name:        vPidSetKp                      */
/* Method description: Set a new value for the PID    */
/*                     proportional constant          */
/* Input params:       fKp: New value                 */
/* Output params:      n/a                            */
/* ************************************************** */
void vPidSetKp(float fKp);


/* ************************************************** */
/* Method name:        fPidGetKp                      */
/* Method description: Get the value from the PID     */
/*                     proportional constant          */
/* Input params:       n/a                            */
/* Output params:      float: Value                   */
float fPidGetKp(void);


/* ************************************************** */
/* Method name:        vPidSetKi                      */
/* Method description: Set a new value for the PID    */
/*                     integrative constant           */
/* Input params:       fKi: New value                 */
/* Output params:      n/a                            */
/* ************************************************** */
void vPidSetKi(float fKi);


/* ************************************************** */
/* Method name:        fPidGetKi                      */
/* Method description: Get the value from the PID     */
/*                     integrative constant           */
/* Input params:       n/a                            */
/* Output params:      float: Value                   */
/* ************************************************** */
float fPidGetKi(void);


/* ************************************************** */
/* Method name:        vPidSetKd                      */
/* Method description: Set a new value for the PID    */
/*                     derivative constant            */
/* Input params:       fKd: New value                 */
/* Output params:      n/a                            */
/* ************************************************** */
void vPidSetKd(float fKd);


/* ************************************************** */
/* Method name:        fPidGetKd                      */
/* Method description: Get the value from the PID     */
/*                     derivative constant            */
/* Input params:       n/a                            */
/* Output params:      float: Value                   */
/* ************************************************** */
float fPidGetKd(void);

/* ************************************************** */
/* Method name:        vPidSetIntegratorWindow        */
/* Method description: Set a new value for the        */
/*                     integrator window (in ms)      */
/* Input params:       usIntSizeMs: New value (in ms) */
/* Output params:      n/a                            */
/* ************************************************** */
void vPidSetIntegratorWindow (unsigned short usIntSizeMs);

/* ************************************************** */
/* Method name:        pid_getIntegratorWindow        */
/* Method description: Get the value from the         */
/*                     integrator window (in ms)      */
/* Input params:       n/a                            */
/* Output params:      usIntSizeMs: Value (in ms)     */
/* ************************************************** */
unsigned short pid_getIntegratorWindow (void);

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
float fPidUpdateData(float fSensorValue, float fReferenceValue);

void vPIDPeriodicControlTask();
float fPIDGetSetPointTemperature();
void vPIDActuatorSetValue(float fActuatorValue);



#endif /* SOURCES_CONTROLLER_PID_H_ */
