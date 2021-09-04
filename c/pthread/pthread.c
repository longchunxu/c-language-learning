#include<stdio.h>
#include<stdlib.h>
#include <pthread.h>


void *func(int *p)
{
 	printf("thread is running\n");

}


int main(int argc,char *argv[])
{	
	puts("start");
	pthread_t tid;
	int n=2;
	pthread_create(&tid,NULL,func,&n);
	pthread_join(tid,NULL);
	
	puts("end");
	exit(0);

}
