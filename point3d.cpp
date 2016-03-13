 ///
 /// @file    point3d.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-13 07:16:07
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Point{
	public:
		Point(int x=0, int y=0)
		:_x(x)
		,_y(y)
		{
			cout<<"Point(int,int)"<<endl;
		}

		void disp(){
			cout<<"("<<_x<<","<<_y<<")"<<endl;
		}

		int getX() const{
			return _x;
		}

		int getY() const{
			return _y;
		}

	private:
		int _x;
		int _y;
};

class Point3d : public Point
{
	public:
		Point3d(int x,int y,int z)
		:Point(x,y)
		,_z(z)
		{
			cout<<"Point(int,int,int)"<<endl;
		}

		void display(){
		//在子类内部访问父类的私有成员是不允许的
			cout<<"("<<getX()<<","<<getY()<<","<<_z<<")"<<endl;
		}

		int add(){
			return getX() + getY() + _z;
		}

	private:
		int _z;
};

int main(void){
	Point p(6,6);
	p.disp();
	cout<<"-------------------"<<endl;
	Point3d p1(8,8,8);
	p1.display();
	cout<<p1.add()<<endl;
	return 0;
}
