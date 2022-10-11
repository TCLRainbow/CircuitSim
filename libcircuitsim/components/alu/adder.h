#ifndef CIRCUITSIM_ADDER_H
#define CIRCUITSIM_ADDER_H

#include <stdio.h>
#include "../logicgate.h"

void half_adder(bool a, bool b, bool* sum, bool* carry) {
    xor(a, b, sum);
    and(a, b, carry);
}

void full_adder(bool a, bool b, bool cin, bool* sum, bool* cout) {
    bool x;

    half_adder(a, b, &x, &a);
    half_adder(x, cin, sum, &b);
    or(a, b, cout);
}

#if CIRCUITSIM_PRECISION <= 2
#include "util.h"
void add32(int a, int b, int* sum) {
    bool a_arr[32], b_arr[32], s_arr[32];
    int_to_bool_array(a, a_arr);
    int_to_bool_array(b, b_arr);

    bool c;
    half_adder(a_arr[0], b_arr[0], &s_arr[0], &c);
    for (int i = 1; i < 32; i++) {
        full_adder(a_arr[i], b_arr[i], c, &s_arr[i], &c);
    }

    *sum = bool_array_to_int(s_arr);
}
#else
void add32(int a, int b, int* sum) {
    *sum = a + b;
}
#endif

#endif //CIRCUITSIM_ADDER_H
