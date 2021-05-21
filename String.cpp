#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char a[]="hello111";
	char b[]="hello2";
	char *c; 
	printf("%d\n",strlen(a));//求字符串长度 不带'\0' 
	c=strcpy(a,b);//返回值为 char *  把b中的字符串覆盖到a中 
	printf("%s\n",c);
	
	c=strncpy(a,b,3);
	a[3]='\0'; //给字符串添加结尾 \0   不加会出现输出错误 
	printf("%s\n",c);
	
	c=strcat(a,b);
	printf("c=%s\n",c);
	c=strncat(a,b,2);
	printf("c2=%s\n",c);//在b字符串中取2位追加到a字符串中 
	
	int n;// 比较a与b的 ascii码值(a-b) n=0字符串相等 n>0 a>b    n<0  a<b
	char x[]="CCC", y[]="BBB";
	n=strcmp(x,y);
	printf("%d\n",n);//n=x相等  n=-1 a<b  n=1 a>b
	
	exit(0); 
	
}
