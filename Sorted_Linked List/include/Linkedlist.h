#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "Node.h"

using namespace std;

class LinkedList
{
public:
    LinkedList()
    {
        head = tail = NULL;
    }

    ///************************* Insert **************************///
    void add(int data)
    {
        Node* node = new Node(data);

        // empty list
        if (head == NULL)
        {
            head = tail = node;
            return;
        }

        // insert before head
        if (data <= head->data)
        {
            node->next = head;
            head->prev = node;
            head = node;
            return;
        }

        // insert after tail
        if (data >= tail->data)
        {
            node->prev = tail;
            tail->next = node;
            tail = node;
            return;
        }

        // find insertion point
        Node* current = head->next;
        while (current != NULL && current->data < data)
            current = current->next;

        // insert before current
        node->next = current;
        node->prev = current->prev;
        current->prev->next = node;
        current->prev = node;
    }

    ///************************ Display **************************///
    void Display()  // O(n)
    {
        Node* current = head;
        while (current != NULL)
        {
            cout << current->data << "   ";
            current = current->next;
        }
        cout << endl;
    }

    ///************************* Search **************************///
    bool Search(int data)
    {
        return (getNode(data) != NULL);
    }

    ///************************* Delete **************************///
    bool Delete(int data)
    {
        Node* node = getNode(data);
        if (node != NULL)
        {
            // one element
            if (head == node && tail == node)
            {
                head = tail = NULL;
            }
            // head
            else if (node == head)
            {
                head = node->next;
                if (head) head->prev = NULL;
            }
            // tail
            else if (node == tail)
            {
                tail = node->prev;
                if (tail) tail->next = NULL;
            }
            // in between
            else
            {
                node->prev->next = node->next;
                node->next->prev = node->prev;
            }

            delete node;
            return true;
        }
        return false;
    }

    ///************************** Count ***************************///
    int count()
    {
        int c = 0;
        Node* current = head;
        while (current != NULL)
        {
            c++;
            current = current->next;
        }
        return c;
    }

    int getDataByIndex(int index)
    {
        if (index < 0) return -1;
        Node* current = head;
        int i = 0;
        while (current != NULL)
        {
            if (i == index) return current->data;
            current = current->next;
            i++;
        }
        return -1;
    }


    ///******************** Reverse in place **********************///
    void ReverseinP()
    {
        Node* current = head;
        Node* temp = NULL;

        while (current != NULL)
        {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev; // moved to old next
        }

        temp = head;
        head = tail;
        tail = temp;
    }

    ///************************ Reverse ***************************///
    LinkedList* Reverse()
    {
        LinkedList* rev = new LinkedList();
        Node* current = tail;
        while (current != NULL)
        {
            rev->add(current->data);
            current = current->prev;
        }
        return rev;
    }

    ///******************* Remove K-th element ********************///
    void removeKth(int k)
    {
        if (k <= 0 || head == NULL) return;

        Node* current = head;
        int Count = 1;
        while (current != NULL)
        {
            Node* next = current->next;
            if (Count % k == 0)
            {
                if (current == head && current == tail)
                {
                    head = tail = NULL;
                }
                else if (current == head)
                {
                    head = current->next;
                    if (head) head->prev = NULL;
                }
                else if (current == tail)
                {
                    tail = current->prev;
                    if (tail) tail->next = NULL;
                }
                else
                {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }
                delete current;
            }
            current = next;
            Count++;
        }
    }

private:
    Node* head;
    Node* tail;

    Node* getNode(int data)
    {
        Node* current = head;
        while (current != NULL)
        {
            if (data == current->data) return current;
            current = current->next;
        }
        return NULL;
    }
};

#endif // LINKEDLIST_H
