#include<stdio.h>
#include<stdlib.h>

int main(char argc,char **argv)
{
	FILE *p=NULL;
	int count=0;
	if(argc<1)//统计./后参数个数 0 1 2| ./2 1.c 2.c 
	{
	fprintf(stderr,"usage..=2\n");
	exit(1);
	}
    p=fopen(argv[1],"r");//argv[]指针数组 存放 文件的地址
	if(p==NULL)
	{
    fclose(p);
	perror("fopen()\n");
	exit(1);
	}
	while(fgetc(p)!=EOF)
    {
    count++;
    }
	printf("char count = %d \n",count);

	int ret;
	ret=fclose(p);
	printf("ret = %d \n",ret);
    exit(0);	

}
