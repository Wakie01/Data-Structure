#ifndef CUSTOMER_H  //�������ظ�����  ע����_H
#define CUSTOMER_H   //ͬ��
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

#endif  //ͬ��