#include<stdio.h>
#include<stdlib.h>

void Sort(int *a,int len)
{
		for(int i=0;i<len-1;i++)
		for(int j=0;j<len-i-1;j++)
		{
			int temp;
			if(a[j+1]<a[j])	
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}		
		}	
		for(int i=0;i<len;i++)
		printf("a[%d]=%d\n",i,a[i]);
} 


int main(void)
{
	int arr[8]={7,4,0,9,2,1,4,3};	
	Sort(arr,sizeof(arr)/sizeof(int));
	exit(0);
}
