#include "display.hpp"
#include <ncurses.h>

void disinit() {
    initscr();
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    raw();

    dwrite(distart, NYANIX_DEVICEOUT_START);
    dwrite(dirows, NYANIX_DISPLAY_ROWS);
    dwrite(dicols, NYANIX_DISPLAY_COLUMNS);
}

// maybe ncurses ?
void disshow() {
    for(int64_t r = 0; r < NYANIX_DISPLAY_ROWS; ++r)
        for(int64_t c = 0; c < NYANIX_DISPLAY_COLUMNS; ++c)
            mvprintw(r, c, "%c", *dread(r * NYANIX_DISPLAY_COLUMNS + c));  
}

void disquit() {
    endwin();
}
