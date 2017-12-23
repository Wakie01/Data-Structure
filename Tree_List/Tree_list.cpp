#include"Tree.h"
#include<iostream>
using namespace std;

Tree::Tree(int size,int *root)
{
    m_iSize=size;
    m_pTree=new int[size];
    for(int i=0;i<m_iSize;i++)  //һ��ʼ��������ֵ��ȫ��
    {
        m_pTree[i]=0;
    }
    m_pTree[0]=*root;
}

Tree::~Tree()
{
    delete m_pTree;
    m_pTree=NULL;
}

int * Tree::SearchNode(int nodeIndex)
{
    if(nodeIndex<0||nodeIndex>m_iSize)
        return NULL;
    if(m_pTree[nodeIndex]==0)   //��Ҫ�жϽ���Ƿ�Ϊ��
        return NULL;
    return &m_pTree[nodeIndex];
}

bool Tree::AddNode(int nodeIndex,int direction,int *pNode)
{
    if(nodeIndex<0||nodeIndex>m_iSize)
        return false;
    if(m_pTree[nodeIndex]==0)   //��Ҫ�жϽ���Ƿ�Ϊ��
        return false;
    if(direction==1)    //1 ����
        m_pTree[2*nodeIndex+1]=*pNode;
    if(direction==2)    //2 �Һ���
        m_pTree[2*nodeIndex+2]=*pNode;
    return true;
}

bool Tree::DeleteNode(int nodeIndex,int *pNode)
{
    if(nodeIndex<0||nodeIndex>m_iSize)
        return false;
    if(m_pTree[nodeIndex]==0)   //��Ҫ�жϽ���Ƿ�Ϊ��
        return false;
    *pNode=m_pTree[nodeIndex];
    m_pTree[nodeIndex]=0;
    return true;
}

void Tree::TreeTraverse()
{
    for(int i=0;i<m_iSize;i++)
        cout<<m_pTree[i]<<"  ";
    cout<<endl;
}


























