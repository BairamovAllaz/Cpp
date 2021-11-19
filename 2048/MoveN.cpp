#include "MoveN.h"
///move top
void MoveTop(int **matrix, int height, int width)
{
     int hh, ww;
     for (size_t i = 0; i < height; i++)
     {
          hh = 0; ////amount of height
          ww = i; ///width for matrix
          for (size_t j = 1; j < width; j++)
          {
               if (matrix[j][i] != 0)
               {
                    if (matrix[j - 1][i] == 0 || matrix[j - 1][i] == matrix[j][i])
                    {
                         if (matrix[hh][ww] == matrix[j][i])
                         {
                              matrix[hh][ww] *= 2;
                              matrix[j][i] = 0;
                         }
                         else
                         {
                              if (matrix[hh][ww] == 0)
                              {
                                   matrix[hh][ww] = matrix[j][i];
                                   matrix[j][i] = 0;
                              }
                              else
                              {
                                   matrix[++hh][ww] = matrix[j][i];
                                   matrix[j][i] = 0;
                              }
                         }
                    }
                    else
                    {
                         hh++;
                    }
               }
          }
     }
}
////move bottom
void MoveBottom(int **matrix, int height, int width)
{
     int ww, hh;
     for (int i = 0; i < height; i++)
     {
          ww = i, hh = height - 1;
          for (int j = width - 2; j >= 0; j--)
          {
               if (matrix[j][i] != 0)
               {
                    if (matrix[j + 1][i] == 0 || matrix[j + 1][i] == matrix[j][i])
                    {
                         if (matrix[hh][ww] == matrix[j][i])
                         {
                              matrix[hh][ww] *= 2;
                              matrix[j][i] = 0;
                         }
                         else
                         {
                              if (matrix[hh][ww] == 0)
                              {
                                   matrix[hh][ww] = matrix[j][i];
                                   matrix[j][i] = 0;
                              }
                              else
                              {
                                   matrix[--hh][ww] = matrix[j][i];
                                   matrix[j][i] = 0;
                              }
                         }
                    }
                    else
                    {
                         --hh;
                         ///if there another number not 0 not number!
                    }
               }
          }
     }
     cout << "BOTO is ok!!" << endl;
}
///move left
void MoveLeft(int **matrix, int height, int width)
{
     int ww, hh;
     for (int i = 0; i < height; i++)
     {
          ww = 0, hh = i;
          for (int j = 0; j < width; j++)
          {
               if (matrix[i][j] != 0)
               {
                    if (matrix[i][j - 1] == 0 || matrix[i][j - 1] == matrix[i][j - 1])
                    {
                         if (matrix[hh][ww] == matrix[i][j])
                         {
                              matrix[hh][ww] *= 2;
                              matrix[i][j] = 0;
                         }
                         else
                         {
                              if (matrix[hh][ww] == 0)
                              {
                                   matrix[hh][ww] = matrix[i][j];
                                   matrix[i][j] = 0;
                              }
                              else
                              {
                                   matrix[hh][++ww] = matrix[i][j];
                                   matrix[i][j] = 0;
                              }
                         }
                    }
                    else
                    {
                         ++ww;
                         ///if there another number not 0 not number!
                    }
               }
          }
     }
}
///move right
void MoveRight(int **matrix, int height, int width)
{
     int ww, hh;
     for (int i = 0; i < height; i++)
     {
          ww = width - 1, hh = i;
          for (int j = width - 2; j >= 0; j--)
          {
               if (matrix[i][j] != 0)
               {
                    if (matrix[i][j + 1] == 0 || matrix[i][j + 1] == matrix[i][j + 1])
                    {
                         if (matrix[hh][ww] == matrix[i][j])
                         {
                              matrix[hh][ww] *= 2;
                              matrix[i][j] = 0;
                         }
                         else
                         {
                              if (matrix[hh][ww] == 0)
                              {
                                   matrix[hh][ww] = matrix[i][j];
                                   matrix[i][j] = 0;
                              }
                              else
                              {
                                   matrix[hh][--ww] = matrix[i][j];
                                   matrix[i][j] = 0;
                              }
                         }
                    }
                    else
                    {
                         --ww;
                         ///if there another number not 0 not number!
                    }
               }
          }
     }
}