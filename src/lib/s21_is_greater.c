#include "../s21_decimal.h"

int s21_is_greater(s21_decimal value_1, s21_decimal value_2) {
  int res = FALSE;

  if (!s21_is_equal(value_1, value_2)) {
    if (get_sign(value_1) < get_sign(value_2)) {
      res = is_zero(value_1) && is_zero(value_2) ? FALSE : TRUE;
    } else if ((get_sign(value_1) == PLUS) && (get_sign(value_2) == PLUS)) {
      normalization(&value_1, &value_2);
      res = comparison_mantissa(value_1, value_2) == FIRST_VALUE ? TRUE : FALSE;
    } else if ((get_sign(value_1) == MINUS) && (get_sign(value_2) == MINUS)) {
      normalization(&value_1, &value_2);
      res =
          comparison_mantissa(value_1, value_2) == SECOND_VALUE ? TRUE : FALSE;
    }
  }

  return res;
}
