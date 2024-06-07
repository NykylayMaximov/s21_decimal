#include "s21_decimal_test.h"

START_TEST(dec_to_int) {
  s21_decimal a = {{123, 0, 0, 0}};
  set_scale(&a, 1);
  int int_a;

  s21_from_decimal_to_int(a, &int_a);
  ck_assert_int_eq(int_a, 12);
}
END_TEST

START_TEST(s21_from_decimal_to_int_1) {
  int temp = 0;
  int return_value = 0;
  s21_decimal value_1 = {{0, 0, 1, 0}};
  return_value = s21_from_decimal_to_int(value_1, &temp);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(s21_from_decimal_to_int_2) {
  int src = 0;
  int temp = 100;
  int return_value = 0;
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_from_decimal_to_int(value_1, &temp);
  return_value = (src == temp);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(s21_from_decimal_to_int_3) {
  int src = 0;
  int temp = 0;
  int return_value = 0;
  s21_decimal value_1 = {{0x80000000, 0, 0, 0}};
  s21_from_decimal_to_int(value_1, &temp);
  return_value = (src == temp);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(s21_from_decimal_to_int_4) {
  int src = 133;
  int temp = 0;
  int return_value = 0;
  s21_decimal value_1 = {{0x85, 0, 0, 0}};
  s21_from_decimal_to_int(value_1, &temp);
  return_value = (src == temp);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(s21_from_decimal_to_int_7) {
  s21_decimal value = {{2, 3, 0, 0}};
  int array = 0;
  int check = 0;
  int return_value = s21_from_decimal_to_int(value, &array);
  ck_assert_int_eq(array, check);
  ck_assert_int_eq(return_value, CONVERTING_ERROR);
}
END_TEST

Suite *suite_dec_to_int_test(void) {
  Suite *s = suite_create("\033[45m dec to int test\033[m");
  TCase *tc = tcase_create("dec to int test");

  tcase_add_test(tc, dec_to_int);
  tcase_add_test(tc, s21_from_decimal_to_int_1);
  tcase_add_test(tc, s21_from_decimal_to_int_2);
  tcase_add_test(tc, s21_from_decimal_to_int_3);
  tcase_add_test(tc, s21_from_decimal_to_int_4);
  tcase_add_test(tc, s21_from_decimal_to_int_7);

  suite_add_tcase(s, tc);

  return s;
}