#include "../s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
  int res = SUCCESS;
  int sign = get_sign(value);

  s21_truncate(value, result);
  if (sign == MINUS && s21_is_not_equal(value, *result)) {
    s21_decimal one;
    initial(&one);
    one.bits[LOW] = 1;
    s21_sub(*result, one, result);
  }

  set_sign(result, sign);

  return res;
}
