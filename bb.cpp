#include<iostream>
#include<string.h>
using namespace std;

class Node{
public:
    char c;
    Node *next;
};

class MyStack{
private:
    Node *topNode;

public:
    MyStack();
    void push(char c);
    char pop();
    bool isEmpty();
};

MyStack::MyStack(){
    topNode=new Node();
    topNode->c='\0';
    topNode->next=NULL;
}

void MyStack::push(char c){
    Node *node=new Node();
    node->c=c;
    node->next=topNode;
    topNode=node;
}

char MyStack::pop(){
    if(topNode->next==NULL){
        return '\0';
    }
    else{
        char c=topNode->c;
        topNode=topNode->next;
        return c;
    }
}

bool MyStack::isEmpty(){
    return topNode->next==NULL ? true:false;
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


//    MyStack my;
//    my.push('a');
//    my.push('b');
//    my.push('c');
//    my.push('d');
//    my.push('e');
//    while(!my.isEmpty()){
//        cout<<my.pop()<<endl;
//    }
    return 0;
}























