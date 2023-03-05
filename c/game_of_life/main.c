#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

WINDOW *create_newwin(int height, int width, int starty, int startx);
void destroy_win(WINDOW *local_win);

int main(int argc, char *argv[]){	
    WINDOW *my_win;
	int startx, starty, width, height;
	int ch;

	initscr();
	cbreak();
	keypad(stdscr, TRUE);

	height = (float)LINES * 80/100;
	width = height*2;
	starty = (LINES - height) / 2;
	startx = (COLS - width) / 2;
	refresh();

    my_win = create_newwin(height, width, starty, startx);
		
    getch();
	endwin();
	return 0;
}

WINDOW *create_newwin(int height, int width, int starty, int startx){
   WINDOW *local_win;
   
   local_win = newwin(height, width, starty, startx);
   box(local_win, 0 , 0);
   wrefresh(local_win);
   
   return local_win;
}

void destroy_win(WINDOW *local_win){	
    wborder(local_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
    wrefresh(local_win);
    delwin(local_win);
}
