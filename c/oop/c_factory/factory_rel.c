
#include <string.h>
#include <stdlib.h>
#include "factory.h"

struct device touch_device_list[] = {

	{"ft",ft_touch_init,ft_touch_open,ft_touch_get_point},
	{"gt",gt_touch_init,gt_touch_open,gt_touch_get_point},

};


touch_device_t touch_device_init(touch_device_t device)
{
	int i = 0;
	if (device->name == NULL)
		return NULL;
	for (i = 0; i < sizeof(touch_device_list)/sizeof(*touch_device_list); i++){
	if (0 == strcmp(device->name,touch_device_list[i].name))
		return &touch_device_list[i];
	}
	
	return NULL;
	

}

