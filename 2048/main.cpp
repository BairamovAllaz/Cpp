#include "stdrfx.h"
#include "Function.h"
#include "Function.cpp"




int main()
{
    srand(time(0));
    int height = 4, width = 4;
    bool gameStartedFirst = true;
    int **matrix = CreateMatrix(height, width);
    char s, move;
    bool gameon = true;
    cout << "Press s to start : ";
    cin >> s;
    while (s != 's')
    {
        cout << "Press s to start : ";
        cin >> s;
    }
    cout << "-------------------Game 2048---------------- started!" << endl;
    cout << endl;
    FillRand(matrix, height, width, gameStartedFirst);
    gameStartedFirst = false;
    PrintArea(matrix, height, width);
    gameon = checkGame(matrix,height,width);
    while (gameon)
    {
        gameStartedFirst = false;
        cout << "w - TOP| s - BOTTOM| a - LEFT| d - RIGHT| e - EXIT : ";
        cin >> move;

        while (move != 'w' && move != 's' && move != 'a' && move != 'd' && move != 'e')
        {
            cout << "AGAIN --- t - TOP| b - BOTTOM| l - LEFT| r - RIGHT| e - EXIT : ";
            cin >> move;
        }
        if (move == 'e')
        {
            break;
        }
        system("clear");
        game(move, matrix, height, width);
        FillRand(matrix, height, width, gameStartedFirst);
        PrintArea(matrix, height, width);
        gameon = checkGame(matrix,height,width);
        cout << "w - TOP| s - BOTTOM| a - LEFT| d - RIGHT| e - EXIT : ";
        cin >> move;
        system("clear");
        game(move, matrix, height, width);
        FillRand(matrix, height, width, gameStartedFirst);
        PrintArea(matrix, height, width);
        gameon = checkGame(matrix,height,width);
    }

    cout << "End game" << endl;

    deleteMatrix(matrix, height, width);
    return 0;
}