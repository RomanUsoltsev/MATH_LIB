//
// Created by roman on 31.01.2022.
//


#include "debug_fun.h"

int check_fun(int mode, unsigned int seed,
              long long int i_min, long long int j_min, long long int i_max, long long int j_max) {
  int flag = SUCCESS;
  for (long long int i = i_min; i < i_max; ++i) {
    for (long long int j = j_min; j < j_max; ++j) {
      double b, a;
      if (mode == TST_LN) {
        b  = (double)pow(i, j);
      } else {
        b = i;
      }
      a = j;
      if (mode == TST_POW) {b = i_max; a =j;}

      if (seed != 0) { b /= rand_r(&seed); }
      LD sum_1 = 0;
      LD sum_2 = change_sum(mode, b, a, &sum_1);
      LD err = sum_1 - sum_2;
      err = err < 0 ? -err : err;
      if (mode != TST_TAN && mode != TST_EXP && mode != TST_POW) {
        if (err > 0.000001) {
          flag = FAILURE;
          printf("TRY - |%.20Lf|\nMMY - |%.20Lf|\nERR - |%.20Lf|\n"
                 "BBB - |%f|\nAAA - |%f|\n\n", sum_1, sum_2, err, b, a);
          break;
        }
      } else if (mode == TST_POW || mode == TST_EXP) {
        char buff_1[500] = {0};
        char buff_2[500] = {0};
        snprintf(buff_1, sizeof(buff_1), "%.20Lf", sum_1);
        snprintf(buff_2, sizeof(buff_2), "%.20Lf", sum_2);
        flag = smp_str(buff_1, buff_2);
        if (flag != SUCCESS) {
          break;
        }
      }
    }
    if (flag != SUCCESS) {
      break;
    }
  }
  return flag;
}
int smp_str(const char *buff_1, const char *buff_2) {
  int flag = SUCCESS;
  for (int i = 0; i < 15; ++i) {
    if (buff_1[i] != buff_2[i]) {
      flag = FAILURE;
      break;
    }
  }
  return flag;
}
LD change_sum(int mode, LD b, LD a, LD *sum_1) {
  LD sum_2 = 0;
  switch (mode) {
    case TST_LN:
      * sum_1 = ST_LN; sum_2 = S21_LN; break;
    case TST_EXP:
      *sum_1 = ST_EXP; sum_2 = S21_EXP; break;
    case TST_POW:
      *sum_1 = ST_POW; sum_2 = S21_POW; break;
    case TST_SQRT:
      *sum_1 = ST_SQRT; sum_2 = S21_SQRT; break;
    case TST_COS:
      *sum_1 = ST_COS; sum_2 = S21_COS; break;
    case TST_SIN:
      *sum_1 = ST_SIN; sum_2 = S21_SIN; break;
    case TST_TAN:
      *sum_1 = ST_TAN; sum_2 = S21_TAN; break;
    case TST_FMOD:
      *sum_1 = ST_FMOD; sum_2 = S21_FMOD; break;
    default:
      *sum_1 = MY_INFINITY;
  }
  return sum_2;
}
