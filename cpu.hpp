#ifndef NYANIX_CPU_HPP
#define NYANIX_CPU_HPP

#include "unit.hpp"
#include "address.hpp"
#include "disk.hpp"
#include "instructions.hpp"

bool validexec(unit_t ex);
addr_t cpuexec(addr_t ex);

#endif
