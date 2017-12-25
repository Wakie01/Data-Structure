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
    if(temp==NULL)       //�ж�����治����
        return false;

    Node *node=new Node();   //�����ڴ�
    if(node==NULL)
        return false;

    node->data=pNode->data;
    node->index=pNode->index;
    node->pParent=temp;

    if(direction==0)    //0���
    {
        if(temp->pLChild==NULL)     //�жϽ���Ƿ��Ѿ���������
        {
            temp->pLChild=node;
            return true;
        }
        Node *p=temp->pLChild;
        temp->pLChild=node;
        temp->pLChild->pLChild=p;
        return true;
    }
    if(direction==1)    //1�ұ�
    {
        if(temp->pRChild==NULL)      //�жϽ���Ƿ��Ѿ���������
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
    if(temp==NULL)   //��㲻����
        return false;
    if(pNode!=NULL)   //�ж��Ƿ�Ҫ��ȡҪɾ���Ľ��
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














