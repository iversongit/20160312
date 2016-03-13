 ///
 /// @file    multiDerived.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-13 07:53:13
 ///
 
#include <iostream>
using std::endl;
using std::cout;

class A{
	public:
		void show(){
			cout<<"A::show()"<<endl;
		}
};

class B{
	public:
		void show(){
			cout<<"B::show()"<<endl;
		}
};

class C : public A,public B
//对于继承而言，默认情况下就是private继承
{
	public:
		void display(){
			A::show();
		}

};

int main(void){
	C c;
	c.A::show();//防止二义性
	c.B::show();
	c.display();
	return 0;
}
