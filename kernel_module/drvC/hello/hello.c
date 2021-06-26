#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
static int __init Hello(void)
{
	printk("hello----------lcx\n");
	return 0;
}
static void __exit move(void)
{
	
	printk("Goodbye-------\n");
}
module_init(Hello);
module_exit(move);
MODULE_LICENSE("GPL");
