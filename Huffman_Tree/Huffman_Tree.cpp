#include<iostream>
#include<stdlib.h>
using namespace std;

class Node{
public:
    Node();
    int weight;
    Node *pParent;
    Node *plChild;
    Node *prChild;
    void traverse();
    void Add(int w);
};

Node::Node()
{
    weight=0;
    pParent=NULL;
    plChild=NULL;
    pParent=NULL;
}

void Node::Add(int w)
{
    this->weight=w;

}

void Node::traverse()
{
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

class HuffmanTree{
public:
    HuffmanTree(int n);  //n:结点个数
    ~HuffmanTree();
    void Add(int i,int w);
    bool select(int *s1,int *s2);
    void creatHuffmanTree();
    void traverse();
private:
    Node *Tree;
    int capacity;
    int leaf;   //叶子结点

};

HuffmanTree::HuffmanTree(int n)
{
    capacity=2*n-1;
    Tree=new Node[capacity+1];
    leaf=n;
}

HuffmanTree::~HuffmanTree()
{
    for(int i=0;i<=capacity;i++)
    {
        delete &Tree[i];
    }
}
void HuffmanTree::Add(int i,int w)
{
    Tree[i].Add(w);
}

bool HuffmanTree::select(int *s1,int *s2)  //目的是得到位置
{
    int min=0;
    int n=0;    //记录结点位置
    int i;
    for(i=1;i<=capacity;i++) //给个值给min，n
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

    for(i=1;i<=capacity;i++)
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

    for(i=1;i<=capacity;i++) //重新给个值给min，n
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

    for(i=1;i<=capacity;i++)
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
    int i=leaf+1;
    for(;i<=capacity;i++)
    {
        select(&s1,&s2);
        Tree[i].weight=Tree[s1].weight+Tree[s2].weight;
        Tree[i].plChild=&Tree[s1];
        Tree[i].prChild=&Tree[s2];
        Tree[s1].pParent=&Tree[i];
        Tree[s2].pParent=&Tree[i];
    }
}

void HuffmanTree::traverse()
{
    int head;
    for(int i=1;i<=capacity;i++)
    {
        if(Tree[i].pParent==NULL)
        {
            head=i;
            break;
        }
    }
    Tree[head].traverse();
}


int main()
{
    HuffmanTree *tree=new HuffmanTree(8);
    tree->Add(1,7);
    tree->Add(2,19);
    tree->Add(3,2);
    tree->Add(4,6);
    tree->Add(5,32);
    tree->Add(6,3);
    tree->Add(7,21);
    tree->Add(8,10);

    tree->creatHuffmanTree();

    tree->traverse();


    delete tree;

    system("pause");
    return 0;
}



































