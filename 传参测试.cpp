#include<stdio.h>
#include<stdlib.h>
void sort(int b[])
{
	
}

int main()
{
	 char a[255];
	a[0]='0';
	for(int i=0;i<255;i++)
	{
		a[i+1]=a[i]+1;
		printf("%c\n",a[i]);
	}
	printf("%s\n",a);
	exit(0);
}
