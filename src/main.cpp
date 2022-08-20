#include <ncurses.h>

//STL
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <array>
#include <iostream>
#include <sstream>

//headers
#include "terminal.hpp"
#include "tictactoe.hpp"
#include "util.hpp"

int main(){
    //initialiaze classes
    Terminal terminal = Terminal();
    TicTacToe game = TicTacToe();
    
    //print empty field
    std::string field = game.GenerateField();
    std::vector<std::string> fieldlines = SplitString(field, '\n');
    for(int i = 0; i < fieldlines.size(); i++){
        terminal.AddLine(fieldlines[i]);
    }
    terminal.PrintLines();

    //game loop
    while(true){
        //get input of field
        int ch = getch();
        //match for 1 - 9
        ch -= 49;
        //check validity
        if(ch > -1 && ch < 9){
            bool ending = game.Place(ch);

            //display field
            std::string field = game.GenerateField();
            std::vector<std::string> fieldlines = SplitString(field, '\n');
            terminal.ClearLines();
            for(int i = 0; i < fieldlines.size(); i++){
                terminal.AddLine(fieldlines[i]);
            }

            //game ending by turnlimit or winner
            if(!ending){
                std::stringstream ss;
                ss << "Player " << game.winner << " has won!";
                terminal.AddLine(ss.str());
                terminal.PrintLines();
                break;
            }

            terminal.PrintLines();
        }
    }

    //destroy terminal
    terminal.Pause();
    terminal.Destroy();

    return EXIT_SUCCESS;
}
