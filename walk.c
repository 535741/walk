#include <stdio.h>
#include <ncurses.h>

int print;
char sprite_char = '@';

void sprite(int y, int x){
    if(print == 1){
        mvprintw(y, x, "%c", sprite_char);
    }
}

int main(void){
    int y, x, row, col;
    initscr();
    noecho();
    getmaxyx(stdscr, row, col);
    y = row/2;
    x = col/2;
    print = 0;
    mvprintw(row- 1, 0, "(p)-start printing (s)-stop printing (f)-set char (c)-clear (q)-quit");
    mvprintw(row - 2, 0, "(h,j,k,l)-move (w)-save (r)-restore");
        for(;;){
        move(y, x);
        refresh();
        switch(getch()){
            case 'h':
                x -= 1;
                sprite(y, x);
                break;
            case 'j':
                y += 1;
                sprite(y, x);
                break;
            case 'k':
                y -= 1;
                sprite(y, x);
                break;
            case 'l':
                x += 1;
                sprite(y, x);
                break;
            case 'c':
                clear();
                getmaxyx(stdscr, row, col);
                y = row/2;
                x = col/2;
                mvprintw(row - 1, 0, "(p)-start printing (s)-stop printing (f)-set char (c)-clear (q)-quit");
                mvprintw(row - 2, 0, "(h,j,k,l)-move (w)-save (r)-restore");
                sprite(y, x);
                break;
            case 'p':
                print = 1;
                sprite(y, x);
                break;
            case 's':
                print = 0;
                break;
            case 'f':
                sprite_char = getch();
                break;
            case 'w':
                scr_dump("ascii.txt");
                break;
            case 'r':
                scr_restore("ascii.txt");
                break;
            case 'q':
                endwin();
                goto KILL;
            default:
                break;
        }
    } 
KILL:
} 
