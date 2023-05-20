#include <iostream>
using namespace std;

vector<vector<char>> board = {{'-', '-', '-'},
                              {'-', '-', '-'},
                              {'-', '-', '-'}};

void print()
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool check(int row, int col, char player)
{
    bool isWin = true;
    // check row
    for (int i = 0; i < board.size(); i++)
    {
        if (board[row][i] != player)
            isWin = false;
    }
    if (isWin)
        return true;

    // check column
    isWin = true;
    for (int i = 0; i < board[col].size(); i++)
    {
        if (board[i][col] != player)
            isWin = false;
    }
    if (isWin)
        return true;

    // check diagonal
    isWin = true;
    for (int i = 0; i < board.size(); i++)
    {
        if (board[i][i] != player)
            isWin = false;
    }
    if (isWin)
        return true;

    // check reverse diagonal
    isWin = true;
    for (int i = 0; i < board.size(); i++)
    {
        if (board[i][board.size() - 1 - i] != player)
            isWin = false;
    }
    if (isWin)
        return true;

    return isWin;
}

int main()
{
    bool player1 = true;
    int totalMoves = board.size() * board[0].size();

    while (totalMoves)
    {
        print();
        int row, col;
        char symbol = (player1 ? 'X' : 'O');

        cout << "Player " << (player1 ? "1 (X)" : "2 (O)") << " turn. Enter row and column(1-3): " << endl;
        cin >> row >> col;

        while (col < 1 || row < 1 || row > board.size() || col > board[0].size())
        {
            cout << "Invalid number. Please try again!" << endl;
            cin >> row >> col;
        }

        while (board[row - 1][col - 1] != '-')
        {
            cout << "Invalid move. Please try again!" << endl;
            cin >> row >> col;
        }

        row--;
        col--;

        board[row][col] = symbol;
        totalMoves--;

        bool isWin = check(row, col, symbol);

        if (isWin)
        {
            print();
            cout << "Player " << (player1 ? "1" : "2") << " wins!" << endl;
            return 0;
        }

        player1 = !player1;
    }

    print();
    cout << "Tie game!" << endl;

    return 0;
}