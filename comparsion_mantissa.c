#include "s21_decimal.h"

int man_is_less(s21_decimal value_1, s21_decimal value_2) {
    int less = FALSE;

    for (int i = 95; i >= 0; i--) {
        if (get_bit(value_1, i) ^ get_bit(value_2, i)) {
            less = get_bit(value_2, i);
            break;
        }
    }

    return less;
}

int man_is_equal(s21_decimal value_1, s21_decimal value_2) {
    int equal = TRUE;
    
    for (int i = 95; i >= 0; i--) {
        if (get_bit(value_1, i) != get_bit(value_2, i)) {
            equal = FALSE;
            break;
        }
    }

    return equal;
}

int man_is_less_or_equal(s21_decimal value_1, s21_decimal value_2) {
    return man_is_less(value_1, value_2) || man_is_equal(value_1, value_2);
}

int man_is_greater(s21_decimal value_1, s21_decimal value_2) {
    return !man_is_less_or_equal(value_1, value_2);
}

int man_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2) {
    return man_is_greater(value_1, value_2) || man_is_equal(value_1, value_2);
}

int man_is_not_equal(s21_decimal value_1, s21_decimal value_2) {
    return !man_is_equal(value_1, value_2);
}
