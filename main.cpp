#include <iostream>

#include "instructions.hpp"
#include "disk.hpp"
#include "registers.hpp"
#include "cpu.hpp"

#include "debug.hpp"

int main() {
    diskinfo();
    unit_t prog[] = {
        inst::put, 10, raa,
        inst::put, 0, rac,
        inst::put, 13, rad,
        inst::put, 23, rae,
        inst::inc, rab,
        inst::dec, raa,
        inst::get, raa, rab,
        inst::nop,
        inst::hlt
    };
    load_prog(prog, sizeof(prog)/sizeof(unit_t));


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
