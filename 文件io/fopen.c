#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

int main()
{
	
	FILE *p;
	p=fopen("tmp","r");//FILE *fopen(const char *path, const char *mode);
	if(p==NULL)
	{
	perror("fopen()");//输出标准错误
	printf("fopen is fail,return %d\n",errno);
	return errno;
	}	
	printf("fopen is successfull\n");
	exit(0);
	fclose(p);//int fclose(FILE *stream);
	
}
