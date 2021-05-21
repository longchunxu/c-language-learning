#include<stdio.h>
#include<stdlib.h>
struct birthday{
	int year;
	int month;
	int day;
};
struct student{
	char *name;
	char *sex;
	char *num;
	birthday born;
};

int main()
{
	student s1={"lcx","male","15215083989",{1997,3,26}};
	printf("name=%s sex=%s num=%s %d-%d-%d\n",s1.name,s1.sex,s1.num,s1.born.year,s1.born.month,s1.born.day); 
	student *p=&s1;
	
	
	printf("%s\n",(*p).name);
	exit(0);
}
