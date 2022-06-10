#include<stdio.h>

int play(int a)
{
	printf("play %d\n",a);
	return 0;
}

int  jump(int a)
{
	printf("jump %d\n",a);
	return 0;
}
int polymorphic(int (*pfun)(int),int a)
{
	printf("enter polymorphic\n");
	pfun(a);
	return 0;
}
int main(int argc, char const *argv[])
{
	polymorphic(play,1);
	polymorphic(jump,2);
	return 0;
}