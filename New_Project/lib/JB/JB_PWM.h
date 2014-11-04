/*****************************************************************************/
//
//  JB_PWM.h
//  
// Author: Josh Blakely
// Company: Robotic Elephant
// Revision: 0.0.1
// Date: 7/4/2013
//
// Purpose:
// This program is designed to control the PWM using opening and closing of
// files through fopen().
//
//  **At this point if disable is used it will lock up the slots**
//
/*****************************************************************************/
//
// Revision History:
//  0.0.1:  7/4/2013
//      - Initial Release
//
/*****************************************************************************/

#ifndef _JB_PWM_h
#define _JB_PWM_h

typedef enum _PWM_PIN
{
    P8_13 = 13,         // EHRPWM2B
    P8_19 = 19,         // EHRPWM2A
    P8_34 = 34,         // EHRPWM1B
    P8_36 = 36,         // EHRPWM1A
    P8_45 = 45,         // EHRPWM2A
    P8_46 = 46,         // EHRPWM2B
    P9_14 = 14,         // EHRPWM1A
    P9_16 = 16,         // EHRPWM1B
    P9_21 = 21,         // EHRPWM0B
    P9_22 = 22,         // EHRPWM0A
    P9_28 = 28,         // ECAPPWM2
    P9_29 = 29,         // EHRPWM0B
    P9_31 = 31,         // EHRPWM0A
    P9_42 = 42          // ECAPPWM0
    
} PWM_PIN;

/*****************************************************************************/
// pwmEnable:
//	This function enable the cape to allow for PWM of different pins from
//  above. This function needs to be called first before enabling a pin.
//
//	return:
//		CETYPE value
//
/*****************************************************************************/
int pwmEnable(void);

/*****************************************************************************/
// pwmPINSelEnable:
//	This function enable the selected pin from above to be set as PWM. The
//  PWM cape needs to be activated first before enabling a pin. Therefore,
//  if the pwm_cape has not been enabled it will be enabled first before a pin
//  is enabled.
//
//	return:
//		CETYPE value
//
/*****************************************************************************/
int pwmPINSelEnable(PWM_PIN _PWM_PIN);

/*****************************************************************************/
// pwmDisable:
//	This function will remove the PWM cape from slots. It will make sure all
//  the other PWM Pin capes have been removed before removing itself
//
//	return:
//		CETYPE value
//
//  **At this point if disable is used it will lock up the slots**
//
/*****************************************************************************/
int pwmDisable(void);

/*****************************************************************************/
// pwmPINSelDisable:
//	This function will remove the PWM PIN cape from slots. It will only remove
//  the specific one that is sent
//
//	return:
//		CETYPE value
//
/*****************************************************************************/
int pwmPINSelDisable(PWM_PIN _PWM_PIN);


/*****************************************************************************/
// pwmPeriod:
//	This function will set the period for the PWM. The Desired PWM will
//  need to be enabled first using pwmEnable()
//
//  input:
//      pin      = desire PWM pin to adjust the period
//      period   = desired pwm period given in nanoseconds
//
//      i.e. pwmPeriod(23, 20000000);
//          This will set the P8_13 Pin's PWM with a period of .02 seconds
//
//	return:
//		CETYPE value
//
//  **At this point if disable is used it will lock up the slots**
//
/*****************************************************************************/
int pwmPeriod(PWM_PIN _PWM_PIN, int period);


/*****************************************************************************/
// pwmWriteDutyCycle:
//	This function will set the duty cycle for the PWM. The Desired PWM will
//  need to be enabled first using pwmEnable() and set a period or it will
//  use whatever was currently set on the period
//
//  input:
//      pin      = desire PWM pin to adjust the dutycyle
//      dutycyle = % between 0 and 100
//
//	return:
//		CETYPE value
//
/*****************************************************************************/
int pwmWriteDutyCycle(PWM_PIN _PWM_PIN, int dutyCyle);

#endif
