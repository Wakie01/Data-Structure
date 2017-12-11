#ifndef COORDINATE_H
#define COORDINATE_H
#include<ostream>
using std::endl; 
using std::cout;
using std::ostream;

class coordinate{
	friend ostream &operator<<(ostream & out,coordinate & coor);  //友元函数不是成员函数，so定义时不必加::
public:
	coordinate(int x1=0,int y1=0);//这里要赋初值
	void printCoordinate();
private:
	int x,y;
};



#endif