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
    int leaf;   //Ҷ�ӽ��
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
    double n=1;   //��ͬ������
    leaf=0;
    int l=0;
    int isExist=0;
    for(t=0;t<strlen(sentence);t++)    //ȷ����ͬ�ַ��ĸ���
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

    capacity=2*leaf-1;               //����leaf�����ڴ�ռ�
    Tree=new Node[capacity+1];

    for(t=0;t<strlen(sentence);t++)    //��tree��data��ֵ
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

    for(t=0;t<leaf;t++)             //����ÿ��data��weightֵ
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

bool HuffmanTree::select(int *s1,int *s2)  //Ŀ���ǵõ�λ��
{
    double min=0;
    int n=0;    //��¼���λ��
    int i;
    for(i=0;i<capacity;i++) //����ֵ��min��n
    {
        if(Tree[i].pParent==NULL&&Tree[i].weight!=0)
        {
            min=Tree[i].weight;
            n=i;
            break;
        }
    }
    if(min==0&&n==0)   //�ж��Ƿ�ɹ���ֵ
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

    for(i=0;i<capacity;i++) //���¸���ֵ��min��n
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

void HuffmanTree::setCode()   //��������
{
    Node *currentNode=NULL;
    for(int i=0;i<leaf;i++)
    {
        int n=0;
        currentNode=&Tree[i];
        while(currentNode!=NULL)
        {
            Tree[i].code[n++]=currentNode->element;  //��һ������һ�����ش洢����
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
    cout<<"����������:"<<endl;
    cin>>inCode;
}

bool HuffmanTree::fileCode()   //���ļ��е������Ƶ�inCode��
{
    char *fileName=new char[100];
    cout<<"������Ҫ������ļ���:"<<endl;
    cin>>fileName;
    FILE *fp2;
    fp2=fopen(fileName,"r+");  //�Զ�д�ķ�ʽ���ļ�
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

void HuffmanTree::tranCode(FILE *fp)      //�����Ǵ�������
{
    int length=strlen(inCode);
    int head;
    int i;
    for(i=0;i<capacity;i++)    //�ҵ�ͷ����λ��head
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
                    cout<<"�����д���"<<endl;
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
    printf("\n**********     ��������������     ***********\n");
	printf("\n\n   =====================================  \n\n");
	printf("\n               0.�˳�ϵͳ.                  \n");
	printf("\n               1.���ļ�����.              \n");
	printf("\n               2.�����ַ�����.             \n");
	printf("\n               3.���ļ�����.              \n");
	printf("\n               4.������������.             \n");
	printf("\n   =====================================");
	printf("\n\n��ѡ��:\n");
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
                cout<<"������Ҫ������ļ���:"<<endl;
                cin>>fileName;
                FILE *fp;     //�ļ�ָ��
                fp=fopen(fileName,"r+");  //�Զ�д�ķ�ʽ��test.txt�ļ�

                if(fp==NULL)   //�ж��ļ��Ƿ�򿪳ɹ�
                {
                    cout<<"���ļ�ʧ��"<<endl;
                    break;
                }

                char *sentence=new char[100];
                int n=0;

                sentence[n]=fgetc(fp);     //���ļ��ж�ȡ�ַ�����
                while(!feof(fp))  //�жϸն�ȡ�����ַ��Ƿ�Ϊ�ļ�������
                {
                    n++;
                    sentence[n]=fgetc(fp);
                }

                sentence[n]='\0';  //�����һ���ļ�����������'\0'
                fclose(fp);

                cout<<"�����뱣�����ĸ��ļ�"<<endl;
                cin>>fileName;
                FILE *fp2;
                fp2=fopen(fileName,"r+");
                if(fp2==NULL)
                {
                    cout<<"���ļ�ʧ��"<<endl;
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
                cout<<"������һ���ַ���:"<<endl;
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
                    cout<<"���ļ�ʧ��"<<endl;
                    break;
                }
                tree->setCode();
                cout<<"�����뱣�����ĸ��ļ�:"<<endl;
                cin>>fileName;
                FILE *fp;
                fp=fopen(fileName,"r+");
                if(fp==NULL)
                {
                    cout<<"���ļ�ʧ��"<<endl;
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
                cout<<"����ȷ��������"<<endl;
                break;
            }
        }
        system("pause");
        system("cls");   //��ս���
        menu();
        cin>>order;
    }

    delete tree;

    system("pause");
    return 0;
}



































