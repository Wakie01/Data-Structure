#ifndef COORDINATE_H
#define COORDINATE_H
#include<ostream>
using std::endl; 
using std::cout;
using std::ostream;

class coordinate{
	friend ostream &operator<<(ostream & out,coordinate & coor);  //��Ԫ�������ǳ�Ա������so����ʱ���ؼ�::
public:
	coordinate(int x1=0,int y1=0);//����Ҫ����ֵ
	void printCoordinate();
private:
	int x,y;
};



#endif