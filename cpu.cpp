#include "cpu.hpp"

bool validexec(unit_t ex) {
    return ex >= inst::nop && ex < inst::max;
}

addr_t cpuexec(addr_t ex) {
    switch(*dread(ex)) {
        case inst::nop:
            break;
        case inst::inc:
            ++*dread(*dread(++ex));
            break;
        case inst::dec:
            --*dread(*dread(++ex));
            break;
    }

    return ex;
}
