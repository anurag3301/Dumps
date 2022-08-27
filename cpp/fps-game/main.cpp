#include <iostream>
#include <ncurses.h>
#include "player.h"
using namespace std;

int main(){
    initscr();
    cbreak();
    noecho();
    curs_set(0);

    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    WINDOW *win = newwin(20, 70, (yMax/2)-10, (xMax/2)-35);
    box(win, 0, 0);
    refresh();
    wrefresh(win);

    Player *p = new Player(win, 1, 1, '@');
    do{
        p->display();
        wrefresh(win);
    }while(p->getmv() != 'x');

    getch();
    endwin();
    return 0;
}
