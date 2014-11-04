#ifndef __ADXL345_H
#define __ADXL345_H

int getDeviceID(int busSelect, int accelAddress);
void initADXL345(int busSelect, int accelAddress);
void getAccelData(int busSelect, int accelAddress, int *xAccel, int *yAccel, int *zAccel);

#endif 
