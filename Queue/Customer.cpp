#include<iostream>
#include"Customer.h"
using namespace std;
Customer::Customer(string name1,int age1)
{
	name=name1;
	age=age1;
}
void Customer::printInfo() const
{
	cout<<"������"<<name<<endl;
	cout<<"���䣺"<<age<<endl;
	cout<<endl;
}
