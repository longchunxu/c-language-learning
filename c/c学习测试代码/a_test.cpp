#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char a[]="hello";//�ַ����� 
	strcpy(a,"world");
	//  a="world"; a�������׵�ַ ��һ������ ���ܹ�����ֵ 
	printf("%s\n",a);
	
	char *p="hello2";
//	strcpy(p,"world");  p��ŵ����ַ��������ĵ�ַ  �ַ������������Ա��޸� ������strcpy ����*p����ַ��� 
	p="world"; 
	printf("%s\n",*p);
	exit(0);
 } 
