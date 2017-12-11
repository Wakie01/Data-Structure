#include<iostream>
#include"stdlib.h"
#include"MyStack.h"
#include"Coordinate.h"
using namespace std;


/*                判断括号匹配
       ([])  (([]))  ([]())  (([])  ([]))
*/


int main()
{
	MyStack<char> * pStack=new MyStack<char>(30);
	MyStack<char> * pNeedStack=new MyStack<char>(30);
	
	char str[]="()[])";//不用留有空格
	
	char currentNeed=0;//只与前一个匹配
	
	for(int i=0;i<strlen(str);i++)
	{
		if(str[i]!=currentNeed)  //不等于就先存起来，再继续往后找，看是否有匹配的
		{
			pStack->push(str[i]);
			switch(str[i])
			{
			case '[':
				if(currentNeed !=0)
				{
					pNeedStack->push(currentNeed);//先存起来
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
				cout<<"字符串括号不匹配"<<endl;
				system("pause");
				return 0;
			}
		}
		else
		{
			char elem;
			pStack->pop(elem);   //等于即匹配，就清空
			if(!pNeedStack->pop(currentNeed)) //pNeedStack可能已经没有元素，so要判断是否成功出栈   此时currentNeed已经更新了
				currentNeed=0;				
		}
	}
	if(pStack->stackEmpty())
		cout<<"字符串括号匹配"<<endl;
	else
		cout<<"字符串括号不匹配"<<endl;

	delete pStack;
	pStack=NULL;
	delete pNeedStack;
	pNeedStack=NULL;

	system("pause"); //显示请按任意键继续
	return 0;
}