#include<stdio.h>
#include<stdlib.h>
void fun( char b[])
{	int i=0;
	char *c=b;
	if(b==NULL)
	return ;
	while(*b!='\0')   
	{
	printf("b[%d]=%c\n",i,*b);
	
	b++;
	i++;
	}
	printf("-----------------\n");
	
	b=c;
	i=0;
	while(*b!='\0')   
	{
	printf("b[%d]=%c\n",i,*b);
	b++;
	i++;
	}	
	
}

int main()
{
	 char a[10]="abcdefghi";
	fun(a);
	exit(0);
}
