#include <iostream>
#include <ctime>
// template <typename T, typename U>   can be used as a function template in function overloading. use to generate as many overloaded function with different data type.

using std::cin;
using std::cout;
using std::string;

bool isValid = 1;
void drawBoard(char spaces[]) {
    cout << "     "
         << "|"
         << "     "
         << "|"
         << "     " << '\n';
    cout << "  " << spaces[0] << "  |"
         << "  " << spaces[1] << "  |"
         << "  " << spaces[2] << '\n';
    cout << "_____"
         << "|"
         << "_____"
         << "|"
         << "_____" << '\n';
    cout << "     "
         << "|"
         << "     "
         << "|"
         << "     " << '\n';
    cout << "  " << spaces[3] << "  |"
         << "  " << spaces[4] << "  |"
         << "  " << spaces[5] << '\n';
    cout << "_____"
         << "|"
         << "_____"
         << "|"
         << "_____" << '\n';
    cout << "     "
         << "|"
         << "     "
         << "|"
         << "     " << '\n';
    cout << "  " << spaces[6] << "  |"
         << "  " << spaces[7] << "  |"
         << "  " << spaces[8] << '\n';
    cout << "     "
         << "|"
         << "     "
         << "|"
         << "     " << '\n';
}
void playerMove(char spaces[], char player) {
    int number;

    do
    {
        cout << "Enter a number between (1-9) : \n";
        cin >> number;
        number--;
        if (spaces[number] == ' ' && isValid == 1)
        {
            spaces[number] = player;
            isValid = 0;
            break;
        }
        else
            drawBoard(spaces);
    } while (isValid == 1);
}
void computerMove(char spaces[], char computer) {
    int number;
    srand(time(0));
    while (true)
    {
        number = rand() % 9;
        if (spaces[number] == ' ' && isValid == 0)
        {
            spaces[number] = computer;
            isValid = 1;
            break;
        }
    }
}
bool checkWinner(char spaces[], char player, char computer)
{
    int ind = 0, count = 2;
    char first_char;
    for (int i = 0; i < 9; i++)
    {
        if (spaces[i] == ' ')
            continue;
        if (spaces[i] == 'X' || spaces[i] == 'O')
        {
            ind = i;
            if (spaces[i] == 'X')
                first_char = 'X';
            else
                first_char = 'O';
        }
        for (int i = ind; i < 9; i++)
        {
            // horizontally :
            if (ind == 0 || ind == 3 || ind == 6)
            {
                if (spaces[ind] == first_char)
                {
                    if (spaces[ind + 1] == first_char)
                    {
                        if (spaces[ind + 2] == first_char)
                            return 1;
                    }
                }
            }

            // vertically :
            if (ind == 0 || ind == 1 || ind == 2)
            {
                if (spaces[ind] == first_char)
                {
                    if (spaces[ind + 3] == first_char)
                    {
                        if (spaces[ind + 6] == first_char)
                            return 1;
                    }
                }
            }

            // right diagonally :
            if (ind == 0)
            {
                if (spaces[ind] == first_char)
                {
                    if (spaces[ind + 4] == first_char)
                    {
                        if (spaces[ind + 8] == first_char)
                            return 1;
                    }
                }
            }

            // left diagonally :
            if (ind == 2)
            {
                if (spaces[ind] == first_char)
                {
                    if (spaces[ind + 2] == first_char)
                    {
                        if (spaces[ind + 4] == first_char)
                            return 1;
                    }
                }
            }
        }
    }
    return 0;
}

int main()
{
    char spaces[] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player = 'X';
    char computer = 'O';
    bool running = true;
    int count = 0;

    drawBoard(spaces);
    while (running)
    {
        playerMove(spaces, player);
        drawBoard(spaces);
        cout << "****************************\n";
        count++;
        if ((count >= 3) && checkWinner(spaces, player, computer))
        {
            cout << "You Wins!!\n";
            running = false;
            break;
        }
        if (count == 5 && checkWinner(spaces, player, computer) == 0)
        {
            cout << "It's a draw!! \n";
            break;
        }
        computerMove(spaces, computer);
        drawBoard(spaces);
        if ((count >= 3) && checkWinner(spaces, player, computer))
        {
            cout << "Computer Wins!!\n";
            running = false;
            break;
        }
    }
    cout << "THANKS FOR PLAYING !!\n";
}