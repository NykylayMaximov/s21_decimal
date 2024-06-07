#ifndef SRC_TESTS_S21_DECIMAL_TEST_H_
#define SRC_TESTS_S21_DECIMAL_TEST_H_

#include <check.h>
#include <math.h>
#include <time.h>

#include "../s21_decimal.h"
#define CONVERTING_ERROR 1
#define OK 0
#define SIGN 0x80000000
#define TRUE 1
#define FALSE 0
#define INF 1
#define NINF 2
#define NAN12 3
#define SUCCESS 0

Suite *suite_add_test(void);
Suite *suite_sub_test(void);
Suite *suite_mul_test(void);
Suite *suite_div_test(void);

Suite *suite_less_test(void);
Suite *suite_less_or_equal_test(void);
Suite *suite_greater_test(void);
Suite *suite_greater_or_equal_test(void);
Suite *suite_equal_test(void);
Suite *suite_not_equal_test(void);

Suite *suite_int_to_dec_test(void);
Suite *suite_float_to_dec_test(void);
Suite *suite_dec_to_int_test(void);
Suite *suite_dec_to_float_test(void);

Suite *suite_floor_test(void);
Suite *suite_round_test(void);
Suite *suite_truncate_test(void);
Suite *suite_negate_test(void);

#endif
