#ifndef NYANIX_UNIT_HPP
#define NYANIX_UNIT_HPP

#include <cstdint>
#include <climits>

using unit_t = uint32_t;

constexpr int unitsize = CHAR_BIT * sizeof(unit_t);

#define nxKU(x) ((x) * 1000)    // kilo unit 
#define nxMU(x) ((x) * 1000000) // mega unit
#define nxPc(x) ((x) % 100)     // percent

#endif
