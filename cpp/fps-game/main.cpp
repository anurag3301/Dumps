#include <iostream>
#include <ncurses.h>
using namespace std;

int main(){
    initscr();
    cbreak();
    noecho();
    int height, width, start_y, start_x;

    height = 10;
    width = 20;
    start_y = start_x = 10;

    WINDOW *win = newwin(height, width, start_y, start_x);
    refresh();

    box(win, 0, 0);
    mvwprintw(win, 1, 1, "This is in the box");
    wrefresh(win);

    int c = getch();
    endwin();

    return 0;
}
