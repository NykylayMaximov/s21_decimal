#include "s21_decimal_test.h"

START_TEST(s21_mul_test_1) {
  s21_decimal a = {{-1, -1, -1, 0}};         // 79228162514264337593543950335
  s21_decimal b = {{1, 0, 0, -2147483648}};  // -1
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_mul(a, b, &res_bits);

  ck_assert_int_eq(res, 0);
  s21_decimal check = {{-1, -1, -1, -2147483648}};
  ck_assert_int_eq(res_bits.bits[0], check.bits[0]);
  ck_assert_int_eq(res_bits.bits[1], check.bits[1]);
  ck_assert_int_eq(res_bits.bits[2], check.bits[2]);
  ck_assert_int_eq(res_bits.bits[3], check.bits[3]);
  // ck_assert_int_eq(s21_is_equal(res_bits, check), 1);
}
END_TEST

START_TEST(s21_mul_test_2) {
  s21_decimal a = {{-2017942635, 47083, 0, 65536}};  // 20222222222222.9
  s21_decimal b = {{0, 0, 0, 0}};                    // 0
  s21_decimal res_bits = {{0, 0, 0, 0}};
  int res = s21_mul(a, b, &res_bits);

  ck_assert_int_eq(res, 0);
  s21_decimal check = {{0, 0, 0, 0}};
  ck_assert_int_eq(res_bits.bits[0], check.bits[0]);
  ck_assert_int_eq(res_bits.bits[1], check.bits[1]);
  ck_assert_int_eq(res_bits.bits[2], check.bits[2]);
  ck_assert_int_eq(res_bits.bits[3], check.bits[3]);
  // ck_assert_int_eq(s21_is_equal(res_bits, check), 1);
}
END_TEST

START_TEST(s21_mul_test_3) {
  s21_decimal a = {{292342, 0, 0, 327680}};  // 2.92342
  s21_decimal b = {{0, 0, 0, 0}};            // 0
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_mul(a, b, &res_bits);

  ck_assert_int_eq(res, 0);
  s21_decimal check = {{0, 0, 0, 0}};
  ck_assert_int_eq(res_bits.bits[0], check.bits[0]);
  ck_assert_int_eq(res_bits.bits[1], check.bits[1]);
  ck_assert_int_eq(res_bits.bits[2], check.bits[2]);
  ck_assert_int_eq(res_bits.bits[3], check.bits[3]);
  // ck_assert_int_eq(s21_is_equal(res_bits, check), 1);
}
END_TEST

START_TEST(s21_mul_test_4) {
  s21_decimal a = {{292342, 0, 0, -2147155968}};  // -2.92342
  s21_decimal b = {{781413, 0, 0, -2147483648}};  // -781413
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_mul(a, b, &res_bits);

  ck_assert_int_eq(res, 0);
  s21_decimal check = {{806572558, 53, 0, 327680}};
  ck_assert_int_eq(res_bits.bits[0], check.bits[0]);
  ck_assert_int_eq(res_bits.bits[1], check.bits[1]);
  ck_assert_int_eq(res_bits.bits[2], check.bits[2]);
  ck_assert_int_eq(res_bits.bits[3], check.bits[3]);
  // ck_assert_int_eq(s21_is_equal(res_bits, check), 1);
}
END_TEST

START_TEST(s21_mul_test_5) {
  s21_decimal a = {{-1158315456, -197194979, 33, 0}};  // 626342352523521000000
  s21_decimal b = {{781413, 0, 0, -2147483648}};       // -781413
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_mul(a, b, &res_bits);

  ck_assert_int_eq(res, 0);
  s21_decimal check = {{-1347460288, -177876063, 26532164, 2147483648}};
  ck_assert_int_eq(res_bits.bits[0], check.bits[0]);
  ck_assert_int_eq(res_bits.bits[1], check.bits[1]);
  ck_assert_int_eq(res_bits.bits[2], check.bits[2]);
  ck_assert_int_eq(res_bits.bits[3], check.bits[3]);
  // ck_assert_int_eq(s21_is_equal(res_bits, check), 1);
}
END_TEST

// Value was either too large or too small for a Decimal.
START_TEST(s21_mul_test_6) {
  s21_decimal a = {
      {-1, -1, -1, -2147483648}};     // -79228162514264337593543950335
  s21_decimal b = {{-1, -1, -1, 0}};  // 79228162514264337593543950335
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_mul(a, b, &res_bits);

  ck_assert_int_eq(res, 2);
  s21_decimal check = {{0, 0, 0, 0}};
  ck_assert_int_eq(res_bits.bits[0], check.bits[0]);
  ck_assert_int_eq(res_bits.bits[1], check.bits[1]);
  ck_assert_int_eq(res_bits.bits[2], check.bits[2]);
  ck_assert_int_eq(res_bits.bits[3], check.bits[3]);
  // ck_assert_int_eq(s21_is_equal(res_bits, check), 1);
}
END_TEST

// Value was either too large or too small for a Decimal.
START_TEST(s21_mul_test_7) {
  s21_decimal a = {{-1, -1, -1, 0}};  // 79228162514264337593543950335
  s21_decimal b = {{-1, -1, -1, 0}};  // 79228162514264337593543950335
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_mul(a, b, &res_bits);

  ck_assert_int_eq(res, 1);
  s21_decimal check = {{0, 0, 0, 0}};
  ck_assert_int_eq(res_bits.bits[0], check.bits[0]);
  ck_assert_int_eq(res_bits.bits[1], check.bits[1]);
  ck_assert_int_eq(res_bits.bits[2], check.bits[2]);
  ck_assert_int_eq(res_bits.bits[3], check.bits[3]);
  // ck_assert_int_eq(s21_is_equal(res_bits, check), 1);
}
END_TEST

// Value was either too large or too small for a Decimal.
START_TEST(s21_mul_test_8) {
  s21_decimal a = {{1015837740, 287445, 0, 0}};  // 1234567890236460
  s21_decimal b = {{-2045900063, 28744, 0, 0}};  // 123456789023457
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_mul(a, b, &res_bits);

  ck_assert_int_eq(res, 1);
  s21_decimal check = {{0, 0, 0, 0}};
  ck_assert_int_eq(res_bits.bits[0], check.bits[0]);
  ck_assert_int_eq(res_bits.bits[1], check.bits[1]);
  ck_assert_int_eq(res_bits.bits[2], check.bits[2]);
  ck_assert_int_eq(res_bits.bits[3], check.bits[3]);
  // ck_assert_int_eq(s21_is_equal(res_bits, check), 1);
}
END_TEST

// Value was either too large or too small for a Decimal.
START_TEST(s21_mul_test_9) {
  s21_decimal a = {{-1345409089, 146074521, 0, 0}};  // 627385293423423423
  s21_decimal b = {
      {1668895137, 1064696021, 0, -2147483648}};  // -4572834592045224353
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_mul(a, b, &res_bits);

  ck_assert_int_eq(res, 2);
  s21_decimal check = {{0, 0, 0, 0}};
  ck_assert_int_eq(res_bits.bits[0], check.bits[0]);
  ck_assert_int_eq(res_bits.bits[1], check.bits[1]);
  ck_assert_int_eq(res_bits.bits[2], check.bits[2]);
  ck_assert_int_eq(res_bits.bits[3], check.bits[3]);
  // ck_assert_int_eq(s21_is_equal(res_bits, check), 1);
}
END_TEST

START_TEST(s21_mul_test_10) {
  s21_decimal a = {{5, 0, 0, -2147483648}};  // -5
  s21_decimal b = {{0, 0, 0, 0}};            // 0
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_mul(a, b, &res_bits);

  ck_assert_int_eq(res, 0);
  s21_decimal check = {{0, 0, 0, 0}};
  set_sign(&check, 1);
  ck_assert_int_eq(res_bits.bits[0], check.bits[0]);
  ck_assert_int_eq(res_bits.bits[1], check.bits[1]);
  ck_assert_int_eq(res_bits.bits[2], check.bits[2]);
  ck_assert_int_eq(res_bits.bits[3], check.bits[3]);
  // ck_assert_int_eq(s21_is_equal(res_bits, check), 1);
}
END_TEST

START_TEST(s21_mul_test_11) {
  s21_decimal a = {{351661334, 63675, 0, 0}};  // 273482394234134
  s21_decimal b = {{7, 0, 0, 0}};              // 7
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_mul(a, b, &res_bits);

  ck_assert_int_eq(res, 0);
  s21_decimal check = {{-1833337958, 445725, 0, 0}};
  ck_assert_int_eq(res_bits.bits[0], check.bits[0]);
  ck_assert_int_eq(res_bits.bits[1], check.bits[1]);
  ck_assert_int_eq(res_bits.bits[2], check.bits[2]);
  ck_assert_int_eq(res_bits.bits[3], check.bits[3]);
  // ck_assert_int_eq(s21_is_equal(res_bits, check), 1);
}
END_TEST

START_TEST(s21_mul_test_12) {
  s21_decimal a = {{61237812, 0, 0, -2147024896}};  // -6.1237812
  s21_decimal b = {{81230311, 0, 0, 196608}};       // 81230.311
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_mul(a, b, &res_bits);

  ck_assert_int_eq(res, 0);
  s21_decimal check = {{-183998228, 1158184, 0, -2146828288}};
  ck_assert_int_eq(res_bits.bits[0], check.bits[0]);
  ck_assert_int_eq(res_bits.bits[1], check.bits[1]);
  ck_assert_int_eq(res_bits.bits[2], check.bits[2]);
  ck_assert_int_eq(res_bits.bits[3], check.bits[3]);
  // ck_assert_int_eq(s21_is_equal(res_bits, check), 1);
}
END_TEST

START_TEST(s21_mul_test_13) {
  s21_decimal a = {{17403, 0, 0, 0}};              // 17403
  s21_decimal b = {{4789282, 0, 0, -2147352576}};  // -47892.82
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_mul(a, b, &res_bits);

  ck_assert_int_eq(res, 0);
  s21_decimal check = {{1743496022, 19, 0, -2147352576}};
  ck_assert_int_eq(res_bits.bits[0], check.bits[0]);
  ck_assert_int_eq(res_bits.bits[1], check.bits[1]);
  ck_assert_int_eq(res_bits.bits[2], check.bits[2]);
  ck_assert_int_eq(res_bits.bits[3], check.bits[3]);
  // ck_assert_int_eq(s21_is_equal(res_bits, check), 1);
}
END_TEST

START_TEST(s21_mul_test_15) {
  s21_decimal a = {{610781734, 168435, 0, 983040}};  // 0.723423427283494
  s21_decimal b = {{784, 0, 0, 196608}};             // 0.784
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_mul(a, b, &res_bits);

  ck_assert_int_eq(res, 0);
  s21_decimal check = {{2111509600, 132053151, 0, 1179648}};
  ck_assert_int_eq(res_bits.bits[0], check.bits[0]);
  ck_assert_int_eq(res_bits.bits[1], check.bits[1]);
  ck_assert_int_eq(res_bits.bits[2], check.bits[2]);
  ck_assert_int_eq(res_bits.bits[3], check.bits[3]);
  // ck_assert_int_eq(s21_is_equal(res_bits, check), 1);
}
END_TEST

START_TEST(s21_mul_test_16) {
  s21_decimal a = {{7938402, 0, 0, 0}};               // 7938402
  s21_decimal b = {{1830490002, 0, 0, -2147155968}};  // -18304.90002
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_mul(a, b, &res_bits);

  ck_assert_int_eq(res, 0);
  s21_decimal check = {{-1654667292, 3383300, 0, -2147155968}};
  ck_assert_int_eq(res_bits.bits[0], check.bits[0]);
  ck_assert_int_eq(res_bits.bits[1], check.bits[1]);
  ck_assert_int_eq(res_bits.bits[2], check.bits[2]);
  ck_assert_int_eq(res_bits.bits[3], check.bits[3]);
  // ck_assert_int_eq(s21_is_equal(res_bits, check), 1);
}
END_TEST

START_TEST(s21_mul_test_21) {
  s21_decimal a = {{0, 0, 0, 0}};  // 0
  s21_decimal b = {{0, 0, 0, 0}};  // 0
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_mul(a, b, &res_bits);

  ck_assert_int_eq(res, 0);
  s21_decimal check = {{0, 0, 0, 0}};
  ck_assert_int_eq(res_bits.bits[0], check.bits[0]);
  ck_assert_int_eq(res_bits.bits[1], check.bits[1]);
  ck_assert_int_eq(res_bits.bits[2], check.bits[2]);
  ck_assert_int_eq(res_bits.bits[3], check.bits[3]);
  // ck_assert_int_eq(s21_is_equal(res_bits, check), 1);
}
END_TEST

START_TEST(s21_mul_test_23) {
  s21_decimal a = {{999999999, 0, 0, 0}};  // 999999999
  s21_decimal b = {{999999999, 0, 0, 0}};  // 999999999
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_mul(a, b, &res_bits);

  ck_assert_int_eq(res, 0);
  s21_decimal check = {{808348673, 232830643, 0, 0}};
  ck_assert_int_eq(res_bits.bits[0], check.bits[0]);
  ck_assert_int_eq(res_bits.bits[1], check.bits[1]);
  ck_assert_int_eq(res_bits.bits[2], check.bits[2]);
  ck_assert_int_eq(res_bits.bits[3], check.bits[3]);
  // ck_assert_int_eq(s21_is_equal(res_bits, check), 1);
}
END_TEST

// Value was either too large or too small for a Decimal.
START_TEST(s21_mul_test_24) {
  s21_decimal a = {{-1, -1, -78293423, 0}};  // 77783903795975396563441680383
  s21_decimal b = {{-2147483648, -2147483648, 628902378,
                    0}};  // 11601201223536716331618402304
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_mul(a, b, &res_bits);

  ck_assert_int_eq(res, 1);
  s21_decimal check = {{0, 0, 0, 0}};
  ck_assert_int_eq(res_bits.bits[0], check.bits[0]);
  ck_assert_int_eq(res_bits.bits[1], check.bits[1]);
  ck_assert_int_eq(res_bits.bits[2], check.bits[2]);
  ck_assert_int_eq(res_bits.bits[3], check.bits[3]);
  // ck_assert_int_eq(s21_is_equal(res_bits, check), 1);
}
END_TEST

// Value was either too large or too small for a Decimal.
START_TEST(s21_mul_test_25) {
  s21_decimal a = {
      {-1, -1, -78293423, -2147483648}};  // -77783903795975396563441680383
  s21_decimal b = {{-2147483648, -2147483648, 628902378,
                    -2147483648}};  // -11601201223536716331618402304
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_mul(a, b, &res_bits);

  ck_assert_int_eq(res, 1);
  s21_decimal check = {{0, 0, 0, 0}};
  ck_assert_int_eq(res_bits.bits[0], check.bits[0]);
  ck_assert_int_eq(res_bits.bits[1], check.bits[1]);
  ck_assert_int_eq(res_bits.bits[2], check.bits[2]);
  ck_assert_int_eq(res_bits.bits[3], check.bits[3]);
  // ck_assert_int_eq(s21_is_equal(res_bits, check), 1);
}
END_TEST

START_TEST(s21_mul_test_26) {
  s21_decimal a = {{1, 0, 0, -2147483648}};  // -1
  s21_decimal b = {
      {-1, -1, -1, -2147483648}};  // -79228162514264337593543950335
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_mul(a, b, &res_bits);

  ck_assert_int_eq(res, 0);
  s21_decimal check = {{-1, -1, -1, 0}};
  ck_assert_int_eq(res_bits.bits[0], check.bits[0]);
  ck_assert_int_eq(res_bits.bits[1], check.bits[1]);
  ck_assert_int_eq(res_bits.bits[2], check.bits[2]);
  ck_assert_int_eq(res_bits.bits[3], check.bits[3]);
  // ck_assert_int_eq(s21_is_equal(res_bits, check), 1);
}
END_TEST

START_TEST(s21_mul_test_27) {
  s21_decimal a = {{8, 0, 0, 0}};        // 8
  s21_decimal b = {{1, 0, 0, 1835008}};  // 0.0000000000000000000000000001
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_mul(a, b, &res_bits);

  ck_assert_int_eq(res, 0);
  s21_decimal check = {{8, 0, 0, 1835008}};
  ck_assert_int_eq(res_bits.bits[0], check.bits[0]);
  ck_assert_int_eq(res_bits.bits[1], check.bits[1]);
  ck_assert_int_eq(res_bits.bits[2], check.bits[2]);
  ck_assert_int_eq(res_bits.bits[3], check.bits[3]);
  // ck_assert_int_eq(s21_is_equal(res_bits, check), 1);
}
END_TEST

START_TEST(s21_mul_test_28) {
  s21_decimal a = {{10, 0, 0, 0}};       // 10
  s21_decimal b = {{1, 0, 0, 1835008}};  // 0.0000000000000000000000000001
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_mul(a, b, &res_bits);

  ck_assert_int_eq(res, 0);
  s21_decimal check = {{10, 0, 0, 1835008}};
  ck_assert_int_eq(res_bits.bits[0], check.bits[0]);
  ck_assert_int_eq(res_bits.bits[1], check.bits[1]);
  ck_assert_int_eq(res_bits.bits[2], check.bits[2]);
  ck_assert_int_eq(res_bits.bits[3], check.bits[3]);
  // ck_assert_int_eq(s21_is_equal(res_bits, check), 1);
}
END_TEST

START_TEST(s21_mul_test_29) {
  s21_decimal a = {{8, 0, 0, 0}};            // 8
  s21_decimal b = {{1, 0, 0, -2147483648}};  // -1
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_mul(a, b, &res_bits);

  ck_assert_int_eq(res, 0);
  s21_decimal check = {{8, 0, 0, -2147483648}};
  ck_assert_int_eq(res_bits.bits[0], check.bits[0]);
  ck_assert_int_eq(res_bits.bits[1], check.bits[1]);
  ck_assert_int_eq(res_bits.bits[2], check.bits[2]);
  ck_assert_int_eq(res_bits.bits[3], check.bits[3]);
  // ck_assert_int_eq(s21_is_equal(res_bits, check), 1);
}
END_TEST

START_TEST(s21_mul_test_30) {
  s21_decimal a = {{10, 0, 0, 0}};           // 10
  s21_decimal b = {{1, 0, 0, -2147483648}};  // -1
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_mul(a, b, &res_bits);

  ck_assert_int_eq(res, 0);
  s21_decimal check = {{10, 0, 0, -2147483648}};
  ck_assert_int_eq(res_bits.bits[0], check.bits[0]);
  ck_assert_int_eq(res_bits.bits[1], check.bits[1]);
  ck_assert_int_eq(res_bits.bits[2], check.bits[2]);
  ck_assert_int_eq(res_bits.bits[3], check.bits[3]);
  // ck_assert_int_eq(s21_is_equal(res_bits, check), 1);
}
END_TEST

START_TEST(s21_mul_test_31) {
  s21_decimal a = {{1, 0, 0, -2147483648}};  // -1
  s21_decimal b = {{-1, -1, -1, 0}};         // 79228162514264337593543950335
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_mul(a, b, &res_bits);

  ck_assert_int_eq(res, 0);
  s21_decimal check = {{-1, -1, -1, -2147483648}};
  ck_assert_int_eq(res_bits.bits[0], check.bits[0]);
  ck_assert_int_eq(res_bits.bits[1], check.bits[1]);
  ck_assert_int_eq(res_bits.bits[2], check.bits[2]);
  ck_assert_int_eq(res_bits.bits[3], check.bits[3]);
  // ck_assert_int_eq(s21_is_equal(res_bits, check), 1);
}
END_TEST

START_TEST(s21_mul_test_32) {
  s21_decimal a = {{1, 0, 0, 0}};  // 1
  s21_decimal b = {
      {-1, -1, -1, -2147483648}};  // -79228162514264337593543950335
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_mul(a, b, &res_bits);

  ck_assert_int_eq(res, 0);
  s21_decimal check = {{-1, -1, -1, -2147483648}};
  ck_assert_int_eq(res_bits.bits[0], check.bits[0]);
  ck_assert_int_eq(res_bits.bits[1], check.bits[1]);
  ck_assert_int_eq(res_bits.bits[2], check.bits[2]);
  ck_assert_int_eq(res_bits.bits[3], check.bits[3]);
  // ck_assert_int_eq(s21_is_equal(res_bits, check), 1);
}
END_TEST

START_TEST(s21_mul_test_33) {
  s21_decimal a = {{-1, -1, -1, 0}};   // 79228162514264337593543950335
  s21_decimal b = {{6, 0, 0, 65536}};  // 0.6
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_mul(a, b, &res_bits);

  ck_assert_int_eq(res, 0);
  s21_decimal check = {{-1717986916, -1717986919, -1717986919, 0}};//p
  ck_assert_int_eq(res_bits.bits[0], check.bits[0]);
  ck_assert_int_eq(res_bits.bits[1], check.bits[1]);
  ck_assert_int_eq(res_bits.bits[2], check.bits[2]);
  ck_assert_int_eq(res_bits.bits[3], check.bits[3]);
  // ck_assert_int_eq(s21_is_equal(res_bits, check), 1);
}
END_TEST

START_TEST(s21_mul_test_34) {
  s21_decimal a = {
      {-1, -1, -1, -2147483648}};            // -79228162514264337593543950335
  s21_decimal b = {{6, 0, 0, -2147418112}};  // -0.6
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_mul(a, b, &res_bits);

  ck_assert_int_eq(res, 0);
  s21_decimal check = {{-1717986916, -1717986919, -1717986919, 0}};//p
  ck_assert_int_eq(res_bits.bits[0], check.bits[0]);
  ck_assert_int_eq(res_bits.bits[1], check.bits[1]);
  ck_assert_int_eq(res_bits.bits[2], check.bits[2]);
  ck_assert_int_eq(res_bits.bits[3], check.bits[3]);
  // ck_assert_int_eq(s21_is_equal(res_bits, check), 1);
}
END_TEST

START_TEST(s21_mul_test_35) {
  s21_decimal a = {{-1, -1, -1, 0}};         // 79228162514264337593543950335
  s21_decimal b = {{6, 0, 0, -2147418112}};  // -0.6
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_mul(a, b, &res_bits);

  ck_assert_int_eq(res, 0);
  s21_decimal check = {{-1717986916, -1717986919, -1717986919, -2147483648}};//p
  ck_assert_int_eq(res_bits.bits[0], check.bits[0]);
  ck_assert_int_eq(res_bits.bits[1], check.bits[1]);
  ck_assert_int_eq(res_bits.bits[2], check.bits[2]);
  ck_assert_int_eq(res_bits.bits[3], check.bits[3]);
  // ck_assert_int_eq(s21_is_equal(res_bits, check), 1);
}
END_TEST

START_TEST(s21_mul_test_36) {
  s21_decimal a = {
      {-1, -1, -1, -2147483648}};      // -79228162514264337593543950335
  s21_decimal b = {{6, 0, 0, 65536}};  // 0.6
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_mul(a, b, &res_bits);

  ck_assert_int_eq(res, 0);
  s21_decimal check = {{-1717986916, -1717986919, -1717986919, -2147483648}};//p
  ck_assert_int_eq(res_bits.bits[0], check.bits[0]);
  ck_assert_int_eq(res_bits.bits[1], check.bits[1]);
  ck_assert_int_eq(res_bits.bits[2], check.bits[2]);
  ck_assert_int_eq(res_bits.bits[3], check.bits[3]);
  // ck_assert_int_eq(s21_is_equal(res_bits, check), 1);
}
END_TEST

START_TEST(s21_mul_test_37) {
  s21_decimal a = {{-1, -1, -1, 0}};    // 79228162514264337593543950335
  s21_decimal b = {{1, 0, 0, 196608}};  // 0.001
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_mul(a, b, &res_bits);

  ck_assert_int_eq(res, 0);
  s21_decimal check = {{-1, -1, -1, 196608}};
  ck_assert_int_eq(res_bits.bits[0], check.bits[0]);
  ck_assert_int_eq(res_bits.bits[1], check.bits[1]);
  ck_assert_int_eq(res_bits.bits[2], check.bits[2]);
  ck_assert_int_eq(res_bits.bits[3], check.bits[3]);
  // ck_assert_int_eq(s21_is_equal(res_bits, check), 1);
}
END_TEST

START_TEST(s21_mul_1) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 2;
  // src2 = 3;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000110;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_2) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 3;
  // src2 = 2;
  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000110;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_3) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0;
  // src2 = 3;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_4) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 2;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_5) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 2;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_6) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 6521;
  // src2 = 74121;
  src1.bits[0] = 0b00000000000000000001100101111001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000010010000110001001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00011100110011110011101011000001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_7) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 4;
  // src2 = 97623323;
  src1.bits[0] = 0b00000000000000000000000000000100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000101110100011001110100011011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00010111010001100111010001101100;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_8) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 65658654;
  // src2 = 5;
  src1.bits[0] = 0b00000011111010011101111100011110;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000101;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00010011100100010101101110010110;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_9) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = -364748;
  // src2 = 1;
  src1.bits[0] = 0b00000000000001011001000011001100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000001011001000011001100;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_10) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 1;
  // src2 = 98745654321;
  src1.bits[0] = 0b00000000000000000000000000000001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b11111101101100110001110000110001;
  src2.bits[1] = 0b00000000000000000000000000010110;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b11111101101100110001110000110001;
  origin.bits[1] = 0b00000000000000000000000000010110;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_11) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = -9878798789;
  // src2 = -3;
  src1.bits[0] = 0b01001100110100101000000111000101;
  src1.bits[1] = 0b00000000000000000000000000000010;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b11100110011101111000010101001111;
  origin.bits[1] = 0b00000000000000000000000000000110;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_12) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 9999999999999999999;
  // src2 = 1;
  src1.bits[0] = 0b10001001111001111111111111111111;
  src1.bits[1] = 0b10001010110001110010001100000100;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b10001001111001111111111111111111;
  origin.bits[1] = 0b10001010110001110010001100000100;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_13) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 18446744073709551615;
  // src2 = 1;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b11111111111111111111111111111111;
  origin.bits[1] = 0b11111111111111111111111111111111;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_14) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_15) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_16) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_17) {
  s21_decimal src1, src2;
  int value_type_result, value_type_origin;
  // src1 = 79228162514264337593543950335;
  // src2 = -1;
  // result = null
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, NULL);
  value_type_origin = 1;
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_18) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 7922816251427554395;
  // src2 = 65645646;
  src1.bits[0] = 0b01011111000010000000010001011011;
  src1.bits[1] = 0b01101101111100110111111101100111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000011111010011010110001001110;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b01011111001100010111011110111010;
  origin.bits[1] = 0b01000100111111001101101110110001;
  origin.bits[2] = 0b00000001101011100011011100011110;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_19) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 665464545;
  // src2 = 8798232189789785;
  src1.bits[0] = 0b00100111101010100010111011100001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00010000010100101110011001011001;
  src2.bits[1] = 0b00000000000111110100000111110010;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b11000100010110100111001000111001;
  origin.bits[1] = 0b01100100100011011110110011010011;
  origin.bits[2] = 0b00000000000001001101011111010011;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_20) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 665464545;
  // src2 = -8798232189789785;
  src1.bits[0] = 0b00100111101010100010111011100001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00010000010100101110011001011001;
  src2.bits[1] = 0b00000000000111110100000111110010;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b11000100010110100111001000111001;
  origin.bits[1] = 0b01100100100011011110110011010011;
  origin.bits[2] = 0b00000000000001001101011111010011;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_21) {
  s21_decimal src1, src2;
  s21_decimal *result = NULL;
  int value_type_result, value_type_origin;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, result);
  value_type_origin = 1;
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_22) {
  s21_decimal src1, src2, result;
  int value_type_result, value_type_origin;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b11111111111111111111111111111111;
  src2.bits[1] = 0b11111111111111111111111111111111;
  src2.bits[2] = 0b11111111111111111111111111111111;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 1;
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_23) {
  s21_decimal val1 = {{2, 0, 0, 0}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(s21_mul_24) {
  s21_decimal val1 = {{8, 0, 0, 0}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(s21_mul_25) {
  s21_decimal val1 = {{2, 0, 0, 0}};
  s21_decimal val2 = {{8, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(s21_mul_26) {
  s21_decimal src1 = {0}, src2 = {0}, origin = {0}, result = {0};
  int value_type_result = 0, value_type_origin = 0;
  // 27
  src1.bits[0] = 0b00000000000000000000000000011011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  // 19
  src2.bits[0] = 0b00000000000000000000000000010011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  // 513
  origin.bits[0] = 0b00000000000000000000001000000001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_27) {
  s21_decimal src1 = {0}, src2 = {0}, origin = {0}, result = {0};
  int value_type_result = 0, value_type_origin = 0;
  // 2668745618745983003
  src1.bits[0] = 0b00101001001111000000000000011011;
  src1.bits[1] = 0b00100101000010010100101000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  // 275
  src2.bits[0] = 0b00000000000000000000000100010011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  // 733905045155145325825
  origin.bits[0] = 0b01001011011101000001110100000001;
  origin.bits[1] = 0b11001000111110100111111000101100;
  origin.bits[2] = 0b00000000000000000000000000100111;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_28) {
  // null * null
  s21_decimal src1 = {0}, src2 = {0}, origin = {0}, result = {0};
  int value_type_result = 0, value_type_origin = 0;
  //
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  //
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  //
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_29) {
  // null * digit
  s21_decimal src1 = {0}, src2 = {0}, origin = {0}, result = {0};
  int value_type_result = 0, value_type_origin = 0;
  //
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  //
  src2.bits[0] = 0b00000000000011000010001000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  //
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_30) {
  s21_decimal src1 = {0}, src2 = {0}, origin = {0}, result = {0};
  int value_type_result = 0, value_type_origin = 0;
  // digit * null
  src1.bits[0] = 0b00000100100011000100101100000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000001001001001000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  //
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  //
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_31) {
  // neg null * null
  s21_decimal src1 = {0}, src2 = {0}, origin = {0}, result = {0};
  int value_type_result = 0, value_type_origin = 0;
  //
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  //
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  //
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_32) {
  // null * neg_null`
  s21_decimal src1 = {0}, src2 = {0}, origin = {0}, result = {0};
  int value_type_result = 0, value_type_origin = 0;
  //
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  //
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  //
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_33) {
  // переполнение плюс
  s21_decimal src1 = {0}, src2 = {0}, origin = {0}, result = {0};
  int value_type_result = 0, value_type_origin = 0;
  // 13038434988312589819859583626
  src1.bits[0] = 0b00010100010100100100001010001010;
  src1.bits[1] = 0b00000001110010010010111111110100;
  src1.bits[2] = 0b00101010001000010010010000000001;
  src1.bits[3] = 0b00000000000000000000000000000000;
  // 4951760157794543045565218816
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00001001000100000000000000000000;
  src2.bits[2] = 0b00010000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 1;
  //
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_34) {
  // отрицательное переполнение
  s21_decimal src1 = {0}, src2 = {0}, origin = {0}, result = {0};
  int value_type_result = 0, value_type_origin = 0;
  //
  src1.bits[0] = 0b00010010011010000001000100000000;
  src1.bits[1] = 0b00000010010001000010101100000000;
  src1.bits[2] = 0b00000100000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  //
  src2.bits[0] = 0b00001000010010001000100101001100;
  src2.bits[1] = 0b00000100000100100010000001111011;
  src2.bits[2] = 0b00010001000000000000000000010000;
  src2.bits[3] = 0b10000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 2;
  //
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

Suite *suite_mul_test(void) {
  Suite *s = suite_create("\033[42m mul test\033[m");
  TCase *tc = tcase_create("mul test");

  tcase_add_test(tc, s21_mul_test_1);
  tcase_add_test(tc, s21_mul_test_2);
  tcase_add_test(tc, s21_mul_test_3);
  tcase_add_test(tc, s21_mul_test_4);
  tcase_add_test(tc, s21_mul_test_5);
  tcase_add_test(tc, s21_mul_test_6);
  tcase_add_test(tc, s21_mul_test_7);
  tcase_add_test(tc, s21_mul_test_8);
  tcase_add_test(tc, s21_mul_test_9);
  tcase_add_test(tc, s21_mul_test_10);
  tcase_add_test(tc, s21_mul_test_11);
  tcase_add_test(tc, s21_mul_test_12);
  tcase_add_test(tc, s21_mul_test_13);
  tcase_add_test(tc, s21_mul_test_15);
  tcase_add_test(tc, s21_mul_test_16);
  tcase_add_test(tc, s21_mul_test_21);
  tcase_add_test(tc, s21_mul_test_23);
  tcase_add_test(tc, s21_mul_test_24);
  tcase_add_test(tc, s21_mul_test_25);
  tcase_add_test(tc, s21_mul_test_26);
  tcase_add_test(tc, s21_mul_test_27);
  tcase_add_test(tc, s21_mul_test_28);
  tcase_add_test(tc, s21_mul_test_29);
  tcase_add_test(tc, s21_mul_test_30);
  tcase_add_test(tc, s21_mul_test_31);
  tcase_add_test(tc, s21_mul_test_32);
  tcase_add_test(tc, s21_mul_test_33);
  tcase_add_test(tc, s21_mul_test_34);
  tcase_add_test(tc, s21_mul_test_35);
  tcase_add_test(tc, s21_mul_test_36);
  tcase_add_test(tc, s21_mul_test_37);
  tcase_add_test(tc, s21_mul_1);
  tcase_add_test(tc, s21_mul_2);
  tcase_add_test(tc, s21_mul_3);
  tcase_add_test(tc, s21_mul_4);
  tcase_add_test(tc, s21_mul_5);
  tcase_add_test(tc, s21_mul_6);
  tcase_add_test(tc, s21_mul_7);
  tcase_add_test(tc, s21_mul_8);
  tcase_add_test(tc, s21_mul_9);
  tcase_add_test(tc, s21_mul_10);
  tcase_add_test(tc, s21_mul_11);
  tcase_add_test(tc, s21_mul_12);
  tcase_add_test(tc, s21_mul_13);
  tcase_add_test(tc, s21_mul_14);
  tcase_add_test(tc, s21_mul_15);
  tcase_add_test(tc, s21_mul_16);
  tcase_add_test(tc, s21_mul_17);
  tcase_add_test(tc, s21_mul_18);
  tcase_add_test(tc, s21_mul_19);
  tcase_add_test(tc, s21_mul_20);
  tcase_add_test(tc, s21_mul_21);
  tcase_add_test(tc, s21_mul_22);
  tcase_add_test(tc, s21_mul_23);
  tcase_add_test(tc, s21_mul_24);
  tcase_add_test(tc, s21_mul_25);
  tcase_add_test(tc, s21_mul_26);
  tcase_add_test(tc, s21_mul_27);
  tcase_add_test(tc, s21_mul_28);
  tcase_add_test(tc, s21_mul_29);
  tcase_add_test(tc, s21_mul_30);
  tcase_add_test(tc, s21_mul_31);
  tcase_add_test(tc, s21_mul_32);
  tcase_add_test(tc, s21_mul_33);
  tcase_add_test(tc, s21_mul_34);

  suite_add_tcase(s, tc);

  return s;
}