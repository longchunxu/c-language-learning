#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char *name[]={"mmm","aaa","ddd","ccc"};
	char *temp;
	for (int i=0;i<4-1;i++)
	
	{
		int min=i;
		for(int j=i+1;j<4;j++)
		
		{
	//	printf("%d\n",strcmp(name[min],name[j]));	
			if(strcmp(name[min],name[j])>0)
			min=j;
		}
		if(min!=i)
		{
			temp=name[min];
			name[min]=name[i];
			name[i ]=temp;
		}
	}
	
	for (int i=0;i<sizeof(name)/sizeof(*name);i++)
	printf("%s\n",name[i]);
	
 } 
