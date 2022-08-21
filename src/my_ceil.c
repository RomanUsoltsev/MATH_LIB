#include "my_math.h"

long double my_ceil(double x) {
  long long int y = (long long int)(x);
  long double res;
  if (x >= 0 && (x - (double) y > 0))
    res = (long double) y+1.0;
  else
    res = (long double) y;
  return res;
}
