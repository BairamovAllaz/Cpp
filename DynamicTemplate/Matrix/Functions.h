#pragma once
#include "stdafx.h"
template <typename T1, typename T2> void deleteMatrix(T1 matrix, T2 width);
template <typename T1, typename T2> T1 **addHeight(T1 **matrix, T2 *height, T2 width, T1 ran);
template <typename T1, typename T2> T1 **push_row_front(T1 **matrix, T2 *height, T2 width, T1 ran);
template <typename T1, typename T2> T1 **insertRow(T1 **matrix, T2 *height, T2 *width, T2 index, T1 ran);
template <typename T1, typename T2> T1 **pop_row_front(T1 **matrix, T2 *height, T2 *width);
template <typename T1, typename T2> T1 **pop_row_back(T1 **matrix, T2 *height, T2 *width);
template <typename T1, typename T2> T1 **erase_row(T1 **matrix, T2 *height, T2 *width, T2 index);
template <typename T1, typename T2> T1 **push_col_back(T1 **matrix, T2 *height, T2 *width, T1 ran);
template <typename T1, typename T2> T1 **push_col_front(T1 **matrix, T2 *height, T2 *width, T1 ran);
template <typename T1, typename T2> T1 **instercol(T1 **matrix, T2 *height, T2 *width, T2 index, T1 ran);
template <typename T1, typename T2> T1 **pop_col_back(T1 **matrix, T2 *height, T2 *width);
template <typename T1, typename T2> T1 **pop_col_front(T1 **matrix, T2 *height, T2 *width);
template <typename T1, typename T2> T1 **erase_col(T1 **matrix, T2 *height, T2 *width, T2 index);