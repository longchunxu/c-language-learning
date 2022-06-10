#include<stdio.h>
#include<stdlib.h>
int main()
{
	char a[]="aead cv v d 	";
	int count=0,flag=0;
	for(int i=0;a[i]!='\0';i++)
	{
			if(a[i]==' ')
			flag=0;
			else
			   if(flag==0)
			   {
			   	count++;
			   	flag=1;
			   }
			
	}	
	 printf("%d\n",count);
	 
	 exit(0);
}
