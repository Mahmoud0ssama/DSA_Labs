#include <iostream>
#include "BST.h"

using namespace std;

int main()
{
    BST tree;

    emp e1(10, "MMDKDO", 25);
    emp e2(5,  "MDKJADM", 30);
    emp e3(20, "OKJAM", 28);
    emp e4(3,  "NADNLSA", 22);
    emp e5(15, "NSNSLMS", 31);

    tree.Insert(e1);
    tree.Insert(e2);
    tree.Insert(e3);
    tree.Insert(e4);
    tree.Insert(e5);

    cout << "Traversal: \nID - Name  - Age \n";
    tree.Trvrs(tree.root);
    cout << endl;

    cout << "Search for ID 20: " << (tree.Search(20) ? "Found" : "Not Found") << endl;
    cout << "Search for ID 99: " << (tree.Search(99) ? "Found" : "Not Found") << endl ;

    cout << "\nMinimum ID employee: ";
    Node* mn = tree.Getmin(tree.root);
    if (mn)
        cout << mn->data.ID << " - " << mn->data.Name << endl;

    cout << "Maximum ID employee: ";
    Node* mx = tree.Getmax(tree.root);
    if (mx)
        cout << mx->data.ID << " - " << mx->data.Name << endl;

    cout << "\nDeleting Leaf: \n";
    tree.root = tree.Delete(tree.root, 3);
    tree.Trvrs(tree.root);
    cout << endl;

    cout << "Deleting, Case 1 child:\n";
    tree.root = tree.Delete(tree.root, 20);
    tree.Trvrs(tree.root);
    cout << endl;

    cout << "Deleting, Case 2 children:\n";
    tree.root = tree.Delete(tree.root, 10);
    tree.Trvrs(tree.root);
    cout << endl;

    return 0;
}

