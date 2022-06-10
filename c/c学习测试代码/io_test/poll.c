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
#include <poll.h>
//int poll(struct pollfd *fds, nfds_t nfds, int timeout);
/*
fds：指向一个 struct pollfd 类型的数组，数组中的每个元素都会指定一个文件描述符以及我们对该文件
描述符所关心的条件，稍后介绍 struct pollfd 结构体类型。
nfds：参数 nfds 指定了 fds 数组中的元素个数，数据类型 nfds_t 实际为无符号整形。
timeout：该参数与 select()函数的 timeout 参数相似，用于决定 poll()函数的阻塞行为，具体用法如下：
⚫ 如果 timeout 等于-1，则 poll()会一直阻塞（与 select()函数的 timeout 等于 NULL 相同），直到 fds
数组中列出的文件描述符有一个达到就绪态或者捕获到一个信号时返回。
⚫ 如果 timeout 等于 0，poll()不会阻塞，只是执行一次检查看看哪个文件描述符处于就绪态。
⚫ 如果 timeout 大于 0，则表示设置 poll()函数阻塞时间的上限值，意味着 poll()函数最多阻塞 timeout
毫秒，直到 fds 数组中列出的文件描述符有一个达到就绪态或者捕获到一个信号为止。
*/
 int main(int argc,char *argv[])
 {
     int fd,ret,fd_key;
	 struct pollfd fds[2];
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
	 printf("111\n");
  	fds[0].fd = fd;
	fds[0].events = POLLIN;//有数据可读        POLLOUT可以写入数据
	fds[0].revents = 0;
	fds[1].fd = fd_key;
	fds[1].events = POLLIN;
	fds[1].revents = 0;
    for(;;){
    ret = poll(fds, 2, -1);//如果有事件发生 会把发生的事件写入fds.revent的位
    if (0 > ret) {
    perror("select error");
    goto out;
    }
    else if (0 == ret) {
    fprintf(stderr, "select timeout.\n");
    continue;
    }
    /*FD_ISSET 检查键盘是否为就绪态 */
    if (fds[0].revents & POLLIN) {
    ret = read(fd, buf, sizeof(buf));
    if (0 < ret)
    printf("滑轮: 成功读取<%d>个字节数据\n", ret);
    }

    if (fds[1].revents & POLLIN) {//有数据可读
    ret = read(fd_key, buf, sizeof(buf));
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