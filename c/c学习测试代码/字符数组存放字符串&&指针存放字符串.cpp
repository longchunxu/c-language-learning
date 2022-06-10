#include<stdio.h>
#include<stdlib.h>
//选择排序 
int main()
{
	int a[5]={3,2,8,5,6};

	int temp;
	for(int i=0;i<sizeof(a)/sizeof(*a)-1;i++)
	{
		int min=i;//每次比较后 外循环设置第一个为最小的 
		for(int j=i+1;j<sizeof(a)/sizeof(*a);j++)
		{
			if(a[min]>a[j]) //找到目前最小值
			min=j;//紀錄最小值
		}
		if(i!=min)//内循环完成比较后 交换最大最小值 
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
