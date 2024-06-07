#include "s21_decimal.h"
#include <string.h>

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
    inintial_decimal(dst);
    dst->bits[0] = (src >= 0) ? src : -src;
    set_sign(dst, src < 0);
    return OK;
}

int count_str_float(float number, char *str) {
    int count = 0, k = 1;
    char buffer[100];

    snprintf(buffer, sizeof(buffer), "%f", number);

    for (int i = strlen(buffer) - 1; i >= 0; i--) {
        if (buffer[i] == '0' && k == 1) {
            buffer[i] = '\0';
            continue;
        } else
            k = 0;

        if (buffer[i] == '.')
            break;
        
        count++;
    }

    strncpy(str, buffer, strlen(buffer) + 1);

    return count;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
    if (dst == NULL)
        return CONVERT_ERROR;

    inintial_decimal(dst);
    
    if (0 < fabsf(src) && fabsf(src) < 1e-28)
        return CONVERT_ERROR;

    char buffer[100];
    int count_str = count_str_float(src, buffer);
    int overflow = 0;

    s21_decimal ten;
    s21_from_int_to_decimal(10, &ten);

    for (size_t i = 0; i < strlen(buffer); i++) {
        if (buffer[i] != '.' && buffer[i] != '-') {
            s21_decimal num;
            s21_from_int_to_decimal(buffer[i] - '0', &num);
            man_add(*dst, num, dst);
            overflow = man_mul(*dst, ten, dst);
        }
    }

    if (!overflow)
        man_div(*dst, ten, dst);

    set_sign(dst, src < 0);
    set_scale(dst, count_str);

    return OK;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
    if (dst == NULL || src.bits[1] != 0 || src.bits[2] != 0)
        return CONVERT_ERROR;
        
    int scale = get_scale(src);
    int sign = (get_sign(src)) ? -1 : 1;
    s21_decimal ten;
    s21_from_int_to_decimal(10, &ten);

    while (scale > 0) {
        man_div(src, ten, &src);
        scale--;
    }

    set_bit(&src, 31, 0);
    *dst = src.bits[0];
    *dst *= sign;

    return OK;
}

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
    if (dst == NULL)
        return CONVERT_ERROR;

    int sign = get_sign(src);
    int scale = get_scale(src);

    double res = 0;
    int bit;

    for (int i = 0; i < 96; i++) {
        bit = get_bit(src, i);
        res += bit * pow(2, i);
    }

    *dst = res / pow(10, scale);

    if (sign == 1)
        *dst *= -1;
    
    return OK;
}
