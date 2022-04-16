/*
 * @Descripttion: 说明
 * @version: V1.0
 * @Author: LongChunxu
 * @Date: 2022-04-16 18:10:59
 * @LastEditors: LongChunxu
 * @LastEditTime: 2022-04-16 18:54:59
 */
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <error.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

 int main(int argc,char *argv[])
 {
     int fd,ret;
     unsigned char buf[] = "test open func";
     unsigned char rbuf[20];
     fd = open("./test.txt",O_RDWR);
     if (fd < 0){
         perror("open fail !!!");
         exit(-1);
     }
     ret = write(fd,buf,strlen(buf));
     if (ret < 0){
         perror("write fail !!!");
         exit(-1);
     } else{
         printf("write successful %d bytes \n",ret);
     }
    int new_offset;
    new_offset = lseek(fd, 0, SEEK_SET);//在这里要把光标移到前面的位置才可以读到信息
     if (new_offset < 0){
         perror("offset fail !!!");
         exit(-1);
     }

     ret = read(fd,rbuf,sizeof(rbuf)/sizeof(*rbuf));
      if (ret < 0){
         perror("read fail !!!");
         exit(-1);
     } else {
         printf("read %d bytes successful: %s  \n",ret,rbuf);
     }
     close(fd);

 }
