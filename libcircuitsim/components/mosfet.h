#ifndef CIRCUITSIM_MOSFET_H
#define CIRCUITSIM_MOSFET_H

#include <stdbool.h>

typedef struct {
    const bool source;
    bool gate;
    bool drain;
} MOS;

#if CIRCUITSIM_PRECISION == 0
bool nmos(bool* i) {
    MOS mos = {.source = 1, .gate = *i};
    mos.drain = mos.gate ? 1 : 0;

    *i = mos.drain;
    return mos.drain;
}

bool pmos(bool* i) {
    MOS mos = {.source = 1, .gate = *i};
    mos.drain = mos.gate ? 0 : 1;

    *i = mos.drain;
    return mos.drain;
}
#else
bool nmos(const bool* i) {
    return *i;
}

bool pmos(bool* i) {
    *i = !*i;
    return *i;
}
#endif

#endif //CIRCUITSIM_MOSFET_H
