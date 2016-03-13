 ///
 /// @file    multiDerived2.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-13 08:33:22
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class A{
public:
	A(int x=0):_x(x)
	{
		cout<<"A(int)"<<endl;
	}

	void setX(int x)
	{
		_x = x;
	}

	void display(){
		cout<<"_x ="<<_x<<endl;		
	}
private:
	int _x;

};

//虚继承的方式解决二义性的问题
class C : virtual public A
{

};

class B : virtual public A
{

};

class D : public B,public C
{

};

int main(void){
	D d;
	d.setX(88);
	d.display();
	return 0;
}

