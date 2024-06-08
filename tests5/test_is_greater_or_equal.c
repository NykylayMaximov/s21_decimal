#include "./test.h"

START_TEST(test_is_greater_or_equal_ok1) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok2) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok3) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = 1;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok4) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 0;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok5) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 52818775009509558395695966890
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  int check = 1;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok6) {
  // 52818775009509558395695966890
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 0;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok7) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -52818775009509558395695966890
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  int check = 1;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok8) {
  // -52818775009509558395695966890
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 0;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok9) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 52818775009509558395695966891
  s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  int check = 1;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok10) {
  // 52818775009509558395695966891
  s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 0;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok11) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -52818775009509558395695966891
  s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  int check = 1;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok12) {
  // -52818775009509558395695966891
  s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 0;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok13) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 5.281877500950955839569596690
  s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
  int check = 1;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok14) {
  // 5.281877500950955839569596690
  s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 0;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok15) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -5.281877500950955839569596690
  s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
  int check = 1;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok16) {
  // -5.281877500950955839569596690
  s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 0;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok17) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 5281877500950955839569596689
  s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
  int check = 1;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok18) {
  // 5281877500950955839569596689
  s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 0;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok19) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -5281877500950955839569596689
  s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
  int check = 1;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok20) {
  // -5281877500950955839569596689
  s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 0;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok21) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 5281877500950955839569596689.0
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
  int check = 1;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok22) {
  // 5281877500950955839569596689.0
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 0;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok23) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -5281877500950955839569596689.0
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
  int check = 1;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok24) {
  // -5281877500950955839569596689.0
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 0;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok25) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7922816251426433759354395033
  s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  int check = 1;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok26) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 0;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok27) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7922816251426433759354395033
  s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  int check = 1;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok28) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 0;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok29) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
  int check = 1;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok30) {
  // 7922816251426433759354395034
  s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 0;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok31) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
  int check = 1;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok32) {
  // -7922816251426433759354395034
  s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 0;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok33) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.2297829382473034409
  s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
  int check = 1;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok34) {
  // 1.2297829382473034409
  s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 0;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok35) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.2297829382473034409
  s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
  int check = 1;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok36) {
  // -1.2297829382473034409
  s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 0;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok37) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.2297829382473034410
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
  int check = 1;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok38) {
  // 1.2297829382473034410
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 0;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok39) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.2297829382473034410
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
  int check = 1;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok40) {
  // -1.2297829382473034410
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 0;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok41) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.2297829382473034411
  s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
  int check = 1;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok42) {
  // 1.2297829382473034411
  s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 0;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok43) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.2297829382473034411
  s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
  int check = 1;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok44) {
  // -1.2297829382473034411
  s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 0;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok45) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
  int check = 1;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok46) {
  // 1
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 0;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok47) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
  int check = 1;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok48) {
  // -1
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 0;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok49) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.0
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x10000}};
  int check = 1;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok50) {
  // 1.0
  s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x10000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 0;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok51) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.0
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80010000}};
  int check = 1;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok52) {
  // -1.0
  s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x80010000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 0;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok53) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.22
  s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x20000}};
  int check = 1;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok54) {
  // 1.22
  s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x20000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 0;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok55) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.22
  s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x80020000}};
  int check = 1;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok56) {
  // -1.22
  s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x80020000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 0;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok57) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.230001
  s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
  int check = 1;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok58) {
  // 1.230001
  s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 0;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok59) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.230001
  s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
  int check = 1;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok60) {
  // -1.230001
  s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 0;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok61) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.23000
  s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x50000}};
  int check = 1;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok62) {
  // 1.23000
  s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x50000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 0;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok63) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.23000
  s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x80050000}};
  int check = 1;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok64) {
  // -1.23000
  s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x80050000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 0;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok65) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
  int check = 1;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok66) {
  // 1431655765
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 0;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok67) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  int check = 1;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok68) {
  // -1431655765
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 0;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok69) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1431655765.00000
  s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
  int check = 1;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok70) {
  // 1431655765.00000
  s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 0;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok71) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1431655765.00000
  s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
  int check = 1;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok72) {
  // -1431655765.00000
  s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 0;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok73) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1431655765.000000000000000001
  s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
  int check = 1;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok74) {
  // 1431655765.000000000000000001
  s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 0;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok75) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1431655765.000000000000000001
  s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
  int check = 1;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok76) {
  // -1431655765.000000000000000001
  s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 0;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok77) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1431655764.999999999999999999
  s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
  int check = 1;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok78) {
  // 1431655764.999999999999999999
  s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 0;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok79) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1431655764.999999999999999999
  s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
  int check = 1;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok80) {
  // -1431655764.999999999999999999
  s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 0;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok81) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  int check = 1;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok82) {
  // 0.9999999999999999999999999999
  s21_decimal decimal1 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 0;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok83) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  int check = 1;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok84) {
  // -0.9999999999999999999999999999
  s21_decimal decimal1 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 0;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok85) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  int check = 1;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok86) {
  // 0.0000000000000000000000000001
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 0;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok87) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
  int check = 1;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok88) {
  // -0.0000000000000000000000000001
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x801C0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 0;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok89) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  int check = 1;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok90) {
  // 0
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 0;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok91) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  int check = 1;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok92) {
  // -0
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 0;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok93) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.00000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x800E0000}};
  int check = 1;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok94) {
  // -0.00000000000000
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x800E0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 0;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok95) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.00000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0xE0000}};
  int check = 1;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok96) {
  // 0.00000000000000
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0xE0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 0;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok97) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
  int check = 1;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok98) {
  // -0.0000000000000000000000000000
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x801C0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 0;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok99) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x1C0000}};
  int check = 1;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

END_TEST START_TEST(test_is_greater_or_equal_ok100) {
  // 0.0000000000000000000000000000
  s21_decimal decimal1 = {{0x0, 0x0, 0x0, 0x1C0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 0;

  int code = s21_is_greater_or_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

Suite *test_is_greater_or_equal(void) {
  Suite *s = suite_create(
      "\n\033[37;1m==========| S21_IS_GREATER_OR_EQUAL |=========\033[0m");
  TCase *tc = tcase_create("tc_is_greater_or_equal");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_is_greater_or_equal_ok1);
  tcase_add_test(tc, test_is_greater_or_equal_ok2);
  tcase_add_test(tc, test_is_greater_or_equal_ok3);
  tcase_add_test(tc, test_is_greater_or_equal_ok4);
  tcase_add_test(tc, test_is_greater_or_equal_ok5);
  tcase_add_test(tc, test_is_greater_or_equal_ok6);
  tcase_add_test(tc, test_is_greater_or_equal_ok7);
  tcase_add_test(tc, test_is_greater_or_equal_ok8);
  tcase_add_test(tc, test_is_greater_or_equal_ok9);
  tcase_add_test(tc, test_is_greater_or_equal_ok10);
  tcase_add_test(tc, test_is_greater_or_equal_ok11);
  tcase_add_test(tc, test_is_greater_or_equal_ok12);
  tcase_add_test(tc, test_is_greater_or_equal_ok13);
  tcase_add_test(tc, test_is_greater_or_equal_ok14);
  tcase_add_test(tc, test_is_greater_or_equal_ok15);
  tcase_add_test(tc, test_is_greater_or_equal_ok16);
  tcase_add_test(tc, test_is_greater_or_equal_ok17);
  tcase_add_test(tc, test_is_greater_or_equal_ok18);
  tcase_add_test(tc, test_is_greater_or_equal_ok19);
  tcase_add_test(tc, test_is_greater_or_equal_ok20);
  tcase_add_test(tc, test_is_greater_or_equal_ok21);
  tcase_add_test(tc, test_is_greater_or_equal_ok22);
  tcase_add_test(tc, test_is_greater_or_equal_ok23);
  tcase_add_test(tc, test_is_greater_or_equal_ok24);
  tcase_add_test(tc, test_is_greater_or_equal_ok25);
  tcase_add_test(tc, test_is_greater_or_equal_ok26);
  tcase_add_test(tc, test_is_greater_or_equal_ok27);
  tcase_add_test(tc, test_is_greater_or_equal_ok28);
  tcase_add_test(tc, test_is_greater_or_equal_ok29);
  tcase_add_test(tc, test_is_greater_or_equal_ok30);
  tcase_add_test(tc, test_is_greater_or_equal_ok31);
  tcase_add_test(tc, test_is_greater_or_equal_ok32);
  tcase_add_test(tc, test_is_greater_or_equal_ok33);
  tcase_add_test(tc, test_is_greater_or_equal_ok34);
  tcase_add_test(tc, test_is_greater_or_equal_ok35);
  tcase_add_test(tc, test_is_greater_or_equal_ok36);
  tcase_add_test(tc, test_is_greater_or_equal_ok37);
  tcase_add_test(tc, test_is_greater_or_equal_ok38);
  tcase_add_test(tc, test_is_greater_or_equal_ok39);
  tcase_add_test(tc, test_is_greater_or_equal_ok40);
  tcase_add_test(tc, test_is_greater_or_equal_ok41);
  tcase_add_test(tc, test_is_greater_or_equal_ok42);
  tcase_add_test(tc, test_is_greater_or_equal_ok43);
  tcase_add_test(tc, test_is_greater_or_equal_ok44);
  tcase_add_test(tc, test_is_greater_or_equal_ok45);
  tcase_add_test(tc, test_is_greater_or_equal_ok46);
  tcase_add_test(tc, test_is_greater_or_equal_ok47);
  tcase_add_test(tc, test_is_greater_or_equal_ok48);
  tcase_add_test(tc, test_is_greater_or_equal_ok49);
  tcase_add_test(tc, test_is_greater_or_equal_ok50);
  tcase_add_test(tc, test_is_greater_or_equal_ok51);
  tcase_add_test(tc, test_is_greater_or_equal_ok52);
  tcase_add_test(tc, test_is_greater_or_equal_ok53);
  tcase_add_test(tc, test_is_greater_or_equal_ok54);
  tcase_add_test(tc, test_is_greater_or_equal_ok55);
  tcase_add_test(tc, test_is_greater_or_equal_ok56);
  tcase_add_test(tc, test_is_greater_or_equal_ok57);
  tcase_add_test(tc, test_is_greater_or_equal_ok58);
  tcase_add_test(tc, test_is_greater_or_equal_ok59);
  tcase_add_test(tc, test_is_greater_or_equal_ok60);
  tcase_add_test(tc, test_is_greater_or_equal_ok61);
  tcase_add_test(tc, test_is_greater_or_equal_ok62);
  tcase_add_test(tc, test_is_greater_or_equal_ok63);
  tcase_add_test(tc, test_is_greater_or_equal_ok64);
  tcase_add_test(tc, test_is_greater_or_equal_ok65);
  tcase_add_test(tc, test_is_greater_or_equal_ok66);
  tcase_add_test(tc, test_is_greater_or_equal_ok67);
  tcase_add_test(tc, test_is_greater_or_equal_ok68);
  tcase_add_test(tc, test_is_greater_or_equal_ok69);
  tcase_add_test(tc, test_is_greater_or_equal_ok70);
  tcase_add_test(tc, test_is_greater_or_equal_ok71);
  tcase_add_test(tc, test_is_greater_or_equal_ok72);
  tcase_add_test(tc, test_is_greater_or_equal_ok73);
  tcase_add_test(tc, test_is_greater_or_equal_ok74);
  tcase_add_test(tc, test_is_greater_or_equal_ok75);
  tcase_add_test(tc, test_is_greater_or_equal_ok76);
  tcase_add_test(tc, test_is_greater_or_equal_ok77);
  tcase_add_test(tc, test_is_greater_or_equal_ok78);
  tcase_add_test(tc, test_is_greater_or_equal_ok79);
  tcase_add_test(tc, test_is_greater_or_equal_ok80);
  tcase_add_test(tc, test_is_greater_or_equal_ok81);
  tcase_add_test(tc, test_is_greater_or_equal_ok82);
  tcase_add_test(tc, test_is_greater_or_equal_ok83);
  tcase_add_test(tc, test_is_greater_or_equal_ok84);
  tcase_add_test(tc, test_is_greater_or_equal_ok85);
  tcase_add_test(tc, test_is_greater_or_equal_ok86);
  tcase_add_test(tc, test_is_greater_or_equal_ok87);
  tcase_add_test(tc, test_is_greater_or_equal_ok88);
  tcase_add_test(tc, test_is_greater_or_equal_ok89);
  tcase_add_test(tc, test_is_greater_or_equal_ok90);
  tcase_add_test(tc, test_is_greater_or_equal_ok91);
  tcase_add_test(tc, test_is_greater_or_equal_ok92);
  tcase_add_test(tc, test_is_greater_or_equal_ok93);
  tcase_add_test(tc, test_is_greater_or_equal_ok94);
  tcase_add_test(tc, test_is_greater_or_equal_ok95);
  tcase_add_test(tc, test_is_greater_or_equal_ok96);
  tcase_add_test(tc, test_is_greater_or_equal_ok97);
  tcase_add_test(tc, test_is_greater_or_equal_ok98);
  tcase_add_test(tc, test_is_greater_or_equal_ok99);
  tcase_add_test(tc, test_is_greater_or_equal_ok100);

  return s;
}