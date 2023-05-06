#include <stdio.h>
#include <ncurses.h>


void sprite(int y, int x){
    mvprintw(y, x, "@");
}

int main(void){
    int y, x, row, col;
    initscr();
    noecho();
    getmaxyx(stdscr, row, col);
    y = row/2;
    x = col/2;
    for(;;){
        sprite(y, x);
        move(0, 0);
        refresh();
        switch(getch()){
            case 'h':
                x -= 1;
                break;
            case 'j':
                y += 1;
                break;
            case 'k':
                y -= 1;
                break;
            case 'l':
                x += 1;
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
