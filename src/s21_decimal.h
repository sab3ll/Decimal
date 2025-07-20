#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H

#include <limits.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// s21_decimal size
// -79228162514264337593543950335
// +79228162514264337593543950335

// Common
enum BOOLEAN { FALSE, TRUE };
enum SIGN { PLUS, MINUS };
enum BYTES { LOW, MID, HIGH, OLDER };
enum DIRECTION { LEFT, RIGHT };
enum COMPARE_OPT { EQUAL, FIRST_VALUE, SECOND_VALUE };

enum MATH_ERR_CODES { OK, POS_INF, NEG_INF, DIV_BY_ZERO };
enum CONV_ERR_CODES { SUCCESS, ERROR };

#define INT_BIT_QUANTITY 32
#define SCALE_ACCURACY 28
#define FLOAT_EXP_CONST 127
#define BIGDEC_SIZE 8

// Bits
#define BIT_EXP_FIRST 23
#define BIT_EXP_LAST 30

#define BIT_SCALE_FIRST 16
#define BIT_SCALE_LAST 23

#define BIT_LOW_FIRST 0
#define BIT_LOW_LAST 31

#define BIT_MID_FIRST 32
#define BIT_MID_LAST 63

#define BIT_HIGH_FIRST 64
#define BIT_HIGH_LAST 95

#define BIT_OLDER_FIRST 96
#define BIT_OLDER_LAST 127

#define BIT_BIGDEC_LAST INT_BIT_QUANTITY *BIGDEC_SIZE - 1

// Masks
#define MASK_LAST_BIT 0x80000000
#define MASK_SIGN MASK_LAST_BIT
#define MASK_SCALE 0x00FF0000
#define MASK_UNUSED 0xFF00FFFF
#define MASK_FLOAT_EXP 0x7F800000
#define MASK_FULL 0xFFFFFFFF

typedef struct {
  unsigned int bits[4];
} s21_decimal;

typedef struct {
  unsigned int sign;
  int scale;
  unsigned int bits[BIGDEC_SIZE];
} s21_bigdec;

typedef struct {
  s21_bigdec quotient;
  s21_bigdec remainder;
} div_res;

// Main functions
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

int s21_is_less(s21_decimal value_1, s21_decimal value_2);
int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2);

int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

// Common functions
void initial(s21_decimal *value);
void initial_bigdec(s21_bigdec *value);

int get_bit(s21_decimal value, int bit_index);
int get_bit_bigdec(s21_bigdec value, int bit_index);
int set_bit(s21_decimal *value, int bit_index, unsigned int bit_value);
int set_bit_bigdec(s21_bigdec *value, int bit_index, unsigned int bit_value);

int get_scale(s21_decimal value);
int get_scale_bigdec(s21_bigdec value);
int set_scale(s21_decimal *value, unsigned int scale);
int set_scale_bigdec(s21_bigdec *value, unsigned int scale);

int get_bin_exp_from_float(float value);

int get_sign(s21_decimal value);
int get_sign_bigdec(s21_bigdec value);
int set_sign(s21_decimal *value, unsigned int sign);
int set_sign_bigdec(s21_bigdec *value, unsigned int sign);

void from_decimal_to_bigdec(s21_decimal src, s21_bigdec *value);
int from_bigdec_to_decimal(s21_bigdec *src, s21_decimal *value);

void shift(s21_decimal *value, int direction);
void shift_bigdec(s21_bigdec *value, int direction);
void shift_by_num_bigdec(s21_bigdec *value, int direction, unsigned int count);
void multiply_by_num(s21_decimal *value, unsigned int num);
void multiply_by_num_bigdec(s21_bigdec *value, unsigned int num);
void division_by_ten_bigdec(s21_bigdec *value);
void normalization(s21_decimal *value_1, s21_decimal *value_2);
void normalization_bigdec(s21_bigdec *value_1, s21_bigdec *value_2);
void bitwise_add(s21_bigdec value_1, s21_bigdec value_2, s21_bigdec *result);
void bitwise_sub(s21_bigdec value_1, s21_bigdec value_2, s21_bigdec *result);
void bitwise_mul(s21_bigdec value_1, s21_bigdec value_2, s21_bigdec *result);
div_res bitwise_div(s21_bigdec value_1, s21_bigdec value_2);

int is_zero(s21_decimal value);
int is_zero_bigdec(s21_bigdec value);
int is_one_bigdec(s21_bigdec value);
int comparison_mantissa(s21_decimal value_1, s21_decimal value_2);
int comparison_mantissa_bigdec(s21_bigdec value_1, s21_bigdec value_2);
void copy_decimal(s21_decimal src, s21_decimal *value);
void copy_bigdec(s21_bigdec src, s21_bigdec *value);

#endif
