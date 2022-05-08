/*
 * @Descripttion: 说明
 * @version: V1.0
 * @Author: LongChunxu
 * @Date: 2022-05-08 14:07:17
 * @LastEditors: LongChunxu
 * @LastEditTime: 2022-05-08 14:47:41
 */
#ifndef DEV_H
#define DEV_H
#define MAX_SIZE 20
struct dev;
struct dev_ops{
    
    void (*open)(struct dev *dev);
    void (*read)(struct dev *dev);
    void (*write)(struct dev *dev,char *name);
    void (*show)(struct dev *dev);

};

struct dev_data {
    char name[20];
    int height;
    int weight;

};

struct dev
{
    char name[MAX_SIZE];
    struct dev_ops  *p_ops;
    struct dev_data *p_data;
};



#endif