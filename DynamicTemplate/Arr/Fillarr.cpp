#pragma once
#include "Fillarr.h"

template <typename T1>
void fillarray(T1 *arr, int *size, T1 ran)
{
    for (size_t i = 0; i < *size; i++)
        arr[i] = rand() % 20 + ran;
}
