#include<iostream>
#include"List.h"
using namespace std;

List::List(int size)
{
    m_iSize=size;
    m_pList=new int [size]; //将指针定义成数组指针
    m_iLength=0;
}
List::~List()
{
    delete []m_pList; //delete 数组指针操作
    m_pList=NULL;
}
void List::ClearList()
{
    m_iLength=0;
}
bool List::ListEmpty()
{
    return m_iLength==0? true:false;

    //if(m_iLength==0) return true;
      //  else return false;

}
int List::ListLength()
{
    return m_iLength;
}
bool List::GetElem(int i,int *e)
{
    if(i<0||i>m_iSize) return false;
    *e=m_pList[i];
    return true;
}
int List::LocateElem(int *e)
{
    for(int i=0;i<m_iLength;i++)
    {
        if(m_pList[i]==*e)
            return i;
    }
    return -1; //表示没有找到
}
bool List::PriorElem(int *currentElem,int *preElem)
{
    int temp=LocateElem(currentElem);
    if(temp==-1) return false;
    else if(temp==0) return false;
    else
    {
        *preElem=m_pList[temp-1];
        return true;
    }
}
bool List::NextElem(int *currentElem,int *nextElem)
{
    int temp=LocateElem(currentElem);
    if(temp==-1) return false;
    else if(temp==m_iLength-1) return false;
    else
    {
        *nextElem=m_pList[temp+1];
        return true;
    }
}
void List::ListTraverse()
{
    for(int i=0;i<m_iLength;i++)
        cout<<m_pList[i]<<" ";
    cout<<endl;
}
bool List::ListInsert(int i,int *e)
{
    if(i<0||i>m_iLength) return false;
    for(int k=m_iLength-1;k>=i;k--) //从后往前
    {
        m_pList[k+1]=m_pList[k];   //key
    }
    m_pList[i]=*e;
    m_iLength++;
    return true;
}
bool List::ListDelete(int i,int *e)    //这里指在第i个位置中删除，即delete m_pList[i]
{
    if(i<0||i>=m_iLength) return false;  //=时List中已经没元素了
    *e=m_pList[i];
    for(int k=i+1;k<m_iLength;k++)    //从前往后
    {
        m_pList[k-1]=m_pList[k];
    }
    m_iLength--;
    return true;
}








