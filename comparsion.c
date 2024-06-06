#include "s21_decimal.h"

int s21_is_less(s21_decimal value_1, s21_decimal value_2) {
    int less;
    int sign_1 = get_sign(value_1);
    int sign_2 = get_sign(value_2);

    if (!sign_1 && !sign_2) {
        normalize(&value_1, &value_2);
        less = man_is_less(value_1, value_2);
    } else if (sign_1 ^ sign_2) {
        less = (sign_1) ? TRUE : FALSE;
    } else {
        normalize(&value_1, &value_2);
        less = !man_is_less(value_1, value_2);        
    }

    return less;
}

int s21_is_equal(s21_decimal value_1, s21_decimal value_2) {
    int equal;
    int sign_1 = get_sign(value_1);
    int sign_2 = get_sign(value_2);
    s21_decimal zero;
    s21_from_int_to_decimal(0, &zero);

    if (sign_1 ^ sign_2) {
        equal = FALSE;
        if (man_is_equal(value_1, zero) && man_is_equal(value_2, zero))
            equal = TRUE;
    } else {
        normalize(&value_1, &value_2);
        equal = man_is_equal(value_1, value_2);         
    }

    return equal;
}

int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2) {
    return s21_is_less(value_1, value_2) || s21_is_equal(value_1, value_2);
}

int s21_is_greater(s21_decimal value_1, s21_decimal value_2) {
    return !s21_is_less_or_equal(value_1, value_2);
}

int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2) {
    return s21_is_greater(value_1, value_2) || s21_is_equal(value_1, value_2);
}

int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2) {
    return !s21_is_equal(value_1, value_2);
}
