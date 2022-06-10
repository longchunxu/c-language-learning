#include<stdio.h>
#include<stdlib.h>
#define M 2 
#define N 3
void change()
{
		int a[M][N]={1,2,3,4,5,6};//M 代表行 N代表列 
	int b[N][M]; 
	for ( int i=0;i<M;i++)
	{
		for(int j=0;j<N;j++)
		{
			printf("%d",a[i][j]);
			b[j][i]=a[i][j];
		}
		printf("\n");
	}
	
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			printf("%d",b[i][j]);
		}
		printf("\n");
	}
}
void max()
{	
int a[M][N]={1,2,9,4,5,6};
	int max,row,col;
	max=a[0][0];
	for(int i=0;i<M;i++)
	{
		for(int j=0;j<N;j++)
		{
			printf("%d",a[i][j]);
			if(a[i][j]>max)
			{
				max=a[i][j];
				row=i;
				col=j;
			}
		}
		printf("\n");
	}
	printf("max=%d row=%d col=%d",max,row,col);
	
}
void sum()
{
	int sum=0;
	int a[5][4]={{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
		for ( int i=0;i<4;i++)
	{
		for(int j=0;j<3;j++)
		{
			a[4][3]+=a[i][j];
			a[4][j]+=a[i][j];
			a[i][3]+=a[i][j]; 
		}
		
	}
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<4;j++)
		{
			printf("%4d",a[i][j]);
		}
		printf("\n");
	}
	

}
int main()
{	

	exit(0); 
} 
