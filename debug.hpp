#ifndef NYANIX_DEBUG_HPP
#define NYANIX_DEBUG_HPP

#include "disk.hpp"
#include "nxdf/nxdf.hpp"

#include <iostream>

void diskinfo();

void load_prog(unit_t* prog, unit_t size);

void memsnip(unit_t begin, unit_t size, int wrap = 10);

void nxdf_display(nxdf* df);

#endif
