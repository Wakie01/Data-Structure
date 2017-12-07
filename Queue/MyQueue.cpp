#include<iostream>
#include"Queue_Class.h"
#include"Customer.h"
using namespace std;
MyQueue::MyQueue(int queueCapacity)
{
	m_iQueueCapacity=queueCapacity;
	m_pQueue=new Customer[m_iQueueCapacity];  //关键
	m_iHead=0;
	m_iTail=0;
	m_iQueueLen=0;
}
MyQueue::~MyQueue()
{
	delete [] m_pQueue;  //释放内存的数组，所以加上[]，数组名称：m_pQueue
	m_pQueue=NULL;
}
void MyQueue::ClearQueue()
{
	m_iHead=0;
	m_iTail=0;
	m_iQueueLen=0;
}
bool MyQueue::QueueEmpty() const
{
	if(m_iQueueLen==0) return true;
	else return false;
	// return m_iQueueLen==0? true:false;
}
int MyQueue::QueueLength() const
{
	return m_iQueueLen;
}
bool MyQueue::EnQueue(Customer element)
{
	if(QueueLength()==m_iQueueCapacity) 
	{
		cout<<"full\n";
		return false;
	}
	else 
	{
		m_pQueue[m_iTail]=element;
		m_iTail++;
		m_iTail=m_iTail%m_iQueueCapacity;
		m_iQueueLen++;
		return true;
	}
}
bool MyQueue::DeQueue(Customer &element)
{
	if(QueueEmpty()) 
	{
		cout<<"empty\n";
		return false;
	}
	else 
	{
		element=m_pQueue[m_iHead];
		m_iHead++;
		m_iHead=m_iHead%m_iQueueCapacity;
		m_iQueueLen--;
		return true;
	}
}
void MyQueue::QueueTraverse()
{
	cout<<"Traverse\n";
	for(int i=m_iHead;i<m_iQueueLen+m_iHead;i++)
	{
		m_pQueue[i%m_iQueueCapacity].printInfo();
		cout<<"前面还有"<<i-m_iHead<<"人"<<endl;
		cout<<endl;
	}
}
		

