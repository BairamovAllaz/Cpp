#include "stdrfx.h"
int **CreateMatrix(int height,int width); 
void deleteMatrix(int **matrix,int height,int width); 
void PrintArea(int **matrix, int height, int width);
void FillRand(int **matrix,int height,int width,bool r);
bool checkGame(int **matrix,int height,int width);
void game(char move, int **matrix, int width, int height);