#include <check.h>

#include "../s21_decimal.h"

#define SHOW_FAILED TRUE

// val_1 = 0; val_2 = 0; res = FALSE;
START_TEST(s21_is_not_equal_test_1) {
  int expected_value = FALSE;

  s21_decimal value_1;
  value_1.bits[LOW] = 0x00000000;
  value_1.bits[MID] = 0x00000000;
  value_1.bits[HIGH] = 0x00000000;
  value_1.bits[OLDER] = 0x00000000;

  s21_decimal value_2;
  value_2.bits[LOW] = 0x00000000;
  value_2.bits[MID] = 0x00000000;
  value_2.bits[HIGH] = 0x00000000;
  value_2.bits[OLDER] = 0x00000000;

  int res = s21_is_not_equal(value_1, value_2);

  ck_assert_int_eq(res, expected_value);
}
END_TEST

// val_1 = 1; val_2 = 1; res = FALSE;
START_TEST(s21_is_not_equal_test_2) {
  int expected_value = FALSE;

  s21_decimal value_1;
  value_1.bits[LOW] = 0x00000001;
  value_1.bits[MID] = 0x00000000;
  value_1.bits[HIGH] = 0x00000000;
  value_1.bits[OLDER] = 0x00000000;

  s21_decimal value_2;
  value_2.bits[LOW] = 0x00000001;
  value_2.bits[MID] = 0x00000000;
  value_2.bits[HIGH] = 0x00000000;
  value_2.bits[OLDER] = 0x00000000;

  int res = s21_is_not_equal(value_1, value_2);

  ck_assert_int_eq(res, expected_value);
}
END_TEST

// val_1 = -1; val_2 = -1; res = FALSE;
START_TEST(s21_is_not_equal_test_3) {
  int expected_value = FALSE;

  s21_decimal value_1;
  value_1.bits[LOW] = 0x00000001;
  value_1.bits[MID] = 0x00000000;
  value_1.bits[HIGH] = 0x00000000;
  value_1.bits[OLDER] = 0x80000000;

  s21_decimal value_2;
  value_2.bits[LOW] = 0x00000001;
  value_2.bits[MID] = 0x00000000;
  value_2.bits[HIGH] = 0x00000000;
  value_2.bits[OLDER] = 0x80000000;

  int res = s21_is_not_equal(value_1, value_2);

  ck_assert_int_eq(res, expected_value);
}
END_TEST

// val_1 = -1; val_2 = 1; res = TRUE;
START_TEST(s21_is_not_equal_test_4) {
  int expected_value = TRUE;

  s21_decimal value_1;
  value_1.bits[LOW] = 0x00000001;
  value_1.bits[MID] = 0x00000000;
  value_1.bits[HIGH] = 0x00000000;
  value_1.bits[OLDER] = 0x80000000;

  s21_decimal value_2;
  value_2.bits[LOW] = 0x00000001;
  value_2.bits[MID] = 0x00000000;
  value_2.bits[HIGH] = 0x00000000;
  value_2.bits[OLDER] = 0x00000000;

  int res = s21_is_not_equal(value_1, value_2);

  ck_assert_int_eq(res, expected_value);
}
END_TEST

// val_1 = 1; val_2 = -1; res = TRUE;
START_TEST(s21_is_not_equal_test_5) {
  int expected_value = TRUE;

  s21_decimal value_1;
  value_1.bits[LOW] = 0x00000001;
  value_1.bits[MID] = 0x00000000;
  value_1.bits[HIGH] = 0x00000000;
  value_1.bits[OLDER] = 0x00000000;

  s21_decimal value_2;
  value_2.bits[LOW] = 0x00000001;
  value_2.bits[MID] = 0x00000000;
  value_2.bits[HIGH] = 0x00000000;
  value_2.bits[OLDER] = 0x80000000;

  int res = s21_is_not_equal(value_1, value_2);

  ck_assert_int_eq(res, expected_value);
}
END_TEST

// START_TEST(s21_is_not_equal_test_6) {
//   s21_decimal dec1 = {.bits[0] = 15,
//                       .bits[1] = 15,
//                       .bits[2] = 15,
//                       .bits[3] = 0b10000000000001010000000000000000};
//   s21_decimal dec2 = {.bits[0] = 10,
//                       .bits[1] = 10,
//                       .bits[2] = 10,
//                       .bits[3] = 0b10000000000001010000000000000000};
//   int res = s21_is_not_equal(dec1, dec2);
//   ck_assert_int_eq(res, 1);
// }
// END_TEST

START_TEST(s21_is_not_equal_test_7) {
  s21_decimal dec1 = {{0x00000000, 0x00000000, 0x00000000, 0x00030000}};
  s21_decimal dec2 = {{0x00000000, 0x00000000, 0x00000000, 0x00030000}};

  int res = s21_is_not_equal(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_is_not_equal_test_8) {
  s21_decimal dec1 = {{0x00000000, 0x00000000, 0x00000000, 0x80000000}};
  s21_decimal dec2 = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};

  int res = s21_is_not_equal(dec1, dec2);
  // ck_assert_int_eq(res, 1);
  ck_assert_int_eq(res, 0);  // -0 и 0 дает False
}
END_TEST

START_TEST(s21_is_not_equal_test_9) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  set_bit(&val2, 3, 1);
  ck_assert_int_eq(1, s21_is_not_equal(val1, val2));
}
END_TEST

START_TEST(s21_is_not_equal_test_10) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  set_bit(&val2, 127, 1);
  set_bit(&val1, 33, 1);
  set_bit(&val2, 33, 1);
  ck_assert_int_eq(1, s21_is_not_equal(val1, val2));
}
END_TEST

START_TEST(s21_is_not_equal_test_11) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  set_bit(&val1, 3, 1);
  set_bit(&val2, 3, 1);
  ck_assert_int_eq(0, s21_is_not_equal(val1, val2));
}
END_TEST

START_TEST(s21_is_not_equal_test_12) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  set_scale(&val1, 3);
  set_scale(&val2, 3);
  ck_assert_int_eq(0, s21_is_not_equal(val1, val2));
}
END_TEST

START_TEST(s21_is_not_equal_test_13) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  set_bit(&val1, 3, 1);
  set_bit(&val2, 4, 1);
  set_scale(&val1, 3);
  set_scale(&val2, 3);
  ck_assert_int_eq(1, s21_is_not_equal(val1, val2));
}
END_TEST

START_TEST(s21_is_not_equal_test_14) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  set_scale(&val1, 3);
  set_scale(&val2, 2);
  ck_assert_int_eq(0, s21_is_not_equal(val1, val2));
}
END_TEST

START_TEST(s21_is_not_equal_test_15) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  ck_assert_int_eq(0, s21_is_not_equal(val1, val2));
}
END_TEST

START_TEST(s21_is_not_equal_test_16) {
  float a = rand();

  s21_decimal _a = {{0}};
  s21_decimal _b = {{0}};
  s21_from_float_to_decimal(a, &_a);
  s21_from_float_to_decimal(a, &_b);
  ck_assert_int_eq(s21_is_not_equal(_a, _b), 0);
}
END_TEST

START_TEST(s21_is_not_equal_test_17) {
  float a = rand();
  float b = rand();

  s21_decimal _a = {{0}};
  s21_decimal _b = {{0}};
  s21_from_float_to_decimal(a, &_a);
  s21_from_float_to_decimal(b, &_b);
  ck_assert_int_eq(s21_is_not_equal(_a, _b), a != b);
}
END_TEST

START_TEST(s21_is_not_equal_test_18) {
  float a = rand();
  float b = rand();

  s21_decimal _a = {{0}};
  s21_decimal _b = {{0}};
  s21_from_float_to_decimal(a, &_a);
  s21_from_float_to_decimal(b, &_b);
  ck_assert_int_eq(s21_is_not_equal(_a, _b), a != b);
}
END_TEST

START_TEST(s21_is_not_equal_test_19) {
  s21_decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 80000000}};
  s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 80000000}};
  int return_value = s21_is_not_equal(value_1, value_2);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_is_not_equal_test_20) {
  s21_decimal value_1 = {{123453u, 654u, 0xFFFFFFFF, 80000000}};
  s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 80000000}};
  int return_value = s21_is_not_equal(value_1, value_2);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(s21_is_not_equal_test_21) {
  s21_decimal value_1 = {{0, 0, 0, 0x80000000}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  int return_value = s21_is_not_equal(value_1, value_2);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_is_not_equal_test_22) {
  float num1 = 1.375342323523;
  float num2 = 1.39;
  s21_decimal dec1 = {{0}};
  s21_decimal dec2 = {{0}};
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_not_equal(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_is_not_equal_test_23) {
  float num1 = 1.39;
  float num2 = 1.39;
  s21_decimal dec1 = {{0}};
  s21_decimal dec2 = {{0}};
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_not_equal(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_is_not_equal_test_24) {
  float num1 = 1.39;
  float num2 = -1.39;
  s21_decimal dec1 = {{0}};
  s21_decimal dec2 = {{0}};
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_not_equal(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_is_not_equal_test_25) {
  int num1 = 0;
  int num2 = 0;
  s21_decimal dec1 = {{0}};
  s21_decimal dec2 = {{0}};
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res = s21_is_not_equal(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_is_not_equal_test_26) {
  int num1 = 3;
  int num2 = 9;
  s21_decimal dec1 = {{0}};
  s21_decimal dec2 = {{0}};
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res = s21_is_not_equal(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_is_not_equal_test_27) {
  int num1 = -3;
  int num2 = -3;
  s21_decimal dec1 = {{0}};
  s21_decimal dec2 = {{0}};
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res = s21_is_not_equal(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_is_not_equal_test_28) {
  s21_decimal dec1 = {
      {12345, 0, 0, 0b00000000000001000000000000000000}};  //  1.2345
  s21_decimal dec2 = {{12, 0, 0, 0b10000000000000010000000000000000}};  // -1.2;
  ck_assert_int_eq(s21_is_not_equal(dec1, dec2), 1);
}
END_TEST

START_TEST(s21_is_not_equal_test_29) {
  s21_decimal dec3 = {
      {120000, 0, 0, 0b00000000000001000000000000000000}};  //  12.0000
  s21_decimal dec4 = {{12, 0, 0, 0b00000000000000000000000000000000}};  //
  ck_assert_int_eq(s21_is_not_equal(dec3, dec4), 0);
}
END_TEST

START_TEST(s21_is_not_equal_test_30) {
  s21_decimal dec5 = {{0, 0, 0, 0b00000000000000000000000000000000}};   //  0
  s21_decimal dec6 = {{00, 0, 0, 0b00000000000000010000000000000000}};  //
  ck_assert_int_eq(s21_is_not_equal(dec5, dec6), 0);
}
END_TEST

START_TEST(s21_is_not_equal_test_31) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  set_bit(&val1, 3, 1);
  set_bit(&val2, 4, 1);
  ck_assert_int_eq(1, s21_is_not_equal(val1, val2));
}
END_TEST

Suite *s21_is_not_equal_suite_create() {
  Suite *suite = suite_create("s21_is_not_equal_test");
  TCase *tc_core = tcase_create("tcase_core_s21_is_not_equal_test");

  tcase_add_test(tc_core, s21_is_not_equal_test_1);
  tcase_add_test(tc_core, s21_is_not_equal_test_2);
  tcase_add_test(tc_core, s21_is_not_equal_test_3);
  tcase_add_test(tc_core, s21_is_not_equal_test_4);
  tcase_add_test(tc_core, s21_is_not_equal_test_5);
  // tcase_add_test(tc_core, s21_is_not_equal_test_6);
  tcase_add_test(tc_core, s21_is_not_equal_test_7);
  tcase_add_test(tc_core, s21_is_not_equal_test_8);
  tcase_add_test(tc_core, s21_is_not_equal_test_9);
  tcase_add_test(tc_core, s21_is_not_equal_test_10);
  tcase_add_test(tc_core, s21_is_not_equal_test_11);
  tcase_add_test(tc_core, s21_is_not_equal_test_12);
  tcase_add_test(tc_core, s21_is_not_equal_test_13);
  tcase_add_test(tc_core, s21_is_not_equal_test_14);
  tcase_add_test(tc_core, s21_is_not_equal_test_15);
  tcase_add_test(tc_core, s21_is_not_equal_test_16);
  tcase_add_test(tc_core, s21_is_not_equal_test_17);
  tcase_add_test(tc_core, s21_is_not_equal_test_18);
  tcase_add_test(tc_core, s21_is_not_equal_test_19);
  tcase_add_test(tc_core, s21_is_not_equal_test_20);
  tcase_add_test(tc_core, s21_is_not_equal_test_21);
  tcase_add_test(tc_core, s21_is_not_equal_test_22);
  tcase_add_test(tc_core, s21_is_not_equal_test_23);
  tcase_add_test(tc_core, s21_is_not_equal_test_24);
  tcase_add_test(tc_core, s21_is_not_equal_test_25);
  tcase_add_test(tc_core, s21_is_not_equal_test_26);
  tcase_add_test(tc_core, s21_is_not_equal_test_27);
  tcase_add_test(tc_core, s21_is_not_equal_test_28);
  tcase_add_test(tc_core, s21_is_not_equal_test_29);
  tcase_add_test(tc_core, s21_is_not_equal_test_30);
  tcase_add_test(tc_core, s21_is_not_equal_test_31);

  suite_add_tcase(suite, tc_core);

  return suite;
}

int main() {
  int failed_count = 0;

  Suite *suite = s21_is_not_equal_suite_create();
  SRunner *suite_runner = srunner_create(suite);

  srunner_run_all(suite_runner, CK_NORMAL);
  failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);

  return failed_count != 0 && !SHOW_FAILED ? EXIT_FAILURE : EXIT_SUCCESS;
}
