/*****************************************************************************/
//
// JB_GPIO.h
//
// Author: Josh Blakely
// Company: Robotic Elephant
// Revision: 0.0.4
// Date: 5/13/2013
//
// Purpose:
// This program is designed to control the GPIO using opening and closing of  
// files through fopen(). The maninuplation of the files are for general GPIO.
//
/*****************************************************************************/
//
// Revision History:
//  0.0.1:  5/13/2013
//      - Initial Release with GPIO out only
//  0.0.2:  5/25/2013
//      - Added PWM only for P8_13
//      - Added _CETYPE
//      - Added DEBUG ability
//  0.0.3:  7/2/2013
//      - Moved the CETYPE to a new header file "Hdr.h"
//      - Moved the define IN, OUT, LOW, HIGH to header file "Hdr.h"
//      - Moved debug option to header file "Hdr.h"
//  0.0.4:  7/4/2013
//      - Removed the PWM into its own files
//      - Added Input instead of output only
//  0.0.5: 12/11/2013
//      - Removed macros in the JB_GPIO.c that would create errors
//
/*****************************************************************************/

#ifndef _JB_GPIO_H_
#define _JB_GPIO_H_

enum
{
	gpioIn,
	gpioOut
	
} direction;

/**************************************************************************************/
// gpioExDirection:
//	This function will export the pin for usage as an output or input
//
// EX: gpioExDirection(23, gpioOut);
//
//	return:
//		CETYPE value
//
/**************************************************************************************/
int gpioExDirection(int pin, int direc);


/**************************************************************************************/
// closeGPIO:
//	This function will unexport the pin. It first sets the pin to input. Once it has
//	been set to input, it will unexport the pin
//
//	return:
//		CETYPE value
//
/**************************************************************************************/
int closeGPIO(int pin);


/**************************************************************************************/
// gpioReadDigPin:
//	This will read the GPIO pin as either a high or low. Need to run
//  gpioExDirection() and set direc to gpioIn before using this function
//
//	return:
//		CETYPE value
//
/**************************************************************************************/
int gpioReadDigPin(int pin, int *value);


/**************************************************************************************/
// gpioDigOutput:
//	This will write to the GPIO output pin either a high or low. Need to run
//  gpioExDirection() and set direc to gpioOut before using this function
//
//	return:
//		CETYPE value
//
/**************************************************************************************/
int gpioDigOutput(int pin, int HighLow);




#endif

