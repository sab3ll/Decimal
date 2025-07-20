#include <check.h>
#include <stdlib.h>

#include "../s21_decimal.h"

#define SHOW_FAILED TRUE

START_TEST(s21_is_greater_test_1) {
  s21_decimal a = {{UINT_MAX, 0, 0, 0}};
  s21_decimal b = {{UINT_MAX, 0, 0, 0}};
  ck_assert_int_eq(s21_is_greater(a, b), 0);
}
END_TEST

START_TEST(s21_is_greater_test_2) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  ck_assert_int_eq(0, s21_is_greater(val1, val2));
}
END_TEST

START_TEST(s21_is_greater_test_3) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  val1.bits[0] = 255;
  val2.bits[0] = 256;
  ck_assert_int_eq(0, s21_is_greater(val1, val2));
}
END_TEST

START_TEST(s21_is_greater_test_4) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  val1.bits[0] = 256;
  val2.bits[0] = 256;
  ck_assert_int_eq(0, s21_is_greater(val1, val2));
}
END_TEST

START_TEST(s21_is_greater_test_5) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  val1.bits[0] = 257;
  val2.bits[0] = 256;
  ck_assert_int_eq(1, s21_is_greater(val1, val2));
}
END_TEST

START_TEST(s21_is_greater_test_6) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  set_bit(&val1, 127, 1);
  ck_assert_int_eq(0, s21_is_greater(val1, val2));
}
END_TEST

START_TEST(s21_is_greater_test_7) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  val1.bits[0] = 257;
  val2.bits[0] = 257;
  val1.bits[2] = 256;
  val2.bits[2] = 257;
  set_scale(&val1, 11);
  set_scale(&val2, 10);
  ck_assert_int_eq(0, s21_is_greater(val1, val2));
}
END_TEST

START_TEST(s21_is_greater_test_8) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  val1.bits[0] = 257;
  val2.bits[0] = 257;
  val1.bits[2] = 256;
  val2.bits[2] = 257;
  set_scale(&val1, 10);
  set_scale(&val2, 11);
  ck_assert_int_eq(1, s21_is_greater(val1, val2));
}
END_TEST

START_TEST(s21_is_greater_test_9) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  val2.bits[2] = 257;
  set_bit(&val1, 127, 1);
  set_bit(&val2, 127, 1);
  ck_assert_int_eq(1, s21_is_greater(val1, val2));
}
END_TEST

START_TEST(s21_is_greater_test_10) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  val2.bits[2] = 257;
  set_bit(&val1, 127, 1);
  set_bit(&val2, 127, 0);
  ck_assert_int_eq(0, s21_is_greater(val1, val2));
}
END_TEST

START_TEST(s21_is_greater_test_11) {
  float a = rand();
  float b = rand();

  s21_decimal _a = {{0}};
  s21_decimal _b = {{0}};
  s21_from_float_to_decimal(a, &_a);
  s21_from_float_to_decimal(b, &_b);
  ck_assert_int_eq(s21_is_greater(_a, _b), a > b);
}
END_TEST

START_TEST(s21_is_greater_test_12) {
  float a = rand();
  float b = rand();

  s21_decimal _a = {{0}};
  s21_decimal _b = {{0}};
  s21_from_float_to_decimal(a, &_a);
  s21_from_float_to_decimal(b, &_b);
  ck_assert_int_eq(s21_is_greater(_a, _b), a > b);
}
END_TEST

START_TEST(s21_is_greater_test_13) {
  s21_decimal value_1 = {{123457u, 654u, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  int return_value = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(s21_is_greater_test_14) {
  s21_decimal value_1 = {{123457u, 654u, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  set_sign(&value_1, MINUS);
  int return_value = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_is_greater_test_15) {
  s21_decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{123457u, 654u, 0xFFFFFFFF, 0}};
  set_sign(&value_2, MINUS);
  int return_value = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(s21_is_greater_test_16) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  set_sign(&value_2, MINUS);
  int return_value = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_is_greater_test_17) {
  s21_decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{123457u, 654u, 0xFFFFFFFF, 0}};
  set_sign(&value_1, MINUS);
  set_sign(&value_2, MINUS);
  int return_value = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(s21_is_greater_test_18) {
  s21_decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  set_scale(&value_2, 10);
  int return_value = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_is_greater_test_19) {
  s21_decimal value_1 = {{234, 0, 0, 0}};
  s21_decimal value_2 = {{2, 0, 0, 0}};
  set_scale(&value_1, 2);
  int return_value = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(s21_is_greater_test_20) {
  float num1 = 1.375342323523;
  float num2 = 1.39;
  s21_decimal dec1, dec2;
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_is_greater_test_21) {
  float num1 = 1.39;
  float num2 = 1.39;
  s21_decimal dec1, dec2;
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_is_greater_test_22) {
  float num1 = 1.39;
  float num2 = -1.39;
  s21_decimal dec1, dec2;
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_is_greater_test_23) {
  int num1 = 0;
  int num2 = 0;
  s21_decimal dec1, dec2;
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_is_greater_test_24) {
  int num1 = 3;
  int num2 = 9;
  s21_decimal dec1, dec2;
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_is_greater_test_25) {
  int num1 = -3;
  int num2 = -3;
  s21_decimal dec1, dec2;
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_is_greater_test_26) {
  int num1 = -3;
  int num2 = 3;
  s21_decimal dec1, dec2;
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_is_greater_test_27) {
  float num1 = -3.232446546;
  float num2 = -3.2;
  s21_decimal dec1, dec2;
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_is_greater_test_28) {
  float num1 = -345.232446546;
  float num2 = -3.2;
  s21_decimal dec1, dec2;
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_is_greater_test_29) {
  float num1 = -3.232323233232323233;
  float num2 = -34545124.232446543232446543;
  s21_decimal dec1, dec2;
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_is_greater_test_30) {
  s21_decimal dec5 = {
      {12345, 0, 0, 0b00000000000001000000000000000000}};  //  1.2345
  s21_decimal dec6 = {
      {12, 0, 0, 0b10000000000000010000000000000000}};  //  -1.2;
  ck_assert_int_eq(s21_is_greater(dec5, dec6), 1);
  ck_assert_int_eq(s21_is_greater(dec6, dec5), 0);

  s21_decimal dec7 = {
      {12345, 0, 0, 0b10000000000001000000000000000000}};  // -1.2345
  s21_decimal dec8 = {{12, 0, 0, 0b00000000000000010000000000000000}};  //  1.2;
  ck_assert_int_eq(s21_is_greater(dec7, dec8), 0);
  ck_assert_int_eq(s21_is_greater(dec8, dec7), 1);

  s21_decimal dec1 = {
      {12345, 0, 0, 0b00000000000001000000000000000000}};  //  1.2345
  s21_decimal dec2 = {{12, 0, 0, 0b00000000000000010000000000000000}};  //  1.2
  ck_assert_int_eq(s21_is_greater(dec1, dec2), 1);
  ck_assert_int_eq(s21_is_greater(dec2, dec1), 0);

  s21_decimal dec3 = {
      {12345, 0, 0, 0b10000000000001000000000000000000}};  // -1.2345
  s21_decimal dec4 = {
      {12, 0, 0, 0b10000000000000010000000000000000}};  //   -1.2
  ck_assert_int_eq(s21_is_greater(dec3, dec4), 0);
  ck_assert_int_eq(s21_is_greater(dec4, dec3), 1);
}
END_TEST

START_TEST(s21_is_greater_test_31) {
  s21_decimal a = {{2, 0, 0, 0}};
  s21_decimal b = {{1, 0, 0, 0}};
  ck_assert_int_eq(s21_is_greater(a, b), 1);
  // Возвращаемое значение : 0 - 0   1 - TRUE
}
END_TEST

START_TEST(s21_is_greater_test_32) {
  s21_decimal a = {{UINT_MAX, 0, 0, 0}};
  s21_decimal b = {{0, 0, 0, 0}};
  ck_assert_int_eq(s21_is_greater(a, b), 1);
}
END_TEST

START_TEST(s21_is_greater_test_33) {
  s21_decimal a = {{UINT_MAX, 0, 0, 0}};
  s21_decimal b = {{UINT_MAX - 1, 0, 0, 0}};
  ck_assert_int_eq(s21_is_greater(a, b), 1);
}
END_TEST

START_TEST(s21_is_greater_test_34) {
  s21_decimal a = {{UINT_MAX, 0, 0, 0}};
  s21_decimal b = {{UINT_MAX, 1, 0, 0}};
  ck_assert_int_eq(s21_is_greater(a, b), 0);
}
END_TEST

START_TEST(s21_is_greater_test_35) {
  s21_decimal a = {{UINT_MAX, 1, 0, 0}};
  s21_decimal b = {{UINT_MAX, 0, 0, 0}};
  ck_assert_int_eq(s21_is_greater(a, b), 1);
}
END_TEST

START_TEST(s21_is_greater_test_36) {
  s21_decimal a = {{UINT_MAX, UINT_MAX, 0, 0}};
  s21_decimal b = {{UINT_MAX, UINT_MAX - 1, 0, 0}};
  ck_assert_int_eq(s21_is_greater(a, b), 1);
}
END_TEST

START_TEST(s21_is_greater_test_37) {
  s21_decimal a = {{UINT_MAX, UINT_MAX, 0, 0}};
  s21_decimal b = {{UINT_MAX, UINT_MAX, 0, 0}};
  ck_assert_int_eq(s21_is_greater(a, b), 0);
}
END_TEST

START_TEST(s21_is_greater_test_38) {
  s21_decimal a = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal b = {{UINT_MAX, UINT_MAX, UINT_MAX - 1, 0}};
  ck_assert_int_eq(s21_is_greater(a, b), 1);
}
END_TEST

START_TEST(s21_is_greater_test_39) {
  s21_decimal a = {{UINT_MAX, UINT_MAX, UINT_MAX - 1, 0}};
  s21_decimal b = {{UINT_MAX, UINT_MAX, 0, 0}};
  ck_assert_int_eq(s21_is_greater(a, b), 1);
}
END_TEST

START_TEST(s21_is_greater_test_40) {
  s21_decimal a = {{0, UINT_MAX, UINT_MAX, 0}};
  s21_decimal b = {{0, UINT_MAX, UINT_MAX - 1, 0}};
  ck_assert_int_eq(s21_is_greater(a, b), 1);
}
END_TEST

START_TEST(s21_is_greater_test_41) {
  s21_decimal a = {{0, 0, UINT_MAX, 0}};
  s21_decimal b = {{0, 0, UINT_MAX - 1, 0}};
  ck_assert_int_eq(s21_is_greater(a, b), 1);
}
END_TEST

START_TEST(s21_is_greater_test_42) {
  s21_decimal a = {{0, 0, 0, 0}};
  s21_decimal b = {{0, 0, UINT_MAX, 0}};
  ck_assert_int_eq(s21_is_greater(a, b), 0);
}
END_TEST

START_TEST(s21_is_greater_test_43) {
  // 3820
  s21_decimal src1 = {{0}};
  s21_decimal src2 = {{0}};
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
  int result = s21_is_greater(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_greater_test_44) {
  // 3838
  s21_decimal src1 = {{0}};
  s21_decimal src2 = {{0}};
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
  int result = s21_is_greater(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_greater_test_45) {
  // 3856
  s21_decimal src1 = {{0}};
  s21_decimal src2 = {{0}};
  // src1 = 3;
  // src2 = 3;

  src1.bits[0] = 0b00000000000000000000000000000011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000011;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_greater_test_46) {
  // 3874
  s21_decimal src1 = {{0}};
  s21_decimal src2 = {{0}};
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
  int result = s21_is_greater(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_greater_test_47) {
  // 3892
  s21_decimal src1 = {{0}};
  s21_decimal src2 = {{0}};
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
  int result = s21_is_greater(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_greater_test_48) {
  // 3910
  s21_decimal src1 = {{0}};
  s21_decimal src2 = {{0}};
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
  int result = s21_is_greater(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_greater_test_49) {
  // 3928
  s21_decimal src1 = {{0}};
  s21_decimal src2 = {{0}};
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
  int result = s21_is_greater(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_greater_test_50) {
  // 3946
  s21_decimal src1 = {{0}};
  s21_decimal src2 = {{0}};
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
  int result = s21_is_greater(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_greater_test_51) {
  // 3964
  s21_decimal src1 = {{0}};
  s21_decimal src2 = {{0}};
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
  int result = s21_is_greater(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_greater_test_52) {
  // 3982
  s21_decimal src1 = {{0}};
  s21_decimal src2 = {{0}};
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
  int result = s21_is_greater(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_greater_test_53) {
  // 4000
  s21_decimal src1 = {{0}};
  s21_decimal src2 = {{0}};
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
  int result = s21_is_greater(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_greater_test_54) {
  // 4018
  s21_decimal src1 = {{0}};
  s21_decimal src2 = {{0}};
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
  int result = s21_is_greater(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_greater_test_55) {
  // 4036
  s21_decimal src1 = {{0}};
  s21_decimal src2 = {{0}};
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
  int result = s21_is_greater(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_greater_test_56) {
  // 4054
  s21_decimal src1 = {{0}};
  s21_decimal src2 = {{0}};
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
  int result = s21_is_greater(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_greater_test_57) {
  // 4072
  s21_decimal src1 = {{0}};
  s21_decimal src2 = {{0}};
  // src1 = 18446744073709551615.0;
  // src2 = 965453154;

  src1.bits[0] = 0b11111111111111111111111111110110;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b00000000000000000000000000001001;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src2.bits[0] = 0b00111001100010111010010101100010;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_greater_test_58) {
  // 4090
  s21_decimal src1 = {{0}};
  s21_decimal src2 = {{0}};
  // src1 = -545454512454545.35265454545645;
  // src2 = 54564654;

  src1.bits[0] = 0b10000010111000100101101011101101;
  src1.bits[1] = 0b11111001111010000010010110101101;
  src1.bits[2] = 0b10110000001111101111000010010100;
  src1.bits[3] = 0b10000000000011100000000000000000;
  src2.bits[0] = 0b00000011010000001001011100101110;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_greater_test_59) {
  // 4126
  s21_decimal src1 = {{0}};
  s21_decimal src2 = {{0}};
  // src1 = 7961327845421.879754123131254;
  // src2 = 0;

  src1.bits[0] = 0b01001110111001000011100101110110;
  src1.bits[1] = 0b01001011001101011010000111011001;
  src1.bits[2] = 0b00011001101110010111010010111111;
  src1.bits[3] = 0b00000000000011110000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_greater_test_60) {
  // 4144
  s21_decimal src1 = {{0}};
  s21_decimal src2 = {{0}};
  // src1 = 12345677.987654345678987654346;
  // src2 = 87654323456.9876545678987653;

  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b00000000000101010000000000000000;

  src2.bits[0] = 0b00010001110011011101000110000101;
  src2.bits[1] = 0b11110101101111000110111111000000;
  src2.bits[2] = 0b00000010110101010000111100111111;
  src2.bits[3] = 0b00000000000100000000000000000000;
  int result = s21_is_greater(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_greater_test_61) {
  // 4162
  s21_decimal src1 = {{0}};
  s21_decimal src2 = {{0}};
  // src1 = -12345677.987654345678987654346;
  // src2 = 87654323456.9876545678987653;

  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b10000000000101010000000000000000;
  src2.bits[0] = 0b00010001110011011101000110000101;
  src2.bits[1] = 0b11110101101111000110111111000000;
  src2.bits[2] = 0b00000010110101010000111100111111;
  src2.bits[3] = 0b00000000000100000000000000000000;
  int result = s21_is_greater(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_greater_test_62) {
  // 4180
  s21_decimal src1 = {{0}};
  s21_decimal src2 = {{0}};
  // src1 = 12345677.987654345678987654346;
  // src2 = -87654323456.9876545678987653;

  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b00000000000101010000000000000000;
  src2.bits[0] = 0b00010001110011011101000110000101;
  src2.bits[1] = 0b11110101101111000110111111000000;
  src2.bits[2] = 0b00000010110101010000111100111111;
  src2.bits[3] = 0b10000000000100000000000000000000;
  int result = s21_is_greater(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_greater_test_63) {
  // 4198
  s21_decimal src1 = {{0}};
  s21_decimal src2 = {{0}};
  // src1 = -12345677.987654345678987654346;
  // src2 = -87654323456.9876545678987653;

  src1.bits[0] = 0b10010001000010101111010011001010;
  src1.bits[1] = 0b11000000010001011101010111110010;
  src1.bits[2] = 0b00100111111001000001101100000000;
  src1.bits[3] = 0b10000000000101010000000000000000;
  src2.bits[0] = 0b00010001110011011101000110000101;
  src2.bits[1] = 0b11110101101111000110111111000000;
  src2.bits[2] = 0b00000010110101010000111100111111;
  src2.bits[3] = 0b10000000000100000000000000000000;
  int result = s21_is_greater(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_greater_test_64) {
  // 4216
  s21_decimal src1 = {{0}};
  s21_decimal src2 = {{0}};
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
  int result = s21_is_greater(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_greater_test_65) {
  // 4234
  s21_decimal src1 = {{0}};
  s21_decimal src2 = {{0}};
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
  int result = s21_is_greater(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_greater_test_66) {
  // 4252
  s21_decimal src1 = {{0}};
  s21_decimal src2 = {{0}};
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
  int result = s21_is_greater(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_greater_test_67) {
  // 4270
  s21_decimal src1 = {{0}};
  s21_decimal src2 = {{0}};
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
  int result = s21_is_greater(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_greater_test_68) {
  // 4288
  s21_decimal src1 = {{0}};
  s21_decimal src2 = {{0}};
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
  int result = s21_is_greater(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_greater_test_69) {
  // 4306
  s21_decimal src1 = {{0}};
  s21_decimal src2 = {{0}};
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
  int result = s21_is_greater(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_greater_test_70) {
  // 4324
  s21_decimal src1 = {{0}};
  s21_decimal src2 = {{0}};
  // src1 = 2.7986531268974139743;
  // src2 = 9.979623121254565121244554;

  src1.bits[0] = 0b11111110100100001101100101011111;
  src1.bits[1] = 0b10000100011001000010000111101000;
  src1.bits[2] = 0b00000000000000000000000000000001;
  src1.bits[3] = 0b00000000000100110000000000000000;
  src2.bits[0] = 0b11010100101011100011110110001010;
  src2.bits[1] = 0b01110100000101000010011110100011;
  src2.bits[2] = 0b00000000000010000100000101000100;
  src2.bits[3] = 0b00000000000110000000000000000000;
  int result = s21_is_greater(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_greater_test_71) {
  // 4342
  s21_decimal src1 = {{0}};
  s21_decimal src2 = {{0}};
  // src1 = -9798956154578676.797564534156;
  // src2 = -2156878451.854764;

  src1.bits[0] = 0b01010100010000000011110110001100;
  src1.bits[1] = 0b10001011010100100000010101011001;
  src1.bits[2] = 0b00011111101010011000000110101101;
  src1.bits[3] = 0b10000000000011000000000000000000;
  src2.bits[0] = 0b01100101111100100100110110101100;
  src2.bits[1] = 0b00000000000001111010100110101011;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000001100000000000000000;
  int result = s21_is_greater(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_greater_test_72) {
  // 4360
  s21_decimal src1 = {{0}};
  s21_decimal src2 = {{0}};
  // src1 = 0.5456465465486476846545465485;
  // src2 = 0.68985125146545154;

  src1.bits[0] = 0b00001011000011110111000010001101;
  src1.bits[1] = 0b10010110101100000101100101010001;
  src1.bits[2] = 0b00010001101000010111101110000001;
  src1.bits[3] = 0b00000000000111000000000000000000;
  src2.bits[0] = 0b00010111001001010100110000000010;
  src2.bits[1] = 0b00000000111101010001010110011011;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000100010000000000000000;
  int result = s21_is_greater(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_greater_test_73) {
  // 4378
  s21_decimal src1 = {{0}};
  s21_decimal src2 = {{0}};
  // src1 = -0.77545545454546589781;
  // src2 = 87894515154546456456;

  src1.bits[0] = 0b10101100001010000001100001010101;
  src1.bits[1] = 0b00110100001010010001111010111100;
  src1.bits[2] = 0b00000000000000000000000000000100;
  src1.bits[3] = 0b10000000000101000000000000000000;
  src2.bits[0] = 0b00010011111011011111011110001000;
  src2.bits[1] = 0b11000011110010000000101111011001;
  src2.bits[2] = 0b00000000000000000000000000000100;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_greater(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_greater_test_74) {
  // 4396
  s21_decimal src1 = {{0}};
  s21_decimal src2 = {{0}};
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
  int result = s21_is_greater(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_greater_test_75) {
  // 4414
  s21_decimal src1 = {{0}};
  s21_decimal src2 = {{0}};
  // src1 = 32323465788987654;
  // src2 = 67543278.89765424354657687;

  src1.bits[0] = 0b01011000010000110001100100000110;
  src1.bits[1] = 0b00000000011100101101011000000101;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b10111110000100011000010110010111;
  src2.bits[1] = 0b11011001001111010001001011000110;
  src2.bits[2] = 0b00000000000001011001011001001000;
  src2.bits[3] = 0b00000000000100010000000000000000;
  int result = s21_is_greater(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_greater_test_76) {
  // 4450
  s21_decimal src1 = {{0}};
  s21_decimal src2 = {{0}};
  // src1 = 0;
  // src2 = -37986322154988653.784354545765;

  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b01001111101101000110000001100101;
  src2.bits[1] = 0b01000010001101101011011001100001;
  src2.bits[2] = 0b01111010101111011000110010011010;
  src2.bits[3] = 0b10000000000011000000000000000000;
  int result = s21_is_greater(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

// START_TEST(s21_is_greater_test_77) {
//   s21_decimal dec1 = {.bits[0] = 15,
//                       .bits[1] = 15,
//                       .bits[2] = 20,
//                       .bits[3] = 0b10000000000001010000000000000000};
//   s21_decimal dec2 = {.bits[0] = 15,
//                       .bits[1] = 15,
//                       .bits[2] = 15,
//                       .bits[3] = 0b10000000000001010000000000000000};
//   int result = s21_is_greater(dec1, dec2);
//   ck_assert_int_eq(result, 0);
// }
// END_TEST

START_TEST(s21_is_greater_test_78) {
  s21_decimal dec1 = {{0x48668fc0, 0x00000001, 0x00000000, 0x000a0000}};
  s21_decimal dec2 = {{0x48668fc0, 0x00000001, 0x00000000, 0x800a0000}};
  int s21_ret = s21_is_greater(dec1, dec2);
  int expected_ret = 1;
  ck_assert_int_eq(s21_ret, expected_ret);
}
END_TEST

START_TEST(s21_is_greater_test_79) {
  s21_decimal dec1 = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  s21_decimal dec2 = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_ret = s21_is_greater(dec1, dec2);
  int expected_ret = 0;
  ck_assert_int_eq(s21_ret, expected_ret);
}
END_TEST

START_TEST(s21_is_greater_test_80) {
  s21_decimal dec1 = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  s21_decimal dec2 = {{0x00000000, 0x00000000, 0x00000000, 0x80000000}};
  int s21_ret = s21_is_greater(dec1, dec2);
  int expected_ret = 0;
  ck_assert_int_eq(s21_ret, expected_ret);
}
END_TEST

START_TEST(s21_is_greater_test_81) {
  s21_decimal dec1 = {{0x80000000, 0x00000000, 0x00000000, 0x80000000}};
  s21_decimal dec2 = {{0x10000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_ret = s21_is_greater(dec1, dec2);
  int expected_ret = 0;
  ck_assert_int_eq(s21_ret, expected_ret);
}
END_TEST

START_TEST(s21_is_greater_test_82) {
  s21_decimal dec1 = {{0x80000000, 0x00000000, 0x00000000, 0x80000000}};
  s21_decimal dec2 = {{0x10000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_ret = s21_is_greater(dec1, dec2);
  int expected_ret = 0;
  ck_assert_int_eq(s21_ret, expected_ret);
}
END_TEST

// START_TEST(s21_is_greater_test_83) {
//   s21_decimal dec1 = {
//       .bits[0] = 15, .bits[1] = 15, .bits[2] = 20, .bits[3] = 1};
//   s21_decimal dec2 = {
//       .bits[0] = 15, .bits[1] = 15, .bits[2] = 15, .bits[3] = 0};
//   int s21_ret = s21_is_greater(dec1, dec2);
//   int expected_ret = 1;
//   ck_assert_int_eq(s21_ret, expected_ret);
// }
// END_TEST

// START_TEST(s21_is_greater_test_84) {
//   s21_decimal dec1 = {.bits[0] = 1, .bits[1] = 1, .bits[2] = 1, .bits[3] =
//   1}; s21_decimal dec2 = {
//       .bits[0] = 15, .bits[1] = 15, .bits[2] = 15, .bits[3] = 0};
//   int result = s21_is_greater(dec1, dec2);
//   ck_assert_int_eq(result, 0);
// }
// END_TEST

// START_TEST(s21_is_greater_test_85) {
//   s21_decimal dec1 = {.bits[0] = 10,
//                       .bits[1] = 10,
//                       .bits[2] = 10,
//                       .bits[3] = 0b10000000000000000000000000000000};

//   s21_decimal dec2 = {.bits[0] = 25,
//                       .bits[1] = 25,
//                       .bits[2] = 25,
//                       .bits[3] = 0b10000000000000000000000000000000};
//   int result = s21_is_greater(dec1, dec2);
//   ck_assert_int_eq(result, 1);
// }
// END_TEST

START_TEST(s21_is_greater_test_86) {
  s21_decimal dec1 = {{0x1ddc6d30, 0x00000002, 0x00000000, 0x000a0000}};
  s21_decimal dec2 = {{0x1ddc6d30, 0x00000002, 0x00000000, 0x800a0000}};
  int s21_ret = s21_is_greater(dec1, dec2);
  int expected_ret = 1;

  ck_assert_int_eq(s21_ret, expected_ret);
}
END_TEST

Suite *s21_is_greater_suite_create() {
  Suite *suite = suite_create("s21_is_greater_test");
  TCase *tc_core = tcase_create("tcase_core_s21_is_greater_test");

  tcase_add_test(tc_core, s21_is_greater_test_1);
  tcase_add_test(tc_core, s21_is_greater_test_2);
  tcase_add_test(tc_core, s21_is_greater_test_3);
  tcase_add_test(tc_core, s21_is_greater_test_4);
  tcase_add_test(tc_core, s21_is_greater_test_5);
  tcase_add_test(tc_core, s21_is_greater_test_6);
  tcase_add_test(tc_core, s21_is_greater_test_7);
  tcase_add_test(tc_core, s21_is_greater_test_8);
  tcase_add_test(tc_core, s21_is_greater_test_9);
  tcase_add_test(tc_core, s21_is_greater_test_10);
  tcase_add_test(tc_core, s21_is_greater_test_11);
  tcase_add_test(tc_core, s21_is_greater_test_12);
  tcase_add_test(tc_core, s21_is_greater_test_13);
  tcase_add_test(tc_core, s21_is_greater_test_14);
  tcase_add_test(tc_core, s21_is_greater_test_15);
  tcase_add_test(tc_core, s21_is_greater_test_16);
  tcase_add_test(tc_core, s21_is_greater_test_17);
  tcase_add_test(tc_core, s21_is_greater_test_18);
  tcase_add_test(tc_core, s21_is_greater_test_19);
  tcase_add_test(tc_core, s21_is_greater_test_20);
  tcase_add_test(tc_core, s21_is_greater_test_21);
  tcase_add_test(tc_core, s21_is_greater_test_22);
  tcase_add_test(tc_core, s21_is_greater_test_23);
  tcase_add_test(tc_core, s21_is_greater_test_24);
  tcase_add_test(tc_core, s21_is_greater_test_25);
  tcase_add_test(tc_core, s21_is_greater_test_26);
  tcase_add_test(tc_core, s21_is_greater_test_27);
  tcase_add_test(tc_core, s21_is_greater_test_28);
  tcase_add_test(tc_core, s21_is_greater_test_29);
  tcase_add_test(tc_core, s21_is_greater_test_30);
  tcase_add_test(tc_core, s21_is_greater_test_31);
  tcase_add_test(tc_core, s21_is_greater_test_32);
  tcase_add_test(tc_core, s21_is_greater_test_33);
  tcase_add_test(tc_core, s21_is_greater_test_34);
  tcase_add_test(tc_core, s21_is_greater_test_35);
  tcase_add_test(tc_core, s21_is_greater_test_36);
  tcase_add_test(tc_core, s21_is_greater_test_37);
  tcase_add_test(tc_core, s21_is_greater_test_38);
  tcase_add_test(tc_core, s21_is_greater_test_39);
  tcase_add_test(tc_core, s21_is_greater_test_40);
  tcase_add_test(tc_core, s21_is_greater_test_41);
  tcase_add_test(tc_core, s21_is_greater_test_42);
  tcase_add_test(tc_core, s21_is_greater_test_43);
  tcase_add_test(tc_core, s21_is_greater_test_44);
  tcase_add_test(tc_core, s21_is_greater_test_45);
  tcase_add_test(tc_core, s21_is_greater_test_46);
  tcase_add_test(tc_core, s21_is_greater_test_47);
  tcase_add_test(tc_core, s21_is_greater_test_48);
  tcase_add_test(tc_core, s21_is_greater_test_49);
  tcase_add_test(tc_core, s21_is_greater_test_50);
  tcase_add_test(tc_core, s21_is_greater_test_51);
  tcase_add_test(tc_core, s21_is_greater_test_52);
  tcase_add_test(tc_core, s21_is_greater_test_53);
  tcase_add_test(tc_core, s21_is_greater_test_54);
  tcase_add_test(tc_core, s21_is_greater_test_55);
  tcase_add_test(tc_core, s21_is_greater_test_56);
  tcase_add_test(tc_core, s21_is_greater_test_57);
  tcase_add_test(tc_core, s21_is_greater_test_58);
  tcase_add_test(tc_core, s21_is_greater_test_59);
  tcase_add_test(tc_core, s21_is_greater_test_60);
  tcase_add_test(tc_core, s21_is_greater_test_61);
  tcase_add_test(tc_core, s21_is_greater_test_62);
  tcase_add_test(tc_core, s21_is_greater_test_63);
  tcase_add_test(tc_core, s21_is_greater_test_64);
  tcase_add_test(tc_core, s21_is_greater_test_65);
  tcase_add_test(tc_core, s21_is_greater_test_66);
  tcase_add_test(tc_core, s21_is_greater_test_67);
  tcase_add_test(tc_core, s21_is_greater_test_68);
  tcase_add_test(tc_core, s21_is_greater_test_69);
  tcase_add_test(tc_core, s21_is_greater_test_70);
  tcase_add_test(tc_core, s21_is_greater_test_71);
  tcase_add_test(tc_core, s21_is_greater_test_72);
  tcase_add_test(tc_core, s21_is_greater_test_73);
  tcase_add_test(tc_core, s21_is_greater_test_74);
  tcase_add_test(tc_core, s21_is_greater_test_75);
  tcase_add_test(tc_core, s21_is_greater_test_76);
  // tcase_add_test(tc_core, s21_is_greater_test_77);
  tcase_add_test(tc_core, s21_is_greater_test_78);
  tcase_add_test(tc_core, s21_is_greater_test_79);
  tcase_add_test(tc_core, s21_is_greater_test_80);
  tcase_add_test(tc_core, s21_is_greater_test_81);
  tcase_add_test(tc_core, s21_is_greater_test_82);
  // tcase_add_test(tc_core, s21_is_greater_test_83);
  // tcase_add_test(tc_core, s21_is_greater_test_84);E
  // tcase_add_test(tc_core, s21_is_greater_test_85);
  tcase_add_test(tc_core, s21_is_greater_test_86);

  suite_add_tcase(suite, tc_core);

  return suite;
}

int main() {
  int failed_count = 0;

  Suite *suite = s21_is_greater_suite_create();
  SRunner *suite_runner = srunner_create(suite);

  srunner_run_all(suite_runner, CK_NORMAL);
  failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);

  return failed_count != 0 && !SHOW_FAILED ? EXIT_FAILURE : EXIT_SUCCESS;
}
