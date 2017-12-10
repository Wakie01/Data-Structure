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
	coordinate *m_pBuffer;    //ջ�ռ�ָ��
	int m_iSize;      //ջ����
	int m_iTop;      //ջ����ջ��Ԫ�ظ���
};

#endif