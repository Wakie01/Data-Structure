#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

class Node{  //定义结点
public:
    Node();  //初始化
    int index;   //索引
    int data;    //内容
    Node *pLChild;     //左孩子指针
    Node *pRChild;     //右孩子指针
    Node *pParent;      //父亲指针
    Node *SearchNode(int nodeIndex);
    void DeleteNode();
    void PreorderTraversal ();
    void InorderTraversal();
    void PostorderTraversal();
};

#endif // NODE_H_INCLUDED
