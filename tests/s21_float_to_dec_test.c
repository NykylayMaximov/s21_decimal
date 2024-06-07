#include "s21_decimal_test.h"

START_TEST(s21_from_float_to_decimal_4) {
  float num = -27348;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_float_to_decimal(num, &res_bits);

  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(res_bits.bits[0], 0b00000000000000000110101011010100);
  ck_assert_int_eq(res_bits.bits[1], 0b00000000000000000000000000000000);
  ck_assert_int_eq(res_bits.bits[2], 0b00000000000000000000000000000000);
  ck_assert_int_eq(res_bits.bits[3], 0b10000000000000000000000000000000);
}
END_TEST

START_TEST(s21_from_float_to_decimal_5) {
  float num = 823923;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_float_to_decimal(num, &res_bits);

  ck_assert_int_eq((int)res, 0);
  ck_assert_int_eq((int)res_bits.bits[0], 823923);
  ck_assert_int_eq((int)res_bits.bits[1], 0);
  ck_assert_int_eq((int)res_bits.bits[2], 0);
  ck_assert_int_eq((int)res_bits.bits[3], 0);
}
END_TEST

START_TEST(s21_from_float_to_decimal_9) {
  float num = 912479.2;

  int res = s21_from_float_to_decimal(num, NULL);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_from_float_to_decimal_10) {
  float num = -123234.000;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_float_to_decimal(num, &res_bits);

  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(res_bits.bits[0], 0b00000000000000011110000101100010);
  ck_assert_int_eq(res_bits.bits[1], 0b00000000000000000000000000000000);
  ck_assert_int_eq(res_bits.bits[2], 0b00000000000000000000000000000000);
  ck_assert_int_eq(res_bits.bits[3], 0b10000000000000000000000000000000);
}
END_TEST

START_TEST(s21_from_float_to_decimal_11) {
  float num = 1e-29;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_float_to_decimal(num, &res_bits);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_from_float_to_decimal_12) {
  float num = -23748280;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_float_to_decimal(num, &res_bits);

  ck_assert_int_eq((int)res, 0);
  ck_assert_int_eq((int)res_bits.bits[0], 23748280);
  ck_assert_int_eq((int)res_bits.bits[1], 0);
  ck_assert_int_eq((int)res_bits.bits[2], 0);
  ck_assert_int_eq((int)res_bits.bits[3], -2147483648);
}
END_TEST

START_TEST(s21_from_float_to_decimal_13) {
  float num = 802000;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_float_to_decimal(num, &res_bits);

  ck_assert_int_eq((int)res, 0);
  ck_assert_int_eq((int)res_bits.bits[0], 802000);
  ck_assert_int_eq((int)res_bits.bits[1], 0);
  ck_assert_int_eq((int)res_bits.bits[2], 0);
  ck_assert_int_eq((int)res_bits.bits[3], 0);
}
END_TEST

START_TEST(s21_from_float_to_decimal_15) {
  float num = 0.5632482;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_float_to_decimal(num, &res_bits);

  ck_assert_int_eq((int)res, 0);
  ck_assert_int_eq((int)res_bits.bits[0], 5632482);
  ck_assert_int_eq((int)res_bits.bits[1], 0);
  ck_assert_int_eq((int)res_bits.bits[2], 0);
  ck_assert_int_eq((int)res_bits.bits[3], 458752);
}
END_TEST

START_TEST(s21_from_float_to_decimal_17) {
  float num = -0.6527385;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_float_to_decimal(num, &res_bits);

  ck_assert_int_eq((int)res, 0);
  ck_assert_int_eq((int)res_bits.bits[0], 6527385);
  ck_assert_int_eq((int)res_bits.bits[1], 0);
  ck_assert_int_eq((int)res_bits.bits[2], 0);
  ck_assert_int_eq((int)res_bits.bits[3], -2147024896);
}
END_TEST

START_TEST(s21_from_float_to_decimal_18) {
  float num = -12397620;
  s21_decimal res_bits = {{0}};

  int res = s21_from_float_to_decimal(num, &res_bits);

  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(res_bits.bits[0], 0b00000000101111010010110000110100);
  ck_assert_int_eq(res_bits.bits[1], 0b00000000000000000000000000000000);
  ck_assert_int_eq(res_bits.bits[2], 0b00000000000000000000000000000000);
  ck_assert_int_eq(res_bits.bits[3], 0b10000000000000000000000000000000);
}
END_TEST

START_TEST(s21_from_float_to_decimal_19) {
  float num = 12397620;
  s21_decimal res_bits = {{0}};

  int res = s21_from_float_to_decimal(num, &res_bits);

  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(res_bits.bits[0], 0b00000000101111010010110000110100);
  ck_assert_int_eq(res_bits.bits[1], 0b00000000000000000000000000000000);
  ck_assert_int_eq(res_bits.bits[2], 0b00000000000000000000000000000000);
  ck_assert_int_eq(res_bits.bits[3], 0b00000000000000000000000000000000);
}
END_TEST

START_TEST(s21_from_float_to_decimal_21) {
  s21_decimal dst = {0}, origin = {0};
  float src = 1234.5;
  int dst_output = 0;
  int result_output = 0;
  origin.bits[0] = 0b00000000000000000011000000111001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000010000000000000000;
  result_output = s21_from_float_to_decimal(src, &dst);
  ck_assert_int_eq(origin.bits[0], dst.bits[0]);
  ck_assert_int_eq(origin.bits[1], dst.bits[1]);
  ck_assert_int_eq(origin.bits[2], dst.bits[2]);
  ck_assert_int_eq(origin.bits[3], dst.bits[3]);
  ck_assert_int_eq(dst_output, result_output);
}
END_TEST

START_TEST(s21_from_float_to_decimal_23) {
  s21_decimal dst = {0}, origin = {0};
  float src = 999999995;
  // 9999999|95.0
  // 10000000|00.0
  int dst_output = 0;
  int result_output = 0;
  origin.bits[0] = 0b00111011100110101100101000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  result_output = s21_from_float_to_decimal(src, &dst);
  ck_assert_int_eq(origin.bits[0], dst.bits[0]);
  ck_assert_int_eq(origin.bits[1], dst.bits[1]);
  ck_assert_int_eq(origin.bits[2], dst.bits[2]);
  ck_assert_int_eq(origin.bits[3], dst.bits[3]);
  ck_assert_int_eq(dst_output, result_output);
}
END_TEST

START_TEST(s21_from_float_to_decimal_24) {
  s21_decimal dst = {0}, origin = {0};
  float src = 0.00000000000000000000000000001f;
  int dst_output = 1;
  int result_output = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  result_output = s21_from_float_to_decimal(src, &dst);
  ck_assert_int_eq(origin.bits[0], dst.bits[0]);
  ck_assert_int_eq(origin.bits[1], dst.bits[1]);
  ck_assert_int_eq(origin.bits[2], dst.bits[2]);
  ck_assert_int_eq(origin.bits[3], dst.bits[3]);
  ck_assert_int_eq(dst_output, result_output);
}
END_TEST

START_TEST(s21_from_float_to_decimal_25) {
  s21_decimal dst = {0}, origin = {0};
  float src = 192836;
  // 192835.9|6
  // 192836.0|0
  int dst_output = 0;
  int result_output = 0;
  origin.bits[0] = 0b00000000000000101111000101000100;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  result_output = s21_from_float_to_decimal(src, &dst);
  ck_assert_int_eq(origin.bits[0], dst.bits[0]);
  ck_assert_int_eq(origin.bits[1], dst.bits[1]);
  ck_assert_int_eq(origin.bits[2], dst.bits[2]);
  ck_assert_int_eq(origin.bits[3], dst.bits[3]);
  ck_assert_int_eq(dst_output, result_output);
}
END_TEST

START_TEST(s21_from_float_to_decimal_26) {
  s21_decimal dst = {0}, origin = {0};
  float src = -192836;
  // 3552346|23461234.12353236
  // 3552346|00000000.0
  int dst_output = 0;
  int result_output = 0;
  origin.bits[0] = 0b00000000000000101111000101000100;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  result_output = s21_from_float_to_decimal(src, &dst);
  ck_assert_int_eq(origin.bits[0], dst.bits[0]);
  ck_assert_int_eq(origin.bits[1], dst.bits[1]);
  ck_assert_int_eq(origin.bits[2], dst.bits[2]);
  ck_assert_int_eq(origin.bits[3], dst.bits[3]);
  ck_assert_int_eq(dst_output, result_output);
}
END_TEST

START_TEST(s21_from_float_to_decimal_27) {
  s21_decimal dst = {0}, origin = {0};
  float src = 999999995;
  // 9999999|95.0
  // 10000000|00.0
  int dst_output = 0;
  int result_output = 0;
  origin.bits[0] = 0b00111011100110101100101000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  result_output = s21_from_float_to_decimal(src, &dst);
  ck_assert_int_eq(origin.bits[0], dst.bits[0]);
  ck_assert_int_eq(origin.bits[1], dst.bits[1]);
  ck_assert_int_eq(origin.bits[2], dst.bits[2]);
  ck_assert_int_eq(origin.bits[3], dst.bits[3]);
  ck_assert_int_eq(dst_output, result_output);
}
END_TEST

START_TEST(s21_from_float_to_decimal_28) {
  s21_decimal dst = {0}, origin = {0};
  float src = 0.00000000000000000000000000001f;
  int dst_output = 1;
  int result_output = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  result_output = s21_from_float_to_decimal(src, &dst);
  ck_assert_int_eq(origin.bits[0], dst.bits[0]);
  ck_assert_int_eq(origin.bits[1], dst.bits[1]);
  ck_assert_int_eq(origin.bits[2], dst.bits[2]);
  ck_assert_int_eq(origin.bits[3], dst.bits[3]);
  ck_assert_int_eq(dst_output, result_output);
}
END_TEST

Suite *suite_float_to_dec_test(void) {
  Suite *s = suite_create("\033[45m float to dec test\033[m");
  TCase *tc = tcase_create("float to dec test");

  tcase_add_test(tc, s21_from_float_to_decimal_4);
  tcase_add_test(tc, s21_from_float_to_decimal_5);
  tcase_add_test(tc, s21_from_float_to_decimal_9);
  tcase_add_test(tc, s21_from_float_to_decimal_10);
  tcase_add_test(tc, s21_from_float_to_decimal_11);
  tcase_add_test(tc, s21_from_float_to_decimal_12);
  tcase_add_test(tc, s21_from_float_to_decimal_13);
  tcase_add_test(tc, s21_from_float_to_decimal_15);
  tcase_add_test(tc, s21_from_float_to_decimal_17);
  tcase_add_test(tc, s21_from_float_to_decimal_18);
  tcase_add_test(tc, s21_from_float_to_decimal_19);
  tcase_add_test(tc, s21_from_float_to_decimal_21);
  tcase_add_test(tc, s21_from_float_to_decimal_23);
  tcase_add_test(tc, s21_from_float_to_decimal_24);
  tcase_add_test(tc, s21_from_float_to_decimal_25);
  tcase_add_test(tc, s21_from_float_to_decimal_26);
  tcase_add_test(tc, s21_from_float_to_decimal_27);
  tcase_add_test(tc, s21_from_float_to_decimal_28);

  suite_add_tcase(s, tc);

  return s;
}