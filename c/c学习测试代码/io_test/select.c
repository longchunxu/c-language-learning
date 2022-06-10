/*
 * @Descripttion: 说明
 * @version: V1.0
 * @Author: LongChunxu
 * @Date: 2022-04-16 18:10:59
 * @LastEditors: LongChunxu
 * @LastEditTime: 2022-04-17 17:43:49
 */
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <error.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>

 int main(int argc,char *argv[])
 {
     int fd,ret,fd_key;
     fd_set rdfds;
     char buf[100];
     //终端上输入 hexdump /dev/input/event? ?代表一个数字 设备不同数字不同  6鼠标 4 滑轮  2 键盘 
     
     fd = open("/dev/input/event6",O_RDWR);
     if (fd < 0){
         perror("open fail !!!");
         exit(-1);
     }
     fd_key = open("/dev/input/event4",O_RDWR);
     if (fd_key < 0){
         perror("open key fail !!!");
         exit(-1);
     }
     //printf("fd = %d,fd_key = %d \n",fd,fd_key);  
    for(;;){
    FD_ZERO(&rdfds);
    FD_SET(fd, &rdfds); //添加鼠标
    FD_SET(fd_key, &rdfds); //添加滑轮
    ret = select(fd_key + 1, &rdfds, NULL, NULL, NULL);//在这里 需要用最大的文件fd+1也就是 fd_key+1
    if (0 > ret) {
    perror("select error");
    goto out;
    }
    else if (0 == ret) {
    fprintf(stderr, "select timeout.\n");
    continue;
    }
    /*FD_ISSET 检查键盘是否为就绪态 */
    if(FD_ISSET(fd_key, &rdfds)) {
    ret = read(fd_key, buf, sizeof(buf));
    if (0 < ret)
    printf("滑轮: 成功读取<%d>个字节数据\n", ret);
    }

    if(FD_ISSET(fd, &rdfds)) {
    ret = read(fd, buf, sizeof(buf));
    if (0 < ret)
    printf("鼠标: 成功读取<%d>个字节数据\n", ret);
    }
       
     

    }
out:
 /* 关闭文件 */
 close(fd);
 close(fd_key);
 exit(ret);
 }