#include"Link_List.h"
#include<stdlib.h>
#include<iostream>
using namespace std;

int main()
{
    Link_List *list=new Link_List();

    Node node1;
    node1.data.name="Peter1";
    node1.data.phone="123456";
    Node node2;
    node2.data.name="Peter2";
    node2.data.phone="234567";

    list->ListInsert(0,&node1);
    list->ListInsert(1,&node2);

    list->ListTraverse();

    cout<<endl;




    delete list;
    list=NULL;
    system("pause");
    return 0;
}































