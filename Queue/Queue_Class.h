#include<iostream>
#include"Customer.h"
using namespace std;
class MyQueue{
public:
	MyQueue(int queueCapacity);   //��������	
	virtual ~MyQueue();             // ���ٶ���
	void ClearQueue();              //��ն���
	int QueueLength() const;         //���г���
	bool QueueEmpty() const;            // �����п�
    bool EnQueue(Customer element);       //��Ԫ�����
	bool DeQueue(Customer &element);        //��Ԫ�س���
    void QueueTraverse();       //��������
private:
	Customer *m_pQueue;         //��������ָ��  �ؼ�
	int m_iQueueLen;      //����Ԫ�ظ���
	int m_iQueueCapacity;    //������������
	int m_iHead;
	int m_iTail;
};
