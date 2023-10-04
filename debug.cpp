#include "debug.hpp"
#include "nxdf/nxdf.hpp"

#include <iostream>
#include <memory.h>

void diskinfo() {
    std::cout
    << "disk size: " << NYANIX_DISK_SIZE << "\n"
    << "register start: " << NYANIX_REG_START << "\n"
    << "register size:  " << NYANIX_REG_SIZE << "\n"
    << "RAM start: " << NYANIX_RAM_START << "\n"
    << "RAM size:  " << NYANIX_RAM_SIZE << "\n"
    << "device-out start: " << NYANIX_DEVICEOUT_START << "\n"
    << "device-out size:  " << NYANIX_DEVICEOUT_SIZE << "\n"
    << "memory start: " << NYANIX_MEMORY_START << "\n"
    << "memory size:  " << NYANIX_MEMORY_SIZE << "\n"
    << "device-in start: " << NYANIX_DEVICEIN_START << "\n"
    << "device-in size:  " << NYANIX_DEVICEIN_SIZE << "\n"
    << "callstack start: " << NYANIX_CALLSTACK_START << "\n"
    << "callstack size:  " << NYANIX_CALLSTACK_SIZE << "\n"
    << "stack start: " << NYANIX_STACK_START << "\n"
    << "stack size:  " << NYANIX_STACK_SIZE << "\n";
}

void load_prog(unit_t* prog, unit_t size) {
    for(addr_t i = 0; i < size; ++i)
        dwrite(NYANIX_MEMORY_START + i, prog[i]);
}

void memsnip(unit_t begin, unit_t size, int wrap) {
    for(unit_t i = 0; i < size; ++i) {
        if(i % wrap == 0) std::cout << "\n";
        std::cout << " " << *dread(begin + i);
    }
    std::cout << "\n";
}

void nxdf_display(nxdf* df) {
    char* magic = new char[4];
    nxdfs_t size = 0;
    memcpy(magic, df->file, 4);
    memcpy((char*)&size, df->file + 4, sizeof(nxdfs_t));

    std::cout 
        << "Magic: " 
            << (int)magic[0] << " " 
            << (int)magic[1] << " "
            << (int)magic[2] << " "
            << (int)magic[3] << "\n"
        << "Expected Magic: "
            << NYANIX_NXDF_MAGIC0 << " "
            << NYANIX_NXDF_MAGIC1 << " "
            << NYANIX_NXDF_MAGIC2 << " "
            << NYANIX_NXDF_MAGIC3 << "\n"
        << "Size: "
            << size << "\n"
        << "Expected Size: "
            << (dchunked() * NYANIX_CHUNK_SIZE * sizeof(unit_t)) << "\n"
        << "\n";

    const nxdfs_t offset = 4 + sizeof(nxdfs_t);
    df->file += offset;

    for(nxdfs_t i = 0; i < df->size - offset; ) {
        nxdfs_t chunks = 0;
        memcpy((char*)&chunks, df->file + i, sizeof(nxdfs_t));
        std::cout << "Chunk found at " << i << ": \n"
            << "Identification: " << chunks << "\n"
            << "Dump: ";

        for(nxdfs_t j = 0; j < NYANIX_CHUNK_SIZE; ++j) {
            if(j % 8 == 0) { 
                std::cout << "\n";
            }
            unit_t unit = unit;
            memcpy((char*)&unit, df->file + j * sizeof(unit_t), sizeof(unit_t));

            printf("%08x ",unit);
        }
        std::cout << "\n";


        i += NYANIX_CHUNK_SIZE * sizeof(unit_t) + sizeof(nxdfs_t);
    }
        

    df->file -= offset;

    delete[] magic;
}
