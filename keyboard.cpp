#include "keyboard.hpp"
#include <ncurses.h>

void keypoll() {
    int c;
    while((c = getch()) != EOF) {
        dwrite(NYANIX_DEVICEIN_START + c, 1);
    }
}
