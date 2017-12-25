#include"Tree_Link.h"
#include<stdlib.h>


Tree::Tree()
{
    m_pRoot=new Node();
}

Tree::~Tree()
{
    DeleteNode(0,NULL);
}

Node * Tree::SearchNode(int nodeIndex)
{
    return m_pRoot->SearchNode(nodeIndex);
}

bool Tree::AddNode(int nodeIndex,int direction,Node *pNode)
{
    Node *temp=SearchNode(nodeIndex);
    if(temp==NULL)       //判断其结点存不存在
        return false;

    Node *node=new Node();   //申请内存
    if(node==NULL)
        return false;

    node->data=pNode->data;
    node->index=pNode->index;
    node->pParent=temp;

    if(direction==0)    //0左边
    {
        if(temp->pLChild==NULL)     //判断结点是否已经存在左孩子
        {
            temp->pLChild=node;
            return true;
        }
        Node *p=temp->pLChild;
        temp->pLChild=node;
        temp->pLChild->pLChild=p;
        return true;
    }
    if(direction==1)    //1右边
    {
        if(temp->pRChild==NULL)      //判断结点是否已经存在左孩子
        {
            temp->pRChild=node;
            return true;
        }
        Node *p=temp->pRChild;
        temp->pRChild=node;
        temp->pRChild->pRChild=p;
        return true;
    }
    return false;
}

bool Tree::DeleteNode(int nodeIndex,Node *pNode)
{
    Node *temp=SearchNode(nodeIndex);
    if(temp==NULL)   //结点不存在
        return false;
    if(pNode!=NULL)   //判断是否要提取要删除的结点
    {
        temp->data=pNode->data;
    }
    temp->DeleteNode();
}

void Tree::PreorderTraversal ()
{
    m_pRoot->PreorderTraversal();
}

void Tree::InorderTraversal()
{
    m_pRoot->InorderTraversal();
}

void Tree::PostorderTraversal()
{
    m_pRoot->PostorderTraversal();
}














