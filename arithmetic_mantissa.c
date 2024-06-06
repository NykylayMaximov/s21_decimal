#include "s21_decimal.h"

int man_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    inintial_decimal(result);
    int overflow = 0;

    for (int i = 0; i < 96; i++) {
        int bit_value1 = get_bit(value_1, i);
        int bit_value2 = get_bit(value_2, i);

        set_bit(result, i, bit_value1 ^ bit_value2 ^ overflow);

        overflow = (bit_value1 && bit_value2) || (bit_value1 && overflow) || (bit_value2 && overflow);
    }

    return overflow;
}

void man_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    inintial_decimal(result);

    for (int i = 0; i < 96; i++) {
        int bit_value1 = get_bit(value_1, i);
        int bit_value2 = get_bit(value_2, i);

        set_bit(result, i, bit_value1 ^ bit_value2);

        if (!bit_value1 && bit_value2) {
            int j = i + 1;

            while ((bit_value1 = get_bit(value_1, j)) != 1) {
                set_bit(&value_1, j++, 1);
            }

            set_bit(&value_1, j, 0);
        }
    }
}

int man_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    s21_decimal temp;
    inintial_decimal(&temp);
    int overflow = 0;

    for (int i = 0; i < 96 && !overflow; i++) {
        if (get_bit(value_2, i) == 1) {
            s21_decimal temp2 = value_1;
            int j = 0;
            while (j < i) {
                if (shift_left(&temp2)) {
                    overflow = 1;
                    break;
                }
                j++;
            }
            if (overflow || (overflow = man_add(temp2, temp, &temp)))
                break;
        }
    }

    if (!overflow) *result = temp;
    return overflow;
}

s21_decimal man_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    if (result) 
        inintial_decimal(result);

    s21_decimal remainder = {0};
    s21_decimal temp = {0};

    if (man_is_greater_or_equal(value_1, value_2)) {
        set_bit(&temp, 0, 1);

        while (1) {
            s21_decimal value_2_copy = value_2;
            while (man_is_greater_or_equal(value_1, value_2_copy) && !(get_bit(value_1, 95) && get_bit(value_2_copy, 95))) {
                shift_left(&value_2_copy);
                shift_left(&temp);
            }

            if (man_is_greater_or_equal(value_2_copy, value_1) || !(get_bit(value_1, 95) && get_bit(value_2_copy, 95))) {
                shift_right(&value_2_copy);
                shift_right(&temp);
            }

            man_sub(value_1, value_2_copy, &value_1);
            
            if (result)
                man_add(*result, temp, result);

            inintial_decimal(&temp);
            set_bit(&temp, 0, 1);

            if (man_is_less(value_1, value_2))
                break;
        }
    }
    remainder = value_1;
    return remainder;
}
