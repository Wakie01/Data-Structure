#include<iostream>
#include"MyStack.h"
using namespace std;
int main()
{
	MyStack * stack=new MyStack(5);

    char elem=0;
	stack->pop(elem);

	stack->push('h');  //底
	stack->push('e');
	stack->push('l');
	stack->push('l');
	stack->push('o');  //顶

    stack->stackTraverse(true);

    

	cout<<stack->stackLength()<<endl;

	if(stack->stackEmpty())
		cout<<"栈为空"<<endl;
	
	if(stack->stackFull())
		cout<<"栈为满"<<endl;










    delete stack;
	stack=NULL;

	system("pause"); //显示请按任意键继续
	return 0;
}