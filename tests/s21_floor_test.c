#include "s21_decimal_test.h"

START_TEST(floor1) {
  s21_decimal a = {{0, 12345, 6789, 0}}, res = {{0, 12345, 6789, 0}};
  s21_decimal floor_a = {0};

  s21_floor(a, &floor_a);
  ck_assert_int_eq(s21_is_equal(floor_a, res), 1);
}
END_TEST

START_TEST(floor2) {
  s21_decimal a = {{2147483648, 12345, 6789, 0}},
              res = {{2147483648, 12345, 6789, 0}};
  s21_decimal floor_a = {0};

  s21_floor(a, &floor_a);
  ck_assert_int_eq(s21_is_equal(floor_a, res), 1);
}
END_TEST

START_TEST(floor3) {
  s21_decimal a, res, floor_a;
  s21_from_float_to_decimal(5.5, &a);
  s21_from_float_to_decimal(5, &res);
  s21_floor(a, &floor_a);
  ck_assert_int_eq(s21_is_equal(floor_a, res), 1);
}
END_TEST

START_TEST(floor4) {
  s21_decimal a, res, floor_a;
  s21_from_float_to_decimal(-5555, &a);
  set_scale(&a, 3);
  s21_from_float_to_decimal(-6, &res);
  s21_floor(a, &floor_a);
  ck_assert_int_eq(s21_is_equal(floor_a, res), 1);
}
END_TEST

START_TEST(s21_floor_1) {
  s21_decimal value_2 = {{0xFFFFFFFF, 0, 0xFFFFFFFF, 0x80000000}};
  s21_decimal result = {0};
  int return_value = s21_floor(value_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(result.bits[2], 0xFFFFFFFF);
}
END_TEST

START_TEST(s21_floor_2) {
  s21_decimal value_2 = {{UINT8_MAX, UINT8_MAX, UINT8_MAX, 0x80010000}};
  s21_decimal result = {0};
  int return_value = s21_floor(value_2, &result);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_floor_3) {
  s21_decimal value_2 = {{UINT8_MAX, UINT8_MAX, UINT8_MAX, 0}};
  s21_decimal result = {0};
  int return_value = s21_floor(value_2, &result);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_floor_4) {
  s21_decimal value_2 = {{UINT8_MAX, UINT8_MAX, 0, 0x80010000}};
  s21_decimal result = {0};
  int return_value = s21_floor(value_2, &result);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_floor_7) {
  s21_decimal src1;
  src1.bits[0] = 0b00001111111111111111111111111111;
  src1.bits[1] = 0b00111110001001010000001001100001;
  src1.bits[2] = 0b00100000010011111100111001011110;
  src1.bits[3] = 0b10000000000010100000000000000000;
  s21_decimal res_od;
  s21_floor(src1, &res_od);
  s21_decimal result;
  result.bits[0] = 0b10100111011001000000000000000000;
  result.bits[1] = 0b00001101111000001011011010110011;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_float_eq(res_od.bits[0], result.bits[0]);
  ck_assert_float_eq(res_od.bits[1], result.bits[1]);
  ck_assert_float_eq(res_od.bits[2], result.bits[2]);
  ck_assert_float_eq(res_od.bits[3], result.bits[3]);
}
END_TEST

Suite *suite_floor_test(void) {
  Suite *s = suite_create("\033[43m floor test\033[m");
  TCase *tc = tcase_create("floor test");

  tcase_add_test(tc, floor1);
  tcase_add_test(tc, floor2);
  tcase_add_test(tc, floor3);
  tcase_add_test(tc, floor4);
  tcase_add_test(tc, s21_floor_1);
  tcase_add_test(tc, s21_floor_2);
  tcase_add_test(tc, s21_floor_3);
  tcase_add_test(tc, s21_floor_4);
  tcase_add_test(tc, s21_floor_7);

  suite_add_tcase(s, tc);

  return s;
}