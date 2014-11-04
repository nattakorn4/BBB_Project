/*****************************************************************************/
//
//  JB_PWM.c
//
// Author: Josh Blakely
// Company: Robotic Elephant
// Revision: SEE JB_PWM.h
// Date: 7/4/2013
//
// Purpose:
// This program is designed to control the PWM using opening and closing of
// files through fopen().
//
/*****************************************************************************/

#include <stdio.h>
#include <string.h>
#include <dirent.h>

#include "JB_PWM.h"
#include "Hdr.h"

#define PWM_MODULE      0
#define AM33XX_PWM      "am33xx_pwm"

// Private Functions
int fileSearch(int searchSel);
int desiredBuildPath(const char *partialPath, const char *searchItem, char *fullPath);

/*****************************************************************************/
// pwmEnable:
//	This function enable the cape to allow for PWM of different pins from
//  above. This function needs to be called first before enabling a pin.
/*****************************************************************************/
int pwmEnable(void)
{
    FILE *fp;
	char set_value[15];
    
    if(fileSearch(PWM_MODULE))
    {
        if((fp = fopen(SLOTS, "rb+")) == NULL)
        {
            #ifdef DEBUG
            printf("Failed to export the am33xx pwm\n");
            #endif
            return CE_FAIL_PWM;
        }
        rewind(fp);
        sprintf(set_value, "%s", AM33XX_PWM);
        fwrite(&set_value, sizeof(char), sizeof(set_value)/sizeof(set_value[0]), fp);
        fclose(fp);
    } else
    {
        return CE_FAIL_PWM;
    }
    
    return CE_GOOD;
}

/*****************************************************************************/
// pwmDisable:
//	This function will remove the PWM cape from slots. It will make sure all
//  the other PWM Pin capes have been removed before removing itself
/*****************************************************************************/
int pwmDisable(void)
{
    FILE *fp;
    char line[256];
    char *slot_line;
    
    if (!fileSearch(PWM_MODULE))
    {
        // Checks to see if one of the PWM PIN Capes are active and disables it
        pwmPINSelDisable(P8_13);
        pwmPINSelDisable(P8_19);
        pwmPINSelDisable(P8_34);
        pwmPINSelDisable(P8_36);
        pwmPINSelDisable(P8_45);
        pwmPINSelDisable(P8_46);
        pwmPINSelDisable(P9_14);
        pwmPINSelDisable(P9_16);
        pwmPINSelDisable(P9_21);
        pwmPINSelDisable(P9_22);
        pwmPINSelDisable(P9_28);
        pwmPINSelDisable(P9_29);
        pwmPINSelDisable(P9_31);
        pwmPINSelDisable(P9_42);
         
        // Open SLOTS so the cape can be removed
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
            if (strstr(line, AM33XX_PWM))
            {
                slot_line = strtok(line, ":");
                
                // Remove the leading space
                while (*slot_line == ' ')
                {
                    slot_line++;
                }
                
                fprintf(fp, "-%s", slot_line);
                fclose(fp);
                
                return CE_GOOD;
            }
        }
        
        // File wasn't loaded therefore we are going to close
        fclose(fp);
        
        return CE_GOOD;
    } // End of fileSearch() if
    
    return CE_GOOD; // The cape wasn't load, so just close w/everything working correctly
}

/*****************************************************************************/
// pwmPINSelDisable:
//	This function will remove the PWM PIN cape from slots. It will only remove
//  the specific one that is sent
/*****************************************************************************/
int pwmPINSelDisable(PWM_PIN _PWM_PIN)
{
    FILE *fp;
    char line[256];
    char desiredReference[15];
    char *slot_line;
    
    if (!fileSearch(_PWM_PIN))
    {
        if ((fp = fopen(SLOTS, "r+")) == NULL)
        {
            #ifdef DEBUG
            printf("Cannot open file\n");
            #endif
            return CE_FAIL_SLOTS;
        }
        
        if (_PWM_PIN == P8_13 || _PWM_PIN == P8_19 || _PWM_PIN == P8_34 || _PWM_PIN == P8_36 || _PWM_PIN == P8_45 || _PWM_PIN == P8_46)
        {
            sprintf(desiredReference, "%s%i", "bone_pwm_P8_", _PWM_PIN);
            
        }
        else if (_PWM_PIN == P9_14 || _PWM_PIN == P9_16 || _PWM_PIN == P9_21 || _PWM_PIN == P9_22 || _PWM_PIN == P9_28 || _PWM_PIN == P9_29 || _PWM_PIN == P9_31 || _PWM_PIN == P9_42)
        {
            sprintf(desiredReference, "%s%i", "bone_pwm_P9_", _PWM_PIN);
        }
        
        while (fgets(line, sizeof(line), fp))
        {
            // Find the loaded Cape, so we can remove it
            if (strstr(line, desiredReference))
            {                
                slot_line = strtok(line, ":");
                
                // Remove the leading space
                while (*slot_line == ' ')
                {
                    slot_line++;
                }
                
                #ifdef DEBUG
                printf("Removing and closing PWM PIN Cape: %i\n", _PWM_PIN);
                #endif
                
                fprintf(fp, "-%s", slot_line);
                fclose(fp);
                
                #ifdef DEBUG
                printf("Closed PWM PIN %i file\n", _PWM_PIN);
                #endif
                
                return CE_GOOD;
            }
        } // End of While
        
        // PIN's Cape wasn't loaded therefore closing and return success
        fclose(fp);
        
    } // End of !fileSearch(_PWM_PIN)
    
    return CE_GOOD; // Cape not active return everything worked correctly
}

/*****************************************************************************/
// pwmPINSelEnable:
//	This function enable the selected pin from above to be set as PWM. The
//  PWM cape needs to be activated first before enabling a pin. Therefore,
//  if the pwm_cape has not been enabled it will be enabled first before a pin
//  is enabled.
/*****************************************************************************/
int pwmPINSelEnable(PWM_PIN _PWM_PIN)
{
    FILE *fp;
	char set_value[15];
    
    if(fileSearch(_PWM_PIN))
    {
        if ((fp = fopen(SLOTS,"rb+")) == NULL)
        {
            #ifdef DEBUG
            printf("Failed to open the SLOTS file\n");
            #endif
            return CE_FAIL_SLOTS;
        }
        
        if (_PWM_PIN == P8_13 || _PWM_PIN == P8_19 || _PWM_PIN == P8_34 || _PWM_PIN == P8_36 || _PWM_PIN == P8_45 || _PWM_PIN == P8_46)
        {
            sprintf(set_value, "%s%i", "bone_pwm_P8_", _PWM_PIN);
            
        }
        else if (_PWM_PIN == P9_14 || _PWM_PIN == P9_16 || _PWM_PIN == P9_21 || _PWM_PIN == P9_22 || _PWM_PIN == P9_28 || _PWM_PIN == P9_29 || _PWM_PIN == P9_31 || _PWM_PIN == P9_42)
        {
            sprintf(set_value, "%s%i", "bone_pwm_P9_", _PWM_PIN);
        }
        
        fwrite(&set_value, sizeof(char), sizeof(set_value)/sizeof(set_value[0]), fp);
        fclose(fp);
        
        return CE_GOOD;
    }
    
    return CE_GOOD;
}

/*****************************************************************************/
// pwmPeriod:
//	This function will set the period for the PWM. The Desired PWM will
//  need to be enabled first using pwmEnable()
/*****************************************************************************/
int pwmPeriod(PWM_PIN _PWM_PIN, int period)
{
    FILE *fp;
    char set_value[10];
    char pwmPINLocation[45];
    char desiredFullPath[40];
    char ocpDir[20];
    char searchString[15];
    
    desiredBuildPath("/sys/devices", "ocp", ocpDir);
	
    if (_PWM_PIN == P8_13 || _PWM_PIN == P8_19 || _PWM_PIN == P8_34 || _PWM_PIN == P8_36 || _PWM_PIN == P8_45 || _PWM_PIN == P8_46)
    {
        sprintf(searchString, "pwm_test_P8_%i", _PWM_PIN);
        desiredBuildPath(ocpDir, searchString, desiredFullPath);
        sprintf(pwmPINLocation, "%s/period", desiredFullPath);
        #ifdef DEBUG
        printf("pwmPINLocation: %s\n", pwmPINLocation);
        #endif
        
    }
    else if (_PWM_PIN == P9_14 || _PWM_PIN == P9_16 || _PWM_PIN == P9_21 || _PWM_PIN == P9_22 || _PWM_PIN == P9_28 || _PWM_PIN == P9_29 || _PWM_PIN == P9_31 || _PWM_PIN == P9_42)
    {
        sprintf(searchString, "pwm_test_P9_%i", _PWM_PIN);
        desiredBuildPath(ocpDir, searchString, desiredFullPath);
        sprintf(pwmPINLocation, "%s/period", desiredFullPath);
        #ifdef DEBUG
        printf("pwmPINLocation: %s\n", pwmPINLocation);
        #endif
    }

    if((fp = fopen(pwmPINLocation, "rb+")) == NULL)
    {
        #ifdef DEBUG
        printf("Problem with Period\n");
        #endif
        return CE_FAIL_PWM_PERIOD;
    }
    
    rewind(fp);		//Set the pointer to the beginning of the file
    sprintf(set_value, "%i", period);
    fwrite(&set_value, sizeof(char), sizeof(set_value)/sizeof(set_value[0]), fp);
    fclose(fp);
    return CE_GOOD;
}

/*****************************************************************************/
// pwmWriteDutyCycle:
//	This function will set the duty cycle for the PWM. The Desired PWM will
//  need to be enabled first using pwmEnable() and set a period or it will
//  use whatever was currently set on the period
/*****************************************************************************/
int pwmWriteDutyCycle(PWM_PIN _PWM_PIN, int dutyCyle)
{
    FILE *fp;
    char set_value[10];
    char read_value[10];
    int periodValue;
    char pwmPINPeriod[45];
    char pwmPINDuty[43];
    char desiredFullPath[40];
    char ocpDir[20];
    char searchString[15];
    
    desiredBuildPath("/sys/devices", "ocp", ocpDir);
	
    if (_PWM_PIN == P8_13 || _PWM_PIN == P8_19 || _PWM_PIN == P8_34 || _PWM_PIN == P8_36 || _PWM_PIN == P8_45 || _PWM_PIN == P8_46)
    {
        sprintf(searchString, "pwm_test_P8_%i", _PWM_PIN);
        desiredBuildPath(ocpDir, searchString, desiredFullPath);
        sprintf(pwmPINPeriod, "%s/period", desiredFullPath);
        #ifdef DEBUG
        printf("pwmPINPeriod: %s\n", pwmPINPeriod);
        #endif
        
    }
    else if (_PWM_PIN == P9_14 || _PWM_PIN == P9_16 || _PWM_PIN == P9_21 || _PWM_PIN == P9_22 || _PWM_PIN == P9_28 || _PWM_PIN == P9_29 || _PWM_PIN == P9_31 || _PWM_PIN == P9_42)
    {
        sprintf(searchString, "pwm_test_P9_%i", _PWM_PIN);
        desiredBuildPath(ocpDir, searchString, desiredFullPath);
        sprintf(pwmPINPeriod, "%s/period", desiredFullPath);
        #ifdef DEBUG
        printf("pwmPINPeriod: %s\n", pwmPINPeriod);
        #endif
    }
    
    if((fp = fopen(pwmPINPeriod, "rb+")) == NULL)
    {
        #ifdef DEBUG
        printf("Problem with Period in Duty Cycle\n");
        #endif
        return CE_FAIL_PWM_PERIOD;
    }
    
    rewind(fp);
    fread(&read_value, sizeof(char), sizeof(read_value), fp);
    fclose(fp);
    sscanf(read_value, "%i", &periodValue);     // Converts a string into an int in this case
    #ifdef DEBUG
    printf("Period Value int: %i\n", periodValue);
    #endif
    
    periodValue *= (100 - dutyCyle);    // The BeagleBone Black is the inverse of what is expected
    periodValue /= 100;                 // Divide by 100; keeps from having to use floating point
    
    sprintf(pwmPINDuty, "%s/duty", desiredFullPath);
    #ifdef DEBUG
    printf("pwmPINDuty: %s\n", pwmPINDuty);
    #endif
    
    if((fp = fopen(pwmPINDuty, "rb+")) == NULL)
    {
        #ifdef DEBUG
        printf("Problem with Duty Cycle\n");
        #endif
        return CE_FAIL_PWM_DUTYCYCLE;
    }

    rewind(fp);		//Set the pointer to the beginning of the file
    sprintf(set_value, "%i", periodValue);
    fwrite(&set_value, sizeof(char), sizeof(set_value)/sizeof(set_value[0]), fp);
    fclose(fp);
    
    return CE_GOOD;
}

/*****************************************************************************/
// fileSearch:
//      This function searches the through the slots looking for whether
//      the desired ouput has been already inserted.
//
// return:
//      0   = Success
//      1   = Not found
/*****************************************************************************/
int fileSearch(int searchSel)
{
    FILE *fp;
    char desiredReference[15];
	char line[256];
    
    // Checks to see if the PWM Cape or PWM PIN Cape currently exists
    if(searchSel == PWM_MODULE)
    {
        sprintf(desiredReference, "%s", AM33XX_PWM);
    }
    else if (searchSel == P8_13 || searchSel == P8_19 || searchSel == P8_34 || searchSel == P8_36 || searchSel == P8_45 || searchSel == P8_46)
    {
        sprintf(desiredReference, "%s%i", "bone_pwm_P8_", searchSel);
        
    }
    else if (searchSel == P9_14 || searchSel == P9_16 || searchSel == P9_21 || searchSel == P9_22 || searchSel == P9_28 || searchSel == P9_29 || searchSel == P9_31 || searchSel == P9_42)
    {
        sprintf(desiredReference, "%s%i", "bone_pwm_P9_", searchSel);
    }
    else
    {
        return CE_INCORRECT_VALUE;
    }
    
    // Tries to open the SLOTS in read mode to see if the required file exists
    if((fp = fopen(SLOTS, "r")) == NULL) {
        return CE_FAIL_SLOTS;
    }
    
    // Search for the specific/desired value in the
    while(fgets(line, sizeof(line), fp))
    {
		if(strstr(line, desiredReference))
        {
            #ifdef DEBUG
			printf("A match found for: %i\n", searchSel);
            #endif
            fclose(fp);
            return CE_GOOD;
		}
	}
    
    fclose(fp);     // Closes the file
    
    return 1;       // Returns a failure
}

/*****************************************************************************/
// desiredBuildPath:
//      This function searches for directories to find the correct one
//
/*****************************************************************************/
int desiredBuildPath(const char *partialPath, const char *searchItem, char *fullPath)
{
    DIR *dp;    //dp = directory path
    struct dirent *ep;
    
    dp = opendir(partialPath);
    if (dp != NULL)
    {
        // readdir() returns a pointer to a structure representing the direction
        // entry at the current position in the stream
        while ((ep = readdir(dp)))   
        {
            if(strstr(ep->d_name, searchItem))  // ep->d_name is a pointer inside the struct
            {
                sprintf(fullPath, "%s/%s",partialPath, ep->d_name);
                (void) closedir(dp);
                return CE_GOOD;
            }
        }
        
        (void) closedir(dp);
        
    }
    
    return CE_FAIL_PWM_EXPORT;
}


