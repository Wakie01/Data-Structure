#ifndef CONTRACT_H_INCLUDED
#define CONTRACT_H_INCLUDED

#include<string>
#include<ostream>
using namespace std;

class Contract{
    friend ostream & operator<<(ostream &out,Contract &contract); //类型:ostream的引用, out是ostream的引用
public:
    string name;
    string phone;
    Contract &operator=(Contract &contract); //返回值是Contract的引用
    bool operator==(Contract &contract);
};


#endif // CONTRACT_H_INCLUDED
