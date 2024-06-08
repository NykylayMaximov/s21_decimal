#include "./test.h"

START_TEST(test_from_decimal_to_float_fail_manual1) {
  // 792281625.14264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  int code = s21_from_decimal_to_float(decimal, NULL);

  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(test_from_decimal_to_float_fail_manual2) {
  // степень 154 (показатель степени должен быть от 0 до 28)
  // биты 0-15 не нули
  // биты 24-30 не нули
  s21_decimal decimal = {{0, 0, 0, 1000000000}};
  float result;
  int code = s21_from_decimal_to_float(decimal, &result);

  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(test_from_decimal_to_float_fail_manual3) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  s21_decimal decimal = {{-1, 0, 0, 0x1D0000}};
  float result;
  int code = s21_from_decimal_to_float(decimal, &result);

  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(test_from_decimal_to_float_fail_manual4) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  s21_decimal decimal = {{0, 0, 0, 0x1D0000}};
  float result;
  int code = s21_from_decimal_to_float(decimal, &result);

  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(test_from_decimal_to_float_fail_manual5) {
  // степень 28 (что корректно), но биты 0-15 не нули (младший бит)
  s21_decimal decimal = {{-1, 0, 0, 0x1C0001}};
  float result;
  int code = s21_from_decimal_to_float(decimal, &result);

  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(test_from_decimal_to_float_fail_manual6) {
  // степень 28 (что корректно), но биты 0-15 не нули (старший бит)
  s21_decimal decimal = {{-1, 0, 0, 0x1C8000}};
  float result;
  int code = s21_from_decimal_to_float(decimal, &result);

  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(test_from_decimal_to_float_fail_manual7) {
  // степень 28 (что корректно), но биты 24-30 не нули (младший бит)
  s21_decimal decimal = {{-1, 0, 0, 0x11C0000}};
  float result;
  int code = s21_from_decimal_to_float(decimal, &result);

  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(test_from_decimal_to_float_fail_manual8) {
  // степень 28 (что корректно), но биты 24-30 не нули (старший бит)
  s21_decimal decimal = {{-1, 0, 0, 0x401C0000}};
  float result;
  int code = s21_from_decimal_to_float(decimal, &result);

  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(test_from_decimal_to_float_fail_manual9) {
  // Просто все единицы
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  float result;
  int code = s21_from_decimal_to_float(decimal, &result);

  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(test_from_decimal_to_float_ok1) {
  // 79228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1870659584;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok2) {
  // -79228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = -276824064;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok3) {
  // 7922816251426433759354395033.5
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  int check = 1842138317;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok4) {
  // -7922816251426433759354395033.5
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  int check = -305345331;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok5) {
  // 20995463066280049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x0}};
  int check = 1854385684;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok6) {
  // -20995463066280049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80000000}};
  int check = -293097964;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok7) {
  // 792281625142643375935439503.35
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};
  int check = 1814288138;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok8) {
  // -792281625142643375935439503.35
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80020000}};
  int check = -333195510;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok9) {
  // 2099546306628004946228914683.9
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x10000}};
  int check = 1826166407;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok10) {
  // -2099546306628004946228914683.9
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80010000}};
  int check = -321317241;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok11) {
  // 79228162514264337593543950.335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x30000}};
  int check = 1786974831;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok12) {
  // -79228162514264337593543950.335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80030000}};
  int check = -360508817;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok13) {
  // 209954630662800494622891468.39
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x20000}};
  int check = 1798155167;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok14) {
  // -209954630662800494622891468.39
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80020000}};
  int check = -349328481;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok15) {
  // 7922816251426433759354395.0335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x40000}};
  int check = 1758574359;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok16) {
  // -7922816251426433759354395.0335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80040000}};
  int check = -388909289;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok17) {
  // 20995463066280049462289146.839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x30000}};
  int check = 1770713011;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok18) {
  // -20995463066280049462289146.839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80030000}};
  int check = -376770637;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok19) {
  // 792281625142643375935439.50335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x50000}};
  int check = 1730659756;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok20) {
  // -792281625142643375935439.50335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80050000}};
  int check = -416823892;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok21) {
  // 2099546306628004946228914.6839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x40000}};
  int check = 1742621777;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok22) {
  // -2099546306628004946228914.6839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80040000}};
  int check = -404861871;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok23) {
  // 79228162514264337593543.950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x60000}};
  int check = 1703294909;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok24) {
  // -79228162514264337593543.950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80060000}};
  int check = -444188739;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok25) {
  // 209954630662800494622891.46839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x50000}};
  int check = 1714542247;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok26) {
  // -209954630662800494622891.46839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80050000}};
  int check = -432941401;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok27) {
  // 7922816251426433759354.3950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x70000}};
  int check = 1675018133;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok28) {
  // -7922816251426433759354.3950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80070000}};
  int check = -472465515;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok29) {
  // 20995463066280049462289.146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x60000}};
  int check = 1687045459;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok30) {
  // -20995463066280049462289.146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80060000}};
  int check = -460438189;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok31) {
  // 792281625142643375935.43950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000}};
  int check = 1647037559;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok32) {
  // -792281625142643375935.43950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80080000}};
  int check = -500446089;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok33) {
  // 2099546306628004946228.9146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x70000}};
  int check = 1659085342;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok34) {
  // -2099546306628004946228.9146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80070000}};
  int check = -488398306;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok35) {
  // 79228162514264337593.543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x90000}};
  int check = 1619619935;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok36) {
  // -79228162514264337593.543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80090000}};
  int check = -527863713;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok37) {
  // 209954630662800494622.89146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80000}};
  int check = 1630935883;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok38) {
  // -209954630662800494622.89146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80080000}};
  int check = -516547765;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok39) {
  // 7922816251426433759.3543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xA0000}};
  int check = 1591469823;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok40) {
  // -7922816251426433759.3543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800A0000}};
  int check = -556013825;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok41) {
  // 20995463066280049462.289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x90000}};
  int check = 1603383151;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok42) {
  // -20995463066280049462.289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80090000}};
  int check = -544100497;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok43) {
  // 792281625142643375.93543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xB0000}};
  int check = 1563421695;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok44) {
  // -792281625142643375.93543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800B0000}};
  int check = -584061953;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok45) {
  // 2099546306628004946.2289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0xA0000}};
  int check = 1575557298;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok46) {
  // -2099546306628004946.2289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x800A0000}};
  int check = -571926350;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok47) {
  // 79228162514264337.593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xC0000}};
  int check = 1535950028;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok48) {
  // -79228162514264337.593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800C0000}};
  int check = -611533620;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok49) {
  // 209954630662800494.62289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0xB0000}};
  int check = 1547336232;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok50) {
  // -209954630662800494.62289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x800B0000}};
  int check = -600147416;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok51) {
  // 7922816251426433.7593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xD0000}};
  int check = 1507929619;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok52) {
  // -7922816251426433.7593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800D0000}};
  int check = -639554029;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok53) {
  // 20995463066280049.462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0xC0000}};
  int check = 1519726214;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok54) {
  // -20995463066280049.462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x800C0000}};
  int check = -627757434;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok55) {
  // 792281625142643.37593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xE0000}};
  int check = 1479812316;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok56) {
  // -792281625142643.37593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800E0000}};
  int check = -667671332;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok57) {
  // 2099546306628004.9462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0xD0000}};
  int check = 1492037847;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok58) {
  // -2099546306628004.9462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x800D0000}};
  int check = -655445801;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok59) {
  // 79228162514264.337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xF0000}};
  int check = 1452285309;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok60) {
  // -79228162514264.337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800F0000}};
  int check = -695198339;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok61) {
  // 209954630662800.49462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0xE0000}};
  int check = 1463743455;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok62) {
  // -209954630662800.49462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x800E0000}};
  int check = -683740193;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok63) {
  // 7922816251426.4337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x100000}};
  int check = 1424397717;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok64) {
  // -7922816251426.4337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80100000}};
  int check = -723085931;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok65) {
  // 20995463066280.049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0xF0000}};
  int check = 1436074777;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok66) {
  // -20995463066280.049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x800F0000}};
  int check = -711408871;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok67) {
  // 792281625142.64337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x110000}};
  int check = 1396209578;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok68) {
  // -792281625142.64337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80110000}};
  int check = -751274070;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok69) {
  // 2099546306628.0049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x100000}};
  int check = 1408527195;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok70) {
  // -2099546306628.0049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80100000}};
  int check = -738956453;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok71) {
  // 79228162514.264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x120000}};
  int check = 1368625903;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok72) {
  // -79228162514.264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80120000}};
  int check = -778857745;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok73) {
  // 209954630662.80049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x110000}};
  int check = 1380157718;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok74) {
  // -209954630662.80049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80110000}};
  int check = -767325930;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok75) {
  // 7922816251.4264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x130000}};
  int check = 1340874314;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok76) {
  // -7922816251.4264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80130000}};
  int check = -806609334;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok77) {
  // 20995463066.280049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x120000}};
  int check = 1352428971;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok78) {
  // -20995463066.280049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80120000}};
  int check = -795054677;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok79) {
  // 792281625.14264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  int check = 1312613640;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok80) {
  // -792281625.14264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80140000}};
  int check = -834870008;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok81) {
  // 2099546306.6280049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x130000}};
  int check = 1325025554;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok82) {
  // -2099546306.6280049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80130000}};
  int check = -822458094;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok83) {
  // 79228162.514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x150000}};
  int check = 1284971936;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok84) {
  // -79228162.514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80150000}};
  int check = -862511712;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok85) {
  // 209954630.66280049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x140000}};
  int check = 1296579188;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok86) {
  // -209954630.66280049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80140000}};
  int check = -850904460;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok87) {
  // 7922816.2514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x160000}};
  int check = 1257359617;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok88) {
  // -7922816.2514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80160000}};
  int check = -890124031;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok89) {
  // 20995463.066280049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x150000}};
  int check = 1268788932;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok90) {
  // -20995463.066280049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80150000}};
  int check = -878694716;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok91) {
  // 792281.62514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x170000}};
  int check = 1229024666;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok92) {
  // -792281.62514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80170000}};
  int check = -918458982;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok93) {
  // 2099546.3066280049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x160000}};
  int check = 1241523561;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok94) {
  // -2099546.3066280049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80160000}};
  int check = -905960087;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok95) {
  // 79228.162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x180000}};
  int check = 1201323541;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok96) {
  // -79228.162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80180000}};
  int check = -946160107;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok97) {
  // 209954.63066280049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x170000}};
  int check = 1213008040;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok98) {
  // -209954.63066280049462289146839
  s21_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80170000}};
  int check = -934475608;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok99) {
  // 7922.8162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x190000}};
  int check = 1173853832;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST START_TEST(test_from_decimal_to_float_ok100) {
  // -7922.8162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80190000}};
  int check = -973629816;

  float result;
  int code = s21_from_decimal_to_float(decimal, &result);
  float_cast_test cast_result;
  cast_result.f = result;
  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, 0);
}

END_TEST

Suite *test_from_decimal_to_float(void) {
  Suite *s = suite_create(
      "\n\033[37;1m==========| S21_FROM_DECIMAL_TO_FLOAT |=========\033[0m");
  TCase *tc = tcase_create("tc_from_decimal_to_float");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_from_decimal_to_float_fail_manual1);
  tcase_add_test(tc, test_from_decimal_to_float_fail_manual2);
  tcase_add_test(tc, test_from_decimal_to_float_fail_manual3);
  tcase_add_test(tc, test_from_decimal_to_float_fail_manual4);
  tcase_add_test(tc, test_from_decimal_to_float_fail_manual5);
  tcase_add_test(tc, test_from_decimal_to_float_fail_manual6);
  tcase_add_test(tc, test_from_decimal_to_float_fail_manual7);
  tcase_add_test(tc, test_from_decimal_to_float_fail_manual8);
  tcase_add_test(tc, test_from_decimal_to_float_fail_manual9);

  tcase_add_test(tc, test_from_decimal_to_float_ok1);
  tcase_add_test(tc, test_from_decimal_to_float_ok2);
  tcase_add_test(tc, test_from_decimal_to_float_ok3);
  tcase_add_test(tc, test_from_decimal_to_float_ok4);
  tcase_add_test(tc, test_from_decimal_to_float_ok5);
  tcase_add_test(tc, test_from_decimal_to_float_ok6);
  tcase_add_test(tc, test_from_decimal_to_float_ok7);
  tcase_add_test(tc, test_from_decimal_to_float_ok8);
  tcase_add_test(tc, test_from_decimal_to_float_ok9);
  tcase_add_test(tc, test_from_decimal_to_float_ok10);
  tcase_add_test(tc, test_from_decimal_to_float_ok11);
  tcase_add_test(tc, test_from_decimal_to_float_ok12);
  tcase_add_test(tc, test_from_decimal_to_float_ok13);
  tcase_add_test(tc, test_from_decimal_to_float_ok14);
  tcase_add_test(tc, test_from_decimal_to_float_ok15);
  tcase_add_test(tc, test_from_decimal_to_float_ok16);
  tcase_add_test(tc, test_from_decimal_to_float_ok17);
  tcase_add_test(tc, test_from_decimal_to_float_ok18);
  tcase_add_test(tc, test_from_decimal_to_float_ok19);
  tcase_add_test(tc, test_from_decimal_to_float_ok20);
  tcase_add_test(tc, test_from_decimal_to_float_ok21);
  tcase_add_test(tc, test_from_decimal_to_float_ok22);
  tcase_add_test(tc, test_from_decimal_to_float_ok23);
  tcase_add_test(tc, test_from_decimal_to_float_ok24);
  tcase_add_test(tc, test_from_decimal_to_float_ok25);
  tcase_add_test(tc, test_from_decimal_to_float_ok26);
  tcase_add_test(tc, test_from_decimal_to_float_ok27);
  tcase_add_test(tc, test_from_decimal_to_float_ok28);
  tcase_add_test(tc, test_from_decimal_to_float_ok29);
  tcase_add_test(tc, test_from_decimal_to_float_ok30);
  tcase_add_test(tc, test_from_decimal_to_float_ok31);
  tcase_add_test(tc, test_from_decimal_to_float_ok32);
  tcase_add_test(tc, test_from_decimal_to_float_ok33);
  tcase_add_test(tc, test_from_decimal_to_float_ok34);
  tcase_add_test(tc, test_from_decimal_to_float_ok35);
  tcase_add_test(tc, test_from_decimal_to_float_ok36);
  tcase_add_test(tc, test_from_decimal_to_float_ok37);
  tcase_add_test(tc, test_from_decimal_to_float_ok38);
  tcase_add_test(tc, test_from_decimal_to_float_ok39);
  tcase_add_test(tc, test_from_decimal_to_float_ok40);
  tcase_add_test(tc, test_from_decimal_to_float_ok41);
  tcase_add_test(tc, test_from_decimal_to_float_ok42);
  tcase_add_test(tc, test_from_decimal_to_float_ok43);
  tcase_add_test(tc, test_from_decimal_to_float_ok44);
  tcase_add_test(tc, test_from_decimal_to_float_ok45);
  tcase_add_test(tc, test_from_decimal_to_float_ok46);
  tcase_add_test(tc, test_from_decimal_to_float_ok47);
  tcase_add_test(tc, test_from_decimal_to_float_ok48);
  tcase_add_test(tc, test_from_decimal_to_float_ok49);
  tcase_add_test(tc, test_from_decimal_to_float_ok50);
  tcase_add_test(tc, test_from_decimal_to_float_ok51);
  tcase_add_test(tc, test_from_decimal_to_float_ok52);
  tcase_add_test(tc, test_from_decimal_to_float_ok53);
  tcase_add_test(tc, test_from_decimal_to_float_ok54);
  tcase_add_test(tc, test_from_decimal_to_float_ok55);
  tcase_add_test(tc, test_from_decimal_to_float_ok56);
  tcase_add_test(tc, test_from_decimal_to_float_ok57);
  tcase_add_test(tc, test_from_decimal_to_float_ok58);
  tcase_add_test(tc, test_from_decimal_to_float_ok59);
  tcase_add_test(tc, test_from_decimal_to_float_ok60);
  tcase_add_test(tc, test_from_decimal_to_float_ok61);
  tcase_add_test(tc, test_from_decimal_to_float_ok62);
  tcase_add_test(tc, test_from_decimal_to_float_ok63);
  tcase_add_test(tc, test_from_decimal_to_float_ok64);
  tcase_add_test(tc, test_from_decimal_to_float_ok65);
  tcase_add_test(tc, test_from_decimal_to_float_ok66);
  tcase_add_test(tc, test_from_decimal_to_float_ok67);
  tcase_add_test(tc, test_from_decimal_to_float_ok68);
  tcase_add_test(tc, test_from_decimal_to_float_ok69);
  tcase_add_test(tc, test_from_decimal_to_float_ok70);
  tcase_add_test(tc, test_from_decimal_to_float_ok71);
  tcase_add_test(tc, test_from_decimal_to_float_ok72);
  tcase_add_test(tc, test_from_decimal_to_float_ok73);
  tcase_add_test(tc, test_from_decimal_to_float_ok74);
  tcase_add_test(tc, test_from_decimal_to_float_ok75);
  tcase_add_test(tc, test_from_decimal_to_float_ok76);
  tcase_add_test(tc, test_from_decimal_to_float_ok77);
  tcase_add_test(tc, test_from_decimal_to_float_ok78);
  tcase_add_test(tc, test_from_decimal_to_float_ok79);
  tcase_add_test(tc, test_from_decimal_to_float_ok80);
  tcase_add_test(tc, test_from_decimal_to_float_ok81);
  tcase_add_test(tc, test_from_decimal_to_float_ok82);
  tcase_add_test(tc, test_from_decimal_to_float_ok83);
  tcase_add_test(tc, test_from_decimal_to_float_ok84);
  tcase_add_test(tc, test_from_decimal_to_float_ok85);
  tcase_add_test(tc, test_from_decimal_to_float_ok86);
  tcase_add_test(tc, test_from_decimal_to_float_ok87);
  tcase_add_test(tc, test_from_decimal_to_float_ok88);
  tcase_add_test(tc, test_from_decimal_to_float_ok89);
  tcase_add_test(tc, test_from_decimal_to_float_ok90);
  tcase_add_test(tc, test_from_decimal_to_float_ok91);
  tcase_add_test(tc, test_from_decimal_to_float_ok92);
  tcase_add_test(tc, test_from_decimal_to_float_ok93);
  tcase_add_test(tc, test_from_decimal_to_float_ok94);
  tcase_add_test(tc, test_from_decimal_to_float_ok95);
  tcase_add_test(tc, test_from_decimal_to_float_ok96);
  tcase_add_test(tc, test_from_decimal_to_float_ok97);
  tcase_add_test(tc, test_from_decimal_to_float_ok98);
  tcase_add_test(tc, test_from_decimal_to_float_ok99);
  tcase_add_test(tc, test_from_decimal_to_float_ok100);

  return s;
}