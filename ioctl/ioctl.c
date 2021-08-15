#include<linux/module.h>//所有模块都要使用头文件module.h，此文件必须包含进来
#include<linux/kernel.h>//头文件kernel.h包含了常用的内核函数。
#include<linux/init.h>//头文件init.h包含了宏_init和_exit，它们允许释放内核占用的内存
#include <linux/ioctl.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include<linux/miscdevice.h>
#include"ioctl_struct.h"
#define CMD_TEST0 		_IO('A',1) 
#define CMD_TEST1 		_IOW('B',2,int)//para 1:magic num para 2:cmd para 3：data type
#define CMD_TEST2 		_IOR('C',3,int)
#define CMD_TEST3 		_IOW('N',3,struct IoStruct)
/*struct IoStruct{
	char *p_name;
	int n;
};*/
long test_ioctl(struct file *file, unsigned int cmd, unsigned long value)
{	
	int num=2;
	switch(cmd)
	{
	case CMD_TEST0:
	printk("CMD_TEST0\n");
	break;
	case CMD_TEST1://write
	printk("CMD_TEST1,write value:%d\n",value);
	break;
	case CMD_TEST2://read
	{
		copy_to_user((int *)value,&num,sizeof(num));//para 1 在这里强转一下是因为app.c里 传过来的是一个int地址，返回给app.c的数据也应该是一个int地址
		printk("CMD_TEST2\n");
		break;
	}
	case CMD_TEST3://write struct type
	{	
		struct IoStruct recv;
		copy_from_user(&recv,(struct IoStruct __user*)value,sizeof(struct IoStruct));
		printk("value: %d \n",recv.n);
		printk("name: %s \n",recv.p_name);
		break;
	}
	
	
	default:
	printk("CMD can't match,cmd: %#x\n",cmd);
	}
	return 0;
}
ssize_t ioctl_read(struct file *file, char __user *buf, size_t size, loff_t *loff_t)
{
	printk("----!read!----\n");
	return 0;

}
ssize_t ioctl_write(struct file *fiel, const char __user *buf, size_t size, loff_t *loff_t)
{	
	printk("----! write !----\n");
	return 0;
}
struct file_operations misc_fops ={
	.owner=THIS_MODULE,
	.write=ioctl_write,
	.read=ioctl_read,
	.unlocked_ioctl=test_ioctl,
	
};
struct miscdevice misc_dev={
	.minor=MISC_DYNAMIC_MINOR,//动态分配从设备号
	.name="misc_test",//节点名
	.fops=&misc_fops//文件操作集
};


static int __init Hello(void)
{
	
	int ret;
	ret=misc_register(&misc_dev);
	if(ret)
	{
	printk("%s register fail",__FUNCTION__);
	return -1;
	}
	
	printk("%s register successful\n",__FUNCTION__);
	printk("Hello, this is ioctl module\n");
	return 0;

}
static void __exit Exit(void)
{
	misc_deregister(&misc_dev);
	printk("------ ioctl module exit-----\n");
}

module_init(Hello);
module_exit(Exit);
MODULE_LICENSE("GPL");//告诉内核该模块具有GNU公共许可证
MODULE_DESCRIPTION("Hello");


