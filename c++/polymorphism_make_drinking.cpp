#include<iostream>
using namespace std;
class make{

public:
	virtual void addWater()=0;
	virtual void pour()=0;
	virtual void warmWater()=0;
	virtual void pourCup()=0;
	void makeDrinking()
	{
		addWater();
		pour();
		warmWater();
		pourCup();
	}

};
class tea: public make{

public:
	virtual void addWater()
	{
		cout<<"tea addWater()"<<endl;
	}
	virtual void pour()
	{
		cout<<"tea pour()"<<endl;
	}
	virtual void warmWater()
	{
		cout<<"tea warmWater()"<<endl;
	}
	virtual void pourCup()
	{
		cout<<"tea teapourCup()"<<endl;
	}

};
class coffee: public make{

public:
	virtual void addWater()
	{
		cout<<"coffee addWater()"<<endl;
	}
	virtual void pour()
	{
		cout<<"coffee pour()"<<endl;
	}
	virtual void warmWater()
	{
		cout<<"coffee warmWater()"<<endl;
	}
	virtual void pourCup()
	{
		cout<<"coffee teapourCup()"<<endl;
	}

};
int main(int argc, char const *argv[])
{
	make *t=new tea;
	t->makeDrinking();
	t=new coffee;
	cout<<endl;
	t->makeDrinking();
	return 0;
}