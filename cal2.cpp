#include <iostream>
using namespace std;

typedef struct Node
{
	int power;      //指数
	int factor;       //系数

} Nodes;   //创建结构体 包含 （int 型）指数 （int 型）系数

const int maxLength = 100;

class Line{

private:
	Nodes nodes[maxLength];  //     类内定义结构体数组
	int length;
public:
    Line() { length = 0; }
	~Line() {}
    Line sum(Line &a,Line &b);

    void setLength(int n);

	void creat(int n);//创建非空链表
	void display();//输出线性表
};

void Line::creat(int n){
    length=n;
    for(int i=0;i<length;i++){
        cout<<endl<<"输入第"<<(i+1)<<"个系数";
        cin>>nodes[i].factor;
        cout<<"输入第"<<(i+1)<<"个指数";
        cin>>nodes[i].power;
    }
    cout<<endl;
}

void Line::display(){
    int num=length;
    for(int i=0;i<num;i++){
        cout<<nodes[i].factor<<" * x^"<<nodes[i].power;
        if(i!=(num-1)){
            cout<<" + ";
        }
    }
    cout<<endl<<endl;
}

void Line::setLength(int n){
    length=n;
}

Line Line::sum(Line &a,Line &b){
    Line c;
    int num1,num2;
    int n=0,n1=0,n2=0;
    num1=a.length;
    num2=b.length;
    int maxPower=a.nodes[num1-1].power>=b.nodes[num2-1].power? a.nodes[num1-1].power:b.nodes[num2-1].power;

    for(int i=1;i<=maxPower;i++){
        int fa=0,fb=0;
        if(n1<num1){
            if(a.nodes[n1].power==i){
                fa=a.nodes[n1].factor;
                n1++;
            }
        }
        if(n2<num2){
            if(b.nodes[n2].power==i){
                fb=b.nodes[n2].factor;
                n2++;
            }
        }
        if((fa+fb)>0){
            c.nodes[n].power=i;
            c.nodes[n].factor=fa+fb;
            n++;
        }
    }
    c.setLength(n);
    return c;
}

int main(){
    Line aa,bb,cc;
    int n1;
    cout<<"请输入第一个多项式长度";
    cin>>n1;
    aa.creat(n1);
    cout<<"多项式 1"<<endl;
    aa.display();

    int n2;
    cout<<"请输入第二个多项式长度";
    cin>>n2;
    bb.creat(n2);
    cout<<"多项式 2"<<endl;
    bb.display();

    cc=aa.sum(aa,bb);
    cout<<"两个多项式之和为："<<endl;
    cc.display();
    return 0;
}

























