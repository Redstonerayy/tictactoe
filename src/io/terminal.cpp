#include "terminal.hpp"

Terminal::Terminal(){
    //initialize ncurseremoveelements
    setlocale(LC_ALL, ""); // character format
    initscr(); //set terminal in ncurses mode
    cbreak(); //disable line buffering, allow interrupt sequences
    keypad(stdscr, TRUE); //enable Fx, arrow keys, etc.
    noecho(); //dont show use typed characters
    intrflush(stdscr, FALSE);
    nonl();

    ///get dimensions of window
    getmaxyx(stdscr,this->rows,this->cols);
};

void Terminal::AddLine(std::string line){
    this->lines.push_back(line);
};

void Terminal::RemoveLine(int index){
    std::list<std::string>::iterator removeelement = this->lines.begin();
    std::advance(removeelement, index);
    this->lines.erase(removeelement);
};

void Terminal::ClearLines(){
    this->lines.clear();
};

void Terminal::PrintLines(){
    move(0, 0);
    std::list<std::string>::iterator listelement = this->lines.begin();
    for(size_t i = 0; i < this->lines.size(); i++){
        addstr(listelement->c_str());
        addstr("\n");
        std::advance(listelement, 1);
    }
    refresh(); //update terminal, needed after every change
};

void Terminal::Erase(){
    erase();
    refresh();
};

void Terminal::Destroy(){
    endwin();
};

void Terminal::Pause(){
    getch();
};
