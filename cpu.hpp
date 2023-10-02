#ifndef NYANIX_CPU_HPP
#define NYANIX_CPU_HPP

#include "unit.hpp"
#include "address.hpp"
#include "disk.hpp"
#include "instructions.hpp"
#include "stack.hpp"
#include "syscall.hpp"

bool validexec(unit_t ex);
void cpuexec();

#endif
