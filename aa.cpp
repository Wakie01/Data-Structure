#include<iostream>
#include<string.h>
using namespace std;

class MyStack{
private:
    char *m_pBuffer;
    int m_top;

public:
    MyStack();
    void push(char c);
    char pop();
    bool isEmpty();

};

MyStack::MyStack(){
    m_pBuffer=new char[50];
    m_top=0;
}

void MyStack::push(char c){
    m_pBuffer[m_top++]=c;
}

char MyStack::pop(){
    if(isEmpty())
        return '\0';
    else{
        return m_pBuffer[--m_top];
    }
}

bool MyStack::isEmpty(){
    return 0==m_top? true:false;
}


int main(){
    char str[50];
    cout<<"ÇëÊäÈëÒ»Á¬´®À¨ºÅ"<<endl;
    cin>>str;

    MyStack pStack;
    MyStack pNeedStack;
    char currentNeed=0;
    for(int i=0;i<strlen(str);i++){
        if(str[i]!=currentNeed){
            if(str[i]=='('){
                if(currentNeed==0){
                    currentNeed=')';
                }
                else{
                    pNeedStack.push(currentNeed);
                    currentNeed=')';
                }
                pStack.push(str[i]);
            }
            else if(str[i]=='['){
                if(currentNeed==0){
                    currentNeed=']';
                }
                else{
                    pNeedStack.push(currentNeed);
                    currentNeed=']';
                }
                pStack.push(str[i]);
            }
        }
        else{
            pStack.pop();
            currentNeed=pNeedStack.pop();
            currentNeed=currentNeed=='\0' ? '0':currentNeed;
        }
    }
    if(pStack.isEmpty()){
        cout<<"×Ö·û´®À¨ºÅÆ¥Åä"<<endl;
    }
    else{
        cout<<"×Ö·û´®À¨ºÅ²»Æ¥Åä"<<endl;
    }

    return 0;
}














