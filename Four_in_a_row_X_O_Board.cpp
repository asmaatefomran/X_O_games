#include <iostream>
#include <algorithm>
#include <iomanip>
#include <random>
#include"BoardGame_Classes.h"
using namespace std;
Four_in_a_row_X_O_Board::Four_in_a_row_X_O_Board(){
  n_rows=6;n_cols=7;
  board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}

bool Four_in_a_row_X_O_Board:: update_board(int x,int y, char mark) {
    //In Four_in_a_row_X_O_Board.cpp

        for (int i = n_rows - 1; i >= 0; --i) {
            if (board[i][y] == 0) {
                board[i][y] = mark;
                ++n_moves;
                return true;
            }
        }
        return false; // Column is full
    }


// Display the board and the pieces on it
void Four_in_a_row_X_O_Board::display_board() {
    for (int i=0;i<n_rows;i++) {
        cout << "\n| ";
        for (int j=0;j<n_cols;j++) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board [i][j] << " |";
        }
        cout << "\n----------------------------------------------------------------";
    }
    cout << endl;
}
bool Four_in_a_row_X_O_Board::is_winner() {
    // Check for a winner horizontally
    for (int row = 0; row < n_rows; ++row) {
        for (int col = 0; col <= n_cols - 3; ++col) {
            char symbol = board[row][col];
            if (symbol != 0 && symbol == board[row][col + 1] && symbol== board[row][col+2] && symbol==board[row][col + 3] ) {
                return true;
            }
        }
    }

    // Check for a winner vertically
    for (int row = 0; row <= n_rows - 3 ;++row)
     {
         for (int col = 0; col < n_cols; ++col){
            char symbol = board[row][col];
            if (symbol != 0 && board[row + 1][col] == symbol && board[row + 2][col] == symbol && board[row + 3][col] == symbol) {
                return true;
            }
        }
    }

    // Check for a winner diagonally (downward)
    for (int row = 0; row <= n_rows - 3; ++row) {
        for (int col = 0; col <= n_cols - 3; ++col) {
            char symbol = board[row][col];
            if (symbol != 0 && board[row + 1][col + 1] == symbol && board[row + 2][col + 2] == symbol && board[row + 3][col + 3] == symbol) {
                return true;
            }
        }
    }

    // Check for a winner diagonally (upward)
    for (int row = 0; row < n_rows-3; ++row) {
        for (int col = 3; col <= n_cols - 4; ++col) {
            char symbol = board[row][col];
            if (symbol != 0 && board[row + 1][col - 1] == symbol && board[row + 2][col - 2] == symbol && board[row + 3][col -3] == symbol) {
                return true;
            }
        }
    }

    return false;
}
bool Four_in_a_row_X_O_Board::is_draw(){
    return (n_moves == 42 && !is_winner());

}
bool Four_in_a_row_X_O_Board::game_is_over(){
    return n_moves >= 42;

}

