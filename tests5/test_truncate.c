#include "./test.h"

START_TEST(test_truncate_ok1) {
  // 79228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}
END_TEST

START_TEST(test_truncate_ok2) {
  // -79228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -79228162514264337593543950335
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok3) {
  // 7922816251426433759354395033.5
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 7922816251426433759354395033
  s21_decimal decimal_check = {{0x99999999, 0x99999999, 0x19999999, 0x0}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok4) {
  // -7922816251426433759354395033.5
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -7922816251426433759354395033
  s21_decimal decimal_check = {
      {0x99999999, 0x99999999, 0x19999999, 0x80000000}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok5) {
  // 792281625142643375935439503.35
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};
  // 792281625142643375935439503
  s21_decimal decimal_check = {{0x28F5C28F, 0xF5C28F5C, 0x28F5C28, 0x0}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok6) {
  // -792281625142643375935439503.35
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80020000}};
  // -792281625142643375935439503
  s21_decimal decimal_check = {{0x28F5C28F, 0xF5C28F5C, 0x28F5C28, 0x80000000}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok7) {
  // 79228162514264337593543950.335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x30000}};
  // 79228162514264337593543950
  s21_decimal decimal_check = {{0x9DB22D0E, 0x4BC6A7EF, 0x418937, 0x0}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok8) {
  // -79228162514264337593543950.335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80030000}};
  // -79228162514264337593543950
  s21_decimal decimal_check = {{0x9DB22D0E, 0x4BC6A7EF, 0x418937, 0x80000000}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok9) {
  // 7922816251426433759354395.0335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x40000}};
  // 7922816251426433759354395
  s21_decimal decimal_check = {{0x295E9E1B, 0xBAC710CB, 0x68DB8, 0x0}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok10) {
  // -7922816251426433759354395.0335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80040000}};
  // -7922816251426433759354395
  s21_decimal decimal_check = {{0x295E9E1B, 0xBAC710CB, 0x68DB8, 0x80000000}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok11) {
  // 792281625142643375935439.50335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x50000}};
  // 792281625142643375935439
  s21_decimal decimal_check = {{0x84230FCF, 0xAC471B47, 0xA7C5, 0x0}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok12) {
  // -792281625142643375935439.50335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80050000}};
  // -792281625142643375935439
  s21_decimal decimal_check = {{0x84230FCF, 0xAC471B47, 0xA7C5, 0x80000000}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok13) {
  // 79228162514264337593543.950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x60000}};
  // 79228162514264337593543
  s21_decimal decimal_check = {{0x8D36B4C7, 0xF7A0B5ED, 0x10C6, 0x0}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok14) {
  // -79228162514264337593543.950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80060000}};
  // -79228162514264337593543
  s21_decimal decimal_check = {{0x8D36B4C7, 0xF7A0B5ED, 0x10C6, 0x80000000}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok15) {
  // 7922816251426433759354.3950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x70000}};
  // 7922816251426433759354
  s21_decimal decimal_check = {{0xF485787A, 0x7F29ABCA, 0x1AD, 0x0}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok16) {
  // -7922816251426433759354.3950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80070000}};
  // -7922816251426433759354
  s21_decimal decimal_check = {{0xF485787A, 0x7F29ABCA, 0x1AD, 0x80000000}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok17) {
  // 792281625142643375935.43950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000}};
  // 792281625142643375935
  s21_decimal decimal_check = {{0x1873BF3F, 0xF31DC461, 0x2A, 0x0}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok18) {
  // -792281625142643375935.43950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80080000}};
  // -792281625142643375935
  s21_decimal decimal_check = {{0x1873BF3F, 0xF31DC461, 0x2A, 0x80000000}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok19) {
  // 79228162514264337593.543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x90000}};
  // 79228162514264337593
  s21_decimal decimal_check = {{0xB5A52CB9, 0x4B82FA09, 0x4, 0x0}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok20) {
  // -79228162514264337593.543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80090000}};
  // -79228162514264337593
  s21_decimal decimal_check = {{0xB5A52CB9, 0x4B82FA09, 0x4, 0x80000000}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok21) {
  // 7922816251426433759.3543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xA0000}};
  // 7922816251426433759
  s21_decimal decimal_check = {{0x5EF6EADF, 0x6DF37F67, 0x0, 0x0}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok22) {
  // -7922816251426433759.3543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800A0000}};
  // -7922816251426433759
  s21_decimal decimal_check = {{0x5EF6EADF, 0x6DF37F67, 0x0, 0x80000000}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok23) {
  // 792281625142643375.93543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xB0000}};
  // 792281625142643375
  s21_decimal decimal_check = {{0xBCB24AAF, 0xAFEBFF0, 0x0, 0x0}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok24) {
  // -792281625142643375.93543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800B0000}};
  // -792281625142643375
  s21_decimal decimal_check = {{0xBCB24AAF, 0xAFEBFF0, 0x0, 0x80000000}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok25) {
  // 79228162514264337.593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xC0000}};
  // 79228162514264337
  s21_decimal decimal_check = {{0x12DEA111, 0x1197998, 0x0, 0x0}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok26) {
  // -79228162514264337.593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800C0000}};
  // -79228162514264337
  s21_decimal decimal_check = {{0x12DEA111, 0x1197998, 0x0, 0x80000000}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok27) {
  // 7922816251426433.7593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xD0000}};
  // 7922816251426433
  s21_decimal decimal_check = {{0x68497681, 0x1C25C2, 0x0, 0x0}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok28) {
  // -7922816251426433.7593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800D0000}};
  // -7922816251426433
  s21_decimal decimal_check = {{0x68497681, 0x1C25C2, 0x0, 0x80000000}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok29) {
  // 792281625142643.37593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xE0000}};
  // 792281625142643
  s21_decimal decimal_check = {{0x70D42573, 0x2D093, 0x0, 0x0}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok30) {
  // -792281625142643.37593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800E0000}};
  // -792281625142643
  s21_decimal decimal_check = {{0x70D42573, 0x2D093, 0x0, 0x80000000}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok31) {
  // 79228162514264.337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xF0000}};
  // 79228162514264
  s21_decimal decimal_check = {{0xBE7B9D58, 0x480E, 0x0, 0x0}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok32) {
  // -79228162514264.337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800F0000}};
  // -79228162514264
  s21_decimal decimal_check = {{0xBE7B9D58, 0x480E, 0x0, 0x80000000}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok33) {
  // 7922816251426.4337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x100000}};
  // 7922816251426
  s21_decimal decimal_check = {{0xACA5F622, 0x734, 0x0, 0x0}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok34) {
  // -7922816251426.4337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80100000}};
  // -7922816251426
  s21_decimal decimal_check = {{0xACA5F622, 0x734, 0x0, 0x80000000}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok35) {
  // 792281625142.64337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x110000}};
  // 792281625142
  s21_decimal decimal_check = {{0x77AA3236, 0xB8, 0x0, 0x0}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok36) {
  // -792281625142.64337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80110000}};
  // -792281625142
  s21_decimal decimal_check = {{0x77AA3236, 0xB8, 0x0, 0x80000000}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok37) {
  // 79228162514.264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x120000}};
  // 79228162514
  s21_decimal decimal_check = {{0x725DD1D2, 0x12, 0x0, 0x0}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok38) {
  // -79228162514.264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80120000}};
  // -79228162514
  s21_decimal decimal_check = {{0x725DD1D2, 0x12, 0x0, 0x80000000}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok39) {
  // 7922816251.4264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x130000}};
  // 7922816251
  s21_decimal decimal_check = {{0xD83C94FB, 0x1, 0x0, 0x0}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok40) {
  // -7922816251.4264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80130000}};
  // -7922816251
  s21_decimal decimal_check = {{0xD83C94FB, 0x1, 0x0, 0x80000000}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok41) {
  // 792281625.14264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  // 792281625
  s21_decimal decimal_check = {{0x2F394219, 0x0, 0x0, 0x0}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok42) {
  // -792281625.14264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80140000}};
  // -792281625
  s21_decimal decimal_check = {{0x2F394219, 0x0, 0x0, 0x80000000}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok43) {
  // 79228162.514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x150000}};
  // 79228162
  s21_decimal decimal_check = {{0x4B8ED02, 0x0, 0x0, 0x0}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok44) {
  // -79228162.514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80150000}};
  // -79228162
  s21_decimal decimal_check = {{0x4B8ED02, 0x0, 0x0, 0x80000000}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok45) {
  // 7922816.2514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x160000}};
  // 7922816
  s21_decimal decimal_check = {{0x78E480, 0x0, 0x0, 0x0}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok46) {
  // -7922816.2514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80160000}};
  // -7922816
  s21_decimal decimal_check = {{0x78E480, 0x0, 0x0, 0x80000000}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok47) {
  // 792281.62514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x170000}};
  // 792281
  s21_decimal decimal_check = {{0xC16D9, 0x0, 0x0, 0x0}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok48) {
  // -792281.62514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80170000}};
  // -792281
  s21_decimal decimal_check = {{0xC16D9, 0x0, 0x0, 0x80000000}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok49) {
  // 79228.162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x180000}};
  // 79228
  s21_decimal decimal_check = {{0x1357C, 0x0, 0x0, 0x0}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok50) {
  // -79228.162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80180000}};
  // -79228
  s21_decimal decimal_check = {{0x1357C, 0x0, 0x0, 0x80000000}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok51) {
  // 7922.8162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x190000}};
  // 7922
  s21_decimal decimal_check = {{0x1EF2, 0x0, 0x0, 0x0}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok52) {
  // -7922.8162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80190000}};
  // -7922
  s21_decimal decimal_check = {{0x1EF2, 0x0, 0x0, 0x80000000}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok53) {
  // 792.28162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1A0000}};
  // 792
  s21_decimal decimal_check = {{0x318, 0x0, 0x0, 0x0}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok54) {
  // -792.28162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801A0000}};
  // -792
  s21_decimal decimal_check = {{0x318, 0x0, 0x0, 0x80000000}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok55) {
  // 79.228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1B0000}};
  // 79
  s21_decimal decimal_check = {{0x4F, 0x0, 0x0, 0x0}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok56) {
  // -79.228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801B0000}};
  // -79
  s21_decimal decimal_check = {{0x4F, 0x0, 0x0, 0x80000000}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok57) {
  // 7.9228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // 7
  s21_decimal decimal_check = {{0x7, 0x0, 0x0, 0x0}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok58) {
  // -7.9228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  // -7
  s21_decimal decimal_check = {{0x7, 0x0, 0x0, 0x80000000}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok59) {
  // 79228162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950334
  s21_decimal decimal_check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok60) {
  // -79228162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -79228162514264337593543950334
  s21_decimal decimal_check = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok61) {
  // 7922816251426433759354395033.4
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 7922816251426433759354395033
  s21_decimal decimal_check = {{0x99999999, 0x99999999, 0x19999999, 0x0}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok62) {
  // -7922816251426433759354395033.4
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -7922816251426433759354395033
  s21_decimal decimal_check = {
      {0x99999999, 0x99999999, 0x19999999, 0x80000000}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok63) {
  // 792281625142643375935439503.34
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};
  // 792281625142643375935439503
  s21_decimal decimal_check = {{0x28F5C28F, 0xF5C28F5C, 0x28F5C28, 0x0}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok64) {
  // -792281625142643375935439503.34
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80020000}};
  // -792281625142643375935439503
  s21_decimal decimal_check = {{0x28F5C28F, 0xF5C28F5C, 0x28F5C28, 0x80000000}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok65) {
  // 79228162514264337593543950.334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x30000}};
  // 79228162514264337593543950
  s21_decimal decimal_check = {{0x9DB22D0E, 0x4BC6A7EF, 0x418937, 0x0}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok66) {
  // -79228162514264337593543950.334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80030000}};
  // -79228162514264337593543950
  s21_decimal decimal_check = {{0x9DB22D0E, 0x4BC6A7EF, 0x418937, 0x80000000}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok67) {
  // 7922816251426433759354395.0334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x40000}};
  // 7922816251426433759354395
  s21_decimal decimal_check = {{0x295E9E1B, 0xBAC710CB, 0x68DB8, 0x0}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok68) {
  // -7922816251426433759354395.0334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80040000}};
  // -7922816251426433759354395
  s21_decimal decimal_check = {{0x295E9E1B, 0xBAC710CB, 0x68DB8, 0x80000000}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok69) {
  // 792281625142643375935439.50334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x50000}};
  // 792281625142643375935439
  s21_decimal decimal_check = {{0x84230FCF, 0xAC471B47, 0xA7C5, 0x0}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok70) {
  // -792281625142643375935439.50334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80050000}};
  // -792281625142643375935439
  s21_decimal decimal_check = {{0x84230FCF, 0xAC471B47, 0xA7C5, 0x80000000}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok71) {
  // 79228162514264337593543.950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x60000}};
  // 79228162514264337593543
  s21_decimal decimal_check = {{0x8D36B4C7, 0xF7A0B5ED, 0x10C6, 0x0}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok72) {
  // -79228162514264337593543.950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80060000}};
  // -79228162514264337593543
  s21_decimal decimal_check = {{0x8D36B4C7, 0xF7A0B5ED, 0x10C6, 0x80000000}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok73) {
  // 7922816251426433759354.3950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x70000}};
  // 7922816251426433759354
  s21_decimal decimal_check = {{0xF485787A, 0x7F29ABCA, 0x1AD, 0x0}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok74) {
  // -7922816251426433759354.3950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80070000}};
  // -7922816251426433759354
  s21_decimal decimal_check = {{0xF485787A, 0x7F29ABCA, 0x1AD, 0x80000000}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok75) {
  // 792281625142643375935.43950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000}};
  // 792281625142643375935
  s21_decimal decimal_check = {{0x1873BF3F, 0xF31DC461, 0x2A, 0x0}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok76) {
  // -792281625142643375935.43950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80080000}};
  // -792281625142643375935
  s21_decimal decimal_check = {{0x1873BF3F, 0xF31DC461, 0x2A, 0x80000000}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok77) {
  // 79228162514264337593.543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x90000}};
  // 79228162514264337593
  s21_decimal decimal_check = {{0xB5A52CB9, 0x4B82FA09, 0x4, 0x0}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok78) {
  // -79228162514264337593.543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80090000}};
  // -79228162514264337593
  s21_decimal decimal_check = {{0xB5A52CB9, 0x4B82FA09, 0x4, 0x80000000}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok79) {
  // 7922816251426433759.3543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xA0000}};
  // 7922816251426433759
  s21_decimal decimal_check = {{0x5EF6EADF, 0x6DF37F67, 0x0, 0x0}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok80) {
  // -7922816251426433759.3543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800A0000}};
  // -7922816251426433759
  s21_decimal decimal_check = {{0x5EF6EADF, 0x6DF37F67, 0x0, 0x80000000}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok81) {
  // 792281625142643375.93543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xB0000}};
  // 792281625142643375
  s21_decimal decimal_check = {{0xBCB24AAF, 0xAFEBFF0, 0x0, 0x0}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok82) {
  // -792281625142643375.93543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800B0000}};
  // -792281625142643375
  s21_decimal decimal_check = {{0xBCB24AAF, 0xAFEBFF0, 0x0, 0x80000000}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok83) {
  // 79228162514264337.593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xC0000}};
  // 79228162514264337
  s21_decimal decimal_check = {{0x12DEA111, 0x1197998, 0x0, 0x0}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok84) {
  // -79228162514264337.593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800C0000}};
  // -79228162514264337
  s21_decimal decimal_check = {{0x12DEA111, 0x1197998, 0x0, 0x80000000}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok85) {
  // 7922816251426433.7593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xD0000}};
  // 7922816251426433
  s21_decimal decimal_check = {{0x68497681, 0x1C25C2, 0x0, 0x0}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok86) {
  // -7922816251426433.7593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800D0000}};
  // -7922816251426433
  s21_decimal decimal_check = {{0x68497681, 0x1C25C2, 0x0, 0x80000000}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok87) {
  // 792281625142643.37593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xE0000}};
  // 792281625142643
  s21_decimal decimal_check = {{0x70D42573, 0x2D093, 0x0, 0x0}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok88) {
  // -792281625142643.37593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800E0000}};
  // -792281625142643
  s21_decimal decimal_check = {{0x70D42573, 0x2D093, 0x0, 0x80000000}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok89) {
  // 79228162514264.337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xF0000}};
  // 79228162514264
  s21_decimal decimal_check = {{0xBE7B9D58, 0x480E, 0x0, 0x0}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok90) {
  // -79228162514264.337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800F0000}};
  // -79228162514264
  s21_decimal decimal_check = {{0xBE7B9D58, 0x480E, 0x0, 0x80000000}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok91) {
  // 7922816251426.4337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x100000}};
  // 7922816251426
  s21_decimal decimal_check = {{0xACA5F622, 0x734, 0x0, 0x0}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok92) {
  // -7922816251426.4337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80100000}};
  // -7922816251426
  s21_decimal decimal_check = {{0xACA5F622, 0x734, 0x0, 0x80000000}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok93) {
  // 792281625142.64337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x110000}};
  // 792281625142
  s21_decimal decimal_check = {{0x77AA3236, 0xB8, 0x0, 0x0}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok94) {
  // -792281625142.64337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80110000}};
  // -792281625142
  s21_decimal decimal_check = {{0x77AA3236, 0xB8, 0x0, 0x80000000}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok95) {
  // 79228162514.264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x120000}};
  // 79228162514
  s21_decimal decimal_check = {{0x725DD1D2, 0x12, 0x0, 0x0}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok96) {
  // -79228162514.264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80120000}};
  // -79228162514
  s21_decimal decimal_check = {{0x725DD1D2, 0x12, 0x0, 0x80000000}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok97) {
  // 7922816251.4264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x130000}};
  // 7922816251
  s21_decimal decimal_check = {{0xD83C94FB, 0x1, 0x0, 0x0}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok98) {
  // -7922816251.4264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80130000}};
  // -7922816251
  s21_decimal decimal_check = {{0xD83C94FB, 0x1, 0x0, 0x80000000}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok99) {
  // 792281625.14264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  // 792281625
  s21_decimal decimal_check = {{0x2F394219, 0x0, 0x0, 0x0}};

  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}

END_TEST START_TEST(test_truncate_ok100) {
  // -792281625.14264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80140000}};
  // -792281625
  s21_decimal decimal_check = {{0x2F394219, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  test_decimal_bytes decimal_bytes_check;
  decimal_bytes_check.d = decimal_check;
  int sign_check = decimal_bytes_check.parts.sign;
  test_decimal_bytes decimal_bytes_result;
  decimal_bytes_result.d = result;
  int sign_result = decimal_bytes_result.parts.sign;
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}
END_TEST

Suite *test_truncate(void) {
  Suite *s =
      suite_create("\n\033[37;1m==========| S21_TRUNCATE |=========\033[0m");
  TCase *tc = tcase_create("tc_truncate");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_truncate_ok1);
  tcase_add_test(tc, test_truncate_ok2);
  tcase_add_test(tc, test_truncate_ok3);
  tcase_add_test(tc, test_truncate_ok4);
  tcase_add_test(tc, test_truncate_ok5);
  tcase_add_test(tc, test_truncate_ok6);
  tcase_add_test(tc, test_truncate_ok7);
  tcase_add_test(tc, test_truncate_ok8);
  tcase_add_test(tc, test_truncate_ok9);
  tcase_add_test(tc, test_truncate_ok10);
  tcase_add_test(tc, test_truncate_ok11);
  tcase_add_test(tc, test_truncate_ok12);
  tcase_add_test(tc, test_truncate_ok13);
  tcase_add_test(tc, test_truncate_ok14);
  tcase_add_test(tc, test_truncate_ok15);
  tcase_add_test(tc, test_truncate_ok16);
  tcase_add_test(tc, test_truncate_ok17);
  tcase_add_test(tc, test_truncate_ok18);
  tcase_add_test(tc, test_truncate_ok19);
  tcase_add_test(tc, test_truncate_ok20);
  tcase_add_test(tc, test_truncate_ok21);
  tcase_add_test(tc, test_truncate_ok22);
  tcase_add_test(tc, test_truncate_ok23);
  tcase_add_test(tc, test_truncate_ok24);
  tcase_add_test(tc, test_truncate_ok25);
  tcase_add_test(tc, test_truncate_ok26);
  tcase_add_test(tc, test_truncate_ok27);
  tcase_add_test(tc, test_truncate_ok28);
  tcase_add_test(tc, test_truncate_ok29);
  tcase_add_test(tc, test_truncate_ok30);
  tcase_add_test(tc, test_truncate_ok31);
  tcase_add_test(tc, test_truncate_ok32);
  tcase_add_test(tc, test_truncate_ok33);
  tcase_add_test(tc, test_truncate_ok34);
  tcase_add_test(tc, test_truncate_ok35);
  tcase_add_test(tc, test_truncate_ok36);
  tcase_add_test(tc, test_truncate_ok37);
  tcase_add_test(tc, test_truncate_ok38);
  tcase_add_test(tc, test_truncate_ok39);
  tcase_add_test(tc, test_truncate_ok40);
  tcase_add_test(tc, test_truncate_ok41);
  tcase_add_test(tc, test_truncate_ok42);
  tcase_add_test(tc, test_truncate_ok43);
  tcase_add_test(tc, test_truncate_ok44);
  tcase_add_test(tc, test_truncate_ok45);
  tcase_add_test(tc, test_truncate_ok46);
  tcase_add_test(tc, test_truncate_ok47);
  tcase_add_test(tc, test_truncate_ok48);
  tcase_add_test(tc, test_truncate_ok49);
  tcase_add_test(tc, test_truncate_ok50);
  tcase_add_test(tc, test_truncate_ok51);
  tcase_add_test(tc, test_truncate_ok52);
  tcase_add_test(tc, test_truncate_ok53);
  tcase_add_test(tc, test_truncate_ok54);
  tcase_add_test(tc, test_truncate_ok55);
  tcase_add_test(tc, test_truncate_ok56);
  tcase_add_test(tc, test_truncate_ok57);
  tcase_add_test(tc, test_truncate_ok58);
  tcase_add_test(tc, test_truncate_ok59);
  tcase_add_test(tc, test_truncate_ok60);
  tcase_add_test(tc, test_truncate_ok61);
  tcase_add_test(tc, test_truncate_ok62);
  tcase_add_test(tc, test_truncate_ok63);
  tcase_add_test(tc, test_truncate_ok64);
  tcase_add_test(tc, test_truncate_ok65);
  tcase_add_test(tc, test_truncate_ok66);
  tcase_add_test(tc, test_truncate_ok67);
  tcase_add_test(tc, test_truncate_ok68);
  tcase_add_test(tc, test_truncate_ok69);
  tcase_add_test(tc, test_truncate_ok70);
  tcase_add_test(tc, test_truncate_ok71);
  tcase_add_test(tc, test_truncate_ok72);
  tcase_add_test(tc, test_truncate_ok73);
  tcase_add_test(tc, test_truncate_ok74);
  tcase_add_test(tc, test_truncate_ok75);
  tcase_add_test(tc, test_truncate_ok76);
  tcase_add_test(tc, test_truncate_ok77);
  tcase_add_test(tc, test_truncate_ok78);
  tcase_add_test(tc, test_truncate_ok79);
  tcase_add_test(tc, test_truncate_ok80);
  tcase_add_test(tc, test_truncate_ok81);
  tcase_add_test(tc, test_truncate_ok82);
  tcase_add_test(tc, test_truncate_ok83);
  tcase_add_test(tc, test_truncate_ok84);
  tcase_add_test(tc, test_truncate_ok85);
  tcase_add_test(tc, test_truncate_ok86);
  tcase_add_test(tc, test_truncate_ok87);
  tcase_add_test(tc, test_truncate_ok88);
  tcase_add_test(tc, test_truncate_ok89);
  tcase_add_test(tc, test_truncate_ok90);
  tcase_add_test(tc, test_truncate_ok91);
  tcase_add_test(tc, test_truncate_ok92);
  tcase_add_test(tc, test_truncate_ok93);
  tcase_add_test(tc, test_truncate_ok94);
  tcase_add_test(tc, test_truncate_ok95);
  tcase_add_test(tc, test_truncate_ok96);
  tcase_add_test(tc, test_truncate_ok97);
  tcase_add_test(tc, test_truncate_ok98);
  tcase_add_test(tc, test_truncate_ok99);
  tcase_add_test(tc, test_truncate_ok100);

  return s;
}

int test_decimal_is_full_equal(s21_decimal value_1, s21_decimal value_2) {
  union {
    s21_decimal d;
    struct {
      uint32_t part0;
      uint32_t part1;
      uint32_t part2;
      uint32_t part3;
    } parts;
  } decimal_bytes1;

  union {
    s21_decimal d;
    struct {
      uint32_t part0;
      uint32_t part1;
      uint32_t part2;
      uint32_t part3;
    } parts;
  } decimal_bytes2;

  decimal_bytes1.d = value_1;
  decimal_bytes2.d = value_2;

  return decimal_bytes1.parts.part0 == decimal_bytes2.parts.part0 &&
         decimal_bytes1.parts.part1 == decimal_bytes2.parts.part1 &&
         decimal_bytes1.parts.part2 == decimal_bytes2.parts.part2 &&
         decimal_bytes1.parts.part3 == decimal_bytes2.parts.part3;
}