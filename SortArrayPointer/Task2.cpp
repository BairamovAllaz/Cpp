#include <iostream>
#include <ctime>
using namespace std;

void fill(int **matrix,int *height,int *width);
void print(int **matrix,int *height,int *width);
int **addHeight(int **matrix,int *height,int width);
int **push_row_front(int **matrix,int *height,int width);
int **insertRow(int **matrix,int *height,int *width,int index);
int **pop_row_front(int **matrix,int *height,int *width);
int **pop_row_back(int **matrix,int *height,int *width);
int **erase_row(int **matrix,int *height,int *width,int index);
int **push_col_back(int **matrix,int *height,int *width);
int **push_col_front(int **matrix,int *height,int *width);
int **instercol(int **matrix,int *height,int *width,int index);
int **pop_col_back(int **matrix,int *height,int *width);
int **pop_col_front(int **matrix,int *height,int *width);
int **erase_col(int **matrix,int *height,int *width,int index);
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

    cout << "Enter  a operation: 1 - 12 --- 13 - Exit: ";
    cin >> op;
    while (op > 13)
    {
        cout << "Enter operation again: ";
        cin >> op;
    }
  while (true)
    {
        if (op == 13)
        {
            break;
        }
        switch (op)
        {
        case 1:
            matrix = addHeight(matrix,&height,width);
            print(matrix,&height,&width);
            break;
        case 2:
            matrix = push_row_front(matrix,&height,width);
            print(matrix,&height,&width);
            break;
        case 3: 
            int indexHeight;
            cout << "Enter a row index: ";
            cin >> indexHeight;
            matrix = insertRow(matrix,&height,&width,indexHeight);
            print(matrix,&height,&width);
        break;
        case 4: 
            matrix = pop_row_front(matrix,&height,&width);
            print(matrix,&height,&width);
        break;
        case 5: 
            matrix = pop_row_back(matrix,&height,&width);
           print(matrix,&height,&width);
        break;
        case 6: 
            int eraseIndex;
            cout << "Enter a Height index: ";
            cin >> eraseIndex;
            while(eraseIndex > height){ 
                cout << "Enter a Height index again!: ";
                cin >> eraseIndex;
            }
            matrix = erase_row(matrix,&height,&width,eraseIndex);
            print(matrix,&height,&width);
            break;
        case 7:
        matrix = push_col_back(matrix,&height,&width);
        print(matrix,&height,&width);
        break;
        case 8:
        matrix = push_col_front(matrix,&height,&width);
        print(matrix,&height,&width);
        break;
        case 9:
        int ColIndex;
        cout << "Enter a col index: ";
        cin >>ColIndex; 
        while (ColIndex > width)
        {
            cout << "Enter a col index: ";
            cin >>ColIndex; 
        }
        matrix = instercol(matrix,&height,&width,ColIndex);
        print(matrix,&height,&width);
        break;
        case 10:
        matrix = pop_col_back(matrix,&height,&width);
        print(matrix,&height,&width);
        break;
        case 11:
        matrix = pop_col_front(matrix,&height,&width);
        print(matrix,&height,&width);
        break;
        case 12: 
        int EraseIndex;
        cout << "Enter a column index for delete: ";
        cin >> EraseIndex;
        while(EraseIndex > width){
            cout << "Enter a column index for delete again!!!!!: ";
            cin >> EraseIndex;
        }
        matrix = erase_col(matrix,&height,&width,EraseIndex);
        print(matrix,&height,&width);
        break;
        default:
            break;
        }
        cout << "Enter a operation 1-12 ---- 13 - Exit";
        cin >> op;
        while (op > 13)
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
    for (size_t i = 0; i < *height; ++i)
    {
        for (size_t j = 0; j < *width; ++j)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
int **addHeight(int **matrix,int *height,int width){
    ++(*height);
    int **newmatrix = new int*[*height];
    newmatrix[*height - 1] = new int[width]; 
    for (int i = 0; i < *height - 1; i++)
        newmatrix[i] = matrix[i];
    for (size_t i = 0; i < width; i++)
        newmatrix[*height - 1][i] = rand() % 20 + 1;
    matrix = newmatrix;
    // for (size_t i = 0; i < width; i++)
    // {
    //     delete[] newmatrix[i];
    // }
    // delete[] newmatrix;
    return matrix;
}

int **push_row_front(int **matrix,int *height,int width){
    ++(*height);
    int **newmatrix = new int*[*height];
    newmatrix[0] = new int[width]; 
    for (int i = 0; i < *height - 1; i++)
        newmatrix[i + 1] = matrix[i];
    for (size_t i = 0; i < width; i++)
        newmatrix[0][i] = rand() % 20 + 1;
    matrix = newmatrix;
    return matrix;
}

int **insertRow(int **matrix,int *height,int *width,int index){ 
    ++(*height);
    int **newmatrix = new int*[*height];
    for (int i = 0; i < index; i++)
        newmatrix[i] = matrix[i];
    newmatrix[index] = new int[*width];
    for (size_t i = 0; i < *width; i++)
        newmatrix[index][i] = rand() % 20 + 1;
    for (size_t i = index; i < *height; i++){
            newmatrix[i + 1] = matrix[i];
    }
    matrix = newmatrix;
    return matrix;   
}


int **pop_row_front(int **matrix,int *height,int *width){ 
    --(*height);
    int **newmatrix = new int*[*height];
    for (size_t i = 0; i < *width; i++)
    {
        newmatrix[i] = new int[*width];
    }
    
    for (size_t i = 0; i < *height; i++)
    {
        for (size_t j = 0; j < *width; j++)
        {
            newmatrix[i][j] = matrix[i + 1][j];
        }
    }
    matrix = newmatrix;
    return matrix;
}

int **pop_row_back(int **matrix,int *height,int *width){ 
    --(*height);
    int **newmatrix = new int*[*height];
    for (size_t i = 0; i < *width; i++)
    {
        newmatrix[i] = new int[*width];
    }
    for (size_t i = 0; i < *height; i++)
    {
        for (size_t j = 0; j < *width; j++)
        {
            newmatrix[i][j] = matrix[i][j];
        }
    }
    matrix = newmatrix;
    return matrix;
}

int **erase_row(int **matrix,int *height,int *width,int index){
    --(*height);
    int **newmatrix = new int*[*height];
    for (size_t i = 0; i < *width; i++)
        newmatrix[i] = new int[*width];
    for (size_t i = 0; i < index; i++)
        for (size_t j = 0; j < *width; j++)
            newmatrix[i][j] = matrix[i][j];
    for (size_t i = index; i < *height; i++)
    {
        for (size_t j = 0; j < *width; j++)
            newmatrix[i][j] = matrix[i + 1][j]; 
    }
    matrix = newmatrix; 
    return matrix;
}


int **push_col_back(int **matrix,int *height,int *width){ 
    ++(*width);
    int **newmatrix = new int*[*height];
    for (size_t i = 0; i < *height; i++)
        newmatrix[i] = new int[*width];
    for (size_t i = 0; i < *height; i++)
        for (size_t j = 0; j < *width; j++)
            newmatrix[i][j] = matrix[i][j];
    for (size_t i = 0; i < *height; i++)
        newmatrix[i][*width-1] = rand() % 20 + 1;
    matrix = newmatrix; 
    return matrix;
}

int **push_col_front(int **matrix,int *height,int *width){ 
   ++(*width);
   int **newmatrix = new int*[*height]; 
    for (size_t i = 0; i < *height; i++)
        newmatrix[i] = new int[*width];
    for (size_t i = 0; i < *height; i++)
        for (size_t j = 0; j < *width; j++)
            newmatrix[i][j + 1] = matrix[i][j];
    for (size_t i = 0; i < *height; i++)
        newmatrix[i][0] = rand() % 20 + 1;
    matrix = newmatrix;
    return matrix;
}

int **instercol(int **matrix,int *height,int *width,int index){ 
    ++(*width);
    int **newmatrix = new int*[*height]; 
    for (size_t i = 0; i < *height; i++)
        newmatrix[i] = new int[*width];
     for (size_t i = 0; i < *height; i++)
        for (size_t j = 0; j < index; j++)
            newmatrix[i][j] = matrix[i][j];
    for (size_t i = 0; i < *height; i++)
        newmatrix[i][index] = rand() % 20 + 1;
     for (size_t i = 0; i < *height; i++)
        for (size_t j = index; j < *width; j++)
            newmatrix[i][j + 1] = matrix[i][j];
    matrix = newmatrix;
    return matrix;
}


int **pop_col_back(int **matrix,int *height,int *width){
    --(*width);
    int **newmatrix = new int*[*height]; 
    for (size_t i = 0; i < *height; i++)
        newmatrix[i] = new int[*width];
    for (size_t i = 0; i < *height; i++)
        for (size_t j = 0; j < *width; j++)
            newmatrix[i][j] = matrix[i][j];
    matrix = newmatrix;
    return matrix;   
}

int **pop_col_front(int **matrix,int *height,int *width){
    --(*width);
    int **newmatrix = new int*[*height]; 
    for (size_t i = 0; i < *height; i++)
        newmatrix[i] = new int[*width];
    for (size_t i = 0; i < *height; i++)
        for (size_t j = 0; j < *width; j++)
            newmatrix[i][j] = matrix[i][j + 1];
    matrix = newmatrix;
    return matrix;  
}

int **erase_col(int **matrix,int *height,int *width,int index){
    --(*width);
    int **newmatrix = new int*[*height]; 
    for (size_t i = 0; i < *height; i++)
        newmatrix[i] = new int[*width];
    for (size_t i = 0; i < *height; i++)
        for (size_t j = 0; j < index; j++)
            newmatrix[i][j] = matrix[i][j];
     for (size_t i = 0; i < *height; i++)
        for (size_t j = index; j < *width; j++)
            newmatrix[i][j] = matrix[i][j + 1];
    matrix = newmatrix;
    return matrix;
}