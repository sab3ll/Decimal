#include "../s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int res = OK;

  s21_bigdec val_1, val_2, res_big;

  initial_bigdec(&val_1);
  initial_bigdec(&val_2);
  initial_bigdec(&res_big);

  from_decimal_to_bigdec(value_1, &val_1);
  from_decimal_to_bigdec(value_2, &val_2);
  normalization_bigdec(&val_1, &val_2);

  int res_scale = fmax(get_scale_bigdec(val_1), get_scale_bigdec(val_2));

  if (get_sign_bigdec(val_1) == get_sign_bigdec(val_2)) {
    bitwise_add(val_1, val_2, &res_big);
    set_sign_bigdec(&res_big, get_sign_bigdec(val_1));
  } else if (comparison_mantissa_bigdec(val_1, val_2) == FIRST_VALUE) {
    bitwise_sub(val_1, val_2, &res_big);
    set_sign_bigdec(&res_big, get_sign_bigdec(val_1));
  } else if (comparison_mantissa_bigdec(val_1, val_2) == SECOND_VALUE) {
    bitwise_sub(val_2, val_1, &res_big);
    set_sign_bigdec(&res_big, get_sign_bigdec(val_2));
  }

  set_scale_bigdec(&res_big, res_scale);

  res = from_bigdec_to_decimal(&res_big, result);
  if (res == POS_INF && get_sign_bigdec(res_big) == MINUS) res = NEG_INF;

  return res;
}
