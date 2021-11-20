#include "Functions.h"
#include "Task1Functions.h"
#include "Task1Functions.cpp"
template <typename T1>
void deleteMatrix(T1 matrix, int width)
{
    for (size_t i = 0; i < width; i++)
        delete[] matrix[i];
    delete[] matrix;
}
template <typename T>
T **AllocateMatrix(int *height, int *width)
{
    T **matrix = new T *[*height] {};
    for (size_t i = 0; i < *height; i++)
    {
        matrix[i] = new T[*width]{};
    }
    return matrix;
}

template <typename T1>
T1 **addHeight(T1 **matrix, int *height, int width, T1 ran)
{
    ++(*height);
    T1 **newmatrix = AllocateMatrix<T1>(height, &width);
    newmatrix[*height - 1] = new T1[width]{};
    for (int i = 0; i < *height - 1; i++)
        newmatrix[i] = matrix[i];
    for (size_t i = 0; i < width; i++)
        newmatrix[*height - 1][i] = rand() % 20 + ran;

    matrix = newmatrix;
    return matrix;
}
template <typename T1>
T1 **push_row_front(T1 **matrix, int *height, int width, T1 ran)
{
    ++(*height);
    T1 **newmatrix =AllocateMatrix<T1>(height, &width);
    newmatrix[0] = new T1[width]{};
    for (int i = 0; i < *height - 1; i++)
        newmatrix[i + 1] = matrix[i];
    for (size_t i = 0; i < width; i++)
        newmatrix[0][i] = rand() % 20 + ran;
    delete[] matrix;
    matrix = newmatrix;
    return matrix;
}
template <typename T1>
T1 **insertRow(T1 **matrix, int *height, int *width, int index, T1 ran)
{
    ++(*height);
    T1 **newmatrix = AllocateMatrix<T1>(height, width);
    for (int i = 0; i < index; i++)
        newmatrix[i] = matrix[i];
    newmatrix[index] = new T1[*width]{};
    for (size_t i = 0; i < *width; i++)
        newmatrix[index][i] = rand() % 20 + ran;
    for (size_t i = index; i < *height; i++)
    {
        newmatrix[i + 1] = matrix[i];
    }
    delete[] matrix;
    matrix = newmatrix;
    return matrix;
}

template <typename T1>
T1 **pop_row_front(T1 **matrix, int *height, int *width)
{
    --(*height);
    T1 **newmatrix = AllocateMatrix<T1>(height, width);
    for (size_t i = 0; i < *height; i++)
        for (size_t j = 0; j < *width; j++)
            newmatrix[i][j] = matrix[i + 1][j];
    delete[] matrix;
    matrix = newmatrix;
    return matrix;
}
template <typename T1>
T1 **pop_row_back(T1 **matrix, int *height, int *width)
{
    --(*height);
    T1 **newmatrix = AllocateMatrix<T1>(height, width);
    for (size_t i = 0; i < *height; i++)
        for (size_t j = 0; j < *width; j++)
            newmatrix[i][j] = matrix[i][j];
    delete[] matrix;
    matrix = newmatrix;
    return matrix;
}

///

template <typename T1>
T1 **erase_row(T1 **matrix, int *height, int *width, int index)
{
    --(*height);
    T1 **newmatrix = AllocateMatrix<T1>(height,width);

    for (size_t i = 0; i < index; i++)
        for (size_t j = 0; j < *width; j++)
            newmatrix[i][j] = matrix[i][j];

    for (size_t i = index; i < *height; i++)
        for (size_t j = 0; j < *width; j++)
            newmatrix[i][j] = matrix[i + 1][j];
    delete[] matrix;
    matrix = newmatrix;
    return matrix;
}

template <typename T1>
T1 **push_col_back(T1 **matrix, int *height, int *width, T1 ran)
{
    ++(*width);
    T1 **newmatrix = AllocateMatrix<T1>(height, width);

    for (size_t i = 0; i < *height; i++)
        for (size_t j = 0; j < *width; j++)
            newmatrix[i][j] = matrix[i][j];
    for (size_t i = 0; i < *height; i++)
        newmatrix[i][*width - 1] = rand() % 20 + ran;

    delete[] matrix;
    matrix = newmatrix;
    return matrix;
}

template <typename T1>
T1 **push_col_front(T1 **matrix, int *height, int *width, T1 ran)
{
    ++(*width);
    T1 **newmatrix = AllocateMatrix<T1>(height, width);
    for (size_t i = 0; i < *height; i++)
        for (size_t j = 0; j < *width; j++)
            newmatrix[i][j + 1] = matrix[i][j];

    for (size_t i = 0; i < *height; i++)
        newmatrix[i][0] = rand() % 20 + ran;
    delete[] matrix;
    matrix = newmatrix;
    return matrix;
}
template <typename T1>
T1 **instercol(T1 **matrix, int *height, int *width, int index, T1 ran)
{
    ++(*width);
    T1 **newmatrix = AllocateMatrix<T1>(height, width);;
    for (size_t i = 0; i < *height; i++)
        for (size_t j = 0; j < index; j++)
            newmatrix[i][j] = matrix[i][j];

    for (size_t i = 0; i < *height; i++)
        newmatrix[i][index] = rand() % 20 + ran;

    for (size_t i = 0; i < *height; i++)
        for (size_t j = index; j < *width; j++)
            newmatrix[i][j + 1] = matrix[i][j];

    delete[] matrix;
    matrix = newmatrix;
    return matrix;
}

template <typename T1>
T1 **pop_col_back(T1 **matrix, int *height, int *width)
{
    --(*width);
    T1 **newmatrix = AllocateMatrix<T1>(height, width);

    for (size_t i = 0; i < *height; i++)
        for (size_t j = 0; j < *width; j++)
            newmatrix[i][j] = matrix[i][j];
    delete[] matrix;
    matrix = newmatrix;
    return matrix;
}
template <typename T1>
T1 **pop_col_front(T1 **matrix, int *height, int *width)
{
    --(*width);
    T1 **newmatrix = AllocateMatrix<T1>(height, width);

    for (size_t i = 0; i < *height; i++)
        for (size_t j = 0; j < *width; j++)
            newmatrix[i][j] = matrix[i][j + 1];
    delete[] matrix;
    matrix = newmatrix;
    return matrix;
}
template <typename T1>
T1 **erase_col(T1 **matrix, int *height, int *width, int index)
{
    --(*width);
    T1 **newmatrix = AllocateMatrix<T1>(height, width);
    for (size_t i = 0; i < *height; i++)
        for (size_t j = 0; j < index; j++)
            newmatrix[i][j] = matrix[i][j];

    for (size_t i = 0; i < *height; i++)
        for (size_t j = index; j < *width; j++)
            newmatrix[i][j] = matrix[i][j + 1];
    delete[] matrix;
    matrix = newmatrix;
    return matrix;
}