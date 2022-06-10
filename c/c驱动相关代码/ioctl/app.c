#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/ioctl.h>
#include<stdlib.h>
#include<errno.h>
#include"ioctl_struct.h"
#define CMD_TEST0 		_IO('A',1)
#define CMD_TEST1 		_IOW('B',2,int)
#define CMD_TEST2 		_IOR('C',3,int)
#define CMD_TEST3 		_IOW('N',3,struct IoStruct)
/*struct IoStruct{
	char *p_name;
	int n;
};*/
int main(int argc,char *argv[])
{
	int fd,ret,num,i=40;
	char buf[1024]={0};
	struct IoStruct io={"lcx",98989};
	fd=open("/dev/misc_test",O_RDWR);
	if(fd<0)
	{
	perror("open fd error\n");
	}
	if(ret<0)
	{
	printf("error\n");
	exit(-1);
	}
	while(i>20)
	{
	if(ioctl(fd,CMD_TEST0))
	{
	perror("info:");
	exit(-1);
	}
	if(ioctl(fd,CMD_TEST1,i))
	{
	perror("info:");
	}
	if(ioctl(fd,CMD_TEST2,&num))
	{
	perror("info:");
	exit(-1);
	}
	printf("read num:%d\n",num);
	if(ioctl(fd,CMD_TEST3,&io))
	{
	perror("info:");
	exit(-1);
	}
	printf("i=%d\n",i);
	sleep(1);
	i--;
	}
/*	read(fd,buf,sizeof(buf));
	printf("the buf:%s \n",buf);
	write(fd,buf,sizeof(buf));
	close(fd);
	printf("finished\n");
*/
	return 0;
}

