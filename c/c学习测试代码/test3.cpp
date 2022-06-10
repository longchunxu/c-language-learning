#include<stdio.h>
#include<stdlib.h>
void fun()
{
	static int i=0;
	i++;
	printf("%d",i);
}
int main()
{
	fun();
	fun();
	fun();
	fun();

	exit(0);
 } 
