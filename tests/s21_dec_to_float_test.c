#include "s21_decimal_test.h"

START_TEST(dec_to_float1) {
  s21_decimal a = {{5, 0, 0, 2147483648}};
  float dec_to_float_a = 0;

  s21_from_decimal_to_float(a, &dec_to_float_a);
  ck_assert_float_eq(dec_to_float_a, -5.0);
}
END_TEST

START_TEST(dec_to_float2) {
  s21_decimal a = {{13, 0, 0, 0}};
  float dec_to_float_a = 0;

  s21_from_decimal_to_float(a, &dec_to_float_a);
  ck_assert_float_eq(dec_to_float_a, 13.0);
}
END_TEST

START_TEST(s21_from_decimal_to_float_1) {
  float src = 0.00000000000;
  float temp = 0;
  int return_value = 0;
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_from_decimal_to_float(value_1, &temp);
  if (fabs(src - temp) < pow(10, -7)) {
    return_value = 1;
  }
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(s21_from_decimal_to_float_2) {
  float src = 0.01;
  float temp = 0;
  s21_decimal value_1 = {{1, 0, 0, 0b00000000000000100000000000000000}};
  s21_from_decimal_to_float(value_1, &temp);
  ck_assert_float_eq_tol(src, temp, 10e-7);
}
END_TEST

START_TEST(s21_from_decimal_to_float_3) {
  float src = 0.00000123;
  float temp = 0;
  s21_decimal value_1 = {{123, 0, 0, 0b00000000000010000000000000000000}};
  s21_from_decimal_to_float(value_1, &temp);
  ck_assert_float_eq_tol(src, temp, 10e-7);
}
END_TEST

START_TEST(s21_from_decimal_to_float_4) {
  float src = -0.01;
  float temp = 0;
  s21_decimal value_1 = {{1, 0, 0, 0x80020000}};
  s21_from_decimal_to_float(value_1, &temp);
  ck_assert_float_eq_tol(src, temp, 10e-7);
}
END_TEST

START_TEST(s21_from_decimal_to_float_5) {
  s21_decimal value = {{1812, 0, 0, 0}};
  set_sign(&value, 1);
  float result;
  float check = -1812;
  int return_value = s21_from_decimal_to_float(value, &result);
  ck_assert_float_eq(result, check);
  ck_assert_int_eq(return_value, SUCCESS);
}
END_TEST

START_TEST(s21_from_decimal_to_float_7) {
  s21_decimal value = {{0xFFFFFF, 0, 0, 0}};
  float result;
  float check = 16777215;
  int return_value = s21_from_decimal_to_float(value, &result);
  ck_assert_float_eq(result, check);
  ck_assert_int_eq(return_value, SUCCESS);
}
END_TEST

START_TEST(s21_from_decimal_to_float_8) {
  s21_decimal value = {{0xFFFFFFFF, 0xFFFFFFFF, 0, 0}};
  float result;
  float check = 0xFFFFFFFFFFFFFFFF;
  int return_value = s21_from_decimal_to_float(value, &result);
  ck_assert_float_eq(result, check);
  ck_assert_int_eq(return_value, SUCCESS);
}
END_TEST

START_TEST(s21_from_decimal_to_float_9) {
  s21_decimal src;
  int result = 0;
  float number = 0.0;
  src.bits[0] = 23450987;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = 2147745792;
  result = s21_from_decimal_to_float(src, &number);
  ck_assert_float_eq(number, -2345.0987);
  ck_assert_int_eq(result, 0);
}
END_TEST

Suite *suite_dec_to_float_test(void) {
  Suite *s = suite_create("\033[45m dec to float test\033[m");
  TCase *tc = tcase_create("dec to float test");

  tcase_add_test(tc, dec_to_float1);
  tcase_add_test(tc, dec_to_float2);

  tcase_add_test(tc, s21_from_decimal_to_float_1);
  tcase_add_test(tc, s21_from_decimal_to_float_2);
  tcase_add_test(tc, s21_from_decimal_to_float_3);
  tcase_add_test(tc, s21_from_decimal_to_float_4);
  tcase_add_test(tc, s21_from_decimal_to_float_5);
  tcase_add_test(tc, s21_from_decimal_to_float_7);
  tcase_add_test(tc, s21_from_decimal_to_float_8);
  tcase_add_test(tc, s21_from_decimal_to_float_9);

  suite_add_tcase(s, tc);

  return s;
}