#include "s21_math.h"

long double s21_asin(double x) {
  long double sum = 0;
  long double y = 0, z, arcinus, result; int flag = 0;
  if (x < 0 && x != -1) {
    flag = 1;
    y = (long double)-x;
  } else if (x > 0 && x != 1) {
    flag = 1;
    y = (long double)x;
  }
  if (y <= 0.5 && flag == 1) {
    for (unsigned int i = 0; i <= 20; i++) {
      z = (long double)(fact(2*i)*s21_pow(y, (2*i+1))/(s21_pow(4, i)*fact(i)*fact(i)*(2*i + 1)));
      sum = sum + z;
    }
    arcinus = sum;
  } else {
    long double w = s21_sqrt((1-y)/2);
    for (unsigned int i = 0; i <= 20; i++) {
      z = (long double)(fact(2*i)*s21_pow(w, (2*i+1))/(s21_pow(4, i)*fact(i)*fact(i)*(2*i + 1)));
      sum = sum + z;
    }
    arcinus = S21_PI2 - 2*sum;
  }
  if (x < 0 && x != -1) {
    result = -arcinus;
  } else if (x == -1) {
    result = -S21_PI2;
  } else if (x == 1) {
    result = S21_PI2;
  } else {
    result = arcinus;
  }
  return (x <= 1 && x >= -1) ? result : S21_NAN;
}

unsigned long long fact(unsigned long long x) {
  return (x == 0) ? 1 : fact(x-1)*x;
}
