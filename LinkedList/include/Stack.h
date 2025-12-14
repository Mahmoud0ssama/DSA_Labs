#ifndef STACK_H
#define STACK_H
#include "LinkedList.h"
using namespace std;

class Stack
{
private:
    Node* top;

public:
    ///********************** Constructor ************************///
    Stack()
    {
        top = NULL;
    }
    ///************************* isEmpty **************************///
    bool isEmpty()
    {
        return (top == NULL);
    }
    ///*************************** Push ***************************///
    void push(int data)
    {
        Node* node = new Node(data);
        node->next = top; //next points to the element below me in stack
        top = node;
    }
    ///*************************** Pop ****************************///
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        Node* temp = top;            //save address of current top
        int value = top->data;       //return value
        top = top->next;             //move top to next node
        delete temp;                 //delete the previous top node

        return value;
    }
    ///*************************** Peak ***************************///
    int peak()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return -1;
        }

        return top->data;
    }
};


#endif // STACK_H
