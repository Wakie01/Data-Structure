#include<iostream>
#include"Customer.h"
using namespace std;
class MyQueue{
public:
	MyQueue(int queueCapacity);   //创建队列	
	virtual ~MyQueue();             // 销毁队列
	void ClearQueue();              //清空队列
	int QueueLength() const;         //队列长度
	bool QueueEmpty() const;            // 队列判空
    bool EnQueue(Customer element);       //新元素入队
	bool DeQueue(Customer &element);        //首元素出队
    void QueueTraverse();       //遍历队列
private:
	Customer *m_pQueue;         //队列数组指针  关键
	int m_iQueueLen;      //队列元素个数
	int m_iQueueCapacity;    //队列数组内容
	int m_iHead;
	int m_iTail;
};
