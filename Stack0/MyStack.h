#ifndef MYSTACK_H
#define MYSTACK_H
#include"Coordinate.h"
class MyStack{
public:
	MyStack(int size);
	~MyStack();
	bool stackEmpty();
	bool stackFull();
	void clearStack();
	int stackLength();
	bool push(coordinate elem);
	bool pop(coordinate &elem);
	void stackTraverse(bool isFromButtom);
private:
	coordinate *m_pBuffer;    //栈空间指针
	int m_iSize;      //栈容量
	int m_iTop;      //栈顶，栈中元素个数
};

#endif