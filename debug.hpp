#ifndef NYANIX_DEBUG_HPP
#define NYANIX_DEBUG_HPP

#include "instructions.hpp"
#include "disk.hpp"
#include "registers.hpp"
#include "cpu.hpp"

#include <iostream>

inline void diskinfo() {
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

inline void load_prog(unit_t* prog, unit_t size) {
    for(addr_t i = 0; i < size; ++i)
        dwrite(NYANIX_MEMORY_START + i, prog[i]);
}

inline void memsnip(unit_t begin, unit_t size, int wrap = 10) {
    for(unit_t i = 0; i < size; ++i) {
        if(i % wrap == 0) std::cout << "\n";
        std::cout << " " << *dread(begin + i);
    }
    std::cout << "\n";
}

#endif
