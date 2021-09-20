#include<iostream>
using namespace std;
template<typename T>//声明一个模板告诉编译器后面紧更的代码 T 是一种 通用的数据类型。不要报错 
void test(T &a,T &b)
{
	int temp;
	temp =a;
	a=b;
	b=temp; 
	
}

int main(void)
{
	int a=1,b=2;
	//1.自动类型推导 
	test(a,b);
	cout<<"a="<<a<<endl;
	cout<<"b="<<b<<endl;
	//2.显示指定类型 
	test<int>(a,b);//指定 a b 的类型为 int型 
	cout<<"a="<<a<<endl;
	cout<<"b="<<b<<endl;
	return 0;
}
