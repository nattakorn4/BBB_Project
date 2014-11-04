/*****************************************************************************/
//
//  JB_ADC.h
//
// Author: Josh Blakely
// Company: Robotic Elephant
// Revision: 0.0.1
// Date: 7/2/2013
//
// Purpose:
//  This header/source files allows the user to enable, disable and retrieve
//  information from the BeagleBone Black.
//
//  **At this point if disable is used it will lock up the slots**
//
/*****************************************************************************/
//
// Revision History:
//  0.0.1:  7/2/2013
//      - Initial Release
//
/*****************************************************************************/

#ifndef _JB_ADC_h
#define _JB_ADC_h

typedef enum _ADC_PIN
{
    P9_39 = 0,      // AIN0
    P9_40,          // AIN1
    P9_37,          // AIN2
    P9_38,          // AIN3
    P9_33,          // AIN4
    P9_36,          // AIN5
    P9_35           // AIN6
    
} ADC_PIN;

/*****************************************************************************/
// enableADC:
//	This function will enable the bone-cape-iio cape in order that the pin
//  can be read from as an ADC pin
//
//	return:
//		CETYPE value (can be found in Hdr.h)
//
/*****************************************************************************/
int enableADC(void);

/*****************************************************************************/
// disableADC:
//	This function will unexport/remove the cape from the slots.
//
//	return:
//		CETYPE value (can be found in Hdr.h)
//
//  **At this point if disable is used it will lock up the slots**
//
/*****************************************************************************/
int disableADC(void);

/*****************************************************************************/
// readADCPIN:
//	This function will will read the current value of the exported pin.
//  It uses a pointer to the value that is being retrieved.
//
//	return:
//		CETYPE value (can be found in Hdr.h)
//
/*****************************************************************************/
int readADCPIN(ADC_PIN _ADC_PIN, float *value);

#endif
