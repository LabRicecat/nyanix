#include <iostream>

#include "instructions.hpp"
#include "disk.hpp"
#include "registers.hpp"
#include "cpu.hpp"

int main() {
    dwrite(10, inst::inc);
    dwrite(11, raa);
    dwrite(17000, 2);
    dwrite(raa, 6);

    cpuexec(10);

    std::cout << *dread(10) << "\n";
    std::cout << *dread(raa) << "\n";
    std::cout 
        << "-----\n"
        << "chunked: " << dchunked() << "\n"
        << "alloced: " << (dchunked() * NYANIX_CHUNK_SIZE) << "\n";

    dfree();
}
