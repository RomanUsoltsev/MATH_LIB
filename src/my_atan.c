#include "my_math.h"

long double my_atan(double x) {
  return my_asin(x / my_sqrt(1 + my_pow(x, 2)));
}
