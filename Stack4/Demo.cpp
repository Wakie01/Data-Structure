#include<iostream>
#include"stdlib.h"
#include"MyStack.h"
#include"Coordinate.h"
using namespace std;


/*                �ж�����ƥ��
       ([])  (([]))  ([]())  (([])  ([]))
*/


int main()
{
	MyStack<char> * pStack=new MyStack<char>(30);
	MyStack<char> * pNeedStack=new MyStack<char>(30);
	
	char str[]="()[])";//�������пո�
	
	char currentNeed=0;//ֻ��ǰһ��ƥ��
	
	for(int i=0;i<strlen(str);i++)
	{
		if(str[i]!=currentNeed)  //�����ھ��ȴ��������ټ��������ң����Ƿ���ƥ���
		{
			pStack->push(str[i]);
			switch(str[i])
			{
			case '[':
				if(currentNeed !=0)
				{
					pNeedStack->push(currentNeed);//�ȴ�����
				}
				currentNeed=']';
				break;
			case '(':
				if(currentNeed !=0)
				{
					pNeedStack->push(currentNeed);
				}
				currentNeed=')';
				break;
			default:
				cout<<"�ַ������Ų�ƥ��"<<endl;
				system("pause");
				return 0;
			}
		}
		else
		{
			char elem;
			pStack->pop(elem);   //���ڼ�ƥ�䣬�����
			if(!pNeedStack->pop(currentNeed)) //pNeedStack�����Ѿ�û��Ԫ�أ�soҪ�ж��Ƿ�ɹ���ջ   ��ʱcurrentNeed�Ѿ�������
				currentNeed=0;				
		}
	}
	if(pStack->stackEmpty())
		cout<<"�ַ�������ƥ��"<<endl;
	else
		cout<<"�ַ������Ų�ƥ��"<<endl;

	delete pStack;
	pStack=NULL;
	delete pNeedStack;
	pNeedStack=NULL;

	system("pause"); //��ʾ�밴���������
	return 0;
}