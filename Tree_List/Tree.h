#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

/*对于一棵二叉树，其结点的2*n+1表示其左孩子，2*n+2表示有孩子*/
/*对于数组型树，在这里用0表示结点没有值，1表示有值*/

class Tree{
public:
    Tree(int size,int *root);
    ~Tree();
    int * SearchNode(int nodeIndex);  //寻找结点  返回值位int的地址  nodeIndex:结点下标
    bool AddNode(int nodeIndex,int diretion,int *pNode); //direction表示插入在左孩子（1）还是右孩子（2）  pNode表示插入的结点
    bool DeleteNode(int nodeIndex,int *pNode);
    void TreeTraverse();
private:
    int *m_pTree;
    int m_iSize;


};


#endif // TREE_H_INCLUDED
