#include "../s21_decimal.h"

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int res = SUCCESS;

  if (isnan(src) || isinf(src)) {
    res = ERROR;
  } else {
    initial(dst);

    if (src != 0) {
      int scale = 0;
      double copy_src = (double)fabs(src);

      while (scale < SCALE_ACCURACY && (int)copy_src / (1 << 21) == 0) {
        copy_src *= 10;
        scale++;
      }

      copy_src = round(copy_src);

      while (fmod(copy_src, 10) == 0 && scale > 0) {
        scale--;
        copy_src /= 10;
      }

      float copy = copy_src;
      int fl_scale = get_bin_exp_from_float(copy);
      set_bit(dst, fl_scale, 1);

      unsigned int copy_bits;
      memcpy(&copy_bits, &copy, sizeof(float));

      for (int i = fl_scale - 1, j = BIT_EXP_FIRST - 1; j >= 0 && i >= 0;
           i--, j--) {
        if ((copy_bits & (1u << j)) != 0) set_bit(dst, i, 1);
      }

      set_scale(dst, scale);
      set_sign(dst, (src < 0) ? MINUS : PLUS);
    }
  }

  return res;
}
