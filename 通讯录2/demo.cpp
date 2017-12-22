#include"Link_List.h"
#include<stdlib.h>
#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
    Link_List *list=new Link_List();

    int order;
    cout<<'\n'<<'\n'<<'\n';
    cout<<"/**************功能菜单******************"<<'\n'<<'\n';
    cout<<"/************1.新建联系人****************"<<'\n'<<'\n';
    cout<<"/************2.删除联系人****************"<<'\n'<<'\n';
    cout<<"/************3.浏览通讯录****************"<<'\n'<<'\n';
    cout<<"/************4.查找联系人****************"<<'\n'<<'\n';
    cout<<"/************5.联系人数目****************"<<'\n'<<'\n';
    cout<<"/************6.退出通讯录****************"<<'\n'<<'\n';

    cout<<endl<<"请输入指令"<<'\n';
    cin>>order;
    while(order!=6)
    {
        switch(order)
        {
            case 1:
                {
                    cout<<"\\1.新建联系人\\"<<endl;
                    cout<<"请输入姓名:";
                    Node node;
                    cin>>node.data.name;
                    cout<<"请输入电话号码:";
                    cin>>node.data.phone;
                    list->ListInsertTail(&node);
                    break;
                }
            case 2:
                {
                    cout<<"\\2.删除联系人\\"<<'\n';
                    int i;
                    Node temp;
                    cout<<"请输入删除第几个联系人:";
                    cin>>i;
                    list->ListDelete(i-1,&temp);
                    cout<<"删除的联系人:"<<temp.data.name<<"-----------"<<temp.data.phone<<endl;
                    break;
                }
            case 3:
                {
                    cout<<"\\3.浏览通讯录\\"<<'\n';
                    list->ListTraverse();
                    break;
                }
            case 4:
                {
                    cout<<"\\4.查找联系人\\"<<endl;
                    cout<<"请输入查找的联系人姓名:"<<endl;
                    int i;
                    Node temp;
                    cin>>temp.data.name;
                    i=list->LocateElem(&temp);
                    cout<<temp.data.name<<"的电话号码:";
                    list->GetElem(i,&temp);
                    cout<<temp.data.phone<<endl;
                    break;
                }
            case 5:
                {
                    cout<<"\\5.联系人数目\\"<<endl;
                    cout<<"总共有"<<list->ListLength()<<"个联系人"<<endl;
                    break;
                }
            case 6:
                {
                    cout<<"\\6.退出通讯录\\"<<'\n';

                    break;
                }


            default:
                {
                    cout<<"请输入正确指令:";
                    cin>>order;
                }
        }
        system("pause");
        system("cls"); //清空界面
        cout<<'\n'<<'\n'<<'\n';
        cout<<"/**************功能菜单******************"<<'\n'<<'\n';
        cout<<"/************1.新建联系人****************"<<'\n'<<'\n';
        cout<<"/************2.删除联系人****************"<<'\n'<<'\n';
        cout<<"/************3.浏览通讯录****************"<<'\n'<<'\n';
        cout<<"/************4.查找联系人****************"<<'\n'<<'\n';
        cout<<"/************5.联系人数目****************"<<'\n'<<'\n';
        cout<<"/************6.退出通讯录****************"<<'\n'<<'\n';

        cout<<endl<<"请输入指令"<<'\n';
        cin>>order;

    }

    delete list;
    list=NULL;
    system("pause");
    return 0;
}































