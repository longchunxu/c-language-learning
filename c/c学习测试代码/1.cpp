#include<stdio.h>
#include<stdlib.h>
void fun(char **a,int len)

{
	for(int i=0;i<len;i++)
	{
	//a[i]="111";
	printf("%s\n",a[i]);
	
	}
	
}

int main(void)
{

	char a[3][20]={"aaa","bbbb","ccc"};
	for(int i=0;i<sizeof(a)/sizeof(*a);i++)
	{
	printf("%x#\n",a[i][i]);
	}
	
	exit (0);
}
