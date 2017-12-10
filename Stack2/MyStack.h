#ifndef MYSTACK_H
#define MYSTACK_H
#include<iostream>
//#include"Coordinate.h"  //已是一个通用的模板，so不必包含此文件
using namespace std;

template<typename T>
class MyStack{
public:
	MyStack(int size);
	~MyStack();
	bool stackEmpty();
	bool stackFull();
	void clearStack();
	int stackLength();
	bool push(T elem);
	bool pop(T &elem);
	void stackTraverse(bool isFromButtom);
private:
	T *m_pBuffer;    //栈空间指针
	int m_iSize;      //栈容量
	int m_iTop;      //栈顶，栈中元素个数
};


/*有的编译器不支持模板的h文件与cpp文件分开编译*/


template<typename T>  //每个成员函数前都要
MyStack<T>::MyStack(int size) //每个类名后都加<T>
{
	m_iSize=size;
	m_pBuffer=new T[m_iSize];
    m_iTop=0;
}
template<typename T>
MyStack<T>::~MyStack()
{
	delete [] m_pBuffer;
	m_pBuffer=NULL;
}
template<typename T>
bool MyStack<T>::stackEmpty()
{
	if(0==m_iTop) return true;
	else return false;
}
template<typename T>
bool MyStack<T>::stackFull()
{
	if(m_iTop==m_iSize)   //or m_Top>=m_iSize
		return true;
	else return false;
}
template<typename T>
int MyStack<T>::stackLength()
{
	return m_iTop;
}
template<typename T>
bool MyStack<T>::push(T elem)
{
	if(stackFull()) return false;
	else 
	{
		m_pBuffer[m_iTop]=elem;  //调用默认的拷贝函数
		m_iTop++;
	    return true;
	}
}
template<typename T>
bool MyStack<T>::pop(T &elem)
{
	if(stackEmpty()) return false;
	else
	{
		elem=m_pBuffer[--m_iTop];
		return true;
	}
}
/*
template<typename T>
char MyStack<T>::pop(char &elem)
{
	if(stackEmpty())
		throw 1;  //抛出异常
	else
	{
		elem=m_pBuffer[--m_iTop];
		return elem;
	}
}*/
template<typename T>
void MyStack<T>::stackTraverse(bool isFromButtom)
{
	int i;
	if(isFromButtom)
	{
		for(i=0;i<m_iTop;i++)
			cout<<m_pBuffer[i];  //这里可以定义运算符重载函数，
			//m_pBuffer[i].printCoordinate(); //当构造类模板时就不通用了
	}
	else
	{
		for(i=m_iTop-1;i>=0;i--)
		    cout<<m_pBuffer[i];
			//m_pBuffer[i].printCoordinate();
	}
	cout<<endl;
}


#endif