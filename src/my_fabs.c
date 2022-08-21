#include "my_math.h"

long double my_fabs(double x) {
  fmod_type X_ = {.d = x};
  if ((X_.u >> 63) == 1) { x = -x;}
  return x;
}
