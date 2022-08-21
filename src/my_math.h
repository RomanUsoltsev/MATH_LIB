#ifndef SRC_MY_MATH_H_
#define SRC_MY_MATH_H_

#include <stdio.h>
#include <float.h>
#include <stdint.h>
#include <stdlib.h>

#define ULL unsigned long long int
#define DLL long long int
#define LD long double
#define SUCCESS 1
#define FAILURE 0
#define MULT 1000
#define MY_INFINITY (__builtin_inff ())
#define MY_NEGATIVE_INFINITY -(__builtin_inff ())
#define MY_NAN (__builtin_nanf (""))
#  define MY_HUGE_VALF (__builtin_huge_valf ())

#define MY_LOG2 0.6931471805599453094172321214581765680755
#define MY_PI3 6.283185307179586476925286766559005768394
#define MY_PI2 1.570796326794896619231321691639751442L
#define MY_PI 3.141592653589793238462643383279502884L
typedef union fmod_d_i {
  double d;
  ULL u;
}fmod_type;

#define NAN_FMOD 10
#define X_ZERO 20


long int my_abs(int x);
long double my_acos(double x);
long double my_asin(double x);
long double my_atan(double x);
long double my_ceil(double x);
long double my_cos(double x);
long double my_exp(double x);
long double my_fabs(double x);
long double my_floor(double x);

long double my_fmod(double x, double y);
int check_null_fmod(double x, double y, ULL my_abs_x, ULL my_abs_y, long double *ans);
int change_exp(int exp, DLL *mantis_x, ULL my_abs_x);
void change_mantissa(DLL *mantis_x, DLL mantis_y, int *shift, DLL *mask, int *deg_diff);
int comparison_and_equality(fmod_type uint_64_X, fmod_type uint_64_Y, LD * ans, LD x);
int check_mantissa_x(DLL mantis_x, fmod_type uint_64_X, LD *ans);
int check_exp_y(DLL mantis_x, int exp_y, fmod_type uint_64_X, LD *ans);

long double my_log(double x);
LD remez_algorithm_polynom(LD X);
int count_log2(LD *x);
int check_null(LD x);

long double my_pow(double base, double exp);
LD exceptions_pow(double x, double y);
long double my_sin(double x);
long double my_sqrt(double x);
long double my_tan(double x);


LD remez_algorithm_polynom_exp(LD X);
int count_2_pow(LD *x);
LD pow_bin(int power);

unsigned long long fact(unsigned long long x);

#endif  //  SRC_MY_MATH_H_
