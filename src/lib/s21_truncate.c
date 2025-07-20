#include "../s21_decimal.h"

int s21_truncate(s21_decimal value, s21_decimal *result) {
  int res = ERROR;
  int scale = get_scale(value);

  uint64_t curr_val, rem = 0;

  while (scale > 0) {
    for (int i = HIGH; i >= LOW; i--) {
      curr_val = value.bits[i];

      curr_val += rem << INT_BIT_QUANTITY;
      rem = curr_val % 10;
      curr_val /= 10;

      value.bits[i] = curr_val;
    }

    scale--;
    rem = 0;
  }

  set_scale(&value, 0);
  *result = value;

  res = SUCCESS;

  return res;
}
