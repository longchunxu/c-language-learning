#include <stdio.h>
#include <stdlib.h>
 
int main()
{
	int a[2][3]={{1,2,3},{4,5,6}};
	printf("%d\n",sizeof(a)/sizeof(a[0][0]));//代表单个元素的大小  求得多少个元素 
	printf("%d\n",sizeof(a)/sizeof(a[0]));//代表的行地址   求得多少行 
	printf("%p\n",a[0][0]);
	printf("%p\n",a[0][0]+1);
	printf("%p\n",a);
	printf("%p\n",a+1);
}
