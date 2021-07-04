#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/init.h>
#include<linux/fs.h>
#include<linux/kdev_t.h>
#include<linux/cdev.h>
// #define MAJOR_NUM 20
// #define MINOR_NUM 1
static int MAJOR_NUM;//主设备号
static int MINOR_NUM;//次设备号
module_param(MAJOR_NUM,int,S_IRUSR);//可以传参加载模块
module_param(MINOR_NUM,int,S_IRUSR);
#define DEVICE_NUMBER 1
#define DEV_SNAME  "sCharDevname"
#define DEV_ANAME  "aCharDevname"
#define DEV_MINOR_NUMBER 1
#define DEV_CLASS_NAME "chrdev_test"
#define DEV_DEVICE_NAME "chrdev_lcx"

struct cdev cdev;//创建一个字符设备
dev_t dev_num;//u32 类型 高16位主设备号 低16位次设备号
struct class *class;
struct device *device;
static int cdev_open(struct inode *node,struct file *file)
{
     printk("%s enter\n",__FUNCTION__);
     return 0;
};

 
struct file_operations cdev_ops = {//实现字符设备文件操作集
    .owner=THIS_MODULE,
    .open=cdev_open
};

static int __init Hello(void)
{   
    int ret; 
    if(MAJOR_NUM)
    {
    dev_num = MKDEV(MAJOR_NUM,MINOR_NUM);
    printk("MAJOR_NUM=%d MINOR_NUM=%d \n",MAJOR(dev_num),MINOR(dev_num));//获取主设备号  次设备号
    ret = register_chrdev_region(dev_num,DEVICE_NUMBER,DEV_SNAME);//param 1： u32 dev_t param 2:注册的设备数量 param 3：设备名
        
    if(ret<0)//静态注册
    {
        printk("register fail static");
    }
    
    printk("%s enter success\n",__FUNCTION__);
    return 0;
    }
    else//动态注册
    {   
    ret = alloc_chrdev_region(&dev_num,DEV_MINOR_NUMBER,DEVICE_NUMBER,DEV_ANAME);//param 2:注册的次设备号  主设备号动态申请并且存放在dev_num中
    if(ret)
        {
            printk("register fail alloc");
        }
    MAJOR_NUM=MAJOR(dev_num);
    MINOR_NUM=MINOR(dev_num);
    printk("MAJOR_NUM=%d MINOR_NUM=%d \n",MAJOR(dev_num),MINOR(dev_num));

    cdev.owner=THIS_MODULE;//初始化字符设备成员owner
    cdev_init(&cdev,&cdev_ops);//初始化字符设备 1.构建结构体 2.实现file_operation接口
    cdev_add(&cdev,dev_num,DEVICE_NUMBER);//注册字符设备

	class=class_create(THIS_MODULE,DEV_CLASS_NAME);//先在sys目录下创建一个类(udev在用户空间创建目录)
	device=device_create(class,NULL,dev_num,NULL,DEV_DEVICE_NAME);//在自定义类下创建自定义节点
    return 0;
    }
    
}
static void  __exit move(void)
{   
    
    unregister_chrdev_region(MKDEV(MAJOR_NUM,MINOR_NUM),DEVICE_NUMBER);//注销设备号
    cdev_del(&cdev);//注销字符设备
    device_destroy(class,dev_num);//注销自定义类class下的设备节点
    class_destroy(class);//注销sys下的自定义class节点
    printk("MKDEV(MAJOR_NUM,MINOR_NUM) = %d \n",MKDEV(MAJOR_NUM,MINOR_NUM));
    printk("%s exit\n",__FUNCTION__);
}
module_init(Hello);
module_exit(move);
MODULE_LICENSE("GPL");
