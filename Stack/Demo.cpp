#include<iostream>
#include"MyStack.h"
using namespace std;
int main()
{
	MyStack * stack=new MyStack(5);

    char elem=0;
	stack->pop(elem);

	stack->push('h');  //��
	stack->push('e');
	stack->push('l');
	stack->push('l');
	stack->push('o');  //��

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