#ifndef NODE_H
#define NODE_H

class Node
{
public:
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int val)
    {
        data = val;
        left = right = NULL;
        height = 1;
    }
};

#endif // NODE_H
