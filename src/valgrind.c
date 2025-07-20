#include "s21_decimal.h"

int main() {
  // s21_from_decimal_to_float

  {
    s21_decimal val = {{123456789, 0, 0, 0}};
    set_scale(&val, 5);
    float res = 1234.56789;
    float tmp = 0.;
    float *dst = &tmp;

    s21_from_decimal_to_float(val, dst);

    printf("from_float_to_decimal: %f\n", res);
  }

  {
    s21_decimal val = {{123456789, 0, 0, 0}};
    set_scale(&val, 5);
    set_sign(&val, MINUS);
    float res = -1234.56789;
    float tmp = 0.;
    float *dst = &tmp;

    s21_from_decimal_to_float(val, dst);

    float ret = 0.0;
    s21_from_decimal_to_float(val, &ret);

    printf("from_float_to_decimal: %f\n", res);
  }

  {
    s21_decimal var = {{0, 0, 0, 0}};
    float value = 0;

    s21_from_float_to_decimal(5.0, &var);
    s21_from_decimal_to_float(var, &value);
  }

  {
    float n = rand();
    s21_decimal var = {{0, 0, 0, 0}};
    float value = 0;

    s21_from_float_to_decimal(n, &var);
    s21_from_decimal_to_float(var, &value);
  }

  {
    float n = rand();
    s21_decimal var = {{0, 0, 0, 0}};
    float value = 0;

    s21_from_float_to_decimal(n, &var);
    s21_from_decimal_to_float(var, &value);
  }

  {
    s21_decimal var = {0};
    float value = 0;

    s21_from_float_to_decimal(5.0, &var);
    s21_from_decimal_to_float(var, &value);
  }

  {
    float n = rand();
    s21_decimal var = {0};
    float value = 0;

    s21_from_float_to_decimal(n, &var);
    s21_from_decimal_to_float(var, &value);
  }

  {
    float n = rand();
    s21_decimal var = {0};
    float value = 0;

    s21_from_float_to_decimal(n, &var);
    s21_from_decimal_to_float(var, &value);
  }

  {
    s21_decimal value = {{1812, 0, 0, 0}};
    set_sign(&value, MINUS);
    float result = 0;
    int return_value = s21_from_decimal_to_float(value, &result);

    printf("from_float_to_decimal: %d\n", return_value);
  }

  {
    s21_decimal value = {{18122, 0, 0, 0}};
    set_scale(&value, 3);
    set_sign(&value, MINUS);
    float result = 0;
    int return_value = s21_from_decimal_to_float(value, &result);

    printf("from_float_to_decimal: %d\n", return_value);
  }

  {
    s21_decimal value = {{0xFFFFFF, 0, 0, 0}};
    float result = 0;
    int return_value = s21_from_decimal_to_float(value, &result);

    printf("from_float_to_decimal: %d\n", return_value);
  }

  {
    s21_decimal value = {{0xFFFFFFFF, 0xFFFFFFFF, 0, 0}};
    float result = 0;
    int return_value = s21_from_decimal_to_float(value, &result);

    printf("from_float_to_decimal: %d\n", return_value);
  }

  {
    s21_decimal src = {0};
    int result = 0;
    float number = 0.0;
    src.bits[LOW] = 23450987;
    src.bits[MID] = 0;
    src.bits[HIGH] = 0;
    src.bits[OLDER] = 2147745792;
    result = s21_from_decimal_to_float(src, &number);

    printf("from_float_to_decimal: %d\n", result);
  }

  // s21_from_float_to_decimal

  {
    float f = -7648904.0;
    s21_decimal value;

    int s21_ret = s21_from_float_to_decimal(f, &value);
    printf("from_decimal_to_float: %d\n", s21_ret);
  }

  {
    float f = 1234567.0;
    s21_decimal value;

    int s21_ret = s21_from_float_to_decimal(f, &value);
    printf("from_decimal_to_float: %d\n", s21_ret);
  }

  {
    float f = -1234567.0;
    s21_decimal value;

    int s21_ret = s21_from_float_to_decimal(f, &value);
    printf("from_decimal_to_float: %d\n", s21_ret);
  }

  {
    float f = 1.568993E-19;
    s21_decimal value;

    int s21_ret = s21_from_float_to_decimal(f, &value);
    printf("from_decimal_to_float: %d\n", s21_ret);
  }

  {
    float a = 123456789012345678901234567.8;
    int func_error = 0;
    s21_decimal dec = {0};
    func_error = s21_from_float_to_decimal(a, &dec);
    printf("from_decimal_to_float: %d\n", func_error);
  }

  {
    float a = 12345678901234567890123456.78;
    int func_error = 0;
    s21_decimal dec = {0};
    func_error = s21_from_float_to_decimal(a, &dec);
    printf("from_decimal_to_float: %d\n", func_error);
  }

  {
    float a = 1234567890123456789012345.678;
    int func_error = 0;
    s21_decimal dec = {0};
    func_error = s21_from_float_to_decimal(a, &dec);
    printf("from_decimal_to_float: %d\n", func_error);
  }

  {
    float a = 123456789012345678901234.5678;
    int func_error = 0;
    s21_decimal dec = {0};
    func_error = s21_from_float_to_decimal(a, &dec);
    printf("from_decimal_to_float: %d\n", func_error);
  }

  {
    float a = 12345678901234567890123.45678;
    int func_error = 0;
    s21_decimal dec = {0};
    func_error = s21_from_float_to_decimal(a, &dec);
    printf("from_decimal_to_float: %d\n", func_error);
  }

  {
    float a = 0.0;
    int func_error = 0;
    s21_decimal dec = {0};
    func_error = s21_from_float_to_decimal(a, &dec);
    printf("from_decimal_to_float: %d\n", func_error);
  }

  // s21_is_equal

  // test_1; val_1 = 0; val_2 = 0; res = TRUE;
  {
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

    int res = s21_is_equal(value_1, value_2);
    printf("is_equal: %d\n", res);
  }

  // test_2; val_1 = 1; val_2 = 1; res = TRUE;
  {
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

    int res = s21_is_equal(value_1, value_2);
    printf("is_equal: %d\n", res);
  }

  // test_3; val_1 = -1; val_2 = -1; res = TRUE;
  {
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

    int res = s21_is_equal(value_1, value_2);
    printf("is_equal: %d\n", res);
  }

  // test_4; val_1 = -1; val_2 = 1; res = FALSE;
  {
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

    int res = s21_is_equal(value_1, value_2);
    printf("is_equal: %d\n", res);
  }

  // test_5; val_1 = 1; val_2 = -1; res = FALSE;
  {
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

    int res = s21_is_equal(value_1, value_2);
    printf("is_equal: %d\n", res);
  }

  // test_6; values are eq; val_2 OLDER has trash; res = TRUE;
  {
    s21_decimal value_1;
    value_1.bits[LOW] = 0x00000001;
    value_1.bits[MID] = 0x00000000;
    value_1.bits[HIGH] = 0x00000000;
    value_1.bits[OLDER] = 0x00000000;

    s21_decimal value_2;
    value_2.bits[LOW] = 0x00000001;
    value_2.bits[MID] = 0x00000000;
    value_2.bits[HIGH] = 0x00000000;
    value_2.bits[OLDER] = ~MASK_SCALE ^ MASK_SIGN;

    int res = s21_is_equal(value_1, value_2);
    printf("is_equal: %d\n", res);
  }

  // test_7; values are eq; val_1 OLDER has trash; res = TRUE;
  {
    s21_decimal value_1;
    value_1.bits[LOW] = 0x00000001;
    value_1.bits[MID] = 0x00000000;
    value_1.bits[HIGH] = 0x00000000;
    value_1.bits[OLDER] = ~MASK_SCALE ^ MASK_SIGN;

    s21_decimal value_2;
    value_2.bits[LOW] = 0x00000001;
    value_2.bits[MID] = 0x00000000;
    value_2.bits[HIGH] = 0x00000000;
    value_2.bits[OLDER] = 0x00000000;

    int res = s21_is_equal(value_1, value_2);
    printf("is_equal: %d\n", res);
  }

  // s21_is_not_equal

  // test_1; val_1 = 0; val_2 = 0; res = FALSE;
  {
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
    printf("is_not_equal: %d\n", res);
  }

  // test_2; val_1 = 1; val_2 = 1; res = FALSE;
  {
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
    printf("is_not_equal: %d\n", res);
  }

  // test_3; val_1 = -1; val_2 = -1; res = FALSE;
  {
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
    printf("is_not_equal: %d\n", res);
  }

  // test_4; val_1 = -1; val_2 = 1; res = TRUE;
  {
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
    printf("is_not_equal: %d\n", res);
  }

  // test_5; val_1 = 1; val_2 = -1; res = TRUE;
  {
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
    printf("is_not_equal: %d\n", res);
  }

  // test_6; values are eq; val_2 OLDER has trash; res = FALSE;
  {
    s21_decimal value_1;
    value_1.bits[LOW] = 0x00000001;
    value_1.bits[MID] = 0x00000000;
    value_1.bits[HIGH] = 0x00000000;
    value_1.bits[OLDER] = 0x00000000;

    s21_decimal value_2;
    value_2.bits[LOW] = 0x00000001;
    value_2.bits[MID] = 0x00000000;
    value_2.bits[HIGH] = 0x00000000;
    value_2.bits[OLDER] = ~MASK_SCALE ^ MASK_SIGN;

    int res = s21_is_not_equal(value_1, value_2);
    printf("is_not_equal: %d\n", res);
  }

  // test_7; values are eq; val_1 OLDER has trash; res = FALSE;
  {
    s21_decimal value_1;
    value_1.bits[LOW] = 0x00000001;
    value_1.bits[MID] = 0x00000000;
    value_1.bits[HIGH] = 0x00000000;
    value_1.bits[OLDER] = ~MASK_SCALE ^ MASK_SIGN;

    s21_decimal value_2;
    value_2.bits[LOW] = 0x00000001;
    value_2.bits[MID] = 0x00000000;
    value_2.bits[HIGH] = 0x00000000;
    value_2.bits[OLDER] = 0x00000000;

    int res = s21_is_not_equal(value_1, value_2);
    printf("is_not_equal: %d\n", res);
  }

  // s21_from_int_to_decimal

  // test_1; expected 0;
  {
    s21_decimal value;
    s21_from_int_to_decimal(0, &value);
  }

  // test_2; exptected 0;
  {
    s21_decimal value;
    s21_from_int_to_decimal(-0, &value);
  }

  // test_3; expected 1;
  {
    s21_decimal value;
    s21_from_int_to_decimal(1, &value);
  }

  // test_4; expected -1;
  {
    s21_decimal value;
    s21_from_int_to_decimal(-1, &value);
  }

  // test_5; expected 100;
  {
    s21_decimal value;
    s21_from_int_to_decimal(100, &value);
  }

  // test_6; expected -100;
  {
    s21_decimal value;
    s21_from_int_to_decimal(-100, &value);
  }

  // test_7; expected 255;
  {
    s21_decimal value;
    s21_from_int_to_decimal(255, &value);
  }

  // test_8; exptected -255;
  {
    s21_decimal value;
    s21_from_int_to_decimal(-255, &value);
  }

  // test_9;
  {
    s21_decimal value;
    s21_from_int_to_decimal(INT32_MAX, &value);
  }

  // test_10;
  {
    s21_decimal value;
    s21_from_int_to_decimal(INT32_MIN, &value);
  }

  // s21_from_decimal_to_int

  // test_1; dec = 0; res = 0;
  {
    int res = 7618246;  // random number to check res = 0

    s21_decimal value;
    value.bits[LOW] = 0x00000000;
    value.bits[MID] = 0x00000000;
    value.bits[HIGH] = 0x00000000;
    value.bits[OLDER] = 0x00000000;

    s21_from_decimal_to_int(value, &res);
  }

  // test_2; dec = -0; res = 0;
  {
    int res = 994818;  // random number to check res = 0

    s21_decimal value;
    value.bits[LOW] = 0x00000000;
    value.bits[MID] = 0x00000000;
    value.bits[HIGH] = 0x00000000;
    value.bits[OLDER] = 0x80000000;

    s21_from_decimal_to_int(value, &res);
  }

  // test_3; dec = 1; res = 1;
  {
    int res = 0;

    s21_decimal value;
    value.bits[LOW] = 0x00000001;
    value.bits[MID] = 0x00000000;
    value.bits[HIGH] = 0x00000000;
    value.bits[OLDER] = 0x00000000;

    s21_from_decimal_to_int(value, &res);
  }

  // test_4; dec = -1; res = -1;
  {
    int res = 0;

    s21_decimal value;
    value.bits[LOW] = 0x00000001;
    value.bits[MID] = 0x00000000;
    value.bits[HIGH] = 0x00000000;
    value.bits[OLDER] = 0x80000000;

    s21_from_decimal_to_int(value, &res);
  }

  // test_5; dec = INT32_MAX; res = INT32_MAX;
  {
    int res = 0;

    s21_decimal value;
    value.bits[LOW] = 0x7FFFFFFF;
    value.bits[MID] = 0x00000000;
    value.bits[HIGH] = 0x00000000;
    value.bits[OLDER] = 0x00000000;

    s21_from_decimal_to_int(value, &res);
  }

  // test_6; dec = -INT32_MAX; res = -INT32_MAX;
  {
    int res = 0;

    s21_decimal value;
    value.bits[LOW] = 0x7FFFFFFF;
    value.bits[MID] = 0x00000000;
    value.bits[HIGH] = 0x00000000;
    value.bits[OLDER] = 0x80000000;

    s21_from_decimal_to_int(value, &res);
  }

  // test_7; dec = INT32_MIN; res = INT32_MIN;
  {
    int res = 0;

    s21_decimal value;
    value.bits[LOW] = 0xFFFFFFFF;
    value.bits[MID] = 0x00000000;
    value.bits[HIGH] = 0x00000000;
    value.bits[OLDER] = 0x80000000;

    s21_from_decimal_to_int(value, &res);
  }

  // test_8; dec = 87491824; res = 87491824;
  {
    int res = 0;

    s21_decimal value;
    value.bits[LOW] = 0x053704F0;
    value.bits[MID] = 0x00000000;
    value.bits[HIGH] = 0x00000000;
    value.bits[OLDER] = 0x00000000;

    s21_from_decimal_to_int(value, &res);
  }

  // test_9; dec = -87491824; res = -87491824;
  {
    int res = 0;

    s21_decimal value;
    value.bits[LOW] = 0x053704F0;
    value.bits[MID] = 0x00000000;
    value.bits[HIGH] = 0x00000000;
    value.bits[OLDER] = 0x80000000;

    s21_from_decimal_to_int(value, &res);
  }

  // test_10; dec with MID trash; return error;
  {
    int res = 0;

    s21_decimal value;
    value.bits[LOW] = 0x00000000;
    value.bits[MID] = 0x00010000;
    value.bits[HIGH] = 0x00000000;
    value.bits[OLDER] = 0x00000000;

    s21_from_decimal_to_int(value, &res);
  }

  // test_11; dec with HIGH trash; return error;
  {
    int res = 0;

    s21_decimal value;
    value.bits[LOW] = 0x00000000;
    value.bits[MID] = 0x00000000;
    value.bits[HIGH] = 0x00100000;
    value.bits[OLDER] = 0x00000000;

    s21_from_decimal_to_int(value, &res);
  }

  // test_12; dec has value with HIGH trash; return error;
  {
    int res = 0;

    s21_decimal value;
    value.bits[LOW] = 0x00000010;
    value.bits[MID] = 0x00000000;
    value.bits[HIGH] = 0x00100000;
    value.bits[OLDER] = 0x80000000;

    s21_from_decimal_to_int(value, &res);
  }

  // s21_negate

  // test_1;
  {
    s21_decimal result;

    s21_decimal value;
    value.bits[LOW] = 0;
    value.bits[MID] = 0;
    value.bits[HIGH] = 0;
    value.bits[OLDER] = 0x00000000;

    s21_negate(value, &result);
  }

  // test_2;
  {
    s21_decimal result;

    s21_decimal value;
    value.bits[LOW] = 0;
    value.bits[MID] = 0;
    value.bits[HIGH] = 0;
    value.bits[OLDER] = 0x80000000;

    s21_negate(value, &result);
  }

  // test_3;
  {
    s21_decimal result;

    s21_decimal value;
    value.bits[LOW] = 14;
    value.bits[MID] = 10;
    value.bits[HIGH] = 80;
    value.bits[OLDER] = 0x80000000;

    s21_negate(value, &result);
  }

  // test_4;
  {
    s21_decimal result;

    s21_decimal value;
    value.bits[LOW] = 14;
    value.bits[MID] = 10;
    value.bits[HIGH] = 80;
    value.bits[OLDER] = 0x00000000;

    s21_negate(value, &result);
  }

  // s21_truncate

  {
    s21_decimal dec1 = {0};

    dec1.bits[OLDER] = 0x000A0000;
    dec1.bits[HIGH] = 0x0;
    dec1.bits[MID] = 0xFFFFFFFF;
    dec1.bits[LOW] = 0xFFFFFFFF;
    s21_decimal res1 = {0};
    s21_truncate(dec1, &res1);
  }

  {
    s21_decimal dec1 = {0};

    dec1.bits[OLDER] = 0b10000000000011000000000000000000;
    dec1.bits[HIGH] = 0x0;
    dec1.bits[MID] = 0xFFFFFFFF;
    dec1.bits[LOW] = 0xFFFFFFFF;
    s21_decimal res1 = {0};
    s21_truncate(dec1, &res1);
  }

  {
    s21_decimal dec1, res1 = {0};

    dec1.bits[OLDER] = 0x80000000;
    dec1.bits[HIGH] = 0x0;
    dec1.bits[MID] = 0xFFFFFFFF;
    dec1.bits[LOW] = 0xFFFFFFFF;
    s21_truncate(dec1, &res1);
  }

  {
    s21_decimal dec1 = {0};

    dec1.bits[LOW] = 0b00000000000000000000000001101101;
    dec1.bits[MID] = 0b00000000000011000110010101011011;
    dec1.bits[HIGH] = 0b00000000000000000011000000111001;
    dec1.bits[OLDER] = 0b00000000000011100000000000000000;
    s21_decimal res1 = {0};
    s21_truncate(dec1, &res1);
  }

  {
    s21_decimal dec1 = {0};

    dec1.bits[OLDER] = 0x80090000;
    dec1.bits[HIGH] = 0;
    dec1.bits[MID] = 0xFFFFEA34;
    dec1.bits[LOW] = 0xFF837E4F;
    s21_decimal result = {0};
    s21_truncate(dec1, &result);
  }

  {
    s21_decimal dec1 = {0};

    dec1.bits[LOW] = 0b11010000101000110011000001101101;
    dec1.bits[MID] = 0b00011111100110100110101101011000;
    dec1.bits[HIGH] = 0;
    dec1.bits[OLDER] = 0b00000000000010010000000000000000;
    s21_decimal result = {0};
    s21_truncate(dec1, &result);
  }

  {
    s21_decimal dec1 = {0};

    dec1.bits[LOW] = 0b01111000101001111011110011000110;
    dec1.bits[MID] = 0b10011111111111001111101010000100;
    dec1.bits[HIGH] = 0b00011111111010011010111101101101;
    dec1.bits[OLDER] = 0b00000000000111000000000000000000;
    s21_decimal res1 = {0};
    s21_truncate(dec1, &res1);
  }

  {
    // 6766
    s21_decimal src1;
    // src1 = 2;

    src1.bits[LOW] = 0b00000000000000000000000000000010;
    src1.bits[MID] = 0b00000000000000000000000000000000;
    src1.bits[HIGH] = 0b00000000000000000000000000000000;
    src1.bits[OLDER] = 0b00000000000000000000000000000000;
    s21_decimal result = {{0, 0, 0, 0}};
    s21_truncate(src1, &result);
  }

  {
    // 6787
    s21_decimal src1;
    // src1 = 3.5;

    src1.bits[LOW] = 0b00000000000000000000000000100011;
    src1.bits[MID] = 0b00000000000000000000000000000000;
    src1.bits[HIGH] = 0b00000000000000000000000000000000;
    src1.bits[OLDER] = 0b00000000000000010000000000000000;
    s21_decimal result = {{0, 0, 0, 0}};
    s21_truncate(src1, &result);
  }

  {
    // 6808
    s21_decimal src1;
    // src1 = 0;

    src1.bits[LOW] = 0b00000000000000000000000000000000;
    src1.bits[MID] = 0b00000000000000000000000000000000;
    src1.bits[HIGH] = 0b00000000000000000000000000000000;
    src1.bits[OLDER] = 0b00000000000000000000000000000000;
    s21_decimal result = {{0, 0, 0, 0}};
    s21_truncate(src1, &result);
  }

  {
    // 6829
    s21_decimal src1;
    // src1 = 0;

    src1.bits[LOW] = 0b00000000000000000000000000000000;
    src1.bits[MID] = 0b00000000000000000000000000000000;
    src1.bits[HIGH] = 0b00000000000000000000000000000000;
    src1.bits[OLDER] = 0b00000000000000000000000000000000;
    s21_decimal result = {{0, 0, 0, 0}};
    s21_truncate(src1, &result);
  }

  {
    // 6850
    s21_decimal src1;
    // src1 = -9878798789;

    src1.bits[LOW] = 0b01001100110100101000000111000101;
    src1.bits[MID] = 0b00000000000000000000000000000010;
    src1.bits[HIGH] = 0b00000000000000000000000000000000;
    src1.bits[OLDER] = 0b10000000000000000000000000000000;
    s21_decimal result = {{0, 0, 0, 0}};
    s21_truncate(src1, &result);
  }

  {
    // 6871
    s21_decimal src1;
    // src1 = -545454512454545.35265454545645;

    src1.bits[LOW] = 0b10000010111000100101101011101101;
    src1.bits[MID] = 0b11111001111010000010010110101101;
    src1.bits[HIGH] = 0b10110000001111101111000010010100;
    src1.bits[OLDER] = 0b10000000000011100000000000000000;
    s21_decimal result = {{0, 0, 0, 0}};
    s21_truncate(src1, &result);
  }

  {
    // 6892
    s21_decimal src1;
    // src1 = -5.492654545456454545645464;

    src1.bits[LOW] = 0b00000111100110110001111110011000;
    src1.bits[MID] = 0b01100110010010001001000110100011;
    src1.bits[HIGH] = 0b00000000000001001000101100011101;
    src1.bits[OLDER] = 0b10000000000110000000000000000000;
    s21_decimal result = {{0, 0, 0, 0}};
    s21_truncate(src1, &result);
  }

  {
    // 6913
    s21_decimal src1;
    // src1 = 7961327845421.879754123131254;

    src1.bits[LOW] = 0b01001110111001000011100101110110;
    src1.bits[MID] = 0b01001011001101011010000111011001;
    src1.bits[HIGH] = 0b00011001101110010111010010111111;
    src1.bits[OLDER] = 0b00000000000011110000000000000000;
    s21_decimal result = {{0, 0, 0, 0}};
    s21_truncate(src1, &result);
  }

  {
    // 6934
    s21_decimal src1;
    // src1 = -12345677.187654345678987654346;

    src1.bits[LOW] = 0b01111000100010101111010011001010;
    src1.bits[MID] = 0b01100010000010101110010010000111;
    src1.bits[HIGH] = 0b00100111111001000001101011010101;
    src1.bits[OLDER] = 0b10000000000101010000000000000000;
    s21_decimal result = {{0, 0, 0, 0}};
    s21_truncate(src1, &result);
  }

  {
    // 6955
    s21_decimal src1;
    // src1 = 2.5086531268974139743;

    src1.bits[LOW] = 0b01100101111011101101100101011111;
    src1.bits[MID] = 0b01011100001001010100001101000110;
    src1.bits[HIGH] = 0b00000000000000000000000000000001;
    src1.bits[OLDER] = 0b00000000000100110000000000000000;
    s21_decimal result = {{0, 0, 0, 0}};
    s21_truncate(src1, &result);
  }

  {
    // 6976
    s21_decimal src1;
    // src1 = 1;

    src1.bits[LOW] = 0b00000000000000000000000000000001;
    src1.bits[MID] = 0b00000000000000000000000000000000;
    src1.bits[HIGH] = 0b00000000000000000000000000000000;
    src1.bits[OLDER] = 0b00000000000000000000000000000000;
    s21_decimal result = {{0, 0, 0, 0}};
    s21_truncate(src1, &result);
  }

  // s21_is_greater

  {
    s21_decimal a = {{UINT_MAX, 0, 0, 0}};
    s21_decimal b = {{UINT_MAX, 0, 0, 0}};
    s21_is_greater(a, b);
  }

  {
    s21_decimal val1 = {{0}};
    s21_decimal val2 = {{0}};
    s21_is_greater(val1, val2);
  }

  {
    s21_decimal val1 = {{0}};
    s21_decimal val2 = {{0}};
    val1.bits[0] = 255;
    val2.bits[0] = 256;
    s21_is_greater(val1, val2);
  }

  {
    s21_decimal val1 = {{0}};
    s21_decimal val2 = {{0}};
    val1.bits[0] = 256;
    val2.bits[0] = 256;
    s21_is_greater(val1, val2);
  }

  {
    s21_decimal val1 = {{0}};
    s21_decimal val2 = {{0}};
    val1.bits[0] = 257;
    val2.bits[0] = 256;
    s21_is_greater(val1, val2);
  }

  {
    s21_decimal val1 = {{0}};
    s21_decimal val2 = {{0}};
    set_bit(&val1, 127, 1);
    s21_is_greater(val1, val2);
  }

  {
    s21_decimal val1 = {{0}};
    s21_decimal val2 = {{0}};
    val1.bits[0] = 257;
    val2.bits[0] = 257;
    val1.bits[2] = 256;
    val2.bits[2] = 257;
    set_scale(&val1, 11);
    set_scale(&val2, 10);
    s21_is_greater(val1, val2);
  }

  {
    s21_decimal val1 = {{0}};
    s21_decimal val2 = {{0}};
    val1.bits[0] = 257;
    val2.bits[0] = 257;
    val1.bits[2] = 256;
    val2.bits[2] = 257;
    set_scale(&val1, 10);
    set_scale(&val2, 11);
    s21_is_greater(val1, val2);
  }

  {
    s21_decimal val1 = {{0}};
    s21_decimal val2 = {{0}};
    val2.bits[2] = 257;
    set_bit(&val1, 127, 1);
    set_bit(&val2, 127, 1);
    s21_is_greater(val1, val2);
  }

  {
    s21_decimal val1 = {{0}};
    s21_decimal val2 = {{0}};
    val2.bits[2] = 257;
    set_bit(&val1, 127, 1);
    set_bit(&val2, 127, 0);
    s21_is_greater(val1, val2);
  }

  // s21_is_less

  {
    s21_decimal val1 = {{0}};
    s21_decimal val2 = {{0}};
    s21_is_less(val1, val2);
  }

  {
    s21_decimal val1 = {{0}};
    s21_decimal val2 = {{0}};
    val1.bits[0] = 255;
    val2.bits[0] = 256;
    s21_is_less(val1, val2);
  }

  {
    s21_decimal val1 = {{0}};
    s21_decimal val2 = {{0}};
    val1.bits[0] = 256;
    val2.bits[0] = 256;
    s21_is_less(val1, val2);
  }

  {
    s21_decimal val1 = {{0}};
    s21_decimal val2 = {{0}};
    val1.bits[0] = 257;
    val2.bits[0] = 256;
    s21_is_less(val1, val2);
  }

  {
    s21_decimal val1 = {{0}};
    s21_decimal val2 = {{0}};
    val1.bits[0] = 257;
    val2.bits[0] = 256;
    val1.bits[2] = 256;
    val2.bits[2] = 257;
    set_scale(&val1, 11);
    set_scale(&val2, 10);
    s21_is_less(val1, val2);
  }

  {
    s21_decimal val1 = {{0}};
    s21_decimal val2 = {{0}};
    val1.bits[0] = 257;
    val2.bits[0] = 257;
    val1.bits[2] = 256;
    val2.bits[2] = 257;
    set_scale(&val1, 10);
    set_scale(&val2, 11);
    s21_is_less(val1, val2);
  }

  {
    s21_decimal val1 = {{0}};
    s21_decimal val2 = {{0}};
    val2.bits[2] = 257;
    set_scale(&val1, 127);
    set_scale(&val2, 127);
    s21_is_less(val1, val2);
  }

  {
    s21_decimal val1 = {{0}};
    s21_decimal val2 = {{0}};
    set_bit(&val1, 127, 1);
    set_bit(&val2, 127, 1);
    set_bit(&val1, 83, 1);
    set_scale(&val1, 12);
    set_scale(&val2, 11);
    s21_is_less(val1, val2);
  }

  {
    s21_decimal val1 = {{0}};
    s21_decimal val2 = {{0}};
    set_bit(&val1, 127, 1);
    set_bit(&val2, 127, 1);
    set_bit(&val1, 83, 1);
    set_bit(&val2, 83, 1);
    set_scale(&val1, 10);
    set_scale(&val2, 11);
    s21_is_less(val1, val2);
  }

  {
    s21_decimal val1 = {{0}};
    s21_decimal val2 = {{0}};
    set_bit(&val1, 127, 1);
    set_bit(&val2, 127, 1);
    set_bit(&val1, 83, 1);
    set_scale(&val1, 10);
    set_scale(&val2, 10);
    s21_is_less(val1, val2);
  }

  // s21_is_less_or_equal

  {
    s21_decimal val1 = {{0}};
    s21_decimal val2 = {{0}};
    s21_is_less_or_equal(val1, val2);
  }

  {
    s21_decimal val1 = {{0}};
    s21_decimal val2 = {{0}};
    val1.bits[0] = 255;
    val2.bits[0] = 256;
    s21_is_less_or_equal(val1, val2);
  }

  {
    s21_decimal val1 = {{0}};
    s21_decimal val2 = {{0}};
    val1.bits[0] = 256;
    val2.bits[0] = 256;
    s21_is_less_or_equal(val1, val2);
  }

  {
    s21_decimal val1 = {{0}};
    s21_decimal val2 = {{0}};
    val1.bits[0] = 257;
    val2.bits[0] = 256;
    s21_is_less_or_equal(val1, val2);
  }

  {
    s21_decimal val1 = {{0}};
    s21_decimal val2 = {{0}};
    set_bit(&val1, 127, 1);
    s21_is_less_or_equal(val1, val2);
  }

  {
    s21_decimal val1 = {{0}};
    s21_decimal val2 = {{0}};
    val1.bits[0] = 257;
    val2.bits[0] = 257;
    val1.bits[2] = 256;
    val2.bits[2] = 257;
    set_scale(&val1, 11);
    set_scale(&val2, 10);
    s21_is_less_or_equal(val1, val2);
  }

  {
    s21_decimal val1 = {{0}};
    s21_decimal val2 = {{0}};
    val1.bits[0] = 257;
    val2.bits[0] = 257;
    val1.bits[2] = 256;
    val2.bits[2] = 257;
    set_scale(&val1, 10);
    set_scale(&val2, 11);
    s21_is_less_or_equal(val1, val2);
  }

  {
    s21_decimal val1 = {{0}};
    s21_decimal val2 = {{0}};
    val2.bits[2] = 257;
    set_bit(&val1, 127, 1);
    set_bit(&val2, 127, 1);
    s21_is_less_or_equal(val1, val2);
  }

  {
    float a = rand();
    float b = rand();

    s21_decimal _a = {{0}};
    s21_decimal _b = {{0}};
    s21_from_float_to_decimal(a, &_a);
    s21_from_float_to_decimal(b, &_b);
    s21_is_less_or_equal(_a, _b);
  }

  {
    float a = rand();
    float b = rand();

    s21_decimal _a = {{0}};
    s21_decimal _b = {{0}};
    s21_from_float_to_decimal(a, &_a);
    s21_from_float_to_decimal(b, &_b);
    s21_is_less_or_equal(_a, _b);
  }

  // s21_is_greater_or_equal

  {
    s21_decimal val1 = {{0}};
    s21_decimal val2 = {{0}};
    s21_is_greater_or_equal(val1, val2);
  }

  {
    s21_decimal val1 = {{0}};
    s21_decimal val2 = {{0}};
    val1.bits[0] = 255;
    val2.bits[0] = 256;
    s21_is_greater_or_equal(val1, val2);
  }

  {
    s21_decimal val1 = {{0}};
    s21_decimal val2 = {{0}};
    val1.bits[0] = 256;
    val2.bits[0] = 256;
    s21_is_greater_or_equal(val1, val2);
  }

  {
    s21_decimal val1 = {{0}};
    s21_decimal val2 = {{0}};
    val1.bits[0] = 257;
    val2.bits[0] = 256;
    s21_is_greater_or_equal(val1, val2);
  }

  {
    s21_decimal val1 = {{0}};
    s21_decimal val2 = {{0}};
    val1.bits[0] = 257;
    val2.bits[0] = 257;
    val1.bits[2] = 256;
    val2.bits[2] = 257;
    set_scale(&val1, 11);
    set_scale(&val2, 10);
    s21_is_greater_or_equal(val1, val2);
  }

  {
    s21_decimal val1 = {{0}};
    s21_decimal val2 = {{0}};
    val1.bits[0] = 257;
    val2.bits[0] = 257;
    val1.bits[2] = 256;
    val2.bits[2] = 257;
    set_scale(&val1, 10);
    set_scale(&val2, 11);
    s21_is_greater_or_equal(val1, val2);
  }

  {
    s21_decimal val1 = {{0}};
    s21_decimal val2 = {{0}};
    val2.bits[2] = 257;
    set_bit(&val1, 127, 1);
    set_bit(&val2, 127, 1);
    s21_is_greater_or_equal(val1, val2);
  }

  {
    float a = rand();
    float b = rand();

    s21_decimal _a = {{0}};
    s21_decimal _b = {{0}};
    s21_from_float_to_decimal(a, &_a);
    s21_from_float_to_decimal(b, &_b);
    s21_is_greater_or_equal(_a, _b);
  }

  {
    float a = rand();

    s21_decimal _a = {{0}};
    s21_decimal _b = {{0}};
    s21_from_float_to_decimal(a, &_a);
    s21_from_float_to_decimal(a, &_b);
    s21_is_greater_or_equal(_a, _b);
  }

  {
    s21_decimal value_1 = {{123457u, 654u, 0xFFFFFFFF, 0}};
    s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
    s21_is_greater_or_equal(value_1, value_2);
  }

  // s21_mul

  {
    s21_decimal src1, src2, result;
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
    s21_mul(src1, src2, &result);
  }

  {
    s21_decimal src1, src2, result;
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
    s21_mul(src1, src2, &result);
  }

  {
    s21_decimal src1, src2, result;
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
    s21_mul(src1, src2, &result);
  }

  {
    s21_decimal src1, src2, result;
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
    s21_mul(src1, src2, &result);
  }

  {
    s21_decimal src1, src2, result;
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
    s21_mul(src1, src2, &result);
  }

  {
    s21_decimal src1, src2, result;
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
    s21_mul(src1, src2, &result);
  }

  {
    s21_decimal src1, src2, result;
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
    s21_mul(src1, src2, &result);
  }

  {
    s21_decimal src1, src2, result;
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
    s21_mul(src1, src2, &result);
  }

  {
    s21_decimal src1, src2, result;
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
    s21_mul(src1, src2, &result);
  }

  {
    s21_decimal src1, src2, result;
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
    s21_mul(src1, src2, &result);
  }

  // s21_add

  {
    int num1 = 42;
    int num2 = 30;
    s21_decimal a, b;
    s21_from_int_to_decimal(num1, &a);
    s21_from_int_to_decimal(num2, &b);
    s21_decimal res_dec = {0};
    s21_add(a, b, &res_dec);
  }

  {
    int num1 = 1000;
    int num2 = 2000;
    s21_decimal a, b;
    s21_from_int_to_decimal(num1, &a);
    s21_from_int_to_decimal(num2, &b);
    s21_decimal res_dec = {0};
    s21_add(a, b, &res_dec);
  }

  {
    int num1 = 0;
    int num2 = 0;
    s21_decimal a, b;
    s21_from_int_to_decimal(num1, &a);
    s21_from_int_to_decimal(num2, &b);
    s21_decimal res_dec = {0};
    s21_add(a, b, &res_dec);
  }

  {
    int num1 = -15;
    int num2 = 5;
    s21_decimal a, b;
    s21_from_int_to_decimal(num1, &a);
    s21_from_int_to_decimal(num2, &b);
    s21_decimal res_dec = {0};
    int res_int = 0;
    s21_add(a, b, &res_dec);
    s21_from_decimal_to_int(res_dec, &res_int);
  }

  {
    int num1 = 11115;
    int num2 = 5;
    s21_decimal a, b;
    s21_from_int_to_decimal(num1, &a);
    s21_from_int_to_decimal(num2, &b);
    s21_decimal res_dec = {0};
    int res_int = 0;
    s21_add(a, b, &res_dec);
    s21_from_decimal_to_int(res_dec, &res_int);
  }

  {
    int num1 = -1;
    int num2 = -10;
    s21_decimal a, b;
    s21_from_int_to_decimal(num1, &a);
    s21_from_int_to_decimal(num2, &b);
    s21_decimal res_dec = {0};
    int res_int = 0;
    s21_add(a, b, &res_dec);
    s21_from_decimal_to_int(res_dec, &res_int);
  }

  {
    s21_decimal src1, src2;
    int a = -1234;
    int b = 234;
    s21_from_int_to_decimal(a, &src1);
    s21_from_int_to_decimal(b, &src2);
    s21_decimal res_dec = {0};
    int res_int = 0;
    s21_add(src1, src2, &res_dec);
    s21_from_decimal_to_int(res_dec, &res_int);
  }

  {
    s21_decimal src1, src2;
    int a = -9403;
    int b = 234;
    s21_from_int_to_decimal(a, &src1);
    s21_from_int_to_decimal(b, &src2);
    s21_decimal res_dec = {0};
    int res_int = 0;
    s21_add(src1, src2, &res_dec);
    s21_from_decimal_to_int(res_dec, &res_int);
  }

  {
    s21_decimal src1, src2;
    int a = 9403;
    int b = 202;
    s21_from_int_to_decimal(a, &src1);
    s21_from_int_to_decimal(b, &src2);
    s21_decimal res_dec = {0};
    int res_int = 0;
    s21_add(src1, src2, &res_dec);
    s21_from_decimal_to_int(res_dec, &res_int);
  }

  {
    s21_decimal src1, src2;
    int a = 450;
    int b = -50;
    s21_from_int_to_decimal(a, &src1);
    s21_from_int_to_decimal(b, &src2);
    s21_decimal res_dec = {0};
    int res_int = 0;
    s21_add(src1, src2, &res_dec);
    s21_from_decimal_to_int(res_dec, &res_int);
  }

  // s21_sub

  {
    s21_decimal src1, src2, result;
    // src1 = 9;
    // src2 = 18571145;
    src1.bits[0] = 0b00000000000000000000000000001001;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000000000000000000000;
    src2.bits[0] = 0b00000001000110110101111110001001;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000000000000000000000000;
    s21_sub(src1, src2, &result);
  }

  {
    s21_decimal src1, src2, result;
    // src1 = 1849687;
    // src2 = 6;
    src1.bits[0] = 0b00000000000111000011100101010111;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000000000000000000000;
    src2.bits[0] = 0b00000000000000000000000000000110;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000000000000000000000000;
    s21_sub(src1, src2, &result);
  }

  {
    s21_decimal src1, src2, result;
    // src1 = -3187878;
    // src2 = 1;
    src1.bits[0] = 0b00000000001100001010010010100110;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b10000000000000000000000000000000;
    src2.bits[0] = 0b00000000000000000000000000000001;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000000000000000000000000;
    s21_sub(src1, src2, &result);
  }

  {
    s21_decimal src1, src2, result;
    // src1 = 1;
    // src2 = 18768768;
    src1.bits[0] = 0b00000000000000000000000000000001;
    src1.bits[1] = 0b00000000000000000000000000000000;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000000000000000000000000;
    src2.bits[0] = 0b00000001000111100110001110000000;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000000000000000000000000;
    s21_sub(src1, src2, &result);
  }

  {
    s21_decimal src1, src2, result;
    // src1 = 18446744073709551615.0;
    // src2 = 3556877454;
    src1.bits[0] = 0b11111111111111111111111111110110;
    src1.bits[1] = 0b11111111111111111111111111111111;
    src1.bits[2] = 0b00000000000000000000000000001001;
    src1.bits[3] = 0b00000000000000010000000000000000;
    src2.bits[0] = 0b11010100000000011010010010001110;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000000000000000000000000;
    s21_sub(src1, src2, &result);
  }

  {
    s21_decimal src1, src2, result;
    // src1 = -54896651557845.352654545456455;
    // src2 = 21465;
    src1.bits[0] = 0b01110001100100011000110101000111;
    src1.bits[1] = 0b00001111010011100000001101011111;
    src1.bits[2] = 0b10110001011000010111001000100100;
    src1.bits[3] = 0b10000000000011110000000000000000;
    src2.bits[0] = 0b00000000000000000101001111011001;
    src2.bits[1] = 0b00000000000000000000000000000000;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000000000000000000000000;
    s21_sub(src1, src2, &result);
  }

  {
    s21_decimal src1, src2, result;
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
    s21_sub(src1, src2, &result);
  }

  {
    s21_decimal src1, src2, result;
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
    s21_sub(src1, src2, &result);
  }

  {
    s21_decimal src1, src2, result;
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
    s21_sub(src1, src2, &result);
  }

  {
    s21_decimal src1, src2, result;
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
    s21_sub(src1, src2, &result);
  }

  // s21_floor

  {
    s21_decimal val = {{2, 0, 0, 0}};
    s21_decimal res;
    s21_floor(val, &res);
  }

  {
    s21_decimal val = {{2, 0, 0, ~(UINT_MAX / 2)}};
    s21_decimal res = {{0}};
    s21_floor(val, &res);
    float fres = 0;
    s21_from_decimal_to_float(res, &fres);
  }

  {
    s21_decimal val = {{2, 0, 0, ~(UINT_MAX / 2)}};
    s21_decimal res = {{0}};
    set_scale(&val, 5);
    s21_floor(val, &res);
    float fres = 0;
    s21_from_decimal_to_float(res, &fres);
  }

  {
    s21_decimal val = {{2, 0, 0, 0}};
    s21_decimal res = {{0}};
    set_scale(&val, 5);
    s21_floor(val, &res);
  }

  {
    s21_decimal value_1 = {{7444923, 0, 0, 0}};
    set_scale(&value_1, 5);
    s21_decimal result = {0};
    s21_floor(value_1, &result);
  }

  {
    s21_decimal value_1 = {{7444923, 0, 0, 0}};
    set_scale(&value_1, 5);
    set_bit(&value_1, 127, 1);
    s21_decimal check = {{75, 0, 0, 0}};
    set_bit(&check, 127, 1);
    s21_decimal result = {0};
    s21_floor(value_1, &result);
  }

  {
    s21_decimal src1;
    src1.bits[0] = 0b00001111111111111111111111111111;
    src1.bits[1] = 0b00111110001001010000001001100001;
    src1.bits[2] = 0b00100000010011111100111001011110;
    src1.bits[3] = 0b10000000000010100000000000000000;
    s21_decimal res_od = {0};
    s21_floor(src1, &res_od);
  }

  // s21_div

  {
    s21_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
    s21_decimal val2 = {{2, 0, 0, 0}};
    s21_decimal res = {{0}};
    s21_div(val1, val2, &res);
  }

  {
    s21_decimal val1 = {{2, 0, 0, 0}};
    s21_decimal val2 = {{2, 0, 0, ~(UINT_MAX / 2)}};
    s21_decimal res;
    s21_div(val1, val2, &res);
  }

  {
    s21_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
    s21_decimal val2 = {{2, 0, 0, ~(UINT_MAX / 2)}};
    s21_decimal res = {{0}};
    s21_div(val1, val2, &res);
  }

  {
    s21_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
    s21_decimal val2 = {{0, 0, 0, 0}};
    s21_decimal res = {{0}};
    s21_div(val1, val2, &res);
  }

  {
    s21_decimal val1 = {{2, 0, 0, 0}};
    s21_decimal val2 = {{0, 0, 0, 0}};
    s21_decimal res = {{0}};
    s21_div(val1, val2, &res);
  }

  {
    s21_decimal value_1 = {{15, 0, 0, 0}};
    set_sign(&value_1, MINUS);
    s21_decimal value_2 = {{0, 0, 0, 0}};
    s21_decimal result = {{0, 0, 0, 0}};
    s21_div(value_1, value_2, &result);
  }

  {
    int num1 = 2;
    int num2 = 2;
    s21_decimal a = {0};
    s21_decimal b = {0};
    s21_from_int_to_decimal(num1, &a);
    s21_from_int_to_decimal(num2, &b);
    s21_decimal res_dec = {0};
    int res_int = 0;
    s21_div(a, b, &res_dec);
    s21_from_decimal_to_int(res_dec, &res_int);
  }

  {
    int num1 = 0;
    int num2 = 5;
    s21_decimal a = {0};
    s21_decimal b = {0};
    s21_from_int_to_decimal(num1, &a);
    s21_from_int_to_decimal(num2, &b);
    s21_decimal res_dec = {0};
    int res_int = 0;
    s21_div(a, b, &res_dec);
    s21_from_decimal_to_int(res_dec, &res_int);
  }

  {
    s21_decimal dec1 = {{1110, 0, 0, 0}};
    s21_decimal dec2 = {{0, 0, 0, 0}};

    s21_decimal res1;
    s21_div(dec1, dec2, &res1);
  }

  // s21_round

  {
    s21_decimal val = {{7, 7, 7, 0}};
    s21_decimal res;
    s21_round(val, &res);
    float fres = 0;
    s21_from_decimal_to_float(res, &fres);
  }

  {
    s21_decimal val = {{3, 3, 3, ~(UINT_MAX / 2)}};
    s21_decimal res = {{0}};
    s21_round(val, &res);
  }

  {
    s21_decimal val = {{3, 3, 3, 0}};
    s21_decimal res = {{0}};
    set_scale(&val, 5);
    s21_round(val, &res);
  }

  {
    s21_decimal val = {{7, 7, 7, ~(UINT_MAX / 2)}};
    s21_decimal res = {{0}};
    set_scale(&val, 5);
    s21_round(val, &res);
  }

  {
    s21_decimal val = {{25, 0, 0, ~(UINT_MAX / 2)}};
    s21_decimal res = {{0}};
    set_scale(&val, 1);
    s21_round(val, &res);
  }

  {
    s21_decimal val = {{26, 0, 0, 0}};
    s21_decimal res = {{0}};
    set_scale(&val, 1);
    s21_round(val, &res);
  }

  {
    s21_decimal val = {{115, 0, 0, 0}};
    s21_decimal res = {{0}};
    set_scale(&val, 1);
    s21_round(val, &res);
  }

  {
    s21_decimal val = {{118, 0, 0, 0}};
    s21_decimal res = {{0}};
    set_scale(&val, 1);
    s21_round(val, &res);
  }

  {
    s21_decimal val = {{125, 0, 0, 0}};
    s21_decimal res = {{0}};
    set_scale(&val, 1);
    s21_round(val, &res);
  }

  {
    s21_decimal val = {{128, 0, 0, 0}};
    s21_decimal res = {{0}};
    set_scale(&val, 1);
    s21_round(val, &res);
    float fres = 0;
    s21_from_decimal_to_float(res, &fres);
  }

  return 0;
}
