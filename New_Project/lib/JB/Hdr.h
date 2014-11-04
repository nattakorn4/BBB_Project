/*****************************************************************************/
//
//  Hdr.h
//
// Author: Josh Blakely
// Company: Robotic Elephant
// Revision: 0.0.1
// Date: 7/2/2013
//
// Purpose:
//  This file is to bring all the common macros and reference information/
//  helpful hints to a single file that can be easily added to a project or
//  referenced.
//
/*****************************************************************************/
//
// Revision History:
//  0.0.1:  7/2/2013
//      - Initial Release
//
/*****************************************************************************/

#ifndef _Hdr_h
#define _Hdr_h

// Uncomment if you need printf statements
//#define DEBUG

// Typical values that can be returned from each of the functions below

typedef enum _CETYPE {
    CE_GOOD = 0, // 0
    CE_FAIL_EXPORT, // 1
    CE_FAIL_UNEXPORT, // 2
    CE_FAIL_DIREC, // 3
    CE_INCORRECT_DIREC, // 4
    CE_FAIL_VALUE, // 5
    CE_INCORRECT_VALUE, // 6
    CE_FAIL_PWM, // 7
    CE_FAIL_PWM_EXPORT, // 8
    CE_BAD_PWM_PIN, // 9
    CE_FAIL_PWM_PERIOD, // 10
    CE_FAIL_PWM_READ_PERIOD, // 11
    CE_FAIL_PWM_DUTYCYCLE, // 12
    CE_FAIL_SLOTS, // 13
    CE_FAIL_CAPE_LOADED, // 14
    CE_FAIL_ADC_PIN, // 15
    CE_INCORRECT_SELECTION, // 16
    CE_FAIL_ACCESS, // 17
    CE_FAIL_READ, // 18
    CE_FAIL_WRITE // 19

} CETYPE;

#define IN		"in"
#define OUT		"out"
#define	LOW		0
#define HIGH	!LOW
#define SLOTS       "/sys/devices/bone_capemgr.9/slots"

#endif
