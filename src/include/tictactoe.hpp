#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP

//STL
#include <array>
#include <string>
#include <sstream>
#include <iostream>

class TicTacToe {
public:
    int turningplayer = 0;
    int turns = 0;
    int winner = 0;
    std::array<int, 9> field{};

    TicTacToe();
    bool Place(int fieldnumber);
    std::string GenerateField();
    int CheckWin();
};

#endif
