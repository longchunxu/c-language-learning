#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char a[]="hello111";
	char b[]="hello2";
	char *c; 
	printf("%d\n",strlen(a));//���ַ������� ����'\0' 
	c=strcpy(a,b);//����ֵΪ char *  ��b�е��ַ������ǵ�a�� 
	printf("%s\n",c);
	
	c=strncpy(a,b,3);
	a[3]='\0'; //���ַ�����ӽ�β \0   ���ӻ����������� 
	printf("%s\n",c);
	
	c=strcat(a,b);
	printf("c=%s\n",c);
	c=strncat(a,b,2);
	printf("c2=%s\n",c);//��b�ַ�����ȡ2λ׷�ӵ�a�ַ����� 
	
	int n;// �Ƚ�a��b�� ascii��ֵ(a-b) n=0�ַ������ n>0 a>b    n<0  a<b
	char x[]="CCC", y[]="BBB";
	n=strcmp(x,y);
	printf("%d\n",n);//n=x���  n=-1 a<b  n=1 a>b
	
	exit(0); 
	
}
