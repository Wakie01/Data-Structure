#include<iostream>
#include"MyStack.h"
using namespace std;
int main()
{
	MyStack * stack=new MyStack(5);

    coordinate elem;
    elem=stack->pop(elem);
	elem.printCoordinate();
	cout<<endl;

	stack->push(coordinate(1,2));  //��
	stack->push(coordinate(3,2));
	stack->push(coordinate(4,2));
	stack->push(coordinate(5,2));
	stack->push(coordinate(6,2));  //��

    stack->stackTraverse(true);

    

	cout<<stack->stackLength()<<endl;

	if(stack->stackEmpty())
		cout<<"ջΪ��"<<endl;
	
	if(stack->stackFull())
		cout<<"ջΪ��"<<endl;










    delete stack;
	stack=NULL;

	system("pause"); //��ʾ�밴���������
	return 0;
}