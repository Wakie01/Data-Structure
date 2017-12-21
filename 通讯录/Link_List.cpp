#include<iostream>
#include"Link_List.h"
using namespace std;

Link_List::Link_List()
{
    m_pList=new Node;
  //  m_pList->data=0;  //这表示头结点的data无意义
    m_pList->next=NULL;
    m_iLength=0;
}

bool Link_List::ListEmpty()
{
    if(m_iLength==0) return true;
    else return false;
}

int Link_List::ListLength()
{
    return m_iLength;
}

void Link_List::ClearList()
{
    Node *currentNode=m_pList->next;
    while(currentNode!=NULL)
    {
        Node *temp=currentNode->next;
        delete currentNode;
        currentNode=temp;
    }
    m_pList->next=NULL;
    m_iLength=1;
}

Link_List::~Link_List()
{
    ClearList();
    delete m_pList;
    m_pList->next=NULL;
    m_iLength=0;
}

bool Link_List::ListInsertHead(Node *pNode)
{
    Node *temp=m_pList->next;
    Node *newNode=new Node;  //一定得从堆中申请内存  创建一个新结点
                                //内存分配要点http://blog.csdn.net/qingtingchen1987/article/details/7698415

    if(newNode==NULL) return false;  //可能申请失败
    newNode->data=pNode->data;
    newNode->next=temp;
    m_pList->next=newNode;   //插入结点关键是把整个链表连起来
    m_iLength++;
    return true;
}

bool Link_List::ListInsertTail(Node *pNode)
{
    Node *currentNode=m_pList;
    while(currentNode->next!=NULL)  //寻找尾结点
    {
        currentNode=currentNode->next;
    }
    Node *newNode=new Node; //创建一个新结点
    if(newNode==NULL) return false;
    newNode->data=pNode->data;
    newNode->next=NULL;
    currentNode->next=newNode;
    m_iLength++;
    return true;
}

bool Link_List::ListInsert(int i,Node *pNode) //i=0,就插入在head的后面
{
    if(i<0||i>m_iLength) return false; //先判断一下
    Node *currentNode=m_pList;
    for(int k=0;k<i;k++)   //寻找第i-1个的结点
    {
        currentNode=currentNode->next;
    }
    Node *newNode=new Node; //创建一个新结点
    if(newNode==NULL) return false;
    //以下三行一定要注意顺序问题
    /********************/
    newNode->data=pNode->data;
    newNode->next=currentNode->next;
    currentNode->next=newNode;
    /*******************/
    m_iLength++;
    return true;
}

bool Link_List::ListDelete(int i,Node *pNode)
{
    if(i<0||i>=m_iLength) return false;   //m_iLength表示已经插入链表中的元素个数，插入进来一个就是1，i是删除的位置，
                                          //也就是下标，最后一个元素的位置是i=m_iLength-1，i=m_iLength并不存在，因此不能取到
    Node *currentNode=m_pList;
    Node *currentNodeBefore=NULL;
    for(int k=0;k<=i;k++)   //寻找第i个和第i-1个的结点
    {
        currentNodeBefore=currentNode;
        currentNode=currentNode->next;
    }
    pNode->data=currentNode->data;
    currentNodeBefore->next=currentNode->next;
    delete currentNode;
    currentNode=NULL;
    m_iLength--;
    return true;
}

bool Link_List::GetElem(int i,Node *pNode)
{
    if(i<0||i>=m_iLength) return false;
    Node * currentNode=m_pList;
    for(int k=0;k<=i;k++)
    {
        currentNode=currentNode->next;
    }
    pNode->data=currentNode->data;
    return true;
}

int Link_List::LocateElem(Node *pNode)
{
    int count=0;  //0表示第一个位置
    Node * currentNode=m_pList;
    while(currentNode->next!=NULL)
    {
        currentNode=currentNode->next;  //头结点的data无意义 so 从下一个结点开始比
        if(currentNode->data==pNode->data)
            return count;   //这里只是返回第一个pNode这样结点的位置，有可能存在多个跟它相同的
        count++;
    }
    return -1;
}

bool Link_List::PriorElem(Node *pCurrentNode,Node *pPreNode)
{
    Node *currentNode=m_pList;
    Node *currentNodeBefore=NULL;
    while(currentNode->next!=NULL)
    {
        currentNodeBefore=currentNode;
        currentNode=currentNode->next; //从第二个结点开始
        if(currentNode->data==pCurrentNode->data)
        {
            if(currentNodeBefore==m_pList)  //头结点无意义
                return false;
            pPreNode->data=currentNodeBefore->data;
            return true;
        }
    }
    return false;
}

bool Link_List::NextElem(Node *pCurrentNode,Node *pNextNode)
{
    Node *currentNode=m_pList;
    while(currentNode->next!=NULL)
    {
        currentNode=currentNode->next;
        if(currentNode->data==pCurrentNode->data)  //data为其他类型时，就得重载==运算符
        {
            if(currentNode->next==NULL)  //尾结点没下一个结点
                return false;
            pNextNode->data=currentNode->next->data;   //重载=运算符
            return true;
        }
    }
    return false;
}

void Link_List::ListTraverse()
{
    Node *currentNode=m_pList;
    while(currentNode->next!=NULL)
    {
        currentNode=currentNode->next;
        currentNode->printNode();
    }
}
























