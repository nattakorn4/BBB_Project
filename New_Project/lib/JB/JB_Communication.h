/*****************************************************************************/
//
// JB_Communication.h
//
// Author: Josh Blakely
// Company: Robotic Elephant
// Revision: 0.0.2
// Date: 7/2/2013
//
// Purpose:
// This program is designed to control the GPIO using opening and closing of
// files through fopen(). The maninuplation of the files are for general GPIO
// and PWM.
//
/*****************************************************************************/
//
// Revision History:
//  0.0.1:  7/2/2013
//      - Initial Release with GPIO out only
//	0.0.2: 12/13/2013
//		- Added initializing EEPROM
//	0.0.3: 12/15/2013
//		- Added I2C Function to be able to connect to any
//
/*****************************************************************************/

#ifndef _JB_Communication_h
#define _JB_Communication_h

#define LC24C64		"24c64"
#define LC24C256	"24c256"

// I2C EEPROM functions
int initI2CEEPROM(int busSelect, unsigned char address, char *typeEEPROM);
int writeI2CEEPROM(int busSelect, unsigned char address, long int location, unsigned char *saveString, int strLength);
int readI2CEEPROM(int busSelect, unsigned char address, long int location, unsigned char *saveString, int strLength);

// I2C Functions
int MasterI2CWrite(int busSelect, int address, int location, int *saveString, int strLength);
int MasterI2CRead(int busSelect, int address, int location, int *saveString, int strLength);

#endif
