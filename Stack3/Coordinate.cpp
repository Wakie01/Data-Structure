#include<iostream>
#include"coordinate.h"
using std::endl; 
using std::cout;
using std::ostream;  //vc++6.0 ��һ��bug��can't using namespace std;
coordinate::coordinate(int x1,int y1)//���ﲻ�ظ�ͷ�ļ���һ������ֵ
{
	x=x1;
	y=y1;
}
void coordinate::printCoordinate()
{
	cout<<"("<<x<<","<<y<<")"<<endl;
}
ostream &operator<<(ostream &out,coordinate &coor)  //out��coor���Ƕ���
{
	out<<"("<<coor.x<<","<<coor.y<<")"<<endl; //��������ģʽ
	return out;
}