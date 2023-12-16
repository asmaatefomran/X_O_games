
#include<iostream>
#include<random>
#include<iomanip>
#include<algorithm>
#include"BoardGame_Classes.hpp"
using namespace std;

// Get desired move: x y (each between 0 and 2)
// Virtual (can change for other player types)
void PyramicPlayer::get_move (int& x, int& y) {
    cout << "\nPlease enter your move x and y (0 to 4) from the following Pyramid separated by spaces: ";
    cin >> x >> y;
}
