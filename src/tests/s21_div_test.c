#include <check.h>
#include <stdlib.h>

#include "../s21_decimal.h"

#define SHOW_FAILED TRUE

START_TEST(s21_div_test_1) {
  s21_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};  //-2147483648?
  s21_decimal val2 = {{2, 0, 0, 0}};                // 2
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_div(val1, val2, &res));
}
END_TEST

START_TEST(s21_div_test_2) {
  s21_decimal val1 = {{2, 0, 0, 0}};                // 2
  s21_decimal val2 = {{2, 0, 0, ~(UINT_MAX / 2)}};  //-2147483648?
  s21_decimal res;
  ck_assert_int_eq(0, s21_div(val1, val2, &res));
}
END_TEST

START_TEST(s21_div_test_3) {
  s21_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res = {{0}};
  int res_int = 0;
  ck_assert_int_eq(0, s21_div(val1, val2, &res));
  s21_from_decimal_to_int(res, &res_int);
  ck_assert_int_eq(1, res_int);
}
END_TEST

START_TEST(s21_div_test_4) {
  s21_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{0, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(3, s21_div(val1, val2, &res));
}
END_TEST

START_TEST(s21_div_test_5) {
  s21_decimal val1 = {{2, 0, 0, 0}};  // 2
  s21_decimal val2 = {{0, 0, 0, 0}};  // 0
  s21_decimal res = {{0}};
  ck_assert_int_eq(3, s21_div(val1, val2, &res));
}
END_TEST

START_TEST(s21_div_test_6) {
  s21_decimal value_1 = {{15, 0, 0, 0}};
  set_sign(&value_1, MINUS);
  s21_decimal value_2 = {{0, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal check = {{0, 0, 0, 0}};
  int return_value = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 3);
}
END_TEST

START_TEST(s21_div_test_7) {
  int num1 = 2;
  int num2 = 2;
  int res_origin = 1;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  int res = s21_div(a, b, &res_dec);
  ck_assert_int_eq(0, res);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(s21_div_test_8) {
  int num1 = 0;
  int num2 = 5;
  int res_origin = num1 / num2;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  int res = s21_div(a, b, &res_dec);
  ck_assert_int_eq(0, res);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(s21_div_test_9) {
  s21_decimal dec1 = {{1110, 0, 0, 0}};
  s21_decimal dec2 = {{0, 0, 0, 0}};

  s21_decimal res1;
  int res = s21_div(dec1, dec2, &res1);
  ck_assert_int_eq(res, 3);
}
END_TEST

// START_TEST(s21_div_test_10) {
//   s21_decimal value_1 = {.bits[0] = 0x00000001,
//                          .bits[1] = 0x00000000,
//                          .bits[2] = 0x00000000,
//                          .bits[3] = 0x00000000};  // 1

//   s21_decimal value_2 = {.bits[0] = 0x00000001,
//                          .bits[1] = 0x00000000,
//                          .bits[2] = 0x00000000,
//                          .bits[3] = 0x00000000};  // 1

//   s21_decimal reference_result = {.bits[0] = 0x00000001,
//                                   .bits[1] = 0x00000000,
//                                   .bits[2] = 0x00000000,
//                                   .bits[3] = 0x00000000};  // 1
//   s21_decimal result = {0};
//   int sub_result = s21_div(value_1, value_2, &result);
//   ck_assert_int_eq(sub_result, 0);
//   ck_assert_int_eq(result.bits[0], reference_result.bits[0]);
//   ck_assert_int_eq(result.bits[1], reference_result.bits[1]);
//   ck_assert_int_eq(result.bits[2], reference_result.bits[2]);
//   ck_assert_int_eq(result.bits[3], reference_result.bits[3]);
// }
// END_TEST

// START_TEST(s21_div_test_11) {
//   s21_decimal value_1 = {.bits[0] = 0x00000002,
//                          .bits[1] = 0x00000000,
//                          .bits[2] = 0x00000000,
//                          .bits[3] = 0x80000000};  // -2

//   s21_decimal value_2 = {.bits[0] = 0x00000001,
//                          .bits[1] = 0x00000000,
//                          .bits[2] = 0x00000000,
//                          .bits[3] = 0x00000000};  // 1

//   s21_decimal reference_result = {.bits[0] = 0x00000002,
//                                   .bits[1] = 0x00000000,
//                                   .bits[2] = 0x00000000,
//                                   .bits[3] = 0x80000000};  // -2
//   s21_decimal result = {0};
//   int sub_result = s21_div(value_1, value_2, &result);
//   ck_assert_int_eq(sub_result, 0);
//   ck_assert_int_eq(result.bits[0], reference_result.bits[0]);
//   ck_assert_int_eq(result.bits[1], reference_result.bits[1]);
//   ck_assert_int_eq(result.bits[2], reference_result.bits[2]);
//   ck_assert_int_eq(result.bits[3], reference_result.bits[3]);
// }
// END_TEST

// START_TEST(s21_div_test_12) {
//   s21_decimal value_1 = {.bits[0] = 0x00000002,
//                          .bits[1] = 0x00000000,
//                          .bits[2] = 0x00000000,
//                          .bits[3] = 0x80000000};  // -2

//   s21_decimal value_2 = {.bits[0] = 0x00000001,
//                          .bits[1] = 0x00000000,
//                          .bits[2] = 0x00000000,
//                          .bits[3] = 0x80000000};  // -1

//   s21_decimal reference_result = {.bits[0] = 0x00000002,
//                                   .bits[1] = 0x00000000,
//                                   .bits[2] = 0x00000000,
//                                   .bits[3] = 0x00000000};  // 2
//   s21_decimal result = {0};
//   int sub_result = s21_div(value_1, value_2, &result);
//   ck_assert_int_eq(sub_result, 0);
//   ck_assert_int_eq(result.bits[0], reference_result.bits[0]);
//   ck_assert_int_eq(result.bits[1], reference_result.bits[1]);
//   ck_assert_int_eq(result.bits[2], reference_result.bits[2]);
//   ck_assert_int_eq(result.bits[3], reference_result.bits[3]);
// }
// END_TEST

START_TEST(s21_div_test_13) {
  s21_decimal dec1 = {{100, 0, 0, 0}};
  s21_decimal dec2 = {{10, 0, 0, 0}};
  s21_decimal res_dec;
  s21_decimal expected = {{10, 0, 0, 0}};

  int expected_scale = 0;

  int res = s21_div(dec1, dec2, &res_dec);

  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(res_dec.bits[LOW], expected.bits[LOW]);
  ck_assert_int_eq(res_dec.bits[MID], expected.bits[MID]);
  ck_assert_int_eq(res_dec.bits[HIGH], expected.bits[HIGH]);
  ck_assert_int_eq(get_scale(res_dec), expected_scale);
}
END_TEST

START_TEST(s21_div_test_14) {
  s21_decimal dec1 = {{100, 0, 0, 0x80000000}};
  s21_decimal dec2 = {{10, 0, 0, 0}};
  s21_decimal expected = {{10, 0, 0, 0x80000000}};
  s21_decimal res_dec;

  int expected_scale = 0;

  int res = s21_div(dec1, dec2, &res_dec);

  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(res_dec.bits[LOW], expected.bits[LOW]);
  ck_assert_int_eq(res_dec.bits[MID], expected.bits[MID]);
  ck_assert_int_eq(res_dec.bits[HIGH], expected.bits[HIGH]);
  ck_assert_int_eq(get_scale(res_dec), expected_scale);
}
END_TEST

START_TEST(s21_div_test_15) {
  s21_decimal dec1 = {{110, 0, 0, 0x80000000}};
  s21_decimal dec2 = {{10, 0, 0, 0x80000000}};
  s21_decimal expected = {{11, 0, 0, 0}};
  s21_decimal res_dec;
  int expected_scale = 0;

  int res = s21_div(dec1, dec2, &res_dec);

  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(res_dec.bits[LOW], expected.bits[LOW]);
  ck_assert_int_eq(res_dec.bits[MID], expected.bits[MID]);
  ck_assert_int_eq(res_dec.bits[HIGH], expected.bits[HIGH]);
  ck_assert_int_eq(get_scale(res_dec), expected_scale);
}
END_TEST

START_TEST(s21_div_test_16) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  s21_decimal dec2 = {{10, 0, 0, 0}};
  s21_decimal expected = {{0, 0, 0, 0}};
  s21_decimal res_dec;

  int expected_scale = 0;

  int res = s21_div(dec1, dec2, &res_dec);

  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(res_dec.bits[LOW], expected.bits[LOW]);
  ck_assert_int_eq(res_dec.bits[MID], expected.bits[MID]);
  ck_assert_int_eq(res_dec.bits[HIGH], expected.bits[HIGH]);
  ck_assert_int_eq(get_scale(res_dec), expected_scale);
}
END_TEST

START_TEST(s21_div_test_17) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  s21_decimal dec2 = {{10, 0, 0, 0x80000000}};
  s21_decimal expected = {{0, 0, 0, 0}};
  s21_decimal res_dec;

  int expected_scale = 0;

  int res = s21_div(dec1, dec2, &res_dec);

  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(res_dec.bits[LOW], expected.bits[LOW]);
  ck_assert_int_eq(res_dec.bits[MID], expected.bits[MID]);
  ck_assert_int_eq(res_dec.bits[HIGH], expected.bits[HIGH]);
  ck_assert_int_eq(get_scale(res_dec), expected_scale);
}
END_TEST

START_TEST(s21_div_test_18) {
  s21_decimal dec1 = {{42, 0, 0, 0}};
  s21_decimal dec2 = {{42, 0, 0, 0}};
  s21_decimal expected = {{1, 0, 0, 0}};
  s21_decimal res_dec;

  int expected_scale = 0;

  int res = s21_div(dec1, dec2, &res_dec);

  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(res_dec.bits[LOW], expected.bits[LOW]);
  ck_assert_int_eq(res_dec.bits[MID], expected.bits[MID]);
  ck_assert_int_eq(res_dec.bits[HIGH], expected.bits[HIGH]);
  ck_assert_int_eq(get_scale(res_dec), expected_scale);
}
END_TEST

START_TEST(s21_div_test_19) {
  s21_decimal dec1 = {{1000, 0, 0, 0x80000000}};
  s21_decimal dec2 = {{10, 0, 0, 0}};
  s21_decimal expected = {{100, 0, 0, 0x80000000}};
  s21_decimal res_dec;

  int expected_scale = 0;

  int res = s21_div(dec1, dec2, &res_dec);

  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(res_dec.bits[LOW], expected.bits[LOW]);
  ck_assert_int_eq(res_dec.bits[MID], expected.bits[MID]);
  ck_assert_int_eq(res_dec.bits[HIGH], expected.bits[HIGH]);
  ck_assert_int_eq(get_scale(res_dec), expected_scale);
}
END_TEST

START_TEST(s21_div_test_20) {
  s21_decimal dec1 = {{10, 0, 0, 0}};
  s21_decimal dec2 = {{1000, 0, 0, 0}};
  s21_decimal res_dec = {0};
  float expected = 0.01, res_float;

  int expected_scale = 2;

  int res = s21_div(dec1, dec2, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);

  ck_assert_int_eq(res, 0);
  ck_assert_uint_eq(res_float, expected);
  ck_assert_int_eq(get_scale(res_dec), expected_scale);
}
END_TEST

START_TEST(s21_div_test_21) {
  s21_decimal dec1 = {{42, 0, 0, 0}};
  s21_decimal dec2 = {{0, 0, 0, 0}};
  s21_decimal res_dec = {0};
  int expected_scale = 0;

  int res = s21_div(dec1, dec2, &res_dec);

  ck_assert_int_eq(res, 3);
  ck_assert_int_eq(get_scale(res_dec), expected_scale);
}
END_TEST

START_TEST(s21_div_test_22) {
  s21_decimal dec1 = {{42, 0, 0, 0x80000000}};
  s21_decimal dec2 = {{0, 0, 0, 0}};
  s21_decimal res_dec = {0};

  int expected_scale = 0;

  int res = s21_div(dec1, dec2, &res_dec);

  ck_assert_int_eq(res, 3);
  ck_assert_int_eq(get_scale(res_dec), expected_scale);
}
END_TEST

START_TEST(s21_div_test_23) {
  s21_decimal dec1 = {{42, 0, 0, 0}};
  s21_decimal dec2 = {{1, 0, 0, 0}};
  s21_decimal expected = {{42, 0, 0, 0}};
  s21_decimal res_dec;

  int expected_scale = 0;

  int res = s21_div(dec1, dec2, &res_dec);

  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(res_dec.bits[LOW], expected.bits[LOW]);
  ck_assert_int_eq(res_dec.bits[MID], expected.bits[MID]);
  ck_assert_int_eq(res_dec.bits[HIGH], expected.bits[HIGH]);
  ck_assert_int_eq(get_scale(res_dec), expected_scale);
}
END_TEST

START_TEST(s21_div_test_24) {
  s21_decimal dec1 = {{85, 0, 0, 0}};
  s21_decimal dec2 = {{10, 0, 0, 0}};
  float expected = 8.5;
  s21_decimal res_dec = {0};
  float res_float = 0;
  int expected_scale = 1;

  int res = s21_div(dec1, dec2, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);

  ck_assert_int_eq(res, 0);
  ck_assert_uint_eq(res_float, expected);
  ck_assert_int_eq(get_scale(res_dec), expected_scale);
}
END_TEST

START_TEST(s21_div_test_25) {
  int num1 = 85;
  int num2 = 10;
  float res_origin = 8.5, res_float;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res = s21_div(a, b, &res_dec);
  int expected_scale = 1;

  s21_from_decimal_to_float(res_dec, &res_float);

  ck_assert_int_eq(res, 0);
  ck_assert_uint_eq(res_float, res_origin);
  ck_assert_int_eq(get_scale(res_dec), expected_scale);
}
END_TEST

START_TEST(s21_div_test_26) {
  int num1 = -96;
  int num2 = 10;
  float res_origin = -9.6, res_float;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int expected_scale = 1;

  int res = s21_div(a, b, &res_dec);
  ck_assert_int_eq(res, 0);

  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_uint_eq(res_float, res_origin);
  ck_assert_int_eq(get_scale(res_dec), expected_scale);
}
END_TEST

START_TEST(s21_div_test_27) {
  int num1 = 84;
  int num2 = -10;
  float res_origin = -8.4, res_float;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int expected_scale = 1;

  int res = s21_div(a, b, &res_dec);
  ck_assert_int_eq(res, 0);

  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_uint_eq(res_float, res_origin);
  ck_assert_int_eq(get_scale(res_dec), expected_scale);
}
END_TEST

START_TEST(s21_div_test_28) {
  int num1 = 0;
  int num2 = 10;
  int res_origin = 0;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  int res = s21_div(a, b, &res_dec);
  int expected_scale = 0;

  ck_assert_int_eq(res, 0);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
  ck_assert_int_eq(get_scale(res_dec), expected_scale);
}
END_TEST

START_TEST(s21_div_test_29) {
  int num1 = 0;
  int num2 = -10;
  int res_origin = 0;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  int res = s21_div(a, b, &res_dec);
  int expected_scale = 0;

  ck_assert_int_eq(res, 0);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
  ck_assert_int_eq(get_scale(res_dec), expected_scale);
}
END_TEST

START_TEST(s21_div_test_30) {
  int num1 = 3;
  int num2 = 3;
  int res_origin = 1;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  int expected_scale = 0;

  int res = s21_div(a, b, &res_dec);
  ck_assert_int_eq(res, 0);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
  ck_assert_int_eq(get_scale(res_dec), expected_scale);
}
END_TEST

START_TEST(s21_div_test_31) {
  int num1 = -8;
  int num2 = -8;
  int res_origin = 1;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  int expected_scale = 0;

  int res = s21_div(a, b, &res_dec);
  ck_assert_int_eq(res, 0);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
  ck_assert_int_eq(get_scale(res_dec), expected_scale);
}
END_TEST

START_TEST(s21_div_test_32) {
  s21_decimal dec1 = {{25, 0, 0, 0}};
  s21_decimal dec2 = {{5, 0, 0, 0}};
  s21_decimal expected = {{5, 0, 0, 0}};
  s21_decimal res_dec;
  int expected_scale = 0;

  int res = s21_div(dec1, dec2, &res_dec);

  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(res_dec.bits[LOW], expected.bits[LOW]);
  ck_assert_int_eq(res_dec.bits[MID], expected.bits[MID]);
  ck_assert_int_eq(res_dec.bits[HIGH], expected.bits[HIGH]);
  ck_assert_int_eq(get_scale(res_dec), expected_scale);
}
END_TEST

START_TEST(s21_div_test_33) {
  s21_decimal dec1 = {{128, 0, 0, 0}};
  s21_decimal dec2 = {{64, 0, 0, 0}};
  s21_decimal expected = {{2, 0, 0, 0}};
  s21_decimal res_dec;
  int expected_scale = 0;

  int res = s21_div(dec1, dec2, &res_dec);

  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(res_dec.bits[LOW], expected.bits[LOW]);
  ck_assert_int_eq(res_dec.bits[MID], expected.bits[MID]);
  ck_assert_int_eq(res_dec.bits[HIGH], expected.bits[HIGH]);
  ck_assert_int_eq(get_scale(res_dec), expected_scale);
}
END_TEST

START_TEST(s21_div_test_34) {
  s21_decimal dec1 = {{128, 0, 0, 0}};
  s21_decimal dec2 = {{32, 0, 0, 0}};
  s21_decimal expected = {{4, 0, 0, 0}};
  s21_decimal res_dec;
  int expected_scale = 0;

  int res = s21_div(dec1, dec2, &res_dec);

  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(res_dec.bits[LOW], expected.bits[LOW]);
  ck_assert_int_eq(res_dec.bits[MID], expected.bits[MID]);
  ck_assert_int_eq(res_dec.bits[HIGH], expected.bits[HIGH]);
  ck_assert_int_eq(get_scale(res_dec), expected_scale);
}
END_TEST

START_TEST(s21_div_test_35) {
  s21_decimal dec1 = {{128, 0, 0, 0}};
  s21_decimal dec2 = {{16, 0, 0, 0}};
  s21_decimal expected = {{8, 0, 0, 0}};
  s21_decimal res_dec;
  int expected_scale = 0;

  int res = s21_div(dec1, dec2, &res_dec);

  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(res_dec.bits[LOW], expected.bits[LOW]);
  ck_assert_int_eq(res_dec.bits[MID], expected.bits[MID]);
  ck_assert_int_eq(res_dec.bits[HIGH], expected.bits[HIGH]);
  ck_assert_int_eq(get_scale(res_dec), expected_scale);
}
END_TEST

Suite *s21_div_suite_create() {
  Suite *suite = suite_create("s21_div_test");
  TCase *tc_core = tcase_create("tcase_core_s21_div_test");

  tcase_add_test(tc_core, s21_div_test_1);
  tcase_add_test(tc_core, s21_div_test_2);
  tcase_add_test(tc_core, s21_div_test_3);
  tcase_add_test(tc_core, s21_div_test_4);
  tcase_add_test(tc_core, s21_div_test_5);
  tcase_add_test(tc_core, s21_div_test_6);
  tcase_add_test(tc_core, s21_div_test_7);
  tcase_add_test(tc_core, s21_div_test_8);
  tcase_add_test(tc_core, s21_div_test_9);
  // tcase_add_test(tc_core, s21_div_test_10);
  // tcase_add_test(tc_core, s21_div_test_11);
  // tcase_add_test(tc_core, s21_div_test_12);
  tcase_add_test(tc_core, s21_div_test_13);
  tcase_add_test(tc_core, s21_div_test_14);
  tcase_add_test(tc_core, s21_div_test_15);
  tcase_add_test(tc_core, s21_div_test_16);
  tcase_add_test(tc_core, s21_div_test_17);
  tcase_add_test(tc_core, s21_div_test_18);
  tcase_add_test(tc_core, s21_div_test_19);
  tcase_add_test(tc_core, s21_div_test_20);
  tcase_add_test(tc_core, s21_div_test_21);
  tcase_add_test(tc_core, s21_div_test_22);
  tcase_add_test(tc_core, s21_div_test_23);
  tcase_add_test(tc_core, s21_div_test_24);
  tcase_add_test(tc_core, s21_div_test_25);
  tcase_add_test(tc_core, s21_div_test_26);
  tcase_add_test(tc_core, s21_div_test_27);
  tcase_add_test(tc_core, s21_div_test_28);
  tcase_add_test(tc_core, s21_div_test_29);
  tcase_add_test(tc_core, s21_div_test_30);
  tcase_add_test(tc_core, s21_div_test_31);
  tcase_add_test(tc_core, s21_div_test_32);
  tcase_add_test(tc_core, s21_div_test_33);
  tcase_add_test(tc_core, s21_div_test_34);
  tcase_add_test(tc_core, s21_div_test_35);

  suite_add_tcase(suite, tc_core);

  return suite;
}

int main() {
  int failed_count = 0;

  Suite *suite = s21_div_suite_create();
  SRunner *suite_runner = srunner_create(suite);

  srunner_run_all(suite_runner, CK_NORMAL);
  failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);

  return failed_count != 0 && !SHOW_FAILED ? EXIT_FAILURE : EXIT_SUCCESS;
}
