#include<stdio.h>
#include<stdlib.h>

void Sort(int *a)
{
	
	printf("a=%d",sizeof(a));
	
	
//		for(int i=0;i<sizeof(a)/sizeof(a[0])-1;i++)
//		for(int j=0;j<sizeof(a)/sizeof(a[0])-i-1;j++)
//		{
//			int temp;
//			if(a[j+1]<a[j])	
//			{
//				temp=a[j];
//				a[j]=a[j+1];
//				a[j+1]=temp;
//			}
//			
//				
//			
//		}	
//		for(int i=0;i<sizeof(a)/sizeof(a[0]);i++)
//		printf("a[%d]=%d\n",i,a[i]);
//	
//	

	
} 


int main()
{
	int arr[8]={7,4,0,9,2,1,4,3};	
	printf("arr=%d\n",sizeof(arr));
	
	Sort(arr);



	exit(0);
}
