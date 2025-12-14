#ifndef AVL_H
#define AVL_H

#include <iostream>
#include "Node.h"
using namespace std;

class AVL
{
public:
    Node* root;

    AVL()
    {
        root = NULL;
    }

    ///******************** Height ************************///
    int Height(Node* n)
    {
        if (n == NULL)
            return 0;

        return n->height;
    }

    int BalanceFactor(Node* n)
    {
        if (n == NULL)
            return 0;

        return Height(n->left) - Height(n->right);
    }

    ///******************** Rotations **********************///
    Node* RotateRight(Node* y)
    {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        // update heights
        y->height = 1 + max(Height(y->left), Height(y->right));
        x->height = 1 + max(Height(x->left), Height(x->right));

        return x;
    }

    Node* RotateLeft(Node* x)
    {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        // update heights
        x->height = 1 + max(Height(x->left), Height(x->right));
        y->height = 1 + max(Height(y->left), Height(y->right));

        return y;
    }

    ///******************** Insert *************************///
    Node* Insert(Node* r, int key)
    {
        if (r == NULL)
            return new Node(key);

        if (key < r->data)
            r->left = Insert(r->left, key);
        else if (key > r->data)
            r->right = Insert(r->right, key);
        else
            return r; // no duplicates

        // 2) Update height
        r->height = 1 + max(Height(r->left), Height(r->right));

        // 3) Balance
        int bf = BalanceFactor(r);

        // LL
        if (bf > 1 && key < r->left->data)
            return RotateRight(r);

        // RR
        if (bf < -1 && key > r->right->data)
            return RotateLeft(r);

        // LR
        if (bf > 1 && key > r->left->data)
        {
            r->left = RotateLeft(r->left);
            return RotateRight(r);
        }

        // RL
        if (bf < -1 && key < r->right->data)
        {
            r->right = RotateRight(r->right);
            return RotateLeft(r);
        }

        return r;
    }

    void Insert(int key)
    {
        root = Insert(root, key);
    }

    ///******************** Min ****************************///
    Node* GetMin(Node* r)
    {
        while (r->left != NULL)
            r = r->left;
        return r;
    }

    ///******************** Delete *************************///
    Node* Delete(Node* r, int key)
    {
        if (r == NULL)
            return r;

        if (key < r->data)
            r->left = Delete(r->left, key);
        else if (key > r->data)
            r->right = Delete(r->right, key);
        else
        {
            // one or zero child
            if (r->left == NULL || r->right == NULL)
            {
                Node* temp = r->left ? r->left : r->right;

                if (temp == NULL)
                {
                    temp = r;
                    r = NULL;
                }
                else
                    *r = *temp;

                delete temp;
            }
            else
            {
                Node* temp = GetMin(r->right);
                r->data = temp->data;
                r->right = Delete(r->right, temp->data);
            }
        }

        if (r == NULL)
            return r;

        // update height
        r->height = 1 + max(Height(r->left), Height(r->right));

        int bf = BalanceFactor(r);

        // LL
        if (bf > 1 && BalanceFactor(r->left) >= 0)
            return RotateRight(r);

        // LR
        if (bf > 1 && BalanceFactor(r->left) < 0)
        {
            r->left = RotateLeft(r->left);
            return RotateRight(r);
        }

        // RR
        if (bf < -1 && BalanceFactor(r->right) <= 0)
            return RotateLeft(r);

        // RL
        if (bf < -1 && BalanceFactor(r->right) > 0)
        {
            r->right = RotateRight(r->right);
            return RotateLeft(r);
        }

        return r;
    }

    void Delete(int key)
    {
        root = Delete(root, key);
    }

    ///******************** Traversal **********************//
    void Trvrs(Node* r)
    {
        if (r == NULL) return;
        cout << r->data << " ";
        Trvrs(r->left);
        Trvrs(r->right);
    }

    void Print()
    {
        Trvrs(root);
        cout << endl;
    }
};

#endif
