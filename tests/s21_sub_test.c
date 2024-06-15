#include "s21_decimal_test.h"

START_TEST(sub1) {
  s21_decimal a = {{123, 0, 0, 0}}, b = {{456, 0, 0, 0}}, c = {{579, 0, 0, 0}},
              res;
  set_scale(&a, 5);
  set_scale(&b, 5);
  set_scale(&c, 5);
  set_sign(&b, 1);

  s21_sub(a, b, &res);
  ck_assert_int_eq(s21_is_equal(res, c), 1);
}
END_TEST

START_TEST(s21_sub_1) {
  s21_decimal value_1 = {{0, 0, 0, 0x80000000}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  s21_decimal result = {0};
  int return_value = s21_sub(value_1, value_2, &result), x = 0;
  s21_from_decimal_to_int(result, &x);
  ck_assert_int_eq(x, 0);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_sub_2) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal result = {0};
  int return_value = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(
      result.bits[0] + result.bits[1] + result.bits[2] + result.bits[3], 0);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_sub_3) {
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal value_1 = {{1, 1, 1, 0}};
  s21_decimal result = {0};
  int return_value = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(return_value, 0);
  for (int i = 0; i < 3; i++) ck_assert_int_eq(result.bits[i], 0xFFFFFFFF - 1);
}
END_TEST

START_TEST(s21_sub_4) {
  s21_decimal value_1 = {{10, 0, 0, 0}};
  s21_decimal value_2 = {{2147483638, 0, 0, 0}};
  s21_decimal result = {{2147483628, 0, 0, 0}};
  set_sign(&result, 1);
  int return_value = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(result.bits[0], 2147483628);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0x80000000);
}
END_TEST

START_TEST(s21_sub_5) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal result = {0};
  int return_value = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(result.bits[0] + result.bits[1] + result.bits[2], 0);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_sub_7) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal value_2 = {{1, 1, 1, 0}};
  s21_decimal result = {0};
  int return_value = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(return_value, 2);
}
END_TEST

START_TEST(s21_sub_10) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  set_sign(&value_1, 1);
  s21_decimal value_2 = {{2, 0, 0, 0}};
  s21_decimal result;
  s21_decimal check = {{0, 0, 0, 0}};
  int return_value = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
  ck_assert_int_eq(return_value, NINF);
}
END_TEST

START_TEST(s21_sub_13) {
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_decimal res = {0};
  s21_from_int_to_decimal(100, &a);
  s21_from_int_to_decimal(50, &b);
  int err = s21_sub(a, b, &res);
  int int_res = 0;
  s21_from_decimal_to_int(res, &int_res);
  ck_assert_int_eq(int_res, 50);
  ck_assert_int_eq(err, 0);
}
END_TEST

START_TEST(s21_sub_14) {
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_decimal res = {0};
  s21_from_int_to_decimal(-100, &a);
  s21_from_int_to_decimal(50, &b);
  int err = s21_sub(a, b, &res);
  int int_res = 0;
  s21_from_decimal_to_int(res, &int_res);
  ck_assert_int_eq(int_res, -150);
  ck_assert_int_eq(err, 0);
}
END_TEST

START_TEST(s21_sub_15) {
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_decimal res = {0};
  s21_from_int_to_decimal(-100, &a);
  s21_from_int_to_decimal(-50, &b);
  int err = s21_sub(a, b, &res);
  int int_res = 0;
  s21_from_decimal_to_int(res, &int_res);
  ck_assert_int_eq(int_res, -50);
  ck_assert_int_eq(err, 0);
}
END_TEST

START_TEST(s21_sub_16) {
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_decimal res = {0};
  s21_from_int_to_decimal(100, &a);
  s21_from_int_to_decimal(-50, &b);
  int err = s21_sub(a, b, &res);
  int int_res = 0;
  s21_from_decimal_to_int(res, &int_res);
  ck_assert_int_eq(int_res, 150);
  ck_assert_int_eq(err, 0);
}
END_TEST

START_TEST(s21_sub_17) {
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_decimal res = {0};
  s21_from_int_to_decimal(100, &a);
  s21_from_int_to_decimal(500, &b);
  int err = s21_sub(a, b, &res);
  int int_res = 0;
  s21_from_decimal_to_int(res, &int_res);
  ck_assert_int_eq(int_res, -400);
  ck_assert_int_eq(err, 0);
}
END_TEST

START_TEST(s21_sub_18) {
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_decimal res = {0};
  s21_from_int_to_decimal(-100, &a);
  s21_from_int_to_decimal(-500, &b);
  int err = s21_sub(a, b, &res);
  int int_res = 0;
  s21_from_decimal_to_int(res, &int_res);
  ck_assert_int_eq(int_res, 400);
  ck_assert_int_eq(err, 0);
}
END_TEST

START_TEST(s21_sub_19) {
  s21_decimal dec1 = {0};
  s21_decimal dec2 = {0};
  s21_decimal ans;
  dec1.bits[0] = 532167;
  dec1.bits[3] = 196608;

  dec2.bits[0] = 1236;
  dec2.bits[3] = 983040;

  s21_decimal true_ans = {0};
  true_ans.bits[0] = 607087404;
  true_ans.bits[1] = 123904785;
  true_ans.bits[3] = 983040;
  int res = s21_sub(dec1, dec2, &ans);
  ck_assert_int_eq(ans.bits[0], true_ans.bits[0]);
  ck_assert_int_eq(ans.bits[1], true_ans.bits[1]);
  ck_assert_int_eq(ans.bits[2], true_ans.bits[2]);
  ck_assert_int_eq(ans.bits[3], true_ans.bits[3]);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_sub_20) {
  s21_decimal dec1 = {0};
  s21_decimal dec2 = {0};
  s21_decimal ans;
  dec1.bits[0] = 532167;
  dec1.bits[3] = 196608;

  s21_decimal true_ans = {0};
  true_ans.bits[0] = 532167;
  true_ans.bits[3] = 196608;
  int res = s21_sub(dec1, dec2, &ans);
  ck_assert_int_eq(ans.bits[0], true_ans.bits[0]);
  ck_assert_int_eq(ans.bits[1], true_ans.bits[1]);
  ck_assert_int_eq(ans.bits[2], true_ans.bits[2]);
  ck_assert_int_eq(ans.bits[3], true_ans.bits[3]);
  ck_assert_int_eq(res, 0);
}
END_TEST

Suite *suite_sub_test(void) {
  Suite *s = suite_create("\033[42m sub test\033[m");
  TCase *tc = tcase_create("sub test");

  tcase_add_test(tc, sub1);
  tcase_add_test(tc, s21_sub_1);
  tcase_add_test(tc, s21_sub_2);
  tcase_add_test(tc, s21_sub_3);
  tcase_add_test(tc, s21_sub_4);
  tcase_add_test(tc, s21_sub_5);
  tcase_add_test(tc, s21_sub_7);
  tcase_add_test(tc, s21_sub_10);
  tcase_add_test(tc, s21_sub_13);
  tcase_add_test(tc, s21_sub_14);
  tcase_add_test(tc, s21_sub_15);
  tcase_add_test(tc, s21_sub_16);
  tcase_add_test(tc, s21_sub_17);
  tcase_add_test(tc, s21_sub_18);
  tcase_add_test(tc, s21_sub_19);
  tcase_add_test(tc, s21_sub_20);

  suite_add_tcase(s, tc);

  return s;
}