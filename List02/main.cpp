
#include<stdlib.h>
#include"List.cpp"  //the difference of compiler
#include"Coordinate.h"



int main()
{
    Coordinate e1(2,3);
	Coordinate e2(3,4);
	Coordinate e3(4,5);
	Coordinate e4(5,6);
    List * list=new List(10);
    list->ListInsert(0,&e1);
	list->ListInsert(1,&e2);
	list->ListInsert(2,&e3);
	list->ListInsert(3,&e4);

    list->ListTraverse();

	cout<<endl;

	cout<<"length:"<<list->ListLength()<<endl;

	cout<<endl;

	Coordinate e5;
	list->GetElem(2,&e5);
	cout<<e5<<endl;

	cout<<endl;

	cout<<list->LocateElem(&e2)<<endl;

	cout<<endl;

	list->PriorElem(&e2,&e5);
	cout<<e5<<endl;

	cout<<endl;

	list->NextElem(&e2,&e5);
	cout<<e5<<endl;

	cout<<endl;

	list->ListDelete(3,&e5);
	cout<<e5<<endl;

	cout<<endl;

	list->ListTraverse();

	cout<<endl;

    delete list;
    list=NULL;

    system("pause");
    return 0;
}
