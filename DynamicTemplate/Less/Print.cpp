#include "Print.h"

template <typename T1>
void print(T1 **matrix, int height, int width)
{
    for (size_t i = 0; i < height; ++i)
    {
        for (size_t j = 0; j < width; ++j)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}

template <typename T1>
void PrintArray(T1 *arr, int *size)
{
    for (size_t i = 0; i < *size; i++)
        cout << arr[i] << endl;
}

void printString(char *string)
{
    cout << string << endl;
}