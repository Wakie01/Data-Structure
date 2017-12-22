#ifndef LINK_LIST_H_INCLUDED
#define LINK_LIST_H_INCLUDED

#include"Node.h"

class Link_List{
public:
    Link_List();
    ~Link_List();  //claer all
    void ClearList();  //clear all except the head
    bool ListEmpty();
    int ListLength();
    bool GetElem(int i,Node *pNode);
    int LocateElem(Node *pNode);
    bool PriorElem(Node *pCurrentNode,Node *pPreNode);
    bool NextElem(Node *pCurrentNode,Node *pNextNode);
    void ListTraverse();
    bool ListInsert(int i,Node *pNode); //在i的位置插入节点
    bool ListDelete(int i,Node *pNode);  //在i的位置删除节点 同时把删除节点的值赋给pNode
    bool ListInsertHead(Node *pNode); //插入结点到头结点的后面
    bool ListInsertTail(Node *pNode);  //在尾结点插入结点
private:
    Node *m_pList; //头结点
    int m_iLength;

};

#endif // LINK_LIST_H_INCLUDED
