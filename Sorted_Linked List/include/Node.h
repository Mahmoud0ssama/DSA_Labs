#ifndef NODE_H
#define NODE_H
#include <iostream>
class Node
{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int _data)
    {
        data = _data;
        next = NULL;
        prev = NULL;
    }
};

#endif // NODE_H
