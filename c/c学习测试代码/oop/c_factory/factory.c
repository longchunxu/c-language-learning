#include <stdio.h>
#include "factory.h"
#include <unistd.h>

struct device touch_cust_device = {
	.name = "gt",
};

struct device touch_cust_device2 = {
	.name = "ft",
};
	
int main(void)
{	
	
	touch_device_t touch_device = touch_device_init(&touch_cust_device);
	if (touch_device == NULL){
		printf("can't find touch decice \n");
		return -1;
	}
	touch_device->init();
	touch_device->open();
	touch_device->get_point();
	sleep(2);

	
	touch_device_t touch_device2 = touch_device_init(&touch_cust_device2);
	if (touch_device2 == NULL){
		printf("can't find touch decice \n");
		return -1;
	}
	
	touch_device2->init();
	touch_device2->open();
	touch_device2->get_point();
	
	return 0;
}