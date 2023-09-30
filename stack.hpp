#ifndef NYANIX_STACK_HPP
#define NYANIX_STACK_HPP

#include "disk.hpp"
#include "registers.hpp"

void spush(addr_t addr);
void spop();
bool sempty();
unit_t ssize();

#endif
