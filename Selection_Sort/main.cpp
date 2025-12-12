#include <iostream>

using namespace std;

void Selection_Sort(int *arr, int Size);
void Swap(int& a, int& b);

int main()
{
    int Arr_Size = 5;
    int ARRAY[Arr_Size] = {1, 5, 10, 6, 9};
    Selection_Sort(ARRAY, Arr_Size);

    for (int i = 0; i < Arr_Size; i++)
        cout << ARRAY[i] << " ";


}

void Swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}


void Selection_Sort(int *arr, int Size)
{
    int minIndex;
    for (int i = 0; i < Size -1 ; i++)
    {
        minIndex = i;

        for (int j = i+1; j < Size ; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j ;
        }
        Swap(arr[minIndex], arr[i]);
    }
}

