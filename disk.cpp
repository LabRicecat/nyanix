#include "disk.hpp"

void dchunk(addr_t idx) {
    disk[idx] = new unit_t[NYANIX_CHUNK_SIZE];
}

unit_t* dread(addr_t addr) {
    if(disk[addr >> 1] == nullptr)
        dchunk((addr >> 1) / NYANIX_CHUNK_SIZE);
    
    return disk[addr >> 1];
}

void dwrite(addr_t addr, unit_t value) {
    *dread(addr) = value;
}
