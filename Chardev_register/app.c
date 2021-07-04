#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc,char *argv[])
{
	int fd;
	char buf[1024]={0};
	fd=open("/dev/test",O_RDWR);
	if(fd<0)
	{
	perror("open fd error\n");
	}
//	read(fd,buf,sizeof(buf));
//	printf("the buf:%s \n",buf);
//	write(fd,buf,sizeof(buf));
	close(fd);
	printf("finished\n");
	return 0;
}
