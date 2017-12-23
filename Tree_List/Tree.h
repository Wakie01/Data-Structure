#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

/*����һ�ö������������2*n+1��ʾ�����ӣ�2*n+2��ʾ�к���*/
/*����������������������0��ʾ���û��ֵ��1��ʾ��ֵ*/

class Tree{
public:
    Tree(int size,int *root);
    ~Tree();
    int * SearchNode(int nodeIndex);  //Ѱ�ҽ��  ����ֵλint�ĵ�ַ  nodeIndex:����±�
    bool AddNode(int nodeIndex,int diretion,int *pNode); //direction��ʾ���������ӣ�1�������Һ��ӣ�2��  pNode��ʾ����Ľ��
    bool DeleteNode(int nodeIndex,int *pNode);
    void TreeTraverse();
private:
    int *m_pTree;
    int m_iSize;


};


#endif // TREE_H_INCLUDED
