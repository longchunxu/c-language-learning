#include<stdio.h>
#include<stdlib.h>
struct stu{
	stu *next;
	int date;
	
};
void printf_stu(stu *p){
	
	while(p->next!=NULL)
	{
		printf("p->date=%d\n",p->date);
		p=p->next;// ��ӡ�����һ���ڵ�֮ǰ��λ�� 
		
	}
	printf("p->date=%d\n",p->date);///��ӡ���һ���ڵ� 
	
}
int main() 
{
	printf("111\n");
	stu *p=NULL;//����ָ��ͷ����ָ�� 
	stu *m=NULL,*q=NULL;
	p=( stu *)malloc(sizeof(stu));//Ϊָ�����ռ� 
	if(p==NULL)
	{
		printf("malloc false\n");
	}
	p->date=0; 
	q=p->next;
	q->date=1;
	m=q->next;
	m->date=2;
	m->next=NULL;
	printf_stu(p); 

//	printf("p->date=%d,q->date=%d\n",p->date,q->date);
	
	
	
	exit(0);
}
