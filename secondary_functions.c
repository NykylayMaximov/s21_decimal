#include "s21_decimal.h"

int get_sign(s21_decimal value) {
    int sign;
    if ((value.bits[3] & (1 << 31)) == 0) {
        sign = 0;
    } else {
        sign = 1;
    }
    return sign;
}

void set_sign(s21_decimal *value, int sign) {
    if (sign == 0) {
        value->bits[3] = value->bits[3] & ~(1 << 31);
    } else {
        value->bits[3] = value->bits[3] | (1 << 31);
    }
}

int get_scale(s21_decimal value) {
    int shift = 16, scale = 0, i = 0;

    while (shift <= 23) {
        int bit = ((value.bits[3] & (1 << shift)) != 0);
        scale += bit * pow(2, i);
        shift++;
        i++;
    }
    return scale;
}

void set_scale(s21_decimal *value, int scale) {
    int shift = 16;

    while (shift <= 23) {
        if (scale > 0 && scale % 2 == 1) {
            value->bits[3] = value->bits[3] | (1 << shift);
        } else {
            value->bits[3] = value->bits[3] & ~(1 << shift);
        }
        scale /= 2;
        shift++;
    }
}

int get_bit(s21_decimal value, int position) {
    int sign;
    if ((value.bits[position / 32] & (1 << position % 32)) == 0) {
        sign = 0;
    } else {
        sign = 1;
    }
    return sign;
}

void set_bit(s21_decimal *value, int position, int bit) {
    if (bit == 0) {
        value->bits[position / 32] = value->bits[position / 32] & ~(1 << position % 32);
    } else {
        value->bits[position / 32] = value->bits[position / 32] | (1 << position % 32);
    }
}

void inintial_decimal(s21_decimal *value) {
    for (int i = 0; i < 128; i++)
        set_bit(value, i, 0);
}

int shift_left(s21_decimal *value) {
    int overflow = get_bit(*value, 95);

    for (int i = 95; i >= 0; i--) {
        if (i != 0)
            set_bit(value, i, get_bit(*value, i - 1));
        else
            set_bit(value, i, 0);
    }
    return overflow;
}

int shift_right(s21_decimal *value) {
    int overflow = get_bit(*value, 1);
    for (int i = 0; i < 96; i++) {
        if (i != 95)
            set_bit(value, i, get_bit(*value, i + 1));
        else
            set_bit(value, i, 0);
    }
    return overflow;
}

void normalize(s21_decimal *value_1, s21_decimal *value_2) {
    int scale_1 = get_scale(*value_1);
    int scale_2 = get_scale(*value_2);
    
    int byte_value_1 = value_1->bits[3];
    int byte_value_2 = value_2->bits[3];

    int min_scale = (scale_1 < scale_2) ? scale_1 : scale_2;
    int max_scale = (scale_1 > scale_2) ? scale_1 : scale_2;

    s21_decimal *min_value = (scale_1 < scale_2) ? value_1 : value_2;
    s21_decimal *max_value = (scale_1 > scale_2) ? value_1 : value_2;
    
    s21_decimal ten;
    s21_from_int_to_decimal(10, &ten);

    while (min_scale != max_scale) {
        if (min_scale < 28 && !man_mul(*min_value, ten, min_value)) {
            min_scale++;
            set_scale(min_value, min_scale);
        } else {
            bank_round(max_value, max_scale - min_scale);
            break;
        }
    }

    value_1->bits[3] = byte_value_1;
    value_2->bits[3] = byte_value_2;
    set_scale(min_value, min_scale);
    set_scale(max_value, min_scale);
}