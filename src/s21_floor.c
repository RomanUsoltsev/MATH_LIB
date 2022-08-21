#include "s21_math.h"

long double s21_floor(double x) {
  long long int y = (long long int)(x);
  long double res;
  if (x < 0 && (x - (double) y < 0))
    res = (long double) y-1.0;
  else
    res = (long double) y;
  return res;
}
