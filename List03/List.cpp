#include<iostream>
#include"List.h"
#include"Coordinate.h"

using namespace std;

template<typename T>
List<T>::List(int size)
{
    m_iSize=size;
    m_pList=new T [size]; //��ָ�붨�������ָ��
    m_iLength=0;
}

template<typename T>
List<T>::~List()
{
    delete []m_pList; //delete ����ָ�����
    m_pList=NULL;
}

template<typename T>
void List<T>::ClearList()
{
    m_iLength=0;
}

template<typename T>
bool List<T>::ListEmpty()
{
    return m_iLength==0? true:false;

    //if(m_iLength==0) return true;
      //  else return false;

}

template<typename T>
int List<T>::ListLength()
{
    return m_iLength;
}

template<typename T>
bool List<T>::GetElem(int i,T *e)
{
    if(i<0||i>m_iSize) return false;
    *e=m_pList[i];
    return true;
}

template<typename T>
int List<T>::LocateElem(T *e)
{
    for(int i=0;i<m_iLength;i++)
    {
        if(m_pList[i]==*e)
            return i;
    }
    return -1; //��ʾû���ҵ�
}

template<typename T>
bool List<T>::PriorElem(T *currentElem,T *preElem)
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

template<typename T>
bool List<T>::NextElem(T *currentElem,T *nextElem)
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

template<typename T>
void List<T>::ListTraverse()
{
    for(int i=0;i<m_iLength;i++)
        cout<<m_pList[i]<<" ";
    cout<<endl;
}

template<typename T>
bool List<T>::ListInsert(int i,T *e)
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

template<typename T>
bool List<T>::ListDelete(int i,T *e)    //����ָ�ڵ�i��λ����ɾ������delete m_pList[i]
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








