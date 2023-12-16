/*#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "BoardGame_Classes.h"
using namespace std;

// Set the board
Pyramic_Board::Pyramic_Board () {
    n_rows =3;
    n_cols = 5;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}

// Return true  if move is valid and put it on board
// within board boundaries in empty cell
// Return false otherwise
bool Pyramic_Board::update_board (int x, int y, char mark){
    // Only update if move is valid
    if ((x >=1&&y>=1)||(x > 2 || y < 0 || y > 2) && (board[x][y] == 0)) {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else
        return false;
}*/
#include <iostream>
#include <vector>
#include "BoardGame_Classes.h"
using namespace std;


// Implement the constructor
Pyramic_Board::Pyramic_Board() {
    // Initialize the board for Pyramid Tic-Tac-Toe
    n_rows =3;
    n_cols = 5;
    board = new char*[3];
    for (int i = 0; i < 3; i++) {
        board [i] = new char[5];
        for (int j = 0; j < 5; j++)
            board[i][j] = 0;
    }
}

// Implement the functions
bool Pyramic_Board::update_board(int x, int y, char symbol) {
    // Implement the update logic based on the game rules
    if (!((x < 1 &&y<=1)||(x<=1&&y<1)||(x<=1&&y>3)||(x<1&&y>=3)|| x >= n_rows || y < 0 || y >= n_cols) && board[x][y] == 0) {
        board[x][y] = symbol;
        n_moves++;
        return true;
    } else {
        return false;
    }
}

void Pyramic_Board::display_board() {
    // Implement the display logic for the Pyramid Tic-Tac-Toe board
    for (int i: {0,1,2}) {
        cout << "\n ";
        for (int j: {0,1,2,3,4,}) {
            if((i==1&&j<1)||(i==1&&j>3))cout<<setw(4)<<"        "<<"      ";
            else if((i == 0 &&j<=1)||(i==0&&j<1)||(i==0&&j>3)||(i==0&&j>=3))cout<<setw(4)<<"     "<<"      ";
            else {
                cout << "|(" << i << "," << j << ")";
                cout << setw(4) << board[i][j] ;
                if(i>1)cout<<" ";
            }
        }
        if(i==2)cout<<"|";
        cout << "\n---------------------------------------------------------";
    }
    cout << endl;
}

bool Pyramic_Board::is_winner() {
    // Implement the logic to check for a winner based on the game rules
   //check diagonal
    if((board[0][2]==board[1][3]&&board[0][2]==board[2][4])||(board[0][2]==board[1][1]&&board[0][2]==board[2][0])&&board[0][2]!=0)
        return true;
    //check all possibles in row 2
    if((board[2][0]==board[2][1]&&board[0][2]==board[2][2]&&board[2][0]!=0)||(board[2][1]==board[2][2]&&board[2][1]==board[2][3]&&board[2][1]!=0)||(board[2][2]==board[2][3]&&board[2][2]==board[2][4]&&board[2][2]!=0))
        return true;
    //check row 1
    if(board[1][1]==board[1][2]&&board[1][1]==board[1][3]&&board[1][1]!=0)
        return true;
    //check vertical
    if(board[0][2]==board[1][2]&&board[0][2]==board[2][2]&&board[0][2]!=0)
        return true;

    return false;
}

bool Pyramic_Board::is_draw() {
    // Implement the logic to check for a draw based on the game rules
    return (n_moves == 9 && !is_winner());
}

bool Pyramic_Board::game_is_over() {
    // Implement the logic to check if the game is over based on the game rules
    return n_moves >= 9;
}

