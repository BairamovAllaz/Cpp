#include "Print.h"
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