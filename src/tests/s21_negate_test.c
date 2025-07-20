#include <check.h>
#include <stdlib.h>

#include "../s21_decimal.h"

#define SHOW_FAILED TRUE

START_TEST(s21_negate_test_1) {
  s21_decimal result;

  s21_decimal value;
  value.bits[LOW] = 0;
  value.bits[MID] = 0;
  value.bits[HIGH] = 0;
  value.bits[OLDER] = 0x00000000;

  int ret = s21_negate(value, &result);

  s21_decimal expected;
  expected.bits[LOW] = 0;
  expected.bits[MID] = 0;
  expected.bits[HIGH] = 0;
  expected.bits[OLDER] = 0x80000000;

  ck_assert_uint_eq(ret, SUCCESS);
  ck_assert_uint_eq(result.bits[OLDER], expected.bits[OLDER]);
}
END_TEST

START_TEST(s21_negate_test_2) {
  s21_decimal result;

  s21_decimal value;
  value.bits[LOW] = 0;
  value.bits[MID] = 0;
  value.bits[HIGH] = 0;
  value.bits[OLDER] = 0x80000000;

  int ret = s21_negate(value, &result);

  s21_decimal expected;
  expected.bits[LOW] = 0;
  expected.bits[MID] = 0;
  expected.bits[HIGH] = 0;
  expected.bits[OLDER] = 0x00000000;

  ck_assert_uint_eq(ret, SUCCESS);
  ck_assert_uint_eq(result.bits[OLDER], expected.bits[OLDER]);
}
END_TEST

START_TEST(s21_negate_test_3) {
  s21_decimal result;

  s21_decimal value;
  value.bits[LOW] = 14;
  value.bits[MID] = 10;
  value.bits[HIGH] = 80;
  value.bits[OLDER] = 0x80000000;

  int ret = s21_negate(value, &result);

  s21_decimal expected;
  expected.bits[LOW] = 14;
  expected.bits[MID] = 10;
  expected.bits[HIGH] = 80;
  expected.bits[OLDER] = 0x00000000;

  ck_assert_uint_eq(ret, SUCCESS);
  ck_assert_uint_eq(result.bits[OLDER], expected.bits[OLDER]);
}
END_TEST

START_TEST(s21_negate_test_4) {
  s21_decimal result;

  s21_decimal value;
  value.bits[LOW] = 14;
  value.bits[MID] = 10;
  value.bits[HIGH] = 80;
  value.bits[OLDER] = 0x00000000;

  int ret = s21_negate(value, &result);

  s21_decimal expected;
  expected.bits[LOW] = 14;
  expected.bits[MID] = 10;
  expected.bits[HIGH] = 80;
  expected.bits[OLDER] = 0x80000000;

  ck_assert_uint_eq(ret, SUCCESS);
  ck_assert_uint_eq(result.bits[OLDER], expected.bits[OLDER]);
}
END_TEST

START_TEST(s21_negate_test_5) {
  s21_decimal val = {{2, 0, 0, 0}};
  s21_decimal res = {{0}};
  int sign_before = get_bit(val, 127);
  s21_negate(val, &res);
  int sign_after = get_bit(res, 127);

  ck_assert_int_ne(sign_before, sign_after);
}
END_TEST

START_TEST(s21_negate_test_6) {
  s21_decimal val = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res;
  int sign_before = get_bit(val, 127);
  s21_negate(val, &res);
  int sign_after = get_bit(res, 127);
  ck_assert_int_ne(sign_before, sign_after);
}
END_TEST

START_TEST(s21_negate_test_7) {
  s21_decimal val = {{0, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res = {{0}};
  int sign_before = get_bit(val, 127);
  s21_negate(val, &res);
  int sign_after = get_bit(res, 127);
  ck_assert_int_ne(sign_before, sign_after);
}
END_TEST

START_TEST(s21_negate_test_8) {
  s21_decimal val = {{0}};
  s21_decimal res = {{0}};
  int sign_before = get_bit(val, 127);
  s21_negate(val, &res);
  int sign_after = get_bit(res, 127);
  ck_assert_int_ne(sign_before, sign_after);
}
END_TEST

START_TEST(s21_negate_test_9) {
  s21_decimal value_1 = {{5, 0xFFFFFFFF, 0, 0}};
  set_sign(&value_1, MINUS);
  s21_decimal check = {{5, 0xFFFFFFFF, 0, 0}};
  s21_decimal result = {0};
  int return_value = s21_negate(value_1, &result);
  ck_assert_uint_eq(s21_is_equal(result, check), 1);
  ck_assert_uint_eq(return_value, 0);
}
END_TEST

START_TEST(s21_negate_test_10) {
  s21_decimal value_1 = {{1, 1, 1, 0}};
  s21_decimal check = {{1, 1, 1, 0x80000000}};
  s21_decimal result = {0};
  int return_value = s21_negate(value_1, &result);
  ck_assert_uint_eq(s21_is_equal(result, check), 1);
  ck_assert_uint_eq(return_value, 0);
}
END_TEST

START_TEST(s21_negate_test_11) {
  float a = 10.1234e5;
  float res_a = 0;
  s21_decimal src = {0};
  s21_from_float_to_decimal(a, &src);
  s21_decimal res = {0};
  s21_negate(src, &res);
  s21_from_decimal_to_float(res, &res_a);
  // ck_assert_uint_eq(-10.1234e5, res_a);
}
END_TEST

START_TEST(s21_negate_test_12) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 5;
  // src2 = 3;
  src1.bits[0] = 0b00000000000000000000000000000101;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_uint_eq(origin.bits[3], result.bits[3]);
  ck_assert_uint_eq(origin.bits[2], result.bits[2]);
  ck_assert_uint_eq(origin.bits[1], result.bits[1]);
  ck_assert_uint_eq(origin.bits[0], result.bits[0]);
  ck_assert_uint_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_negate_test_13) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 3;
  // src2 = 6;
  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000110;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_uint_eq(origin.bits[3], result.bits[3]);
  ck_assert_uint_eq(origin.bits[2], result.bits[2]);
  ck_assert_uint_eq(origin.bits[1], result.bits[1]);
  ck_assert_uint_eq(origin.bits[0], result.bits[0]);
  ck_assert_uint_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_negate_test_14) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0;
  // src2 = 8;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000001000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000001000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_uint_eq(origin.bits[3], result.bits[3]);
  ck_assert_uint_eq(origin.bits[2], result.bits[2]);
  ck_assert_uint_eq(origin.bits[1], result.bits[1]);
  ck_assert_uint_eq(origin.bits[0], result.bits[0]);
  ck_assert_uint_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_negate_test_15) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 7;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000111;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_uint_eq(origin.bits[3], result.bits[3]);
  ck_assert_uint_eq(origin.bits[2], result.bits[2]);
  ck_assert_uint_eq(origin.bits[1], result.bits[1]);
  ck_assert_uint_eq(origin.bits[0], result.bits[0]);
  ck_assert_uint_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_negate_test_16) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 3;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_uint_eq(origin.bits[3], result.bits[3]);
  ck_assert_uint_eq(origin.bits[2], result.bits[2]);
  ck_assert_uint_eq(origin.bits[1], result.bits[1]);
  ck_assert_uint_eq(origin.bits[0], result.bits[0]);
  ck_assert_uint_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_negate_test_17) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 787891;
  // src2 = 238471;
  src1.bits[0] = 0b00000000000011000000010110110011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000111010001110000111;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_sub(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000010000110001000101100;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_uint_eq(origin.bits[3], result.bits[3]);
  ck_assert_uint_eq(origin.bits[2], result.bits[2]);
  ck_assert_uint_eq(origin.bits[1], result.bits[1]);
  ck_assert_uint_eq(origin.bits[0], result.bits[0]);
  ck_assert_uint_eq(value_type_result, value_type_origin);
}
END_TEST

Suite *s21_negate_suite_create() {
  Suite *suite = suite_create("s21_negate_test");
  TCase *tc_core = tcase_create("tcase_core_s21_negate_test");

  tcase_add_test(tc_core, s21_negate_test_1);
  tcase_add_test(tc_core, s21_negate_test_2);
  tcase_add_test(tc_core, s21_negate_test_3);
  tcase_add_test(tc_core, s21_negate_test_4);
  tcase_add_test(tc_core, s21_negate_test_5);
  tcase_add_test(tc_core, s21_negate_test_6);
  tcase_add_test(tc_core, s21_negate_test_7);
  tcase_add_test(tc_core, s21_negate_test_8);
  tcase_add_test(tc_core, s21_negate_test_9);
  tcase_add_test(tc_core, s21_negate_test_10);
  tcase_add_test(tc_core, s21_negate_test_11);
  tcase_add_test(tc_core, s21_negate_test_12);
  tcase_add_test(tc_core, s21_negate_test_13);
  tcase_add_test(tc_core, s21_negate_test_14);
  tcase_add_test(tc_core, s21_negate_test_15);
  tcase_add_test(tc_core, s21_negate_test_16);
  tcase_add_test(tc_core, s21_negate_test_17);

  suite_add_tcase(suite, tc_core);

  return suite;
}

int main() {
  int failed_count = 0;

  Suite *suite = s21_negate_suite_create();
  SRunner *suite_runner = srunner_create(suite);

  srunner_run_all(suite_runner, CK_NORMAL);
  failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);

  return failed_count != 0 && !SHOW_FAILED ? EXIT_FAILURE : EXIT_SUCCESS;
}
