#include "../s21_decimal.h"

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int res = OK;

  s21_negate(value_2, &value_2);

  res = s21_add(value_1, value_2, result);

  if (is_zero(*result)) result->bits[OLDER] = 0;

  return res;
}
