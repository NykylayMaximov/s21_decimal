#include "s21_decimal.h"

int s21_truncate(s21_decimal value, s21_decimal *result) {
    int sign = get_sign(value);
    int scale = get_scale(value);

    s21_decimal ten;
    s21_from_int_to_decimal(10, &ten);

    *result = value;

    while (scale != 0) {
        man_div(*result, ten, result);
        scale--;
    }

    set_sign(result, sign);

    return OK;
}

int s21_floor(s21_decimal value, s21_decimal *result) {
    int sign = get_sign(value);

    s21_decimal one;
    s21_from_int_to_decimal(1, &one);

    s21_truncate(value, result);

    if (sign == 1 && !s21_is_equal(value, *result))
        man_add(*result, one, result);

    set_sign(result, sign);

    return OK;
}

int s21_round(s21_decimal value, s21_decimal *result) {
    int sign = get_sign(value);
    int scale = get_scale(value);
    s21_decimal ten, one, rem = {0};
    s21_decimal value_copy = value;
    s21_from_int_to_decimal(10, &ten);
    s21_from_int_to_decimal(1, &one);
    s21_truncate(value, result);

    if (scale != 0)
        scale--;

    while (scale != 0) {
        man_div(value, ten, &value);
        scale--;
    }

    rem = man_div(value, ten, &value);

    if (rem.bits[0] >= 5 && !s21_is_equal(value_copy, *result))
        man_add(*result, one, result);
    
    set_sign(result, sign);

    return OK;
}

int s21_negate(s21_decimal value, s21_decimal *result) {
    *result = value;
    set_sign(result, !get_sign(value));
    return OK;
}

void bank_round(s21_decimal *value, int count) {
    int byte = value->bits[3];
    int scale = get_scale(*value) - count;
    while (count > 0) {
        s21_decimal ten, two, one, rem = {0}, rem_2 = {0};
        s21_from_int_to_decimal(10, &ten);
        s21_from_int_to_decimal(2, &two);
        s21_from_int_to_decimal(1, &one);
        rem = man_div(*value, ten, value);

        if (rem.bits[0] > 5)
            man_add(*value, one, value);
        else if (rem.bits[0] == 5)
            rem_2 = man_div(*value, two, NULL);
        
        if (man_is_equal(one, rem_2))
            man_add(*value, one, value);

        count++;
    }
    value->bits[3] = byte;
    set_scale(value, scale);
}