#include "tictactoe.hpp"

TicTacToe::TicTacToe(){
}

bool TicTacToe::Place(int fieldnumber){ // 0 - 8
    //place if valid and increase turns, change turning player
    if(!this->field[fieldnumber]){ //field is still zero
        this->field[fieldnumber] = this->turningplayer + 1;
        this->turningplayer = this->turningplayer ? 0 : 1;
        this->turns++;
    }

    //check win
    this->winner = this->CheckWin();
    if(this->winner != 0) return false;

    //game ended by filled up field
    if(this->turns >= 9){
        return false;
    }
    return true; //only return true if a next turn should be made
};

std::string TicTacToe::GenerateField(){
    std::array<std::string, 3> fieldvalues = {" ", "x", "o"}; //convert number to displayed sign
    std::stringstream ss;
    ss << "\t [" << fieldvalues[this->field[0]] << "] [" << fieldvalues[this->field[1]] << "] [" << fieldvalues[this->field[2]] << "] \n";
    ss << "\t [" << fieldvalues[this->field[3]] << "] [" << fieldvalues[this->field[4]] << "] [" << fieldvalues[this->field[5]] << "] \n";
    ss << "\t [" << fieldvalues[this->field[6]] << "] [" << fieldvalues[this->field[7]] << "] [" << fieldvalues[this->field[8]] << "] \n";
    return ss.str();
};

int TicTacToe::CheckWin(){
    //horizontal
    if ((this->field[0] == this->field[1]) && (this->field[1] == this->field[2]) && this->field[0] != 0) return this->field[0];
    if ((this->field[3] == this->field[4]) && (this->field[4] == this->field[5]) && this->field[3] != 0) return this->field[3];
    if ((this->field[6] == this->field[7]) && (this->field[7] == this->field[8]) && this->field[6] != 0) return this->field[6];
    //vertically
    if ((this->field[0] == this->field[3]) && (this->field[3] == this->field[6]) && this->field[0] != 0) return this->field[0];
    if ((this->field[1] == this->field[4]) && (this->field[4] == this->field[7]) && this->field[1] != 0) return this->field[1];
    if ((this->field[2] == this->field[5]) && (this->field[5] == this->field[8]) && this->field[2] != 0) return this->field[2];
    //diagonal
    if ((this->field[0] == this->field[4]) && (this->field[4] == this->field[8]) && this->field[0] != 0) return this->field[0];
    if ((this->field[2] == this->field[4]) && (this->field[4] == this->field[6]) && this->field[2] != 0) return this->field[2];    
    
    //return 0 for draw or no win
    return 0;
};
