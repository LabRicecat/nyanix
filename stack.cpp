#include "stack.hpp"
#include "disk.hpp"

void spush(addr_t addr) {
    ++*dread(ss);
    dwrite(*dread(sp), *dread(addr));
    ++*dread(sp);
}

void spop() {
    --*dread(ss);
    --*dread(sp);
}

bool sempty() {
    return *dread(ss) == 0;
}

unit_t ssize() {
    return *dread(css);
}

void cspush(addr_t addr) {
    ++*dread(css);
    dwrite(*dread(csp), *dread(addr));
    ++*dread(csp);
}

void cspop() {
    --*dread(css);
    --*dread(csp);
}

bool csempty() {
    return *dread(css) == 0;
}

unit_t cssize() {
    return *dread(css);
}
