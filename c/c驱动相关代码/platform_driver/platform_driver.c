#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/platform_device.h>
#include<linux/miscdevice.h>
#include<linux/fs.h>
struct resource *Platform_device_resource;
struct resource *Platform_device_tmp;
struct file_operations misc_fops ={
	.owner=THIS_MODULE

};

struct miscdevice misc_dev={
	.minor=MISC_DYNAMIC_MINOR,//动态分配从设备号
	.name="misc_test",//节点名
	.fops=&misc_fops//文件操作集

};
int Platform_driver_probe(struct platform_device *Device)
{	
	int ret;
	printk("Platform_driver_probe enter\n");
//	printk("device resource name:%s\n",Device->resource[0].name);			  1.直接获取硬件资源
	Platform_device_resource=platform_get_resource(Device,IORESOURCE_MEM,0);//2.通过函数获取硬件资源 参数1 设备结构体指针 参数2 设备资源类型 参数3 同种资源类型序列 
	if(Platform_device_resource==NULL)
	{
	printk("Platform_device_resource==NULL device is busy");
	return -EBUSY;
	} 
	printk("start=%#x\n",Platform_device_resource->start);
	printk("end=%#x\n",Platform_device_resource->end);
	printk("name=%s\n",Platform_device_resource->name);
	//向内核注册已经使用了的地址
/*	Platform_device_tmp=request_mem_region(Platform_device_resource->start,Platform_device_resource->end-Platform_device_resource->start+1,"test");
	if(Platform_device_tmp==NULL)
	{
	printk("Platform_device_tmp==NULL\n");
	return -EBUSY;
	} */
	
	ret=misc_register(&misc_dev);
	if(ret)
	{
	printk("%s register fail",__FUNCTION__);
	return -1;
	}
	printk("%s register successful\n",__FUNCTION__);
	printk("hello----------misc\n");
	
	
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
	misc_deregister(&misc_dev);
	printk("platform_driver_remove\n");
}
module_init(lcx_driver_init);
module_exit(lcx_driver_remove);
MODULE_LICENSE("GPL");
