#include "s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    if (result == NULL)
        return NUM_LARGE;
    
    int scale_1 = get_scale(value_1);
    int scale_2 = get_scale(value_2);

    if (scale_1 > 28 || scale_1 < 0 || scale_2 > 28 || scale_2 < 0)
        return NUM_LARGE;

    int overflow = OK;

    normalize(&value_1, &value_2);
    int scale = get_scale(value_1);
    int sign_1 = get_sign(value_1);
    int sign_2 = get_sign(value_2);

    if (!(sign_1 ^ sign_2)) {
        overflow = man_add(value_1, value_2, result);
        set_sign(result, sign_1);
        if (overflow && sign_1 && sign_2)
            overflow = NUM_SMALL;
    } else if (man_is_less_or_equal(value_1, value_2)) {
        man_sub(value_2, value_1, result);
        set_sign(result, sign_2);
    } else {
        man_sub(value_1, value_2, result);
        set_sign(result, sign_1);
    }

    if (overflow && get_scale(value_1)) {
        bank_round(&value_1, 1);
        bank_round(&value_2, 1);
        overflow = s21_add(value_1, value_2, result);
    } else 
        set_scale(result, scale);

    return overflow;
}

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    int overflow = OK;
    set_sign(&value_2, !get_sign(value_2));
    overflow = s21_add(value_1, value_2, result);

    return overflow;
}

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    if (result == NULL)
        return NUM_LARGE;

    int scale_1 = get_scale(value_1);
    int scale_2 = get_scale(value_2);

    if (scale_1 > 28 || scale_1 < 0 || scale_2 > 28 || scale_2 < 0)
        return NUM_LARGE;
    
    int overflow = OK;
    int sign = get_sign(value_1) ^ get_sign(value_2);
    int scale = get_scale(value_1) + get_scale(value_2);

    s21_decimal zero = {0};
    s21_decimal ten, one;
    s21_from_int_to_decimal(10, &ten);
    s21_from_int_to_decimal(1, &one);

    if (s21_is_equal(value_1, zero) || s21_is_equal(value_2, zero)) {
        inintial_decimal(result);
        return overflow;
    }

    overflow = man_mul(value_1, value_2, result);

    while (overflow && scale > 0) {
        if (man_is_less_or_equal(value_2, value_1)) {
            bank_round(&value_1, 1);
            scale--;
        } else {
            bank_round(&value_2, 1);
            scale--;
        }

        overflow = man_mul(value_1, value_2, result);
    }

    if (scale > 28 || (overflow && sign))
        return NUM_SMALL;

    set_scale(result, scale);
    set_sign(result, sign);

    return overflow;
}

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    if (result == NULL)
        return NUM_LARGE;

    int scale_1 = get_scale(value_1);
    int scale_2 = get_scale(value_2);

    if (scale_1 > 28 || scale_1 < 0 || scale_2 > 28 || scale_2 < 0)
        return NUM_LARGE;

    s21_decimal zero = {0};

    if (s21_is_equal(value_2, zero))
        return DIV_ZERO;

    if (s21_is_equal(value_1, zero)) {
        inintial_decimal(result);
        return OK;
    }
    
    s21_decimal remainder = man_div(value_1, value_2, result);

    int scale = scale_1 - scale_2;
    int overflow = OK;
    s21_decimal ten;
    s21_from_int_to_decimal(10, &ten);

    while (scale < 0) {
        overflow = man_mul(*result, ten, result);
        scale++;
        if (overflow) {
            inintial_decimal(result);
            return NUM_LARGE;
        }
    }


    while (scale < 28 && !overflow && remainder.bits[0] != 0) {
        s21_decimal temp;
        man_mul(remainder, ten, &remainder);
        remainder = man_div(remainder, value_2, &temp);
        overflow = man_mul(*result, ten, result);
        man_add(*result, temp, result);
        if (!overflow)
            scale++;
    }

    set_scale(result, scale);

    return OK;
}
