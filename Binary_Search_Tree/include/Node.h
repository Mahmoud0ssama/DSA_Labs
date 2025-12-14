#ifndef NODE_H
#define NODE_H
#include <iostream>
#include "Emp.h"

class Node
{
public:
    emp data;
    Node* right;
    Node* left;

    Node(emp e)
    {
        data = e;
        left = right = NULL;
    }
};


#endif // NODE_H
