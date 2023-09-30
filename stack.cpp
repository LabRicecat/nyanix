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
    return *dread(ss);
}
