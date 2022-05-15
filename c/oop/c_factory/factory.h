#ifndef FACTORY_H
#define FACTORY_H

typedef struct device {

	char *name;
	int (*init)();
	int (*open)();
	int (*get_point)();

} * touch_device_t;


int gt_touch_init();
int gt_touch_open();
int gt_touch_get_point();

int ft_touch_init();
int ft_touch_open();
int ft_touch_get_point();

touch_device_t touch_device_init(touch_device_t device);



#endif