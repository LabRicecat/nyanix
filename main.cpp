#include <iostream>

#include "instructions.hpp"
#include "disk.hpp"
#include "registers.hpp"
#include "cpu.hpp"

#include "debug.hpp"

int main() {
    // diskinfo();
    unit_t prog[] = { 
        inst::put, 35, raa,
        inst::sys, sysdbg,
        inst::hlt
    };
    load_prog(prog, sizeof(prog)/sizeof(unit_t));

    regset();
    dwrite(ic, NYANIX_MEMORY_START);

    while(*dread(*dread(ic)) != inst::hlt)
        cpuexec();

    std::cout << *dread(raa) << "\n";
    std::cout << *dread(rab) << "\n";
    std::cout 
        << "-----\n"
        << "chunked: " << dchunked() << "\n"
        << "alloced: " << (dchunked() * NYANIX_CHUNK_SIZE) << "\n";

    memsnip(NYANIX_MEMORY_START, 40);
    
    dfree();
}
