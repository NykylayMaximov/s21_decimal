#include "s21_decimal_test.h"

START_TEST(round1) {
  s21_decimal a = {{0, 12345, 6789, 0}}, res = {{0, 12345, 6789, 0}};
  s21_decimal round_a = {0};

  s21_round(a, &round_a);
  ck_assert_int_eq(s21_is_equal(round_a, res), 1);
}
END_TEST

START_TEST(round2) {
  s21_decimal a = {{2147483648, 12345, 6789, 0}},
              res = {{2147483648, 12345, 6789, 0}};
  s21_decimal round_a = {0};

  s21_round(a, &round_a);
  ck_assert_int_eq(s21_is_equal(round_a, res), 1);
}
END_TEST

START_TEST(round3) {
  s21_decimal a, res, round_a;
  s21_from_float_to_decimal(-5555, &a);
  set_scale(&a, 3);
  s21_from_float_to_decimal(-6, &res);
  s21_round(a, &round_a);
  ck_assert_int_eq(s21_is_equal(round_a, res), 1);
}
END_TEST

START_TEST(round4) {
  s21_decimal a, res, round_a;
  s21_from_float_to_decimal(-5.5, &a);
  s21_from_float_to_decimal(-6, &res);
  s21_round(a, &round_a);
  ck_assert_int_eq(s21_is_equal(round_a, res), 1);
}
END_TEST

START_TEST(s21_round_2) {
  s21_decimal value_2 = {{0xFFFFFFFF, 0, 0xFFFFFFFF, 0x80000000}};
  s21_decimal result = {0};
  int return_value = s21_round(value_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(result.bits[2], 0xFFFFFFFF);
}
END_TEST

START_TEST(s21_round_3) {
  s21_decimal value_2 = {{0xFFFFFFFF, 0, 0xFFFFFFFF, 0x80020000}};
  s21_decimal result = {0};
  int return_value = s21_round(value_2, &result);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_round_5) {
  s21_decimal value_2 = {{15, 0, 0, pow(2, 16)}};
  s21_decimal result = {0};
  int return_value = s21_round(value_2, &result);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_round_6) {
  s21_decimal value_2 = {{15, 0, 0, 0x80010000}};
  s21_decimal result = {0};
  int return_value = s21_round(value_2, &result);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_round_11) {
  s21_decimal src1;
  src1.bits[0] = 0b01010101001110101110101110110001;
  src1.bits[1] = 0b00001101101101001101101001011111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000100100000000000000000;
  s21_decimal result;
  result.bits[0] = 0b00000000000000000000000000000001;
  result.bits[1] = 0b00000000000000000000000000000000;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b10000000000000000000000000000000;
  s21_decimal res_od;
  s21_round(src1, &res_od);
  ck_assert_float_eq(res_od.bits[0], result.bits[0]);
  ck_assert_float_eq(res_od.bits[1], result.bits[1]);
  ck_assert_float_eq(res_od.bits[2], result.bits[2]);
  ck_assert_float_eq(res_od.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_12) {
  s21_decimal src1;
  src1.bits[0] = 0b10010111011100111001111111111111;
  src1.bits[1] = 0b00111100000010000011000110001101;
  src1.bits[2] = 0b00000000000000000000000000000001;
  src1.bits[3] = 0b10000000000001110000000000000000;
  s21_decimal res_od;
  s21_round(src1, &res_od);
  s21_decimal result;
  result.bits[3] = 0b10000000000000000000000000000000;
  result.bits[2] = 0;
  result.bits[1] = 0b00000000000000000000001000010010;
  result.bits[0] = 0b00110110101101101000110001000000;
  ck_assert_float_eq(res_od.bits[0], result.bits[0]);
  ck_assert_float_eq(res_od.bits[1], result.bits[1]);
  ck_assert_float_eq(res_od.bits[2], result.bits[2]);
  ck_assert_float_eq(res_od.bits[3], result.bits[3]);
}
END_TEST

Suite *suite_round_test(void) {
  Suite *s = suite_create("\033[43m round test\033[m");
  TCase *tc = tcase_create("round test");

  tcase_add_test(tc, round1);
  tcase_add_test(tc, round2);
  tcase_add_test(tc, round3);
  tcase_add_test(tc, round4);
  tcase_add_test(tc, s21_round_2);
  tcase_add_test(tc, s21_round_3);
  tcase_add_test(tc, s21_round_5);
  tcase_add_test(tc, s21_round_6);
  tcase_add_test(tc, s21_round_11);
  tcase_add_test(tc, s21_round_12);

  suite_add_tcase(s, tc);

  return s;
}