#include"Tree_Link.h"
#include<iostream>
#include<stdlib.h>
using namespace std;

/*
            0(0)
       4(1)        2(2)
    8(3)  7(4)  9(5)  3(6)

       前序：0134256
       中序: 3140526
       后序：3415620

*/


int main()
{
    Tree *tree=new Tree();   //在构造函数中已经把根节点初始化为0
    Node *node1=new Node();
    node1->data=4;
    node1->index=1;
    Node *node2=new Node();
    node2->data=2;
    node2->index=2;
    Node *node3=new Node();
    node3->data=8;
    node3->index=3;
    Node *node4=new Node();
    node4->data=7;
    node4->index=4;
    Node *node5=new Node();
    node5->data=9;
    node5->index=5;
    Node *node6=new Node();
    node6->data=3;
    node6->index=6;

    tree->AddNode(0,0,node1);
    tree->AddNode(0,1,node2);
    tree->AddNode(1,0,node3);
    tree->AddNode(1,1,node4);
    tree->AddNode(2,0,node5);
    tree->AddNode(2,1,node6);

    cout<<"前序遍历:"<<endl;
    tree->PreorderTraversal();

    cout<<endl;

    cout<<"中序遍历:"<<endl;
    tree->InorderTraversal();

    cout<<endl;

    cout<<"后序遍历:"<<endl;
    tree->PostorderTraversal();

    cout<<endl;

    tree->DeleteNode(2,NULL);

    cout<<"前序遍历:"<<endl;
    tree->PreorderTraversal();

    cout<<endl;



    delete tree;
    tree=NULL;
    system("pause");
    return 0;
}

























