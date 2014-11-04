//
//  JBUtility.c
//  
//
//  Created by Joshua Blakely on 5/26/13.
//
//

#include <stdio.h>
#include <unistd.h>

#include "JBUtility.h"

/**************************************************************************************/
// DelayMS:
//	This function will create a delay for the requested amount of milliseconds
/**************************************************************************************/
void DelayMS(int milliseconds)
{
    int requestTime = 0;
    requestTime = milliseconds * 1000;
    usleep(requestTime);
}

/**************************************************************************************/
// DelayUS:
//	This function will create a delay for the requested amount of microseconds
/**************************************************************************************/
void DelayUS(int microseconds)
{
    usleep(microseconds);
}
