#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxsize 20
struct student{
	int id;
	char name[maxsize];
	int age;

};
void stu_set(student *p)
{	student q;
	printf("����ѧ����id��name��age��");
	scanf("%d%s%d",&q.id,q.name,&q.age);
	p->id=q.id;
	strcpy(p->name,q.name);
	p->age=q.age;
//	printf("%d\n %s\n %d\n",p->id,p->name,p->age);
}
void stu_show(student *p)
{
		printf("%d\n %s\n %d\n",p->id,p->name,p->age);
}
void stu_changename(student *p)
{	student q;
	printf("����ѧ����name��");
	scanf("%s",q.name);//������q->name Ϊɶ���У� q��ָ��student��ָ�� 
	strcpy(p->name,q.name);//�������ַ��� Ҫ��strcpy�����ַ��� 
}
int main()
{
	struct student stu;
	stu_set(&stu);
	stu_show(&stu);
	stu_changename(&stu);
	stu_show(&stu);
	exit(0);
 } 
