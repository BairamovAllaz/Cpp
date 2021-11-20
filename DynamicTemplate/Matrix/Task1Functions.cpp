#include "Task1Functions.h"
template <typename T1, typename T2>
T1 *addNum(T1 *arr, T2 num, int *size)
{
    ++(*size);
    T1 *newarr = new T1[*size];
    newarr[*size - 1] = num;
    for (size_t i = 0; i < *size - 1; i++)
        newarr[i] = arr[i];
    delete[] arr;
    arr = newarr;
    return arr;
}
template <typename T1, typename T2>
T1 *push_front(T1 *arr, T2 num, int *size)
{
    ++(*size);
    T1 *newarr = new T1[*size];
    newarr[0] = num;
    for (size_t i = 0; i < *size; i++)
        newarr[i + 1] = arr[i];
    delete[] arr;
    arr = newarr;
    return arr;
}
template <typename T1, typename T2>
T1 *IndexAddNum(T1 *arr, int index, T2 number, int *size)
{
    ++(*size);
    T1 *newarr = new T1[*size];
    for (size_t i = 0; i < index; i++)
        newarr[i] = arr[i];
    newarr[index] = number;
    for (size_t i = index; i < *size; i++)
        newarr[i + 1] = arr[i];
    delete[] arr;
    arr = newarr;
    return arr;
}
template <typename T1>
T1 *DeleteLast(T1 *arr, int *size)
{
    --(*size);
    T1 *newarr = new T1[*size];
    for (size_t i = 0; i < *size; i++)
        newarr[i] = arr[i];
    delete[] arr;
    arr = newarr;
    return arr;
}
template <typename T1>
T1 *DeleteFirst(T1 *arr, int *size)
{
    --(*size);
    T1 *newarr = new T1[*size];
    for (size_t i = 0; i < *size; i++)
        newarr[i] = arr[i + 1];
    delete[] arr;
    arr = newarr;
    return arr;
}
template <typename T1>
T1 *DeleteIndex(T1 *arr, int index, int *size)
{
    --(*size);
    T1 *newarr = new T1[*size];
    for (size_t i = 0; i < index; i++)
        newarr[i] = arr[i];
    for (size_t i = index; i < *size; i++)
        newarr[i] = arr[i + 1];
    delete[] arr;
    arr = newarr;
    return arr;
}
int SizeOfString(char *string)
{
    int length = 0;
    while (*string)
    {
        ++length;
        ++string;
    }
    return length;
}
