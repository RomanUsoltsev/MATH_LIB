#include "s21_math.h"

long double s21_atan(double x) {
  return s21_asin(x/s21_sqrt(1+s21_pow(x, 2)));
}
