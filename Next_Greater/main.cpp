#include <iostream>
#include "Stack_Arr.h"

using namespace std;

void nextGreaterElement(int arr[], int n, int nge[])
{
    Stack st(n);

    for (int i = n - 1; i >= 0; --i)
    {
        int topVal; //for return value of peek

        ///peek has isEmpty condition and returns topVal
        while (st.Peek(topVal) && topVal <= arr[i])
        {
            int temp; // for return value of pop
            st.Pop(temp);
        }

        if (st.Peek(topVal))
            nge[i] = topVal;
        else
            nge[i] = -1;

        st.Push(arr[i]);
    }
}


int main()
{
    int arr1[] = {1, 3, 2, 4};
    int n1 = 4;
    cout << "My array: ";
    for (int i = 0; i < n1; i++)
        cout << arr1[i] << " ";
    cout << endl;

    int nge1[n1];

    nextGreaterElement(arr1, n1, nge1);

    cout << "Next Greater Element: ";
    for (int i = 0; i < n1; i++)
        cout << nge1[i] << " ";
    cout << endl;

    return 0;
}
