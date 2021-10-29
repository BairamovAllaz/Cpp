#include <iostream>
#include <ctime>
using namespace std;


void fill(int **matrix,int *height,int *width);
void print(int **matrix,int *height,int *width);
int **addHeight(int **matrix,int *height,int *width);
int **push_row_front(int **matrix,int *height,int *width);
int **insertRow(int **matrix,int *height,int *width,int index);
int main(){
    srand(time(0));
    int width,height,op;
    cout << "Enter a height: ";
    cin >> height;
    cout << "Enter width: ";
    cin >> width;

    int **matrix = new int*[height];
    for (size_t i = 0; i < width; i++)
        matrix[i] = new int[width];

    fill(matrix,&height,&width);
    print(matrix,&height,&width);

    cout << endl;

    cout << "Enter  a operation: 1 - 10";
    cin >> op;
    while (op > 10)
    {
        cout << "Enter operation again: ";
        cin >> op;
    }


  while (true)
    {
        if (op == 7)
        {
            break;
        }
        switch (op)
        {
        case 1:
            matrix = addHeight(matrix,&height,&width);
            print(matrix,&height,&width);
            break;
        case 2:
            matrix = push_row_front(matrix,&height,&width);
            print(matrix,&height,&width);
        case 3: 
            int indexHeight;
            cout << "Enter a row index: ";
            cin >> indexHeight;
            matrix = insertRow(matrix,&height,&width,indexHeight);
            print(matrix,&height,&width);
        break;
        default:
            break;
        }
        cout << "Enter a operation 1-10";
        cin >> op;
        while (op > 10)
        {
            cout << "Enter operatrion again : ";
            cin >> op;
        }
    }

    for (size_t i = 0; i < width; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}
void fill(int **matrix,int *height,int *width){
    for (size_t i = 0; i < *height; i++)
    {
        for (size_t j = 0; j < *width; j++)
        {
            matrix[i][j] = rand() % 20 + 1;
        }
    }
}
void print(int **matrix,int *height,int *width){ 
    for (size_t i = 0; i < *height; i++)
    {
        for (size_t j = 0; j < *width; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
int **addHeight(int **matrix,int *height,int *width){
    ++(*height);
    int **newmatrix = new int*[*height];
    newmatrix[*height - 1] = new int[*width]; 
    for (int i = 0; i < *height - 1; i++)
        newmatrix[i] = matrix[i];
    for (size_t i = 0; i < *width; i++)
        newmatrix[*height - 1][i] = rand() % 20 + 1;
    return newmatrix;
}
int **push_row_front(int **matrix,int *height,int *width){
    ++(*height);
    int **newmatrix = new int*[*height];
    newmatrix[0] = new int[*width]; 
    for (int i = 0; i < *height - 1; i++)
        newmatrix[i + 1] = matrix[i];
    for (size_t i = 0; i < *width; i++)
        newmatrix[0][i] = rand() % 20 + 1;

    return newmatrix;   
}

int **insertRow(int **matrix,int *height,int *width,int index){ 
    ++(*height);
    int **newmatrix = new int*[*height];
    newmatrix[0] = new int[*width]; 
    for (int i = 0; i < index; i++)
        newmatrix[i] = matrix[i];

    for (size_t i = index; i < *height; i++)
        newmatrix[i + 1] = matrix[i];
    for (size_t i = 0; i < *width; i++)
        newmatrix[index][i] = rand() % 20 + 1;
    return newmatrix;   
}