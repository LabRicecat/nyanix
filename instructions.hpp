#ifndef NYANIX_INSTRUCTIONS_HPP
#define NYANIX_INSTRUCTIONS_HPP

#include "unit.hpp"

using instruction_t = unit_t; 

namespace inst {
enum : instruction_t {
    nop,
        // math
    inc,
    dec,
    add,
    sub,
    mul,
    div,
    divf,
    mod,
        // memory
    get,
    put,
        // jump 
    jmp, 
    eq, 
    ls,
    gr,
        //stack
    push,
    pop,
    top,
        // boolean algebra
    band,
    bor,
    bxor,
        // system
    sys,
    hlt,
        // pointer
    deref,

    max,
};
}

#endif
