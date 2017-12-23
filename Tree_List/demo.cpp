#include"Tree.h"
#include<stdlib.h>
#include<iostream>
using namespace std;
/*
                   3(0)
            5(1)          4(2)
        7(3)    9(4)   2(5)  8(6)

*/


int main()
{
    int root=3;
    Tree * Ptree=new Tree(10,&root);
    int node1=5;
    int node2=4;
    Ptree->AddNode(0,1,&node1);
    Ptree->AddNode(0,2,&node2);
    int node3=7;
    int node4=9;
    Ptree->AddNode(1,1,&node3);
    Ptree->AddNode(1,2,&node4);
    int node5=2;
    int node6=8;
    Ptree->AddNode(2,1,&node5);
    Ptree->AddNode(2,2,&node6);

    Ptree->TreeTraverse();

    cout<<endl;

    int *node;
    node=Ptree->SearchNode(3);
    cout<<"node:"<<*node<<endl;

    cout<<endl;

    int p;
    Ptree->DeleteNode(2,&p);
    cout<<"p:"<<p<<endl;

    cout<<endl;

    Ptree->TreeTraverse();

    delete Ptree;
    Ptree=NULL;
    system("pause");
    return 0;
}























