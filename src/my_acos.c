#include "my_math.h"

long double my_acos(double x) {
  return MY_PI2 - my_asin(x);
}
