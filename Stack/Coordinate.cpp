#include<iostream>
#include"coordinate.h"
using namespace std;
coordinate::coordinate(int x1,int y1)//���ﲻ�ظ�ͷ�ļ���һ������ֵ
{
	x=x1;
	y=y1;
}
void coordinate::printCoordinate()
{
	cout<<"("<<x<<","<<y<<")"<<endl;
}