#include <check.h>
#include <stdlib.h>

#include "../s21_decimal.h"

#define SHOW_FAILED TRUE

START_TEST(s21_truncate_test_1) {
  s21_decimal val = {{7, 7, 7, 0}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_truncate(val, &res));
  float fres = 0;
  s21_from_decimal_to_float(res, &fres);
  float need = 129127208515966861312.0;
  ck_assert_uint_eq(need, fres);
}
END_TEST

START_TEST(s21_truncate_test_2) {
  s21_decimal dec1 = {0};

  dec1.bits[OLDER] = 0x000A0000;
  dec1.bits[HIGH] = 0x0;
  dec1.bits[MID] = 0xFFFFFFFF;
  dec1.bits[LOW] = 0xFFFFFFFF;
  s21_decimal result = {0};
  result.bits[OLDER] = 0x0;
  result.bits[HIGH] = 0x0;
  result.bits[MID] = 0x0;
  result.bits[LOW] = 0x6DF37F67;
  s21_decimal res1 = {0};
  s21_truncate(dec1, &res1);
  ck_assert_uint_eq(res1.bits[LOW], result.bits[LOW]);
  ck_assert_uint_eq(res1.bits[MID], result.bits[MID]);
  ck_assert_uint_eq(res1.bits[HIGH], result.bits[HIGH]);
  ck_assert_uint_eq(res1.bits[OLDER], result.bits[OLDER]);
}
END_TEST

START_TEST(s21_truncate_test_3) {
  s21_decimal dec1 = {0};

  dec1.bits[OLDER] = 0b10000000000011000000000000000000;
  dec1.bits[HIGH] = 0x0;
  dec1.bits[MID] = 0xFFFFFFFF;
  dec1.bits[LOW] = 0xFFFFFFFF;
  s21_decimal result = {0};
  result.bits[OLDER] = 0b10000000000000000000000000000000;
  result.bits[HIGH] = 0x0;
  result.bits[MID] = 0x0;
  result.bits[LOW] = 0x1197998;
  s21_decimal res1 = {0};
  s21_truncate(dec1, &res1);
  ck_assert_uint_eq(res1.bits[LOW], result.bits[LOW]);
  ck_assert_uint_eq(res1.bits[MID], result.bits[MID]);
  ck_assert_uint_eq(res1.bits[HIGH], result.bits[HIGH]);
  ck_assert_uint_eq(res1.bits[OLDER], result.bits[OLDER]);
}
END_TEST

START_TEST(s21_truncate_test_4) {
  s21_decimal dec1 = {0};

  dec1.bits[OLDER] = 0x80000000;
  dec1.bits[HIGH] = 0x0;
  dec1.bits[MID] = 0xFFFFFFFF;
  dec1.bits[LOW] = 0xFFFFFFFF;
  s21_decimal result = {0};
  result.bits[OLDER] = 0x80000000;
  result.bits[HIGH] = 0x0;
  result.bits[MID] = 0xFFFFFFFF;
  result.bits[LOW] = 0xFFFFFFFF;
  s21_decimal res1 = {0};
  s21_truncate(dec1, &res1);
  ck_assert_uint_eq(res1.bits[LOW], result.bits[LOW]);
  ck_assert_uint_eq(res1.bits[MID], result.bits[MID]);
  ck_assert_uint_eq(res1.bits[HIGH], result.bits[HIGH]);
  ck_assert_uint_eq(res1.bits[OLDER], result.bits[OLDER]);
}
END_TEST

START_TEST(s21_truncate_test_5) {
  s21_decimal dec1 = {0};

  dec1.bits[LOW] = 0b00000000000000000000000001101101;
  dec1.bits[MID] = 0b00000000000011000110010101011011;
  dec1.bits[HIGH] = 0b00000000000000000011000000111001;
  dec1.bits[OLDER] = 0b00000000000011100000000000000000;
  s21_decimal result = {0};
  result.bits[LOW] = 0b10000111101111000001011000011110;
  result.bits[MID] = 0b00000000000000000000000000000000;
  result.bits[HIGH] = 0b00000000000000000000000000000000;
  result.bits[OLDER] = 0b00000000000000000000000000000000;
  s21_decimal res1 = {0};
  s21_truncate(dec1, &res1);
  ck_assert_uint_eq(res1.bits[LOW], result.bits[LOW]);
  ck_assert_uint_eq(res1.bits[MID], result.bits[MID]);
  ck_assert_uint_eq(res1.bits[HIGH], result.bits[HIGH]);
  ck_assert_uint_eq(res1.bits[OLDER], result.bits[OLDER]);
}
END_TEST

START_TEST(s21_truncate_test_6) {
  s21_decimal dec1 = {0};

  dec1.bits[OLDER] = 0x80090000;
  dec1.bits[HIGH] = 0;
  dec1.bits[MID] = 0xFFFFEA34;
  dec1.bits[LOW] = 0xFF837E4F;
  s21_decimal result = {0};
  s21_truncate(dec1, &result);
  s21_decimal res1 = {0};

  res1.bits[OLDER] = 0x80000000;
  res1.bits[HIGH] = 0;
  res1.bits[MID] = 0x4;
  res1.bits[LOW] = 0x4B829C70;
  ck_assert_int_eq(res1.bits[OLDER], result.bits[OLDER]);
  ck_assert_int_eq(res1.bits[HIGH], result.bits[HIGH]);
  ck_assert_int_eq(res1.bits[MID], result.bits[MID]);
  ck_assert_int_eq(res1.bits[LOW], result.bits[LOW]);
}
END_TEST

START_TEST(s21_truncate_test_7) {
  s21_decimal dec1 = {0};

  dec1.bits[LOW] = 0b11010000101000110011000001101101;
  dec1.bits[MID] = 0b00011111100110100110101101011000;
  dec1.bits[HIGH] = 0;
  dec1.bits[OLDER] = 0b00000000000010010000000000000000;
  s21_decimal result = {0};
  s21_truncate(dec1, &result);
  s21_decimal result_origin;
  result_origin.bits[OLDER] = 0;
  result_origin.bits[HIGH] = 0;
  result_origin.bits[MID] = 0;
  result_origin.bits[LOW] = 0b10000111101111000001011000011110;
  ck_assert_int_eq(result_origin.bits[OLDER], result.bits[OLDER]);
  ck_assert_int_eq(result_origin.bits[HIGH], result.bits[HIGH]);
  ck_assert_int_eq(result_origin.bits[MID], result.bits[MID]);
  ck_assert_int_eq(result_origin.bits[LOW], result.bits[LOW]);
}
END_TEST

START_TEST(s21_truncate_test_8) {
  s21_decimal dec1 = {0};

  dec1.bits[LOW] = 0b01111000101001111011110011000110;
  dec1.bits[MID] = 0b10011111111111001111101010000100;
  dec1.bits[HIGH] = 0b00011111111010011010111101101101;
  dec1.bits[OLDER] = 0b00000000000111000000000000000000;
  s21_decimal result = {0};
  result.bits[LOW] = 0b00000000000000000000000000000000;
  result.bits[MID] = 0b00000000000000000000000000000000;
  result.bits[HIGH] = 0b00000000000000000000000000000000;
  result.bits[OLDER] = 0b00000000000000000000000000000000;
  s21_decimal res1 = {0};
  s21_truncate(dec1, &res1);
  ck_assert_uint_eq(res1.bits[LOW], result.bits[LOW]);
  ck_assert_uint_eq(res1.bits[MID], result.bits[MID]);
  ck_assert_uint_eq(res1.bits[HIGH], result.bits[HIGH]);
  ck_assert_uint_eq(res1.bits[OLDER], result.bits[OLDER]);
}
END_TEST

START_TEST(s21_truncate_test_9) {
  // 6766
  s21_decimal src1, origin;
  // src1 = 2;

  src1.bits[LOW] = 0b00000000000000000000000000000010;
  src1.bits[MID] = 0b00000000000000000000000000000000;
  src1.bits[HIGH] = 0b00000000000000000000000000000000;
  src1.bits[OLDER] = 0b00000000000000000000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_truncate(src1, &result);

  origin.bits[LOW] = 0b00000000000000000000000000000010;
  origin.bits[MID] = 0b00000000000000000000000000000000;
  origin.bits[HIGH] = 0b00000000000000000000000000000000;
  origin.bits[OLDER] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[OLDER], result.bits[OLDER]);
  ck_assert_int_eq(origin.bits[HIGH], result.bits[HIGH]);
  ck_assert_int_eq(origin.bits[MID], result.bits[MID]);
  ck_assert_int_eq(origin.bits[LOW], result.bits[LOW]);
}
END_TEST

START_TEST(s21_truncate_test_10) {
  // 6787
  s21_decimal src1, origin;
  // src1 = 3.5;

  src1.bits[LOW] = 0b00000000000000000000000000100011;
  src1.bits[MID] = 0b00000000000000000000000000000000;
  src1.bits[HIGH] = 0b00000000000000000000000000000000;
  src1.bits[OLDER] = 0b00000000000000010000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_truncate(src1, &result);

  origin.bits[LOW] = 0b00000000000000000000000000000011;
  origin.bits[MID] = 0b00000000000000000000000000000000;
  origin.bits[HIGH] = 0b00000000000000000000000000000000;
  origin.bits[OLDER] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[OLDER], result.bits[OLDER]);
  ck_assert_int_eq(origin.bits[HIGH], result.bits[HIGH]);
  ck_assert_int_eq(origin.bits[MID], result.bits[MID]);
  ck_assert_int_eq(origin.bits[LOW], result.bits[LOW]);
}
END_TEST

START_TEST(s21_truncate_test_11) {
  // 6808
  s21_decimal src1, origin;
  // src1 = 0;

  src1.bits[LOW] = 0b00000000000000000000000000000000;
  src1.bits[MID] = 0b00000000000000000000000000000000;
  src1.bits[HIGH] = 0b00000000000000000000000000000000;
  src1.bits[OLDER] = 0b00000000000000000000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_truncate(src1, &result);

  origin.bits[LOW] = 0b00000000000000000000000000000000;
  origin.bits[MID] = 0b00000000000000000000000000000000;
  origin.bits[HIGH] = 0b00000000000000000000000000000000;
  origin.bits[OLDER] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[OLDER], result.bits[OLDER]);
  ck_assert_int_eq(origin.bits[HIGH], result.bits[HIGH]);
  ck_assert_int_eq(origin.bits[MID], result.bits[MID]);
  ck_assert_int_eq(origin.bits[LOW], result.bits[LOW]);
}
END_TEST

START_TEST(s21_truncate_test_12) {
  // 6829
  s21_decimal src1, origin;
  // src1 = 0;

  src1.bits[LOW] = 0b00000000000000000000000000000000;
  src1.bits[MID] = 0b00000000000000000000000000000000;
  src1.bits[HIGH] = 0b00000000000000000000000000000000;
  src1.bits[OLDER] = 0b00000000000000000000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_truncate(src1, &result);

  origin.bits[LOW] = 0b00000000000000000000000000000000;
  origin.bits[MID] = 0b00000000000000000000000000000000;
  origin.bits[HIGH] = 0b00000000000000000000000000000000;
  origin.bits[OLDER] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[OLDER], result.bits[OLDER]);
  ck_assert_int_eq(origin.bits[HIGH], result.bits[HIGH]);
  ck_assert_int_eq(origin.bits[MID], result.bits[MID]);
  ck_assert_int_eq(origin.bits[LOW], result.bits[LOW]);
}
END_TEST

START_TEST(s21_truncate_test_13) {
  // 6850
  s21_decimal src1, origin;
  // src1 = -9878798789;

  src1.bits[LOW] = 0b01001100110100101000000111000101;
  src1.bits[MID] = 0b00000000000000000000000000000010;
  src1.bits[HIGH] = 0b00000000000000000000000000000000;
  src1.bits[OLDER] = 0b10000000000000000000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_truncate(src1, &result);

  origin.bits[LOW] = 0b01001100110100101000000111000101;
  origin.bits[MID] = 0b00000000000000000000000000000010;
  origin.bits[HIGH] = 0b00000000000000000000000000000000;
  origin.bits[OLDER] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[OLDER], result.bits[OLDER]);
  ck_assert_int_eq(origin.bits[HIGH], result.bits[HIGH]);
  ck_assert_int_eq(origin.bits[MID], result.bits[MID]);
  ck_assert_int_eq(origin.bits[LOW], result.bits[LOW]);
}
END_TEST

START_TEST(s21_truncate_test_14) {
  // 6871
  s21_decimal src1, origin;
  // src1 = -545454512454545.35265454545645;

  src1.bits[LOW] = 0b10000010111000100101101011101101;
  src1.bits[MID] = 0b11111001111010000010010110101101;
  src1.bits[HIGH] = 0b10110000001111101111000010010100;
  src1.bits[OLDER] = 0b10000000000011100000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_truncate(src1, &result);

  origin.bits[LOW] = 0b10000110011101001011101110010001;
  origin.bits[MID] = 0b00000000000000011111000000010110;
  origin.bits[HIGH] = 0b00000000000000000000000000000000;
  origin.bits[OLDER] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[OLDER], result.bits[OLDER]);
  ck_assert_int_eq(origin.bits[HIGH], result.bits[HIGH]);
  ck_assert_int_eq(origin.bits[MID], result.bits[MID]);
  ck_assert_int_eq(origin.bits[LOW], result.bits[LOW]);
}
END_TEST

START_TEST(s21_truncate_test_15) {
  // 6892
  s21_decimal src1, origin;
  // src1 = -5.492654545456454545645464;

  src1.bits[LOW] = 0b00000111100110110001111110011000;
  src1.bits[MID] = 0b01100110010010001001000110100011;
  src1.bits[HIGH] = 0b00000000000001001000101100011101;
  src1.bits[OLDER] = 0b10000000000110000000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_truncate(src1, &result);

  origin.bits[LOW] = 0b00000000000000000000000000000101;
  origin.bits[MID] = 0b00000000000000000000000000000000;
  origin.bits[HIGH] = 0b00000000000000000000000000000000;
  origin.bits[OLDER] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[OLDER], result.bits[OLDER]);
  ck_assert_int_eq(origin.bits[HIGH], result.bits[HIGH]);
  ck_assert_int_eq(origin.bits[MID], result.bits[MID]);
  ck_assert_int_eq(origin.bits[LOW], result.bits[LOW]);
}
END_TEST

START_TEST(s21_truncate_test_16) {
  // 6913
  s21_decimal src1, origin;
  // src1 = 7961327845421.879754123131254;

  src1.bits[LOW] = 0b01001110111001000011100101110110;
  src1.bits[MID] = 0b01001011001101011010000111011001;
  src1.bits[HIGH] = 0b00011001101110010111010010111111;
  src1.bits[OLDER] = 0b00000000000011110000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_truncate(src1, &result);

  origin.bits[LOW] = 0b10100100000111100100000000101101;
  origin.bits[MID] = 0b00000000000000000000011100111101;
  origin.bits[HIGH] = 0b00000000000000000000000000000000;
  origin.bits[OLDER] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[OLDER], result.bits[OLDER]);
  ck_assert_int_eq(origin.bits[HIGH], result.bits[HIGH]);
  ck_assert_int_eq(origin.bits[MID], result.bits[MID]);
  ck_assert_int_eq(origin.bits[LOW], result.bits[LOW]);
}
END_TEST

START_TEST(s21_truncate_test_17) {
  // 6934
  s21_decimal src1, origin;
  // src1 = -12345677.187654345678987654346;

  src1.bits[LOW] = 0b01111000100010101111010011001010;
  src1.bits[MID] = 0b01100010000010101110010010000111;
  src1.bits[HIGH] = 0b00100111111001000001101011010101;
  src1.bits[OLDER] = 0b10000000000101010000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_truncate(src1, &result);

  origin.bits[LOW] = 0b00000000101111000110000101001101;
  origin.bits[MID] = 0b00000000000000000000000000000000;
  origin.bits[HIGH] = 0b00000000000000000000000000000000;
  origin.bits[OLDER] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[OLDER], result.bits[OLDER]);
  ck_assert_int_eq(origin.bits[HIGH], result.bits[HIGH]);
  ck_assert_int_eq(origin.bits[MID], result.bits[MID]);
  ck_assert_int_eq(origin.bits[LOW], result.bits[LOW]);
}
END_TEST

START_TEST(s21_truncate_test_18) {
  // 6955
  s21_decimal src1, origin;
  // src1 = 2.5086531268974139743;

  src1.bits[LOW] = 0b01100101111011101101100101011111;
  src1.bits[MID] = 0b01011100001001010100001101000110;
  src1.bits[HIGH] = 0b00000000000000000000000000000001;
  src1.bits[OLDER] = 0b00000000000100110000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_truncate(src1, &result);

  origin.bits[LOW] = 0b00000000000000000000000000000010;
  origin.bits[MID] = 0b00000000000000000000000000000000;
  origin.bits[HIGH] = 0b00000000000000000000000000000000;
  origin.bits[OLDER] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[OLDER], result.bits[OLDER]);
  ck_assert_int_eq(origin.bits[HIGH], result.bits[HIGH]);
  ck_assert_int_eq(origin.bits[MID], result.bits[MID]);
  ck_assert_int_eq(origin.bits[LOW], result.bits[LOW]);
}
END_TEST

START_TEST(s21_truncate_test_19) {
  // 6976
  s21_decimal src1, origin;
  // src1 = 1;

  src1.bits[LOW] = 0b00000000000000000000000000000001;
  src1.bits[MID] = 0b00000000000000000000000000000000;
  src1.bits[HIGH] = 0b00000000000000000000000000000000;
  src1.bits[OLDER] = 0b00000000000000000000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_truncate(src1, &result);

  origin.bits[LOW] = 0b00000000000000000000000000000001;
  origin.bits[MID] = 0b00000000000000000000000000000000;
  origin.bits[HIGH] = 0b00000000000000000000000000000000;
  origin.bits[OLDER] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[OLDER], result.bits[OLDER]);
  ck_assert_int_eq(origin.bits[HIGH], result.bits[HIGH]);
  ck_assert_int_eq(origin.bits[MID], result.bits[MID]);
  ck_assert_int_eq(origin.bits[LOW], result.bits[LOW]);
}
END_TEST

START_TEST(s21_truncate_test_20) {
  static s21_decimal arr[] = {
      {{0x00000000, 0x00000000, 0x00000000, 0x00000000}},  // 0
      {{0x00000001, 0x00000000, 0x00000000, 0x00000000}},  // 1
      {{0x00000001, 0x00000000, 0x00000000, 0x80000000}},  // -1
      {{0xCF5C048C, 0x004D2BEF, 0x00000000, 0x00070000}},  // 2172188218.2812812
      {{0xFEADBDA2, 0x000001FB, 0x00000000, 0x80060000}},  // -2181821.218210
      {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
        0x00000000}},  // 79228162514264337593543950335
      {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
        0x80000000}},  // -79228162514264337593543950335
      {{0x00000000, 0x00000000, 0x00000000, 0x00020000}},  // 0.00
      {{0x000F4240, 0x00000000, 0x00000000, 0x00020000}},  // 10000.00
      {{0x000F4240, 0x00000000, 0x00000000, 0x80020000}},  // -10000.00
      {{0x00000467, 0x0000007A, 0x00000000, 0x00040000}},  // 52398601.1239
      {{0x00000467, 0x0000007A, 0x00000000, 0x80000000}},  // -523986011239
      {{0x00000467, 0x0000007A, 0x00003215,
        0x00010000}},  // 23650570576955414727997.5
      {{0x00000467, 0x0000007A, 0x00205FF0,
        0x80020000}},  // -391386782621189641642978.31
      {{0x000F4240, 0x00002710, 0x00002710,
        0x80050000}},  // -1844674407800451901.20000
      {{0x0000000E, 0x00000000, 0x00000000, 0x00000000}},  // 14
      {{0x0000000F, 0x00000000, 0x00000000, 0x80000000}},  // -15
      {{0x000186A0, 0x00000000, 0x00000000, 0x00000000}},  // 100000
      {{0x0000000B, 0x00000000, 0x00000000, 0x00010000}},  // 1.1
      {{0x0000000B, 0x00000000, 0x00000000, 0x80010000}},  // -1.1
      {{0x0000000F, 0x00000000, 0x00000000, 0x80010000}},  // -1.5
      {{0x0000000F, 0x00000000, 0x00000000, 0x00010000}},  // 1.5
      {{0x00000086, 0x00000000, 0x00000000, 0x80020000}},  // -1.34
      {{0x00000086, 0x00000000, 0x00000000, 0x00020000}},  // 1.34
      {{0x000006E5, 0x00000000, 0x00000000, 0x00030000}},  // 1.765
      {{0x000006E5, 0x00000000, 0x00000000, 0x80030000}},  // -1.765
      {{0x00000019, 0x00000000, 0x00000000, 0x00010000}},  // 2.5
      {{0x00000019, 0x00000000, 0x00000000, 0x80010000}},  // -2.5
      {{0x1FC40A5F, 0xA98FD4BE, 0x00000000,
        0x00020000}},  // 122182182271212611.51
      {{0x1FC40A5D, 0xA98FD4BE, 0x00000000,
        0x00020000}},  // 122182182271212611.49
      {{0x1FC40A5F, 0xA98FD4BE, 0x00000000,
        0x80020000}},  // -122182182271212611.51
      {{0x1FC40A5D, 0xA98FD4BE, 0x00000000,
        0x80020000}},  // -122182182271212611.49
      {{0x075BCD15, 0x00000000, 0x00000000, 0x00030000}},  // 123456.789
      {{0x075BCD15, 0x00000000, 0x00000000, 0x00090000}},  // 0.123456789
      {{0x075BCD15, 0x00000000, 0x00000000,
        0x00120000}},  // 0.000000000123456789
      {{0x075BCD15, 0x00000000, 0x00000000,
        0x001B0000}},  // 0.000000000000000000123456789
      {{0xFFFFFFFF, 0x00000000, 0x00000000, 0x00060000}},  // 4294.967295
      {{0xFFFFFFFF, 0xFFFFFFFF, 0x00000000,
        0x00050000}},  // 184467440737095.51615
      {{0xFFFFFFFF, 0x00000000, 0x00000000, 0x80060000}},  // -4294.967295
      {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
        0x001C0000}},  // 7.9228162514264337593543950335
      {{0xFFFFFFFF, 0xFFFFFFFF, 0x00000000,
        0x80050000}},  // -184467440737095.51615
      {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
        0x801C0000}},  // -7.9228162514264337593543950335
  };

  static s21_decimal result[] = {
      {{0x00000000, 0x00000000, 0x00000000, 0x00000000}},  // 0
      {{0x00000001, 0x00000000, 0x00000000, 0x00000000}},  // 1
      {{0x00000001, 0x00000000, 0x00000000, 0x80000000}},  //-1
      {{0x8178F63A, 0x00000000, 0x00000000, 0x00000000}},  // 2172188218
      {{0x00214ABD, 0x00000000, 0x00000000, 0x80000000}},  //-2181821
      {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
        0x00000000}},  // 79228162514264337593543950335
      {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
        0x80000000}},  //-79228162514264337593543950335
      {{0x00000000, 0x00000000, 0x00000000, 0x00000000}},  // 0
      {{0x00002710, 0x00000000, 0x00000000, 0x00000000}},  // 10000
      {{0x00002710, 0x00000000, 0x00000000, 0x80000000}},  //-10000
      {{0x031F8A09, 0x00000000, 0x00000000, 0x00000000}},  // 52398601
      {{0x00000467, 0x0000007A, 0x00000000, 0x80000000}},  //-523986011239
      {{0xCCCCCD3D, 0x199999A5, 0x00000502,
        0x00000000}},  // 23650570576955414727997
      {{0xBD70A3E2, 0x1EB851EC, 0x000052E1,
        0x80000000}},  //-391386782621189641642978
      {{0xB333333D, 0x19999999, 0x00000000, 0x80000000}},
      //-1844674407800451901
      {{0x0000000E, 0x00000000, 0x00000000, 0x00000000}},  // 14
      {{0x0000000F, 0x00000000, 0x00000000, 0x80000000}},  //-15
      {{0x000186A0, 0x00000000, 0x00000000, 0x00000000}},  // 100000
      {{0x00000001, 0x00000000, 0x00000000, 0x00000000}},  // 1
      {{0x00000001, 0x00000000, 0x00000000, 0x80000000}},  //-1
      {{0x00000001, 0x00000000, 0x00000000, 0x80000000}},  //-1
      {{0x00000001, 0x00000000, 0x00000000, 0x00000000}},  // 1
      {{0x00000001, 0x00000000, 0x00000000, 0x80000000}},  //-1
      {{0x00000001, 0x00000000, 0x00000000, 0x00000000}},  // 1
      {{0x00000001, 0x00000000, 0x00000000, 0x00000000}},  // 1
      {{0x00000001, 0x00000000, 0x00000000, 0x80000000}},  //-1
      {{0x00000002, 0x00000000, 0x00000000, 0x00000000}},  // 2
      {{0x00000002, 0x00000000, 0x00000000, 0x80000000}},  //-2
      {{0x24285C43, 0x01B2140C, 0x00000000, 0x00000000}},  // 122182182271212611
      {{0x24285C43, 0x01B2140C, 0x00000000, 0x00000000}},  // 122182182271212611
      {{0x24285C43, 0x01B2140C, 0x00000000, 0x80000000}},  //-122182182271212611
      {{0x24285C43, 0x01B2140C, 0x00000000, 0x80000000}},  //-122182182271212611
      {{0x0001E240, 0x00000000, 0x00000000, 0x00000000}},  // 123456
      {{0x00000000, 0x00000000, 0x00000000, 0x00000000}},  // 0
      {{0x00000000, 0x00000000, 0x00000000, 0x00000000}},  // 0
      {{0x00000000, 0x00000000, 0x00000000, 0x00000000}},  // 0
      {{0x000010C6, 0x00000000, 0x00000000, 0x00000000}},  // 4294
      {{0xAC471B47, 0x0000A7C5, 0x00000000, 0x00000000}},  // 184467440737095
      {{0x000010C6, 0x00000000, 0x00000000, 0x80000000}},  //-4294
      {{0x00000007, 0x00000000, 0x00000000, 0x00000000}},  // 7
      {{0xAC471B47, 0x0000A7C5, 0x00000000, 0x80000000}},  //-184467440737095
      {{0x00000007, 0x00000000, 0x00000000, 0x80000000}},  //-7
  };

  for (size_t i = 0; i < sizeof(arr) / sizeof(s21_decimal); ++i) {
    s21_decimal tmp;
    int ret = s21_truncate(arr[i], &tmp);
    ck_assert_int_eq(tmp.bits[LOW], result[i].bits[LOW]);
    ck_assert_int_eq(tmp.bits[MID], result[i].bits[MID]);
    ck_assert_int_eq(tmp.bits[HIGH], result[i].bits[HIGH]);
    ck_assert_int_eq(tmp.bits[OLDER], result[i].bits[OLDER]);
    ck_assert_int_eq(ret, 0);
  }
}
END_TEST

Suite *s21_truncate_suite_create() {
  Suite *suite = suite_create("s21_truncate_test");
  TCase *tc_core = tcase_create("tcase_core_s21_truncate_test");

  tcase_add_test(tc_core, s21_truncate_test_1);
  tcase_add_test(tc_core, s21_truncate_test_2);
  tcase_add_test(tc_core, s21_truncate_test_3);
  tcase_add_test(tc_core, s21_truncate_test_4);
  tcase_add_test(tc_core, s21_truncate_test_5);
  tcase_add_test(tc_core, s21_truncate_test_6);
  tcase_add_test(tc_core, s21_truncate_test_7);
  tcase_add_test(tc_core, s21_truncate_test_8);
  tcase_add_test(tc_core, s21_truncate_test_9);
  tcase_add_test(tc_core, s21_truncate_test_10);
  tcase_add_test(tc_core, s21_truncate_test_11);
  tcase_add_test(tc_core, s21_truncate_test_12);
  tcase_add_test(tc_core, s21_truncate_test_13);
  tcase_add_test(tc_core, s21_truncate_test_14);
  tcase_add_test(tc_core, s21_truncate_test_15);
  tcase_add_test(tc_core, s21_truncate_test_16);
  tcase_add_test(tc_core, s21_truncate_test_17);
  tcase_add_test(tc_core, s21_truncate_test_18);
  tcase_add_test(tc_core, s21_truncate_test_19);
  tcase_add_test(tc_core, s21_truncate_test_20);

  suite_add_tcase(suite, tc_core);

  return suite;
}

int main() {
  int failed_count = 0;

  Suite *suite = s21_truncate_suite_create();
  SRunner *suite_runner = srunner_create(suite);

  srunner_run_all(suite_runner, CK_NORMAL);
  failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);

  return failed_count != 0 && !SHOW_FAILED ? EXIT_FAILURE : EXIT_SUCCESS;
}
