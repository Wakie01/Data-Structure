#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

class Node{  //������
public:
    Node();  //��ʼ��
    int index;   //����
    int data;    //����
    Node *pLChild;     //����ָ��
    Node *pRChild;     //�Һ���ָ��
    Node *pParent;      //����ָ��
    Node *SearchNode(int nodeIndex);
    void DeleteNode();
    void PreorderTraversal ();
    void InorderTraversal();
    void PostorderTraversal();
};

#endif // NODE_H_INCLUDED