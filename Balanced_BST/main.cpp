#include <iostream>
#include "Balanced_BST.h"

using namespace std;

int main()
{
    AVL t;
    t.Insert(30);
    t.Insert(20);
    t.Insert(25); //LR rotation

    t.Print(); // 25 20 30

    t.Delete(20);
    t.Print();

    return 0;
}

