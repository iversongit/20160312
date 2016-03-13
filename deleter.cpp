 ///
 /// @file    deleter.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-13 06:30:27
 ///
 
#include <iostream>
#include <memory>
using std::cout;
using std::endl;

struct Fcloser{
	void operator()(FILE *fp)
	{
		if(fp){
			cout<<"close file pointer"<<endl;
			fclose(fp);
		}
	}
};

int main(void){
	std::unique_ptr<FILE,Fcloser> deFile(fopen("test.dat","r"),
	Fcloser());
	return 0;
}
