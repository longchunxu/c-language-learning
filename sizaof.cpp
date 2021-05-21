#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a;
	char *b;
	float c;

	printf("sizeof(a)=%d\n",sizeof(a));
	printf("sizeof(*b)=%d\n",sizeof(*b));
	printf("sizeof(c)=%d\n",sizeof(c));

	exit(0);
}