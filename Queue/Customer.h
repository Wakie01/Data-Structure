#ifndef CUSTOMER_H  //避免类重复定义  注意是_H
#define CUSTOMER_H   //同上
#include<string>
using namespace std;
class Customer{
private:
	string name;
	int age;
public:
	Customer(string name1=" ",int age1=0);
	void printInfo() const;
};

#endif  //同上