/*
	@author:Md.Jamal Mohiuddin<mjmohiuddin@cdac.in>
	@desc :As the sysfs exports information about devices and drivers to the user 			space,and it is also used for configuration.We will be using to configure
		our beaglebone black gpios.
		Totally we are having 67 gpios available in the two expansion connectors(p8 			and p9)
	
*/

#ifndef GPIO_H
#define GPIO_H

#define IN 0
#define OUT 1
#define P8 8
#define P9 9
#define SET 0
#define CLR 1
#define TOGGLE 2
#define READ 3
#define READ_STATE 4


	/*
		Initialize a particluar gpio
		exp_hdr_no = should be either 8 or 9
		pin_number = should not be 1,2 in P8 header as they are GND,and 1-10,43-46 					32-40,in P9 header
		direction  = input = 0
			     output = 1

		initial_val
	*/
	int gpio_initialize(int exp_hdr_no,int pin_number,int direction,int initial_val);



	/*
		set a particular gpio pin
		exp_hdr_no = should be either 8 or 9
		pin_number = should not be 1,2 in P8 header as they are GND,and 1-10,43-46 					32-40,in P9 header

	*/
	void gpio_set(int exp_hdr_no,int pin_number);

	
	/*
		clear a particular gpio pin
		exp_hdr_no = should be either 8 or 9
		pin_number = should not be 1,2 in P8 header as they are GND,and 1-10,43-46 					32-40,in P9 header

	*/
	
	void gpio_clr(int exp_hdr_no,int pin_number);
	
	
	/*
		Toggle a particular gpio pin
		exp_hdr_no = should be either 8 or 9
		pin_number = should not be 1,2 in P8 header as they are GND,and 1-10,43-46 					32-40,in P9 header

	*/

	void gpio_toggle(int exp_hdr_no,int pin_number);

	
	/*
		Read a gpio pin
		exp_hdr_no = should be either 8 or 9
		pin_number = should not be 1,2 in P8 header as they are GND,and 1-10,43-46 					32-40,in P9 header
		return : 1 or 0

	*/
	int gpio_read(int exp_hdr_no,int pin_number);


	/*
		Check whether the gpio is input or not
		exp_hdr_no = should be either 8 or 9
		pin_number = should not be 1,2 in P8 header as they are GND,and 1-10,43-46 					32-40,in P9 header
		return : 1 for input or 0 for output
	*/
	int gpio_is_input(int exp_hdr_no,int pin_number);

	


#endif
