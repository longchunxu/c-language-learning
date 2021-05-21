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
		p=p->next;// 打印到最后一个节点之前的位置 
		
	}
	printf("p->date=%d\n",p->date);///打印最后一个节点 
	
}
int main() 
{
	printf("111\n");
	stu *p=NULL;//定义指向头结点的指针 
	stu *m=NULL,*q=NULL;
	p=( stu *)malloc(sizeof(stu));//为指针分配空间 
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
