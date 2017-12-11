#include<iostream>
#include"stdlib.h"
#include"MyStack.h"
#include"Coordinate.h"
using namespace std;

#define BINARY 2
#define OCTONARY 8
#define HEXADECIMAL 16

int main()
{
	MyStack<int> * stack=new MyStack<int>(30); 
    int H=1348;
	int mod=0;
	char num[]="0123456789ABCDE";
	while(H)
	{
		mod=H%HEXADECIMAL;
		stack->push(mod);
		H=H/HEXADECIMAL;
	}
//	stack->stackTraverse(false);

	int elem=0;
	while(!stack->stackEmpty())
	{
		stack->pop(elem);  //false:elem=stack->pop(elem);
		cout<<num[elem];
	}

    delete stack;
	stack=NULL;

	system("pause"); //显示请按任意键继续
	return 0;
}