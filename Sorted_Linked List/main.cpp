#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
    LinkedList lst;

    // insert out of order
    lst.add(50);
    lst.add(10);
    lst.add(40);
    lst.add(20);
    lst.add(30);

    cout << "List after sorted insertion: " ;
    lst.Display();   // Expected: 10 20 30 40 50

    return 0;
}
