#ifndef NYANIX_DISPLAY_HPP
#define NYANIX_DISPLAY_HPP

#ifndef NYANIX_DISPLAY_ROWS
#define NYANIX_DISPLAY_ROWS 100
#endif

#ifndef NYANIX_DISPLAY_COLUMNS
#define NYANIX_DISPLAY_COLUMNS 40
#endif

#include "disk.hpp"

nxdiskname(dirows, NYANIX_DEVICEOUT_START, 0);
nxdiskname(dicols, NYANIX_DEVICEOUT_START, 1);
nxdiskname(distart, NYANIX_DEVICEOUT_START, 2);

void disinit();
void disshow();

#endif
