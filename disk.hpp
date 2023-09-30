#ifndef NYANIX_DISK_HPP
#define NYANIX_DISK_HPP

#include "unit.hpp"
#include "address.hpp"

/*
 *
|------|-----|------------|--------|-----------|----|-------|
| REGs | RAM | DEVICE-OUT | MEMORY | DEVICE-IN | CS | STACK |
|------|-----|------------|--------|-----------|----|-------| 
 */

#define nxdiskpc(x) ((unit_t)(((x) / 100.0) * NYANIX_DISK_SIZE))     // disc percent
#define nxdiskafter(start, pcsize) ((start) + (pcsize)) 
#define nxdiskname(name, of, idx) inline const addr_t name = of + idx


#ifndef NYANIX_DISK_SIZE 
#define NYANIX_DISK_SIZE (unit_t(-1))
#endif

#ifndef NYANIX_REG_START
#define NYANIX_REG_START 0
#endif

#ifndef NYANIX_REG_SIZE 
#define NYANIX_REG_SIZE nxdiskpc(5)
#endif

#ifndef NYANIX_RAM_START
#define NYANIX_RAM_START nxdiskafter(NYANIX_REG_START, NYANIX_REG_SIZE)
#endif

#ifndef NYANIX_RAM_SIZE 
#define NYANIX_RAM_SIZE nxdiskpc(30)
#endif

#ifndef NYANIX_DEVICEOUT_START
#define NYANIX_DEVICEOUT_START nxdiskafter(NYANIX_RAM_START, NYANIX_RAM_SIZE)
#endif

#ifndef NYANIX_DEVICEOUT_SIZE
#define NYANIX_DEVICEOUT_SIZE nxdiskpc(10)
#endif

#ifndef NYANIX_MEMORY_START
#define NYANIX_MEMORY_START nxdiskafter(NYANIX_DEVICEOUT_START, NYANIX_DEVICEOUT_SIZE)
#endif

#ifndef NYANIX_MEMORY_SIZE
#define NYANIX_MEMORY_SIZE nxdiskpc(45)
#endif

#ifndef NYANIX_DEVICEIN_START
#define NYANIX_DEVICEIN_START nxdiskafter(NYANIX_MEMORY_START, NYANIX_MEMORY_SIZE)
#endif

#ifndef NYANIX_DEVICEIN_SIZE
#define NYANIX_DEVICEIN_SIZE nxdiskpc(5)
#endif

#ifndef NYANIX_CALLSTACK_START
#define NYANIX_CALLSTACK_START nxdiskafter(NYANIX_DEVICEIN_START, NYANIX_DEVICEIN_SIZE)
#endif

#ifndef NYANIX_CALLSTACK_SIZE
#define NYANIX_CALLSTACK_SIZE nxdiskpc(5)
#endif

#ifndef NYANIX_STACK_START
#define NYANIX_STACK_START nxdiskafter(NYANIX_CALLSTACK_START, NYANIX_CALLSTACK_SIZE)
#endif

#ifndef NYANIX_STACK_SIZE
#define NYANIX_STACK_SIZE nxdiskpc(5)
#endif

#ifndef NYANIX_CHUNK_SIZE
#define NYANIX_CHUNK_SIZE nxKU(4)
#endif

inline unit_t* disk[NYANIX_DISK_SIZE / NYANIX_CHUNK_SIZE] = {nullptr};

void dchunk(addr_t idx);
unit_t* dread(addr_t addr);
void dwrite(addr_t addr, unit_t value);
bool downed(addr_t addr);
void dfree();

unit_t dchunked();

#endif
