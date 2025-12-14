#include <iostream>

using namespace std;

int Partition(int arr[], int left, int right)
{
    int pivot = arr[(left + right) / 2];
    int i = left;
    int j = right;

    while (i <= j)
    {
        while (arr[i] < pivot)
            i++;

        while (arr[j] > pivot)
            j--;

        if (i <= j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;

            i++;
            j--;
        }
    }
    return i;
}

void QuickSort(int arr[], int left, int right)
{
    if (left >= right)
        return;

    int index = Partition(arr, left, right);

    QuickSort(arr, left, index - 1);

    QuickSort(arr, index, right);
}

int main()
{
    int arr[] = {20, 2, 7, 12, 15, 1, 6, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before sorting: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    QuickSort(arr, 0, n - 1);

    cout << "\nAfter sorting: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
