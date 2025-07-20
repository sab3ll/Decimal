#include <check.h>
#include <stdlib.h>

#include "../s21_decimal.h"

#define SHOW_FAILED TRUE

START_TEST(s21_is_greater_or_equal_test_1) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  ck_assert_int_eq(1, s21_is_greater_or_equal(val1, val2));
}
END_TEST

START_TEST(s21_is_greater_or_equal_test_2) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  val1.bits[0] = 255;
  val2.bits[0] = 256;
  ck_assert_int_eq(0, s21_is_greater_or_equal(val1, val2));
}
END_TEST

START_TEST(s21_is_greater_or_equal_test_3) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  val1.bits[0] = 256;
  val2.bits[0] = 256;
  ck_assert_int_eq(1, s21_is_greater_or_equal(val1, val2));
}
END_TEST

START_TEST(s21_is_greater_or_equal_test_4) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  val1.bits[0] = 257;
  val2.bits[0] = 256;
  ck_assert_int_eq(1, s21_is_greater_or_equal(val1, val2));
}
END_TEST

START_TEST(s21_is_greater_or_equal_test_5) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  val1.bits[0] = 257;
  val2.bits[0] = 257;
  val1.bits[2] = 256;
  val2.bits[2] = 257;
  set_scale(&val1, 11);
  set_scale(&val2, 10);
  ck_assert_int_eq(0, s21_is_greater_or_equal(val1, val2));
}
END_TEST

START_TEST(s21_is_greater_or_equal_test_6) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  val1.bits[0] = 257;
  val2.bits[0] = 257;
  val1.bits[2] = 256;
  val2.bits[2] = 257;
  set_scale(&val1, 10);
  set_scale(&val2, 11);
  ck_assert_int_eq(1, s21_is_greater_or_equal(val1, val2));
}
END_TEST

START_TEST(s21_is_greater_or_equal_test_7) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  val2.bits[2] = 257;
  set_bit(&val1, 127, 1);
  set_bit(&val2, 127, 1);
  ck_assert_int_eq(1, s21_is_greater_or_equal(val1, val2));
}
END_TEST

START_TEST(s21_is_greater_or_equal_test_8) {
  float a = rand();
  float b = rand();

  s21_decimal _a = {{0}};
  s21_decimal _b = {{0}};
  s21_from_float_to_decimal(a, &_a);
  s21_from_float_to_decimal(b, &_b);
  ck_assert_int_eq(s21_is_greater_or_equal(_a, _b), a >= b);
}
END_TEST

START_TEST(s21_is_greater_or_equal_test_9) {
  float a = rand();

  s21_decimal _a = {{0}};
  s21_decimal _b = {{0}};
  s21_from_float_to_decimal(a, &_a);
  s21_from_float_to_decimal(a, &_b);
  ck_assert_int_eq(s21_is_greater_or_equal(_a, _b), 1);
}
END_TEST

START_TEST(s21_is_greater_or_equal_test_10) {
  s21_decimal value_1 = {{123457u, 654u, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  int return_value = s21_is_greater_or_equal(value_1, value_2);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(s21_is_greater_or_equal_test_11) {
  s21_decimal value_1 = {{123457u, 654u, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  set_sign(&value_1, MINUS);
  int return_value = s21_is_greater_or_equal(value_1, value_2);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_is_greater_or_equal_test_12) {
  s21_decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{123457u, 654u, 0xFFFFFFFF, 0}};
  set_sign(&value_2, MINUS);
  int return_value = s21_is_greater_or_equal(value_1, value_2);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(s21_is_greater_or_equal_test_13) {
  s21_decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{123457u, 654u, 0xFFFFFFFF, 0}};
  set_sign(&value_1, MINUS);
  set_sign(&value_2, MINUS);
  int return_value = s21_is_greater_or_equal(value_1, value_2);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(s21_is_greater_or_equal_test_14) {
  s21_decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  int return_value = s21_is_greater_or_equal(value_1, value_2);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(s21_is_greater_or_equal_test_15) {
  s21_decimal value_1 = {{12345, 0, 0, 0}};
  set_scale(&value_1, 4);
  s21_decimal value_2 = {{12u, 0, 0, 0}};
  set_scale(&value_1, 1);
  int return_value = s21_is_greater_or_equal(value_1, value_2);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(s21_is_greater_or_equal_test_16) {
  float num1 = 1.375323;
  float num2 = 1.39;
  s21_decimal dec1, dec2;
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_is_greater_or_equal_test_17) {
  int num1 = 2;
  int num2 = 1;
  s21_decimal dec1, dec2;
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_is_greater_or_equal_test_18) {
  float num1 = 1.39;
  float num2 = -1.39;
  s21_decimal dec1, dec2;
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_is_greater_or_equal_test_19) {
  int num1 = 0;
  int num2 = 0;
  s21_decimal dec1, dec2;
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_is_greater_or_equal_test_20) {
  int num1 = 3;
  int num2 = 9;
  s21_decimal dec1, dec2;
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_is_greater_or_equal_test_21) {
  int num1 = -3;
  int num2 = -3;
  s21_decimal dec1, dec2;
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_is_greater_or_equal_test_22) {
  int num1 = 10;
  int num2 = 3;
  s21_decimal dec1, dec2;
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_is_greater_or_equal_test_23) {
  float num1 = 10423546.34534534;
  float num2 = 3.34534534;
  s21_decimal dec1, dec2;
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_is_greater_or_equal_test_24) {
  float num1 = -3.34534534;
  float num2 = 3.34534534;
  s21_decimal dec1, dec2;
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_is_greater_or_equal_test_25) {
  float num1 = 1042634.34534534;
  float num2 = 10424546.34534534;
  s21_decimal dec1, dec2;
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_is_greater_or_equal_test_26) {
  float num1 = 10426.34534534;
  float num2 = 104234.345345;
  s21_decimal dec1, dec2;
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_is_greater_or_equal_test_27) {
  float num1 = 1042.5667777;
  float num2 = 1042.345345;
  s21_decimal dec1, dec2;
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_is_greater_or_equal_test_28) {
  s21_decimal dec5 = {
      {12345, 0, 0, 0b00000000000001000000000000000000}};  //  1.2345
  s21_decimal dec6 = {{12, 0, 0, 0b10000000000000010000000000000000}};  //
  ck_assert_int_eq(s21_is_greater_or_equal(dec5, dec6), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(dec6, dec5), 0);

  s21_decimal dec7 = {
      {12345, 0, 0, 0b10000000000001000000000000000000}};  // -1.2345
  s21_decimal dec8 = {{12, 0, 0, 0b00000000000000010000000000000000}};
  ck_assert_int_eq(s21_is_greater_or_equal(dec7, dec8), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(dec8, dec7), 1);

  s21_decimal dec1 = {
      {12345, 0, 0, 0b00000000000001000000000000000000}};  //  1.2345
  s21_decimal dec2 = {{12, 0, 0, 0b00000000000000010000000000000000}};
  ck_assert_int_eq(s21_is_greater_or_equal(dec1, dec2), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(dec2, dec1), 0);

  s21_decimal dec3 = {
      {12345, 0, 0, 0b10000000000001000000000000000000}};  // -1.2345
  s21_decimal dec4 = {{12, 0, 0, 0b10000000000000010000000000000000}};  //

  ck_assert_int_eq(s21_is_greater_or_equal(dec3, dec4), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(dec4, dec3), 1);

  s21_decimal dec9 = {{12345, 0, 0, 0}};
  s21_decimal dec10 = {{12345, 0, 0, 0}};
  ck_assert_int_eq(s21_is_greater_or_equal(dec9, dec10), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(dec10, dec9), 1);

  s21_decimal dec11 = {{0, 0, 0, 0}};
  s21_decimal dec12 = {{0, 0, 0, 0}};
  ck_assert_int_eq(s21_is_greater_or_equal(dec11, dec12), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(dec12, dec11), 1);
}
END_TEST

Suite *s21_is_greater_or_equal_suite_create() {
  Suite *suite = suite_create("s21_is_greater_or_equal_test");
  TCase *tc_core = tcase_create("tcase_core_s21_is_greater_or_equal_test");

  tcase_add_test(tc_core, s21_is_greater_or_equal_test_1);
  tcase_add_test(tc_core, s21_is_greater_or_equal_test_2);
  tcase_add_test(tc_core, s21_is_greater_or_equal_test_3);
  tcase_add_test(tc_core, s21_is_greater_or_equal_test_4);
  tcase_add_test(tc_core, s21_is_greater_or_equal_test_5);
  tcase_add_test(tc_core, s21_is_greater_or_equal_test_6);
  tcase_add_test(tc_core, s21_is_greater_or_equal_test_7);
  tcase_add_test(tc_core, s21_is_greater_or_equal_test_8);
  tcase_add_test(tc_core, s21_is_greater_or_equal_test_9);
  tcase_add_test(tc_core, s21_is_greater_or_equal_test_10);
  tcase_add_test(tc_core, s21_is_greater_or_equal_test_11);
  tcase_add_test(tc_core, s21_is_greater_or_equal_test_12);
  tcase_add_test(tc_core, s21_is_greater_or_equal_test_13);
  tcase_add_test(tc_core, s21_is_greater_or_equal_test_14);
  tcase_add_test(tc_core, s21_is_greater_or_equal_test_15);
  tcase_add_test(tc_core, s21_is_greater_or_equal_test_16);
  tcase_add_test(tc_core, s21_is_greater_or_equal_test_17);
  tcase_add_test(tc_core, s21_is_greater_or_equal_test_18);
  tcase_add_test(tc_core, s21_is_greater_or_equal_test_19);
  tcase_add_test(tc_core, s21_is_greater_or_equal_test_20);
  tcase_add_test(tc_core, s21_is_greater_or_equal_test_21);
  tcase_add_test(tc_core, s21_is_greater_or_equal_test_22);
  tcase_add_test(tc_core, s21_is_greater_or_equal_test_23);
  tcase_add_test(tc_core, s21_is_greater_or_equal_test_24);
  tcase_add_test(tc_core, s21_is_greater_or_equal_test_25);
  tcase_add_test(tc_core, s21_is_greater_or_equal_test_26);
  tcase_add_test(tc_core, s21_is_greater_or_equal_test_27);
  tcase_add_test(tc_core, s21_is_greater_or_equal_test_28);

  suite_add_tcase(suite, tc_core);

  return suite;
}

int main() {
  int failed_count = 0;

  Suite *suite = s21_is_greater_or_equal_suite_create();
  SRunner *suite_runner = srunner_create(suite);

  srunner_run_all(suite_runner, CK_NORMAL);
  failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);

  return failed_count != 0 && !SHOW_FAILED ? EXIT_FAILURE : EXIT_SUCCESS;
}
