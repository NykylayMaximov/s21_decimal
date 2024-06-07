#include "s21_decimal_test.h"

START_TEST(not_equal) {
  s21_decimal a = {{0, 12346, 12, 101113}}, b = {{0, 12345, 6789, 101112}};
  set_scale(&a, 5);
  set_scale(&b, 5);
  set_sign(&a, 1);
  set_sign(&b, 1);

  ck_assert_int_eq(s21_is_not_equal(a, b), 1);
}
END_TEST

START_TEST(s21_is_not_equal_1) {
  s21_decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 80000000}};
  s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 80000000}};
  int return_value = s21_is_not_equal(value_1, value_2);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_is_not_equal_2) {
  s21_decimal value_1 = {{123453u, 654u, 0xFFFFFFFF, 80000000}};
  s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 80000000}};
  int return_value = s21_is_not_equal(value_1, value_2);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(s21_is_not_equal_3) {
  s21_decimal value_1 = {{0, 0, 0, 80000000}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  int return_value = s21_is_not_equal(value_1, value_2);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_is_not_equal_4) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0x80000000}};
  int return_value = s21_is_not_equal(value_1, value_2);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_is_not_equal_5) {
  s21_decimal value_1 = {{0, 0, 0, 0x80000000}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  int return_value = s21_is_not_equal(value_1, value_2);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_is_not_equal_6) {
  s21_decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 80000000}};
  s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 80000000}};
  int return_value = s21_is_not_equal(value_1, value_2);
  ck_assert_int_eq(return_value, FALSE);
}
END_TEST

START_TEST(s21_is_not_equal_7) {
  s21_decimal value_1 = {{123453u, 654u, 0xFFFFFFFF, 80000000}};
  s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 80000000}};
  int return_value = s21_is_not_equal(value_1, value_2);
  ck_assert_int_eq(return_value, TRUE);
}
END_TEST

START_TEST(s21_is_not_equal_8) {
  s21_decimal value_1 = {{0, 0, 0, 80000000}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  int return_value = s21_is_not_equal(value_1, value_2);
  ck_assert_int_eq(return_value, FALSE);
}
END_TEST

Suite *suite_not_equal_test(void) {
  Suite *s = suite_create("\033[44m not equal test\033[m");
  TCase *tc = tcase_create("not equal test");

  tcase_add_test(tc, not_equal);
  tcase_add_test(tc, s21_is_not_equal_1);
  tcase_add_test(tc, s21_is_not_equal_2);
  tcase_add_test(tc, s21_is_not_equal_3);
  tcase_add_test(tc, s21_is_not_equal_4);
  tcase_add_test(tc, s21_is_not_equal_5);
  tcase_add_test(tc, s21_is_not_equal_6);
  tcase_add_test(tc, s21_is_not_equal_7);
  tcase_add_test(tc, s21_is_not_equal_8);

  suite_add_tcase(s, tc);

  return s;
}