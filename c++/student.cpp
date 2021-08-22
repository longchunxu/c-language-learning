#include<iostream>
#include<string>
using namespace std;
class Student{
	public:	
		Student()//类实例化时使用 
		{
			cout<<"无参构造函数调用"<<endl; 
		}
		Student(string name,int id,int sex)
		{	cout<<"有参构造函数调用"<<endl; 
			this->name=name;
			this->id=id;
			this->sex=sex;
		}
		~Student()//不可以有参数 类销毁时调用 
		{
			
			cout<<"析构函数调用"<<endl; 
		}
		Student(const Student &p)//拷贝构造函数 传一个引用进来 
		{
		cout<<"拷贝构造函数调用"<<endl; 
		this->name=p.name;
		this->id=p.id;
		this->sex=p.sex;
		}

	public:
	///  	char *name;
	  	string name;
		int id;
		bool sex;
		void getName()
		{
			cout<<"name:"<<this->name<<endl;
		}
		void getId()
		{
			cout<<"id:"<<this->id<<endl;
		}
		void getSex()
		{
			cout<<"sex:"<<this->sex<<endl;
		}
		void setName(string name)
		{
			this->name=name;
		}


};
int main(int argc,char **argv)
{
	Student stu("test",9,1);
	Student stu2(stu);
//	Student stu;
//	stu.name="test";
//	stu.id=13;

	stu.getName();
	stu.getSex();
	stu.getId();
	stu.setName("changename");
	stu.getName();
	
	stu2.getName();
	stu2.getSex();
	stu2.getId();

	return 0;

}
