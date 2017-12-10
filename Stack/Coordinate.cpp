#include<iostream>
#include"coordinate.h"
using std::endl; 
using std::cout;
using std::ostream;  //vc++6.0 的一个bug，can't using namespace std;
coordinate::coordinate(int x1,int y1)//这里不必跟头文件的一样赋初值
{
	x=x1;
	y=y1;
}
void coordinate::printCoordinate()
{
	cout<<"("<<x<<","<<y<<")"<<endl;
}
ostream &operator<<(ostream &out,coordinate &coor)  //out和coor都是对象
{
	out<<"("<<coor.x<<","<<coor.y<<")"<<endl; //输出对象的模式
	return out;
}