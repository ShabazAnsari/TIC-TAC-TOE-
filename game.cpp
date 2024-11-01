#include <iostream>
#include <stdlib.h>

using namespace std;

char game[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

int choice, row, column;
char turn = 'X';
bool draw = false;

void display()
{
    cout << "\tPLAYER 1 -> [X] AND PLAYER 2 -> [O]\n\n";
    // cout << "\t\t    |    |    \n";
    cout << "\t\t  " << game[0][0] << " | " << game[0][1] << "  |  " << game[0][2] << " \n";
    cout << "\t\t____|____|____\n";
    cout << "\t\t    |    |    \n";
    cout << "\t\t  " << game[1][0] << " | " << game[1][1] << "  |  " << game[1][2] << " \n";
    cout << "\t\t____|____|____\n";
    cout << "\t\t    |    |    \n";
    cout << "\t\t  " << game[2][0] << " | " << game[2][1] << "  |  " << game[2][2] << " \n\n";
    // cout << "\t\t    |    |    \n";
}

void player_turn()
{
    if (turn == 'X')
    {
        cout << "\nPlayer 1 - [X] turn: ";
    }
    else if (turn == 'O')
    {
        cout << "\nPlayer 2 - [O] turn: ";
    }

    cin >> choice;

    switch (choice)
    {
    case 1:
        row = 0;
        column = 0;
        break;
    case 2:
        row = 0;
        column = 1;
        break;
    case 3:
        row = 0;
        column = 2;
        break;
    case 4:
        row = 1;
        column = 0;
        break;
    case 5:
        row = 1;
        column = 1;
        break;
    case 6:
        row = 1;
        column = 2;
        break;
    case 7:
        row = 2;
        column = 0;
        break;
    case 8:
        row = 2;
        column = 1;
        break;
    case 9:
        row = 2;
        column = 2;
        break;
    default:
        cout << "Invalid";
    }

    if (turn == 'X' && game[row][column] != 'X' && game[row][column] != 'O')
    {
        game[row][column] = 'X';
        turn = 'O';
    }

    else if (turn == 'O' && game[row][column] != 'X' && game[row][column] != 'O')
    {
        game[row][column] = 'O';
        turn = 'X';
    }

    else
    {
        cout << "Box already filled\n";
        player_turn();
    }

    // display();
}

bool gameOver()
{
    for (int i = 0; i < 3; i++)
        if (game[i][0] == game[i][1] && game[i][0] == game[i][2] || game[0][i] == game[1][i] && game[0][i] == game[2][i])
            return false;

    if (game[0][0] == game[1][1] && game[0][0] == game[2][2] || game[0][2] == game[1][1] && game[0][2] == game[2][0])
        return false;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (game[i][j] != 'X' && game[i][j] != 'O')
                return true;

    draw = true;
    return false;
}

int main()
{
    cout << "\n\n\t\t    WELCOME TO TIC-TAC-TOE GAME\n\n";
    cout << "\n\t\t\tFOR 2 PLAYERs\n\t\t";

    while (gameOver())
    {
        display();
        player_turn();
        gameOver();
    }

    if (turn == 'X' && draw == false)
        cout << "CONGRATULATIONS! Player with X has won the game";
    else if (turn == 'O' && draw == false)
        cout << "CONGRATULATIONS! Player with O has won the game";
    else
        cout << "GAME DRAW";

    return 0;
}