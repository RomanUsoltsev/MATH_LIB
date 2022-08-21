#include "my_math.h"

long double my_log(double x) {
  LD sum, X = x;
  if (check_null((LD)x) == SUCCESS) {
    if (x > 0.8) {
      sum = remez_algorithm_polynom(X);
    } else if (x > 0 && x <= 0.8) {sum = -remez_algorithm_polynom(1.f / X);
    } else if ( x == 0) { sum = -__builtin_inf();
    } else { sum = -MY_NAN;}

  } else { sum = x;}
  return sum;
}

int count_log2(LD *x) {
  LD X = *x;
  int count = 0;
  ULL pow2 = 1;
  ULL mask = 2; mask = mask << 62;
  while ( X > 2) { ++count; X = X / 2;}
  for (int i = 0; i < count; ++i) {
    pow2 = pow2 << 1;
    if (pow2 == mask) {*x = *x / pow2; pow2 = 1; }
  }
  *x = *x / pow2;
  return count;
}

LD remez_algorithm_polynom(LD X) {
  LD sum = 0;
  int count = count_log2(&X);
// Remez algorithm polynom [1;2]
  sum += 1/(0.11264987354198733 + X) * (-0.4293954346081574 + X* (-0.7067066871184202 +
  X* (1.9773734306297717 +
  X* (-1.5013650143445472 + X* (1.037955085967872 + X* (-0.45244896647572186 + X* (-0.04490452854692667 +
  X* (0.28295927804127013 + X* (-0.2799806277385297 + X* (0.17278320297435368 + X* (-0.07560317237275387 +
  X* (0.024029167619612213 + X* (-0.005466520209606878 + X* (0.0008477752057801314 +
  (-0.00008053118456379199 + 0.0000035421605687533005 *X) *X))))))))))))));
  sum += count * MY_LOG2;
  return sum;
}

int check_null(LD x) {
  int flag = SUCCESS;
  if (__builtin_isnan(x) == 1 || x == MY_INFINITY || x == - MY_INFINITY) { flag = FAILURE;}
  return flag;
}
