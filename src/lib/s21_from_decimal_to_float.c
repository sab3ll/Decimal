#include "../s21_decimal.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int res = SUCCESS;

  int scale = get_scale(src);
  long long int older_bit = 0;

  for (int i = BIT_HIGH_LAST; i >= BIT_LOW_FIRST; i--) {
    if (get_bit(src, i)) {
      older_bit = i;
      break;
    }
  }

  double number = 0;
  for (int i = LOW; i <= older_bit; i++) number += pow(2, i) * get_bit(src, i);

  // int tmp_scale = 0;
  // int num_int = (int)number;

  // while (num_int % 10 != 0 || num_int) {
  //   num_int /= 10;
  //   tmp_scale++;
  // }

  // number /= pow(10, tmp_scale - scale);
  number /= pow(10, scale);

  if (get_sign(src) == MINUS) number *= -1;

  *dst = number;

  return res;
}
