#include<stdio.h>#include<stdlib.h>char* call(char *a){	static char buf[40];	sprintf(buf,"call is invoked,%s",a);//	printf("%s\n",buf);	return buf;}struct card{	char *cname;	int cid;	int (*call)(char *a);};struct student{		char *name;	struct card *scard;	};int main(int argc,char **argv){		struct card *p_scard=(struct card *)malloc(sizeof(struct card));	struct card scard={		.cname="lcx",		.cid=99,		.call=call	};	p_scard=&scard;	struct student stu={		.name="lcx",		.scard=p_scard	};	printf("%s,%d,%s\n",stu.scard->cname,stu.scard->cid,stu.scard->call("lcx"));	//stu.scard->call("lcx");	exit(0);}