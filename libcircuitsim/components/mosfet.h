#ifndef CIRCUITSIM_MOSFET_H
#define CIRCUITSIM_MOSFET_H

#include <stdbool.h>

typedef struct {
    const bool source;
    bool gate;
    bool drain;
} MOS;

#if CIRCUITSIM_PRECISION == 0
void nmos(bool* i) {
    MOS mos = {.source = 1, .gate = *i};
    mos.drain = mos.gate ? 1 : 0;

    *i = mos.drain;
}

void pmos(bool* i) {
    MOS mos = {.source = 1, .gate = *i};
    mos.drain = mos.gate ? 0 : 1;

    *i = mos.drain;
}
#else
void nmos(bool* i) {}

void pmos(bool* i) {
    *i = !*i;
}
#endif

#endif //CIRCUITSIM_MOSFET_H
