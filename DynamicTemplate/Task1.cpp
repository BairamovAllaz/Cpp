#include <iostream>
#include <ctime>
using namespace std;

template <typename T1, typename T2>
void fillarray(T1 *arr, T2 *size,T1 ran)
{
    for (size_t i = 0; i < *size; i++)
        arr[i] = rand() % 20 + ran;
}

template <typename T1, typename T2>
void PrintArray(T1 *arr, T2 *size)
{
    for (size_t i = 0; i < *size; i++)
        cout << arr[i] << endl;
}

void printString(char *string)
{
    cout << string << endl;
}

template <typename T1, typename T2, typename T3>
T1 *addNum(T1 *arr, T3 num, T2 *size)
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
template <typename T1, typename T2, typename T3>
T1 *push_front(T1 *arr, T3 num, T2 *size)
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
template <typename T1, typename T2, typename T3>
T1 *IndexAddNum(T1 *arr, T2 index, T3 number, T2 *size)
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
template <typename T1, typename T2>
T1 *DeleteLast(T1 *arr, T2 *size)
{
    --(*size);
    T1 *newarr = new T1[*size];
    for (size_t i = 0; i < *size; i++)
        newarr[i] = arr[i];
    delete[] arr;
    arr = newarr;
    return arr;
}
template <typename T1, typename T2>
T1 *DeleteFirst(T1 *arr, T2 *size)
{
    --(*size);
    T1 *newarr = new T1[*size];
    for (size_t i = 0; i < *size; i++)
        newarr[i] = arr[i + 1];
    delete[] arr;
    arr = newarr;
    return arr;
}
template <typename T1, typename T2>
T1 *DeleteIndex(T1 *arr, T2 index, T2 *size)
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

int main()
{
    srand(time(0));
    int ArrOp;
    cout << "Enter arr type- 1 - int 2 - double 3 - char 4-Exit ";
    cin >> ArrOp;
    while (ArrOp > 4)
    {
        cout << "Enter arr type again- 1 - int 2 - double 3 - char: ";
        cin >> ArrOp;
    }
    while (true)
    {
        if (ArrOp == 4)
        {
            break;
        }
        ///for int array
        switch (ArrOp)
        {
        case 1:
        {
            int size,ran = 1;
            int op, num, index;
            cout << "Enter size of array: ";
            cin >> size;

            int *arr = new int[size];
            fillarray(arr, &size,ran);
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
                    cout << "Enter a number for add: ";
                    cin >> num;
                    arr = addNum(arr, num, &size);
                    PrintArray(arr, &size);
                    break;
                case 2:
                    cout << "Enter a number for add: ";
                    cin >> num;
                    arr = push_front(arr, num, &size);
                    PrintArray(arr, &size);
                    break;
                case 3:
                    cout << "Enter a index for add number: ";
                    cin >> index;
                    while (index > size)
                    {
                        cout << "Enter a index again : ";
                        cin >> index;
                    }
                    cout << "Enter a number for add: ";
                    cin >> num;
                    arr = IndexAddNum(arr, index, num, &size);
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
                    cout << "Enter a index for delete: ";
                    cin >> index;
                    arr = DeleteIndex(arr, index, &size);
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
            break;
        }
        ///for double
        case 2:
        {
            int size;
            double ran = 0.1,num;
            int op, index;
            cout << "Enter size of array: ";
            cin >> size;
            double *arr = new double[size];
            fillarray(arr, &size,ran);
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
                    break;
                switch (op)
                {
                case 1:
                    cout << "Enter a number for add: ";
                    cin >> num;
                    arr = addNum(arr, num, &size);
                    PrintArray(arr, &size);
                    break;
                case 2:
                    cout << "Enter a number for add: ";
                    cin >> num;
                    arr = push_front(arr, num, &size);
                    PrintArray(arr, &size);
                    break;
                case 3:
                    cout << "Enter a index for add number: ";
                    cin >> index;
                    while (index > size)
                    {
                        cout << "Enter a index again : ";
                        cin >> index;
                    }
                    cout << "Enter a number for add: ";
                    cin >> num;
                    arr = IndexAddNum(arr, index, num, &size);
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
                    cout << "Enter a index for delete: ";
                    cin >> index;
                    arr = DeleteIndex(arr, index, &size);
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
            break;
        }

            ///for char

        case 3:
        {
            int op, index;
            char c;
            char *arr = new char[300];
            cout << "Enter a string: " << endl;
            cin.ignore();
            cin.getline(arr, 300);
            int size = SizeOfString(arr);
            printString(arr);
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
                    break;
                switch (op)
                {
                case 1:
                    cout << "Enter a character for add: ";
                    cin >> c;
                    arr = addNum(arr, c, &size);
                    printString(arr);
                    break;
                case 2:
                    cout << "Enter a character for add: ";
                    cin >> c;
                    arr = push_front(arr, c, &size);
                    printString(arr);
                    break;
                case 3:
                    cout << "Enter a index for add character: ";
                    cin >> index;
                    while (index > size)
                    {
                        cout << "Enter a index again : ";
                        cin >> index;
                    }
                    cout << "Enter a character for add: ";
                    cin >> c;
                    arr = IndexAddNum(arr, index, c, &size);
                    printString(arr);
                    break;
                case 4:
                    arr = DeleteLast(arr, &size);
                    printString(arr);
                    break;
                case 5:
                    arr = DeleteFirst(arr, &size);
                    printString(arr);
                    break;
                case 6:
                    cout << "Enter a index for delete: ";
                    cin >> index;
                    arr = DeleteIndex(arr, index, &size);
                    printString(arr);
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
            break;
        }
        default:
        {
            break;
        }
        }

        cout << "Enter arr type- 1 - int 2 - double 3 - char 4-Exit ";
        cin >> ArrOp;
        while (ArrOp > 4)
        {
            cout << "Enter arr type again- 1 - int 2 - double 3 - char: ";
            cin >> ArrOp;
        }
    }
    return 0;
}
