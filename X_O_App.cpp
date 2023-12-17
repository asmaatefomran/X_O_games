// Class definition for XO_App class
// Author:  Mohammad El-Ramly
// Date:    10/10/2022
// Version: 1

#include <iostream>
#include"BoardGame_Classes.h"
#include "Player.cpp"
#include "PyramicPlayer.cpp"
#include "FourinRowPlayer.cpp"
#include "FiveXFivePlayer.cpp"
#include"GameManager.cpp"
#include"RandomPlayer.cpp"
#include"Pyramic_Board.cpp"
#include "Four_in_a_row_X_O_Board.cpp"
#include "TICTAC_X_O_Board.cpp"
using namespace std;

int main() {
    cout<<"Welcome to the Board Game App!\n"<<"Choose a game(^_^):\n"
        <<"1.Pyramic\n"
        <<"2.Four in a row\n"
        <<"3.X_O\n";
    
    int gameChoice;
    cin>>gameChoice;
    if(gameChoice==1){
        Pyramic_Board* gameBoard;
        PyramicPlayer* players[2];
        players[0] = new PyramicPlayer (1, 'x');
       // players[0]->get_move(1 ,'X',gameChoice);
        cout << "Welcome to FCAI Pyramic x_o Game. :)\n";
        cout << "Press 1 if you want to play with computer: ";
        int choice;
        cin >> choice;
        if (choice != 1)
            players[1] = new PyramicPlayer (2, 'o');
        /*else
            //Player pointer points to child
            players[1] = new RandomPlayer ('o', 3);*/

        gameBoard=new Pyramic_Board();
        GameManager* x_o_game=new GameManager(gameBoard, players);
        x_o_game->run();
        delete players[0];
        delete players[1];
        delete gameBoard;
        delete x_o_game;
        system ("pause");
        return 0;

        }
    else if(gameChoice==2){
        Four_in_a_row_X_O_Board* gameBoard;
        FourinRowPlayer* players[2];
        players[0] = new FourinRowPlayer (1, 'x');
       // players[0]->get_move(1 ,'X',gameChoice);
        cout << "Welcome to FCAI Pyramic x_o Game. :)\n";
        cout << "Press 1 if you want to play with computer: ";
        int choice;
        cin >> choice;
        if (choice != 1)
            players[1] = new FourinRowPlayer (2, 'o');
        /*else
            //Player pointer points to child
            players[1] = new RandomPlayer ('o', 3);*/

        gameBoard=new Four_in_a_row_X_O_Board();
        GameManager* x_o_game=new GameManager(gameBoard, players);
        x_o_game->run();
        delete players[0];
        delete players[1];
        delete gameBoard;
        delete x_o_game;
        system ("pause");
        return 0;
 
    }
    else if(gameChoice==3){
       TICTAC_X_O_Board* gameBoard;
        FiveXFivePlayer* players[2];
        players[0] = new FiveXFivePlayer (1, 'x');
       // players[0]->get_move(1 ,'X',gameChoice);
        cout << "Welcome to FCAI Pyramic x_o Game. :)\n";
        cout << "Press 1 if you want to play with computer: ";
        int choice;
        cin >> choice;
        if (choice != 1)
            players[1] = new FiveXFivePlayer (2, 'o');
        /*else
            //Player pointer points to child
            players[1] = new RandomPlayer ('o', 3);*/

        gameBoard=new TICTAC_X_O_Board();
        GameManager* x_o_game=new GameManager(gameBoard, players);
        x_o_game->run();
        delete players[0];
        delete players[1];
        delete gameBoard;
        delete x_o_game;
        system ("pause");
        return 0;
    }
        


}
