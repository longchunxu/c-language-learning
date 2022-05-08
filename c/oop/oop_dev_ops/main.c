/*
 * @Descripttion: 说明
 * @version: V1.0
 * @Author: LongChunxu
 * @Date: 2022-05-08 14:11:25
 * @LastEditors: LongChunxu
 * @LastEditTime: 2022-05-08 15:52:12
 */
#include <stdio.h>
#include <string.h>
#include "dev.h"
struct dev dev_test;

void dev_open(struct dev *dev)
{
    printf("%s\t %d \t \n",__func__,__LINE__);
}
void dev_read(struct dev *dev)
{
    printf("%s\t %d \t dev->p_data->height = %d\n",__func__,__LINE__,dev->p_data->height);
}

void dev_write(struct dev *dev,char name[])
{   
    int len =strlen(name) + 1;
    memcpy(dev_test.name,name,len);
    printf("%s\t %d \t dev_test.name = %s \n",__func__,__LINE__,dev_test.name);
}
void dev_show(struct dev *dev)
{
    printf("%s \n", dev_test.name);
    printf("%d \n", dev_test.p_data->height);
    printf("%d \n", dev_test.p_data->weight);
    printf("%s \n", dev_test.p_data->name);
}
struct dev_ops test_dev_ops = {
    .open = dev_open,
    .read = dev_read,
    .write = dev_write,
    .show = dev_show,
};
struct dev_data test_dev_data = {
    .name = "testtest",
    .height = 175,
    .weight = 20,

};
void dev_init(char name[],struct dev_ops  *p_ops,struct dev_data *p_data)
{
    memcpy(dev_test.name,name,sizeof(name)/sizeof(*name)+1);
    dev_test.p_ops = p_ops;
    dev_test.p_data = p_data;
}
int  main(void)
{
   // memcpy(dev_test.name,"dev_test",9);
    dev_init("dev_test",&test_dev_ops,&test_dev_data);
    dev_test.p_ops->open(&dev_test);
    dev_test.p_ops->read(&dev_test);
    dev_test.p_ops->write(&dev_test,"test_change_name");
    dev_test.p_ops->show(&dev_test);
    return 0;
}