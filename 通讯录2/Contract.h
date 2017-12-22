#ifndef CONTRACT_H_INCLUDED
#define CONTRACT_H_INCLUDED

#include<string>
#include<ostream>
using namespace std;

class Contract{
    friend ostream & operator<<(ostream &out,Contract &contract); //����:ostream������, out��ostream������
public:
    string name;
    string phone;
    Contract &operator=(Contract &contract); //����ֵ��Contract������
    bool operator==(Contract &contract);
};


#endif // CONTRACT_H_INCLUDED
