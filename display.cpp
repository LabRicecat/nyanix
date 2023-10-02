#include "display.hpp"

void disinit() {
    dwrite(distart, NYANIX_DEVICEOUT_START);
    dwrite(dirows, NYANIX_DISPLAY_ROWS);
    dwrite(dicols, NYANIX_DISPLAY_COLUMNS);
}

// maybe ncurses ?
void disshow() {

}
