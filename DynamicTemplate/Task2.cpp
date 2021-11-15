#include <iostream>
#include <ctime>
using namespace std;
//dynamic template
//
template <typename T1, typename T2>
void fill(T1 **matrix, T2 height, T2 width, T1 ran)
{
    for (size_t i = 0; i < height; i++)
        for (size_t j = 0; j < width; j++)
            matrix[i][j] = rand() % 20 + ran;
}
void fillStringMatrix(char **matrix, int height, int width)
{
    for (size_t i = 0; i < height; i++)
        for (size_t j = 0; j < width; j++)
            cin >> matrix[i][j];
}

template <typename T1, typename T2>
void deleteMatrix(T1 matrix, T2 width)
{
    for (size_t i = 0; i < width; i++)
        delete[] matrix[i];
    delete[] matrix;
}

template <typename T1, typename T2>
void print(T1 **matrix, T2 height, T2 width)
{
    for (size_t i = 0; i < height; ++i)
    {
        for (size_t j = 0; j < width; ++j)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}
template <typename T1, typename T2>
T1 **addHeight(T1 **matrix, T2 *height, T2 width, T1 ran)
{
    ++(*height);
    T1 **newmatrix = new T1 *[*height];
    newmatrix[*height - 1] = new T1[width];
    for (int i = 0; i < *height - 1; i++)
        newmatrix[i] = matrix[i];
    for (size_t i = 0; i < width; i++)
        newmatrix[*height - 1][i] = rand() % 20 + ran;
    deleteMatrix(matrix, width);
    matrix = newmatrix;
    return matrix;
}
template <typename T1, typename T2>
T1 **push_row_front(T1 **matrix, T2 *height, T2 width, T1 ran)
{
    ++(*height);
    T1 **newmatrix = new T1 *[*height];
    newmatrix[0] = new T1[width];
    for (int i = 0; i < *height - 1; i++)
        newmatrix[i + 1] = matrix[i];
    for (size_t i = 0; i < width; i++)
        newmatrix[0][i] = rand() % 20 + ran;
    matrix = newmatrix;
    return matrix;
}
template <typename T1, typename T2>
T1 **insertRow(T1 **matrix, T2 *height, T2 *width, T2 index, T1 ran)
{
    ++(*height);
    T1 **newmatrix = new T1 *[*height];
    for (int i = 0; i < index; i++)
        newmatrix[i] = matrix[i];
    newmatrix[index] = new T1[*width];
    for (size_t i = 0; i < *width; i++)
        newmatrix[index][i] = rand() % 20 + ran;
    for (size_t i = index; i < *height; i++)
    {
        newmatrix[i + 1] = matrix[i];
    }
    matrix = newmatrix;
    return matrix;
}

template <typename T1, typename T2>
T1 **pop_row_front(T1 **matrix, T2 *height, T2 *width)
{
    --(*height);
    T1 **newmatrix = new T1 *[*height];
    for (size_t i = 0; i < *width; i++)
        newmatrix[i] = new T1[*width];
    for (size_t i = 0; i < *height; i++)
        for (size_t j = 0; j < *width; j++)
            newmatrix[i][j] = matrix[i + 1][j];
    matrix = newmatrix;
    return matrix;
}
template <typename T1, typename T2>
T1 **pop_row_back(T1 **matrix, T2 *height, T2 *width)
{
    --(*height);
    T1 **newmatrix = new T1 *[*height];
    for (size_t i = 0; i < *width; i++)
        newmatrix[i] = new T1[*width];
    for (size_t i = 0; i < *height; i++)
        for (size_t j = 0; j < *width; j++)
            newmatrix[i][j] = matrix[i][j];
    matrix = newmatrix;
    return matrix;
}
template <typename T1, typename T2>
T1 **erase_row(T1 **matrix, T2 *height, T2 *width, T2 index)
{
    --(*height);
    T1 **newmatrix = new T1 *[*height];
    for (size_t i = 0; i < *width; i++)
        newmatrix[i] = new T1[*width];
    for (size_t i = 0; i < index; i++)
        for (size_t j = 0; j < *width; j++)
            newmatrix[i][j] = matrix[i][j];
    for (size_t i = index; i < *height; i++)
        for (size_t j = 0; j < *width; j++)
            newmatrix[i][j] = matrix[i + 1][j];
    matrix = newmatrix;
    return matrix;
}

template <typename T1, typename T2>
T1 **push_col_back(T1 **matrix, T2 *height, T2 *width, T1 ran)
{
    ++(*width);
    T1 **newmatrix = new T1 *[*height];
    for (size_t i = 0; i < *height; i++)
        newmatrix[i] = new T1[*width];
    for (size_t i = 0; i < *height; i++)
        for (size_t j = 0; j < *width; j++)
            newmatrix[i][j] = matrix[i][j];
    for (size_t i = 0; i < *height; i++)
        newmatrix[i][*width - 1] = rand() % 20 + ran;
    matrix = newmatrix;
    return matrix;
}

template <typename T1, typename T2>
T1 **push_col_front(T1 **matrix, T2 *height, T2 *width, T1 ran)
{
    ++(*width);
    T1 **newmatrix = new T1 *[*height];
    for (size_t i = 0; i < *height; i++)
        newmatrix[i] = new T1[*width];
    for (size_t i = 0; i < *height; i++)
        for (size_t j = 0; j < *width; j++)
            newmatrix[i][j + 1] = matrix[i][j];
    for (size_t i = 0; i < *height; i++)
        newmatrix[i][0] = rand() % 20 + ran;
    matrix = newmatrix;
    return matrix;
}
template <typename T1, typename T2>
T1 **instercol(T1 **matrix, T2 *height, T2 *width, T2 index, T1 ran)
{
    ++(*width);
    T1 **newmatrix = new T1 *[*height];
    for (size_t i = 0; i < *height; i++)
        newmatrix[i] = new T1[*width];
    for (size_t i = 0; i < *height; i++)
        for (size_t j = 0; j < index; j++)
            newmatrix[i][j] = matrix[i][j];
    for (size_t i = 0; i < *height; i++)
        newmatrix[i][index] = rand() % 20 + ran;
    for (size_t i = 0; i < *height; i++)
        for (size_t j = index; j < *width; j++)
            newmatrix[i][j + 1] = matrix[i][j];
    matrix = newmatrix;
    return matrix;
}

template <typename T1, typename T2>
T1 **pop_col_back(T1 **matrix, T2 *height, T2 *width)
{
    --(*width);
    T1 **newmatrix = new T1 *[*height];
    for (size_t i = 0; i < *height; i++)
        newmatrix[i] = new T1[*width];
    for (size_t i = 0; i < *height; i++)
        for (size_t j = 0; j < *width; j++)
            newmatrix[i][j] = matrix[i][j];
    matrix = newmatrix;
    return matrix;
}
template <typename T1, typename T2>
T1 **pop_col_front(T1 **matrix, T2 *height, T2 *width)
{
    --(*width);
    T1 **newmatrix = new T1 *[*height];
    for (size_t i = 0; i < *height; i++)
        newmatrix[i] = new T1[*width];
    for (size_t i = 0; i < *height; i++)
        for (size_t j = 0; j < *width; j++)
            newmatrix[i][j] = matrix[i][j + 1];
    matrix = newmatrix;
    return matrix;
}
template <typename T1, typename T2>
T1 **erase_col(T1 **matrix, T2 *height, T2 *width, T2 index)
{
    --(*width);
    T1 **newmatrix = new T1 *[*height];
    for (size_t i = 0; i < *height; i++)
        newmatrix[i] = new T1[*width];
    for (size_t i = 0; i < *height; i++)
        for (size_t j = 0; j < index; j++)
            newmatrix[i][j] = matrix[i][j];
    for (size_t i = 0; i < *height; i++)
        for (size_t j = index; j < *width; j++)
            newmatrix[i][j] = matrix[i][j + 1];
    matrix = newmatrix;
    return matrix;
}

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
        {
            break;
        }
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
                {
                    break;
                }
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
                {
                    break;
                }
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
            fillStringMatrix(matrix, height, width);
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
                {
                    break;
                }
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
