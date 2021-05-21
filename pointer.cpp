#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i=1;
	int *p=&i;
	int **q=&p;//p指针指向i的地址   p指针的地址用二级指针**q存放  
	
	printf("i=%d\n",i);
	printf("&i=%p\n",&i);//i的地址 
	printf("p=%p\n",p);//i的地址 
	printf("&p=%p\n",&p);//&p=指针p的地址 
	printf("*p=%d\n",*p);//*p=1
	printf("*q=%p\n",*q);// *q存放的是i的地址 
	printf("**q=%d\n",**q);//**q=1

	exit(0);
}
