#include "../s21_decimal.h"

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int res = OK;

  s21_bigdec val_1, val_2, res_big;
  initial_bigdec(&val_1);
  initial_bigdec(&val_2);
  initial_bigdec(&res_big);
  initial(result);

  from_decimal_to_bigdec(value_1, &val_1);
  from_decimal_to_bigdec(value_2, &val_2);
  normalization_bigdec(&val_1, &val_2);

  if (is_one_bigdec(val_2) && !is_zero_bigdec(val_1)) {
    res = OK;
    copy_decimal(value_1, result);
  } else if (is_one_bigdec(val_2) && is_zero_bigdec(val_1)) {
    res = OK;
    result->bits[LOW] = 0;
  } else if (is_zero_bigdec(val_2))
    res = DIV_BY_ZERO;
  else if (is_zero_bigdec(val_1))
    res = OK;
  else if (comparison_mantissa_bigdec(val_1, val_2) == EQUAL &&
           get_scale_bigdec(val_1) == get_scale_bigdec(val_2)) {
    res = OK;
    result->bits[LOW] = 1;
  } else {
    div_res div_result = bitwise_div(val_1, val_2);
    copy_bigdec(div_result.quotient, &res_big);

    s21_bigdec remainder = div_result.remainder;

    if (!is_zero_bigdec(remainder)) {
      int accuracy = 0;

      while (!is_zero_bigdec(remainder) && accuracy <= SCALE_ACCURACY) {
        if (comparison_mantissa_bigdec(remainder, val_2) == SECOND_VALUE) {
          multiply_by_num_bigdec(&remainder, 10);

          if (comparison_mantissa_bigdec(remainder, val_2) == SECOND_VALUE) {
            multiply_by_num_bigdec(&remainder, 10);
            multiply_by_num_bigdec(&res_big, 10);
            accuracy++;
          }

          div_res new_div_result = bitwise_div(remainder, val_2);
          multiply_by_num_bigdec(&res_big, 10);

          bitwise_add(res_big, new_div_result.quotient, &res_big);
          copy_bigdec(new_div_result.remainder, &remainder);

          accuracy++;
          set_scale_bigdec(&res_big, accuracy);

          if (is_zero_bigdec(new_div_result.remainder)) break;
        }
      }
    }

    res = from_bigdec_to_decimal(&res_big, result);
  }

  if (get_sign(value_1) == MINUS && get_sign(value_2) == MINUS)
    set_sign(result, PLUS);
  else if (get_sign(value_1) == MINUS || get_sign(value_2) == MINUS)
    set_sign(result, MINUS);
  else
    set_sign(result, PLUS);

  return res;
}
