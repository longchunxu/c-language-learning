#include<stdio.h>
#include<stdlib.h>
void fun( char b[])//禁止对b做出修改 只读权限 
{	int i=0;
	if(b==NULL)
	return ;
//	while(b[i]!=0)//字符串结尾标识 0/0x00/'\0'   '\0'对应的ascii码值0   
//	{
//	printf("b[%d]=%c\n",i,b[i]);
//	i++;
//	}
//	printf("len=%d",i);
//	i=0;
	while(b[i]!=0)//字符串结尾标识 0/0x00/'\0'   '\0'对应的ascii码值0   
	{
	printf("b[%d]=%c\n",i,b[i]);
	i++;
	}	
	
}

int main()
{
	 char a[10]="abcdefghi";//留一位给字符串结尾标识a[9] ='\0' 
	fun(a);
	exit(0);
}
