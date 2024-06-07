#include "s21_decimal_test.h"

START_TEST(greater) {
  s21_decimal a = {{0, 12345, 6889, 101112}}, b = {{0, 12345, 6789, 101112}};
  set_scale(&a, 5);
  set_scale(&b, 5);

  ck_assert_int_eq(s21_is_greater(a, b), 1);
}
END_TEST

START_TEST(s21_is_greater_1) {
  s21_decimal value_1 = {{123, 1, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{12, 1, 0xFFFFFFFF, 0}};
  int return_value = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(s21_is_greater_2) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 1, 0}};
  int return_value = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_is_greater_3) {
  s21_decimal value_1 = {{12, 1, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{1, 1, 0xFFFFFFFF, 0}};
  int return_value = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(s21_is_greater_4) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0x80000000}};
  int return_value = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_is_greater_5) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  int return_value = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_is_greater_6) {
  s21_decimal value_1 = {{123456, 1, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{123456, 1, 0xFFFFFFFF, 0x10000}};
  int return_value = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(s21_is_greater_7) {
  s21_decimal value_1 = {{234, 0, 0, 0}};
  s21_decimal value_2 = {{2, 0, 0, 0}};
  int return_value = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(s21_is_greater_8) {
  s21_decimal value_1 = {{234, 0, 0, 0x80000000}};
  s21_decimal value_2 = {{2, 0, 0, 0x80000000}};
  int return_value = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_is_greater_9) {
  s21_decimal value_1 = {{234, 0, 0, 0x80000000}};
  s21_decimal value_2 = {{2, 0, 0, 0}};
  int return_value = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_is_greater_10) {
  s21_decimal value_1 = {{123457u, 654u, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  int return_value = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(return_value, TRUE);
}
END_TEST

START_TEST(s21_is_greater_11) {
  s21_decimal value_1 = {{123457u, 654u, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  set_sign(&value_1, 1);
  int return_value = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(return_value, FALSE);
}
END_TEST

START_TEST(s21_is_greater_12) {
  s21_decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{123457u, 654u, 0xFFFFFFFF, 0}};
  set_sign(&value_2, 1);
  int return_value = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(return_value, TRUE);
}
END_TEST

START_TEST(s21_is_greater_13) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  set_sign(&value_2, 1);
  int return_value = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(return_value, FALSE);
}
END_TEST

START_TEST(s21_is_greater_14) {
  s21_decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{123457u, 654u, 0xFFFFFFFF, 0}};
  set_sign(&value_1, 1);
  set_sign(&value_2, 1);
  int return_value = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(return_value, TRUE);
}
END_TEST

Suite *suite_greater_test(void) {
  Suite *s = suite_create("\033[44m greater test\033[m");
  TCase *tc = tcase_create("greater test");

  tcase_add_test(tc, greater);

  tcase_add_test(tc, s21_is_greater_1);
  tcase_add_test(tc, s21_is_greater_2);
  tcase_add_test(tc, s21_is_greater_3);
  tcase_add_test(tc, s21_is_greater_4);
  tcase_add_test(tc, s21_is_greater_5);
  tcase_add_test(tc, s21_is_greater_6);
  tcase_add_test(tc, s21_is_greater_7);
  tcase_add_test(tc, s21_is_greater_8);
  tcase_add_test(tc, s21_is_greater_9);
  tcase_add_test(tc, s21_is_greater_10);
  tcase_add_test(tc, s21_is_greater_11);
  tcase_add_test(tc, s21_is_greater_12);
  tcase_add_test(tc, s21_is_greater_13);
  tcase_add_test(tc, s21_is_greater_14);

  suite_add_tcase(s, tc);

  return s;
}