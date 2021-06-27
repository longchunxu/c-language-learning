#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/fs.h>//文件操作集头文件
#include<linux/miscdevice.h>//杂项设备头文件
#include<linux/uaccess.h>//数据发送接受头文件
int misc_open(struct inode *inode, struct file *file)
{
	printk("function %s\n",__FUNCTION__);
	return 0;
}
int misc_release(struct inode *inode, struct file *file)
{
	printk("---------function-------- %s bye",__FUNCTION__);
	return 0;
}
ssize_t misc_read(struct file *file, char __user *ubuf, size_t size, loff_t *loff_t)
{
	char kbuf[1024]="Hello here are kernel data";
//static __always_inline unsigned long __must_check copy_to_user(void __user *to, const void *from, unsigned long n)
	if(copy_to_user(ubuf, kbuf, strlen(kbuf)) != 0)//内核层向应用层发送数据
	{
	printk("function %s error",__FUNCTION__);
	}
	printk("function %s ",__FUNCTION__);
	return 0;
}
ssize_t misc_write(struct file *file, const char __user *ubuf, size_t size, loff_t *loff_t)
{
	char kbuf[1024];
//static __always_inline unsigned long __must_check copy_from_user(void *to, const void __user *from, unsigned long n)
	if(copy_from_user(kbuf, ubuf, strlen(ubuf)))//应用层向内核层发送数据
	{
	printk("function %s error",__FUNCTION__);
	}
	printk("function %s:%s ",__FUNCTION__,kbuf);
	return 0;
}
struct file_operations misc_fops ={
	.owner=THIS_MODULE,
	.open=misc_open,
	.release=misc_release,
	.read=misc_read,
	.write=misc_write

};

struct miscdevice misc_dev={
	.minor=MISC_DYNAMIC_MINOR,//动态分配从设备号
	.name="misc_test_open",//节点名
	.fops=&misc_fops//文件操作集

};

static int __init misc_init(void)
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
static void __exit misc_exit(void)
{
	misc_deregister(&misc_dev);
	printk("Goodbye----------\n");
}
module_init(misc_init);
module_exit(misc_exit);
MODULE_LICENSE("GPL");
