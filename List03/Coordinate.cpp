#include<iostream>
#include"Coordinate.h"
using namespace std;

Coordinate::Coordinate(int x,int y)
{
    m_x=x;
    m_y=y;
}
void Coordinate::show()
{
    cout<<"("<<m_x<<","<<m_y<<")"<<endl;
    cout<<endl;
}
ostream &operator<<(ostream &out,Coordinate &coor)
{
    out<<"("<<coor.m_x<<","<<coor.m_y<<")"<<endl;
    return out;
}
bool Coordinate::operator==(Coordinate &coor)
{
    if(this->m_x==coor.m_x&&this->m_y==coor.m_y)
        return true;
    else return false;
}
