
#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include"../include/BoardGame_Classes.hpp"
using namespace std;
static bool nowin =false, dontrun=false;
TICTAC_X_O_Board::TICTAC_X_O_Board (Player* playerPtr[2] ) {
    player_tictac[0]=playerPtr[0];
    player_tictac[1]=playerPtr[1];
    n_rows = n_cols = 5;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}
bool TICTAC_X_O_Board::update_board (int x, int y, char mark) {
    if (!(x < 0 || x > 4 || y < 0 || y > 4) && (board[x][y] == 0)) {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else
        return false;
}
void TICTAC_X_O_Board::display_board() {

    for (int i: {0,1,2,3,4}) {
        cout << "\n| ";
        for (int j: {0,1,2,3,4}) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board [i][j] << " |";
        }
        cout << "\n-----------------------------";
    }
    cout << endl;
}
bool TICTAC_X_O_Board::is_winner() {
    if(n_moves!=24&&dontrun) return false;
    int i,j;
    int win1=0,win2=0;
    //iterating over rows
    for(i=0 ; i<5 ;i++){
        for(j=0; j<3 ; j++){}
        if(board[i][j]==board[i][j+1]&&board[i][j+2]==board[i][j+1]){
            if(board[i][j]==toupper('x')) win1+=1;
            else win2+=1;
        }
    }

    //iterating over columns
    for(j=0 ; j<5 ;j++){
        for(i=0; i<3 ; i++) {
            if (board[i][j] == board[i + 1][j] && board[i + 2][j] == board[i][j]) {
                if (board[i][j] == toupper('x')) win1 += 1;
                else win2++;
            }
        }
    }

    //iterating diag
    for(i=0 ; i<3 ;i++){
        for(j=0; j<3 ; j++) {
            if (board[i][j] == board[i + 1][j + 1] && board[i + 2][j + 2] == board[i + 1][j + 1]) {
                if (board[i][j] == toupper('x')) win1 += 1;
                else win2 += 1;
            }
        }
    }
    //iterating diag
    for(i=4 ; i>=2 ;i--){
        for(j=4; j>=2 ; j--) {
            if (board[i][j] == board[i - 1][j - 1] && board[i - 2][j - 2] == board[i - 1][j - 1]) {
                if (board[i][j] == toupper('x')) win1++;
                else win2++;
            }
        }
    }
    if(win1>win2 ) cout<<player_tictac[0]->to_string()<<" wins\n";
    else if(win1 < win2 ) cout<<player_tictac[1]->to_string()<<" wins\n";
    else nowin=true;

    return false;
}
bool TICTAC_X_O_Board::is_draw() {
    dontrun=true;
    return (n_moves == 24&&nowin ); }


bool TICTAC_X_O_Board::game_is_over() {
    return n_moves >= 24;
}