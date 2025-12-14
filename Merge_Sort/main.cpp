#include <iostream>

using namespace std;

void MergeArr(int* Arr, int LF, int LE, int RF, int RE)
{
    int Index = LF;
    int TempSize = RE - LF + 1;
    int mid = TempSize/2;

    int* temp = new int[TempSize];
    int k = 0;

    while ((LF <= LE) && (RF <=RE))
    {
        if (Arr[LF] < Arr[RF])
        {
             temp[k] = Arr[LF];
             LF++;
        }
        else
        {
            temp[k] = Arr[RF];
            RF++;
        }
        k++;
    }
    while (LF <= LE)
    {
        temp[k++] = Arr[LF++];
    }

    while (RF <= RE)
    {
        temp[k++] = Arr[RF++];
    }

    for (int i = 0; i < TempSize; i++)
    {
        Arr[Index + i] = temp[i];
    }

    delete[] temp;
}

void MergeSort(int arr[], int LF, int RE)
{
    if (LF >= RE)
        return;

    int LE = (LF + RE) / 2;
    int RF = LE + 1;

    MergeSort(arr, LF, LE);
    MergeSort(arr, RF, RE);

    MergeArr(arr, LF, LE, RF, RE); // merge halves in-place
}

int main()
{
    int arr[] = { 38, 27, 43, 3, 9, 82, 10 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before sorting: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    MergeSort(arr, 0, n - 1);

    cout << "\n\nAfter sorting: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;
    return 0;
}
