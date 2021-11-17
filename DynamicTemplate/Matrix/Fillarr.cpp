#pragma once
#include "Fillarr.h"

template <typename T1>
void fill(T1 **matrix, int height, int width, T1 ran)
{
    for (size_t i = 0; i < height; i++)
        for (size_t j = 0; j < width; j++)
            matrix[i][j] = rand() % 20 + ran;
}