#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

#include"Contract.h"

class Node{
public:
    Contract data;  //涉及到data的都要注意
    Node *next;
    void printNode();
};


#endif // NODE_H_INCLUDED
