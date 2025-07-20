#include "../s21_decimal.h"

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int res = OK;

  initial(result);

  s21_bigdec val_1, val_2, res_big;
  initial_bigdec(&val_1);
  initial_bigdec(&val_2);
  initial_bigdec(&res_big);

  from_decimal_to_bigdec(value_1, &val_1);
  from_decimal_to_bigdec(value_2, &val_2);
  normalization_bigdec(&val_1, &val_2);

  if (is_one_bigdec(val_1) || is_one_bigdec(val_2)) {
    if (is_one_bigdec(val_1))
      copy_decimal(value_2, result);
    else if (is_one_bigdec(val_2))
      copy_decimal(value_1, result);

    if (get_sign(value_1) == MINUS && get_sign(value_2) == MINUS)
      set_sign(result, PLUS);
    else if (get_sign(value_1) == MINUS || get_sign(value_2) == MINUS)
      set_sign(result, MINUS);
    else
      set_sign(result, PLUS);
  } else {
    if (comparison_mantissa_bigdec(val_1, val_2) == SECOND_VALUE)
      bitwise_mul(val_2, val_1, &res_big);
    else if (comparison_mantissa_bigdec(val_1, val_2) == FIRST_VALUE)
      bitwise_mul(val_1, val_2, &res_big);

    if (comparison_mantissa_bigdec(val_1, val_2) != EQUAL) {
      set_scale_bigdec(&res_big,
                       get_scale_bigdec(val_1) + get_scale_bigdec(val_2));
      if (get_sign(value_1) == MINUS && get_sign(value_2) == MINUS)
        set_sign_bigdec(&res_big, PLUS);
      else if (get_sign(value_1) == MINUS || get_sign(value_2) == MINUS)
        set_sign_bigdec(&res_big, MINUS);
      else
        set_sign_bigdec(&res_big, PLUS);

      res = from_bigdec_to_decimal(&res_big, result);
    }
  }

  return res;
}
