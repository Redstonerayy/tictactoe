#ifndef TERMINAL_HPP
#define TERMINAL_HPP

#include <ncurses.h>

//STL
#include <list>
#include <string>

class Terminal {
public:
    int rows, cols;
    std::list<std::string> lines;
    
    Terminal();
    void AddLine(std::string line);
    void RemoveLine(int index);
    void ClearLines();
    void PrintLines();
    void Erase();
    void Destroy();
    void Pause();
};

#endif
