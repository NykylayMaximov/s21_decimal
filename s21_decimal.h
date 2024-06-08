#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>


enum errors {
    OK = 0,
    FALSE = 0,
    TRUE = 1,
    CONVERT_ERROR = 1,
    CALCULATION_ERROR = 1,
    NUM_LARGE = 1,
    NUM_SMALL = 2,
    DIV_ZERO = 3
};

typedef struct {
    unsigned int bits[4];
} s21_decimal;

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

int s21_is_less(s21_decimal value_1, s21_decimal value_2);
int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2);

int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

int get_sign(s21_decimal value);
void set_sign(s21_decimal *value, int sign);
int get_scale(s21_decimal value);
void set_scale(s21_decimal *value, int scale);
int get_bit(s21_decimal value, int position);
void set_bit(s21_decimal *value, int position, int bit);
int shift_left(s21_decimal *value);
int shift_right(s21_decimal *value);
void inintial_decimal(s21_decimal *value);
int man_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
void man_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int man_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
s21_decimal man_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int man_is_less(s21_decimal value_1, s21_decimal value_2);
int man_is_less_or_equal(s21_decimal value_1, s21_decimal value_2);
int man_is_greater(s21_decimal value_1, s21_decimal value_2);
int man_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2);
int man_is_equal(s21_decimal value_1, s21_decimal value_2);
int man_is_not_equal(s21_decimal value_1, s21_decimal value_2);
void bank_round(s21_decimal *value, int count);
void normalize(s21_decimal *value_1, s21_decimal *value_2);
void print_decimal_bin(s21_decimal value);

#endif
