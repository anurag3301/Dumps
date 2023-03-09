#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <wchar.h>
#include <locale.h>
#include <time.h>

WINDOW *create_newwin(int height, int width, int starty, int startx);
void destroy_win(WINDOW *local_win);

char** create_matrix(int size, int prob){
    size = (size-2) * 2;
    char** matrix = malloc(sizeof(char*) * size);
    for(size_t i=0; i<size; i++){
        matrix[i] = malloc(sizeof(char) * size);
        for(size_t j=0; j<size; j++){
            matrix[i][j] = (rand() % 100) < prob;
        }
    }

    return matrix;
}

void destroy_matrix(char** mat, int size){
    size = (size-2) * 2;
    for(size_t i=0; i<size; i++){
        free(mat[i]);
    }
    free(mat);
}

void draw_matrix(char** mat, int size, int startx, int starty){
    size = (size-2) * 2;
    for(int i=0; i<size; i+=2){
        for(int j=0; j<size; j++){
            char top = mat[i][j];
            char bottom = mat[i+1][j];
            if(top && bottom)
                mvprintw(starty+1+(i/2), startx+1+j, "%ls", L"█");
            else if(top)
                mvprintw(starty+1+(i/2), startx+1+j, "%ls", L"▀");
            else if(bottom)
                mvprintw(starty+1+(i/2), startx+1+j, "%ls", L"▄");
            else
                mvprintw(starty+1+(i/2), startx+1+j, "%ls", L" ");
        }
    }
}

int calc_neighbour(char** mat, int size, int row, int col){
    int count = 0;

    if(row > 0 && col > 0) count += mat[row-1][col-1];
    if(row > 0) count += mat[row-1][col];
    if(row > 0 && col < size-1) count += mat[row-1][col+1];

    if(col > 0) count += mat[row][col-1];
    if(col < size-1) count += mat[row][col+1];

    if(row < size-1 && col > 0) count += mat[row+1][col-1];
    if(row < size-1) count += mat[row+1][col];
    if(row < size-1 && col < size-1) count += mat[row+1][col+1];
    return count;
}

char** next_move(char** mat, int size){
    char** temp = create_matrix(size, 0);
    size = (size-2) * 2;
    for(int i=0; i<size; i++){
    for(int j=0; j<size; j++){
        int neighbour = calc_neighbour(mat, size, i, j);
        if(mat[i][j] && (neighbour == 2 || neighbour == 3)){
            temp[i][j] = 1;
        }
        else if(!mat[i][j] && neighbour == 3){
            temp[i][j] = 1;
        }
    }
    }
    destroy_matrix(mat, (size/2)+2);
    return temp;
}


int main(int argc, char *argv[]){	
    setlocale(LC_ALL, "");
    srand ( time(NULL) );
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

    char** matrix = create_matrix(height, 50);
    draw_matrix(matrix, height, startx+1, starty);
    mvprintw(starty-1, startx+(height)-10, "Press Enter to start!");
    mvgetch(0, 0);
    mvprintw(starty-1, startx+(height)-10, "                     ");
    int gen = 0;
    while(true){
        matrix = next_move(matrix, height);
        mvprintw(starty-1, startx+(height)-7, "Generation: %d", gen++);
        draw_matrix(matrix, height, startx+1, starty);
        refresh();
        if(0)
            mvgetch(0, 0);
        else
            delay_output(50);
    }
    destroy_matrix(matrix, height);
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
