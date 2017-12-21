#include"Link_List.h"
#include<stdlib.h>
#include<iostream>
using namespace std;

int main()
{
    Link_List *list=new Link_List();

    Node temp;

    Node node1;
    node1.data=3;
    Node node2;
    node2.data=4;
    Node node3;
    node3.data=5;
    Node node4;
    node4.data=6;
    Node node5;
    node5.data=7;


    list->ListInsertHead(&node1);
    list->ListInsertHead(&node2);
    list->ListInsertHead(&node3);
    list->ListInsertHead(&node4);


    list->ListInsertTail(&node1);
    list->ListInsertTail(&node2);
    list->ListInsertTail(&node3);
    list->ListInsertTail(&node4);

    list->ListInsert(1,&node5);  //第一个位置是0，第二个位置是1

    list->ListDelete(1,&temp);

    list->ListTraverse();

    cout<<endl;

    cout<<"temp:"<<temp.data<<endl;

    cout<<endl;

    list->PriorElem(&node2,&temp);
    cout<<"PriorElem:"<<temp.data<<endl;

    cout<<endl;

    list->NextElem(&node1,&temp);
    cout<<"NextElem:"<<temp.data<<endl;

    cout<<endl;

    list->GetElem(1,&temp);
    cout<<"GetElem:"<<temp.data<<endl;

    cout<<endl;

    cout<<"local:"<<list->LocateElem(&node4)<<endl;

    cout<<endl;

    cout<<"length:"<<list->ListLength()<<endl;

    cout<<endl;

    list->ClearList();

    cout<<"Second length:"<<list->ListLength()<<endl;

    cout<<endl;


    delete list;
    list=NULL;
    system("pause");
    return 0;
}































