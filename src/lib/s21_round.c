#include "../s21_decimal.h"

int s21_round(s21_decimal value, s21_decimal *result) {
  int res = SUCCESS;

  s21_decimal one, half, truncated, fraction;
  initial(&one);
  initial(&half);
  initial(&truncated);
  initial(&fraction);

  one.bits[LOW] = 1;
  half.bits[LOW] = 5;
  set_scale(&half, 1);

  int sign = get_sign(value);

  s21_truncate(value, &truncated);
  s21_sub(value, truncated, &fraction);

  if (sign == MINUS) s21_negate(fraction, &fraction);

  if (s21_is_greater_or_equal(fraction, half))
    sign == MINUS ? s21_sub(truncated, one, &truncated)
                  : s21_add(truncated, one, &truncated);

  *result = truncated;

  return res;
}
