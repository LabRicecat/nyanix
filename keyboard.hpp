#ifndef NYANIX_KEYBOARD_HPP
#define NYANIX_KEYBOARD_HPP

#include "disk.hpp"

#ifndef NYANIX_KEYBOARD_OFFSET
#define NYANIX_KEYBOARD_OFFSET 3
#endif

nxdiskname(kb, NYANIX_DEVICEIN_START, NYANIX_KEYBOARD_OFFSET);

void keypoll();

#endif
