#include<stdio.h>

struct birthday{
	int year;
	int month;
	int day;
};
struct student{
	int name;
	int sex;
	int num;
//	birthday born;
};

int mian()
{
	struct	student s1={1,2,3};
	printf("name=%s sex=%s num=%s %d-%d-%d",s1.name,s1.sex,s1.num); 
//	printf("name=%s sex=%s num=%s %d-%d-%d",s1.name,s1.sex,s1.num,s1.born.year,s1.born.month,s1.born.day); 
	
return 0;
}