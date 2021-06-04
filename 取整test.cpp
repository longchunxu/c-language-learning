#include<stdio.h> 
#include<stdlib.h>
void Get_Integer(float a[],int len)
{
	int dec;
		float decimal;
		float *array;
		array=a;
		int ret[len];
		for(int i=0;i<len;i++)
		{
		dec=(int)array[i];
		decimal=array[i]-dec;
		if(decimal>=0.5)
		ret[i]=dec+1;
		else
		ret[i]=dec; 
		printf("dec=%d,decimal=%f\n",dec,decimal);
		}
		
		for(int i=0;i<len;i++)
			{
			printf("-------ret[%d]=%d-----\n",i,ret[i]);
			}
	
}
int main()
{
	float array[]={1.2,3.6,4.7,8.9,5.6,5.1,5.9,10.5,17.45,19.7};
    Get_Integer(array,sizeof(array)/sizeof(*array));
	exit(0);
}
