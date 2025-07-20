#include <check.h>
#include <stdlib.h>

#include "../s21_decimal.h"

#define SHOW_FAILED TRUE

START_TEST(s21_mul_test_1) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 2;
  // src2 = 3;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000110;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_test_2) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 3;
  // src2 = 2;
  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000110;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_test_3) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0;
  // src2 = 3;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_test_4) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 2;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_test_5) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 2;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_test_6) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 6521;
  // src2 = 74121;
  src1.bits[0] = 0b00000000000000000001100101111001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000010010000110001001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00011100110011110011101011000001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_test_7) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 4;
  // src2 = 97623323;
  src1.bits[0] = 0b00000000000000000000000000000100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000101110100011001110100011011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00010111010001100111010001101100;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_test_8) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 65658654;
  // src2 = 5;
  src1.bits[0] = 0b00000011111010011101111100011110;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000101;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00010011100100010101101110010110;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_test_9) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = -364748;
  // src2 = 1;
  src1.bits[0] = 0b00000000000001011001000011001100;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000001011001000011001100;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_test_10) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 1;
  // src2 = 98745654321;
  src1.bits[0] = 0b00000000000000000000000000000001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b11111101101100110001110000110001;
  src2.bits[1] = 0b00000000000000000000000000010110;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b11111101101100110001110000110001;
  origin.bits[1] = 0b00000000000000000000000000010110;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_test_11) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = -9878798789;
  // src2 = -3;
  src1.bits[0] = 0b01001100110100101000000111000101;
  src1.bits[1] = 0b00000000000000000000000000000010;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b11100110011101111000010101001111;
  origin.bits[1] = 0b00000000000000000000000000000110;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_test_12) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 9999999999999999999;
  // src2 = 1;
  src1.bits[0] = 0b10001001111001111111111111111111;
  src1.bits[1] = 0b10001010110001110010001100000100;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b10001001111001111111111111111111;
  origin.bits[1] = 0b10001010110001110010001100000100;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_test_13) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 18446744073709551615;
  // src2 = 1;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b11111111111111111111111111111111;
  origin.bits[1] = 0b11111111111111111111111111111111;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_test_14) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_test_15) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_test_16) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 0;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_test_17) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 79228162514264337593543950335;
  // src2 = -1;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b11111111111111111111111111111111;
  origin.bits[1] = 0b11111111111111111111111111111111;
  origin.bits[2] = 0b11111111111111111111111111111111;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_test_18) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 7922816251427554395;
  // src2 = 65645646;
  src1.bits[0] = 0b01011111000010000000010001011011;
  src1.bits[1] = 0b01101101111100110111111101100111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000011111010011010110001001110;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b01011111001100010111011110111010;
  origin.bits[1] = 0b01000100111111001101101110110001;
  origin.bits[2] = 0b00000001101011100011011100011110;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_test_19) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = 665464545;
  // src2 = 8798232189789785;
  src1.bits[0] = 0b00100111101010100010111011100001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00010000010100101110011001011001;
  src2.bits[1] = 0b00000000000111110100000111110010;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b11000100010110100111001000111001;
  origin.bits[1] = 0b01100100100011011110110011010011;
  origin.bits[2] = 0b00000000000001001101011111010011;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_test_20) {
  s21_decimal src1, src2, origin, result;
  int value_type_result, value_type_origin;
  // src1 = -79228162514264337593543950335;
  // src2 = 1;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b11111111111111111111111111111111;
  origin.bits[1] = 0b11111111111111111111111111111111;
  origin.bits[2] = 0b11111111111111111111111111111111;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(s21_mul_test_21) {
  s21_decimal src1, src2, result;
  int value_type_result, value_type_origin;
  // src1 = 0;
  // src2 = 3;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b10000000000000000000000000000000;
  src2.bits[0] = 0b01000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = s21_mul(src1, src2, &result);
  value_type_origin = 2;
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

// START_TEST(s21_mul_test_22) {
//   s21_decimal value_1 = {.bits[0] = 0x00000001,
//                          .bits[1] = 0x00000000,
//                          .bits[2] = 0x00000000,
//                          .bits[3] = 0x80000000};  //-1

//   s21_decimal value_2 = {.bits[0] = 0x00000001,
//                          .bits[1] = 0x00000000,
//                          .bits[2] = 0x00000000,
//                          .bits[3] = 0x80000000};  // -1

//   s21_decimal reference_result = {.bits[0] = 0x00000001,
//                                   .bits[1] = 0x00000000,
//                                   .bits[2] = 0x00000000,
//                                   .bits[3] = 0x00000000};  // 1
//   s21_decimal result = {0};
//   int sub_result = s21_mul(value_1, value_2, &result);
//   ck_assert_int_eq(sub_result, 0);
//   ck_assert_int_eq(result.bits[0], reference_result.bits[0]);
//   ck_assert_int_eq(result.bits[1], reference_result.bits[1]);
//   ck_assert_int_eq(result.bits[2], reference_result.bits[2]);
//   ck_assert_int_eq(result.bits[3], reference_result.bits[3]);
// }
// END_TEST

START_TEST(s21_mul_test_23) {
  s21_decimal value_1 = {{0x4111b58d, 0xad5e5818, 0x00000006, 0x00190000}};

  s21_decimal value_2 = {{0xc11cc13d, 0xaee52e86, 0x00000006, 0x00190000}};

  s21_decimal reference_result = {
      {0x5f290773, 0x1512d7eb, 0x00000000, 0x001c0000}};  // 1
  s21_decimal result = {0};
  int sub_result = s21_mul(value_1, value_2, &result);
  ck_assert_int_eq(sub_result, 0);
  ck_assert_int_eq(result.bits[0], reference_result.bits[0]);
  ck_assert_int_eq(result.bits[1], reference_result.bits[1]);
  ck_assert_int_eq(result.bits[2], reference_result.bits[2]);
  ck_assert_int_eq(result.bits[3], reference_result.bits[3]);
}
END_TEST

START_TEST(s21_mul_test_24) {
  s21_decimal value_1 = {{0x4111bf9a, 0xad5e5818, 0x00000006, 0x00190000}};

  s21_decimal value_2 = {{0x4b34791a, 0x1401a7ac, 0x00000008, 0x00190000}};

  s21_decimal reference_result = {
      {0xe7facd26, 0x1978e58c, 0x00000000, 0x001c0000}};
  s21_decimal result = {0};
  int sub_result = s21_mul(value_1, value_2, &result);
  ck_assert_int_eq(sub_result, 0);
  ck_assert_int_eq(result.bits[0], reference_result.bits[0]);
  ck_assert_int_eq(result.bits[1], reference_result.bits[1]);
  ck_assert_int_eq(result.bits[2], reference_result.bits[2]);
  ck_assert_int_eq(result.bits[3], reference_result.bits[3]);
}
END_TEST

START_TEST(s21_mul_test_25) {
  s21_decimal value_1 = {{0x4111bdde, 0xad5e5818, 0x00000006, 0x00190000}};

  s21_decimal value_2 = {{0x49769f9e, 0xd66206fa, 0x00000007, 0x00190000}};

  s21_decimal reference_result = {
      {0xb1b9bfd3, 0x18b69564, 0x00000000, 0x001c0000}};
  s21_decimal result = {0};
  int sub_result = s21_mul(value_1, value_2, &result);
  ck_assert_int_eq(sub_result, 0);
  ck_assert_int_eq(result.bits[0], reference_result.bits[0]);
  ck_assert_int_eq(result.bits[1], reference_result.bits[1]);
  ck_assert_int_eq(result.bits[2], reference_result.bits[2]);
  ck_assert_int_eq(result.bits[3], reference_result.bits[3]);
}
END_TEST

START_TEST(s21_mul_test_26) {
  s21_decimal a = {{0x4111bd39, 0xad5e5818, 0x00000006, 0x00190000}};
  s21_decimal b = {{0xc8d0efa9, 0xbf7b7680, 0x00000007, 0x00190000}};
  s21_decimal res;
  int s21_ret = s21_mul(a, b, &res);
  // ck_assert_uint_eq {{0x96a508b6, 0x186e5f63, 0x00000000, 0x001c0000}};
  int expected_ret = 0;
  ck_assert_int_eq(s21_ret, expected_ret);
  // ck_assert_str_eq(&expected, &res);
}
END_TEST

START_TEST(s21_mul_test_27) {
  s21_decimal value_1 = {{0, 0, 0, 0b00000000000010100000000000000000}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  s21_decimal result = {0};

  ck_assert_int_eq(0, s21_mul(value_1, value_2, &result));

  ck_assert_int_eq(result.bits[0], 0);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST

START_TEST(s21_mul_test_28) {
  s21_decimal a = {{0x4111bffa, 0xad5e5818, 0x00000006, 0x00190000}};
  s21_decimal b = {{0x4b94df7a, 0x215499fc, 0x00000008, 0x00190000}};
  s21_decimal res;
  int s21_ret = s21_mul(a, b, &res);
  // ck_assert_uint_eq {{0x38e645a6, 0x19a2e90b, 0x00000000, 0x001c0000}};
  int expected_ret = 0;
  // int mem_cmp = memcmp(res.bits,expected.bits,4*sizeof(uint32_t));
  // printf("%s",(mem_cmp)?"Different\n":"Same\n");
  ck_assert_int_eq(s21_ret, expected_ret);
  // ck_assert_mem_eq(&expected, &res, 4 * sizeof(uint32_t));
}
END_TEST

START_TEST(s21_mul_test_29) {
  s21_decimal a = {{0x4111bff7, 0xad5e5818, 0x00000006, 0x00190000}};
  s21_decimal b = {{0xcb91dc47, 0x20ea0269, 0x00000008, 0x00190000}};
  s21_decimal res;
  int s21_ret = s21_mul(a, b, &res);
  // ck_assert_uint_eq {{0x465ee9e2, 0x19a198ef, 0x00000000, 0x001c0000}};
  int expected_ret = 0;
  // int mem_cmp = memcmp(res.bits,expected.bits,4*sizeof(uint32_t));
  // printf("%s",(mem_cmp)?"Different\n":"Same\n");
  ck_assert_int_eq(s21_ret, expected_ret);
  // ck_assert_mem_eq(&expected, &res, 4 * sizeof(uint32_t));
}
END_TEST

START_TEST(s21_mul_test_30) {
  s21_decimal a = {{0x4111bff4, 0xad5e5818, 0x00000006, 0x00190000}};
  s21_decimal b = {{0x4b8ed914, 0x207f6ad7, 0x00000008, 0x00190000}};
  s21_decimal res;
  int s21_ret = s21_mul(a, b, &res);
  // ck_assert_uint_eq {{0x53d78e1e, 0x19a048d3, 0x00000000, 0x001c0000}};
  int expected_ret = 0;
  // int mem_cmp = memcmp(res.bits,expected.bits,4*sizeof(uint32_t));
  // printf("%s",(mem_cmp)?"Different\n":"Same\n");
  ck_assert_int_eq(s21_ret, expected_ret);
  // ck_assert_mem_eq(&expected, &res, 4 * sizeof(uint32_t));
}
END_TEST

START_TEST(s21_mul_test_31) {
  s21_decimal a = {{0x4111bff0, 0xad5e5818, 0x00000006, 0x00190000}};
  s21_decimal b = {{0x4b8ad4d0, 0x1ff14b69, 0x00000008, 0x00190000}};
  s21_decimal res;
  int s21_ret = s21_mul(a, b, &res);
  // ck_assert_uint_eq {{0x10786919, 0x199e88ae, 0x00000000, 0x001c0000}};
  int expected_ret = 0;
  // int mem_cmp = memcmp(res.bits,expected.bits,4*sizeof(uint32_t));
  // printf("%s",(mem_cmp)?"Different\n":"Same\n");
  ck_assert_int_eq(s21_ret, expected_ret);
  // ck_assert_mem_eq(&expected, &res, 4 * sizeof(uint32_t));

  // ck_assert_int_eq(res.bits[0], expected.bits[0]);
  // ck_assert_int_eq(res.bits[2], expected.bits[1]);
  // ck_assert_int_eq(res.bits[3], expected.bits[2]);
  // ck_assert_int_eq(res.bits[0], expected.bits[3]);
}
END_TEST

START_TEST(s21_mul_test_32) {
  s21_decimal a = {{0x4111bfed, 0xad5e5818, 0x00000006, 0x00190000}};
  s21_decimal b = {{0xcb87d19d, 0x1f86b3d6, 0x00000008, 0x00190000}};
  s21_decimal res;
  int s21_ret = s21_mul(a, b, &res);
  // ck_assert_uint_eq {{0x1df10d55, 0x199d3892, 0x00000000, 0x001c0000}};
  int expected_ret = 0;
  // int mem_cmp = memcmp(res.bits,expected.bits,4*sizeof(uint32_t));
  // printf("%s",(mem_cmp)?"Different\n":"Same\n");
  ck_assert_int_eq(s21_ret, expected_ret);
  // ck_assert_mem_eq(&expected, &res, 4 * sizeof(uint32_t));

  // ck_assert_int_eq(res.bits[0], expected.bits[0]);
  // ck_assert_int_eq(res.bits[1], expected.bits[1]);
  // ck_assert_int_eq(res.bits[3], expected.bits[2]);
  // ck_assert_int_eq(res.bits[0], expected.bits[3]);
}
END_TEST

START_TEST(s21_mul_test_33) {
  s21_decimal a = {{0x4111bfe9, 0xad5e5818, 0x00000006, 0x00190000}};
  s21_decimal b = {{0xcb83cd59, 0x1ef89468, 0x00000008, 0x00190000}};
  s21_decimal res;
  int s21_ret = s21_mul(a, b, &res);
  // ck_assert_uint_eq {{0xda91e84f, 0x199b786c, 0x00000000, 0x001c0000}};
  int expected_ret = 0;
  // int mem_cmp = memcmp(res.bits,expected.bits,4*sizeof(uint32_t));
  // printf("%s",(mem_cmp)?"Different\n":"Same\n");
  ck_assert_int_eq(s21_ret, expected_ret);
  // ck_assert_mem_eq(&expected, &res, 4 * sizeof(uint32_t));
}
END_TEST

START_TEST(s21_mul_test_34) {
  s21_decimal a = {{0x4111bfe5, 0xad5e5818, 0x00000006, 0x00190000}};
  s21_decimal b = {{0xcb7fc915, 0x1e6a74fa, 0x00000008, 0x00190000}};
  s21_decimal res;
  int s21_ret = s21_mul(a, b, &res);
  // ck_assert_uint_eq {{0x9732c34a, 0x1999b847, 0x00000000, 0x001c0000}};
  int expected_ret = 0;
  // int mem_cmp = memcmp(res.bits,expected.bits,4*sizeof(uint32_t));
  // printf("%s",(mem_cmp)?"Different\n":"Same\n");
  ck_assert_int_eq(s21_ret, expected_ret);
  // ck_assert_mem_eq(&expected, &res, 4 * sizeof(uint32_t));
}
END_TEST

START_TEST(s21_mul_test_35) {
  s21_decimal a = {{0x4111bfe1, 0xad5e5818, 0x00000006, 0x00190000}};
  s21_decimal b = {{0xcb7bc4d1, 0x1ddc558c, 0x00000008, 0x00190000}};
  s21_decimal res;
  int s21_ret = s21_mul(a, b, &res);
  // ck_assert_uint_eq {{0x53d39e45, 0x1997f822, 0x00000000, 0x001c0000}};
  int expected_ret = 0;
  // int mem_cmp = memcmp(res.bits,expected.bits,4*sizeof(uint32_t));
  // printf("%s",(mem_cmp)?"Different\n":"Same\n");
  ck_assert_int_eq(s21_ret, expected_ret);
  // ck_assert_mem_eq(&expected, &res, 4 * sizeof(uint32_t));
}
END_TEST

START_TEST(s21_mul_test_36) {
  s21_decimal a = {{0x4111bfde, 0xad5e5818, 0x00000006, 0x00190000}};
  s21_decimal b = {{0x4b78c19e, 0x1d71bdfa, 0x00000008, 0x00190000}};
  s21_decimal res;
  int s21_ret = s21_mul(a, b, &res);
  // ck_assert_uint_eq {{0x614c4281, 0x1996a806, 0x00000000, 0x001c0000}};
  int expected_ret = 0;
  // int mem_cmp = memcmp(res.bits,expected.bits,4*sizeof(uint32_t));
  // printf("%s",(mem_cmp)?"Different\n":"Same\n");
  ck_assert_int_eq(s21_ret, expected_ret);
  // ck_assert_mem_eq(&expected, &res, 4 * sizeof(uint32_t));
}
END_TEST

START_TEST(s21_mul_test_37) {
  s21_decimal a = {{0x4111bfdb, 0xad5e5818, 0x00000006, 0x00190000}};
  s21_decimal b = {{0xcb75be6b, 0x1d072667, 0x00000008, 0x00190000}};
  s21_decimal res;
  int s21_ret = s21_mul(a, b, &res);
  // ck_assert_uint_eq {{0x6ec4e6bd, 0x199557ea, 0x00000000, 0x001c0000}};
  int expected_ret = 0;
  // int mem_cmp = memcmp(res.bits,expected.bits,4*sizeof(uint32_t));
  // printf("%s",(mem_cmp)?"Different\n":"Same\n");
  ck_assert_int_eq(s21_ret, expected_ret);
  // ck_assert_mem_eq(&expected, &res, 4 * sizeof(uint32_t));
}
END_TEST

START_TEST(s21_mul_test_38) {
  s21_decimal a = {{0x4111bfd2, 0xad5e5818, 0x00000006, 0x00190000}};
  s21_decimal b = {{0x4b6cb4d2, 0x1bc75fb0, 0x00000008, 0x00190000}};
  s21_decimal res;
  int s21_ret = s21_mul(a, b, &res);
  // ck_assert_uint_eq {{0x972ed371, 0x19916796, 0x00000000, 0x001c0000}};
  int expected_ret = 0;
  // int mem_cmp = memcmp(res.bits,expected.bits,4*sizeof(uint32_t));
  // printf("%s",(mem_cmp)?"Different\n":"Same\n");
  ck_assert_int_eq(s21_ret, expected_ret);
  // ck_assert_mem_eq(&expected, &res, 4 * sizeof(uint32_t));
}
END_TEST

START_TEST(s21_mul_test_39) {
  s21_decimal a = {{0x4111bfce, 0xad5e5818, 0x00000006, 0x00190000}};
  s21_decimal b = {{0x4b68b08e, 0x1b394042, 0x00000008, 0x00190000}};
  s21_decimal res;
  int s21_ret = s21_mul(a, b, &res);
  // ck_assert_uint_eq {{0x53cfae6b, 0x198fa771, 0x00000000, 0x001c0000}};
  int expected_ret = 0;
  // int mem_cmp = memcmp(res.bits,expected.bits,4*sizeof(uint32_t));
  // printf("%s",(mem_cmp)?"Different\n":"Same\n");
  ck_assert_int_eq(s21_ret, expected_ret);
  // ck_assert_mem_eq(&expected, &res, 4 * sizeof(uint32_t));
}
END_TEST

START_TEST(s21_mul_test_40) {
  s21_decimal a = {{0x4111bfca, 0xad5e5818, 0x00000006, 0x00190000}};
  s21_decimal b = {{0x4b64ac4a, 0x1aab20d4, 0x00000008, 0x00190000}};
  s21_decimal res;
  int s21_ret = s21_mul(a, b, &res);
  // ck_assert_uint_eq {{0x10708966, 0x198de74c, 0x00000000, 0x001c0000}};
  int expected_ret = 0;
  // int mem_cmp = memcmp(res.bits,expected.bits,4*sizeof(uint32_t));
  // printf("%s",(mem_cmp)?"Different\n":"Same\n");
  ck_assert_int_eq(s21_ret, expected_ret);
  // ck_assert_mem_eq(&expected, &res, 4 * sizeof(uint32_t));
}
END_TEST

START_TEST(s21_mul_test_41) {
  s21_decimal a = {{0x4111bf67, 0xad5e5818, 0x00000006, 0x00190000}};
  s21_decimal b = {{0xcb0142b7, 0x0ced96f1, 0x00000008, 0x00190000}};
  s21_decimal res;
  int s21_ret = s21_mul(a, b, &res);
  // ck_assert_uint_eq {{0xccfdb521, 0x196293b1, 0x00000000, 0x001c0000}};
  int expected_ret = 0;
  // int mem_cmp = memcmp(res.bits,expected.bits,4*sizeof(uint32_t));
  // printf("%s",(mem_cmp)?"Different\n":"Same\n");
  ck_assert_int_eq(s21_ret, expected_ret);
  // ck_assert_mem_eq(&expected, &res, 4 * sizeof(uint32_t));
}
END_TEST

START_TEST(s21_mul_test_42) {
  s21_decimal a = {{0x4111be6a, 0xad5e5818, 0x00000006, 0x00190000}};
  s21_decimal b = {{0x4a0334ea, 0xe9d05304, 0x00000007, 0x00190000}};
  s21_decimal res;
  int s21_ret = s21_mul(a, b, &res);
  // ck_assert_uint_eq {{0xe7bbcf8e, 0x18f3da7c, 0x00000000, 0x001c0000}};
  int expected_ret = 0;
  // int mem_cmp = memcmp(res.bits,expected.bits,4*sizeof(uint32_t));
  // printf("%s",(mem_cmp)?"Different\n":"Same\n");
  ck_assert_int_eq(s21_ret, expected_ret);
  // ck_assert_mem_eq(&expected, &res, 4 * sizeof(uint32_t));
}
END_TEST

START_TEST(s21_mul_test_43) {
  s21_decimal a = {{0x4111be03, 0xad5e5818, 0x00000006, 0x00190000}};
  s21_decimal b = {{0xc99bc713, 0xdb84a9b3, 0x00000007, 0x00190000}};
  s21_decimal res;
  int s21_ret = s21_mul(a, b, &res);
  // ck_assert_uint_eq {{0x60e9d644, 0x18c6c6bd, 0x00000000, 0x001c0000}};
  int expected_ret = 0;
  // int mem_cmp = memcmp(res.bits,expected.bits,4*sizeof(uint32_t));
  // printf("%s",(mem_cmp)?"Different\n":"Same\n");
  ck_assert_int_eq(s21_ret, expected_ret);
  // ck_assert_mem_eq(&expected, &res, 4 * sizeof(uint32_t));
}
END_TEST

START_TEST(s21_mul_test_44) {
  s21_decimal a = {{0x4111be00, 0xad5e5818, 0x00000006, 0x00190000}};
  s21_decimal b = {{0x4998c3e0, 0xdb1a1221, 0x00000007, 0x00190000}};
  s21_decimal res;
  int s21_ret = s21_mul(a, b, &res);
  // ck_assert_uint_eq {{0x6e627a80, 0x18c576a1, 0x00000000, 0x001c0000}};
  int expected_ret = 0;
  // int mem_cmp = memcmp(res.bits,expected.bits,4*sizeof(uint32_t));
  // printf("%s",(mem_cmp)?"Different\n":"Same\n");
  ck_assert_int_eq(s21_ret, expected_ret);
  // ck_assert_mem_eq(&expected, &res, 4 * sizeof(uint32_t));
}
END_TEST

START_TEST(s21_mul_test_45) {
  s21_decimal a = {{0x4111bdf0, 0xad5e5818, 0x00000006, 0x00190000}};
  s21_decimal b = {{0x4988b2d0, 0xd8e19469, 0x00000007, 0x00190000}};
  s21_decimal res;
  int s21_ret = s21_mul(a, b, &res);
  // ck_assert_uint_eq {{0x60e5e66b, 0x18be760c, 0x00000000, 0x001c0000}};
  int expected_ret = 0;
  // int mem_cmp = memcmp(res.bits,expected.bits,4*sizeof(uint32_t));
  // printf("%s",(mem_cmp)?"Different\n":"Same\n");
  ck_assert_int_eq(s21_ret, expected_ret);
  // ck_assert_mem_eq(&expected, &res, 4 * sizeof(uint32_t));
}
END_TEST

START_TEST(s21_mul_test_46) {
  s21_decimal a = {{0x4111bd8f, 0xad5e5818, 0x00000006, 0x00190000}};
  s21_decimal b = {{0xc9274b5f, 0xcb6b1a3d, 0x00000007, 0x00190000}};
  s21_decimal res;
  int s21_ret = s21_mul(a, b, &res);
  // ck_assert_uint_eq {{0xbf22a4a9, 0x18940284, 0x00000000, 0x001c0000}};
  int expected_ret = 0;
  // int mem_cmp = memcmp(res.bits,expected.bits,4*sizeof(uint32_t));
  // printf("%s",(mem_cmp)?"Different\n":"Same\n");
  ck_assert_int_eq(s21_ret, expected_ret);
  // ck_assert_mem_eq(&expected, &res, 4 * sizeof(uint32_t));
}
END_TEST

START_TEST(s21_mul_test_47) {
  s21_decimal a = {{0x4111bd34, 0xad5e5818, 0x00000006, 0x00190000}};
  s21_decimal b = {{0x48cbea54, 0xbec9cf37, 0x00000007, 0x00190000}};
  s21_decimal res;
  int s21_ret = s21_mul(a, b, &res);
  // ck_assert_uint_eq {{0x026e1a6f, 0x186c2f35, 0x00000000, 0x001c0000}};
  int expected_ret = 0;
  // int mem_cmp = memcmp(res.bits,expected.bits,4*sizeof(uint32_t));
  // printf("%s",(mem_cmp)?"Different\n":"Same\n");
  ck_assert_int_eq(s21_ret, expected_ret);
  // ck_assert_mem_eq(&expected, &res, 4 * sizeof(uint32_t));
}
END_TEST

START_TEST(s21_mul_test_48) {
  s21_decimal a = {{0x4111bcb4, 0xad5e5818, 0x00000006, 0x00190000}};
  s21_decimal b = {{0x484b61d4, 0xad05e177, 0x00000007, 0x00190000}};
  s21_decimal res;
  int s21_ret = s21_mul(a, b, &res);
  // ck_assert_uint_eq {{0x968979c3, 0x18342a8c, 0x00000000, 0x001c0000}};
  int expected_ret = 0;
  // int mem_cmp = memcmp(res.bits,expected.bits,4*sizeof(uint32_t));
  // printf("%s",(mem_cmp)?"Different\n":"Same\n");
  ck_assert_int_eq(s21_ret, expected_ret);
  // ck_assert_mem_eq(&expected, &res, 4 * sizeof(uint32_t));
}
END_TEST

START_TEST(s21_mul_test_49) {
  s21_decimal a = {{0x4111bc5a, 0xad5e5818, 0x00000006, 0x00190000}};
  s21_decimal b = {{0x47f101da, 0xa0881e4c, 0x00000007, 0x00190000}};
  s21_decimal res;
  int s21_ret = s21_mul(a, b, &res);
  // ck_assert_uint_eq {{0x2aacb8cb, 0x180cc746, 0x00000000, 0x001c0000}};
  int expected_ret = 0;
  // int mem_cmp = memcmp(res.bits,expected.bits,4*sizeof(uint32_t));
  // printf("%s",(mem_cmp)?"Different\n":"Same\n");
  ck_assert_int_eq(s21_ret, expected_ret);
  // ck_assert_mem_eq(&expected, &res, 4 * sizeof(uint32_t));
}
END_TEST

START_TEST(s21_mul_test_50) {
  s21_decimal a = {{0x4111bbf2, 0xad5e5818, 0x00000006, 0x00190000}};
  s21_decimal b = {{0x478892f2, 0x9218ed20, 0x00000007, 0x00190000}};
  s21_decimal res;
  int s21_ret = s21_mul(a, b, &res);
  // ck_assert_uint_eq {{0x5302f640, 0x17df437d, 0x00000000, 0x001c0000}};
  int expected_ret = 0;
  // int mem_cmp = memcmp(res.bits,expected.bits,4*sizeof(uint32_t));
  // printf("%s",(mem_cmp)?"Different\n":"Same\n");
  ck_assert_int_eq(s21_ret, expected_ret);
  // ck_assert_mem_eq(&expected, &res, 4 * sizeof(uint32_t));
}
END_TEST

START_TEST(s21_mul_test_51) {
  s21_decimal a = {{0x4111bb80, 0xad5e5818, 0x00000006, 0x00190000}};
  s21_decimal b = {{0x47161960, 0x82466d61, 0x00000007, 0x00190000}};
  s21_decimal res;
  int s21_ret = s21_mul(a, b, &res);
  // ck_assert_uint_eq {{0x52eb5727, 0x17ad5f57, 0x00000000, 0x001c0000}};
  int expected_ret = 0;
  // int mem_cmp = memcmp(res.bits,expected.bits,4*sizeof(uint32_t));
  // printf("%s",(mem_cmp)?"Different\n":"Same\n");
  ck_assert_int_eq(s21_ret, expected_ret);
  // ck_assert_mem_eq(&expected, &res, 4 * sizeof(uint32_t));
}
END_TEST

START_TEST(s21_mul_test_52) {
  s21_decimal a = {{0x4111bb19, 0xad5e5818, 0x00000006, 0x00190000}};
  s21_decimal b = {{0xc6aeab89, 0x73fac410, 0x00000007, 0x00190000}};
  s21_decimal res;
  int s21_ret = s21_mul(a, b, &res);
  // ck_assert_uint_eq {{0xcc195ddd, 0x17804b97, 0x00000000, 0x001c0000}};
  int expected_ret = 0;
  // int mem_cmp = memcmp(res.bits,expected.bits,4*sizeof(uint32_t));
  // printf("%s",(mem_cmp)?"Different\n":"Same\n");
  ck_assert_int_eq(s21_ret, expected_ret);
  // ck_assert_mem_eq(&expected, &res, 4 * sizeof(uint32_t));
}
END_TEST

START_TEST(s21_mul_test_53) {
  s21_decimal a = {{0x4111bac1, 0xad5e5818, 0x00000006, 0x00190000}};
  s21_decimal b = {{0xc6564db1, 0x67c4109c, 0x00000007, 0x00190000}};
  s21_decimal res;
  int s21_ret = s21_mul(a, b, &res);
  // ck_assert_uint_eq {{0x01ec2f68, 0x1759c864, 0x00000000, 0x001c0000}};
  int expected_ret = 0;
  // int mem_cmp = memcmp(res.bits,expected.bits,4*sizeof(uint32_t));
  // printf("%s",(mem_cmp)?"Different\n":"Same\n");
  ck_assert_int_eq(s21_ret, expected_ret);
  // ck_assert_mem_eq(&expected, &res, 4 * sizeof(uint32_t));
}
END_TEST

START_TEST(s21_mul_test_54) {
  s21_decimal a = {{0x4111ba91, 0xad5e5818, 0x00000006, 0x00190000}};
  s21_decimal b = {{0xc6261a81, 0x611a9774, 0x00000007, 0x00190000}};
  s21_decimal res;
  int s21_ret = s21_mul(a, b, &res);
  // ck_assert_uint_eq {{0xd9767327, 0x1744c6a4, 0x00000000, 0x001c0000}};
  int expected_ret = 0;
  // int mem_cmp = memcmp(res.bits,expected.bits,4*sizeof(uint32_t));
  // printf("%s",(mem_cmp)?"Different\n":"Same\n");
  ck_assert_int_eq(s21_ret, expected_ret);
  // ck_assert_mem_eq(&expected, &res, 4 * sizeof(uint32_t));
}
END_TEST

START_TEST(s21_mul_test_55) {
  s21_decimal a = {{0x4111ba70, 0xad5e5818, 0x00000006, 0x00190000}};
  s21_decimal b = {{0x4604f750, 0x5c861429, 0x00000007, 0x00190000}};
  s21_decimal res;
  int s21_ret = s21_mul(a, b, &res);
  // ck_assert_uint_eq {{0x6da581bb, 0x17365571, 0x00000000, 0x001c0000}};
  int expected_ret = 0;
  // int mem_cmp = memcmp(res.bits,expected.bits,4*sizeof(uint32_t));
  // printf("%s",(mem_cmp)?"Different\n":"Same\n");
  ck_assert_int_eq(s21_ret, expected_ret);
  // ck_assert_mem_eq(&expected, &res, 4 * sizeof(uint32_t));
}
END_TEST

START_TEST(s21_mul_test_56) {
  s21_decimal a = {{0x4111ba1a, 0xad5e5818, 0x00000006, 0x00190000}};
  s21_decimal b = {{0x45ae9b9a, 0x5096706c, 0x00000007, 0x00190000}};
  s21_decimal res;
  int s21_ret = s21_mul(a, b, &res);
  // ck_assert_uint_eq {{0x4527e5c8, 0x1710b250, 0x00000000, 0x001c0000}};
  int expected_ret = 0;
  // int mem_cmp = memcmp(res.bits,expected.bits,4*sizeof(uint32_t));
  // printf("%s",(mem_cmp)?"Different\n":"Same\n");
  ck_assert_int_eq(s21_ret, expected_ret);
  // ck_assert_mem_eq(&expected, &res, 4 * sizeof(uint32_t));
}
END_TEST

START_TEST(s21_mul_test_57) {
  s21_decimal a = {{0x4111b9c0, 0xad5e5818, 0x00000006, 0x00190000}};
  s21_decimal b = {{0x45543ba0, 0x4418ad41, 0x00000007, 0x00190000}};
  s21_decimal res;
  int s21_ret = s21_mul(a, b, &res);
  // ck_assert_uint_eq {{0xd94b24d0, 0x16e94f09, 0x00000000, 0x001c0000}};
  int expected_ret = 0;
  // int mem_cmp = memcmp(res.bits,expected.bits,4*sizeof(uint32_t));
  // printf("%s",(mem_cmp)?"Different\n":"Same\n");
  ck_assert_int_eq(s21_ret, expected_ret);
  // ck_assert_mem_eq(&expected, &res, 4 * sizeof(uint32_t));
}
END_TEST

START_TEST(s21_mul_test_58) {
  s21_decimal a = {{0x4111b950, 0xad5e5818, 0x00000006, 0x00190000}};
  s21_decimal b = {{0x44e3c430, 0x348d3d39, 0x00000007, 0x00190000}};
  s21_decimal res;
  int s21_ret = s21_mul(a, b, &res);
  // ck_assert_uint_eq {{0x7ae3183a, 0x16b84af6, 0x00000000, 0x001c0000}};
  int expected_ret = 0;
  // int mem_cmp = memcmp(res.bits,expected.bits,4*sizeof(uint32_t));
  // printf("%s",(mem_cmp)?"Different\n":"Same\n");
  ck_assert_int_eq(s21_ret, expected_ret);
  // ck_assert_mem_eq(&expected, &res, 4 * sizeof(uint32_t));
}
END_TEST

START_TEST(s21_mul_test_59) {
  s21_decimal a = {{0x4111b8d0, 0xad5e5818, 0x00000006, 0x00190000}};
  s21_decimal b = {{0x44633bb0, 0x22c94f79, 0x00000007, 0x00190000}};
  s21_decimal res;
  int s21_ret = s21_mul(a, b, &res);
  // ck_assert_uint_eq {{0x0efe778f, 0x1680464e, 0x00000000, 0x001c0000}};
  int expected_ret = 0;
  // int mem_cmp = memcmp(res.bits,expected.bits,4*sizeof(uint32_t));
  // printf("%s",(mem_cmp)?"Different\n":"Same\n");
  ck_assert_int_eq(s21_ret, expected_ret);
  // ck_assert_mem_eq(&expected, &res, 4 * sizeof(uint32_t));
}
END_TEST

START_TEST(s21_mul_test_60) {
  s21_decimal a = {{0x4111b85f, 0xad5e5818, 0x00000006, 0x00190000}};
  s21_decimal b = {{0xc3f1c32f, 0x131a5795, 0x00000007, 0x00190000}};
  s21_decimal res;
  int s21_ret = s21_mul(a, b, &res);
  // ck_assert_uint_eq {{0x5fbea1b8, 0x164ed231, 0x00000000, 0x001c0000}};
  int expected_ret = 0;
  // int mem_cmp = memcmp(res.bits,expected.bits,4*sizeof(uint32_t));
  // printf("%s",(mem_cmp)?"Different\n":"Same\n");
  ck_assert_int_eq(s21_ret, expected_ret);
  // ck_assert_mem_eq(&expected, &res, 4 * sizeof(uint32_t));
}
END_TEST

START_TEST(s21_mul_test_61) {
  s21_decimal a = {{0x4111b7f0, 0xad5e5818, 0x00000006, 0x00190000}};
  s21_decimal b = {{0x43824cd0, 0x03b26f69, 0x00000007, 0x00190000}};
  s21_decimal res;
  int s21_ret = s21_mul(a, b, &res);
  // ck_assert_uint_eq {{0x522e5e63, 0x161e3e27, 0x00000000, 0x001c0000}};
  int expected_ret = 0;
  // int mem_cmp = memcmp(res.bits,expected.bits,4*sizeof(uint32_t));
  // printf("%s",(mem_cmp)?"Different\n":"Same\n");
  ck_assert_int_eq(s21_ret, expected_ret);
  // ck_assert_mem_eq(&expected, &res, 4 * sizeof(uint32_t));
}
END_TEST

START_TEST(s21_mul_test_62) {
  s21_decimal a = {{0x4111b797, 0xad5e5818, 0x00000006, 0x00190000}};
  s21_decimal b = {{0xc328ede7, 0xf7583419, 0x00000006, 0x00190000}};
  s21_decimal res;
  int s21_ret = s21_mul(a, b, &res);
  // ck_assert_uint_eq {{0x372966ac, 0x15f74aea, 0x00000000, 0x001c0000}};
  int expected_ret = 0;
  // int mem_cmp = memcmp(res.bits,expected.bits,4*sizeof(uint32_t));
  // printf("%s",(mem_cmp)?"Different\n":"Same\n");
  ck_assert_int_eq(s21_ret, expected_ret);
  // ck_assert_mem_eq(&expected, &res, 4 * sizeof(uint32_t));
}
END_TEST

START_TEST(s21_mul_test_63) {
  s21_decimal a = {{0x4111b72d, 0xad5e5818, 0x00000006, 0x00190000}};
  s21_decimal b = {{0xc2be7cdd, 0xe8a1f336, 0x00000006, 0x00190000}};
  s21_decimal res;
  int s21_ret = s21_mul(a, b, &res);
  // ck_assert_uint_eq {{0xbdd0119f, 0x15c8e70e, 0x00000000, 0x001c0000}};
  int expected_ret = 0;
  // int mem_cmp = memcmp(res.bits,expected.bits,4*sizeof(uint32_t));
  // printf("%s",(mem_cmp)?"Different\n":"Same\n");
  ck_assert_int_eq(s21_ret, expected_ret);
  // ck_assert_mem_eq(&expected, &res, 4 * sizeof(uint32_t));
}
END_TEST

START_TEST(s21_mul_test_64) {
  s21_decimal a = {{0x4111b6dc, 0xad5e5818, 0x00000006, 0x00190000}};
  s21_decimal b = {{0x426d267c, 0xdd63f6c3, 0x00000006, 0x00190000}};
  s21_decimal res;
  int s21_ret = s21_mul(a, b, &res);
  // ck_assert_uint_eq {{0x298963f3, 0x15a5741c, 0x00000000, 0x001c0000}};
  int expected_ret = 0;
  // int mem_cmp = memcmp(res.bits,expected.bits,4*sizeof(uint32_t));
  // printf("%s",(mem_cmp)?"Different\n":"Same\n");
  ck_assert_int_eq(s21_ret, expected_ret);
  // ck_assert_mem_eq(&expected, &res, 4 * sizeof(uint32_t));
}
END_TEST

START_TEST(s21_mul_test_65) {
  s21_decimal a = {{0x4111b699, 0xad5e5818, 0x00000006, 0x00190000}};
  s21_decimal b = {{0xc229df09, 0xd4176850, 0x00000006, 0x00190000}};
  s21_decimal res;
  int s21_ret = s21_mul(a, b, &res);
  // ck_assert_uint_eq {{0x010fb7d9, 0x158821ac, 0x00000000, 0x001c0000}};
  int expected_ret = 0;
  // int mem_cmp = memcmp(res.bits,expected.bits,4*sizeof(uint32_t));
  // printf("%s",(mem_cmp)?"Different\n":"Same\n");
  ck_assert_int_eq(s21_ret, expected_ret);
  // ck_assert_mem_eq(&expected, &res, 4 * sizeof(uint32_t));
}
END_TEST

START_TEST(s21_mul_test_66) {
  s21_decimal a = {{0x4111b65a, 0xad5e5818, 0x00000006, 0x00190000}};
  s21_decimal b = {{0x41ea9bda, 0xcb58f94c, 0x00000006, 0x00190000}};
  s21_decimal res;
  int s21_ret = s21_mul(a, b, &res);
  // ck_assert_uint_eq {{0x1bf530c5, 0x156c8f61, 0x00000000, 0x001c0000}};
  int expected_ret = 0;
  // int mem_cmp = memcmp(res.bits,expected.bits,4*sizeof(uint32_t));
  // printf("%s",(mem_cmp)?"Different\n":"Same\n");
  ck_assert_int_eq(s21_ret, expected_ret);
  // ck_assert_mem_eq(&expected, &res, 4 * sizeof(uint32_t));
}
END_TEST

START_TEST(s21_mul_test_67) {
  s21_decimal a = {{0x4111b624, 0xad5e5818, 0x00000006, 0x00190000}};
  s21_decimal b = {{0x41b46244, 0xc3da50ff, 0x00000006, 0x00190000}};
  s21_decimal res;
  int s21_ret = s21_mul(a, b, &res);
  // ck_assert_uint_eq {{0x0e70bcfd, 0x1554ed6a, 0x00000000, 0x001c0000}};
  int expected_ret = 0;
  // int mem_cmp = memcmp(res.bits,expected.bits,4*sizeof(uint32_t));
  // printf("%s",(mem_cmp)?"Different\n":"Same\n");
  ck_assert_int_eq(s21_ret, expected_ret);
  // ck_assert_mem_eq(&expected, &res, 4 * sizeof(uint32_t));
}
END_TEST

START_TEST(s21_mul_test_68) {
  s21_decimal a = {{0x4111b5e7, 0xad5e5818, 0x00000006, 0x00190000}};
  s21_decimal b = {{0xc1772137, 0xbb62f1b1, 0x00000006, 0x00190000}};
  s21_decimal res;
  int s21_ret = s21_mul(a, b, &res);
  // ck_assert_uint_eq {{0xcb05c86b, 0x153a3b31, 0x00000000, 0x001c0000}};
  int expected_ret = 0;
  // int mem_cmp = memcmp(res.bits,expected.bits,4*sizeof(uint32_t));
  // printf("%s",(mem_cmp)?"Different\n":"Same\n");
  ck_assert_int_eq(s21_ret, expected_ret);
  // ck_assert_mem_eq(&expected, &res, 4 * sizeof(uint32_t));
}
END_TEST

START_TEST(s21_mul_test_69) {
  s21_decimal a = {{0x4111b5a9, 0xad5e5818, 0x00000006, 0x00190000}};
  s21_decimal b = {{0xc138df19, 0xb2c80a88, 0x00000006, 0x00190000}};
  s21_decimal res;
  int s21_ret = s21_mul(a, b, &res);
  // ck_assert_uint_eq {{0x36c30a99, 0x151f18f0, 0x00000000, 0x001c0000}};
  int expected_ret = 0;
  // int mem_cmp = memcmp(res.bits,expected.bits,4*sizeof(uint32_t));
  // printf("%s",(mem_cmp)?"Different\n":"Same\n");
  ck_assert_int_eq(s21_ret, expected_ret);
  // ck_assert_mem_eq(&expected, &res, 4 * sizeof(uint32_t));
}
END_TEST

START_TEST(s21_mul_test_70) {
  s21_decimal a = {{0x4111b583, 0xad5e5818, 0x00000006, 0x00190000}};
  s21_decimal b = {{0xc112b693, 0xad81dff3, 0x00000006, 0x00190000}};
  s21_decimal res;
  int s21_ret = s21_mul(a, b, &res);
  // ck_assert_uint_eq {{0x36bb2ae6, 0x150e778e, 0x00000000, 0x001c0000}};
  int expected_ret = 0;
  // int mem_cmp = memcmp(res.bits,expected.bits,4*sizeof(uint32_t));
  // printf("%s",(mem_cmp)?"Different\n":"Same\n");
  ck_assert_int_eq(s21_ret, expected_ret);
  // ck_assert_mem_eq(&expected, &res, 4 * sizeof(uint32_t));
}
END_TEST

START_TEST(s21_mul_test_71) {
  s21_decimal a = {{0x4111b591, 0xad5e5818, 0x00000006, 0x00190000}};
  s21_decimal b = {{0xc120c581, 0xaf734df4, 0x00000006, 0x00190000}};
  s21_decimal res;
  int s21_ret = s21_mul(a, b, &res);
  // ck_assert_uint_eq {{0xa2882c79, 0x15149810, 0x00000000, 0x001c0000}};
  int expected_ret = 0;
  // int mem_cmp = memcmp(res.bits,expected.bits,4*sizeof(uint32_t));
  // printf("%s",(mem_cmp)?"Different\n":"Same\n");
  ck_assert_int_eq(s21_ret, expected_ret);
  // ck_assert_mem_eq(&expected, &res, 4 * sizeof(uint32_t));
}
END_TEST

START_TEST(s21_mul_test_72) {
  s21_decimal a = {{0x4111b5ab, 0xad5e5818, 0x00000006, 0x00190000}};
  s21_decimal b = {{0xc13ae13b, 0xb30f1a3f, 0x00000006, 0x00190000}};
  s21_decimal res;
  int s21_ret = s21_mul(a, b, &res);
  // ck_assert_uint_eq {{0xd8729d1b, 0x151ff902, 0x00000000, 0x001c0000}};
  int expected_ret = 0;
  // int mem_cmp = memcmp(res.bits,expected.bits,4*sizeof(uint32_t));
  // printf("%s",(mem_cmp)?"Different\n":"Same\n");
  ck_assert_int_eq(s21_ret, expected_ret);
  // ck_assert_mem_eq(&expected, &res, 4 * sizeof(uint32_t));
}
END_TEST

START_TEST(s21_mul_test_73) {
  s21_decimal a = {{0x4111be38, 0xad5e5818, 0x00000006, 0x00190000}};
  s21_decimal b = {{0x49d0ff98, 0xe2dfca25, 0x00000007, 0x00190000}};
  s21_decimal res;
  int s21_ret = s21_mul(a, b, &res);
  // ck_assert_uint_eq {{0x1d9680cb, 0x18ddf8ab, 0x00000000, 0x001c0000}};
  int expected_ret = 0;
  // int mem_cmp = memcmp(res.bits,expected.bits,4*sizeof(uint32_t));
  // printf("%s",(mem_cmp)?"Different\n":"Same\n");
  ck_assert_int_eq(s21_ret, expected_ret);
  // ck_assert_mem_eq(&expected, &res, 4 * sizeof(uint32_t));
}
END_TEST

START_TEST(s21_mul_test_74) {
  s21_decimal a = {{0x4111be45, 0xad5e5818, 0x00000006, 0x00190000}};
  s21_decimal b = {{0xc9de0d75, 0xe4adb04a, 0x00000007, 0x00190000}};
  s21_decimal res;
  int s21_ret = s21_mul(a, b, &res);
  // ck_assert_uint_eq {{0x388bb91d, 0x18e3a924, 0x00000000, 0x001c0000}};
  int expected_ret = 0;
  // int mem_cmp = memcmp(res.bits,expected.bits,4*sizeof(uint32_t));
  // printf("%s",(mem_cmp)?"Different\n":"Same\n");
  ck_assert_int_eq(s21_ret, expected_ret);
  // ck_assert_mem_eq(&expected, &res, 4 * sizeof(uint32_t));
}
END_TEST

START_TEST(s21_mul_test_75) {
  s21_decimal a = {{0x4111be6e, 0xad5e5818, 0x00000006, 0x00190000}};
  s21_decimal b = {{0x4a07392e, 0xea5e7272, 0x00000007, 0x00190000}};
  s21_decimal res;
  int s21_ret = s21_mul(a, b, &res);
  // ck_assert_uint_eq {{0x2b1af493, 0x18f59aa2, 0x00000000, 0x001c0000}};
  int expected_ret = 0;
  // int mem_cmp = memcmp(res.bits,expected.bits,4*sizeof(uint32_t));
  // printf("%s",(mem_cmp)?"Different\n":"Same\n");
  ck_assert_int_eq(s21_ret, expected_ret);
  // ck_assert_mem_eq(&expected, &res, 4 * sizeof(uint32_t));
}
END_TEST

Suite *s21_mul_suite_create() {
  Suite *suite = suite_create("s21_mul_test");
  TCase *tc_core = tcase_create("tcase_core_s21_mul_test");

  tcase_add_test(tc_core, s21_mul_test_1);
  tcase_add_test(tc_core, s21_mul_test_2);
  tcase_add_test(tc_core, s21_mul_test_3);
  tcase_add_test(tc_core, s21_mul_test_4);
  tcase_add_test(tc_core, s21_mul_test_5);
  tcase_add_test(tc_core, s21_mul_test_6);
  tcase_add_test(tc_core, s21_mul_test_7);
  tcase_add_test(tc_core, s21_mul_test_8);
  tcase_add_test(tc_core, s21_mul_test_9);
  tcase_add_test(tc_core, s21_mul_test_10);
  tcase_add_test(tc_core, s21_mul_test_11);
  tcase_add_test(tc_core, s21_mul_test_12);
  tcase_add_test(tc_core, s21_mul_test_13);
  tcase_add_test(tc_core, s21_mul_test_14);
  tcase_add_test(tc_core, s21_mul_test_15);
  tcase_add_test(tc_core, s21_mul_test_16);
  tcase_add_test(tc_core, s21_mul_test_17);
  tcase_add_test(tc_core, s21_mul_test_18);
  tcase_add_test(tc_core, s21_mul_test_19);
  tcase_add_test(tc_core, s21_mul_test_20);
  tcase_add_test(tc_core, s21_mul_test_20);
  tcase_add_test(tc_core, s21_mul_test_21);
  // tcase_add_test(tc_core, s21_mul_test_22);
  tcase_add_test(tc_core, s21_mul_test_23);
  tcase_add_test(tc_core, s21_mul_test_24);
  tcase_add_test(tc_core, s21_mul_test_25);
  tcase_add_test(tc_core, s21_mul_test_26);
  tcase_add_test(tc_core, s21_mul_test_27);
  tcase_add_test(tc_core, s21_mul_test_28);
  tcase_add_test(tc_core, s21_mul_test_29);
  tcase_add_test(tc_core, s21_mul_test_30);
  tcase_add_test(tc_core, s21_mul_test_31);
  tcase_add_test(tc_core, s21_mul_test_32);
  tcase_add_test(tc_core, s21_mul_test_33);
  tcase_add_test(tc_core, s21_mul_test_34);
  tcase_add_test(tc_core, s21_mul_test_35);
  tcase_add_test(tc_core, s21_mul_test_36);
  tcase_add_test(tc_core, s21_mul_test_37);
  tcase_add_test(tc_core, s21_mul_test_38);
  tcase_add_test(tc_core, s21_mul_test_39);
  tcase_add_test(tc_core, s21_mul_test_40);
  tcase_add_test(tc_core, s21_mul_test_41);
  tcase_add_test(tc_core, s21_mul_test_42);
  tcase_add_test(tc_core, s21_mul_test_43);
  tcase_add_test(tc_core, s21_mul_test_44);
  tcase_add_test(tc_core, s21_mul_test_45);
  tcase_add_test(tc_core, s21_mul_test_46);
  tcase_add_test(tc_core, s21_mul_test_47);
  tcase_add_test(tc_core, s21_mul_test_48);
  tcase_add_test(tc_core, s21_mul_test_49);
  tcase_add_test(tc_core, s21_mul_test_50);
  tcase_add_test(tc_core, s21_mul_test_51);
  tcase_add_test(tc_core, s21_mul_test_52);
  tcase_add_test(tc_core, s21_mul_test_53);
  tcase_add_test(tc_core, s21_mul_test_54);
  tcase_add_test(tc_core, s21_mul_test_55);
  tcase_add_test(tc_core, s21_mul_test_56);
  tcase_add_test(tc_core, s21_mul_test_57);
  tcase_add_test(tc_core, s21_mul_test_58);
  tcase_add_test(tc_core, s21_mul_test_59);
  tcase_add_test(tc_core, s21_mul_test_60);
  tcase_add_test(tc_core, s21_mul_test_60);
  tcase_add_test(tc_core, s21_mul_test_61);
  tcase_add_test(tc_core, s21_mul_test_62);
  tcase_add_test(tc_core, s21_mul_test_63);
  tcase_add_test(tc_core, s21_mul_test_64);
  tcase_add_test(tc_core, s21_mul_test_65);
  tcase_add_test(tc_core, s21_mul_test_66);
  tcase_add_test(tc_core, s21_mul_test_67);
  tcase_add_test(tc_core, s21_mul_test_68);
  tcase_add_test(tc_core, s21_mul_test_69);
  tcase_add_test(tc_core, s21_mul_test_70);
  tcase_add_test(tc_core, s21_mul_test_71);
  tcase_add_test(tc_core, s21_mul_test_72);
  tcase_add_test(tc_core, s21_mul_test_73);
  tcase_add_test(tc_core, s21_mul_test_74);
  tcase_add_test(tc_core, s21_mul_test_75);

  suite_add_tcase(suite, tc_core);

  return suite;
}

int main() {
  int failed_count = 0;

  Suite *suite = s21_mul_suite_create();
  SRunner *suite_runner = srunner_create(suite);

  srunner_run_all(suite_runner, CK_NORMAL);
  failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);

  return failed_count != 0 && !SHOW_FAILED ? EXIT_FAILURE : EXIT_SUCCESS;
}
