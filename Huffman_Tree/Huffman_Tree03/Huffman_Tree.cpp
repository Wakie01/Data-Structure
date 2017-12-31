#include<iostream>
#include<stdio.h>
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
    void showCode(FILE *fp);
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

void Node::showCode(FILE *fp)
{
    cout<<this->data<<"   "<<this->weight<<"    ";
    for(int i=this->codeNum-1;i>=0;i--)
    {
        cout<<this->code[i];
        if(fp!=NULL)
        {
            fputc(this->code[i],fp);
        }
    }
    cout<<endl;
}


class HuffmanTree{
public:
    HuffmanTree();
    ~HuffmanTree();
    void Add(char *sentence);
    bool select(int *s1,int *s2);
    void creatHuffmanTree();
    void traverse();
    void setCode();
    void writeCode();
    void tranCode(FILE *fp);
    void showCode(FILE *fp);
    bool fileCode();
private:
    Node *Tree;
    int capacity;
    int leaf;   //叶子结点
    char *inCode;

};

HuffmanTree::HuffmanTree()
{

}

HuffmanTree::~HuffmanTree()
{
    for(int i=0;i<=capacity;i++)
    {
        delete &Tree[i];
    }
}

void HuffmanTree::Add(char *sentence)
{
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
    for(int i=0;i<capacity;i++)
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
            Tree[i].code[n++]=currentNode->element;  //用一个数组一个个地存储数码
            currentNode=currentNode->pParent;
        }
        Tree[i].codeNum=n;
    }
}

void HuffmanTree::showCode(FILE *fp)
{
    for(int i=0;i<leaf;i++)
        {
            Tree[i].showCode(fp);
        }
}

void HuffmanTree::writeCode()
{
    inCode=new char [100];
    cout<<"请输入数码:"<<endl;
    cin>>inCode;
}

bool HuffmanTree::fileCode()   //将文件中的数码移到inCode中
{
    char *fileName=new char[100];
    cout<<"请输入要编码的文件名:"<<endl;
    cin>>fileName;
    FILE *fp2;
    fp2=fopen(fileName,"r+");  //以读写的方式打开文件
    if(fp2==NULL)
    {
        return false;
    }
    else
    {
        inCode=new char [100];
        int i=0;
        inCode[i]=fgetc(fp2);
        while(inCode[i]!=EOF)
        {
            i++;
            inCode[i]=fgetc(fp2);
        }
        inCode[i]='\0';
        fclose(fp2);
        return true;
    }

}

void HuffmanTree::tranCode(FILE *fp)      //译码是从上往下
{
    int length=strlen(inCode);
    int head;
    int i;
    for(i=0;i<capacity;i++)    //找到头结点的位置head
    {
        if(Tree[i].pParent==NULL)
        {
            head=i;
            break;
        }
    }

    Node *currentNode=&Tree[head];
    for(i=0;i<length;i++)
    {
        if(currentNode->plChild!=NULL&&currentNode->prChild!=NULL)
        {
            switch(inCode[i])
            {
                case '0':
                {
                    currentNode=currentNode->plChild;
                    break;
                }
                case '1':
                {
                    currentNode=currentNode->prChild;
                    break;
                }
                default:
                    cout<<"数码有错误"<<endl;
                    break;
            }
        }
        if(currentNode->plChild==NULL&&currentNode->prChild==NULL)
        {
            cout<<currentNode->data<<" ";
            if(fp!=NULL)
            {
                fputc(currentNode->data,fp);
            }
            currentNode=&Tree[head];
        }

    }
    cout<<endl;
}

void menu()
{
    printf("\n**********     哈夫曼编码译码     ***********\n");
	printf("\n\n   =====================================  \n\n");
	printf("\n               0.退出系统.                  \n");
	printf("\n               1.对文件编码.              \n");
	printf("\n               2.输入字符编码.             \n");
	printf("\n               3.对文件译码.              \n");
	printf("\n               4.输入数码译码.             \n");
	printf("\n   =====================================");
	printf("\n\n请选择:\n");
}

int main()
{
    HuffmanTree *tree=new HuffmanTree();
    menu();
    int order;
    cin>>order;
    while(order!=0)
    {
        switch(order)
        {
        case 1:
            {
                char *fileName=new char[100];
                cout<<"请输入要编码的文件名:"<<endl;
                cin>>fileName;
                FILE *fp;     //文件指针
                fp=fopen(fileName,"r+");  //以读写的方式打开test.txt文件

                if(fp==NULL)   //判断文件是否打开成功
                {
                    cout<<"打开文件失败"<<endl;
                    break;
                }

                char *sentence=new char[100];
                int n=0;

                sentence[n]=fgetc(fp);     //从文件中读取字符函数
                while(!feof(fp))  //判断刚读取到的字符是否为文件结束符
                {
                    n++;
                    sentence[n]=fgetc(fp);
                }

                sentence[n]='\0';  //将最后一个文件结束符换成'\0'
                fclose(fp);

                cout<<"请输入保存在哪个文件"<<endl;
                cin>>fileName;
                FILE *fp2;
                fp2=fopen(fileName,"r+");
                if(fp2==NULL)
                {
                    cout<<"打开文件失败"<<endl;
                    break;
                }
                tree->Add(sentence);
                tree->creatHuffmanTree();
                tree->setCode();
                tree->showCode(fp2);
                fclose(fp2);
                break;
            }
        case 2:
            {
                char *sentence=new char[100];
                cout<<"请输入一行字符串:"<<endl;
                cin>>sentence;
                tree->Add(sentence);
                tree->creatHuffmanTree();
                tree->setCode();
                tree->showCode(NULL);
                break;
            }
        case 3:
            {
                char *fileName=new char[100];
                if(!tree->fileCode())
                {
                    cout<<"打开文件失败"<<endl;
                    break;
                }
                tree->setCode();
                cout<<"请输入保存在哪个文件:"<<endl;
                cin>>fileName;
                FILE *fp;
                fp=fopen(fileName,"r+");
                if(fp==NULL)
                {
                    cout<<"打开文件失败"<<endl;
                    break;
                }

                tree->tranCode(fp);
                fclose(fp);
                break;
            }
        case 4:
            {
                tree->writeCode();
                tree->tranCode(NULL);
                break;
            }
        default:
            {
                cout<<"请正确输入命令"<<endl;
                break;
            }
        }
        system("pause");
        system("cls");   //清空界面
        menu();
        cin>>order;
    }

    delete tree;

    system("pause");
    return 0;
}



































