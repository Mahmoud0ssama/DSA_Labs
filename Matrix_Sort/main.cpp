#include <iostream>
#include <algorithm>

#define cols 3

using namespace std;

void sortMatrix(int mat[][cols], int rows)
{
    int Size = rows * cols;
    int* arr = new int[Size];

    int k = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            arr[k++] = mat[i][j];

    sort(arr, arr + Size);

    k = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            mat[i][j] = arr[k++];

    delete[] arr;
}

int main()
{
    int mat[3][3] =
    {   {5, 4, 7},
        {1, 3, 8},
        {2, 9, 6}   };

    sortMatrix(mat, 3);

    cout << "Sorted matrix:\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}
