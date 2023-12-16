// Class definition for XO_App class
// Author:  Mohammad El-Ramly
// Date:    10/10/2022
// Version: 1

#include <iostream>
#include"../include/BoardGame_Classes.hpp"
using namespace std;

int main() {
    cout<<"Welcome to the Board Game App!\n"<<"Choose a game(^_^):\n"
        <<"1.Four in a row\n"
        <<"2.X_O\n";
    int gameChoice;
    cin>>gameChoice;
    if(gameChoice==1||gameChoice==2){
        Board* gameBoard;


        Player* players[2];
        players[0] = new Player (1, 'x');
       // players[0]->get_move(1 ,'X',gameChoice);
        cout << "Welcome to FCAI X-O Game. :)\n";
        cout << "Press 1 if you want to play with computer: ";
        int choice;
        cin >> choice;
        if (choice != 1)
            players[1] = new Player (2, 'o');
        else
            //Player pointer points to child
            players[1] = new RandomPlayer ('o', 3);

        if(gameChoice==1){
            gameBoard=new Four_in_a_row_X_O_Board();

        }else
        {
           gameBoard=new X_O_Board();

        }



        GameManager* x_o_game=new GameManager(gameBoard, players);
        x_o_game->run();
        delete players[0];
        delete players[1];
        delete gameBoard;
        delete x_o_game;
    }
else{
    cout<<"Invaild choice"<<" "<<"Exiting....\n";

}



    system ("pause");
 return 0;
}
