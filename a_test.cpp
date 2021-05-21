#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char a[]="hello";//字符数组 
	strcpy(a,"world");
	//  a="world"; a是数组首地址 是一个常量 不能够被赋值 
	printf("%s\n",a);
	
	char *p="hello2";
//	strcpy(p,"world");  p存放的是字符串常量的地址  字符串常量不可以被修改 不能用strcpy 覆盖*p里的字符串 
	p="world"; 
	printf("%s\n",*p);
	exit(0);
 } 
