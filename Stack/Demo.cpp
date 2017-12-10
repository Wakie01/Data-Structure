#include<iostream>
#include"stdlib.h"
#include"MyStack.h"
#include"Coordinate.h"
using namespace std;
int main()
{
	//MyStack<coordinate> * stack=new MyStack<coordinate>(5);  //定义类型

	MyStack<char> * stack=new MyStack<char>(5); 

    char elem;
	
    //elem=stack->pop(elem);
	//elem.printCoordinate();
	//cout<<endl;

	/*stack->push(coordinate(1,2));  //底
	stack->push(coordinate(3,2));
	stack->push(coordinate(4,2));
	stack->push(coordinate(5,2));
	stack->push(coordinate(6,2));  //顶
*/

	stack->push('h');
	stack->push('e');
	stack->push('l');
	stack->push('l');
	stack->push('o');


    stack->stackTraverse(true);

	elem=stack->pop(elem);
	cout<<elem<<endl;
    

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