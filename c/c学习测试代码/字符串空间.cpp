#include<stdio.h>
#include<stdlib.h>
void fun( char b[])//��ֹ��b�����޸� ֻ��Ȩ�� 
{	int i=0;
	if(b==NULL)
	return ;
//	while(b[i]!=0)//�ַ�����β��ʶ 0/0x00/'\0'   '\0'��Ӧ��ascii��ֵ0   
//	{
//	printf("b[%d]=%c\n",i,b[i]);
//	i++;
//	}
//	printf("len=%d",i);
//	i=0;
	while(b[i]!=0)//�ַ�����β��ʶ 0/0x00/'\0'   '\0'��Ӧ��ascii��ֵ0   
	{
	printf("b[%d]=%c\n",i,b[i]);
	i++;
	}	
	
}

int main()
{
	 char a[10]="abcdefghi";//��һλ���ַ�����β��ʶa[9] ='\0' 
	fun(a);
	exit(0);
}
