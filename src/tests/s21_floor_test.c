#include <check.h>
#include <stdlib.h>

#include "../s21_decimal.h"

#define SHOW_FAILED TRUE

START_TEST(s21_floor_test_1) {
  s21_decimal val = {{2, 0, 0, 0}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_floor(val, &res));
}
END_TEST

START_TEST(s21_floor_test_2) {
  s21_decimal val = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res = {{0}};
  s21_floor(val, &res);
  float fres = 0;
  s21_from_decimal_to_float(res, &fres);
  ck_assert_uint_eq(0, fres);
}
END_TEST

START_TEST(s21_floor_test_3) {
  s21_decimal val = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res = {{0}};
  set_scale(&val, 5);
  s21_floor(val, &res);
  float fres = 0;
  s21_from_decimal_to_float(res, &fres);
  ck_assert_uint_eq(0, fres);
}
END_TEST

START_TEST(s21_floor_test_4) {
  s21_decimal val = {{2, 0, 0, 0}};
  s21_decimal res = {{0}};
  set_scale(&val, 5);
  s21_floor(val, &res);
  float fres = 0;
  s21_from_decimal_to_float(res, &fres);
  ck_assert_uint_eq(0, fres);
}
END_TEST

START_TEST(s21_floor_test_5) {
  s21_decimal value_1 = {{7444923, 0, 0, 0}};
  set_scale(&value_1, 5);
  s21_decimal check = {{74, 0, 0, 0}};
  s21_decimal result = {0};
  int return_value = s21_floor(value_1, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_floor_test_6) {
  s21_decimal value_1 = {{7444923, 0, 0, 0}};
  set_scale(&value_1, 5);
  set_bit(&value_1, 127, 1);
  s21_decimal check = {{75, 0, 0, 0}};
  set_bit(&check, 127, 1);
  s21_decimal result = {0};
  int return_value = s21_floor(value_1, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_floor_test_7) {
  s21_decimal src1;
  src1.bits[0] = 0b00001111111111111111111111111111;
  src1.bits[1] = 0b00111110001001010000001001100001;
  src1.bits[2] = 0b00100000010011111100111001011110;
  src1.bits[3] = 0b10000000000010100000000000000000;
  s21_decimal res_od = {0};
  s21_floor(src1, &res_od);
  s21_decimal result = {0};
  result.bits[0] = 0b10100111011001000000000000000000;
  result.bits[1] = 0b00001101111000001011011010110011;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_uint_eq(res_od.bits[0], result.bits[0]);
  ck_assert_uint_eq(res_od.bits[1], result.bits[1]);
  ck_assert_uint_eq(res_od.bits[2], result.bits[2]);
  ck_assert_uint_eq(res_od.bits[3], result.bits[3]);
}
END_TEST

Suite *s21_floor_suite_create() {
  Suite *suite = suite_create("s21_floor_test");
  TCase *tc_core = tcase_create("tcase_core_s21_floor_test");

  tcase_add_test(tc_core, s21_floor_test_1);
  tcase_add_test(tc_core, s21_floor_test_2);
  tcase_add_test(tc_core, s21_floor_test_3);
  tcase_add_test(tc_core, s21_floor_test_4);
  tcase_add_test(tc_core, s21_floor_test_5);
  tcase_add_test(tc_core, s21_floor_test_6);
  tcase_add_test(tc_core, s21_floor_test_7);

  suite_add_tcase(suite, tc_core);

  return suite;
}

int main() {
  int failed_count = 0;

  Suite *suite = s21_floor_suite_create();
  SRunner *suite_runner = srunner_create(suite);

  srunner_run_all(suite_runner, CK_NORMAL);
  failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);

  return failed_count != 0 && !SHOW_FAILED ? EXIT_FAILURE : EXIT_SUCCESS;
}
