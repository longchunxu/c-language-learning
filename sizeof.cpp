#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a;
	char *b;
	float c;
	double *d;
	printf("sizeof(a)=%d\n",sizeof(a));
	printf("sizeof(*b)=%d\n",sizeof(*b));
	printf("sizeof(c)=%d\n",sizeof(c));
	printf("sizeof(*d+1)=%d\n",sizeof(*d+1));

	exit(0);
}