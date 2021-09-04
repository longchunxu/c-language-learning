#include<stdio.h>
#include<stdlib.h>
#define LOG(x) log##x()//#使后面的字符字符串化，A##B链接两个字符串
 
void logA(){
    printf("log func A \n");
}
 
void logB(){
    printf("log func B\n");
}
int main(int argc,char *argv[])
{	
	//char* tmp;
//	tmp=Conn("abcd","1234");
//	printf("%s\n",tmp );
	LOG(A);//logA();
	exit(0);
}