#include "s21_math.h"

long double s21_pow(double base, double exp) {
  LD sum = exceptions_pow(base, exp);
  int flag = (int)sum;
  if (flag == SUCCESS * MULT) {
    int sign = 1;
    long long int exp_int = (long long int) (exp);
    if (base < 0) {
      base = -base;
      if (exp_int % 2 != 0) { sign = -sign; }
    }
      sum = sign * s21_exp((double) (exp * s21_log(base)));
  }
  return sum;
}

LD exceptions_pow(double x, double y) {
  int flag_ = SUCCESS * MULT;
  long long int y_ = (long long int)y;
  LD _y_ = y_;
  union fmod_d_i X_ = {.d = x};

  if (x == 1) {return 1;}
  if (y == 0) {return  1;}
  if (x == 0.f && ((X_.u >> 63) == 0 || (X_.u >> 63) == 1) && y_ % 2 != 0 && y > 0) {return x;}
  if (x == 0 && y_ % 2 == 0 && y > 0) {return 0;}
  if (x == -1 && (y == S21_INFINITY || y == -S21_INFINITY)) {return 1;}
  if (s21_fabs(x) < 1 && y == -S21_INFINITY) {return S21_INFINITY;}
  if (s21_fabs(x) > 1 && y == -S21_INFINITY) {return +0.f;}
  if (s21_fabs(x) < 1 && y == S21_INFINITY) { return +0.f;}
  if (s21_fabs(x) > 1 && y == S21_INFINITY) {return S21_INFINITY;}
  if (x == -S21_INFINITY && y_ % 2 != 0 && y == _y_ && y < 0) {return -0.f;}
  if (x == -S21_INFINITY && y_ % 2 == 0 && y == _y_ && y < 0) {return +0.f;}
  if (x == -S21_INFINITY && y_ % 2 != 0 && y == _y_ && y > 0) {return -S21_INFINITY;}
  if (x == -S21_INFINITY && y_ % 2 == 0 && y == _y_ && y > 0) {return S21_INFINITY;}
  if (x == S21_INFINITY && y < 0) {return +0.f;}
  if (x == S21_INFINITY && y > 0) {return S21_INFINITY;}


  if (x == 0.f && (X_.u >> 63) == 0  && y_ % 2 != 0 && y == _y_ && y < 0) { return S21_HUGE_VALF;}
  if (x == 0.f && (X_.u >> 63) == 1  && y_ % 2 != 0 && y == _y_ && y < 0) { return -S21_HUGE_VALF;}
  if (x == 0.f && ((X_.u >> 63) == 0 || (X_.u >> 63) == 1) && y_ % 2 == 0 && y == _y_ && y < 0) {
    return S21_HUGE_VALF;
  }

//  ERROR___________________________ERROR
  if (x != 0 && (X_.u >> 63) == 1 && y != _y_) {return -S21_NAN;}
  if (x == 0  && y < 0) {return S21_INFINITY;}
//  ERROR___________________________ERROR

  if (__builtin_isnan(x) == 1 || __builtin_isnan(y) == 1) {return S21_NAN;}
  return flag_;
}
