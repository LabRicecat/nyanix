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
    gr,
    ls,
        //stack
    push,
    pop,
        // boolean algebra
    bnot,
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
