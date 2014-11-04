#include "ADXL345.h" 
#include "JB_Communication.h"
#include "JBUtility.h"

int getDeviceID(int busSelect, int accelAddress)
{
    int value = 0;
    MasterI2CRead(busSelect, accelAddress, 0x00, &value, 1);
    return value;
}

void initADXL345(int busSelect, int accelAddress)
{
    int BW_RATE = 0x0B;
    int DATA_FORM = 0x0A;
    int PWR_CTRL = 0x08;

    MasterI2CWrite(busSelect, accelAddress, 0x2C, &BW_RATE, 1);       //Sets the BW_Rate
    DelayMS(10);
    MasterI2CWrite(busSelect, accelAddress, 0x31, &DATA_FORM, 1);     //Sets the data format
    DelayMS(10);
//    MasterI2CWrite(busSelect, ADXL345_ADD, 0x2D, 0x00, 1);           //0x2D is the power control register
//    DelayMS(10);
    MasterI2CWrite(busSelect, accelAddress, 0x2D, &PWR_CTRL, 1);      //Sets the power and sets to measurement mode
    DelayMS(10);
}

void getAccelData(int busSelect, int accelAddress, int *xAccel, int *yAccel, int *zAccel)
{
    int str[6];
    MasterI2CRead(busSelect, ADXL345_ADD, 0x32, str, sizeof(str)/sizeof(str[0]));

    *xAccel = ((str[1] & 0b00001111) << 8) | (str[0] & 0b00001111);
    *yAccel = ((str[3] & 0b00001111) << 8) | (str[2] & 0b00001111);
    *zAccel = ((str[5] & 0b00001111) << 8) | (str[4] & 0b00001111);
    // Scale factor is calculated by using the range of the accel divided by
    //the bit resolution. If using +/-4g @ 10bit resolutions (2^10), then SCALE = 8g/1024
}