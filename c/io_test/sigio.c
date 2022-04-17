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
#include <error.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <fcntl.h>


/*

要使用异步 I/O，程序需要按照如下步骤来执行：
⚫ 通过指定 O_NONBLOCK 标志使能非阻塞 I/O。
⚫ 通过指定 O_ASYNC 标志使能异步 I/O。
⚫ 设置异步 I/O 事件的接收进程。也就是当文件描述符上可执行 I/O 操作时会发送信号通知该进程，
通常将调用进程设置为异步 I/O 事件的接收进程。
⚫ 为内核发送的通知信号注册一个信号处理函数。默认情况下，异步 I/O 的通知信号是 SIGIO，所以
内核会给进程发送信号 SIGIO。在 8.2 小节中简单地提到过该信号。
⚫ 以上步骤完成之后，进程就可以执行其它任务了，当 I/O 操作就绪时，内核会向进程发送一个 SIGIO
信号，当进程接收到信号时，会执行预先注册好的信号处理函数，我们就可以在信号处理函数中进
行 I/O 操作。

*/
static int fd;
static void sigio_handler(int sig)
{
	 static int loops = 5;
	 char buf[100] = {0};
	 int ret;
	 if(SIGIO != sig)
	 	return;
	 
	 ret = read(fd, buf, sizeof(buf));
	 
	 if (0 < ret)
	 	printf("滚轮: 成功读取<%d>个字节数据\n", ret);
	 
	 loops--;
	 if (0 >= loops) {
	 close(fd);
	 exit(0);
	 }

}
 int main(int argc,char *argv[])
 {
	 int flag;
    //终端上输入 hexdump /dev/input/event? ?代表一个数字 设备不同数字不同  6鼠标 4 滑轮  2 键盘 

	/* 打开设备文件<使能非阻塞 I/O> */
     fd = open("/dev/input/event4",O_RDWR|O_NONBLOCK);//通过指定 O_NONBLOCK 标志使能非阻塞 I/O
     if (fd < 0){
         perror("open  fail !!!");
         exit(-1);
     }
	 
	 /* 使能异步 I/O */
	 flag = fcntl(fd, F_GETFL); //先获取原来的 flag
	 flag |= O_ASYNC; //将 O_ASYNC 标志添加到 flag 通过指定 O_ASYNC 标志使能异步 I/O
	 fcntl(fd, F_SETFL, flag); //重新设置 flag

	 /* 设置异步 I/O 的所有者 */
	 fcntl(fd, F_SETOWN, getpid());//绑定到进程去处理事件

	 /* 为 SIGIO 信号注册信号处理函数 */
 	 signal(SIGIO, sigio_handler);//滚轮滑动时会触发回调函数读取数据
	 
	 for(;;) {
	 sleep(100);//在这里循环等待 等待滚轮事件发生
     }

 	 exit(0);
 }
