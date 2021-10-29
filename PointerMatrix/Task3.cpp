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

void **ShiftMyColumn(int **matrix,size_t height,size_t value){
 int *newmat;
    for (int p = 1; p <=value; p++)
    {
    newmat=matrix[height-1];    
    for (int i = height-1; i > 0; i--)
        matrix[i]=matrix[i-1];  
    matrix[0]=newmat; 
    } 
}

int main(){
    srand(time(0));
    int height,width,index;
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
    cout << "Shift Index: ";
    cin  >> index;
    ShiftMyColumn(matrix,height,index);
    cout << "New Matrix: " << endl;
    PrintMatrix(matrix,height,width);
    for (size_t i = 0; i < width; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}