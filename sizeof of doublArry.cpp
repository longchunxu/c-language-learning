#include <stdio.h>
#include <stdlib.h>
 
int main()
{
	int a[2][3]={{1,2,3},{4,5,6}};
	printf("%d\n",sizeof(a)/sizeof(a[0][0]));//������Ԫ�صĴ�С  ��ö��ٸ�Ԫ�� 
	printf("%d\n",sizeof(a)/sizeof(a[0]));//������е�ַ   ��ö����� 
	printf("%p\n",a[0][0]);
	printf("%p\n",a[0][0]+1);
	printf("%p\n",a);
	printf("%p\n",a+1);
}
