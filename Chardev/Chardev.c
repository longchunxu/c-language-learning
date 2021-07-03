#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/init.h>
#include<linux/fs.h>
#include<linux/kdev_t.h>
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
static int __init Hello(void)
{   dev_t dev_num;//u32 类型 高16位主设备号 低16位次设备号
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
    return 0;
    }
    
}
static void  __exit move(void)
{   
    
    unregister_chrdev_region(MKDEV(MAJOR_NUM,MINOR_NUM),DEVICE_NUMBER);
    printk("MKDEV(MAJOR_NUM,MINOR_NUM) = %d \n",MKDEV(MAJOR_NUM,MINOR_NUM));
    printk("%s exit\n",__FUNCTION__);
}
module_init(Hello);
module_exit(move);
MODULE_LICENSE("GPL");