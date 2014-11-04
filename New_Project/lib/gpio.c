#include <stdio.h>
#include <string.h>
#include "gpio.h"

int p8_pinno[46]={0,0,38,39,34,35,66,67,69,68,
			45,44,23,26,47,46,27,65,22,63,
			62,37,36,33,32,61,86,88,87,89,
			10,11,9,81,8,80,78,79,76,77,
			74,75,72,73,70,71};

int p9_pinno[46]={0,0,0,0,0,0,0,0,0,0,
			30,60,31,50,48,51,5,4,13,12,
			3,2,49,15,117,14,115,113,111,112,
			110,0,0,0,0,0,0,0,0,0,
			20,7,0,0,0,0

			};

	int checkPinNumber(int exp_hdr_no,int pin_number)
	{
		if(exp_hdr_no == 8){
			if(pin_number == 1 || pin_number == 2)
				return 1;
			return 0;
		}else if(exp_hdr_no == 9){
			if(pin_number <=10 || (pin_number >=32 && pin_number <=40) || (pin_number >= 43 && pin_number <=46))
				return 1;
			return 0;
		}
		return 1;
	}


	int gpio_change_value(int exp_hdr_no,int pin_number,int state)
	{

		char gpio[40];
		FILE *fp =NULL;
		int gpio_value=-1;
		char gpio_state[10];
		if(exp_hdr_no == P8)
			sprintf(gpio,"/sys/class/gpio/gpio%d%s",p8_pinno[pin_number-1],"/value");
		else if(exp_hdr_no == P9)
			sprintf(gpio,"/sys/class/gpio/gpio%d%s",p9_pinno[pin_number-1],"/value");
		if(state ==SET || state == CLR){
			fp= fopen(gpio,"w");
			if(fp!=NULL){
			if(state == SET)
				fprintf(fp,"%d",1);	
			else if(state == CLR)
				fprintf(fp,"%d",0);
			fclose(fp);
			}
			return 0;
		}else if(state == TOGGLE){
			fp = fopen(gpio,"r");
			if(fp!=NULL){
				fscanf(fp,"%d",&gpio_value);
				fclose(fp);
				fp = fopen(gpio,"w");
				if(fp != NULL) {
					fprintf(fp,"%d",!gpio_value);
					fclose(fp);
				}
			}
			return 0;
		}else if(state == READ){

			fp = fopen(gpio,"r");
			if(fp!=NULL){
				fscanf(fp,"%d",&gpio_value);

				fclose(fp);
			return gpio_value;
			}
			return -1;
		}else if (state == READ_STATE){
			if(exp_hdr_no == P8)
				sprintf(gpio,"/sys/class/gpio/gpio%d%s",p8_pinno[pin_number-1],"/direction");
			if(exp_hdr_no == P9)
				sprintf(gpio,"/sys/class/gpio/gpio%d%s",p9_pinno[pin_number-1],"/direction");
			fp = fopen(gpio,"r");
			if(fp!=NULL){
				fscanf(fp,"%s",gpio_state);
				fclose(fp);

				if(!strcmp(gpio_state,"in"))	
					return 1;
				else if(!strcmp(gpio_state,"out"))
					return 0;
			}

		}
		return -1;
	}

	/*	
		Return -1 on Failure
		Return 0 on Success
	*/
	int gpio_initialize(int exp_hdr_no,int pin_number,int direction,int initial_val)
	{

		FILE *fp =NULL;
		char gpio[40];
				
		if(exp_hdr_no != 8 && exp_hdr_no != 9)
			return -1;

		if(checkPinNumber(exp_hdr_no,pin_number))
			return -1;

		if(direction > 1 || initial_val > 1)
			return -1;

		fp = fopen("/sys/class/gpio/export","w");

		if(fp!=NULL){
			if(exp_hdr_no == P8){
				fprintf(fp,"%d",p8_pinno[pin_number-1]);
				fclose(fp);
				sprintf(gpio,"/sys/class/gpio/gpio%d%s",p8_pinno[pin_number-1],"/direction");
				fp= fopen(gpio,"w");
				if(fp!=NULL){
					if(direction)
						fprintf(fp,"out");
					else
						fprintf(fp,"in");
				fclose(fp);

				sprintf(gpio,"/sys/class/gpio/gpio%d%s",p8_pinno[pin_number-1],"/value");

				fp= fopen(gpio,"w");
				if(fp!=NULL){					
					fprintf(fp,"%d",initial_val);
					fclose(fp);
					return 0;
				}
				}
				
								
			}

			if(exp_hdr_no == P9){
				fprintf(fp,"%d",p9_pinno[pin_number-1]);
				fclose(fp);
				sprintf(gpio,"/sys/class/gpio/gpio%d%s",p9_pinno[pin_number-1],"/direction");
				fp= fopen(gpio,"w");
				if(fp!=NULL){
					if(direction)
						fprintf(fp,"out");
					else
						fprintf(fp,"in");
				fclose(fp);
				sprintf(gpio,"/sys/class/gpio/gpio%d%s",p8_pinno[pin_number-1],"/value");

				fp= fopen(gpio,"w");
				if(fp!=NULL){				
					fprintf(fp,"%d",initial_val);	
					fclose(fp);
					return 0;
				}
				}
			
			}
		}
		return -1;	
	}
	

	void gpio_set(int exp_hdr_no,int pin_number)
	{
		gpio_change_value(exp_hdr_no,pin_number,SET);		
	}

	void gpio_clr(int exp_hdr_no,int pin_number)
	{
		gpio_change_value(exp_hdr_no,pin_number,CLR);
	}

	void gpio_toggle(int exp_hdr_no,int pin_number)
	{
		gpio_change_value(exp_hdr_no,pin_number,TOGGLE);
	}
	

	/*
		Return -1 on failure
		Returns the value on success
	*/

	int gpio_read(int exp_hdr_no,int pin_number)
	{
		return gpio_change_value(exp_hdr_no,pin_number,READ);		
	}


	int gpio_is_input(int exp_hdr_no,int pin_number)
	{
		return gpio_change_value(exp_hdr_no,pin_number,READ_STATE);
	}


