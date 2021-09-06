#include<iostream>
using namespace std;
#include<string>

class caculator_interface{
public:
	int num1;
	int num2;

public:
	caculator_interface()
	{
		num1=3;num2=4;
	}
	virtual void getResult()
	{
		num1=1;num2=2;
	}

};
class add:public caculator_interface{

public:
	void getResult()
	{

		cout<<"num1+num2="<<num1+num2<<endl;
	}

};
class sub:public caculator_interface{
public:
	void getResult()
	{
		cout<<"num1-num2="<<num1-num2<<endl;
	}
};
int main()
{
	caculator_interface *c=new add;
	c->getResult();
	c=new sub;
	c->getResult();
	delete(c);
	return 0;
}