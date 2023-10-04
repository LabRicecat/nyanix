#include <iostream>

#include "instructions.hpp"
#include "disk.hpp"
#include "registers.hpp"
#include "cpu.hpp"
#include "display.hpp"
#include "keyboard.hpp"
#include "nxdf/nxdf.hpp"

#include "debug.hpp"

int main() {
    // diskinfo();
    regset();
    //nxdf df = nxdf_from_file("disk.nxdf");
    //nxdf_to_disk(df);

    unit_t prog[] = { 
        inst::put, 12, raa,  
        inst::hlt
    };
    load_prog(prog, sizeof(prog)/sizeof(unit_t));

    // disinit();
    regset();
    dwrite(ic, NYANIX_MEMORY_START);

    while(*dread(*dread(ic)) != inst::hlt)
        cpuexec(); // , keypoll();

    std::cout << *dread(raa) << "\n";
    std::cout << *dread(rab) << "\n";
    std::cout 
        << "-----\n"
        << "chunked: " << dchunked() << "\n"
        << "alloced: " << (dchunked() * NYANIX_CHUNK_SIZE) << "\n";

    memsnip(NYANIX_MEMORY_START, 40);
 
    diskinfo();

    // disquit();

    nxdf f = nxdf_from_disk();
    dfree();
    //nxdf_display(&f);
    nxdf_to_file(&f, "disk.nxdf");

    // delete[] f.file;
}
