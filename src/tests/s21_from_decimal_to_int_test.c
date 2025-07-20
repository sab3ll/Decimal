#include <check.h>

#include "../s21_decimal.h"

#define SHOW_FAILED TRUE

#define EXPONENT_PLUS_1 65536
#define EXPONENT_PLUS_28 1835008

// dec = 0; res = 0;
START_TEST(s21_from_decimal_to_int_test_1) {
  int expected_value = 0;
  int res = 7618246;  // random number to check res = 0

  s21_decimal value;
  value.bits[LOW] = 0x00000000;
  value.bits[MID] = 0x00000000;
  value.bits[HIGH] = 0x00000000;
  value.bits[OLDER] = 0x00000000;

  int error = s21_from_decimal_to_int(value, &res);

  ck_assert_int_eq(res, expected_value);
  ck_assert_int_eq(error, FALSE);
}
END_TEST

// dec = -0; res = 0;
START_TEST(s21_from_decimal_to_int_test_2) {
  int expected_value = 0;
  int res = 994818;  // random number to check res = 0

  s21_decimal value;
  value.bits[LOW] = 0x00000000;
  value.bits[MID] = 0x00000000;
  value.bits[HIGH] = 0x00000000;
  value.bits[OLDER] = 0x80000000;

  int error = s21_from_decimal_to_int(value, &res);

  ck_assert_int_eq(res, expected_value);
  ck_assert_int_eq(error, FALSE);
}
END_TEST

// dec = 1; res = 1;
START_TEST(s21_from_decimal_to_int_test_3) {
  int expected_value = 1;
  int res = 0;

  s21_decimal value;
  value.bits[LOW] = 0x00000001;
  value.bits[MID] = 0x00000000;
  value.bits[HIGH] = 0x00000000;
  value.bits[OLDER] = 0x00000000;

  int error = s21_from_decimal_to_int(value, &res);

  ck_assert_int_eq(res, expected_value);
  ck_assert_int_eq(error, FALSE);
}
END_TEST

// dec = -1; res = -1;
START_TEST(s21_from_decimal_to_int_test_4) {
  int expected_value = -1;
  int res = 0;

  s21_decimal value;
  value.bits[LOW] = 0x00000001;
  value.bits[MID] = 0x00000000;
  value.bits[HIGH] = 0x00000000;
  value.bits[OLDER] = 0x80000000;

  int error = s21_from_decimal_to_int(value, &res);

  ck_assert_int_eq(res, expected_value);
  ck_assert_int_eq(error, FALSE);
}
END_TEST

// dec = INT32_MAX; res = INT32_MAX;
START_TEST(s21_from_decimal_to_int_test_5) {
  int expected_value = INT32_MAX;
  int res = 0;

  s21_decimal value;
  value.bits[LOW] = 0x7FFFFFFF;
  value.bits[MID] = 0x00000000;
  value.bits[HIGH] = 0x00000000;
  value.bits[OLDER] = 0x00000000;

  int error = s21_from_decimal_to_int(value, &res);

  ck_assert_int_eq(res, expected_value);
  ck_assert_int_eq(error, FALSE);
}
END_TEST

// dec = -INT32_MAX; res = -INT32_MAX;
START_TEST(s21_from_decimal_to_int_test_6) {
  int expected_value = -INT32_MAX;
  int res = 0;

  s21_decimal value;
  value.bits[LOW] = 0x7FFFFFFF;
  value.bits[MID] = 0x00000000;
  value.bits[HIGH] = 0x00000000;
  value.bits[OLDER] = 0x80000000;

  int error = s21_from_decimal_to_int(value, &res);

  ck_assert_int_eq(res, expected_value);
  ck_assert_int_eq(error, FALSE);
}
END_TEST

// dec = 87491824; res = 87491824;
START_TEST(s21_from_decimal_to_int_test_8) {
  int expected_value = 87491824;
  int res = 0;

  s21_decimal value;
  value.bits[LOW] = 0x053704F0;
  value.bits[MID] = 0x00000000;
  value.bits[HIGH] = 0x00000000;
  value.bits[OLDER] = 0x00000000;

  int error = s21_from_decimal_to_int(value, &res);

  ck_assert_int_eq(res, expected_value);
  ck_assert_int_eq(error, FALSE);
}
END_TEST

// dec = -87491824; res = -87491824;
START_TEST(s21_from_decimal_to_int_test_9) {
  int expected_value = -87491824;
  int res = 0;

  s21_decimal value;
  value.bits[LOW] = 0x053704F0;
  value.bits[MID] = 0x00000000;
  value.bits[HIGH] = 0x00000000;
  value.bits[OLDER] = 0x80000000;

  int error = s21_from_decimal_to_int(value, &res);

  ck_assert_int_eq(res, expected_value);
  ck_assert_int_eq(error, FALSE);
}
END_TEST

// dec with MID trash; return error;
START_TEST(s21_from_decimal_to_int_test_10) {
  int res = 0;

  s21_decimal value;
  value.bits[LOW] = 0x00000000;
  value.bits[MID] = 0x00010000;
  value.bits[HIGH] = 0x00000000;
  value.bits[OLDER] = 0x00000000;

  int error = s21_from_decimal_to_int(value, &res);

  ck_assert_int_eq(error, TRUE);
}
END_TEST

// dec with HIGH trash; return error;
START_TEST(s21_from_decimal_to_int_test_11) {
  int res = 0;

  s21_decimal value;
  value.bits[LOW] = 0x00000000;
  value.bits[MID] = 0x00000000;
  value.bits[HIGH] = 0x00100000;
  value.bits[OLDER] = 0x00000000;

  int error = s21_from_decimal_to_int(value, &res);

  ck_assert_int_eq(error, TRUE);
}
END_TEST

// dec has value with HIGH trash; return error;
START_TEST(s21_from_decimal_to_int_test_12) {
  int res = 0;

  s21_decimal value;
  value.bits[LOW] = 0x00000010;
  value.bits[MID] = 0x00000000;
  value.bits[HIGH] = 0x00100000;
  value.bits[OLDER] = 0x80000000;

  int error = s21_from_decimal_to_int(value, &res);

  ck_assert_int_eq(error, TRUE);
}
END_TEST

START_TEST(s21_from_decimal_to_int_test_13) {
  s21_decimal val = {{123456789, 0, 0, 0}};
  set_scale(&val, 5);
  int res = 1234;
  int tmp = 0;
  int *dst = &tmp;
  s21_from_decimal_to_int(val, dst);
  ck_assert_int_eq(*dst, res);
}
END_TEST

START_TEST(s21_from_decimal_to_int_test_14) {
  s21_decimal val = {{123456789, 0, 0, 0}};
  set_bit(&val, 127, 1);
  set_scale(&val, 5);
  int res = -1234;
  int tmp = 0;
  int *dst = &tmp;
  s21_from_decimal_to_int(val, dst);
  ck_assert_int_eq(*dst, res);
}
END_TEST

START_TEST(s21_from_decimal_to_int_test_15) {
  s21_decimal var = {{0, 0, 0, 0}};
  int value = 0;
  s21_from_int_to_decimal(5, &var);
  s21_from_decimal_to_int(var, &value);
  ck_assert_int_eq(5, value);
}
END_TEST

START_TEST(s21_from_decimal_to_int_test_16) {
  int n = 666;
  s21_decimal var = {{0, 1, 0, 0}};
  int value = 0;
  s21_from_int_to_decimal(n, &var);
  s21_from_decimal_to_int(var, &value);
  ck_assert_uint_eq(n, value);
}
END_TEST

START_TEST(s21_from_decimal_to_int_test_17) {
  s21_decimal src = {{0}};
  int result = 0, number = 0;
  src.bits[0] = INT_MAX;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = 0;
  result = s21_from_decimal_to_int(src, &number);
  ck_assert_uint_eq(number, 2147483647);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_int_test_18) {
  s21_decimal src = {{0}};
  int result = 0, number = 0;
  src.bits[0] = 133141;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = 0;
  result = s21_from_decimal_to_int(src, &number);
  ck_assert_int_eq(number, 133141);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_int_test_19) {
  s21_decimal src = {{0}};
  int result = 0, number = 0;
  long int c = 2147483648;
  src.bits[0] = 123451234;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = c;
  result = s21_from_decimal_to_int(src, &number);
  ck_assert_int_eq(number, -123451234);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_int_test_20) {
  s21_decimal src = {{0}};
  int result = 0, number = 0;
  long int c = 2147483648;
  src.bits[0] = 18;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = c;  // 2147483648
  result = s21_from_decimal_to_int(src, &number);
  ck_assert_int_eq(number, -18);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_int_test_21) {
  s21_decimal src = {{0}};
  int result = 0, number = 0;
  src.bits[0] = UINT_MAX;
  src.bits[1] = UINT_MAX;
  src.bits[2] = 0;
  src.bits[3] = 0;
  result = s21_from_decimal_to_int(src, &number);
  ck_assert_int_eq(number, 0);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(s21_from_decimal_to_int_test_22) {
  int check, result, code;
  s21_decimal a = {{100, 0, 0, 0}};
  check = 100;
  code = s21_from_decimal_to_int(a, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_int_test_23) {
  int check, result, code;
  s21_decimal a = {{INT_MAX, 0, 0, 0}};
  check = INT_MAX;
  code = s21_from_decimal_to_int(a, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_int_test_24) {
  // int check = 0;
  int result, code;
  s21_decimal a = {{INT_MAX, INT_MAX, INT_MAX, 0}};

  code = s21_from_decimal_to_int(a, &result);
  //   ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(s21_from_decimal_to_int_test_25) {
  int result, code;
  s21_decimal a = {{INT_MAX, INT_MAX, INT_MAX, INT_MAX}};
  // int check = 0;
  code = s21_from_decimal_to_int(a, &result);
  //   ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(s21_from_decimal_to_int_test_26) {
  int code;
  // int check, result;
  s21_decimal src1;
  int error = 0;
  //   s21_decimal src1 = {{UINT_MAX, 0, 0, 0}};
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  //   unsigned int check1 = UINT_MAX;
  int result1 = 0;
  code = s21_from_decimal_to_int(src1, &result1);
  // error = check_bits_decimal_int(&src1, result1);
  //    ck_assert_int_eq(result1, check1);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_int_test_27) {
  int check, result, code;
  s21_decimal a = {{UINT_MAX, 0, 0, 0}};
  check = -1;
  code = s21_from_decimal_to_int(a, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_int_test_28) {
  int check, result, code;
  result = 0;
  s21_decimal a = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  check = 0;
  code = s21_from_decimal_to_int(a, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(s21_from_decimal_to_int_test_29) {
  int result, code;
  s21_decimal a = {{UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX}};
  // int check = 0;
  code = s21_from_decimal_to_int(a, &result);
  //   ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(s21_from_decimal_to_int_test_30) {
  int check, result, code;
  s21_decimal a = {{INT_MAX, 0, 0, INT_MIN}};
  check = -INT_MAX;
  code = s21_from_decimal_to_int(a, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_int_test_31) {
  int check, result, code;
  s21_decimal a = {{INT_MAX, 0, 0, INT_MIN}};

  check = -INT_MAX;
  code = s21_from_decimal_to_int(a, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_int_test_32) {
  int check, result, code;
  s21_decimal a = {{INT_MAX, 0, 0, EXPONENT_PLUS_1}};
  check = 214748364;  // (int)(INT_MAX / 10^1)
  code = s21_from_decimal_to_int(a, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_int_test_33) {
  int check, result, code;
  s21_decimal a = {{INT_MAX, 0, 0, EXPONENT_PLUS_28}};
  check = 0;  // (int)(INT_MAX / 10^28)
  code = s21_from_decimal_to_int(a, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_int_test_34) {
  int check, result, code;
  s21_decimal a;
  a.bits[0] = 0b10000000000000000000000000000000;
  a.bits[1] = 0b00000000000000000000000000000000;
  a.bits[2] = 0b00000000000000000000000000000000;
  a.bits[3] = 0b00000000000000000000000000000001;
  check = -2147483648;
  code = s21_from_decimal_to_int(a, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_int_test_35) {
  int check, result, code;
  s21_decimal a;
  a.bits[0] = 0b00000000000000000000000000000001;
  a.bits[1] = 0b00000000000000000000000000000000;
  a.bits[2] = 0b00000000000000000000000000000000;
  a.bits[3] = 0b00000000000000000000000000000000;
  check = 1;
  code = s21_from_decimal_to_int(a, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_int_test_36) {
  int check, result, code;
  s21_decimal a;
  a.bits[0] = 0b10000000000000000000000000000001;
  a.bits[1] = 0b00000000000000000000000000000000;
  a.bits[2] = 0b00000000000000000000000000000000;
  a.bits[3] = 0b00000000000000000000000000000000;
  check = -2147483647;
  code = s21_from_decimal_to_int(a, &result);
  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_int_test_37) {
  // 6556
  s21_decimal src1;
  // src1 = 2;

  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  int result = 0;
  int *res = &result;
  s21_from_decimal_to_int(src1, res);
  ck_assert_int_eq(result, 2);
}
END_TEST

START_TEST(s21_from_decimal_to_int_test_38) {
  // 6570
  s21_decimal src1;
  // src1 = 0;

  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  int result = 0;
  int *res = &result;
  s21_from_decimal_to_int(src1, res);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_int_test_39) {
  // 6584
  s21_decimal src1;
  // src1 = 3.5;

  src1.bits[0] = 0b00000000000000000000000000100011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  int result = 0;
  int *res = &result;
  s21_from_decimal_to_int(src1, res);
  ck_assert_int_eq(result, 3);
}
END_TEST

START_TEST(s21_from_decimal_to_int_test_40) {
  // 6598
  s21_decimal src1;
  // src1 = 4.5;

  src1.bits[0] = 0b00000000000000000000000000101101;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  int result = 0;
  int *res = &result;
  s21_from_decimal_to_int(src1, res);
  ck_assert_int_eq(result, 4);
}
END_TEST

START_TEST(s21_from_decimal_to_int_test_41) {
  // 6612
  s21_decimal src1;
  // src1 = -4.5;

  src1.bits[0] = 0b00000000000000000000000000101101;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000010000000000000000;
  int result = 0;
  int *res = &result;
  s21_from_decimal_to_int(src1, res);
  ck_assert_int_eq(result, -4);
}
END_TEST

START_TEST(s21_from_decimal_to_int_test_42) {
  // 6696
  s21_decimal src1;
  // src1 = 1;

  src1.bits[0] = 0b00000000000000000000000000000001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  int result = 0;
  int *res = &result;
  s21_from_decimal_to_int(src1, res);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(s21_from_decimal_to_int_test_43) {
  // 6710
  s21_decimal src1;
  // src1 = 1.25;

  src1.bits[0] = 0b00000000000000000000000001111101;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000100000000000000000;
  int result = 0;
  int *res = &result;
  s21_from_decimal_to_int(src1, res);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(s21_from_decimal_to_int_test_44) {
  // 6724
  s21_decimal src1;
  // src1 = -1.25;

  src1.bits[0] = 0b00000000000000000000000001111101;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000100000000000000000;
  int result = 0;
  int *res = &result;
  s21_from_decimal_to_int(src1, res);
  ck_assert_int_eq(result, -1);
}
END_TEST

START_TEST(s21_from_decimal_to_int_test_45) {
  // 6738
  s21_decimal src1;
  // src1 = -12.25;

  src1.bits[0] = 0b00000000000000000000010011001001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000100000000000000000;
  int result = 0;
  int *res = &result;
  s21_from_decimal_to_int(src1, res);
  ck_assert_int_eq(result, -12);
}
END_TEST

START_TEST(s21_from_decimal_to_int_test_46) {
  // 6752
  s21_decimal src1;
  // src1 = -3.5;

  src1.bits[0] = 0b00000000000000000000000000100011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000010000000000000000;
  int result = 0;
  int *res = &result;
  s21_from_decimal_to_int(src1, res);
  ck_assert_int_eq(result, -3);
}
END_TEST

Suite *s21_from_decimal_to_int_suite_create() {
  Suite *suite = suite_create("s21_from_decimal_to_int_test");
  TCase *tc_core = tcase_create("tcase_core_s21_from_decimal_to_int_test");

  tcase_add_test(tc_core, s21_from_decimal_to_int_test_1);
  tcase_add_test(tc_core, s21_from_decimal_to_int_test_2);
  tcase_add_test(tc_core, s21_from_decimal_to_int_test_3);
  tcase_add_test(tc_core, s21_from_decimal_to_int_test_4);
  tcase_add_test(tc_core, s21_from_decimal_to_int_test_5);
  tcase_add_test(tc_core, s21_from_decimal_to_int_test_6);
  tcase_add_test(tc_core, s21_from_decimal_to_int_test_8);
  tcase_add_test(tc_core, s21_from_decimal_to_int_test_9);
  tcase_add_test(tc_core, s21_from_decimal_to_int_test_10);
  tcase_add_test(tc_core, s21_from_decimal_to_int_test_11);
  tcase_add_test(tc_core, s21_from_decimal_to_int_test_12);
  tcase_add_test(tc_core, s21_from_decimal_to_int_test_13);
  tcase_add_test(tc_core, s21_from_decimal_to_int_test_14);
  tcase_add_test(tc_core, s21_from_decimal_to_int_test_15);
  tcase_add_test(tc_core, s21_from_decimal_to_int_test_16);
  tcase_add_test(tc_core, s21_from_decimal_to_int_test_17);
  tcase_add_test(tc_core, s21_from_decimal_to_int_test_18);
  tcase_add_test(tc_core, s21_from_decimal_to_int_test_19);
  tcase_add_test(tc_core, s21_from_decimal_to_int_test_20);
  tcase_add_test(tc_core, s21_from_decimal_to_int_test_21);
  tcase_add_test(tc_core, s21_from_decimal_to_int_test_22);
  tcase_add_test(tc_core, s21_from_decimal_to_int_test_23);
  tcase_add_test(tc_core, s21_from_decimal_to_int_test_24);
  tcase_add_test(tc_core, s21_from_decimal_to_int_test_25);
  tcase_add_test(tc_core, s21_from_decimal_to_int_test_26);
  tcase_add_test(tc_core, s21_from_decimal_to_int_test_27);
  tcase_add_test(tc_core, s21_from_decimal_to_int_test_28);
  tcase_add_test(tc_core, s21_from_decimal_to_int_test_29);
  tcase_add_test(tc_core, s21_from_decimal_to_int_test_30);
  tcase_add_test(tc_core, s21_from_decimal_to_int_test_31);
  tcase_add_test(tc_core, s21_from_decimal_to_int_test_32);
  tcase_add_test(tc_core, s21_from_decimal_to_int_test_33);
  tcase_add_test(tc_core, s21_from_decimal_to_int_test_34);
  tcase_add_test(tc_core, s21_from_decimal_to_int_test_35);
  tcase_add_test(tc_core, s21_from_decimal_to_int_test_36);
  tcase_add_test(tc_core, s21_from_decimal_to_int_test_37);
  tcase_add_test(tc_core, s21_from_decimal_to_int_test_38);
  tcase_add_test(tc_core, s21_from_decimal_to_int_test_39);
  tcase_add_test(tc_core, s21_from_decimal_to_int_test_40);
  tcase_add_test(tc_core, s21_from_decimal_to_int_test_41);
  tcase_add_test(tc_core, s21_from_decimal_to_int_test_42);
  tcase_add_test(tc_core, s21_from_decimal_to_int_test_43);
  tcase_add_test(tc_core, s21_from_decimal_to_int_test_44);
  tcase_add_test(tc_core, s21_from_decimal_to_int_test_45);
  tcase_add_test(tc_core, s21_from_decimal_to_int_test_46);

  suite_add_tcase(suite, tc_core);

  return suite;
}

int main() {
  int failed_count = 0;

  Suite *suite = s21_from_decimal_to_int_suite_create();
  SRunner *suite_runner = srunner_create(suite);

  srunner_run_all(suite_runner, CK_NORMAL);
  failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);

  return failed_count != 0 && !SHOW_FAILED ? EXIT_FAILURE : EXIT_SUCCESS;
}
