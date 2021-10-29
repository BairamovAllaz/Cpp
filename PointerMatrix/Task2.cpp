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
int **DeleteMyColumn(int **matrix,size_t height,size_t value){
    int **newMatrix = new int*[height - value];
    for (size_t i = 0; i < height; i++)
        if(i != value)
            newMatrix[i] = matrix[i];
    return newMatrix;
}
int main(){
    srand(time(0));
    int height,width,DeleteHeight;
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
    cout << "Delete Height: ";
    cin  >> DeleteHeight;
    while (DeleteHeight >= height)
    {
        cout << "Delete Height: ";
        cin  >> DeleteHeight;
    }
    matrix = DeleteMyColumn(matrix,height,DeleteHeight);
    height -= DeleteHeight;
    createMatrix(matrix,height,width);
    cout << "New Matrix: " << endl;
    PrintMatrix(matrix,height,width);
    for (size_t i = 0; i < width; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}