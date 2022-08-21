#include "s21_math.h"

long double s21_exp(double x) {
  LD sum, X = x;
  if (check_null((LD)x) == SUCCESS) {
    if (x != S21_INFINITY && x != S21_NAN) {
      sum = remez_algorithm_polynom_exp(X);
    } else { sum = -x;}

  } else {
    if (x == -S21_INFINITY) {
      sum = 0;
    } else {
      sum = x;
    }
    }

  return sum;
}


LD remez_algorithm_polynom_exp(LD X) {
  LD sum = 0;
  int sign = 0;
  if (X < 0) { X = -X; sign = 1;}
  int count = count_2_pow(&X);

// Remez algorithm polynom [0;1]
  sum += (1/(-10.503730733730627 + X)) * (-10.503730733730613 + X* (-9.503730733733716 +
      X* (-4.2518653667317245 +X* (-1.2506217911561137 + X* (-0.27098876230536484 +
          X* (-0.04586450997866506 + X* (-0.006254925509907162 +
              X* (-0.0006956603304410819 + (-0.00006154085870107144 - 0.000004531732488392385 *X) *X))))))));
  sum *=  pow_bin(count);
  sum = sign == 0 ?  sum : 1.0f / sum;
  return sum;
}

int count_2_pow(LD *x) {
  LD X = *x;
  int count = 0;
  while ( X > 1) { ++count; X = X - S21_LOG2; }
  *x = *x - count * S21_LOG2;
  return count;
}

LD pow_bin(int power) {
  ULL value = 1, mask = 2;
  mask = mask << 62;
  LD sum = 1;
  for (int i = 0; i < power; ++i) {
    value = value << 1;
    if (value == mask) { sum *= value; value = 1;}
  }
  sum *= value;
  return sum;
}
