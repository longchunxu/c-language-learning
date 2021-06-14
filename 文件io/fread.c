#include<stdio.h>
#include<stdlib.h>
#define SIZE 1024
int main(char argc,char **argv)
{
	FILE *p=NULL,*q=NULL;
	
	int count=0;
	char buf[SIZE];
	if(argc<1)
	{
	printf("argc need 2 parameter\n");
	exit(1);
	}
	p=fopen(argv[1],"r");
	{
	if(p==NULL)
		{
		perror("open file fail\n");
		exit(1);
		}
	
	}
	q=fopen(argv[2],"w");
	{
	if(q==NULL)
		{
		perror("open file fail\n");
		exit(1);
		}
	
	}
	int n=0;//代表读取成功的个数
	while((n=fread(buf,1,SIZE,p))>0)//size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);读取到的内容放进buf中 1个字节 SIZE个整体
	{
	count++;
	printf("---------count=%d-----------",count);
	fwrite(buf,1,n,q);//size_t fwrite(const void *ptr, size_t size, size_t nmemb,FILE *stream);  从buf中读取写进文件q中
	}
	printf("---------count=%d-----------",count);
	fclose(p);
	fclose(q);
	
	exit (0);
}
