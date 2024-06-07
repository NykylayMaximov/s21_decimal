#include "s21_decimal_test.h"

START_TEST(equal1) {
  s21_decimal a = {{101112, 12345, 6789, 0}}, b = {{101112, 12345, 6789, 0}};
  set_scale(&a, 5);
  set_scale(&b, 5);

  ck_assert_int_eq(s21_is_equal(a, b), 1);
}
END_TEST

START_TEST(equal2) {
  s21_decimal a = {{101112, 12345, 6789, 0}}, b = {{101112, 12345, 6789, 0}};
  set_scale(&a, 5);
  set_scale(&b, 6);

  ck_assert_int_eq(s21_is_equal(a, b), 0);
}
END_TEST

START_TEST(equal3) {
  s21_decimal a = {{101112, 12345, 6789, 0}}, b = {{101112, 12345, 6789, 0}};
  set_scale(&a, 5);
  set_scale(&b, 5);
  set_sign(&b, 1);

  ck_assert_int_eq(s21_is_equal(a, b), 0);
}
END_TEST

START_TEST(equal4) {
  s21_decimal a = {0}, b = {0};
  set_sign(&b, 1);

  ck_assert_int_eq(s21_is_equal(a, b), 1);
}
END_TEST

START_TEST(s21_is_equal_1) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  int return_value = s21_is_equal(value_1, value_2);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(s21_is_equal_2) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 1, 0}};
  int return_value = s21_is_equal(value_1, value_2);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_is_equal_3) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, 80000000}};
  int return_value = s21_is_equal(value_1, value_2);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(s21_is_equal_4) {
  s21_decimal value_1 = {{2, 0, 0, 0}};
  s21_decimal value_2 = {{20, 0, 0, 0x10000}};
  int return_value = s21_is_equal(value_1, value_2);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(s21_is_equal_5) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0x80000000}};
  int return_value = s21_is_equal(value_1, value_2);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(s21_is_equal_6) {
  s21_decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 80000000}};
  s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 80000000}};
  int return_value = s21_is_equal(value_1, value_2);
  ck_assert_int_eq(return_value, TRUE);
}
END_TEST

START_TEST(s21_is_equal_7) {
  s21_decimal value_1 = {{123453u, 654u, 0xFFFFFFFF, 80000000}};
  s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 80000000}};
  int return_value = s21_is_equal(value_1, value_2);
  ck_assert_int_eq(return_value, FALSE);
}
END_TEST

START_TEST(s21_is_equal_8) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0x80000000}};
  int return_value = s21_is_equal(value_1, value_2);
  ck_assert_int_eq(return_value, TRUE);
}
END_TEST

Suite *suite_equal_test(void) {
  Suite *s = suite_create("\033[44m equal test\033[m");
  TCase *tc = tcase_create("equal test");

  tcase_add_test(tc, equal1);
  tcase_add_test(tc, equal2);
  tcase_add_test(tc, equal3);
  tcase_add_test(tc, equal4);
  tcase_add_test(tc, s21_is_equal_1);
  tcase_add_test(tc, s21_is_equal_2);
  tcase_add_test(tc, s21_is_equal_3);
  tcase_add_test(tc, s21_is_equal_4);
  tcase_add_test(tc, s21_is_equal_5);
  tcase_add_test(tc, s21_is_equal_6);
  tcase_add_test(tc, s21_is_equal_7);
  tcase_add_test(tc, s21_is_equal_8);

  suite_add_tcase(s, tc);

  return s;
}