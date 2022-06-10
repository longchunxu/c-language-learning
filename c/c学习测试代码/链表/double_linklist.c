#include<stdio.h>
#include<stdlib.h>
typedef struct double_linklist
{
	struct double_linklist *pre,*next;
	int data;

}linklist;



int main(int argc,char *argv[])
{

	linklist *head=malloc(sizeof(linklist));
	head->data=0;
	linklist *first=malloc(sizeof(linklist));
	head->next=first;
	first->pre=head;

	head->next->data=10;
	printf("first->data:%d,head->data:%d\n",first->data,head->data);
	first->pre->data=20;
	printf("first->data:%d,head->data:%d\n",first->data,head->data);
	exit(0);
}