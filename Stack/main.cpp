#include <iostream>
#include "LinkedList.h"
#include "Stack.h"
using namespace std;

int main()
{
    Stack * stc = new Stack(5);

    // 10    5    -20
    stc->Push(10);
    stc->Push(5);
    stc->Push(-20);

    int popvalue;
    if(stc->Pop(popvalue))
        cout<<popvalue;    // -20

    if(stc->Pop(popvalue))
        cout<<popvalue;    // 5

    if(stc->Peek(popvalue))
        cout<<popvalue;    // 10

    if(!stc->Pop(popvalue))
        cout<<"stack is empty";

    else cout<<popvalue;


}
