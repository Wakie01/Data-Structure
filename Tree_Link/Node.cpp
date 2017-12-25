#include"Node.h"
#include<stdlib.h>
#include<iostream>
using namespace std;

Node::Node()
{
    index=0;
    data=0;
    pLChild=NULL;
    pRChild=NULL;
    pParent=NULL;
}

Node *Node::SearchNode(int nodeIndex)   //Way one
{
    Node *currentNode=this;
    if(currentNode->index==nodeIndex)
        return currentNode;


    while(currentNode->pLChild!=NULL)     //递归思想
    {
        currentNode=currentNode->pLChild;
        if(currentNode->index==nodeIndex)
            return currentNode;
    }

    currentNode=this;
    while(currentNode->pRChild!=NULL)
    {
        currentNode=currentNode->pRChild;
        if(currentNode->index==nodeIndex)
            return currentNode;
    }

    return NULL;
}

/*
Node *Node::SearchNode(int nodeIndex)     //Way Two
{
    Node *temp=NULL;
    if(this->index==nodeIndex)  return this;
    if(this->pLChild!=NULL)
    {
        if(this->pLChild->index==nodeIndex)
        {
            return this->pLChild;
        }
        else
        {
            temp=this->pLChild->SearchNode(nodeIndex);   //递归思想
            if(temp!=NULL) return temp;
        }
    }

    if(this->pRChild!=NULL)
    {
        if(this->pRChild->index==nodeIndex)
        return this->pRChild;
        else
        {
            temp=this->pRChild->SearchNode(nodeIndex);
            if(temp!=NULL) return temp;
        }
    }

    return NULL;

}
*/

void Node::DeleteNode()
{
    if(this->pLChild!=NULL)  //删除孩子
    {
        this->pLChild->DeleteNode();
    }
    if(this->pRChild!=NULL)
    {
        this->pRChild->DeleteNode();
    }
    if(this->pParent!=NULL)        //删除本结点
    {
        if(this->pParent->pLChild==this)
        {
            this->pParent->pLChild=NULL;
        }
        if(this->pParent->pRChild==this)
        {
            this->pParent->pRChild=NULL;
        }
    }
    delete this;  //删除temp
}

void  Node::PreorderTraversal ()
{
    cout<<this->index<<" "<<this->data<<endl;
    if(this->pLChild!=NULL)
    {
        this->pLChild->PreorderTraversal();
    }
    if(this->pRChild!=NULL)
    {
        this->pRChild->PreorderTraversal();
    }
}

void Node::InorderTraversal()
{
    if(this->pLChild!=NULL)
    {
        this->pLChild->InorderTraversal();
    }
    cout<<this->index<<" "<<this->data<<endl;
    if(this->pRChild!=NULL)
    {
        this->pRChild->InorderTraversal();
    }
}

void Node::PostorderTraversal()
{
    if(this->pLChild!=NULL)
    {
        this->pLChild->PostorderTraversal();
    }
    if(this->pRChild!=NULL)
    {
        this->pRChild->PostorderTraversal();
    }
    cout<<this->index<<" "<<this->data<<endl;
}


















