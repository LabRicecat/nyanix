#ifndef NYANIX_REGISTERS_HPP
#define NYANIX_REGISTERS_HPP

#include "unit.hpp"
#include "disk.hpp"

#define nxdeclreg(name, idx) nxdiskname(name, NYANIX_REG_START, idx) 

nxdeclreg( raa, 0 );
nxdeclreg( rab, 1 );
nxdeclreg( rac, 2 );
nxdeclreg( rad, 3 );
nxdeclreg( rae, 4 );

nxdeclreg( regs, 40 ); // starting 
nxdeclreg( rams, 41 );
nxdeclreg( deos, 42 );
nxdeclreg( mems, 43 );
nxdeclreg( deis, 44 );
nxdeclreg( csts, 45 );
nxdeclreg( stks, 46 );

nxdeclreg( ic, NYANIX_REG_SIZE - 1 ); // instruction counter
nxdeclreg( sp, NYANIX_REG_SIZE - 2 ); // stack pointer
nxdeclreg( ss, NYANIX_REG_SIZE - 3 ); // stack size 
nxdeclreg( csp, NYANIX_REG_SIZE - 4 ); // callstack pointer
nxdeclreg( css, NYANIX_REG_SIZE - 5 ); // callstack size

void regset();

#endif
