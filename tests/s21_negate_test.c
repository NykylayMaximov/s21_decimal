#include "s21_decimal_test.h"

START_TEST(negate1) {
  s21_decimal a = {{0, 12345, 6789, 0}}, res = {{0, 12345, 6789, 2147483648}};
  s21_decimal negate_a = {0};

  s21_negate(a, &negate_a);
  ck_assert_int_eq(s21_is_equal(negate_a, res), 1);
}
END_TEST

START_TEST(s21_negate_1) {
  s21_decimal value_2 = {{0, 0, 1, 0x80000000}};
  s21_decimal value_1 = {{0, 0, 1, 0}};
  s21_decimal result = {0};
  int return_value = s21_negate(value_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(value_1, result), 1);
}
END_TEST

START_TEST(s21_negate_2) {
  s21_decimal value_2 = {{0, 0, 1, 0x80000000}};
  s21_decimal value_1 = {{0, 0, 1, 0}};
  s21_decimal result = {0};
  int return_value = s21_negate(value_1, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(result, value_2), 1);
}
END_TEST

START_TEST(s21_negate_3) {
  s21_decimal value_1 = {{5, 0xFFFFFFFF, 0, 0}};
  set_sign(&value_1, 1);
  s21_decimal check = {{5, 0xFFFFFFFF, 0, 0}};
  s21_decimal result;
  int return_value = s21_negate(value_1, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, OK);
}
END_TEST

START_TEST(s21_negate_4) {
  s21_decimal value_1 = {{1, 1, 1, 0}};
  s21_decimal check = {{1, 1, 1, 0x80000000}};
  s21_decimal result;
  int return_value = s21_negate(value_1, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, OK);
}
END_TEST

START_TEST(s21_negate_5) {
  float a = 10.1234e5;
  float res_a = 0;
  s21_decimal src;
  s21_from_float_to_decimal(a, &src);
  s21_decimal res;
  s21_negate(src, &res);
  s21_from_decimal_to_float(res, &res_a);
  ck_assert_float_eq(-10.1234e5, res_a);
}
END_TEST

Suite *suite_negate_test(void) {
  Suite *s = suite_create("\033[43m negate test\033[m");
  TCase *tc = tcase_create("negate test");

  tcase_add_test(tc, negate1);
  tcase_add_test(tc, s21_negate_1);
  tcase_add_test(tc, s21_negate_2);
  tcase_add_test(tc, s21_negate_3);
  tcase_add_test(tc, s21_negate_4);
  tcase_add_test(tc, s21_negate_5);

  suite_add_tcase(s, tc);

  return s;
}