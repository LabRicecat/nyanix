#include "cpu.hpp"
#include "registers.hpp"

bool validexec(unit_t ex) {
    return ex >= inst::nop && ex < inst::max;
}

void cpuexec() {
    switch(*dread(*dread(ic))) {
        case inst::nop:
            break;
        case inst::inc:
            ++*dread(*dread(++*dread(ic)));
            break;
        case inst::dec:
            --*dread(*dread(++*dread(ic)));
            break;
        case inst::add: {
            unit_t* v = dread(*dread(++*dread(ic)));
            unit_t* w = dread(*dread(++*dread(ic)));
            *dread(*dread(++*dread(ic))) = *v + *w;
        } break;
        case inst::sub: {
            unit_t* v = dread(*dread(++*dread(ic)));
            unit_t* w = dread(*dread(++*dread(ic)));
            *dread(*dread(++*dread(ic))) = *v - *w;
        } break;
        case inst::mul: {
            unit_t* v = dread(*dread(++*dread(ic)));
            unit_t* w = dread(*dread(++*dread(ic)));
            *dread(*dread(++*dread(ic))) = *v * *w;
        } break;
        case inst::div: {
            unit_t* v = dread(*dread(++*dread(ic)));
            unit_t* w = dread(*dread(++*dread(ic)));
            *dread(*dread(++*dread(ic))) = *v / *w;
        } break;
        case inst::divf: 
            break;
        case inst::mod: {
            unit_t* v = dread(*dread(++*dread(ic)));
            unit_t* w = dread(*dread(++*dread(ic)));
            *dread(*dread(++*dread(ic))) = *v % *w;
        } break;

        case inst::get: {
            unit_t* v = dread(*dread(++*dread(ic)));
            *dread(*dread(++*dread(ic))) = *v;
        } break;
        case inst::put: {
            unit_t* v = dread(++*dread(ic));
            *dread(*dread(++*dread(ic))) = *v;
        } break;
        
        case inst::jmp:
            *dread(ic) = *dread(*dread(++*dread(ic)));
            break;
        case inst::eq: {
            unit_t* v = dread(*dread(++*dread(ic)));
            unit_t* w = dread(*dread(++*dread(ic)));
            unit_t* p = dread(*dread(++*dread(ic)));

            if(*v == *w) 
                *dread(ic) = *p;
        } break;
        case inst::gr: {
            unit_t* v = dread(*dread(++*dread(ic)));
            unit_t* w = dread(*dread(++*dread(ic)));
            unit_t* p = dread(*dread(++*dread(ic)));

            if(*v > *w) 
                *dread(ic) = *p;
        }
        case inst::ls: {
            unit_t* v = dread(*dread(++*dread(ic)));
            unit_t* w = dread(*dread(++*dread(ic)));
            unit_t* p = dread(*dread(++*dread(ic)));

            if(*v < *w) 
                *dread(ic) = *p;
        } break;

        case inst::push:
            break;
        case inst::pop:
            break;
        case inst::top:
            break;

        case inst::bnot: {
            unit_t* v = dread(*dread(++*dread(ic)));
            *dread(*dread(++*dread(ic))) = ~*v;
        } break;
        case inst::band: {
            unit_t* v = dread(*dread(++*dread(ic)));
            unit_t* w = dread(*dread(++*dread(ic)));
            *dread(*dread(++*dread(ic))) = *v & *w;
        } break;
        case inst::bor: {
            unit_t* v = dread(*dread(++*dread(ic)));
            unit_t* w = dread(*dread(++*dread(ic)));
            *dread(*dread(++*dread(ic))) = *v | *w;
        } break;
        case inst::bxor: {
            unit_t* v = dread(*dread(++*dread(ic)));
            unit_t* w = dread(*dread(++*dread(ic)));
            *dread(*dread(++*dread(ic))) = *v ^ *w;
        } break;

        case inst::sys:
            break;
        case inst::hlt:
            break;

        case inst::deref: {
            unit_t* v = dread(*dread(++*dread(ic)));
            *dread(*dread(++*dread(ic))) = *dread(*v);
        } break;
    }

    ++*dread(ic);
}
