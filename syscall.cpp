#include "syscall.hpp"
#include "registers.hpp"
#include <cstdio>

void syshandle(syscall_t sys) {
    switch(sys) {
        case sysdbg:
            fwrite(dread(raa), sizeof(unit_t), 1, stdout);
            break;
    }
}

