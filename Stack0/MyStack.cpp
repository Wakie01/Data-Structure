#include<iostream>
#include"MyStack.h"
using namespace std;
MyStack::MyStack(int size)
{
	m_iSize=size;
	m_pBuffer=new coordinate[m_iSize];
    m_iTop=0;
}
MyStack::~MyStack()
{
	delete [] m_pBuffer;
	m_pBuffer=NULL;
}
bool MyStack::stackEmpty()
{
	if(0==m_iTop) return true;
	else return false;
}
bool MyStack::stackFull()
{
	if(m_iTop==m_iSize)   //or m_Top>=m_iSize
		return true;
	else return false;
}
int MyStack::stackLength()
{
	return m_iTop;
}
bool MyStack::push(coordinate elem)
{
	if(stackFull()) return false;
	else 
	{
		m_pBuffer[m_iTop]=elem;  //调用默认的拷贝函数
		m_iTop++;
	    return true;
	}
}
bool MyStack::pop(coordinate &elem)
{
	if(stackEmpty()) return false;
	else
	{
		elem=m_pBuffer[--m_iTop];
		return true;
	}
}
/*char MyStack::pop(char &elem)
{
	if(stackEmpty())
		throw 1;  //抛出异常
	else
	{
		elem=m_pBuffer[--m_iTop];
		return elem;
	}
}*/
void MyStack::stackTraverse(bool isFromButtom)
{
	int i;
	if(isFromButtom)
	{
		for(i=0;i<m_iTop;i++)
			//cout<<m_pBuffer[i]<<"  "; 这里可以定义运算符重载函数，
			m_pBuffer[i].printCoordinate();
	}
	else
	{
		for(i=m_iTop-1;i>=0;i--)
		    //cout<<m_pBuffer[i]<<"  ";
			m_pBuffer[i].printCoordinate();
	}
}