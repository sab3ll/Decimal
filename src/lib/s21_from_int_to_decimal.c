#include "../s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int res = SUCCESS;

  initial(dst);

  if (src < 0) {
    src *= -1;
    set_sign(dst, MINUS);
  }

  dst->bits[LOW] = src;

  return res;
}
