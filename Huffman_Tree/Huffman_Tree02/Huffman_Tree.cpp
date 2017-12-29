#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

class Node{
public:
    Node();
    char data;
    double weight;
    char element;
    char *code;
    int codeNum;
    Node *pParent;
    Node *plChild;
    Node *prChild;
    void traverse();
    void showCode();
    //void Add(char a,double w);
};

Node::Node()
{
    data='\0';
    weight=0;
    element='\0';
    code=new char[100];
    codeNum=0;
    pParent=NULL;
    plChild=NULL;
    pParent=NULL;
}

/*
void Node::Add(char a,double w)
{
    this->weight=w;
    this->data=a;
}
*/

void Node::traverse()
{
    if(this->data!='\0')
        cout<<this->data;
    cout<<"   ";
    cout<<this->weight<<endl;
    if(this->plChild!=NULL)
    {
        this->plChild->traverse();
    }
    if(this->prChild!=NULL)
    {
        this->prChild->traverse();
    }
}

void Node::showCode()
{
    cout<<this->data<<"   "<<this->weight<<"    ";
    for(int i=this->codeNum-1;i>=0;i--)
    {
        cout<<this->code[i];
    }
    cout<<endl;
}


class HuffmanTree{
public:
    HuffmanTree();  //n:结点个数
    ~HuffmanTree();
    void Add();
    bool select(int *s1,int *s2);
    void creatHuffmanTree();
    void traverse();
    void setCode();
    void showCode();
private:
    Node *Tree;
    int capacity;
    int leaf;   //叶子结点

};

HuffmanTree::HuffmanTree()
{
    Add();
}

HuffmanTree::~HuffmanTree()
{
    for(int i=0;i<=capacity;i++)
    {
        delete &Tree[i];
    }
}

void HuffmanTree::Add()
{
    char *sentence=new char[100];
    cout<<"请输入一行字符串:"<<endl;
    cin>>sentence;
    int t;
    double n=1;   //相同结点个数
    leaf=0;
    int l=0;
    int isExist=0;
    for(t=0;t<strlen(sentence);t++)    //确定不同字符的个数
    {
        for(int j=0;j<t;j++)
        {
            if(sentence[j]==sentence[t])
            {
                isExist=1;
                break;
            }
        }
        if(isExist==0)
        {
            leaf++;
        }
        else
            isExist=0;
    }

    cout<<"leaf:"<<leaf<<endl;

    capacity=2*leaf-1;               //根据leaf建立内存空间
    Tree=new Node[capacity+1];

    for(t=0;t<strlen(sentence);t++)    //给tree的data赋值
    {
        for(int j=0;j<t;j++)
        {
            if(sentence[j]==sentence[t])
            {
                isExist=1;
                break;
            }
        }
        if(isExist==0)
        {
            Tree[l++].data=sentence[t];
        }
        else
            isExist=0;
    }

    for(t=0;t<leaf;t++)             //计算每个data的weight值
    {
        for(int i=0;i<strlen(sentence);i++)
        {
            if(Tree[t].data==sentence[i])
            {
                n++;
            }
        }
        Tree[t].weight=(n-1)/leaf;
        n=1;
    }

    for(t=0;t<leaf;t++)
        cout<<Tree[t].data<<"     "<<Tree[t].weight<<endl;
    cout<<endl;
}

bool HuffmanTree::select(int *s1,int *s2)  //目的是得到位置
{
    double min=0;
    int n=0;    //记录结点位置
    int i;
    for(i=0;i<capacity;i++) //给个值给min，n
    {
        if(Tree[i].pParent==NULL&&Tree[i].weight!=0)
        {
            min=Tree[i].weight;
            n=i;
            break;
        }
    }
    if(min==0&&n==0)   //判断是否成功赋值
        return false;

    for(i=0;i<capacity;i++)
    {
        if(Tree[i].pParent==NULL&&Tree[i].weight!=0)
        {
            if(Tree[i].weight<min)
            {
                min=Tree[i].weight;
                n=i;
            }
        }
    }
    *s1=n;

    for(i=0;i<capacity;i++) //重新给个值给min，n
    {
        if(Tree[i].pParent==NULL&&Tree[i].weight!=0&&i!=*s1)
        {
            min=Tree[i].weight;
            n=i;
            break;
        }
    }
    if(n==*s1)
        return false;

    for(i=0;i<capacity;i++)
    {
        if(Tree[i].pParent==NULL&&Tree[i].weight!=0&&i!=*s1)
        {
            if(Tree[i].weight<min)
            {
                min=Tree[i].weight;
                n=i;
            }
        }
    }
    *s2=n;

    return true;
}

void HuffmanTree::creatHuffmanTree()
{
    int s1,s2;
    int i=leaf;
    for(;i<capacity;i++)
    {
        select(&s1,&s2);
        Tree[i].weight=Tree[s1].weight+Tree[s2].weight;
        Tree[i].plChild=&Tree[s1];
        Tree[s1].element='0';
        Tree[i].prChild=&Tree[s2];
        Tree[s2].element='1';
        Tree[s1].pParent=&Tree[i];
        Tree[s2].pParent=&Tree[i];
    }
}

void HuffmanTree::traverse()
{
    int head;
    for(int i=0;i<=capacity;i++)
    {
        if(Tree[i].pParent==NULL)
        {
            head=i;
            break;
        }
    }
    Tree[head].traverse();
}

void HuffmanTree::setCode()   //从下往上
{
    Node *currentNode=NULL;
    for(int i=0;i<leaf;i++)
    {
        int n=0;
        currentNode=&Tree[i];
        while(currentNode!=NULL)
        {
            Tree[i].code[n++]=currentNode->element;
            currentNode=currentNode->pParent;
        }
        Tree[i].codeNum=n;
    }
}

void HuffmanTree::showCode()
{
    for(int i=0;i<leaf;i++)
        {
            Tree[i].showCode();
        }
}

int main()
{
    HuffmanTree *tree=new HuffmanTree();

    tree->creatHuffmanTree();

    tree->traverse();

    cout<<endl<<endl;

    tree->setCode();
    tree->showCode();





    delete tree;

    system("pause");
    return 0;
}



































