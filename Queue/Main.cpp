#include<iostream>
#include<stdlib.h>
#include"Queue_Class.h"
#include"Customer.h"
using namespace std;
int main()
{
    Customer c1("zhangsan",20);
	Customer c2("lisi",30);
	Customer c3("xiaohuang",40);
	Customer c5("xiaoli",50);
	Customer c6("xiaoliang",60);
	Customer c7("xiaoman",70);
	Customer c4;
	MyQueue *p=new MyQueue(4);  //¹Ø¼ü
	p->EnQueue(c1);
	p->EnQueue(c2);
	p->EnQueue(c3);
	p->DeQueue(c4);
	c4.printInfo();
	p->EnQueue(c5);
	p->EnQueue(c6);
	p->EnQueue(c7);
//	p->EnQueue(4);
//	p->EnQueue(5);
//	p->DeQueue(t);
//	p->EnQueue(5);
//	cout<<"dequeue:"<<t<<endl;
//	cout<<p->QueueLength()<<endl;
//	cout<<endl;
	p->QueueTraverse();
	p->~MyQueue();
	p->QueueTraverse();
	return 0;
}