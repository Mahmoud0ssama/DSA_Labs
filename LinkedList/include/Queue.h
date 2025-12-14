#ifndef QUEUE_H
#define QUEUE_H
#include "Node.h"
using namespace std;


class Queue
{
private:
    Node* Front;
    Node* Rear;

public:
    ///********************** Constructor ************************///
    Queue()
    {
        Front = Rear = NULL;
    }
    ///************************* isEmpty **************************///
    bool isEmpty()
    {
        return (Front == NULL);
    }
    ///************************* Enqueue **************************///
    void enqueue(int data)
    {
        Node* node = new Node(data);
        node->next = NULL;

        if (isEmpty())
        {
            node->prev = NULL;
            Front = Rear = node;
        }
        else
        {
            node->prev = Rear;
            Rear->next = node;
            Rear = node;
        }
    }
    ///************************* Dequeue **************************///
    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }

        Node* temp = Front;
        int value = Front->data;

        Front = Front->next;

        if (Front == NULL) //isEmpty
        {
            Rear = NULL;
        }
        else
        {
            Front->prev = NULL;
        }

        delete temp;
        return value;
    }
    ///************************* Peak *****************************///
    int peak()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return Front->data;
    }
    ///************************* Reverse ***************************///
    void reverse()
    {
        if (isEmpty() || Front == Rear)
            return;

        Node* curr = Front;
        Node* temp = NULL;

        while (curr != NULL)
        {
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            curr = curr->prev;
        }

        temp = Front;
        Front = Rear;
        Rear = temp;
    }

};

#endif // QUEUE_H
