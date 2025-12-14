#include <iostream>
#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"

using namespace std;

int main()
{
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    q.reverse();

    cout << "Queue after reverse: ";
    while (!q.isEmpty())
    {
        cout << q.dequeue() << " ";
    }

    cout << endl;

/*
    cout << "************************* Stack **************************\n";
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Pop: " << s.pop() << endl;
    cout << "Pop: " << s.pop() << endl;

    cout << "Top element: " << s.peak() << endl;

    cout << "Pop: " << s.pop() << endl;
    cout << "Pop: " << s.pop() << endl;


    cout << "************************* Queue **************************\n";
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Dequeuing: " << q.dequeue() << endl;
    cout << "Dequeuing: " << q.dequeue() << endl;

    cout << "Peak front: " << q.peak() << endl;

    cout << "Dequeuing: " << q.dequeue() << endl;
    cout << "Dequeuing: " << q.dequeue() << endl;
*/
    return 0;
}
