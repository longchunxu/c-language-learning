#include<linux/module.h>//所有模块都要使用头文件module.h，此文件必须包含进来
#include<linux/kernel.h>//头文件kernel.h包含了常用的内核函数。
#include<linux/init.h>//头文件init.h包含了宏_init和_exit，它们允许释放内核占用的内存
#include<linux/of.h>
#include<linux/platform_device.h>
#include<linux/miscdevice.h>
#include<linux/uaccess.h>
#include<linux/slab.h>
#include <linux/gpio.h>
#include <linux/of_gpio.h>
#include<linux/workqueue.h>
#include<linux/delay.h>

int  misc_open(struct inode *inode, struct file *file)
{
	printk(" misc_open %s \n",__func__);
	return 0;
}
int misc_release(struct inode *inode, struct file *file)
{
	printk(" misc_release %s \n",__func__);
	return 0;
}
ssize_t misc_read(struct file *file, char __user *buf, size_t size, loff_t *loff_t)
{
	char local_buf[]=" misc_read_copy_to_user";
	copy_to_user( buf,local_buf,sizeof(local_buf));
	printk(" misc_read %s : %s \n",__func__,local_buf);
	return 0;
}
ssize_t misc_write(struct file *file, const char __user *buf, size_t size, loff_t *loff_t)
{
	unsigned char local_buf[20];
	if(copy_from_user(local_buf,buf,sizeof(buf)))
	{
		printk(" misc_write fail\n");
		return -22;
	}
	local_buf[19]='\0';
	printk(" misc_write %s : %s \n",__func__,local_buf);
	return size;//这里要返回写入的数据字节数 否则写入时陷入死循环！
}
struct file_operations misc_fops = {
	.owner=THIS_MODULE,
	.open=misc_open,
	.read=misc_read,
	.write=misc_write,
	.release=misc_release,
};
struct miscdevice misc_dev = {
	.name="misc_test",
	.minor=MISC_DYNAMIC_MINOR,
	.fops=&misc_fops,
};
void mywork_func(struct work_struct *work)
{
	udelay(2000);//延时等待一会儿 看效果
	printk(" enter %s \n",__func__);
}
int probe_test(struct platform_device *platform_device)
{
	/* #include<linux/workqueue.h */
	/* 1. 动态初始化一个工作队列
	struct work_struct mywork;//定义一个工作队列
	INIT_WORK(&mywork,mywork_func);//初始化工作队列 mywork_func 为要加入队列的处理函数
	printk("%s  enter  start \n",__func__);
	schedule_work(&mywork);//工作调度 让mywork_func加入队列排队
	printk("%s  enter  end   \n",__func__);*/
	/*2.  静态初始化一个工作队列  */
	DECLARE_WORK(mywork,mywork_func); //定义并且初始化
	printk("%s  static enter  start \n",__func__);
	schedule_work(&mywork);//工作调度 让mywork_func加入队列排队
	printk("%s  enter  end   \n",__func__);

	misc_register(&misc_dev);
	return 0;
}
int platform_remove(struct platform_device *platform_device)
{
	printk(" enter %s \n",__func__);
	misc_deregister(&misc_dev);
	return 0;
}
const struct of_device_id platform_driver_of_match_ptr[] = {
	{.compatible="lcx,dts_test"},
};

struct platform_driver platform_driver_test = {
	.probe=probe_test,
	.remove=platform_remove,
	.driver = {
	.name="lcx_platform_test",
	.of_match_table=of_match_ptr(platform_driver_of_match_ptr),//使用设备树进行匹配
	}
//	const struct platform_device_id *id_table;
};
static int __init dts_test(void)
{
//	misc_register(&misc_dev);
	printk(" enter %s \n",__func__);
	platform_driver_register(&platform_driver_test);
	return 0;
}
static void __exit remove_dts_test(void)
{
//	misc_deregister(&misc_dev);
	platform_driver_unregister(&platform_driver_test);
	printk(" enter %s \n",__func__);

}
module_init(dts_test);
module_exit(remove_dts_test);
MODULE_LICENSE("GPL");
