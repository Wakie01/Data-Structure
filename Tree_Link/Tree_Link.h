#ifndef TREE_LINK_H_INCLUDED
#define TREE_LINK_H_INCLUDED

#include"Node.h"

class Tree{
public:
    Tree();
    ~Tree();
    Node *SearchNode(int nodeIndex);
    bool AddNode(int nodeIndex,int direction,Node *pNode);
    bool DeleteNode(int nodeIndex,Node *pNode);
    void PreorderTraversal ();  //前序遍历
    void InorderTraversal();   //中序遍历
    void PostorderTraversal();   //后序遍历
private:
    Node *m_pRoot;   //根结点
};

#endif // TREE_LINK_H_INCLUDED
