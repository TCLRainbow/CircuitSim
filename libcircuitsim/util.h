//
// Created by wongc on 11/10/2022.
//

#ifndef CIRCUITSIM_UTIL_H
#define CIRCUITSIM_UTIL_H

bool extract_bit(int value, int pos) {
    return (value >> pos) & 1;
}

void set_bit(int* value, int pos, bool bit) {
    *value += bit << pos;
}

void int_to_bool_array(int value, bool* arr) {
    for (int i = 0; i < 32; i++) {
        arr[i] = extract_bit(value, i);
    }
}

int bool_array_to_int(bool* arr) {
    int value = 0;
    for (int i = 0; i < 32; i++) {
        set_bit(&value, i, arr[i]);
    }
    return value;
}

#endif //CIRCUITSIM_UTIL_H
