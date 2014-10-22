#ifndef GPIO_CONFIG_H
#define GPIO_CONFIG_H

#include "SimpleGPIO.h"

class GPIO_Config
{
public:
    GPIO_Config();
    void UnGPIO_Config();
    int GPIO_Getvalue(int pin);
    void GPIO_Setvalue(int pin,int value);
    void GPIO_Initial();

private:
    int gpio_output[10];
    int gpio_input[10];


};

#endif // GPIO_CONFIG_H
