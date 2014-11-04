/*****************************************************************************/
//
//  JB_ADC.c
//
// Author: Josh Blakely
// Company: Robotic Elephant
// Revision: SEE JB_ADC.h
// Date: 7/2/2013
//
// Purpose:
//  This header/source files allows the user to enable, disable and retrieve
//  information from the BeagleBone Black.
//
/*****************************************************************************/

#include <stdio.h>
#include <string.h>

#include "JB_ADC.h"
#include "Hdr.h"

#define ADC_NAME        "cape-bone-iio"
#define ADC_BASE_PIN    "/sys/devices/ocp.2/helper.11/AIN"

/*****************************************************************************/
// enableADC:
//	This function will enable the ADC by writing to slots the cape-bone-iio
//  cape
/*****************************************************************************/
int enableADC(void)
{
    FILE *fp;
    char line[256];
    
    // Attempt to open the slots
    if ((fp = fopen(SLOTS, "r+")) == NULL)
    {
        #ifdef DEBUG
		printf("Cannot open file\n");
        #endif
        return CE_FAIL_SLOTS;
    }
    
    // Check to see if the file is already loaded
    while (fgets(line, sizeof(line), fp))
    {
        // The device is already loaded return CE_FAIL_CAPE_LOADED
        if (strstr(line, ADC_NAME))
        {
            fclose(fp);
            return CE_FAIL_CAPE_LOADED;
        }
    }
    
    // The device isn't currently loaded, therefore, lets load it and return
    fprintf(fp, ADC_NAME);
    fclose(fp);
    
    return CE_GOOD;
}

/*****************************************************************************/
// disableADC:
//	This function will 
/*****************************************************************************/
int disableADC(void)
{
    FILE *fp;
    char line[256];
    char *slot_line;
    
    if ((fp = fopen(SLOTS, "r+")) == NULL)
    {
        #ifdef DEBUG
		printf("Cannot open file\n");
        #endif
        return CE_FAIL_SLOTS;
    }
    
    while (fgets(line, sizeof(line), fp))
    {
        // Find the loaded Cape, so we can remove it
        if (strstr(line, ADC_NAME))
        {
            slot_line = strtok(line, ":");
            
            // Remove the leading space
            while (*slot_line == ' ')
            {
                slot_line++;
            }
            
            #ifdef DEBUG
            printf("fprintf printing: %s\n", slot_line);
            #endif
            
            fprintf(fp, "-%s", slot_line);
            fclose(fp);
            
            return CE_GOOD;
        }
    }
    
    // File wasn't loaded therefore we are going to close
    fclose(fp);
    
    return CE_GOOD;
}

/*****************************************************************************/
// readADCPIN:
//	This function will read the value of the selected ADC pin
/*****************************************************************************/
int readADCPIN(ADC_PIN _ADC_PIN, float *value)
{
    FILE *fp;
    char ain_path[40];
    snprintf(ain_path, sizeof(ain_path), "%s%d", ADC_BASE_PIN, _ADC_PIN);
    
    // Open the specific ain pin in order to read the value
    if ((fp = fopen(ain_path, "r")) == NULL)
    {
        #ifdef DEBUG
		printf("Cannot open file %s%d\n", ADC_BASE_PIN, _ADC_PIN);
        #endif
    }
    
    // Sets the position to an offset of 0 from the beginning (SEEK_SET = position is relative to beginning of file)
    fseek(fp, 0, SEEK_SET);
    
    // When using fscanf the value must be a pointer
    fscanf(fp, "%f", value);
    
    fclose(fp);
    
    return CE_GOOD;
}
