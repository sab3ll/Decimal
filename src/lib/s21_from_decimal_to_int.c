#include "../s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int res = SUCCESS;

  if (src.bits[LOW] > UINT_MAX || src.bits[MID] || src.bits[HIGH])
    res = ERROR;
  else {
    s21_truncate(src, &src);
    *dst = src.bits[LOW];

    int scale = get_scale(src);
    if (scale > 0 && scale <= SCALE_ACCURACY) *dst = *dst / pow(10, scale);

    if (get_sign(src)) *dst = *dst * (-1);
  }

  return res;
}
