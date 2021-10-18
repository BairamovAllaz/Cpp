#include <iostream>
using namespace std;
void Enters(char **matrix,char User1,char User2,size_t height,size_t width);
bool calculateGame(char **matrix,char User1,char User2,size_t height,size_t width,int tab);
void PrintMatrix(char **matrix,size_t height,size_t width); 
void WatchLocation(char **matrix,int LocationX,int LocationY,int tab);
int main() {
    size_t width = 3,height = 3;
    char User1,User2;
    ///catch user characters!
    cout << "Enter O or X" << endl;
    cout << "Enter character user 1: ";
    cin >> User1;
    while(User1 != 'O' && User1 != 'X'){
         cout << "Enter character again user 1: ";
          cin >> User1;
    }

    cout << "Enter character user 2: ";
    cin >> User2;
    while(User2 != 'O' && User2 != 'X' || User2 == User1){
        cout << "Enter character again user 1: ";
        cin >> User2;
    }
    //////////////////////////////////
    ///create matrix
    char **matrix = new char*[height];

    for (size_t i = 0; i < height; i++)
        matrix[i] = new char[width];
    
    for (size_t i = 0; i < height; i++)
    {
        for (size_t j = 0; j < width; j++)
        {
            matrix[i][j] = '*';
        }
    }
        Enters(matrix,User1,User2,height,width);
    delete[] matrix;
    return 0;
}
//for enters chars!!!
void Enters(char **matrix,char User1,char User2,size_t height,size_t width){
    int locationX,locationY;
    int tab = 1;
     while(true){
        cout << "User - " << tab <<  " enter a location X - Y  1 - 3: " << endl;
        cout << "Location Y : ";
        cin >> locationY;
        cout << "Location X: ";
        cin >> locationX;

        while (locationY < 0 || locationY > 2 && locationX < 0 || locationX > 2)
        {
        cout << "User - " << tab <<  " enter again a location 1 - 3: ";  
        cout << "Location Y : ";
        cin >> locationY;
        cout << "Location X: ";
        cin >> locationX;    
        }

    //testing current location!
        while(matrix[locationY][locationX] != '*'){
                cout << "This location already used try another location!" << endl;
                cout << "User - " << tab <<  " enter a location 1 - 3: ";  
                cout << "Location Y : ";
                cin >> locationY;
                cout << "Location X: ";
                cin >> locationX;    

             while (locationY < 1 || locationY > 3 && locationX  < 1 || locationX > 3)
             {
                cout << "User - " << tab <<  " enter a location 1 - 3: ";  
                cout << "Location Y : ";
                cin >> locationY;
                 cout << "Location X: ";
                cin >> locationX;    
            }
        }

                if(tab == 1){
                    matrix[locationY][locationX] = User1;
                }else{
                     matrix[locationY][locationX] = User2;
                }

        //print matrix
        PrintMatrix(matrix,height,width);
       
        bool game = calculateGame(matrix,User1,User2,height,width,tab);
        if(game == true){ 
            cout << "User - " << tab << "Winned" << endl;
            break;
        }
        if(tab == 2){
            tab = 1;
        }else{
            ++tab;
        }
    }
}
//print function!
void PrintMatrix(char **matrix,size_t height,size_t width){
    for (size_t i = 0; i < height; i++)
    {
        for (size_t j = 0; j < width;j++)
        {
                cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
//for calculate game
bool calculateGame(char **matrix,char User1,char User2,size_t height,size_t width,int tab){ 
    char CurrentUser = tab == 1 ? User1 : User2; 
    int lab = 0;
    ////top corner
    for (size_t i = 0; i < height; i++)
    {
        if(matrix[0][i] == CurrentUser){ 
            ++lab;
        }
    }
    if(lab == 3)
        return true;
    else
        lab = 0;

    //center corner

    for (size_t i = 0; i < height; i++)
    {
        if(matrix[1][i] == CurrentUser){ 
            ++lab;
        }
    }
    if(lab == 3)
        return true;
    else
        lab = 0;
    //bottom corner 
    for (size_t i = 0; i < width; i++){
        if(matrix[2][i] == CurrentUser){ 
            ++lab;
        }
    }
    if(lab == 3)
        return true;
    else
        lab = 0;
    //left corner
    for (size_t i = 0; i < height; i++){
        if(matrix[i][0] == CurrentUser){ 
            ++lab;
        }
    }
    if(lab == 3)
        return true;
    else
        lab = 0;
    
    //right corner
    for (size_t i = 0; i < height; i++){
        if(matrix[i][2] == CurrentUser){ 
            ++lab;
        }
    }
    if(lab == 3)
        return true;
    else
        lab = 0;


    //center uo corner
    for (size_t i = 0; i < height; i++){
        if(matrix[i][1] == CurrentUser){ 
            ++lab;
        }
    }
    if(lab == 3)
        return true;
    else
        lab = 0;
    //first diagonal
     for (size_t i = 0; i < height; i++){
        if(matrix[i][i] == CurrentUser){ 
            ++lab;
        }
    }
    if(lab == 3)
        return true;
    else
        lab = 0;

    //second diagonal
    for (size_t i = 0; i < height; i++){
        char num = matrix[i][height - i - 1];
        if(num == CurrentUser){ 
            ++lab;
        }
    }
    if(lab == 3)
        return true;
    else
        lab = 0;

    return false;
}