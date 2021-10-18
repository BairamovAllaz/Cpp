#include <iostream>
#include <ctime>
using namespace std;
void PrintMatrix(int **matrix,size_t height,size_t width){
     for (size_t i = 0; i < height; i++){
         for (size_t j = 0; j < width; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
     }
        
}
void createMatrix(int **matrix,size_t height,size_t width){
    for (size_t i = 0; i < height; i++)
        for (size_t j = 0; j < width; j++)
            matrix[i][j] = rand() % 20 + 1;
}
int **AddColumn(int **matrix,size_t height,size_t width,size_t value){
    int ** newmatrix = new int *[height + value];

   for (int i = height - 1; i >= 0; i--)
        newmatrix[i + value] = matrix[i];

    for (size_t i = 0; i < value; i++)
        newmatrix[i] = new int[width];

    return newmatrix;
}
int main(){
    srand(time(0));
    int height,width,NewHeight;
    cout << "Enter Height of matrix : ";
    cin >> height;
    cout << "Enter width of matrix: ";
    cin >> width;
    int **matrix = new int*[height];
    for (size_t i = 0; i < height; i++)
        matrix[i] = new int[width];
    createMatrix(matrix,height,width);
    PrintMatrix(matrix,height,width);
    cout << "---------------------------" << endl;
    cout << "Add new Height: ";
    cin  >> NewHeight;
    matrix = AddColumn(matrix,height,width,NewHeight);
    height += NewHeight;
    createMatrix(matrix,height,width);
    cout << "New Matrix: " << endl;
    PrintMatrix(matrix,height,width);
    delete[] matrix;
    return 0;
}