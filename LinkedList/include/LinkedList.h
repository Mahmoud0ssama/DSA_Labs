#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
using namespace std;
class LinkedList
{
    public:
        LinkedList()
        {
            head = tail = NULL;
        }
        ///************************** Insert *****************************///
        void add(int data)  // O(1)
        {
            // insert new node
            Node * node = new Node(data);
            // List if it was empty
            if(head == NULL)
            {
                head = tail = node;
            }
            else
            {
                // connect it
                node->prev = tail;
                tail->next = node;
                tail = node;
            }
        }
        ///************************** Display ****************************///
        // for testing
        void Display()  // O(n)
        {
            Node * current = head;
            // Loop
            while(current!= NULL)
            {
                // print data
                cout<<current->data<<"   ";

                //move next
                current = current->next;
            }
            cout << endl ;
        }
        ///************************** Search *****************************///
        bool Search(int data)
        {
            // getNode(Data)
            if(getNode(data)!=NULL)
                return true;
            else return false;
        }
        ///************************** Delete *****************************///
        bool Delete(int data)
        {
            // search
            Node * node = getNode(data);
            if(node!=NULL)
            {
                // delete
                //one element
                if(head == node && tail == node)
                {
                    head = tail = NULL;
                }

                // head
                else if(node == head)
                {
                    head = node->next;
                    head->prev = NULL;
                }

                // tail
                else if(node == tail)
                {
                     tail = node->prev;
                     tail->next = NULL;
                }

                // inbetween
                else
                {
                    node->prev->next = node->next;
                    node->next->prev = node->prev;
                }

                delete node;
                return true;
            }
            else return false;
        }
        ///************************ Insert After **************************///
        void insertAfter (int data, int afterData)
        {
            Node* current = getNode(afterData);

            // if afterData not found  do nothing
            if (current == NULL)
                return;

            Node* node = new Node(data);

            // inserting after tail
            if (current == tail)
            {
                node->prev = tail;
                tail->next = node;
                tail = node;
            }
            // inserting in the middle
            else
            {
                node->next = current->next;
                node->prev = current;
                current->next->prev = node;
                current->next = node;
            }
        }
        ///*********************** Insert Before **************************///
        void insertBefore (int data, int beforeData)
        {
            Node* current = getNode(beforeData);

            if (current == NULL)
                return;

            Node* node = new Node(data);
            // inserting before head
            if (current == head)
            {
                node->next = head;
                node->prev = NULL;
                head->prev = node;
                head = node;
            }
            // inserting in the middle
            else
            {
                node->next = current;
                node->prev = current->prev;
                current->prev->next = node;
                current->prev = node;
            }
        }
        ///*************************** Count ****************************///
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
        ///*************************** Index ****************************///
        int getDataByIndex(int index)
        {
            if (index < 0)
                return -1;

            Node* current = head;
            int i = 0;

            while (current != NULL)
            {
                if (i == index)
                {
                    return current->data;
                }
                current = current->next;
                i++;
            }
            return -1;
        }
        ///********************** Reverse In Place **********************///
        void reverse()
        {
            Node* current = head;
            Node* temp = NULL;

            // swap next and prev for all nodes
            while (current != NULL)
            {
                temp = current->prev;
                current->prev = current->next;
                current->next = temp;

                current = current->prev;  //next node is prev after swap
            }

            temp = head;
            head = tail;
            tail = temp;
        }
        ///************************** Reverse ***************************///
        LinkedList* Reverse()
        {
            LinkedList* rev = new LinkedList();

            Node* current = tail;

            while (current != NULL)
            {
                rev->add(current->data);  // add to new list
                current = current->prev;
            }
            return rev;
        }
        ///********************** Remove K-th Node **********************///
        void removeKth(int k)
        {
            if (k <= 0 || head == NULL)
                return;

            Node* current = head;
            int Count = 1;

            while (current != NULL)
            {
                Node* next = current->next;

                if (Count % k == 0)
                {
                    // delete current node
                    if (current == head && current == tail)
                    {
                        head = tail = NULL;
                    }
                    else if (current == head)
                    {
                        head = current->next;
                        head->prev = NULL;
                    }
                    else if (current == tail)
                    {
                        tail = current->prev;
                        tail->next = NULL;
                    }
                    else
                    {
                        current->prev->next = current->next;  //my prev next = my next
                        current->next->prev = current->prev;  //my next prev = my prev
                    }
                    delete current;
                }

                current = next;
                Count++;
            }
        }



        ///************************** Private ***************************///
    private:
        Node * head;
        Node * tail;

        Node* getNode(int data)
        {
            Node * current = head;
            while(current != NULL)
            {
                // found
                if(data == current->data)
                    return current;
                //move next
                current = current->next;
            }
            return NULL;
        }
};

#endif // LINKEDLIST_H
