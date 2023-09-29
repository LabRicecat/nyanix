#ifndef NYANIX_REGISTERS_HPP
#define NYANIX_REGISTERS_HPP

#ifndef NYANIX_REGISTERS 
#define NYANIX_REGISTERS 20
#endif

#include "unit.hpp"
#include "disk.hpp"

#define nxdeclreg(name, idx) inline const addr_t name = NYANIX_REG_START + idx

nxdeclreg( raa, 0 );
nxdeclreg( rab, 1 );
nxdeclreg( rac, 2 );

nxdeclreg( ic, NYANIX_REGISTERS - 1 ); // instruction counter
nxdeclreg( sp, NYANIX_REGISTERS - 2 ); // stack pointer
nxdeclreg( rs, NYANIX_REGISTERS - 3 ); // stack size 

#undef nxdeclreg

#endif
