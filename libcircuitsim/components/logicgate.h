#ifndef CIRSIMTEST_LOGICGATE_H
#define CIRSIMTEST_LOGICGATE_H

#if CIRCUITSIM_PRECISION <= 1
void or(bool a, bool b, bool* output) {
    nmos(&a);
    nmos(&b);
    *output = a | b;
}

void and(bool a, bool b, bool* output) {
    nmos(&a);
    nmos(&b);
    *output = a & b;
}

void not(bool* i) {
    pmos(i);
}

void nor(bool a, bool b, bool* output) {
    pmos(&a);
    pmos(&b);
    *output = a & b;
}

void nand(bool a, bool b, bool* output) {
    pmos(&a);
    pmos(&b);
    *output = a | b;
}

void xor(bool a, bool b, bool* output) {
    bool not_a = a;
    bool not_b = b;

    nmos(&a);
    nmos(&b);
    pmos(&not_a);
    pmos(&not_b);

    *output = (a&not_b) | (b&not_a);
}

void xnor(bool a, bool b, bool* output) {
    bool not_a = a;
    bool not_b = b;

    nmos(&a);
    nmos(&b);
    pmos(&not_a);
    pmos(&not_b);

    *output = (a&b) | (not_a & not_b);
}
#else
void or(bool a, bool b, bool* output) {
    *output = a | b;
}

void and(bool a, bool b, bool* output) {
    *output = a & b;
}

void not(bool* i) {
    *i = !*i;
}

void nor(bool a, bool b, bool* output) {
    *output = !(a|b);
}

void nand(bool a, bool b, bool* output) {
    *output = !(a&b);
}

void xor(bool a, bool b, bool* output) {
    *output = a != b;
}

void xnor(bool a, bool b, bool* output) {
    *output = a == b;
}
#endif

#endif //CIRSIMTEST_LOGICGATE_H
