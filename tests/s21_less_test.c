#include "s21_decimal_test.h"

START_TEST(less1) {
  s21_decimal a = {{101112, 12345, 6789, 0}}, b = {{101112, 12345, 6789, 0}};
  set_scale(&a, 5);
  set_scale(&b, 5);

  ck_assert_int_eq(s21_is_less(a, b), 0);
}
END_TEST

START_TEST(less2) {
  s21_decimal a = {{101112, 12345, 6789, 0}}, b = {{101112, 12345, 6789, 0}};
  set_scale(&a, 5);
  set_scale(&b, 6);

  ck_assert_int_eq(s21_is_less(a, b), 0);
}
END_TEST

START_TEST(less3) {
  s21_decimal a = {{101112, 12345, 6789, 0}}, b = {{101112, 12345, 6789, 0}};
  set_scale(&a, 5);
  set_scale(&b, 5);
  set_sign(&b, 1);

  ck_assert_int_eq(s21_is_less(a, b), 0);
}
END_TEST

START_TEST(less4) {
  s21_decimal a = {{0, 12345, 6789, 101113}}, b = {{0, 12345, 6789, 101112}};
  set_scale(&a, 5);
  set_scale(&b, 5);
  set_sign(&a, 1);
  set_sign(&b, 1);

  ck_assert_int_eq(s21_is_less(a, b), 1);
}
END_TEST

START_TEST(less5) {
  s21_decimal a = {{123455, 123455, 123455, 0}},
              b = {{123455, 123455, 123455, 123455}};
  set_scale(&a, 0);
  set_scale(&b, 28);

  ck_assert_int_eq(s21_is_less(a, b), 0);
}
END_TEST

START_TEST(s21_is_less_1) {
  s21_decimal value_1 = {{123457u, 654u, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  int return_value = s21_is_less(value_1, value_2);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_is_less_2) {
  s21_decimal value_1 = {{123457u, 654u, 0xFFFFFFFF, 0x80000000}};
  s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  int return_value = s21_is_less(value_1, value_2);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(s21_is_less_3) {
  s21_decimal value_1 = {{12345, 654, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{12, 654, 0xFFFFFFFF, 0}};
  int return_value = s21_is_less(value_1, value_2);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_is_less_4) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  int return_value = s21_is_less(value_1, value_2);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_is_less_5) {
  s21_decimal value_1 = {{123456, 6, 0xFFFFFFFF, 0x80000000}};
  s21_decimal value_2 = {{123, 6, 0xFFFFFFFF, 0x80000000}};
  int return_value = s21_is_less(value_1, value_2);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(s21_is_less_6) {
  s21_decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 3454334633}};
  int return_value = s21_is_less(value_1, value_2);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_is_less_7) {
  s21_decimal value_1 = {{123456, 6, 0xFFFFFFFF, 0x80000000}};
  s21_decimal value_2 = {{123456, 6, 0xFFFFFFFF, 0}};
  int return_value = s21_is_less(value_1, value_2);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(s21_is_less_8) {
  s21_decimal value_1 = {{123457u, 654u, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  int return_value = s21_is_less(value_1, value_2);
  ck_assert_int_eq(return_value, FALSE);
}
END_TEST

START_TEST(s21_is_less_9) {
  s21_decimal value_1 = {{123457u, 654u, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  set_sign(&value_1, 1);
  int return_value = s21_is_less(value_1, value_2);
  ck_assert_int_eq(return_value, TRUE);
}
END_TEST

START_TEST(s21_is_less_10) {
  s21_decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{123457u, 654u, 0xFFFFFFFF, 0}};
  set_sign(&value_2, 1);
  int return_value = s21_is_less(value_1, value_2);
  ck_assert_int_eq(return_value, FALSE);
}
END_TEST

START_TEST(s21_is_less_11) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  set_sign(&value_2, 1);
  int return_value = s21_is_less(value_1, value_2);
  ck_assert_int_eq(return_value, FALSE);
}
END_TEST

START_TEST(s21_is_less_12) {
  s21_decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{123457u, 654u, 0xFFFFFFFF, 0}};
  set_sign(&value_1, 1);
  set_sign(&value_2, 1);
  int return_value = s21_is_less(value_1, value_2);
  ck_assert_int_eq(return_value, FALSE);
}
END_TEST

Suite *suite_less_test(void) {
  Suite *s = suite_create("\033[44m less test\033[m");
  TCase *tc = tcase_create("less test");

  tcase_add_test(tc, less1);
  tcase_add_test(tc, less2);
  tcase_add_test(tc, less3);
  tcase_add_test(tc, less4);
  tcase_add_test(tc, less5);

  tcase_add_test(tc, s21_is_less_1);
  tcase_add_test(tc, s21_is_less_2);
  tcase_add_test(tc, s21_is_less_3);
  tcase_add_test(tc, s21_is_less_4);
  tcase_add_test(tc, s21_is_less_5);
  tcase_add_test(tc, s21_is_less_6);
  tcase_add_test(tc, s21_is_less_7);
  tcase_add_test(tc, s21_is_less_8);
  tcase_add_test(tc, s21_is_less_9);
  tcase_add_test(tc, s21_is_less_10);
  tcase_add_test(tc, s21_is_less_11);
  tcase_add_test(tc, s21_is_less_12);

  suite_add_tcase(s, tc);

  return s;
}