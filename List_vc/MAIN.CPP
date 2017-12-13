#include <iostream>
#include<stdlib.h>
#include"List_vc.h"
using namespace std;

int main()
{
    int e1=3;
    List * list=new List(10);
    list->ListInsert(0,&e1);

    list->ListTraverse();

    delete list;
    list=NULL;

    system("pause");
    return 0;
}