#include<iostream>
#include"coordinate.h"
using namespace std;
coordinate::coordinate(int x1,int y1)//这里不必跟头文件的一样赋初值
{
	x=x1;
	y=y1;
}
void coordinate::printCoordinate()
{
	cout<<"("<<x<<","<<y<<")"<<endl;
}