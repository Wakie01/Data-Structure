#include"Contract.h"
#include<iostream>
using namespace std;

Contract &Contract::operator=(Contract &contract)
{
    this->name=contract.name;
    this->phone=contract.phone;
    return *this;
}

bool Contract::operator==(Contract &contract)
{
    if(this->name==contract.name&&this->phone==contract.phone)
        return true;
    else return false;
}

ostream & operator<<(ostream &out,Contract &contract)
{
    out<<contract.name<<"---------------"<<contract.phone<<endl;
    return out;
}
