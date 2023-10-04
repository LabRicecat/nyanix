#ifndef NYANIX_SYSCALL_HPP
#define NYANIX_SYSCALL_HPP

#include "disk.hpp"

using syscall_t = unit_t;

#define nxsysdecl(i, n) constexpr syscall_t i = n 

nxsysdecl(sysdbg, 0);
nxsysdecl(sysdis, 1);

void syshandle(syscall_t sys);

#endif
