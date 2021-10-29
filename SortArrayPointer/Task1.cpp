#include <iostream>
#include <ctime>
using namespace std;
void fillarray(int *arr, int *size);
void PrintArray(int *arr, int *size);
int *addNum(int *arr, int num, int *size);
int *push_front(int *arr, int num, int *size);
int *IndexAddNum(int *arr, int index, int number, int *size);
int *DeleteLast(int *arr, int *size);
int *DeleteFirst(int *arr, int *size);
int *DeleteIndex(int *arr, int index, int *size);
int main()
{
    srand(time(0));
    int size;
    int op;
    cout << "Enter size of array: ";
    cin >> size;
    int *arr = new int[size];
    fillarray(arr, &size);
    PrintArray(arr, &size);
    cout << "Enter a operation 1-pushback 2-pushfront 3-insert 4-pop-back 5-pop-front 6-erase 7 -exit: ";
    cin >> op;
    while (op > 7)
    {
        cout << "Enter operatrion again : ";
        cin >> op;
    }
    while (true)
    {
        if (op == 7)
        {
            break;
        }
        switch (op)
        {
        case 1:
            int num;
            cout << "Enter a number for add: ";
            cin >> num;
            arr = addNum(arr, num, &size);
            PrintArray(arr, &size);
            break;
        case 2:
            int num1;
            cout << "Enter a number for add: ";
            cin >> num1;
            arr = push_front(arr, num1, &size);
            PrintArray(arr, &size);
            break;
        case 3:
            int num3, index;
            cout << "Enter a index for add number: ";
            cin >> index;
            while (index > size)
            {
                cout << "Enter a index again : ";
                cin >> index;
            }
            cout << "Enter a number for add: ";
            cin >> num3;
            arr = IndexAddNum(arr, index, num3, &size);
            PrintArray(arr, &size);
            break;
        case 4:
            arr = DeleteLast(arr, &size);
            PrintArray(arr, &size);
            break;
        case 5:
            arr = DeleteFirst(arr, &size);
            PrintArray(arr, &size);
            break;
        case 6:
            int indexl;
            cout << "Enter a index for delete: ";
            cin >> indexl;
            arr = DeleteIndex(arr, indexl, &size);
            PrintArray(arr, &size);
            break;
        default:
        {
            break;
        }
        }
        cout << "Enter a operation 1-pushback 2-pushfront 3-insert 4-pop-back 5-pop-front 6-erase 7 -exit: ";
        cin >> op;
        while (op > 7)
        {
            cout << "Enter operatrion again : ";
            cin >> op;
        }
    }

    delete[] arr;
    return 0;
}

void fillarray(int *arr, int *size)
{
    for (size_t i = 0; i < *size; i++)
        arr[i] = rand() % 20 + 1;
}
void PrintArray(int *arr, int *size)
{
    for (size_t i = 0; i < *size; i++)
        cout << arr[i] << endl;
}
int *addNum(int *arr, int num, int *size)
{
    ++(*size);
    int *newarr = new int[*size];
    int *Narr = arr;
    newarr[*size - 1] = num;
    for (size_t i = 0; i < *size - 1; i++)
        newarr[i] = arr[i];
    arr = newarr;
    newarr = Narr;
    delete[] newarr;
    return arr;
}
int *push_front(int *arr, int num, int *size)
{
    ++(*size);
    int *newarr = new int[*size];
    int *an = arr;
    newarr[0] = num;
    for (size_t i = 0; i < *size; i++)
        newarr[i + 1] = arr[i];
    arr = newarr;
    newarr = an;
    delete[] newarr;
    return arr;
}
int *IndexAddNum(int *arr, int index, int number, int *size)
{
    ++(*size);
    int *newarr = new int[*size];
    int *narr = arr;
    for (size_t i = 0; i < index; i++)
        newarr[i] = arr[i];
    newarr[index] = number;
    for (size_t i = index; i < *size; i++)
        newarr[i + 1] = arr[i];
    arr = newarr;
    newarr = narr;
    delete[] newarr;
    return arr;
}
int *DeleteLast(int *arr, int *size)
{
    --(*size);
    int *newarr = new int[*size];
    int *narr = arr;

    for (size_t i = 0; i < *size; i++)
        newarr[i] = arr[i];
    arr = newarr;
    newarr = narr;
    delete[] newarr;
    return arr;
}
int *DeleteFirst(int *arr, int *size)
{
    --(*size);
    int *newarr = new int[*size];
    int *narr = arr;
    for (size_t i = 0; i < *size; i++)
        newarr[i] = arr[i + 1];
    arr = newarr;
    newarr = narr;
    delete[] newarr;
    return arr;
}
int *DeleteIndex(int *arr, int index, int *size)
{
    --(*size);
    int *newarr = new int[*size];
    int *narr = arr;
    for (size_t i = 0; i < index; i++)
        newarr[i] = arr[i];
    for (size_t i = index; i < *size; i++)
        newarr[i] = arr[i + 1];
    arr = newarr;
    newarr = narr;
    delete[] newarr;
    return arr;
}