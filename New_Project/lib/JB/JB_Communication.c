/*****************************************************************************/
//
// JB_Communication.c
//
// Author: Josh Blakely
// Company: Robotic Elephant
// Revision: SEE JB_Communication.h
// Date: XX/XX/XXXX
//
// Purpose:
// This program is designed to control the GPIO using opening and closing of
// files through fopen(). The maninuplation of the files are for general GPIO
// and PWM.
//
/*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <linux/i2c.h>
//#include <string.h>
//#include <unistd.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <fcntl.h>

#include "JB_Communication.h"
#include "Hdr.h"

int initI2C(int busSelect, int address, int *file);
static inline __s32 i2c_smbus_access(int file, char read_write, __u8 command, int size, union i2c_smbus_data *data);

/****************************************************************************/
//
// EEPROM I2C
//

/****************************************************************************/
int initI2CEEPROM(int busSelect, unsigned char address, char *typeEEPROM)
{
    if (busSelect != 1 && busSelect != 0)
    {
        printf("Incorrect BUS selected\n");
        return CE_INCORRECT_SELECTION;
    }
    char str[60];
    sprintf(str, "echo %s 0x%x > /sys/bus/i2c/devices/i2c-%i/new_device", typeEEPROM, address, busSelect);
    system(str);
    return CE_GOOD;
}

int writeI2CEEPROM(int busSelect, unsigned char address, long int location, unsigned char *saveString, int strLength)
{
    FILE *fp;
    int count;
    char str[50];

    if (busSelect == 1 || busSelect == 0)
    {
        sprintf(str, "/sys/bus/i2c/devices/%i-00%x/eeprom", busSelect, address);

        if ((fp = fopen(str, "rb+")) == NULL)
        {
            printf("Failed to open the new_device to export\n");
            return CE_FAIL_EXPORT;
        }

        fseek(fp, location, SEEK_SET); // Seeks from the beginning of the file until the desired location.

        for (count = 0; count < strLength; count++)
        {
            fputc(*saveString++, fp); // Writes a character to the I2C bus
        }
        fclose(fp); // Closes the FIle pointer

        return CE_GOOD;
    }

    return CE_INCORRECT_SELECTION;
}

int readI2CEEPROM(int busSelect, unsigned char address, long int location, unsigned char *saveString, int strLength)
{
    FILE *fp;
    int count;
    char str[50];

    if (busSelect == 1 || busSelect == 0)
    {
        sprintf(str, "/sys/bus/i2c/devices/%i-00%x/eeprom", busSelect, address);

        if ((fp = fopen(str, "rb+")) == NULL)
        {
            printf("Failed to open the new_device to export\n");
            return CE_FAIL_EXPORT;
        }

        fseek(fp, location, SEEK_SET); // Seeks from the beginning of the file until the desired location.

        for (count = 0; count < strLength; count++)
        {
            *saveString++ = fgetc(fp); // Writes a character to the I2C bus
        }
        fclose(fp); // Closes the FIle pointer

        return CE_GOOD;
    }

    return CE_INCORRECT_SELECTION;
}

/***********************************************************************************************/
//
// I2C Main
//

/***********************************************************************************************/
int initI2C(int busSelect, int address, int *file)
{
    char filename[12];

    sprintf(filename, "/dev/i2c-%i", busSelect);
    if ((*file = open(filename, O_RDWR)) < 0)
    {
        printf("Failed to open the bus.");
        return CE_FAIL_EXPORT;
    }

    if (ioctl(*file, I2C_SLAVE, address) < 0)
    {
        printf("Failed to acquire bus access and/or talk to slave.\n");
        close(*file);
        return CE_FAIL_ACCESS;
    }

    return CE_GOOD;
}

int MasterI2CWrite(int busSelect, int address, int location, int *saveString, int strLength)
{
    int file, errorValue, temp;
    errorValue = initI2C(busSelect, address, &file);
    if (errorValue != CE_GOOD)
    {
        return errorValue;
    }

    union i2c_smbus_data data;
    
    if (strLength > 32)
    {
        strLength = 32;
    }
    for (temp = 1; temp <= strLength; temp++)
    {
        data.block[temp] = saveString[temp - 1];
    }
    data.block[0] = strLength;
    
    i2c_smbus_access(file, I2C_SMBUS_WRITE, location, I2C_SMBUS_I2C_BLOCK_BROKEN, &data);

    return CE_GOOD;
}

int MasterI2CRead(int busSelect, int address, int location, int *saveString, int strLength)
{
    int file, errorValue, temp;
    errorValue = initI2C(busSelect, address, &file);
    if (errorValue != CE_GOOD)
    {
        return errorValue;
    }

    union i2c_smbus_data data;

    if (strLength > 32)
    {
        strLength = 32;
    }
    data.block[0] = strLength;

    if (i2c_smbus_access(file, I2C_SMBUS_READ, location, strLength == 32 ? I2C_SMBUS_I2C_BLOCK_BROKEN : I2C_SMBUS_I2C_BLOCK_DATA, &data))
    {
        return CE_FAIL_ACCESS;
    } else
    {
        for (temp = 1; temp <= data.block[0]; temp++)
        {
            saveString[temp - 1] = data.block[temp];
        }
        //        return data.block[0];
    }

    close(file);
    return CE_GOOD;
}

static inline __s32 i2c_smbus_access(int file, char read_write, __u8 command, int size, union i2c_smbus_data *data)
{
    struct i2c_smbus_ioctl_data args;

    args.read_write = read_write;
    args.command = command;
    args.size = size;
    args.data = data;
    return ioctl(file, I2C_SMBUS, &args);
}
