 ///
 /// @file    point.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-13 06:44:30
 ///
 
#include <iostream>
#include <memory>
using std::cout;
using std::endl;

class Point : public std::enable_shared_from_this<Point>
{
	public:
		Point(int x=0, int y=0)
		:_x(x)
		,_y(y)
		{
			cout<<"Point(int,int)"<<endl;
		}

		Point(const Point & rhs)
		:_x(rhs._x)
		,_y(rhs._y)
		{
			cout<<"Point(const Point &)"<<endl;
		}

		std::shared_ptr<Point> add(const Point * rhs){
		/*如果是直接返回裸指针，会脱离shared_ptr的控制
		 *也会造成两次析构的问题，所以返回值应该是
		 *shared_ptr
		 */
			_x += rhs->_x;
			_y += rhs->_y;
		//类内部通过this指针返回shared_ptr对象
			return shared_from_this();
		}

		~Point(){
			cout<<"~Point()"<<endl;
		}
	private:
		int _x;
		int _y;
};

int test(void){
	Point *p = new Point(6,6);
/*不要把原生的裸指针交给不同的shared_ptr托管
 *该对象会被析构两次
 */
	std::shared_ptr<Point> p1(p);
//	std::shared_ptr<Point> p2(p);
	std::shared_ptr<Point> p3(new Point(8,8));
/*对于reset函数的误用，p会被析构两次*/
	p3.reset(p1.get());
	return 0;
}

int main(void){
	Point *p = new Point(6,6);
	std::shared_ptr<Point> p1(p);
	std::shared_ptr<Point> p2(new Point(8,8));
	p2->add(p1.get());
	return 0;
}
