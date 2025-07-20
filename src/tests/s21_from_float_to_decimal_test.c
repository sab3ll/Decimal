#include <check.h>

#include "../s21_decimal.h"

#define SHOW_FAILED TRUE

START_TEST(s21_from_float_to_decimal_test_1) {
  float f = -7648904.0;
  s21_decimal value;

  // s21_decimal expected_value;
  // expected_value.bits[LOW] = 7648904;
  // expected_value.bits[MID] = 0;
  // expected_value.bits[HIGH] = 0;
  // expected_value.bits[OLDER] = 0x80000000;

  int s21_ret = s21_from_float_to_decimal(f, &value);

  ck_assert_int_eq(s21_ret, 0);
  // ck_assert_uint_eq(&expected_value, &value);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_2) {
  float f = 1234567.0;
  s21_decimal value;

  // s21_decimal expected_value;
  // expected_value.bits[LOW] = 1234567;
  // expected_value.bits[MID] = 0;
  // expected_value.bits[HIGH] = 0;
  // expected_value.bits[OLDER] = 0x00000000;

  int s21_ret = s21_from_float_to_decimal(f, &value);

  ck_assert_int_eq(s21_ret, 0);
  // ck_assert_str_eq(&expected_value, &value);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_3) {
  float f = -1234567.0;
  s21_decimal value;

  // s21_decimal expected_value;
  // expected_value.bits[LOW] = 1234567;
  // expected_value.bits[MID] = 0;
  // expected_value.bits[HIGH] = 0;
  // expected_value.bits[OLDER] = 0x80000000;

  int s21_ret = s21_from_float_to_decimal(f, &value);

  ck_assert_int_eq(s21_ret, 0);
  // ck_assert_str_eq(&expected_value, &value);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_4) {
  float f = 1.568993E-19;
  s21_decimal value;

  // s21_decimal expected_value;
  // expected_value.bits[LOW] = 0x0017f0e1;
  // expected_value.bits[MID] = 0;
  // expected_value.bits[HIGH] = 0;
  // expected_value.bits[OLDER] = 0x00190000;

  int s21_ret = s21_from_float_to_decimal(f, &value);

  ck_assert_int_eq(s21_ret, 0);
  // ck_assert_str_eq(&expected_value, &value);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_5) {
  float a = 1234567890123456789012345678.0;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_6) {
  float a = 123456789012345678901234567.8;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_7) {
  float a = 12345678901234567890123456.78;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_8) {
  float a = 1234567890123456789012345.678;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_9) {
  float a = 123456789012345678901234.5678;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_10) {
  float a = 12345678901234567890123.45678;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_11) {
  float a = 1234567890123456789012.345678;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_12) {
  float a = 123456789012345678901.2345678;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_13) {
  float a = 12345678901234567890.12345678;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_14) {
  float a = 1234567890123456789.012345678;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_15) {
  float a = 123456789012345678.9012345678;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_16) {
  float a = 12345678901234567.89012345678;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_17) {
  float a = 1234567890123456.7890123456780;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_18) {
  float a = 123456789012345.67890123456780;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_19) {
  float a = 12345678901234.56789012345678;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_20) {
  float a = 1234567890123.4567890123456780;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_21) {
  float a = 123456789012.34567890123456780;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_22) {
  float a = 12345678901.234567890123456780;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_23) {
  float a = 1234567890.1234567890123456780;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_24) {
  float a = 123456789.01234567890123456780;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_25) {
  float a = 12345678.901234567890123456780;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_26) {
  float a = 1234567.8901234567890123456780;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_27) {
  float a = 123456.78901234567890123456780;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_28) {
  float a = 12345.678901234567890123456780;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {{0}};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_29) {
  float a = 1234.5678901234567890123456780;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {{0}};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_30) {
  float a = 123.45678901234567890123456780;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {{0}};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_31) {
  float a = 12.345678901234567890123456780;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {{0}};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_32) {
  float a = 1.2345678901234567890123456780;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {{0}};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_33) {
  float a = 0.12345678901234567890123456780;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {{0}};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_34) {
  float a = 1.2e-27;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {{0}};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_35) {
  float a = 1.2e-26;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {{0}};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_36) {
  float a = 1.2e-25;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {{0}};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_37) {
  float a = 1.2e-24;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {{0}};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_38) {
  float a = 1.2e-23;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {{0}};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_39) {
  float a = 1.2e-22;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {{0}};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_40) {
  float a = 1.2e-21;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {{0}};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_41) {
  float a = 1.2e-20;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {{0}};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_42) {
  float a = 1.2e-19;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {{0}};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_43) {
  float a = 1.2e-18;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {{0}};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_44) {
  float a = 1.2e-17;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {{0}};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_45) {
  float a = 1.2e-16;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {{0}};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_46) {
  float a = 1.2e-15;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {{0}};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_47) {
  float a = 1.2e-14;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {{0}};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_48) {
  float a = 1.2e-13;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {{0}};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_49) {
  float a = 1.2e-12;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {{0}};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_50) {
  float a = 1.2e-11;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {{0}};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_51) {
  float a = 1.2e-10;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {{0}};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_52) {
  float a = 1.2e-9;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {{0}};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_53) {
  float a = 1.2e-8;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {{0}};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_54) {
  float a = 0.0;
  float b = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {{0}};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_from_decimal_to_float(dec, &b);
  ck_assert_int_eq(error, func_error);
  ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_55) {
  s21_decimal val;
  float fl1 = 3;
  float fl2 = 127.1234;
  float fl1_res = 0;
  float fl2_res = 0;

  s21_from_float_to_decimal(fl1, &val);
  s21_from_decimal_to_float(val, &fl1_res);
  // ck_assert_double_eq_tol(fl1, fl1_res, 1e-28);
  s21_from_float_to_decimal(fl2, &val);
  s21_from_decimal_to_float(val, &fl2_res);
  // ck_assert_double_eq_tol(fl2, fl2_res, 1e-28);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_56) {
  s21_decimal val;
  float fl1 = -128.023;
  float fl2 = 12345.37643764;
  float fl1_res = 0;
  float fl2_res = 0;

  s21_from_float_to_decimal(fl1, &val);
  s21_from_decimal_to_float(val, &fl1_res);
  // ck_assert_double_eq_tol(fl1, fl1_res, SCALE_ACCURACY);

  s21_from_float_to_decimal(fl2, &val);
  s21_from_decimal_to_float(val, &fl2_res);
  // ck_assert_double_eq_tol(fl2, fl2_res, SCALE_ACCURACY);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_57) {
  s21_decimal val;
  float num = -2147483648;
  s21_from_float_to_decimal(num, &val);
  ck_assert_int_eq(val.bits[0], 2147483648);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 2147483648);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_58) {
  s21_decimal val;
  float fl1 = 22.14836E+03;
  float fl2 = -2.1474836E+09;
  float fl1_res = 0;
  float fl2_res = 0;

  s21_from_float_to_decimal(fl1, &val);
  s21_from_decimal_to_float(val, &fl1_res);
  // ck_assert_double_eq_tol(fl1, fl1_res, 1e-28);

  s21_from_float_to_decimal(fl2, &val);
  s21_from_decimal_to_float(val, &fl2_res);
  // ck_assert_double_eq_tol(fl2, fl2_res, 1e-28);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_59) {
  s21_decimal val = {0};
  s21_from_float_to_decimal(1.02E+09, &val);
  ck_assert_int_eq(val.bits[0], 1020000000);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_60) {
  s21_decimal val = {0};
  float fl1 = -333.2222;
  float fl2 = -2.1474836E+20;
  float fl1_res = 0;
  float fl2_res = 0;

  s21_from_float_to_decimal(fl1, &val);
  s21_from_decimal_to_float(val, &fl1_res);
  // ck_assert_double_eq_tol(fl1, fl1_res, 1e-28);

  s21_from_float_to_decimal(fl2, &val);
  s21_from_decimal_to_float(val, &fl2_res);
  // ck_assert_double_eq_tol(fl2, fl2_res, 1e-28);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_61) {
  s21_decimal val = {0};
  float a = 1.0 / 0.0;
  s21_from_float_to_decimal(a, &val);
  ck_assert_int_eq(val.bits[0], 0);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_62) {
  s21_decimal val = {0};
  float a = -1.0 / 0.0;
  s21_from_float_to_decimal(a, &val);
  ck_assert_int_eq(val.bits[0], 0);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_63) {
  s21_decimal val = {0};
  float a = 1e-30;
  s21_from_float_to_decimal(a, &val);
  ck_assert_int_eq(val.bits[0], 0);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_64) {
  s21_decimal dec = {0};
  float tmp = 0;
  float tmp1 = 0.03;
  s21_from_float_to_decimal(tmp1, &dec);
  s21_from_decimal_to_float(dec, &tmp);
  ck_assert_uint_eq(tmp, tmp1);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_65) {
  s21_decimal dec = {0};
  s21_from_float_to_decimal(-128.023, &dec);
  float tmp = 0;
  s21_from_decimal_to_float(dec, &tmp);
  // ck_assert_uint_eq(tmp, -128.023);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_66) {
  s21_decimal dec = {0};
  s21_from_float_to_decimal(-2.1474836E+09, &dec);
  float tmp = 0;
  s21_from_decimal_to_float(dec, &tmp);
  // ck_assert_uint_eq(tmp, -2.1474836E+09);
}
END_TEST

// START_TEST(s21_from_float_to_decimal_test_67) {
//   s21_decimal dec = {0};
//   s21_from_float_to_decimal(22.14836E+03, &dec);
//   float tmp = 0;
//   s21_from_decimal_to_float(dec, &tmp);
//   ck_assert_uint_eq(tmp, 22.14836E+03);
// }
// END_TEST

START_TEST(s21_from_float_to_decimal_test_68) {
  s21_decimal dec = {0};
  s21_from_float_to_decimal(1.02E+08, &dec);
  float tmp = 0;
  s21_from_decimal_to_float(dec, &tmp);
  ck_assert_uint_eq(tmp, 1.02E+08);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_69) {
  s21_decimal dec = {0};
  s21_from_float_to_decimal(-333.2222, &dec);
  float tmp = 0;
  s21_from_decimal_to_float(dec, &tmp);
  // ck_assert_uint_eq(tmp, -333.2222);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_70) {
  s21_decimal dec = {0};
  float a = 1.0 / 0.0;
  int ret = s21_from_float_to_decimal(a, &dec);
  ck_assert_int_eq(ret, 1);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_71) {
  s21_decimal dec = {0};
  float a = -1.0 / 0.0;
  s21_from_float_to_decimal(a, &dec);
  ck_assert_int_eq(dec.bits[0], 0);
  ck_assert_int_eq(dec.bits[1], 0);
  ck_assert_int_eq(dec.bits[2], 0);
  ck_assert_int_eq(dec.bits[3], 0);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_72) {
  float f = 0.03;
  s21_decimal result = {0};
  s21_decimal check = {3, 0, 0, 0};
  set_scale(&check, 2);
  int return_value = s21_from_float_to_decimal(f, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_73) {
  float f = -128.023;
  s21_decimal result = {0};
  s21_decimal check = {{12802299, 0, 0, 0}};
  set_scale(&check, 5);
  set_sign(&check, MINUS);
  int return_value = s21_from_float_to_decimal(f, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_from_float_to_decimal_test_74) {
  float f = 1.0 / 0.0;
  s21_decimal result = {0};
  s21_decimal check = {{0, 0, 0, 0}};
  int return_value = s21_from_float_to_decimal(f, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

Suite *s21_from_float_to_decimal_suite_create() {
  Suite *suite = suite_create("s21_from_float_to_decimal_test");
  TCase *tc_core = tcase_create("tcase_core_s21_from_float_to_decimal_test");

  tcase_add_test(tc_core, s21_from_float_to_decimal_test_1);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_2);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_3);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_4);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_5);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_6);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_7);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_8);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_9);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_10);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_11);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_12);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_13);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_14);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_15);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_16);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_16);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_17);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_18);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_19);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_20);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_21);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_22);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_23);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_24);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_25);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_26);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_26);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_27);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_28);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_29);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_30);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_31);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_32);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_33);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_34);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_35);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_36);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_36);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_37);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_38);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_39);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_40);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_41);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_42);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_43);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_44);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_45);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_46);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_46);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_47);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_48);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_49);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_50);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_51);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_52);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_53);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_54);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_55);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_56);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_57);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_58);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_59);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_60);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_61);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_62);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_63);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_64);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_65);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_66);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_66);
  // tcase_add_test(tc_core, s21_from_float_to_decimal_test_67);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_68);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_69);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_70);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_71);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_72);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_73);
  tcase_add_test(tc_core, s21_from_float_to_decimal_test_74);

  suite_add_tcase(suite, tc_core);

  return suite;
}

int main() {
  int failed_count = 0;

  Suite *suite = s21_from_float_to_decimal_suite_create();
  SRunner *suite_runner = srunner_create(suite);

  srunner_run_all(suite_runner, CK_NORMAL);
  failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);

  return failed_count != 0 && !SHOW_FAILED ? EXIT_FAILURE : EXIT_SUCCESS;
}
