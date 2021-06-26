#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/fs.h>
#include<linux/miscdevice.h>
struct file_operations misc_fops ={
	.owner=THIS_MODULE

};

struct miscdevice misc_dev={
	.minor=MISC_DYNAMIC_MINOR,//动态分配从设备号
	.name="misc_test",//节点名
	.fops=&misc_fops//文件操作集

};

static int  misc_init(void)
{
	int ret;
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
static void  misc_exit(void)
{
	misc_deregister(&misc_dev);
	printk("Goodbye----------\n");
}
module_init(misc_init);
module_exit(misc_exit);
MODULE_LICENSE("GPL");
