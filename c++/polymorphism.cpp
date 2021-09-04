#include <iostream>
using namespace std;
/*
*多态：1.有继承关系 2.子类重写父类的虚函数
*
*父类的指针 或者 引用 指向子类对象
*
*/
class animal{

public:
	virtual void speak()
	{
		cout<<"animal is speaking"<<endl;
	}

};
class cat:public animal{
public:
	void speak()//重写父类的虚函数
	{
		cout<<"cat is speaking"<<endl;
	}
};
void test(animal &a)//animal &a=c   实际上c来调用speak方法
{
	a.speak();
}
int main()

{	
	cat c;
	test(c);
	return 0;
}