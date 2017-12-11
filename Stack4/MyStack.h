#ifndef MYSTACK_H
#define MYSTACK_H
#include<iostream>
//#include"Coordinate.h"  //����һ��ͨ�õ�ģ�壬so���ذ������ļ�
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
	T *m_pBuffer;    //ջ�ռ�ָ��
	int m_iSize;      //ջ����
	int m_iTop;      //ջ����ջ��Ԫ�ظ���
};


/*�еı�������֧��ģ���h�ļ���cpp�ļ��ֿ�����*/


template<typename T>  //ÿ����Ա����ǰ��Ҫ
MyStack<T>::MyStack(int size) //ÿ�������󶼼�<T>
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
		m_pBuffer[m_iTop]=elem;  //����Ĭ�ϵĿ�������
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
		throw 1;  //�׳��쳣
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
			cout<<m_pBuffer[i];  //������Զ�����������غ�����
			//m_pBuffer[i].printCoordinate(); //��������ģ��ʱ�Ͳ�ͨ����
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