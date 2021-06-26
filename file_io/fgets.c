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
	
	while(fgets(buf,SIZE,p))//char *fgets(char *s, int size, FILE *stream);
	{
	count++;
	fputs(buf,q);//int fputs(const char *s, FILE *stream);
	}
	printf("---------count=%d-----------",count);
	fclose(p);
	fclose(q);
	
	exit (0);
}
