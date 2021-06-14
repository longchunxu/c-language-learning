#include<stdio.h>
#include<stdio.h>
void  func(int *p,int n)
{
	int a[n];
	 int k=n;
	for(int i=0;i<n;i++)
	{
		a[i]=p[i];		
	}
	for(int i=0;n>0;n--)
	{
		p[i]=a[n-1];
		i++;
	}

}

int main()
{	
	int a[]={1,2,5,10,11,8,9};
	int *b=NULL;
	func(a,sizeof(a)/sizeof(*a));	
	for(int j=0;j<sizeof(a)/sizeof(*a);j++)
	{
		printf("a[%d]=%d\n",j,a[j]);
	}
}
