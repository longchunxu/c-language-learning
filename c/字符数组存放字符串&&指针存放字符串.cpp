#include<stdio.h>
#include<stdlib.h>
//ѡ������ 
int main()
{
	int a[5]={3,2,8,5,6};

	int temp;
	for(int i=0;i<sizeof(a)/sizeof(*a)-1;i++)
	{
		int min=i;//ÿ�αȽϺ� ��ѭ�����õ�һ��Ϊ��С�� 
		for(int j=i+1;j<sizeof(a)/sizeof(*a);j++)
		{
			if(a[min]>a[j]) //�ҵ�Ŀǰ��Сֵ
			min=j;//�o���Сֵ
		}
		if(i!=min)//��ѭ����ɱȽϺ� ���������Сֵ 
		{
			temp=a[i];
			a[i]=a[min];
			a[min]=temp;
			
		}
		
	 } 
	 for(int i=0;i<sizeof(a)/sizeof(*a);i++)
	 printf("%d\n",a[i]); 
	
	exit(0);
 } 
