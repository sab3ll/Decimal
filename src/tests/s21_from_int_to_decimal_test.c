#include <check.h>

#include "../s21_decimal.h"

#define SHOW_FAILED TRUE

// 0
START_TEST(s21_from_int_to_decimal_test_1) {
  s21_decimal value;
  int error = s21_from_int_to_decimal(0, &value);

  ck_assert_int_eq(value.bits[LOW], 0);
  ck_assert_int_eq(value.bits[MID], 0);
  ck_assert_int_eq(value.bits[HIGH], 0);
  ck_assert_int_eq(value.bits[OLDER], 0);

  ck_assert_int_eq(error, FALSE);
}
END_TEST

// -0
START_TEST(s21_from_int_to_decimal_test_2) {
  s21_decimal value;
  int error = s21_from_int_to_decimal(-0, &value);

  ck_assert_int_eq(value.bits[LOW], 0);
  ck_assert_int_eq(value.bits[MID], 0);
  ck_assert_int_eq(value.bits[HIGH], 0);
  ck_assert_int_eq(value.bits[OLDER], 0);

  ck_assert_int_eq(error, FALSE);
}
END_TEST

// 1
START_TEST(s21_from_int_to_decimal_test_3) {
  s21_decimal value;
  int error = s21_from_int_to_decimal(1, &value);

  ck_assert_int_eq(value.bits[LOW], 0x00000001);
  ck_assert_int_eq(value.bits[MID], 0x00000000);
  ck_assert_int_eq(value.bits[HIGH], 0x00000000);
  ck_assert_int_eq(value.bits[OLDER], 0x00000000);

  ck_assert_int_eq(error, FALSE);
}
END_TEST

// -1
START_TEST(s21_from_int_to_decimal_test_4) {
  s21_decimal value;
  int error = s21_from_int_to_decimal(-1, &value);

  ck_assert_int_eq(value.bits[LOW], 0x00000001);
  ck_assert_int_eq(value.bits[MID], 0x00000000);
  ck_assert_int_eq(value.bits[HIGH], 0x00000000);
  ck_assert_int_eq(value.bits[OLDER], 0x80000000);

  ck_assert_int_eq(error, FALSE);
}
END_TEST

// 100
START_TEST(s21_from_int_to_decimal_test_5) {
  s21_decimal value;
  int error = s21_from_int_to_decimal(100, &value);

  ck_assert_int_eq(value.bits[LOW], 0x00000064);
  ck_assert_int_eq(value.bits[MID], 0x00000000);
  ck_assert_int_eq(value.bits[HIGH], 0x00000000);
  ck_assert_int_eq(value.bits[OLDER], 0x00000000);

  ck_assert_int_eq(error, FALSE);
}
END_TEST

// -100
START_TEST(s21_from_int_to_decimal_test_6) {
  s21_decimal value;
  int error = s21_from_int_to_decimal(-100, &value);

  ck_assert_int_eq(value.bits[LOW], 0x00000064);
  ck_assert_int_eq(value.bits[MID], 0x00000000);
  ck_assert_int_eq(value.bits[HIGH], 0x00000000);
  ck_assert_int_eq(value.bits[OLDER], 0x80000000);

  ck_assert_int_eq(error, FALSE);
}
END_TEST

// 255
START_TEST(s21_from_int_to_decimal_test_7) {
  s21_decimal value;
  int error = s21_from_int_to_decimal(255, &value);

  ck_assert_int_eq(value.bits[LOW], 0x000000FF);
  ck_assert_int_eq(value.bits[MID], 0x00000000);
  ck_assert_int_eq(value.bits[HIGH], 0x00000000);
  ck_assert_int_eq(value.bits[OLDER], 0x00000000);

  ck_assert_int_eq(error, FALSE);
}
END_TEST

// -255
START_TEST(s21_from_int_to_decimal_test_8) {
  s21_decimal value;
  int error = s21_from_int_to_decimal(-255, &value);

  ck_assert_int_eq(value.bits[LOW], 0x000000FF);
  ck_assert_int_eq(value.bits[MID], 0x00000000);
  ck_assert_int_eq(value.bits[HIGH], 0x00000000);
  ck_assert_int_eq(value.bits[OLDER], 0x80000000);

  ck_assert_int_eq(error, FALSE);
}
END_TEST

// INT32_MAX
START_TEST(s21_from_int_to_decimal_test_9) {
  s21_decimal value;
  int error = s21_from_int_to_decimal(INT32_MAX, &value);

  ck_assert_int_eq(value.bits[LOW], 0x7FFFFFFF);
  ck_assert_int_eq(value.bits[MID], 0x00000000);
  ck_assert_int_eq(value.bits[HIGH], 0x00000000);
  ck_assert_int_eq(value.bits[OLDER], 0x00000000);

  ck_assert_int_eq(error, FALSE);
}
END_TEST

// INT32_MIN
START_TEST(s21_from_int_to_decimal_test_10) {
  s21_decimal value;
  int error = s21_from_int_to_decimal(INT32_MIN, &value);

  ck_assert_int_eq(value.bits[LOW], 0x80000000);
  ck_assert_int_eq(value.bits[MID], 0x00000000);
  ck_assert_int_eq(value.bits[HIGH], 0x00000000);
  ck_assert_int_eq(value.bits[OLDER], 0x80000000);

  ck_assert_int_eq(error, FALSE);
}
END_TEST

START_TEST(s21_from_int_to_decimal_test_11) {
  s21_decimal val = {{0, 0, 0, 0}};
  int res = 0;
  int tmp = -2147483648;
  s21_from_int_to_decimal(tmp, &val);
  s21_from_decimal_to_int(val, &res);
  ck_assert_int_eq(res, tmp);
}
END_TEST

START_TEST(s21_from_int_to_decimal_test_12) {
  s21_decimal val = {{0, 0, 0, 0}};
  int res = 0;
  int tmp = -123456789;
  s21_from_int_to_decimal(tmp, &val);
  s21_from_decimal_to_int(val, &res);
  ck_assert_int_eq(res, tmp);
}
END_TEST

START_TEST(s21_from_int_to_decimal_test_13) {
  s21_decimal val = {{0, 0, 0, 0}};
  int res = 0;
  int tmp = 2147483647;
  s21_from_int_to_decimal(tmp, &val);
  s21_from_decimal_to_int(val, &res);
  ck_assert_int_eq(res, tmp);
}
END_TEST

START_TEST(s21_from_int_to_decimal_test_14) {
  s21_decimal val = {0};

  s21_from_int_to_decimal(0, &val);
  ck_assert_int_eq(val.bits[0], 0);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);

  initial(&val);
  s21_from_int_to_decimal(-128, &val);
  ck_assert_int_eq(val.bits[0], 128);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 2147483648);

  initial(&val);
  s21_from_int_to_decimal(127, &val);
  ck_assert_int_eq(val.bits[0], 127);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);

  initial(&val);
  s21_from_int_to_decimal(-2147483648, &val);
  ck_assert_int_eq(val.bits[0], 2147483648);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 2147483648);

  initial(&val);
  s21_from_int_to_decimal(2147483647, &val);
  ck_assert_int_eq(val.bits[0], 2147483647);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);
}
END_TEST

START_TEST(s21_from_int_to_decimal_test_15) {
  int a, add, equal;
  a = 100;
  s21_decimal b = {{0, 0, 0, 0}};
  s21_decimal *ptr_b = &b;

  add = s21_from_int_to_decimal(a, ptr_b);  // a записываем в b
  s21_decimal etalon = {{100, 0, 0, 0}};
  ck_assert_int_eq(add, 0);
  // выходное значение s21_from_int_to_decimal - 0 TRUE и 1 FALSE
  // s21_is_equal Возвращаемое значение: 0 - FALSE 1 - TRUE
  equal = s21_is_equal(b, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_from_int_to_decimal_test_16) {
  int a, add, equal;
  a = 100;
  s21_decimal b = {{0, 0, 0, 0}};
  s21_decimal *ptr_b = &b;

  add = s21_from_int_to_decimal(a, ptr_b);  // a записываем в b
  s21_decimal etalon = {{1000, 0, 0, 0}};
  ck_assert_int_eq(add, 0);
  // выходное значение s21_from_int_to_decimal -
  // 0 TRUE и 1 FALSE
  // s21_is_equal Возвращаемое значение: 0 - FALSE 1 - TRUE
  equal = s21_is_equal(b, etalon);
  ck_assert_int_eq(equal, 0);
}
END_TEST

START_TEST(s21_from_int_to_decimal_test_17) {
  int a, add, equal;
  a = INT_MAX;
  s21_decimal b = {{0, 0, 0, 0}};
  s21_decimal *ptr_b = &b;

  add = s21_from_int_to_decimal(a, ptr_b);  // a записываем в b
  s21_decimal etalon = {{INT_MAX, 0, 0, 0}};
  ck_assert_int_eq(add, 0);  // выходное значение s21_from_int_to_decimal -
                             // 0 TRUE и 1 FALSE
  // s21_is_equal Возвращаемое значение: 0 - FALSE 1 - TRUE
  equal = s21_is_equal(b, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_from_int_to_decimal_test_18) {
  int a, add, equal;
  a = -INT_MAX;
  s21_decimal b = {{0, 0, 0, 0}};
  s21_decimal *ptr_b = &b;

  add = s21_from_int_to_decimal(a, ptr_b);  // a записываем в b
  s21_decimal etalon = {{INT_MAX, 0, 0, 0}};
  ck_assert_int_eq(add, 0);  // выходное значение s21_from_int_to_decimal -
                             // 0 TRUE и 1 FALSE
  // s21_is_equal Возвращаемое значение: 0 - FALSE 1 - TRUE
  equal = s21_is_equal(b, etalon);
  ck_assert_int_eq(equal, 0);
}
END_TEST

START_TEST(s21_from_int_to_decimal_test_19) {
  int a, add, equal;
  a = -INT_MAX;
  s21_decimal b = {{0, 0, 0, 0}};
  s21_decimal *ptr_b = &b;

  add = s21_from_int_to_decimal(a, ptr_b);  // a записываем в b
  s21_decimal etalon = {{INT_MAX, 0, 0, ~(INT_MAX)}};
  ck_assert_int_eq(add, 0);  // выходное значение s21_from_int_to_decimal -
                             // 0 TRUE и 1 FALSE
  // s21_is_equal Возвращаемое значение: 0 - FALSE 1 - TRUE
  equal = s21_is_equal(b, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_from_int_to_decimal_test_20) {
  int a, add, equal;
  a = 0;  // ERROR of NAN
  s21_decimal b = {0, 0, 0, 0};
  s21_decimal *ptr_b = &b;

  add = s21_from_int_to_decimal(a, ptr_b);  // a записываем в b
  s21_decimal etalon = {{INT_MAX, 0, 0, ~(INT_MAX)}};
  ck_assert_int_eq(add, 0);  // выходное значение s21_from_int_to_decimal -
                             // 0 TRUE и 1 FALSE
  // s21_is_equal Возвращаемое значение: 0 - FALSE 1 - TRUE
  equal = s21_is_equal(b, etalon);
  ck_assert_int_eq(equal, 0);
}
END_TEST

START_TEST(s21_from_int_to_decimal_test_21) {
  // int a, add, equal;
  // 6412
  int src1 = 1;
  s21_decimal origin = {0}, result = {0};
  s21_decimal *res = &result;
  s21_from_int_to_decimal(src1, res);

  origin.bits[0] = 0b00000000000000000000000000000001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_from_int_to_decimal_test_22) {
  // 6428
  int src1 = -1;
  s21_decimal origin = {0}, result = {0};
  s21_decimal *res = &result;
  s21_from_int_to_decimal(src1, res);

  origin.bits[0] = 0b00000000000000000000000000000001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_from_int_to_decimal_test_23) {
  // 6444
  int src1 = 0;
  s21_decimal origin = {0}, result = {0};
  s21_decimal *res = &result;
  s21_from_int_to_decimal(src1, res);

  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_from_int_to_decimal_test_24) {
  // 6460
  int src1 = 0;
  s21_decimal origin = {0}, result = {0};
  s21_decimal *res = &result;
  s21_from_int_to_decimal(src1, res);

  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_from_int_to_decimal_test_25) {
  // 6476
  int src1 = -987879878;
  s21_decimal origin = {0}, result = {0};
  s21_decimal *res = &result;
  s21_from_int_to_decimal(src1, res);

  origin.bits[0] = 0b00111010111000011101100111000110;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_from_int_to_decimal_test_26) {
  // 6492
  int src1 = -2147483646;
  s21_decimal origin = {0}, result = {0};
  s21_decimal *res = &result;
  s21_from_int_to_decimal(src1, res);

  origin.bits[0] = 0b01111111111111111111111111111110;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_from_int_to_decimal_test_27) {
  // 6508
  int src1 = 2147483646;
  s21_decimal origin = {0}, result = {0};
  s21_decimal *res = &result;
  s21_from_int_to_decimal(src1, res);

  origin.bits[0] = 0b01111111111111111111111111111110;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_from_int_to_decimal_test_28) {
  // 6524
  int src1 = 796132784;
  s21_decimal origin = {0}, result = {0};
  s21_decimal *res = &result;
  s21_from_int_to_decimal(src1, res);

  origin.bits[0] = 0b00101111011101000000010110110000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_from_int_to_decimal_test_29) {
  // 6540
  int src1 = -12345677;
  s21_decimal origin = {0}, result = {0};
  s21_decimal *res = &result;
  s21_from_int_to_decimal(src1, res);
  origin.bits[0] = 0b00000000101111000110000101001101;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

Suite *s21_from_int_to_decimal_suite_create() {
  Suite *suite = suite_create("s21_from_int_to_decimal_test");
  TCase *tc_core = tcase_create("tcase_core_s21_from_int_to_decimal_test");

  tcase_add_test(tc_core, s21_from_int_to_decimal_test_1);
  tcase_add_test(tc_core, s21_from_int_to_decimal_test_2);
  tcase_add_test(tc_core, s21_from_int_to_decimal_test_3);
  tcase_add_test(tc_core, s21_from_int_to_decimal_test_4);
  tcase_add_test(tc_core, s21_from_int_to_decimal_test_5);
  tcase_add_test(tc_core, s21_from_int_to_decimal_test_6);
  tcase_add_test(tc_core, s21_from_int_to_decimal_test_7);
  tcase_add_test(tc_core, s21_from_int_to_decimal_test_8);
  tcase_add_test(tc_core, s21_from_int_to_decimal_test_9);
  tcase_add_test(tc_core, s21_from_int_to_decimal_test_10);
  tcase_add_test(tc_core, s21_from_int_to_decimal_test_11);
  tcase_add_test(tc_core, s21_from_int_to_decimal_test_12);
  tcase_add_test(tc_core, s21_from_int_to_decimal_test_13);
  tcase_add_test(tc_core, s21_from_int_to_decimal_test_14);
  tcase_add_test(tc_core, s21_from_int_to_decimal_test_15);
  tcase_add_test(tc_core, s21_from_int_to_decimal_test_16);
  tcase_add_test(tc_core, s21_from_int_to_decimal_test_17);
  tcase_add_test(tc_core, s21_from_int_to_decimal_test_18);
  tcase_add_test(tc_core, s21_from_int_to_decimal_test_19);
  tcase_add_test(tc_core, s21_from_int_to_decimal_test_20);
  tcase_add_test(tc_core, s21_from_int_to_decimal_test_21);
  tcase_add_test(tc_core, s21_from_int_to_decimal_test_22);
  tcase_add_test(tc_core, s21_from_int_to_decimal_test_23);
  tcase_add_test(tc_core, s21_from_int_to_decimal_test_24);
  tcase_add_test(tc_core, s21_from_int_to_decimal_test_25);
  tcase_add_test(tc_core, s21_from_int_to_decimal_test_26);
  tcase_add_test(tc_core, s21_from_int_to_decimal_test_27);
  tcase_add_test(tc_core, s21_from_int_to_decimal_test_28);
  tcase_add_test(tc_core, s21_from_int_to_decimal_test_29);

  suite_add_tcase(suite, tc_core);

  return suite;
}

int main() {
  int failed_count = 0;

  Suite *suite = s21_from_int_to_decimal_suite_create();
  SRunner *suite_runner = srunner_create(suite);

  srunner_run_all(suite_runner, CK_NORMAL);
  failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);

  return failed_count != 0 && !SHOW_FAILED ? EXIT_FAILURE : EXIT_SUCCESS;
}
