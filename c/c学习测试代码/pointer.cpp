#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i=1;
	int *p=&i;
	int **q=&p;//pָ��ָ��i�ĵ�ַ   pָ��ĵ�ַ�ö���ָ��**q���  
	
	printf("i=%d\n",i);
	printf("&i=%p\n",&i);//i�ĵ�ַ 
	printf("p=%p\n",p);//i�ĵ�ַ 
	printf("&p=%p\n",&p);//&p=ָ��p�ĵ�ַ 
	printf("*p=%d\n",*p);//*p=1
	printf("*q=%p\n",*q);// *q��ŵ���i�ĵ�ַ 
	printf("**q=%d\n",**q);//**q=1

	exit(0);
}
