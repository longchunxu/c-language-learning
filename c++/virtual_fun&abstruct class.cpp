#include<iostream>
using namespace std;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
class base{
//抽象类子类要实现接口
public:
	virtual void add()=0;//纯虚函数 子类必须重写
	virtual void play()=0;//纯虚函数 子类必须重写

};
class son :public base {

public:
	void add()
	{
		cout<<"add is invoked"<<endl;
	}
	void play()
	{

		cout<<"play is invoked"<<endl;
	}
};
int main(int argc, char const *argv[])
{

	son s;
	base &b=s;
	s.add();
	s.play();

	//base *b=new son;
	//b->add();
	//b->play();
	return 0;
}
