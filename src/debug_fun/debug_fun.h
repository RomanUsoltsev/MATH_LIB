//
// Created by roman on 31.01.2022.
//

#ifndef SRC_DEBUG_FUN_DEBUG_FUN_H_
#define SRC_DEBUG_FUN_DEBUG_FUN_H_
#include "../my_math.h"
#include <stdlib.h>
#include <math.h>
// DEBUG_FUN________________________________DEBUG_FUN
#define TST_LN 0
#define TST_EXP 1
#define TST_POW 2
#define TST_SQRT 3
#define TST_COS 4
#define TST_SIN 5
#define TST_TAN 6
#define TST_FMOD 7

#define ST_LN log(b)
#define ST_EXP exp(b)
#define ST_POW pow(b, a)
#define ST_SQRT sqrt(b)
#define ST_COS cos(b)
#define ST_SIN sin(b)
#define ST_TAN tan(b)
#define ST_FMOD fmod(b, a)

#define S21_LN my_log(b)
#define S21_EXP my_exp(b)
#define S21_POW my_pow(b, a)
#define S21_SQRT my_sqrt(b)
#define S21_COS my_cos(b)
#define S21_SIN my_sin(b)
#define S21_TAN my_tan(b)
#define S21_FMOD my_fmod(b, a)

LD change_sum(int mode, LD b, LD a, LD *sum_1);
int check_fun(int mode, unsigned int seed,
              long long int i_min,
              long long int j_min,
              long long int i_max,
              long long int j_max);
int smp_str(const char *buff_1, const char *buff_2);
// DEBUG_FUN________________________________DEBUG_FUN

#endif  // SRC_DEBUG_FUN_DEBUG_FUN_H_
