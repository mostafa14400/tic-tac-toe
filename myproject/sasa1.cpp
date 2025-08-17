#include <iostream>
using namespace std;

char board[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };

void drawBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << "\n";
        if (i < 2) cout << "---|---|---\n";
    }
    cout << "\n";
}

bool checkWin(char player) {
    // Rows & Columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
    }
    // Diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;

    return false;
}

bool isDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

void makeMove(char player) {
    int choice;
    bool valid = false;

    do 
    {
        cout << "Player " << player << ", enter your move (1-9): ";
        cin >> choice;

        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;

        if (choice >= 1 && choice <= 9 && board[row][col] != 'X' && board[row][col] != 'O') {
            board[row][col] = player;
            valid = true;
        }
        else {
            cout << "Invalid move! Try again.\n";
        }
    } while (!valid);
}

int main() 
{
    char currentPlayer = 'X';
    bool gameOver = false;

    cout << "=== Tic Tac Toe Game ===\n";
    drawBoard();

    while (!gameOver) {
        makeMove(currentPlayer);
        drawBoard();
        if (checkWin(currentPlayer)) {
            cout << "Player " << currentPlayer << " wins!!!!\n";
            break;
        }

        if (isDraw()) {
            cout << "It's a draw! \n";
            break;
        }
        if (currentPlayer == 'X') 
        {
            currentPlayer = 'O';
        }
        else 
        {
            currentPlayer = 'X';
        }
    }

    return 0;
}
