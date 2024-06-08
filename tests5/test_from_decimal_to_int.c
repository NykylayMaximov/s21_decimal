#include "./test.h"

START_TEST(test_from_decimal_to_int_fail_manual1) {
  // 792281625.14264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  int code = s21_from_decimal_to_int(decimal, NULL);

  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(test_from_decimal_to_int_fail_manual2) {
  // степень 154 (показатель степени должен быть от 0 до 28)
  // биты 0-15 не нули
  // биты 24-30 не нули
  s21_decimal decimal = {{0, 0, 0, 1000000000}};
  int result;
  int code = s21_from_decimal_to_int(decimal, &result);

  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(test_from_decimal_to_int_fail_manual3) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  s21_decimal decimal = {{-1, 0, 0, 0x1D0000}};
  int result;
  int code = s21_from_decimal_to_int(decimal, &result);

  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(test_from_decimal_to_int_fail_manual4) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  s21_decimal decimal = {{0, 0, 0, 0x1D0000}};
  int result;
  int code = s21_from_decimal_to_int(decimal, &result);

  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(test_from_decimal_to_int_fail_manual5) {
  // степень 28 (что корректно), но биты 0-15 не нули (младший бит)
  s21_decimal decimal = {{-1, 0, 0, 0x1C0001}};
  int result;
  int code = s21_from_decimal_to_int(decimal, &result);

  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(test_from_decimal_to_int_fail_manual6) {
  // степень 28 (что корректно), но биты 0-15 не нули (старший бит)
  s21_decimal decimal = {{-1, 0, 0, 0x1C8000}};
  int result;
  int code = s21_from_decimal_to_int(decimal, &result);

  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(test_from_decimal_to_int_fail_manual7) {
  // степень 28 (что корректно), но биты 24-30 не нули (младший бит)
  s21_decimal decimal = {{-1, 0, 0, 0x11C0000}};
  int result;
  int code = s21_from_decimal_to_int(decimal, &result);

  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(test_from_decimal_to_int_fail_manual8) {
  // степень 28 (что корректно), но биты 24-30 не нули (старший бит)
  s21_decimal decimal = {{-1, 0, 0, 0x401C0000}};
  int result;
  int code = s21_from_decimal_to_int(decimal, &result);

  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(test_from_decimal_to_int_fail_manual9) {
  // Просто все единицы
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  int result;
  int code = s21_from_decimal_to_int(decimal, &result);

  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(test_from_decimal_to_int_ok1) {
  // 792281625.14264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  int check = 792281625;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(test_from_decimal_to_int_ok2) {
  // -792281625.14264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80140000}};
  int check = -792281625;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok3) {
  // 79228162.514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x150000}};
  int check = 79228162;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok4) {
  // -79228162.514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80150000}};
  int check = -79228162;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok5) {
  // 7922816.2514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x160000}};
  int check = 7922816;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok6) {
  // -7922816.2514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80160000}};
  int check = -7922816;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok7) {
  // 792281.62514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x170000}};
  int check = 792281;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok8) {
  // -792281.62514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80170000}};
  int check = -792281;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok9) {
  // 79228.162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x180000}};
  int check = 79228;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok10) {
  // -79228.162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80180000}};
  int check = -79228;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok11) {
  // 7922.8162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x190000}};
  int check = 7922;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok12) {
  // -7922.8162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80190000}};
  int check = -7922;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok13) {
  // 792.28162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1A0000}};
  int check = 792;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok14) {
  // -792.28162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801A0000}};
  int check = -792;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok15) {
  // 79.228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1B0000}};
  int check = 79;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok16) {
  // -79.228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801B0000}};
  int check = -79;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok17) {
  // 7.9228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  int check = 7;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok18) {
  // -7.9228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  int check = -7;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok19) {
  // 792281625.14264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  int check = 792281625;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok20) {
  // -792281625.14264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80140000}};
  int check = -792281625;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok21) {
  // 79228162.514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x150000}};
  int check = 79228162;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok22) {
  // -79228162.514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80150000}};
  int check = -79228162;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok23) {
  // 7922816.2514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x160000}};
  int check = 7922816;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok24) {
  // -7922816.2514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80160000}};
  int check = -7922816;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok25) {
  // 792281.62514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x170000}};
  int check = 792281;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok26) {
  // -792281.62514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80170000}};
  int check = -792281;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok27) {
  // 79228.162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x180000}};
  int check = 79228;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok28) {
  // -79228.162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80180000}};
  int check = -79228;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok29) {
  // 7922.8162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x190000}};
  int check = 7922;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok30) {
  // -7922.8162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80190000}};
  int check = -7922;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok31) {
  // 792.28162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x1A0000}};
  int check = 792;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok32) {
  // -792.28162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x801A0000}};
  int check = -792;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok33) {
  // 79.228162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x1B0000}};
  int check = 79;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok34) {
  // -79.228162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x801B0000}};
  int check = -79;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok35) {
  // 7.9228162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  int check = 7;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok36) {
  // -7.9228162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  int check = -7;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok37) {
  // 528187750.09509558395695966890
  s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x140000}};
  int check = 528187750;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok38) {
  // -528187750.09509558395695966890
  s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80140000}};
  int check = -528187750;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok39) {
  // 5.2818775009509558395695966890
  s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x1C0000}};
  int check = 5;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok40) {
  // -5.2818775009509558395695966890
  s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x801C0000}};
  int check = -5;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok41) {
  // 528187750.09509558392832655360
  s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x140000}};
  int check = 528187750;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok42) {
  // -528187750.09509558392832655360
  s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x80140000}};
  int check = -528187750;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok43) {
  // 5.2818775009509558392832655360
  s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x1C0000}};
  int check = 5;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok44) {
  // -5.2818775009509558392832655360
  s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x801C0000}};
  int check = -5;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok45) {
  // 528187749.97211729016086244010
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x140000}};
  int check = 528187749;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok46) {
  // -528187749.97211729016086244010
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x80140000}};
  int check = -528187749;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok47) {
  // 5.2818774997211729016086244010
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x1C0000}};
  int check = 5;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok48) {
  // -5.2818774997211729016086244010
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x801C0000}};
  int check = -5;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok49) {
  // 528187749.97211729013222932480
  s21_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x140000}};
  int check = 528187749;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok50) {
  // -528187749.97211729013222932480
  s21_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x80140000}};
  int check = -528187749;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok51) {
  // 5.2818774997211729013222932480
  s21_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x1C0000}};
  int check = 5;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok52) {
  // -5.2818774997211729013222932480
  s21_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x801C0000}};
  int check = -5;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok53) {
  // 122978293.82473034410
  s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0xB0000}};
  int check = 122978293;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok54) {
  // -122978293.82473034410
  s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x800B0000}};
  int check = -122978293;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok55) {
  // 1.2297829382473034410
  s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
  int check = 1;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok56) {
  // -1.2297829382473034410
  s21_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
  int check = -1;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok57) {
  // 122978293.79609722880
  s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0xB0000}};
  int check = 122978293;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok58) {
  // -122978293.79609722880
  s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x800B0000}};
  int check = -122978293;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok59) {
  // 1.2297829379609722880
  s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x130000}};
  int check = 1;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok60) {
  // -1.2297829379609722880
  s21_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x80130000}};
  int check = -1;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok61) {
  // 286331153.0
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x10000}};
  int check = 286331153;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok62) {
  // -286331153.0
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x80010000}};
  int check = -286331153;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok63) {
  // 286331.1530
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x40000}};
  int check = 286331;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok64) {
  // -286331.1530
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x80040000}};
  int check = -286331;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok65) {
  // 2.863311530
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x90000}};
  int check = 2;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok66) {
  // -2.863311530
  s21_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x80090000}};
  int check = -2;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok67) {
  // 264093875.04754779197847983445
  s21_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x140000}};
  int check = 264093875;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok68) {
  // -264093875.04754779197847983445
  s21_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x80140000}};
  int check = -264093875;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok69) {
  // 2.6409387504754779197847983445
  s21_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x1C0000}};
  int check = 2;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok70) {
  // -2.6409387504754779197847983445
  s21_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x801C0000}};
  int check = -2;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok71) {
  // 264093875.04754779196416327680
  s21_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x140000}};
  int check = 264093875;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok72) {
  // -264093875.04754779196416327680
  s21_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x80140000}};
  int check = -264093875;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok73) {
  // 2.6409387504754779196416327680
  s21_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x1C0000}};
  int check = 2;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok74) {
  // -2.6409387504754779196416327680
  s21_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x801C0000}};
  int check = -2;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok75) {
  // 264093874.98605864508043122005
  s21_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x140000}};
  int check = 264093874;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok76) {
  // -264093874.98605864508043122005
  s21_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x80140000}};
  int check = -264093874;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok77) {
  // 2.6409387498605864508043122005
  s21_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x1C0000}};
  int check = 2;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok78) {
  // -2.6409387498605864508043122005
  s21_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x801C0000}};
  int check = -2;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok79) {
  // 264093874.98605864506611466240
  s21_decimal decimal = {{0x0, 0x0, 0x55555555, 0x140000}};
  int check = 264093874;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok80) {
  // -264093874.98605864506611466240
  s21_decimal decimal = {{0x0, 0x0, 0x55555555, 0x80140000}};
  int check = -264093874;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok81) {
  // 2.6409387498605864506611466240
  s21_decimal decimal = {{0x0, 0x0, 0x55555555, 0x1C0000}};
  int check = 2;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok82) {
  // -2.6409387498605864506611466240
  s21_decimal decimal = {{0x0, 0x0, 0x55555555, 0x801C0000}};
  int check = -2;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok83) {
  // 6148914.691236517205
  s21_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0xC0000}};
  int check = 6148914;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok84) {
  // -6148914.691236517205
  s21_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0x800C0000}};
  int check = -6148914;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok85) {
  // 6.148914691236517205
  s21_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0x120000}};
  int check = 6;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok86) {
  // -6.148914691236517205
  s21_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0x80120000}};
  int check = -6;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok87) {
  // 6148914.689804861440
  s21_decimal decimal = {{0x0, 0x55555555, 0x0, 0xC0000}};
  int check = 6148914;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok88) {
  // -6148914.689804861440
  s21_decimal decimal = {{0x0, 0x55555555, 0x0, 0x800C0000}};
  int check = -6148914;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok89) {
  // 6.148914689804861440
  s21_decimal decimal = {{0x0, 0x55555555, 0x0, 0x120000}};
  int check = 6;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok90) {
  // -6.148914689804861440
  s21_decimal decimal = {{0x0, 0x55555555, 0x0, 0x80120000}};
  int check = -6;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok91) {
  // 1431655765
  s21_decimal decimal = {{0x55555555, 0x0, 0x0, 0x0}};
  int check = 1431655765;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok92) {
  // -1431655765
  s21_decimal decimal = {{0x55555555, 0x0, 0x0, 0x80000000}};
  int check = -1431655765;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok93) {
  // 143165576.5
  s21_decimal decimal = {{0x55555555, 0x0, 0x0, 0x10000}};
  int check = 143165576;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok94) {
  // -143165576.5
  s21_decimal decimal = {{0x55555555, 0x0, 0x0, 0x80010000}};
  int check = -143165576;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok95) {
  // 143165.5765
  s21_decimal decimal = {{0x55555555, 0x0, 0x0, 0x40000}};
  int check = 143165;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok96) {
  // -143165.5765
  s21_decimal decimal = {{0x55555555, 0x0, 0x0, 0x80040000}};
  int check = -143165;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok97) {
  // 1.431655765
  s21_decimal decimal = {{0x55555555, 0x0, 0x0, 0x90000}};
  int check = 1;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok98) {
  // -1.431655765
  s21_decimal decimal = {{0x55555555, 0x0, 0x0, 0x80090000}};
  int check = -1;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok99) {
  // 184467440.78004518913
  s21_decimal decimal = {{0x1, 0x1, 0x1, 0xB0000}};
  int check = 184467440;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_int_ok100) {
  // -184467440.78004518913
  s21_decimal decimal = {{0x1, 0x1, 0x1, 0x800B0000}};
  int check = -184467440;

  int result;
  int code = s21_from_decimal_to_int(decimal, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}

Suite *test_from_decimal_to_int(void) {
  Suite *s = suite_create(
      "\n\033[37;1m==========| S21_FROM_DECIMAL_TO_INT |=========\033[0m");
  TCase *tc = tcase_create("tc_from_decimal_to_int");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_from_decimal_to_int_fail_manual1);
  tcase_add_test(tc, test_from_decimal_to_int_fail_manual2);
  tcase_add_test(tc, test_from_decimal_to_int_fail_manual3);
  tcase_add_test(tc, test_from_decimal_to_int_fail_manual4);
  tcase_add_test(tc, test_from_decimal_to_int_fail_manual5);
  tcase_add_test(tc, test_from_decimal_to_int_fail_manual6);
  tcase_add_test(tc, test_from_decimal_to_int_fail_manual7);
  tcase_add_test(tc, test_from_decimal_to_int_fail_manual8);
  tcase_add_test(tc, test_from_decimal_to_int_fail_manual9);
  tcase_add_test(tc, test_from_decimal_to_int_ok1);
  tcase_add_test(tc, test_from_decimal_to_int_ok2);
  tcase_add_test(tc, test_from_decimal_to_int_ok3);
  tcase_add_test(tc, test_from_decimal_to_int_ok4);
  tcase_add_test(tc, test_from_decimal_to_int_ok5);
  tcase_add_test(tc, test_from_decimal_to_int_ok6);
  tcase_add_test(tc, test_from_decimal_to_int_ok7);
  tcase_add_test(tc, test_from_decimal_to_int_ok8);
  tcase_add_test(tc, test_from_decimal_to_int_ok9);
  tcase_add_test(tc, test_from_decimal_to_int_ok10);
  tcase_add_test(tc, test_from_decimal_to_int_ok11);
  tcase_add_test(tc, test_from_decimal_to_int_ok12);
  tcase_add_test(tc, test_from_decimal_to_int_ok13);
  tcase_add_test(tc, test_from_decimal_to_int_ok14);
  tcase_add_test(tc, test_from_decimal_to_int_ok15);
  tcase_add_test(tc, test_from_decimal_to_int_ok16);
  tcase_add_test(tc, test_from_decimal_to_int_ok17);
  tcase_add_test(tc, test_from_decimal_to_int_ok18);
  tcase_add_test(tc, test_from_decimal_to_int_ok19);
  tcase_add_test(tc, test_from_decimal_to_int_ok20);
  tcase_add_test(tc, test_from_decimal_to_int_ok21);
  tcase_add_test(tc, test_from_decimal_to_int_ok22);
  tcase_add_test(tc, test_from_decimal_to_int_ok23);
  tcase_add_test(tc, test_from_decimal_to_int_ok24);
  tcase_add_test(tc, test_from_decimal_to_int_ok25);
  tcase_add_test(tc, test_from_decimal_to_int_ok26);
  tcase_add_test(tc, test_from_decimal_to_int_ok27);
  tcase_add_test(tc, test_from_decimal_to_int_ok28);
  tcase_add_test(tc, test_from_decimal_to_int_ok29);
  tcase_add_test(tc, test_from_decimal_to_int_ok30);
  tcase_add_test(tc, test_from_decimal_to_int_ok31);
  tcase_add_test(tc, test_from_decimal_to_int_ok32);
  tcase_add_test(tc, test_from_decimal_to_int_ok33);
  tcase_add_test(tc, test_from_decimal_to_int_ok34);
  tcase_add_test(tc, test_from_decimal_to_int_ok35);
  tcase_add_test(tc, test_from_decimal_to_int_ok36);
  tcase_add_test(tc, test_from_decimal_to_int_ok37);
  tcase_add_test(tc, test_from_decimal_to_int_ok38);
  tcase_add_test(tc, test_from_decimal_to_int_ok39);
  tcase_add_test(tc, test_from_decimal_to_int_ok40);
  tcase_add_test(tc, test_from_decimal_to_int_ok41);
  tcase_add_test(tc, test_from_decimal_to_int_ok42);
  tcase_add_test(tc, test_from_decimal_to_int_ok43);
  tcase_add_test(tc, test_from_decimal_to_int_ok44);
  tcase_add_test(tc, test_from_decimal_to_int_ok45);
  tcase_add_test(tc, test_from_decimal_to_int_ok46);
  tcase_add_test(tc, test_from_decimal_to_int_ok47);
  tcase_add_test(tc, test_from_decimal_to_int_ok48);
  tcase_add_test(tc, test_from_decimal_to_int_ok49);
  tcase_add_test(tc, test_from_decimal_to_int_ok50);
  tcase_add_test(tc, test_from_decimal_to_int_ok51);
  tcase_add_test(tc, test_from_decimal_to_int_ok52);
  tcase_add_test(tc, test_from_decimal_to_int_ok53);
  tcase_add_test(tc, test_from_decimal_to_int_ok54);
  tcase_add_test(tc, test_from_decimal_to_int_ok55);
  tcase_add_test(tc, test_from_decimal_to_int_ok56);
  tcase_add_test(tc, test_from_decimal_to_int_ok57);
  tcase_add_test(tc, test_from_decimal_to_int_ok58);
  tcase_add_test(tc, test_from_decimal_to_int_ok59);
  tcase_add_test(tc, test_from_decimal_to_int_ok60);
  tcase_add_test(tc, test_from_decimal_to_int_ok61);
  tcase_add_test(tc, test_from_decimal_to_int_ok62);
  tcase_add_test(tc, test_from_decimal_to_int_ok63);
  tcase_add_test(tc, test_from_decimal_to_int_ok64);
  tcase_add_test(tc, test_from_decimal_to_int_ok65);
  tcase_add_test(tc, test_from_decimal_to_int_ok66);
  tcase_add_test(tc, test_from_decimal_to_int_ok67);
  tcase_add_test(tc, test_from_decimal_to_int_ok68);
  tcase_add_test(tc, test_from_decimal_to_int_ok69);
  tcase_add_test(tc, test_from_decimal_to_int_ok70);
  tcase_add_test(tc, test_from_decimal_to_int_ok71);
  tcase_add_test(tc, test_from_decimal_to_int_ok72);
  tcase_add_test(tc, test_from_decimal_to_int_ok73);
  tcase_add_test(tc, test_from_decimal_to_int_ok74);
  tcase_add_test(tc, test_from_decimal_to_int_ok75);
  tcase_add_test(tc, test_from_decimal_to_int_ok76);
  tcase_add_test(tc, test_from_decimal_to_int_ok77);
  tcase_add_test(tc, test_from_decimal_to_int_ok78);
  tcase_add_test(tc, test_from_decimal_to_int_ok79);
  tcase_add_test(tc, test_from_decimal_to_int_ok80);
  tcase_add_test(tc, test_from_decimal_to_int_ok81);
  tcase_add_test(tc, test_from_decimal_to_int_ok82);
  tcase_add_test(tc, test_from_decimal_to_int_ok83);
  tcase_add_test(tc, test_from_decimal_to_int_ok84);
  tcase_add_test(tc, test_from_decimal_to_int_ok85);
  tcase_add_test(tc, test_from_decimal_to_int_ok86);
  tcase_add_test(tc, test_from_decimal_to_int_ok87);
  tcase_add_test(tc, test_from_decimal_to_int_ok88);
  tcase_add_test(tc, test_from_decimal_to_int_ok89);
  tcase_add_test(tc, test_from_decimal_to_int_ok90);
  tcase_add_test(tc, test_from_decimal_to_int_ok91);
  tcase_add_test(tc, test_from_decimal_to_int_ok92);
  tcase_add_test(tc, test_from_decimal_to_int_ok93);
  tcase_add_test(tc, test_from_decimal_to_int_ok94);
  tcase_add_test(tc, test_from_decimal_to_int_ok95);
  tcase_add_test(tc, test_from_decimal_to_int_ok96);
  tcase_add_test(tc, test_from_decimal_to_int_ok97);
  tcase_add_test(tc, test_from_decimal_to_int_ok98);
  tcase_add_test(tc, test_from_decimal_to_int_ok99);
  tcase_add_test(tc, test_from_decimal_to_int_ok100);

  return s;
}