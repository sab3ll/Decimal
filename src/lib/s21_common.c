#include "../s21_decimal.h"

int get_bit(s21_decimal value, int bit_index) {
  int i = bit_index / INT_BIT_QUANTITY;
  bit_index -= (i * INT_BIT_QUANTITY);

  return (value.bits[i] & (1 << bit_index)) >> bit_index;
}

int get_bit_bigdec(s21_bigdec value, int bit_index) {
  int i = bit_index / INT_BIT_QUANTITY;
  bit_index -= (i * INT_BIT_QUANTITY);

  return (value.bits[i] & (1 << bit_index)) >> bit_index;
}

int set_bit(s21_decimal *value, int bit_index, unsigned int bit_value) {
  int err = FALSE;

  if (bit_value == 0 || bit_value == 1) {
    int i = bit_index / INT_BIT_QUANTITY;
    bit_index -= (i * INT_BIT_QUANTITY);

    if (bit_value == 1) value->bits[i] |= (1 << bit_index);
    if (bit_value == 0) value->bits[i] &= (~(1 << bit_index));
  } else
    err = TRUE;

  return err;
}

int set_bit_bigdec(s21_bigdec *value, int bit_index, unsigned int bit_value) {
  int err = FALSE;

  if (bit_value == 0 || bit_value == 1) {
    int i = bit_index / INT_BIT_QUANTITY;
    bit_index -= (i * INT_BIT_QUANTITY);

    if (bit_value == 1) value->bits[i] |= (1 << bit_index);
    if (bit_value == 0) value->bits[i] &= (~(1 << bit_index));
  } else
    err = TRUE;

  return err;
}

void initial(s21_decimal *value) {
  for (unsigned int i = LOW; i <= OLDER; i++) value->bits[i] = 0;
}

void initial_bigdec(s21_bigdec *value) {
  for (unsigned int i = 0; i < BIGDEC_SIZE; i++) value->bits[i] = 0;
  set_sign_bigdec(value, PLUS);
  set_scale_bigdec(value, 0);
}

int get_sign(s21_decimal value) { return get_bit(value, BIT_OLDER_LAST); }

int get_sign_bigdec(s21_bigdec value) { return value.sign; }

int set_sign(s21_decimal *value, unsigned int sign) {
  int err = FALSE;

  sign > 1 ? err = TRUE : set_bit(value, BIT_OLDER_LAST, sign);

  return err;
}

int set_sign_bigdec(s21_bigdec *value, unsigned int sign) {
  int err = FALSE;

  sign > 1 ? err = TRUE : (value->sign = sign);

  return err;
}

int get_scale(s21_decimal value) {
  return (value.bits[OLDER] & MASK_SCALE) >> BIT_SCALE_FIRST;
}

int get_scale_bigdec(s21_bigdec value) { return value.scale; }

int set_scale(s21_decimal *value, unsigned int scale) {
  unsigned int sign = get_sign(*value);

  value->bits[OLDER] = (scale << BIT_SCALE_FIRST) & MASK_SCALE;
  set_sign(value, sign);

  return get_scale(*value);
}

int set_scale_bigdec(s21_bigdec *value, unsigned int scale) {
  value->scale = scale;

  return value->scale;
}

int get_bin_exp_from_float(float value) {
  unsigned int float_bits;
  memcpy(&float_bits, &value, sizeof(float));
  return ((float_bits & MASK_FLOAT_EXP) >> BIT_EXP_FIRST) - FLOAT_EXP_CONST;
}

int is_zero(s21_decimal value) {
  int res = TRUE;

  for (int i = LOW; i <= HIGH; i++) {
    if (value.bits[i] != 0) {
      res = FALSE;
      break;
    }
  }

  return res;
}

int is_zero_bigdec(s21_bigdec value) {
  int res = TRUE;

  for (int i = LOW; i < BIGDEC_SIZE; i++) {
    if (value.bits[i] != 0) {
      res = FALSE;
      break;
    }
  }

  return res;
}

int is_one_bigdec(s21_bigdec value) {
  int res = FALSE;

  if (value.bits[LOW] == 1) res = TRUE;

  for (int i = LOW + 1; i < BIGDEC_SIZE; ++i)
    if (value.bits[i] != 0) res = FALSE;

  return res;
}

int comparison_mantissa(s21_decimal value_1, s21_decimal value_2) {
  int res = EQUAL;

  for (int i = BIT_HIGH_LAST; i >= BIT_LOW_FIRST; --i) {
    int bit1 = get_bit(value_1, i);
    int bit2 = get_bit(value_2, i);

    if (bit1 > bit2) {
      res = FIRST_VALUE;
      break;
    } else if (bit1 < bit2) {
      res = SECOND_VALUE;
      break;
    }
  }

  return res;
}

int comparison_mantissa_bigdec(s21_bigdec value_1, s21_bigdec value_2) {
  int res = EQUAL;

  for (int i = BIT_BIGDEC_LAST; i >= BIT_LOW_FIRST; --i) {
    int bit1 = get_bit_bigdec(value_1, i);
    int bit2 = get_bit_bigdec(value_2, i);

    if (bit1 > bit2) {
      res = FIRST_VALUE;
      break;
    } else if (bit1 < bit2) {
      res = SECOND_VALUE;
      break;
    }
  }

  return res;
}

void shift_bigdec(s21_bigdec *value, int direction) {
  if (direction == LEFT || direction == RIGHT) {
    s21_bigdec shifted = *value;

    switch (direction) {
      case LEFT: {
        for (int i = LOW; i <= BIGDEC_SIZE - 1; i++) shifted.bits[i] <<= 1;

        for (int j = INT_BIT_QUANTITY - 1; j <= BIT_BIGDEC_LAST + 1;
             j += INT_BIT_QUANTITY)
          set_bit_bigdec(&shifted, j + 1, get_bit_bigdec(*value, j));

        break;
      }
      case RIGHT: {
        for (int i = BIGDEC_SIZE - 1; i >= LOW; i--) shifted.bits[i] >>= 1;

        for (int j = BIT_BIGDEC_LAST - INT_BIT_QUANTITY + 1; j > 0;
             j -= INT_BIT_QUANTITY)
          set_bit_bigdec(&shifted, j - 1, get_bit_bigdec(*value, j));

        break;
      }
    }

    *value = shifted;
  }
}

void shift_by_num_bigdec(s21_bigdec *value, int direction, unsigned int count) {
  while (count) {
    shift_bigdec(value, direction);
    count--;
  }
}

void multiply_by_num(s21_decimal *value, unsigned int num) {
  uint64_t rem = 0;

  for (int i = LOW; i <= HIGH; i++) {
    uint64_t tmp_u = value->bits[i];
    tmp_u *= num;
    tmp_u += rem;
    rem = tmp_u >> INT_BIT_QUANTITY;

    value->bits[i] = tmp_u;
  }
}

void multiply_by_ten_bigdec(s21_bigdec *value) {
  uint64_t rem = 0;

  for (int i = LOW; i <= BIGDEC_SIZE - 1; i++) {
    uint64_t tmp_u = value->bits[i];
    tmp_u *= 10;
    tmp_u += rem;
    rem = tmp_u >> INT_BIT_QUANTITY;

    value->bits[i] = tmp_u;
  }
}

void multiply_by_num_bigdec(s21_bigdec *value, unsigned int num) {
  uint64_t rem = 0;

  for (int i = LOW; i <= BIGDEC_SIZE - 1; i++) {
    uint64_t tmp_u = value->bits[i];
    tmp_u *= num;
    tmp_u += rem;
    rem = tmp_u >> INT_BIT_QUANTITY;

    value->bits[i] = tmp_u;
  }
}

void division_by_ten_bigdec(s21_bigdec *value) {
  uint64_t tmp_u, rem = 0;

  for (int i = BIGDEC_SIZE - 1; i >= LOW; i--) {
    tmp_u = value->bits[i];
    tmp_u |= rem << INT_BIT_QUANTITY;
    rem = tmp_u % 10;
    tmp_u /= 10;

    value->bits[i] = UINT_MAX & tmp_u;
  }

  if (rem > 4) value->bits[0] += 1;
}

void normalization(s21_decimal *value_1, s21_decimal *value_2) {
  int scale_1 = get_scale(*value_1);
  int scale_2 = get_scale(*value_2);

  while (scale_1 != scale_2) {
    if (scale_1 > scale_2 && scale_2 < SCALE_ACCURACY) {
      multiply_by_num(value_2, 10);
      scale_2++;
    } else if (scale_1 < scale_2 && scale_1 < SCALE_ACCURACY) {
      multiply_by_num(value_1, 10);
      scale_1++;
    }
  }

  set_scale(value_1, scale_1);
  set_scale(value_2, scale_2);
}

void normalization_bigdec(s21_bigdec *value_1, s21_bigdec *value_2) {
  int scale_1 = get_scale_bigdec(*value_1);
  int scale_2 = get_scale_bigdec(*value_2);

  while (scale_1 != scale_2) {
    if (scale_1 > scale_2) {
      multiply_by_num_bigdec(value_2, 10);
      scale_2++;
    } else {
      multiply_by_ten_bigdec(value_1);
      scale_1++;
    }
  }

  set_scale_bigdec(value_1, scale_1);
  set_scale_bigdec(value_2, scale_2);
}

void bitwise_add(s21_bigdec value_1, s21_bigdec value_2, s21_bigdec *result) {
  int transfer = 0;

  for (int i = BIT_LOW_FIRST; i <= BIT_BIGDEC_LAST; ++i) {
    uint64_t sum = 0;
    sum = get_bit_bigdec(value_1, i) + get_bit_bigdec(value_2, i) + transfer;

    if (!sum) {
      set_bit_bigdec(result, i, 0);
      transfer = 0;
    } else if (sum == 1) {
      set_bit_bigdec(result, i, 1);
      transfer = 0;
    } else if (sum == 2) {
      set_bit_bigdec(result, i, 0);
      transfer = 1;
    } else if (sum == 3) {
      set_bit_bigdec(result, i, 1);
      transfer = 1;
    }
  }
}

void bitwise_sub(s21_bigdec value_1, s21_bigdec value_2, s21_bigdec *result) {
  for (int i = BIT_LOW_FIRST; i <= BIT_BIGDEC_LAST; i++) {
    int cur_bit_1 = get_bit_bigdec(value_1, i);
    int cur_bit_2 = get_bit_bigdec(value_2, i);
    int n = i;

    if (cur_bit_1 < cur_bit_2) {
      n = i;

      if (get_bit_bigdec(value_1, n) == 0) {
        while (get_bit_bigdec(value_1, n) == 0) {
          set_bit_bigdec(&value_1, n, 1);
          n++;
        }

        set_bit_bigdec(&value_1, n, 0);
      }

      set_bit_bigdec(result, i, 1);
    } else
      set_bit_bigdec(result, i, cur_bit_1 - cur_bit_2);
  }
}

void bitwise_mul(s21_bigdec value_1, s21_bigdec value_2, s21_bigdec *result) {
  s21_bigdec tmp;
  initial_bigdec(&tmp);
  set_scale_bigdec(&tmp, get_scale_bigdec(value_1));

  for (int i = BIT_LOW_FIRST; i <= BIT_BIGDEC_LAST; i++) {
    s21_bigdec tmp_val = value_2;

    if (get_bit_bigdec(value_1, i)) {
      shift_by_num_bigdec(&tmp_val, LEFT, i);
      bitwise_add(tmp, tmp_val, &tmp);
    }
  }

  *result = tmp;
}

div_res bitwise_div(s21_bigdec value_1, s21_bigdec value_2) {
  div_res res;

  s21_bigdec quotient;
  s21_bigdec remainder;
  initial_bigdec(&quotient);
  initial_bigdec(&remainder);

  for (int i = BIT_BIGDEC_LAST; i >= 0; i--) {
    shift_bigdec(&remainder, LEFT);

    set_bit_bigdec(&remainder, 0, get_bit_bigdec(value_1, i));

    if (comparison_mantissa_bigdec(remainder, value_2) != SECOND_VALUE) {
      bitwise_sub(remainder, value_2, &remainder);
      set_bit_bigdec(&quotient, i, 1);
    }
  }

  res.quotient = quotient;
  res.remainder = remainder;

  return res;
}

void from_decimal_to_bigdec(s21_decimal src, s21_bigdec *value) {
  initial_bigdec(value);

  for (unsigned int i = LOW; i <= HIGH; i++) value->bits[i] = src.bits[i];
  set_sign_bigdec(value, get_sign(src));
  set_scale_bigdec(value, get_scale(src));
}

int from_bigdec_to_decimal(s21_bigdec *src, s21_decimal *value) {
  int res = OK;

  initial(value);

  while (src->scale > SCALE_ACCURACY) {
    division_by_ten_bigdec(src);
    --src->scale;
  }

  if (get_scale_bigdec(*src) < 0 && get_sign_bigdec(*src) == PLUS)
    res = POS_INF;

  for (int i = BIGDEC_SIZE - 1; i >= OLDER; --i)
    if (src->bits[i]) {
      if (get_sign_bigdec(*src) == PLUS)
        res = POS_INF;
      else
        res = NEG_INF;
      break;
    }

  set_scale(value, get_scale_bigdec(*src));

  for (int i = LOW; i <= HIGH; i++) value->bits[i] = src->bits[i];

  set_sign(value, get_sign_bigdec(*src));

  return res;
}

void copy_decimal(s21_decimal src, s21_decimal *value) {
  for (int i = LOW; i <= OLDER; ++i) value->bits[i] = src.bits[i];
}

void copy_bigdec(s21_bigdec src, s21_bigdec *value) {
  for (int i = LOW; i < BIGDEC_SIZE; ++i) value->bits[i] = src.bits[i];
}
