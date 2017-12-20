#ifndef LIST_H
#define LIST_H
#include"Coordinate.h"

class List{
public:
    List(int size);
    ~List();
    void ClearList();
    bool ListEmpty();
    int ListLength();
    bool GetElem(int i,Coordinate *e);
    int LocateElem(Coordinate *e);
    bool PriorElem(Coordinate *currentElem,Coordinate *preElem);
    bool NextElem(Coordinate *currentElem,Coordinate *nextElem);
    bool ListInsert(int i,Coordinate *e);
    bool ListDelete(int i,Coordinate *e);
    void ListTraverse();

private:
    Coordinate *m_pList; //ָ������ռ�
    int m_iSize;
    int m_iLength;
};

/*
List::List(int size)
{
    m_iSize=size;
    m_pList=new int [size]; //��ָ�붨�������ָ��
    m_iLength=0;
}
List::~List()
{
    delete []m_pList; //delete ����ָ�����
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
       // else return false;

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
    return -1; //��ʾû���ҵ�
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
    for(int k=m_iLength-1;k>=i;k--) //�Ӻ���ǰ
    {
        m_pList[k+1]=m_pList[k];   //key
    }
    m_pList[i]=*e;
    m_iLength++;
    return true;
}
bool List::ListDelete(int i,int *e)    //����ָ�ڵ�i��λ����ɾ������delete m_pList[i]
{
    if(i<0||i>=m_iLength) return false;  //=ʱList���Ѿ�ûԪ����
    *e=m_pList[i];
    for(int k=i+1;k<m_iLength;k++)    //��ǰ����
    {
        m_pList[k-1]=m_pList[k];
    }
    m_iLength--;
    return true;
}


*/

#endif // LIST_H_INCLUDED
