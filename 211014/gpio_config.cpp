#include "gpio_config.h"

GPIO_Config::GPIO_Config()
{
    gpio_input[0] = 67;
    gpio_input[1] = 68;
    gpio_input[2] = 44;
    gpio_input[3] = 26;
    gpio_input[4] = 46;
    gpio_input[5] = 22;
    gpio_input[6] = 27;
    gpio_input[7] = 47;
    gpio_input[8] = 23;
    gpio_input[9] = 45;
    gpio_output[0] = 2;
    gpio_output[1] = 50;
    gpio_output[2] = 14;
    gpio_output[3] = 3;
    gpio_output[4] = 48;
    gpio_output[5] = 15;
    gpio_output[6] = 49;
    gpio_output[7] = 60;
    gpio_output[8] = 51;
    gpio_output[9] = 31;



}
void GPIO_Config::UnGPIO_Config(){
    gpio_unexport(gpio_input[0]);
    gpio_unexport(gpio_input[1]);
    gpio_unexport(gpio_input[2]);
    gpio_unexport(gpio_input[3]);
    gpio_unexport(gpio_input[4]);
    gpio_unexport(gpio_input[5]);
    gpio_unexport(gpio_input[6]);
    gpio_unexport(gpio_input[7]);
    gpio_unexport(gpio_input[8]);
    gpio_unexport(gpio_input[9]);
    gpio_unexport(gpio_output[0]);
    gpio_unexport(gpio_output[1]);
    gpio_unexport(gpio_output[2]);
    gpio_unexport(gpio_output[3]);
    gpio_unexport(gpio_output[4]);
    gpio_unexport(gpio_output[5]);
    gpio_unexport(gpio_output[6]);
    gpio_unexport(gpio_output[7]);
    gpio_unexport(gpio_output[8]);
    gpio_unexport(gpio_output[9]);
}
int GPIO_Config::GPIO_Getvalue(int pin){
    return gpio_get_value(gpio_input[pin-1]);
}
void GPIO_Config::GPIO_Setvalue(int pin,int value){
    if(value==1){
        gpio_set_value(gpio_output[pin-1],HIGH);
    }else{
        gpio_set_value(gpio_output[pin-1],LOW);
    }

}
void GPIO_Config::GPIO_Initial(){
    gpio_export(gpio_input[0]);
    gpio_export(gpio_input[1]);
    gpio_export(gpio_input[2]);
    gpio_export(gpio_input[3]);
    gpio_export(gpio_input[4]);
    gpio_export(gpio_input[5]);
    gpio_export(gpio_input[6]);
    gpio_export(gpio_input[7]);
    gpio_export(gpio_input[8]);
    gpio_export(gpio_input[9]);
    gpio_export(gpio_output[0]);
    gpio_export(gpio_output[1]);
    gpio_export(gpio_output[2]);
    gpio_export(gpio_output[3]);
    gpio_export(gpio_output[4]);
    gpio_export(gpio_output[5]);
    gpio_export(gpio_output[6]);
    gpio_export(gpio_output[7]);
    gpio_export(gpio_output[8]);
    gpio_export(gpio_output[9]);
    gpio_set_dir(gpio_input[0],INPUT_PIN);
    gpio_set_dir(gpio_input[1],INPUT_PIN);
    gpio_set_dir(gpio_input[2],INPUT_PIN);
    gpio_set_dir(gpio_input[3],INPUT_PIN);
    gpio_set_dir(gpio_input[4],INPUT_PIN);
    gpio_set_dir(gpio_input[5],INPUT_PIN);
    gpio_set_dir(gpio_input[6],INPUT_PIN);
    gpio_set_dir(gpio_input[7],INPUT_PIN);
    gpio_set_dir(gpio_input[8],INPUT_PIN);
    gpio_set_dir(gpio_input[9],INPUT_PIN);
    gpio_set_dir(gpio_output[0],OUTPUT_PIN);
    gpio_set_dir(gpio_output[1],OUTPUT_PIN);
    gpio_set_dir(gpio_output[2],OUTPUT_PIN);
    gpio_set_dir(gpio_output[3],OUTPUT_PIN);
    gpio_set_dir(gpio_output[4],OUTPUT_PIN);
    gpio_set_dir(gpio_output[5],OUTPUT_PIN);
    gpio_set_dir(gpio_output[6],OUTPUT_PIN);
    gpio_set_dir(gpio_output[7],OUTPUT_PIN);
    gpio_set_dir(gpio_output[8],OUTPUT_PIN);
    gpio_set_dir(gpio_output[9],OUTPUT_PIN);
    gpio_set_value(gpio_output[0],LOW);
    gpio_set_value(gpio_output[1],LOW);
    gpio_set_value(gpio_output[2],LOW);
    gpio_set_value(gpio_output[3],LOW);
    gpio_set_value(gpio_output[4],LOW);
    gpio_set_value(gpio_output[5],LOW);
    gpio_set_value(gpio_output[6],LOW);
    gpio_set_value(gpio_output[7],LOW);
    gpio_set_value(gpio_output[8],LOW);
    gpio_set_value(gpio_output[9],LOW);
}
