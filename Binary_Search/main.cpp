#include <iostream>

using namespace std;

int BinarySearchItr(int arr[], int Size, int key)
{
    int left = 0;
    int right = Size - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key)
            return mid;

        else if (key < arr[mid])
            right = mid - 1;

        else
            left = mid + 1;
    }

    return -1;
}

int BinarySearchRec(int arr[], int left, int right, int key)
{
    if (left > right)
        return -1;

    int mid = left + (right - left) / 2;

    if (arr[mid] == key)
        return mid;

    if (key < arr[mid])
        return BinarySearchRec(arr, left, mid - 1, key);
    else
        return BinarySearchRec(arr, mid + 1, right, key);
}

int main()
{
    int arr[] = { 3, 9, 10, 27, 38, 43, 82};
    int n = sizeof(arr) / sizeof(arr[0]);

    int key = 85;

    int pos = BinarySearchItr(arr, n, key);
    if (pos != -1)
        cout << "Iterative, Found at index: " << pos << endl;
    else
        cout << "Not found\n";

    int posrec = BinarySearchRec(arr, 0, n - 1, key);
    if (posrec != -1)
        cout << "Recursive, Found at index: " << posrec << endl;
    else
        cout << "Not found" << endl;

    return 0;
}
