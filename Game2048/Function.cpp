#include "Function.h"
#include "MoveN.cpp"
#include "MoveN.h"
///print arrea
void PrintArea(int **matrix, int height, int width)
{
    cout << "-----------------------" << endl;
    for (size_t i = 0; i < height; i++)
    {
        for (size_t j = 0; j < width; j++)
        {
            if (matrix[i][j] == 0)
            {
                cout << "| "
                     << "   ";
            }
            else
            {
                cout << "|  " << matrix[i][j] << "  ";
            }
        }
        cout << "|" << endl
             << "-----------------------" << endl;
    }
}
//fill Area randomly
void FillRand(int **matrix, int height, int width, bool r)
{
    int dis = 2;
    int RandHeight = rand() % height;
    int RandWidht = rand() % width;

    while (matrix[RandHeight][RandWidht] != 0)
    {
        RandWidht = rand() % width;
        RandHeight = rand() % height;
    }
    if (r == false)
    {
        matrix[RandHeight][RandWidht] = dis;
    }
    else
    {
        for (size_t i = 0; i < 2; i++)
        {
            while (matrix[RandHeight][RandWidht] != 0)
            {
                RandWidht = rand() % width;
                RandHeight = rand() % height;
            }
            matrix[RandHeight][RandWidht] = dis;
            RandHeight = rand() % height;
            RandWidht = rand() % width;
        }
    }
}

void deleteMatrix(int **matrix, int height, int width)
{
    for (size_t i = 0; i < height; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}
int **CreateMatrix(int height, int width)
{
    int **matrix = new int *[height] {};
    for (size_t i = 0; i < height; i++)
    {
        matrix[i] = new int[width]{};
    }
    return matrix;
}

bool checkGame(int **matrix, int height, int width)
{
    int amountN = 0;
    for (size_t i = 0; i < height; i++)
    {
        for (size_t j = 0; j < width; j++)
        {
            if (matrix[i][j] == 2048)
            {
                return true;
            }
            if (matrix[i][j] == 0)
            {
                ++amountN;
            }
        }
    }
    if (amountN <= 1)
    {
        return false;
    }
    return true;
}

void game(char move, int **matrix, int width, int height)
{
    switch (move)
    {
    case 'w':
        MoveTop(matrix, height, width);
        break;
    case 's':
        MoveBottom(matrix, height, width);
        break;
    case 'a':
        MoveLeft(matrix, height, width);
        break;
    case 'd':
        MoveRight(matrix, height, width);
        break;
    default:
        break;
    }
}
