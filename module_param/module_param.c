#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
static int a;
static int b[5];
static int count;
//传参数
module_param(a,int,0555);//module_param(name,type,perm) module_param(变量名,变量类型,权限)
//传数组
module_param_array(b,int,&count,0555);//module_param_array(name,type,&count,perm) module_param array(数组名,数组类型,传入的个数,权限)
static int __init Hello(void)
{
	int i;
	printk("hello---------a=%d\n",a);	
	for(i=0;b[i]!=NULL;i++)
	printk("b[%d]=%d \n",i,b[i]);
	printk("count=%d\n",count);
	return 0;
}
static void __exit move(void)
{
	
	printk("Goodbye-------\n");
}
module_init(Hello);
module_exit(move);
MODULE_LICENSE("GPL");
