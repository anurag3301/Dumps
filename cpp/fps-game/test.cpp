#include <iostream>
#include <ncurses.h>
using namespace std;

int main(){
    initscr();
    cbreak();
    noecho();
    int y, x, yBeg, xBeg, yMax, xMax;

    getyx(stdscr, x, y);
    getbegyx(stdscr, yBeg, xBeg);
    getmaxyx(stdscr, yMax, xMax);

    mvprintw(yMax/2, xMax/2, "hello");

    getch();
    endwin();
    return 0;

}
