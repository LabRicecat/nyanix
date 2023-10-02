#include "registers.hpp"

void regset() {
    dwrite(regs, NYANIX_REG_START);
    dwrite(rams, NYANIX_RAM_START);
    dwrite(deos, NYANIX_DEVICEOUT_START);
    dwrite(mems, NYANIX_MEMORY_START);
    dwrite(deis, NYANIX_DEVICEIN_START);
    dwrite(csts, NYANIX_CALLSTACK_START);
    dwrite(stks, NYANIX_STACK_START);

    dwrite(sp, NYANIX_STACK_START);
    dwrite(ss, 0);
    dwrite(csp, NYANIX_CALLSTACK_START);
    dwrite(css, 0);
}
