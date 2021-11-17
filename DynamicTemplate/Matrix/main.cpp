#include "stdafx.h"
#include "Print.h"
#include "Print.cpp"
#include "Fillarr.h"
#include "Fillarr.cpp"
#include "Functions.h"
#include "Functions.cpp"

int main()
{
    srand(time(0));
    int ArrOp;
    int op;

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
            break;
        switch (ArrOp)
        {
        case 1:
        {
            int width, height;
            cout << "Enter a height: ";
            cin >> height;
            cout << "Enter width: ";
            cin >> width;
            int ran = 1;

            int **matrix = new int *[height];
            for (size_t i = 0; i < width; i++)
                matrix[i] = new int[width];
            fill(matrix, height, width, ran);
            print(matrix, height, width);
            cout << endl;
            cout << "Enter  a operation: 1 - 12 --- 13 - Exit: ";
            cin >> op;
            while (op > 13)
            {
                cout << "Enter operation again: ";
                cin >> op;
            }
            while (true)
            {
                if (op == 13)
                    break;
                switch (op)
                {
                case 1:
                    matrix = addHeight(matrix, &height, width, ran);
                    print(matrix, height, width);
                    break;
                case 2:
                    matrix = push_row_front(matrix, &height, width, ran);
                    print(matrix, height, width);
                    break;
                case 3:
                    int indexHeight;
                    cout << "Enter a row index: ";
                    cin >> indexHeight;
                    matrix = insertRow(matrix, &height, &width, indexHeight, ran);
                    print(matrix, height, width);
                    break;
                case 4:
                    matrix = pop_row_front(matrix, &height, &width);
                    print(matrix, height, width);
                    break;
                case 5:
                    matrix = pop_row_back(matrix, &height, &width);
                    print(matrix, height, width);
                    break;
                case 6:
                    int eraseIndex;
                    cout << "Enter a Height index: ";
                    cin >> eraseIndex;
                    while (eraseIndex > height)
                    {
                        cout << "Enter a Height index again!: ";
                        cin >> eraseIndex;
                    }
                    matrix = erase_row(matrix, &height, &width, eraseIndex);
                    print(matrix, height, width);
                    break;
                case 7:
                    matrix = push_col_back(matrix, &height, &width, ran);
                    print(matrix, height, width);
                    break;
                case 8:
                    matrix = push_col_front(matrix, &height, &width, ran);
                    print(matrix, height, width);
                    break;
                case 9:
                    int ColIndex;
                    cout << "Enter a col index: ";
                    cin >> ColIndex;
                    while (ColIndex > width)
                    {
                        cout << "Enter a col index: ";
                        cin >> ColIndex;
                    }
                    matrix = instercol(matrix, &height, &width, ColIndex, ran);
                    print(matrix, height, width);
                    break;
                case 10:
                    matrix = pop_col_back(matrix, &height, &width);
                    print(matrix, height, width);
                    break;
                case 11:
                    matrix = pop_col_front(matrix, &height, &width);
                    print(matrix, height, width);
                    break;
                case 12:
                    int EraseIndex;
                    cout << "Enter a column index for delete: ";
                    cin >> EraseIndex;
                    while (EraseIndex > width)
                    {
                        cout << "Enter a column index for delete again!!!!!: ";
                        cin >> EraseIndex;
                    }
                    matrix = erase_col(matrix, &height, &width, EraseIndex);
                    print(matrix, height, width);
                    break;
                default:
                    break;
                }
                cout << "Enter a operation 1-12 ---- 13 - Exit";
                cin >> op;
                while (op > 13)
                {
                    cout << "Enter operatrion again : ";
                    cin >> op;
                }
            }
            deleteMatrix(matrix, width);
            break;
        }

        case 2:
        {
            int width, height;
            double ran = 0.1;
            cout << "Enter a height: ";
            cin >> height;
            cout << "Enter width: ";
            cin >> width;

            double **matrix = new double *[height];
            for (size_t i = 0; i < width; i++)
                matrix[i] = new double[width];

            fill(matrix, height, width, ran);
            print(matrix, height, width);

            cout << endl;
            cout << "Enter  a operation: 1 - 12 --- 13 - Exit: ";
            cin >> op;
            while (op > 13)
            {
                cout << "Enter operation again: ";
                cin >> op;
            }
            while (true)
            {
                if (op == 13)
                    break;
                switch (op)
                {
                case 1:
                    matrix = addHeight(matrix, &height, width, ran);
                    print(matrix, height, width);
                    break;
                case 2:
                    matrix = push_row_front(matrix, &height, width, ran);
                    print(matrix, height, width);
                    break;
                case 3:
                    int indexHeight;
                    cout << "Enter a row index: ";
                    cin >> indexHeight;
                    matrix = insertRow(matrix, &height, &width, indexHeight, ran);
                    print(matrix, height, width);
                    break;
                case 4:
                    matrix = pop_row_front(matrix, &height, &width);
                    print(matrix, height, width);
                    break;
                case 5:
                    matrix = pop_row_back(matrix, &height, &width);
                    print(matrix, height, width);
                    break;
                case 6:
                    int eraseIndex;
                    cout << "Enter a Height index: ";
                    cin >> eraseIndex;
                    while (eraseIndex > height)
                    {
                        cout << "Enter a Height index again!: ";
                        cin >> eraseIndex;
                    }
                    matrix = erase_row(matrix, &height, &width, eraseIndex);
                    print(matrix, height, width);
                    break;
                case 7:
                    matrix = push_col_back(matrix, &height, &width, ran);
                    print(matrix, height, width);
                    break;
                case 8:
                    matrix = push_col_front(matrix, &height, &width, ran);
                    print(matrix, height, width);
                    break;
                case 9:
                    int ColIndex;
                    cout << "Enter a col index: ";
                    cin >> ColIndex;
                    while (ColIndex > width)
                    {
                        cout << "Enter a col index: ";
                        cin >> ColIndex;
                    }
                    matrix = instercol(matrix, &height, &width, ColIndex, ran);
                    print(matrix, height, width);
                    break;
                case 10:
                    matrix = pop_col_back(matrix, &height, &width);
                    print(matrix, height, width);
                    break;
                case 11:
                    matrix = pop_col_front(matrix, &height, &width);
                    print(matrix, height, width);
                    break;
                case 12:
                    int EraseIndex;
                    cout << "Enter a column index for delete: ";
                    cin >> EraseIndex;
                    while (EraseIndex > width)
                    {
                        cout << "Enter a column index for delete again!!!!!: ";
                        cin >> EraseIndex;
                    }
                    matrix = erase_col(matrix, &height, &width, EraseIndex);
                    print(matrix, height, width);
                    break;
                default:
                    break;
                }
                cout << "Enter a operation 1-12 ---- 13 - Exit";
                cin >> op;
                while (op > 13)
                {
                    cout << "Enter operatrion again : ";
                    cin >> op;
                }
            }
            deleteMatrix(matrix, width);
            break;
        }

        case 3:
        {
            int width, height;
            char run = 'a';
            cout << "Enter a height: ";
            cin >> height;
            cout << "Enter width: ";
            cin >> width;

            char **matrix = new char *[height];
            for (size_t i = 0; i < width; i++)
                matrix[i] = new char[width];
            cout << "Lets fill our matrxi enter characters: " << endl;
            fill(matrix, height, width,run);
            print(matrix, height, width);

            cout << endl;

            cout << "Enter  a operation: 1 - 12 --- 13 - Exit: ";
            cin >> op;
            while (op > 13)
            {
                cout << "Enter operation again: ";
                cin >> op;
            }
            while (true)
            {
                if (op == 13)
                    break;
                switch (op)
                {
                case 1:
                    matrix = addHeight(matrix, &height, width, run);
                    print(matrix, height, width);
                    break;
                case 2:
                    matrix = push_row_front(matrix, &height, width, run);
                    print(matrix, height, width);
                    break;
                case 3:
                    int indexHeight;
                    cout << "Enter a row index: ";
                    cin >> indexHeight;
                    matrix = insertRow(matrix, &height, &width, indexHeight, run);
                    print(matrix, height, width);
                    break;
                case 4:
                    matrix = pop_row_front(matrix, &height, &width);
                    print(matrix, height, width);
                    break;
                case 5:
                    matrix = pop_row_back(matrix, &height, &width);
                    print(matrix, height, width);
                    break;
                case 6:
                    int eraseIndex;
                    cout << "Enter a Height index: ";
                    cin >> eraseIndex;
                    while (eraseIndex > height)
                    {
                        cout << "Enter a Height index again!: ";
                        cin >> eraseIndex;
                    }
                    matrix = erase_row(matrix, &height, &width, eraseIndex);
                    print(matrix, height, width);
                    break;
                case 7:
                    matrix = push_col_back(matrix, &height, &width, run);
                    print(matrix, height, width);
                    break;
                case 8:
                    matrix = push_col_front(matrix, &height, &width, run);
                    print(matrix, height, width);
                    break;
                case 9:
                    int ColIndex;
                    cout << "Enter a col index: ";
                    cin >> ColIndex;
                    while (ColIndex > width)
                    {
                        cout << "Enter a col index: ";
                        cin >> ColIndex;
                    }
                    matrix = instercol(matrix, &height, &width, ColIndex, run);
                    print(matrix, height, width);
                    break;
                case 10:
                    matrix = pop_col_back(matrix, &height, &width);
                    print(matrix, height, width);
                    break;
                case 11:
                    matrix = pop_col_front(matrix, &height, &width);
                    print(matrix, height, width);
                    break;
                case 12:
                    int EraseIndex;
                    cout << "Enter a column index for delete: ";
                    cin >> EraseIndex;
                    while (EraseIndex > width)
                    {
                        cout << "Enter a column index for delete again!!!!!: ";
                        cin >> EraseIndex;
                    }
                    matrix = erase_col(matrix, &height, &width, EraseIndex);
                    print(matrix, height, width);
                    break;
                default:
                    break;
                }
                cout << "Enter a operation 1-12 ---- 13 - Exit";
                cin >> op;
                while (op > 13)
                {
                    cout << "Enter operatrion again : ";
                    cin >> op;
                }
            }
            deleteMatrix(matrix, width);
            break;
        }

        default:
            break;
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
