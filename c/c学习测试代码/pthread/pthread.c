/*
 * @Descripttion: 说明
 * @version: V1.0
 * @Author: LongChunxu
 * @Date: 2021-07-14 23:04:40
 * @LastEditors: LongChunxu
 * @LastEditTime: 2022-04-18 21:01:09
 */
#include<stdio.h>
#include<stdlib.h>
#include <pthread.h>


void *func(int *p)
{
 	printf("thread is running,%d \n",p);
	printf("新线程: 进程 ID<%d> 线程 ID<%lu>\n", getpid(), pthread_self());
}


int main(int argc,char *argv[])
{	
	puts("start");
	pthread_t tid;
	int n=2;
	pthread_create(&tid,NULL,func,n);
	pthread_join(tid,NULL);
	printf("新线程: 进程 ID<%d> 线程 ID<%lu>\n", getpid(), pthread_self());
	
	puts("end");
	exit(0);

}
