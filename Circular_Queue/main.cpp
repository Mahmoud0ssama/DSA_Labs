#include <iostream>

using namespace std;

class CircularQueue
{
    int* Q;
    int Size;
    int Head;
    int Tail;
    int Count;

public:
    CircularQueue()
    {
        Size = 5;
        Q = new int[Size];
        Head = Tail = Count = 0;
    }

    bool IsEmpty()
    {
        return Count == 0;
    }

    bool IsFull()
    {
        return Count == Size;
    }

    void EnQueue(int val)
    {
        if (IsFull())
        {
            cout << "CircularQueue is full\n";
            return;
        }

        Q[Tail] = val;
        Tail = (Tail + 1) % Size;
        Count++;
    }

    int DeQueue()
    {
        if (IsEmpty())
        {
            cout << "CircularQueue is empty\n";
            return -1;
        }

        int ret = Q[Head];
        Head = (Head + 1) % Size;
        Count--;
        return ret;
    }

    int Peak()
{
    if (IsEmpty())
    {
        cout << "CircularQueue is empty\n";
        return -1;
    }
    return Q[Head];
}
};

int main()
{
    CircularQueue q;

    q.EnQueue(10);
    q.EnQueue(20);
    q.EnQueue(30);

    cout << "DeQueue: " << q.DeQueue() << endl;
    cout << "DeQueue: " << q.DeQueue() << endl;

    cout << "Peak Value: " << q.Peak() << endl;

    cout << "DeQueue: " << q.DeQueue() << endl;
    cout << "DeQueue: " << q.DeQueue() << endl;


    return 0;
}
