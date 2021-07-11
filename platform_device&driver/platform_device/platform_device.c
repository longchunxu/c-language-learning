#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/platform_device.h>
struct resource platform_device_resource[]={
	[0]=
	{
	.start=0x00100,//内存起始地址
	.end=0x00104,//内存结束地址
	.flags=IORESOURCE_MEM,//3种 1.io 2.mem 3.irq 
	.name="resource_tset"
	}
};

struct platform_device  platform_device_test={
	.name="platform_device_test", // 设备名在这个节点/sys/bus/platform/platform_device_test
	.id=-1,
	.resource=platform_device_resource,//对硬件资源的描述
	.num_resources=ARRAY_SIZE(platform_device_resource)//通过ARRAY_SIZE获取资源个数
};

static int __init platform_device_init(void)
{	int ret;
	ret=platform_device_register(&platform_device_test);
	if(ret)
		{
		printk("register fail\n");
		}
	printk("platform_device_init\n");
	
	return 0;
}
static void __exit platformdevice_remove(void)
{
	platform_device_unregister(&platform_device_test);
	printk("platformdevice_remove\n");
	
}
module_init(platform_device_init);
module_exit(platformdevice_remove);
MODULE_LICENSE("GPL");
