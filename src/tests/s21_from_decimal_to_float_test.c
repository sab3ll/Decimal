#include <check.h>
#include <stdlib.h>

#include "../s21_decimal.h"

#define SHOW_FAILED TRUE

START_TEST(s21_from_decimal_to_float_test_1) {
  s21_decimal val = {{123456789, 0, 0, 0}};
  set_scale(&val, 5);
  float res = 1234.56789;
  float tmp = 0.;
  float *dst = &tmp;

  s21_from_decimal_to_float(val, dst);

  ck_assert_uint_eq(*dst, res);
}
END_TEST

START_TEST(s21_from_decimal_to_float_test_2) {
  s21_decimal val = {{123456789, 0, 0, 0}};
  set_scale(&val, 5);
  set_sign(&val, MINUS);
  float res = -1234.56789;
  float tmp = 0.;
  float *dst = &tmp;

  s21_from_decimal_to_float(val, dst);

  float ret = 0.0;
  s21_from_decimal_to_float(val, &ret);

  ck_assert_uint_eq(ret, res);
}
END_TEST

START_TEST(s21_from_decimal_to_float_test_3) {
  s21_decimal var = {{0, 0, 0, 0}};
  float value = 0;

  s21_from_float_to_decimal(5.0, &var);
  s21_from_decimal_to_float(var, &value);

  ck_assert_uint_eq(5.0, value);
}
END_TEST

START_TEST(s21_from_decimal_to_float_test_4) {
  float n = rand();
  s21_decimal var = {{0, 0, 0, 0}};
  float value = 0;

  s21_from_float_to_decimal(n, &var);
  s21_from_decimal_to_float(var, &value);

  ck_assert_uint_eq(n, value);
}
END_TEST

START_TEST(s21_from_decimal_to_float_test_5) {
  float n = rand();
  s21_decimal var = {{0, 0, 0, 0}};
  float value = 0;

  s21_from_float_to_decimal(n, &var);
  s21_from_decimal_to_float(var, &value);

  ck_assert_uint_eq(n, value);
}
END_TEST

START_TEST(s21_from_decimal_to_float_test_6) {
  s21_decimal var = {0};
  float value = 0;

  s21_from_float_to_decimal(5.0, &var);
  s21_from_decimal_to_float(var, &value);

  ck_assert_uint_eq(5.0, value);
}
END_TEST

START_TEST(s21_from_decimal_to_float_test_7) {
  float n = rand();
  s21_decimal var = {0};
  float value = 0;

  s21_from_float_to_decimal(n, &var);
  s21_from_decimal_to_float(var, &value);

  ck_assert_uint_eq(n, value);
}
END_TEST

START_TEST(s21_from_decimal_to_float_test_8) {
  float n = rand();
  s21_decimal var = {0};
  float value = 0;

  s21_from_float_to_decimal(n, &var);
  s21_from_decimal_to_float(var, &value);

  ck_assert_uint_eq(n, value);
}
END_TEST

START_TEST(s21_from_decimal_to_float_test_9) {
  s21_decimal value = {{1812, 0, 0, 0}};
  set_sign(&value, MINUS);
  float result = 0;
  float check = -1812;
  int return_value = s21_from_decimal_to_float(value, &result);

  ck_assert_uint_eq(result, check);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_float_test_10) {
  s21_decimal value = {{18122, 0, 0, 0}};
  set_scale(&value, 3);
  set_sign(&value, MINUS);
  float result = 0;
  float check = -18.122;
  int return_value = s21_from_decimal_to_float(value, &result);

  ck_assert_uint_eq(result, check);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_float_test_11) {
  s21_decimal value = {{0xFFFFFF, 0, 0, 0}};
  float result = 0;
  float check = 16777215;
  int return_value = s21_from_decimal_to_float(value, &result);

  ck_assert_uint_eq(result, check);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_float_test_12) {
  s21_decimal value = {{0xFFFFFFFF, 0xFFFFFFFF, 0, 0}};
  float result = 0;
  float check = 0xFFFFFFFFFFFFFFFF;
  int return_value = s21_from_decimal_to_float(value, &result);

  ck_assert_uint_eq(result, check);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_float_test_13) {
  s21_decimal src = {0};
  int result = 0;
  float number = 0.0;
  src.bits[LOW] = 23450987;
  src.bits[MID] = 0;
  src.bits[HIGH] = 0;
  src.bits[OLDER] = 2147745792;
  result = s21_from_decimal_to_float(src, &number);

  // ck_assert_uint_eq(number, -2345.0987);
  ck_assert_int_eq(result, 0);
}
END_TEST

Suite *s21_from_decimal_to_float_suite_create() {
  Suite *suite = suite_create("s21_from_decimal_to_float_test");
  TCase *tc_core = tcase_create("tcase_core_s21_from_decimal_to_float_test");

  tcase_add_test(tc_core, s21_from_decimal_to_float_test_1);
  tcase_add_test(tc_core, s21_from_decimal_to_float_test_2);
  tcase_add_test(tc_core, s21_from_decimal_to_float_test_3);
  tcase_add_test(tc_core, s21_from_decimal_to_float_test_4);
  tcase_add_test(tc_core, s21_from_decimal_to_float_test_5);
  tcase_add_test(tc_core, s21_from_decimal_to_float_test_6);
  tcase_add_test(tc_core, s21_from_decimal_to_float_test_7);
  tcase_add_test(tc_core, s21_from_decimal_to_float_test_8);
  tcase_add_test(tc_core, s21_from_decimal_to_float_test_9);
  tcase_add_test(tc_core, s21_from_decimal_to_float_test_10);
  tcase_add_test(tc_core, s21_from_decimal_to_float_test_11);
  tcase_add_test(tc_core, s21_from_decimal_to_float_test_12);
  tcase_add_test(tc_core, s21_from_decimal_to_float_test_13);

  suite_add_tcase(suite, tc_core);

  return suite;
}

int main() {
  int failed_count = 0;

  Suite *suite = s21_from_decimal_to_float_suite_create();
  SRunner *suite_runner = srunner_create(suite);

  srunner_run_all(suite_runner, CK_NORMAL);
  failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);

  return failed_count != 0 && !SHOW_FAILED ? EXIT_FAILURE : EXIT_SUCCESS;
}
