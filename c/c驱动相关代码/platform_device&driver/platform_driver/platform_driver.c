#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/platform_device.h>
int Platform_driver_probe(struct platform_device *Device)
{
	printk("Platform_driver_probe enter\n");
	return 0;
}
int Platform_driver_remove(struct platform_device *Device)
{
	printk("platform_driver_probe remove\n");
	return 0;
}
const struct platform_device_id Platform_driver_id_tables={
	//.name="11platform_device_test"
};
struct platform_driver platform_driver_test = {
	.probe=Platform_driver_probe,
	.remove=Platform_driver_remove,
	.driver={
	.name="platform_device_test",
	.owner=THIS_MODULE
	},
//	.id_table=&Platform_driver_id_tables  //id_table 的匹配优先级比name的匹配优先级要高
};

static int __init lcx_driver_init(void)
{	int ret;
	ret=platform_driver_register(&platform_driver_test);
	if(ret)
		{
		printk("register fail\n");
		}
	printk("platform_driver_init\n");
	return 0;
}
static void __exit lcx_driver_remove(void)
{
	platform_driver_unregister(&platform_driver_test);
	printk("platform_driver_remove\n");
}
module_init(lcx_driver_init);
module_exit(lcx_driver_remove);
MODULE_LICENSE("GPL");
