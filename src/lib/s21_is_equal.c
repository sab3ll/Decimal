#include "../s21_decimal.h"

int s21_is_equal(s21_decimal value_1, s21_decimal value_2) {
  int res = TRUE;

  if (get_sign(value_1) != get_sign(value_2))
    if (!is_zero(value_1) || !is_zero(value_2))
      res = FALSE;
    else
      res = TRUE;
  else {
    normalization(&value_1, &value_2);

    for (int i = LOW; i <= HIGH && res; i++) {
      if (value_1.bits[i] != value_2.bits[i]) {
        res = FALSE;
        break;
      }
    }
  }

  return res;
}
