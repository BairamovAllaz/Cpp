#pragma once
#include "stdafx.h"


template <typename T1, typename T2> T1 *addNum(T1 *arr, T2 num, int *size);
template <typename T1, typename T2> T1 *push_front(T1 *arr, T2 num, int *size);
template <typename T1, typename T2> T1 *IndexAddNum(T1 *arr, int index, T2 number, int *size);
template <typename T1> T1 *DeleteLast(T1 *arr, int *size);
template <typename T1> T1 *DeleteFirst(T1 *arr, int *size);
template <typename T1> T1 *DeleteIndex(T1 *arr, int index, int *size);
int SizeOfString(char *string);