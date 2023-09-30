#include "disk.hpp"

void dchunk(addr_t idx) {
    disk[idx] = new unit_t[NYANIX_CHUNK_SIZE];
}

constexpr addr_t drem_owned(addr_t addr) {
    return (addr << 1) >> 1;
}

constexpr addr_t dto_chunk(addr_t addr) {
    return drem_owned(addr) / NYANIX_CHUNK_SIZE;
}

unit_t* dread(addr_t addr) {
    if(disk[dto_chunk(addr)] == nullptr)
        dchunk(dto_chunk(addr));
    
    return &disk[dto_chunk(addr)][drem_owned(addr) % NYANIX_CHUNK_SIZE];
}

void dwrite(addr_t addr, unit_t value) {
    *dread(addr) = value;
}

bool downed(addr_t addr) {
    return addr >> (addrsize-1);
}

void dfree() {
    for(addr_t i = 0; i < sizeof(disk)/sizeof(unit_t*); ++i)
        if(disk[i] != nullptr)
            delete[] disk[i], disk[i] = nullptr;
}

unit_t dchunked() {
    unit_t chunkedv = 0;
    for(addr_t i = 0; i < sizeof(disk)/sizeof(unit_t*); ++i) 
        if(disk[i] != nullptr)
            ++chunkedv;
    return chunkedv;
}
