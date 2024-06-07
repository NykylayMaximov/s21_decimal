#include "s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    if (result == NULL)
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
    
    int overflow = OK;
    int sign = get_sign(value_1) ^ get_sign(value_2);

    s21_decimal zero = {0};

    if (s21_is_equal(value_1, zero) || s21_is_equal(value_2, zero)) {
        inintial_decimal(result);
        return overflow;
    }

    if (s21_is_less(value_2, value_1)) {
        overflow = man_mul(value_1, value_2, result);
        if (overflow && get_scale(value_1)) {
            while (overflow) {
                bank_round(&value_1, 1);
                overflow = man_mul(value_1, value_2, result);
            }
        }
    }

    int scale = get_scale(value_1) + get_scale(value_2);
    if (scale > 28 || (overflow && sign))
        return NUM_SMALL;

    set_scale(result, scale);
    set_sign(result, sign);

    return overflow;
}

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    s21_decimal zero = {0};

    if (s21_is_equal(value_2, zero))
        return DIV_ZERO;
    
    man_div(value_1, value_2,result);

    return OK;
}
