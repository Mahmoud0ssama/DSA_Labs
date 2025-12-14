#ifndef BST_H
#define BST_H
#include "Node.h"

using namespace std;

class BST
{
public:
    Node* root;

    //Ctor
    BST()
    {
       root = NULL;
    }

    ///************************* Insert *************************///
    Node* Insert(Node* r, emp Data)
    {
        // if position found: create and return new node
        if (r == NULL)
            return new Node(Data);

        // go left
        if (Data.ID < r->data.ID)
            r->left = Insert(r->left, Data);

        // go right
        else
            r->right = Insert(r->right, Data);

        return r;
    }

    //no need to keep entering the root
    void Insert(emp Data)
    {
        root = Insert(root, Data);
    }

    ///*********************** Traversal ************************///
    void Trvrs(Node* r)
    {
        if (r == NULL)
            return;

        cout << r->data.ID << " - " << r->data.Name << " - " << r->data.Age << endl;

        Trvrs(r->left);
        Trvrs(r->right);
    }

    ///************************ Search **************************///
    Node* Search(Node* r, int key)
    {
        if (r == NULL)
            return NULL;
        else if (r->data.ID == key)
            return r;
        else if (key < r->data.ID)
            return Search(r->left, key);
        else
            return Search(r->right, key);
    }

    bool Search(int key)
    {
        Node* result = Search(root, key);
        return result != NULL;
    }

    ///************************* Min ****************************///
    Node* Getmin(Node* r)
    {
        if (r == NULL)
            return NULL;

        while (r->left != NULL)
            r = r->left;

        return r;
    }

    ///************************* Max ****************************///
    Node* Getmax(Node* r)
    {
        if (r == NULL)
            return NULL;

        while (r->right != NULL)
            r = r->right;

        return r;
    }

    ///************************ Delete **************************///
    Node* Delete(Node* r, int key)
    {
        if (r == NULL)
            return NULL;

        if (key < r->data.ID)
            r->left = Delete(r->left, key);

        else if (key > r->data.ID)
            r->right = Delete(r->right, key);

        else
        {
            // leaf
            if (r->left == NULL && r->right == NULL)
            {
                delete r;
                return NULL;
            }

            // only right child
            if (r->left == NULL && r->right != NULL)
            {
                Node* tmp = r->right;
                delete r;
                return tmp;
            }

            // only left child
            if (r->left != NULL && r->right == NULL)
            {
                Node* tmp = r->left;
                delete r;
                return tmp;
            }

            // two children
            Node* Max = Getmax(r->left);
            r->data = Max->data;
            r->left = Delete(r->left, Max->data.ID);
        }

        return r;
    }
};

#endif // BST_H
