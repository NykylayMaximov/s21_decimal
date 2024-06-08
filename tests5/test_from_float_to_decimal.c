#include "./test.h"

static const float fails_big[] = {
    340282346638528859811704183484516925440.f,
    340282326356119256160033759537265639424.f,
    340282306073709652508363335590014353408.f,
    170141173319264429905852091742258462720.f,
    226854897759019239874469455656344616960.f,
    283568632339978851668922031544056414208.f,
    85070586659632214952926045871129231360.f,
    85070591730234615865843651857942052864.f,
    5316911666227013434557877866945576960.f,
    2658455991569831745807614120560689152.f,
    20769186196199271228741710417756160.f,
    10384593717069655257060992658440192.f,
    158456325028528675187087900672.0f,
    158456315583795709447797473280.0f,
    158456306139062743708507045888.0f,
    316912631167591418895594946560.f,
    158456325028528675187087900672.f,
    79228190848463234811415232512.f,
    79228181403730269072124805120.f,
    79228171958997303332834377728.f,
    79228162514264337593543950336.f,
    79228162514264337593543950335.f,
};

static const float fails_small[] = {
    0.00000000000000000000000000009999999429857660888699309391359540480357727713304344f,
    0.00000000000000000000000000009999998828004553267688105311366433422567940670147579f,
    0.00000000000000000000000000009999998226151445646676901231373326364778153626990814f,
    0.00000000000000000000000000009000000028539691658739462124217382784332763280814999f,
    0.00000000000000000000000000005000000015855384254855256735676323769073757378230555f,
    0.00000000000000000000000000004999999714928830444349654695679770240178863856652172f,
    4.999999414002276633844052655683216711283970335073789659219301029224880039691925048828125E-29f,
    1.2621774483536188886587657044524579674771302961744368076324462890625E-29f,
    1.0000000031710768509710513471352647538147514756461109453056224083411507308483123779296875E-29f,
    7.7037193183714626222678539700519994217126886949453196668630670929101000865557580254971981E-34f,
    4.8148245739821641389174087312824996385704304343408247917894169330688125540973487659357488E-35f,
    1.1754943508222875079687365372222456778186655567720875215087517062784172594547271728515625E-38f,
    1.4012984643248170709237295832899161312802619418765157717570682838897910826858606014866381E-45f,
};

START_TEST(test_from_float_to_decimal_unnormal1) {
  float f = 0.0;
  s21_decimal result;
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};

  int code = s21_from_float_to_decimal(f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
}
END_TEST

START_TEST(test_from_float_to_decimal_unnormal2) {
  float f = -0.0;
  s21_decimal result;
  s21_decimal check = {{0x0, 0x0, 0x0, 0x80000000}};

  int code = s21_from_float_to_decimal(f, &result);

  int sign_check = get_sign(check);
  int sign_result = get_sign(result);

  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}
END_TEST

START_TEST(test_from_float_to_decimal_unnormal3) {
  float f = INFINITY;
  s21_decimal result;

  int code = s21_from_float_to_decimal(f, &result);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(test_from_float_to_decimal_unnormal4) {
  float f = -INFINITY;
  s21_decimal result;

  int code = s21_from_float_to_decimal(f, &result);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(test_from_float_to_decimal_unnormal5) {
  float f = NAN;
  s21_decimal result;

  int code = s21_from_float_to_decimal(f, &result);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(test_from_float_to_decimal_unnormal6) {
  float f = -NAN;
  s21_decimal result;

  int code = s21_from_float_to_decimal(f, &result);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(test_from_float_to_decimal_incorrect1) {
  float f = 1.0f;
  int code = s21_from_float_to_decimal(f, NULL);

  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(test_from_float_to_decimal_fail_big) {
  float f = fails_big[_i];
  s21_decimal result;

  int code = s21_from_float_to_decimal(f, &result);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(test_from_float_to_decimal_fail_big_negate) {
  float f = -fails_big[_i];
  s21_decimal result;

  int code = s21_from_float_to_decimal(f, &result);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(test_from_float_to_decimal_fail_small) {
  float f = fails_small[_i];
  s21_decimal result;
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};

  int code = s21_from_float_to_decimal(f, &result);
  ck_assert_int_eq(code, 1);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
}
END_TEST

START_TEST(test_from_float_to_decimal_fail_small_negate) {
  float f = -fails_small[_i];
  s21_decimal result;
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};

  int code = s21_from_float_to_decimal(f, &result);
  ck_assert_int_eq(code, 1);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
}
END_TEST

START_TEST(test_from_float_to_decimal_ok1) {
  // 2.28401628E-19
  int f = 545706772;
  // 0.0000000000000000002284016
  s21_decimal decimal_check = {{0x22D9F0, 0x0, 0x0, 0x190000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok2) {
  // -2.28401628E-19
  int f = -1601776876;
  // -0.0000000000000000002284016
  s21_decimal decimal_check = {{0x22D9F0, 0x0, 0x0, 0x80190000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok3) {
  // 5.92141241E+23
  int f = 1727711253;
  // 592141200000000000000000
  s21_decimal decimal_check = {{0xBF280000, 0x9ED0576, 0x7D64, 0x0}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok4) {
  // -5.92141241E+23
  int f = -419772395;
  // -592141200000000000000000
  s21_decimal decimal_check = {{0xBF280000, 0x9ED0576, 0x7D64, 0x80000000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok5) {
  // 2.1349025E-18
  int f = 572360491;
  // 0.000000000000000002134902
  s21_decimal decimal_check = {{0x209376, 0x0, 0x0, 0x180000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok6) {
  // -2.1349025E-18
  int f = -1575123157;
  // -0.000000000000000002134902
  s21_decimal decimal_check = {{0x209376, 0x0, 0x0, 0x80180000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok7) {
  // 2.38582807E-08
  int f = 852291818;
  // 0.00000002385828
  s21_decimal decimal_check = {{0x2467A4, 0x0, 0x0, 0xE0000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok8) {
  // -2.38582807E-08
  int f = -1295191830;
  // -0.00000002385828
  s21_decimal decimal_check = {{0x2467A4, 0x0, 0x0, 0x800E0000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok9) {
  // 7.91617864E+11
  int f = 1396199450;
  // 791617900000
  s21_decimal decimal_check = {{0x501A8DE0, 0xB8, 0x0, 0x0}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok10) {
  // -7.91617864E+11
  int f = -751284198;
  // -791617900000
  s21_decimal decimal_check = {{0x501A8DE0, 0xB8, 0x0, 0x80000000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok11) {
  // 1.99102057E+21
  int f = 1658314220;
  // 1991021000000000000000
  s21_decimal decimal_check = {{0x5F048000, 0xEEF78A9E, 0x6B, 0x0}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok12) {
  // -1.99102057E+21
  int f = -489169428;
  // -1991021000000000000000
  s21_decimal decimal_check = {{0x5F048000, 0xEEF78A9E, 0x6B, 0x80000000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok13) {
  // 9.29209423E+24
  int f = 1760949678;
  // 9292094000000000000000000
  s21_decimal decimal_check = {{0xE380000, 0x6CD28004, 0x7AFAD, 0x0}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok14) {
  // -9.29209423E+24
  int f = -386533970;
  // -9292094000000000000000000
  s21_decimal decimal_check = {{0xE380000, 0x6CD28004, 0x7AFAD, 0x80000000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok15) {
  // 0.000115481133
  int f = 955395702;
  // 0.0001154811
  s21_decimal decimal_check = {{0x119EFB, 0x0, 0x0, 0xA0000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok16) {
  // -0.000115481133
  int f = -1192087946;
  // -0.0001154811
  s21_decimal decimal_check = {{0x119EFB, 0x0, 0x0, 0x800A0000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok17) {
  // 8.66900895E-23
  int f = 449944209;
  // 0.0000000000000000000000866901
  s21_decimal decimal_check = {{0xD3A55, 0x0, 0x0, 0x1C0000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok18) {
  // -8.66900895E-23
  int f = -1697539439;
  // -0.0000000000000000000000866901
  s21_decimal decimal_check = {{0xD3A55, 0x0, 0x0, 0x801C0000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok19) {
  // 3.91406387E+11
  int f = 1387676487;
  // 391406400000
  s21_decimal decimal_check = {{0x21A3B200, 0x5B, 0x0, 0x0}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok20) {
  // -3.91406387E+11
  int f = -759807161;
  // -391406400000
  s21_decimal decimal_check = {{0x21A3B200, 0x5B, 0x0, 0x80000000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok21) {
  // 1.54636995E-16
  int f = 624052425;
  // 0.000000000000000154637
  s21_decimal decimal_check = {{0x25C0D, 0x0, 0x0, 0x150000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok22) {
  // -1.54636995E-16
  int f = -1523431223;
  // -0.000000000000000154637
  s21_decimal decimal_check = {{0x25C0D, 0x0, 0x0, 0x80150000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok23) {
  // 1.05583253E-13
  int f = 703447194;
  // 0.0000000000001055833
  s21_decimal decimal_check = {{0x101C59, 0x0, 0x0, 0x130000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok24) {
  // -1.05583253E-13
  int f = -1444036454;
  // -0.0000000000001055833
  s21_decimal decimal_check = {{0x101C59, 0x0, 0x0, 0x80130000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok25) {
  // 4882.71582
  int f = 1167627706;
  // 4882.716
  s21_decimal decimal_check = {{0x4A811C, 0x0, 0x0, 0x30000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok26) {
  // -4882.71582
  int f = -979855942;
  // -4882.716
  s21_decimal decimal_check = {{0x4A811C, 0x0, 0x0, 0x80030000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok27) {
  // 1.9929916E-26
  int f = 348479575;
  // 0.0000000000000000000000000199
  s21_decimal decimal_check = {{0xC7, 0x0, 0x0, 0x1C0000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok28) {
  // -1.9929916E-26
  int f = -1799004073;
  // -0.0000000000000000000000000199
  s21_decimal decimal_check = {{0xC7, 0x0, 0x0, 0x801C0000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok29) {
  // 3574.10864
  int f = 1163878845;
  // 3574.109
  s21_decimal decimal_check = {{0x36895D, 0x0, 0x0, 0x30000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok30) {
  // -3574.10864
  int f = -983604803;
  // -3574.109
  s21_decimal decimal_check = {{0x36895D, 0x0, 0x0, 0x80030000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok31) {
  // 3.62930687E-13
  int f = 718032851;
  // 0.0000000000003629307
  s21_decimal decimal_check = {{0x3760FB, 0x0, 0x0, 0x130000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok32) {
  // -3.62930687E-13
  int f = -1429450797;
  // -0.0000000000003629307
  s21_decimal decimal_check = {{0x3760FB, 0x0, 0x0, 0x80130000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok33) {
  // 2.1409382E-19
  int f = 545047011;
  // 0.0000000000000000002140938
  s21_decimal decimal_check = {{0x20AB0A, 0x0, 0x0, 0x190000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok34) {
  // -2.1409382E-19
  int f = -1602436637;
  // -0.0000000000000000002140938
  s21_decimal decimal_check = {{0x20AB0A, 0x0, 0x0, 0x80190000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok35) {
  // 241.244507
  int f = 1131495064;
  // 241.2445
  s21_decimal decimal_check = {{0x24CF9D, 0x0, 0x0, 0x40000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok36) {
  // -241.244507
  int f = -1015988584;
  // -241.2445
  s21_decimal decimal_check = {{0x24CF9D, 0x0, 0x0, 0x80040000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok37) {
  // 802580.063
  int f = 1229189441;
  // 802580.1
  s21_decimal decimal_check = {{0x7A76C9, 0x0, 0x0, 0x10000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok38) {
  // -802580.063
  int f = -918294207;
  // -802580.1
  s21_decimal decimal_check = {{0x7A76C9, 0x0, 0x0, 0x80010000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok39) {
  // 8.38680669E+16
  int f = 1536490184;
  // 83868070000000000
  s21_decimal decimal_check = {{0xB858FC00, 0x129F590, 0x0, 0x0}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok40) {
  // -8.38680669E+16
  int f = -610993464;
  // -83868070000000000
  s21_decimal decimal_check = {{0xB858FC00, 0x129F590, 0x0, 0x80000000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok41) {
  // 3.93541897E-17
  int f = 607485242;
  // 0.00000000000000003935419
  s21_decimal decimal_check = {{0x3C0CBB, 0x0, 0x0, 0x170000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok42) {
  // -3.93541897E-17
  int f = -1539998406;
  // -0.00000000000000003935419
  s21_decimal decimal_check = {{0x3C0CBB, 0x0, 0x0, 0x80170000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok43) {
  // 1.45764168E-20
  int f = 512338845;
  // 0.00000000000000000001457642
  s21_decimal decimal_check = {{0x163DEA, 0x0, 0x0, 0x1A0000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok44) {
  // -1.45764168E-20
  int f = -1635144803;
  // -0.00000000000000000001457642
  s21_decimal decimal_check = {{0x163DEA, 0x0, 0x0, 0x801A0000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok45) {
  // 1.34647118E+20
  int f = 1625920341;
  // 134647100000000000000
  s21_decimal decimal_check = {{0x207FC000, 0x4C9A980F, 0x7, 0x0}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok46) {
  // -1.34647118E+20
  int f = -521563307;
  // -134647100000000000000
  s21_decimal decimal_check = {{0x207FC000, 0x4C9A980F, 0x7, 0x80000000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok47) {
  // 2.20958198E-20
  int f = 516993130;
  // 0.00000000000000000002209582
  s21_decimal decimal_check = {{0x21B72E, 0x0, 0x0, 0x1A0000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok48) {
  // -2.20958198E-20
  int f = -1630490518;
  // -0.00000000000000000002209582
  s21_decimal decimal_check = {{0x21B72E, 0x0, 0x0, 0x801A0000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok49) {
  // 5.36623235E-09
  int f = 834167265;
  // 0.000000005366232
  s21_decimal decimal_check = {{0x51E1D8, 0x0, 0x0, 0xF0000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok50) {
  // -5.36623235E-09
  int f = -1313316383;
  // -0.000000005366232
  s21_decimal decimal_check = {{0x51E1D8, 0x0, 0x0, 0x800F0000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok51) {
  // 4.71008997E+17
  int f = 1557212038;
  // 471009000000000000
  s21_decimal decimal_check = {{0xA3031000, 0x6895C30, 0x0, 0x0}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok52) {
  // -4.71008997E+17
  int f = -590271610;
  // -471009000000000000
  s21_decimal decimal_check = {{0xA3031000, 0x6895C30, 0x0, 0x80000000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok53) {
  // 2.36363464E-11
  int f = 768600146;
  // 0.00000000002363635
  s21_decimal decimal_check = {{0x2410F3, 0x0, 0x0, 0x110000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok54) {
  // -2.36363464E-11
  int f = -1378883502;
  // -0.00000000002363635
  s21_decimal decimal_check = {{0x2410F3, 0x0, 0x0, 0x80110000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok55) {
  // 0.0255207196
  int f = 1020334292;
  // 0.02552072
  s21_decimal decimal_check = {{0x26F108, 0x0, 0x0, 0x80000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok56) {
  // -0.0255207196
  int f = -1127149356;
  // -0.02552072
  s21_decimal decimal_check = {{0x26F108, 0x0, 0x0, 0x80080000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok57) {
  // 3.9575282E-24
  int f = 412686710;
  // 0.0000000000000000000000039575
  s21_decimal decimal_check = {{0x9A97, 0x0, 0x0, 0x1C0000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok58) {
  // -3.9575282E-24
  int f = -1734796938;
  // -0.0000000000000000000000039575
  s21_decimal decimal_check = {{0x9A97, 0x0, 0x0, 0x801C0000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok59) {
  // 0.00399137754
  int f = 998427162;
  // 0.003991378
  s21_decimal decimal_check = {{0x3CE752, 0x0, 0x0, 0x90000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok60) {
  // -0.00399137754
  int f = -1149056486;
  // -0.003991378
  s21_decimal decimal_check = {{0x3CE752, 0x0, 0x0, 0x80090000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok61) {
  // 1.95127377E-05
  int f = 933474121;
  // 0.00001951274
  s21_decimal decimal_check = {{0x1DC62A, 0x0, 0x0, 0xB0000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok62) {
  // -1.95127377E-05
  int f = -1214009527;
  // -0.00001951274
  s21_decimal decimal_check = {{0x1DC62A, 0x0, 0x0, 0x800B0000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok63) {
  // 1.26745242E-20
  int f = 510618173;
  // 0.00000000000000000001267452
  s21_decimal decimal_check = {{0x1356FC, 0x0, 0x0, 0x1A0000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok64) {
  // -1.26745242E-20
  int f = -1636865475;
  // -0.00000000000000000001267452
  s21_decimal decimal_check = {{0x1356FC, 0x0, 0x0, 0x801A0000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok65) {
  // 0.0764362067
  int f = 1033669270;
  // 0.07643621
  s21_decimal decimal_check = {{0x74A1E5, 0x0, 0x0, 0x80000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok66) {
  // -0.0764362067
  int f = -1113814378;
  // -0.07643621
  s21_decimal decimal_check = {{0x74A1E5, 0x0, 0x0, 0x80080000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok67) {
  // 1.19421885E-18
  int f = 565197904;
  // 0.000000000000000001194219
  s21_decimal decimal_check = {{0x1238EB, 0x0, 0x0, 0x180000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok68) {
  // -1.19421885E-18
  int f = -1582285744;
  // -0.000000000000000001194219
  s21_decimal decimal_check = {{0x1238EB, 0x0, 0x0, 0x80180000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok69) {
  // 7.93902012E-16
  int f = 644141985;
  // 0.000000000000000793902
  s21_decimal decimal_check = {{0xC1D2E, 0x0, 0x0, 0x150000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok70) {
  // -7.93902012E-16
  int f = -1503341663;
  // -0.000000000000000793902
  s21_decimal decimal_check = {{0xC1D2E, 0x0, 0x0, 0x80150000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok71) {
  // 5.86327048E-15
  int f = 668155680;
  // 0.00000000000000586327
  s21_decimal decimal_check = {{0x8F257, 0x0, 0x0, 0x140000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok72) {
  // -5.86327048E-15
  int f = -1479327968;
  // -0.00000000000000586327
  s21_decimal decimal_check = {{0x8F257, 0x0, 0x0, 0x80140000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok73) {
  // 8.52215659E-11
  int f = 784033658;
  // 0.00000000008522157
  s21_decimal decimal_check = {{0x8209AD, 0x0, 0x0, 0x110000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok74) {
  // -8.52215659E-11
  int f = -1363449990;
  // -0.00000000008522157
  s21_decimal decimal_check = {{0x8209AD, 0x0, 0x0, 0x80110000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok75) {
  // 9.61645806E-28
  int f = 311976189;
  // 0.000000000000000000000000001
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x1B0000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok76) {
  // -9.61645806E-28
  int f = -1835507459;
  // -0.000000000000000000000000001
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x801B0000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok77) {
  // 46282560
  int f = 1278250448;
  // 46282560
  s21_decimal decimal_check = {{0x2C23740, 0x0, 0x0, 0x0}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok78) {
  // -46282560
  int f = -869233200;
  // -46282560
  s21_decimal decimal_check = {{0x2C23740, 0x0, 0x0, 0x80000000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok79) {
  // 1.15109615E-12
  int f = 732037276;
  // 0.000000000001151096
  s21_decimal decimal_check = {{0x119078, 0x0, 0x0, 0x120000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok80) {
  // -1.15109615E-12
  int f = -1415446372;
  // -0.000000000001151096
  s21_decimal decimal_check = {{0x119078, 0x0, 0x0, 0x80120000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok81) {
  // 2.83794689E-11
  int f = 771334370;
  // 0.00000000002837947
  s21_decimal decimal_check = {{0x2B4DBB, 0x0, 0x0, 0x110000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok82) {
  // -2.83794689E-11
  int f = -1376149278;
  // -0.00000000002837947
  s21_decimal decimal_check = {{0x2B4DBB, 0x0, 0x0, 0x80110000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok83) {
  // 8.43187742E-10
  int f = 812107280;
  // 0.0000000008431877
  s21_decimal decimal_check = {{0x80A905, 0x0, 0x0, 0x100000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok84) {
  // -8.43187742E-10
  int f = -1335376368;
  // -0.0000000008431877
  s21_decimal decimal_check = {{0x80A905, 0x0, 0x0, 0x80100000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok85) {
  // 9.83161032E+17
  int f = 1566199356;
  // 983161000000000000
  s21_decimal decimal_check = {{0x72049000, 0xDA4E3B8, 0x0, 0x0}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok86) {
  // -9.83161032E+17
  int f = -581284292;
  // -983161000000000000
  s21_decimal decimal_check = {{0x72049000, 0xDA4E3B8, 0x0, 0x80000000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok87) {
  // 5010.18115
  int f = 1167888755;
  // 5010.181
  s21_decimal decimal_check = {{0x4C7305, 0x0, 0x0, 0x30000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok88) {
  // -5010.18115
  int f = -979594893;
  // -5010.181
  s21_decimal decimal_check = {{0x4C7305, 0x0, 0x0, 0x80030000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok89) {
  // 5.82704236E-25
  int f = 389306006;
  // 0.0000000000000000000000005827
  s21_decimal decimal_check = {{0x16C3, 0x0, 0x0, 0x1C0000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok90) {
  // -5.82704236E-25
  int f = -1758177642;
  // -0.0000000000000000000000005827
  s21_decimal decimal_check = {{0x16C3, 0x0, 0x0, 0x801C0000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok91) {
  // 5.07265574E+16
  int f = 1530148745;
  // 50726560000000000
  s21_decimal decimal_check = {{0x9D7A4000, 0xB43789, 0x0, 0x0}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok92) {
  // -5.07265574E+16
  int f = -617334903;
  // -50726560000000000
  s21_decimal decimal_check = {{0x9D7A4000, 0xB43789, 0x0, 0x80000000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok93) {
  // 1.35639493E+19
  int f = 1597783252;
  // 13563950000000000000
  s21_decimal decimal_check = {{0xFD28E000, 0xBC3CD4A8, 0x0, 0x0}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok94) {
  // -1.35639493E+19
  int f = -549700396;
  // -13563950000000000000
  s21_decimal decimal_check = {{0xFD28E000, 0xBC3CD4A8, 0x0, 0x80000000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok95) {
  // 1.2867606E+27
  int f = 1820658757;
  // 1286761000000000000000000000
  s21_decimal decimal_check = {{0x8FA00000, 0x955F02E9, 0x428623D, 0x0}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok96) {
  // -1.2867606E+27
  int f = -326824891;
  // -1286761000000000000000000000
  s21_decimal decimal_check = {{0x8FA00000, 0x955F02E9, 0x428623D, 0x80000000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok97) {
  // 9.07980924E+20
  int f = 1648681745;
  // 907980900000000000000
  s21_decimal decimal_check = {{0x6B7A4000, 0x38C429DC, 0x31, 0x0}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok98) {
  // -9.07980924E+20
  int f = -498801903;
  // -907980900000000000000
  s21_decimal decimal_check = {{0x6B7A4000, 0x38C429DC, 0x31, 0x80000000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok99) {
  // 15372566
  int f = 1265275158;
  // 15372570
  s21_decimal decimal_check = {{0xEA911A, 0x0, 0x0, 0x0}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

END_TEST START_TEST(test_from_float_to_decimal_ok100) {
  // -15372566
  int f = -882208490;
  // -15372570
  s21_decimal decimal_check = {{0xEA911A, 0x0, 0x0, 0x80000000}};

  s21_decimal result;
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &result);
  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}

Suite *test_from_float_to_decimal(void) {
  Suite *s = suite_create(
      "\n\033[37;1m==========| S21_FROM_FLOAT_TO_DECIMAL |=========\033[0m");
  TCase *tc = tcase_create("tc_from_float_to_decimal");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_from_float_to_decimal_incorrect1);
  tcase_add_test(tc, test_from_float_to_decimal_unnormal1);
  tcase_add_test(tc, test_from_float_to_decimal_unnormal2);
  tcase_add_test(tc, test_from_float_to_decimal_unnormal3);
  tcase_add_test(tc, test_from_float_to_decimal_unnormal4);
  tcase_add_test(tc, test_from_float_to_decimal_unnormal5);
  tcase_add_test(tc, test_from_float_to_decimal_unnormal6);
  tcase_add_loop_test(tc, test_from_float_to_decimal_fail_big, 0,
                      sizeof(fails_big) / sizeof(*fails_big));
  tcase_add_loop_test(tc, test_from_float_to_decimal_fail_big_negate, 0,
                      sizeof(fails_big) / sizeof(*fails_big));
  tcase_add_loop_test(tc, test_from_float_to_decimal_fail_small, 0,
                      sizeof(fails_small) / sizeof(*fails_small));
  tcase_add_loop_test(tc, test_from_float_to_decimal_fail_small_negate, 0,
                      sizeof(fails_small) / sizeof(*fails_small));
  tcase_add_test(tc, test_from_float_to_decimal_ok1);
  tcase_add_test(tc, test_from_float_to_decimal_ok2);
  tcase_add_test(tc, test_from_float_to_decimal_ok3);
  tcase_add_test(tc, test_from_float_to_decimal_ok4);
  tcase_add_test(tc, test_from_float_to_decimal_ok5);
  tcase_add_test(tc, test_from_float_to_decimal_ok6);
  tcase_add_test(tc, test_from_float_to_decimal_ok7);
  tcase_add_test(tc, test_from_float_to_decimal_ok8);
  tcase_add_test(tc, test_from_float_to_decimal_ok9);
  tcase_add_test(tc, test_from_float_to_decimal_ok10);
  tcase_add_test(tc, test_from_float_to_decimal_ok11);
  tcase_add_test(tc, test_from_float_to_decimal_ok12);
  tcase_add_test(tc, test_from_float_to_decimal_ok13);
  tcase_add_test(tc, test_from_float_to_decimal_ok14);
  tcase_add_test(tc, test_from_float_to_decimal_ok15);
  tcase_add_test(tc, test_from_float_to_decimal_ok16);
  tcase_add_test(tc, test_from_float_to_decimal_ok17);
  tcase_add_test(tc, test_from_float_to_decimal_ok18);
  tcase_add_test(tc, test_from_float_to_decimal_ok19);
  tcase_add_test(tc, test_from_float_to_decimal_ok20);
  tcase_add_test(tc, test_from_float_to_decimal_ok21);
  tcase_add_test(tc, test_from_float_to_decimal_ok22);
  tcase_add_test(tc, test_from_float_to_decimal_ok23);
  tcase_add_test(tc, test_from_float_to_decimal_ok24);
  tcase_add_test(tc, test_from_float_to_decimal_ok25);
  tcase_add_test(tc, test_from_float_to_decimal_ok26);
  tcase_add_test(tc, test_from_float_to_decimal_ok27);
  tcase_add_test(tc, test_from_float_to_decimal_ok28);
  tcase_add_test(tc, test_from_float_to_decimal_ok29);
  tcase_add_test(tc, test_from_float_to_decimal_ok30);
  tcase_add_test(tc, test_from_float_to_decimal_ok31);
  tcase_add_test(tc, test_from_float_to_decimal_ok32);
  tcase_add_test(tc, test_from_float_to_decimal_ok33);
  tcase_add_test(tc, test_from_float_to_decimal_ok34);
  tcase_add_test(tc, test_from_float_to_decimal_ok35);
  tcase_add_test(tc, test_from_float_to_decimal_ok36);
  tcase_add_test(tc, test_from_float_to_decimal_ok37);
  tcase_add_test(tc, test_from_float_to_decimal_ok38);
  tcase_add_test(tc, test_from_float_to_decimal_ok39);
  tcase_add_test(tc, test_from_float_to_decimal_ok40);
  tcase_add_test(tc, test_from_float_to_decimal_ok41);
  tcase_add_test(tc, test_from_float_to_decimal_ok42);
  tcase_add_test(tc, test_from_float_to_decimal_ok43);
  tcase_add_test(tc, test_from_float_to_decimal_ok44);
  tcase_add_test(tc, test_from_float_to_decimal_ok45);
  tcase_add_test(tc, test_from_float_to_decimal_ok46);
  tcase_add_test(tc, test_from_float_to_decimal_ok47);
  tcase_add_test(tc, test_from_float_to_decimal_ok48);
  tcase_add_test(tc, test_from_float_to_decimal_ok49);
  tcase_add_test(tc, test_from_float_to_decimal_ok50);
  tcase_add_test(tc, test_from_float_to_decimal_ok51);
  tcase_add_test(tc, test_from_float_to_decimal_ok52);
  tcase_add_test(tc, test_from_float_to_decimal_ok53);
  tcase_add_test(tc, test_from_float_to_decimal_ok54);
  tcase_add_test(tc, test_from_float_to_decimal_ok55);
  tcase_add_test(tc, test_from_float_to_decimal_ok56);
  tcase_add_test(tc, test_from_float_to_decimal_ok57);
  tcase_add_test(tc, test_from_float_to_decimal_ok58);
  tcase_add_test(tc, test_from_float_to_decimal_ok59);
  tcase_add_test(tc, test_from_float_to_decimal_ok60);
  tcase_add_test(tc, test_from_float_to_decimal_ok61);
  tcase_add_test(tc, test_from_float_to_decimal_ok62);
  tcase_add_test(tc, test_from_float_to_decimal_ok63);
  tcase_add_test(tc, test_from_float_to_decimal_ok64);
  tcase_add_test(tc, test_from_float_to_decimal_ok65);
  tcase_add_test(tc, test_from_float_to_decimal_ok66);
  tcase_add_test(tc, test_from_float_to_decimal_ok67);
  tcase_add_test(tc, test_from_float_to_decimal_ok68);
  tcase_add_test(tc, test_from_float_to_decimal_ok69);
  tcase_add_test(tc, test_from_float_to_decimal_ok70);
  tcase_add_test(tc, test_from_float_to_decimal_ok71);
  tcase_add_test(tc, test_from_float_to_decimal_ok72);
  tcase_add_test(tc, test_from_float_to_decimal_ok73);
  tcase_add_test(tc, test_from_float_to_decimal_ok74);
  tcase_add_test(tc, test_from_float_to_decimal_ok75);
  tcase_add_test(tc, test_from_float_to_decimal_ok76);
  tcase_add_test(tc, test_from_float_to_decimal_ok77);
  tcase_add_test(tc, test_from_float_to_decimal_ok78);
  tcase_add_test(tc, test_from_float_to_decimal_ok79);
  tcase_add_test(tc, test_from_float_to_decimal_ok80);
  tcase_add_test(tc, test_from_float_to_decimal_ok81);
  tcase_add_test(tc, test_from_float_to_decimal_ok82);
  tcase_add_test(tc, test_from_float_to_decimal_ok83);
  tcase_add_test(tc, test_from_float_to_decimal_ok84);
  tcase_add_test(tc, test_from_float_to_decimal_ok85);
  tcase_add_test(tc, test_from_float_to_decimal_ok86);
  tcase_add_test(tc, test_from_float_to_decimal_ok87);
  tcase_add_test(tc, test_from_float_to_decimal_ok88);
  tcase_add_test(tc, test_from_float_to_decimal_ok89);
  tcase_add_test(tc, test_from_float_to_decimal_ok90);
  tcase_add_test(tc, test_from_float_to_decimal_ok91);
  tcase_add_test(tc, test_from_float_to_decimal_ok92);
  tcase_add_test(tc, test_from_float_to_decimal_ok93);
  tcase_add_test(tc, test_from_float_to_decimal_ok94);
  tcase_add_test(tc, test_from_float_to_decimal_ok95);
  tcase_add_test(tc, test_from_float_to_decimal_ok96);
  tcase_add_test(tc, test_from_float_to_decimal_ok97);
  tcase_add_test(tc, test_from_float_to_decimal_ok98);
  tcase_add_test(tc, test_from_float_to_decimal_ok99);
  tcase_add_test(tc, test_from_float_to_decimal_ok100);

  return s;
}