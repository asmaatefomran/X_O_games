#include<iostream>
#include<random>
#include<iomanip>
#include<algorithm>
#include"BoardGame_Classes.h"
using namespace std;

// Give player a symbol to use in playing
// It can be X or O or others
// This is needed for computer players
// as it does not ask for a name


// Optionally, you can give him ID or order
// Like Player 1 and Player 2

// Get desired move: x y (each between 0 and 2)
// Virtual (can change for other player types)
void FourinRowPlayer::get_move (int& x, int& y) {
    cout << "\nPlease enter your move  y (0 to 6)  separated by spaces: ";
    cin >> y;
    x=0;
}
