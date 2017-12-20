#ifndef COORDINATE_H
#define COORDINATE_H

#include<ostream>
using namespace std;

class Coordinate{
    friend ostream &operator<<(ostream &out,Coordinate &coor);
public:
    Coordinate(int x=0,int y=0);
    void show();
    bool operator==(Coordinate &coor);
private:
    int m_x,m_y;
};

#endif // COORDINATE_H_INCLUDED
