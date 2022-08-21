#include "s21_math.h"

#define MANTISSA_MASK 0x000fffffffffffff  //  2^53 - 1
#define ABS_MASK 0x8000000000000000ULL  //  2^63
#define NEW_MAN_MASK 0x0010000000000000ULL  //  2^52
#define MAX_MASK 0x7fefffffffffffffULL  //  2^64 - 1

long double s21_fmod(double x, double y) {
  LD ans = 0;
  fmod_type uint_64_X = {x}; fmod_type uint_64_Y = {y};
  ULL my_abs_x = uint_64_X.u & ~ABS_MASK; ULL my_abs_y = uint_64_Y.u & ~ABS_MASK;

  int flag = check_null_fmod(x, y, my_abs_x, my_abs_y, &ans);

  if (flag == SUCCESS) {
    flag = comparison_and_equality(uint_64_X, uint_64_Y, &ans, x);

    if (flag == SUCCESS) {
      int exp_x = (int)(my_abs_x >> 52);
      int exp_y = (int)(my_abs_y >> 52);
      DLL mantis_x = (DLL)(my_abs_x & MANTISSA_MASK);
      DLL mantis_y = (DLL)(my_abs_y & MANTISSA_MASK);

      exp_x = change_exp(exp_x, &mantis_x, my_abs_x);
      exp_y = change_exp(exp_y, &mantis_y, my_abs_y);

      mantis_x |= NEW_MAN_MASK;
      mantis_y |= NEW_MAN_MASK;

      DLL mask; int deg_diff = exp_x - exp_y, shift = 0;

      change_mantissa(&mantis_x, mantis_y, &shift, &mask, &deg_diff);

      if (deg_diff < 0) {
        mantis_x += mantis_y & mask;
        mantis_x >>= 1; deg_diff = 0;
      }
      mantis_x <<= deg_diff;

      if (check_mantissa_x(mantis_x, uint_64_X, &ans) == SUCCESS) {
        shift = __builtin_clzll(mantis_x) - (64 - 53);
        mantis_x <<= shift;
        exp_y -= shift;
        mantis_x &= MANTISSA_MASK;
        mantis_x |= (DLL)(uint_64_X.u & ABS_MASK);
        if (check_exp_y(mantis_x, exp_y, uint_64_X, &ans) == SUCCESS) {
          exp_y += 1022;
          uint_64_X.u = mantis_x | ((int64_t) exp_y << 52);
          ans =  uint_64_X.d * 0x1.0p-1022;
        }
      }
    }
  }
  return ans;
}

int check_null_fmod(double x, double y, ULL my_abs_x, ULL my_abs_y, long double *ans) {
  int flag = SUCCESS;
  if (my_abs_x - 1ULL >= MAX_MASK || my_abs_y - 1ULL >= MAX_MASK) {
    double fabsx = __builtin_fabs(x);
    double fabsy = __builtin_fabs(y);

    if ( fabsx == __builtin_inf() || 0.0 == y ) { flag = NAN_FMOD; *ans = -__builtin_nan("");}
    if ( fabsy == __builtin_inf() || 0.0 == x ) { flag = X_ZERO; *ans = x;}
  }
  return flag;
}

int comparison_and_equality(fmod_type uint_64_X, fmod_type uint_64_Y, LD * ans, LD x) {
  int flag = SUCCESS;
  ULL my_abs_x = uint_64_X.u& ~ABS_MASK;
  ULL my_abs_y = uint_64_Y.u & ~ABS_MASK;

  if (my_abs_y >= my_abs_x) { flag = FAILURE; *ans = x; }
  if (my_abs_y == my_abs_x) { flag = FAILURE; uint_64_X.u ^= my_abs_x; *ans = uint_64_X.d; }
  return flag;
}

int check_mantissa_x(DLL mantis_x, fmod_type uint_64_X, LD *ans) {
  int flag = SUCCESS;
  if (0 == mantis_x) { uint_64_X.u &= ABS_MASK; flag = FAILURE; *ans = uint_64_X.d; }
  return flag;
}

int check_exp_y(DLL mantis_x, int exp_y, fmod_type uint_64_X, LD *ans) {
  int flag = SUCCESS;
  if (exp_y > 0) { uint_64_X.u = mantis_x | ((int64_t) exp_y << 52); flag = FAILURE; *ans = uint_64_X.d;
  }
  return flag;
}

int change_exp(int exp, DLL *mantis_x, ULL my_abs_x) {
  if (exp == 0) {
    unsigned int shift = __builtin_clzll(my_abs_x) - (64 - 53);
    *mantis_x <<= shift;
    exp = (int)(1 - shift);
  }
  return exp;
}

void change_mantissa(DLL *mantis_x, DLL mantis_y, int *shift, DLL *mask, int *deg_diff) {
  do {
    *mantis_x <<= *shift;
    *deg_diff += ~*shift;
    *mantis_x -= mantis_y;
    *mask = *mantis_x >> 63;
    *mantis_x += *mantis_x;
    *mantis_x += mantis_y & *mask;
    *shift = __builtin_clzll(*mantis_x) - (64 - 53);
  } while (*deg_diff >= *shift && *mantis_x != 0LL);
}
