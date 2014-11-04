/*****************************************************************************/
//
// JB_GPIO.c
//
// Author: Josh Blakely
// Company: Robotic Elephant
// Revision: SEE JB_GPIO.h for Current Revision
// Date: 5/13/2013
//
// Purpose:
// This program is designed to control the GPIO using opening and closing of
// files through fopen(). The maninuplation of the files are for general GPIO.
//
/*****************************************************************************/

#include <stdio.h>
#include <string.h>

#include "JB_GPIO.h"
#include "Hdr.h"

#define PIN_EXPORT          "/sys/class/gpio/export"
#define PIN_UNEXPORT        "/sys/class/gpio/unexport"

/**************************************************************************************/
// gpioExDirection:
//	This function will export the pin for usage as an output or input

/**************************************************************************************/
int gpioExDirection(int pin, int direc)
{
    FILE *fp;
    char set_value[4];
    char pinDirectory[35];

    if ((fp = fopen(PIN_EXPORT, "ab")) == NULL) // Opens the export file
    {
#ifdef DEBUG
        printf("Cannot open export file\n");
#endif
        return CE_FAIL_EXPORT;
    }
    rewind(fp); //Set the pointer to the beginning of the file
    sprintf(set_value, "%i", pin);
    fwrite(&set_value, sizeof (char), sizeof (set_value) / sizeof (set_value[0]), fp); //Writes export to selected PIN
    fclose(fp); // Closes the file. Once closed then it will be executed, therefore, must close.

    sprintf(pinDirectory, "/sys/class/gpio/gpio%i/direction", pin);

    if ((fp = fopen(pinDirectory, "rb+")) == NULL) // Opens direction file
    {
#ifdef DEBUG
        printf("Cannot open direction file\n");
#endif
        return CE_FAIL_DIREC;
    }
    rewind(fp); //Sets the pointer to the beginning of the file


    switch (direc)
    {
    case gpioOut:
        sprintf(set_value, OUT);
        break;
    case gpioIn:
        sprintf(set_value, IN);
        break;
    default:
#ifdef DEBUG
        printf("An invalid direction for the pin has been selected\n");
#endif
        fclose(fp); // Need to close the file before exiting otherwise it will hang
        return CE_INCORRECT_DIREC;
        break;
    }

    fwrite(&set_value, sizeof (char), sizeof (set_value) / sizeof (set_value[0]), fp);
    fclose(fp);

    return CE_GOOD;

}

/**************************************************************************************/
// closeGPIO:
//	This function will unexport the pin. It first sets the pin to input. Once it has
//	been set to input, it will unexport the pin

/**************************************************************************************/
int closeGPIO(int pin)
{
    FILE *fp;
    char set_value[4];
    char pinDirectory[35];
    
    sprintf(pinDirectory, "/sys/class/gpio/gpio%i/direction", pin);

    if ((fp = fopen(pinDirectory, "rb+")) == NULL)
    {
#ifdef DEBUG
        printf("Cannot open direction file\n");
#endif
        return 0;
    }
    rewind(fp); //Sets the pointer to the beginning of the file

    sprintf(set_value, IN);
    fwrite(&set_value, sizeof (char), sizeof (set_value) / sizeof (set_value[0]), fp);
    fclose(fp); //Close the file pointer

    if ((fp = fopen(PIN_UNEXPORT, "ab")) == NULL)
    {
#ifdef DEBUG
        printf("Cannot open export file\n");
#endif
        return CE_FAIL_UNEXPORT;
    }
    rewind(fp); //Set the pointer to the beginning of the file
    sprintf(set_value, "%i", pin);
    fwrite(&set_value, sizeof (char), sizeof (set_value) / sizeof (set_value[0]), fp);
    fclose(fp);

    return 1;
}

/**************************************************************************************/
// gpioReadDigPin:
//	This will read the GPIO pin as either a high or low. Need to run
//  gpioExDirection() and set direc to gpioIn before using this function

/**************************************************************************************/
int gpioReadDigPin(int pin, int *value)
{
    FILE *fp;
    //	char set_value[4];
    char pinDirectory[30];
    
    sprintf(pinDirectory, "/sys/class/gpio/gpio%i/value", pin);
    
    if ((fp = fopen(pinDirectory, "rb+")) == NULL)
    {
#ifdef DEBUG
        printf("Cannot open value file\n");
#endif
        return CE_FAIL_VALUE;
    }

    // Sets the position to an offset of 0 from the beginning (SEEK_SET = position is relative to beginning of file)
    fseek(fp, 0, SEEK_SET);

    // When using fscanf the value must be a pointer
    fscanf(fp, "%i", value);

    fclose(fp);

    return CE_GOOD;
}

/**************************************************************************************/
// gpioDigOutput:
//	This will write to the GPIO output pin either a high or low. Need to run
//  gpioExDirection() and set direc to gpioOut before using this function

/**************************************************************************************/
int gpioDigOutput(int pin, int HighLow)
{
    FILE *fp;
    char set_value[4];
    char pinDirectory[30];

    sprintf(pinDirectory, "/sys/class/gpio/gpio%i/value",pin);
    
    if ((fp = fopen(pinDirectory, "rb+")) == NULL)
    {
#ifdef DEBUG
        printf("Cannot open value file\n");
#endif
        return CE_FAIL_VALUE;
    }
    rewind(fp); //Sets the pointer to the beginning of the file

    switch (HighLow)
    {
    case HIGH:
        sprintf(set_value, "%i", HIGH);
        break;
    case LOW:
        sprintf(set_value, "%i", LOW);
        break;
    default:
#ifdef DEBUG
        printf("An invalid value for the pin has been selected\n");
#endif
        fclose(fp); // Need to close the file before exiting otherwise it will hang
        return CE_INCORRECT_VALUE;
        break;
    }

    fwrite(&set_value, sizeof (char), sizeof (set_value) / sizeof (set_value[0]), fp);
    fclose(fp); //Close the file pointer
    return CE_GOOD;
}
