//
// Created by roman on 10.02.2022.
//
#include "../s21_math.h"
#include "../debug_fun/debug_fun.h"
#include <math.h>
int main() {
  printf("TEST_1\n");
  double x_1 = S21_NAN;
  double y_1 = 1;
  LD sum_11 = pow(x_1, y_1);
  LD sum_21 = s21_pow(x_1, y_1);
  printf("TRY - |%.20Lf|\nMYY - |%.20Lf|\n\n", sum_11, sum_21);
  printf("TEST_2\n");
  x_1 = 1;
  y_1 = 5;
  sum_11 = pow(x_1, y_1);
  sum_21 = s21_pow(x_1, y_1);
  printf("TRY - |%.20Lf|\nMYY - |%.20Lf|\n\n", sum_11, sum_21);

  x_1 = 1;
  y_1 = NAN;
  sum_11 = pow(x_1, y_1);
  sum_21 = s21_pow(x_1, y_1);
  printf("TRY - |%.20Lf|\nMYY - |%.20Lf|\n\n", sum_11, sum_21);

  x_1 = 1;
  y_1 = INFINITY;
  sum_11 = pow(x_1, y_1);
  sum_21 = s21_pow(x_1, y_1);
  printf("TRY - |%.20Lf|\nMYY - |%.20Lf|\n\n", sum_11, sum_21);

  x_1 = 5;
  y_1 = INFINITY;
  sum_11 = pow(x_1, y_1);
  sum_21 = s21_pow(x_1, y_1);
  printf("TRY - |%.20Lf|\nMYY - |%.20Lf|\n\n", sum_11, sum_21);
  printf("TEST_3\n");
  x_1 = S21_NAN;
  y_1 = 0;
  sum_11 = pow(x_1, y_1);
  sum_21 = s21_pow(x_1, y_1);
  printf("TRY - |%.20Lf|\nMYY - |%.20Lf|\n\n", sum_11, sum_21);

  x_1 = S21_INFINITY;
  y_1 = 0;
  sum_11 = pow(x_1, y_1);
  sum_21 = s21_pow(x_1, y_1);
  printf("TRY - |%.20Lf|\nMYY - |%.20Lf|\n\n", sum_11, sum_21);

  x_1 = -S21_INFINITY;
  y_1 = 0;
  sum_11 = pow(x_1, y_1);
  sum_21 = s21_pow(x_1, y_1);
  printf("TRY - |%.20Lf|\nMYY - |%.20Lf|\n\n", sum_11, sum_21);

  printf("TEST_4\n");
  x_1 = +0.f;
  y_1 = 3;
  sum_11 = pow(x_1, y_1);
  sum_21 = s21_pow(x_1, y_1);
  printf("TRY - |%.20Lf|\nMYY - |%.20Lf|\n\n", sum_11, sum_21);

  x_1 = -0.f;
  y_1 = 3;
  sum_11 = pow(x_1, y_1);
  sum_21 = s21_pow(x_1, y_1);
  printf("TRY - |%.20Lf|\nMYY - |%.20Lf|\n\n", sum_11, sum_21);

  x_1 = -0;
  y_1 = 3;
  sum_11 = pow(x_1, y_1);
  sum_21 = s21_pow(x_1, y_1);
  printf("TRY - |%.20Lf|\nMYY - |%.20Lf|\n\n", sum_11, sum_21);

  printf("TEST_5\n");
  x_1 = +0.f;
  y_1 = 2;
  sum_11 = pow(x_1, y_1);
  sum_21 = s21_pow(x_1, y_1);
  printf("TRY - |%.20Lf|\nMYY - |%.20Lf|\n\n", sum_11, sum_21);

  x_1 = -0.f;
  y_1 = 2;
  sum_11 = pow(x_1, y_1);
  sum_21 = s21_pow(x_1, y_1);
  printf("TRY - |%.20Lf|\nMYY - |%.20Lf|\n\n", sum_11, sum_21);
  printf("TEST_6\n");
  x_1 = -1;
  y_1 = S21_INFINITY;
  sum_11 = pow(x_1, y_1);
  sum_21 = s21_pow(x_1, y_1);
  printf("TRY - |%.20Lf|\nMYY - |%.20Lf|\n\n", sum_11, sum_21);

  x_1 = -1;
  y_1 = -S21_INFINITY;
  sum_11 = pow(x_1, y_1);
  sum_21 = s21_pow(x_1, y_1);
  printf("TRY - |%.20Lf|\nMYY - |%.20Lf|\n\n", sum_11, sum_21);

  printf("TEST_7\n");
  x_1 = -0.12354684;
  y_1 = -S21_INFINITY;
  sum_11 = pow(x_1, y_1);
  sum_21 = s21_pow(x_1, y_1);
  printf("TRY - |%.20Lf|\nMYY - |%.20Lf|\n\n", sum_11, sum_21);

  x_1 = 0.8819418;
  y_1 = -S21_INFINITY;
  sum_11 = pow(x_1, y_1);
  sum_21 = s21_pow(x_1, y_1);
  printf("TRY - |%.20Lf|\nMYY - |%.20Lf|\n\n", sum_11, sum_21);
//       Если абсолютное значение x_1 больше 1, а y_1 равно отрицательной бесконечности, результат равен +0.
  printf("TEST_8\n");
  x_1 = 1.111516;
  y_1 = -S21_INFINITY;
  sum_11 = pow(x_1, y_1);
  sum_21 = s21_pow(x_1, y_1);
  printf("TRY - |%.20Lf|\nMYY - |%.20Lf|\n\n", sum_11, sum_21);

  x_1 = -13465.1651;
  y_1 = -S21_INFINITY;
  sum_11 = pow(x_1, y_1);
  sum_21 = s21_pow(x_1, y_1);
  printf("TRY - |%.20Lf|\nMYY - |%.20Lf|\n\n", sum_11, sum_21);
//       Если абсолютное значение x_1 меньше 1, а y_1 равно бесконечности, результат равен +0.
  printf("TEST_9\n");
  x_1 = -0.8946684;
  y_1 = S21_INFINITY;
  sum_11 = pow(x_1, y_1);
  sum_21 = s21_pow(x_1, y_1);
  printf("TRY - |%.20Lf|\nMYY - |%.20Lf|\n\n", sum_11, sum_21);


  x_1 = 0.1244564;
  y_1 = S21_INFINITY;
  sum_11 = pow(x_1, y_1);
  sum_21 = s21_pow(x_1, y_1);
  printf("TRY - |%.20Lf|\nMYY - |%.20Lf|\n\n", sum_11, sum_21);
//       Если абсолютное значение x_1 больше 1, а y_1 равно положительной бесконечности, результатом будет положительная бесконечность.
  printf("TEST_10\n");
  x_1 = 12524252.46654;
  y_1 = S21_INFINITY;
  sum_11 = pow(x_1, y_1);
  sum_21 = s21_pow(x_1, y_1);
  printf("TRY - |%.20Lf|\nMYY - |%.20Lf|\n\n", sum_11, sum_21);


  x_1 = -65765574.46654;
  y_1 = S21_INFINITY;
  sum_11 = pow(x_1, y_1);
  sum_21 = s21_pow(x_1, y_1);
  printf("TRY - |%.20Lf|\nMYY - |%.20Lf|\n\n", sum_11, sum_21);
//       Если x_1 — отрицательная бесконечность, а y_1 — нечетное целое число меньше 0, результат равен -0.
  printf("TEST_11\n");
  x_1 = -S21_INFINITY;
  y_1 = -5;
  sum_11 = pow(x_1, y_1);
  sum_21 = s21_pow(x_1, y_1);
  printf("TRY - |%.20Lf|\nMYY - |%.20Lf|\n\n", sum_11, sum_21);

  x_1 = -S21_INFINITY;
  y_1 = -5457234758465;
  sum_11 = pow(x_1, y_1);
  sum_21 = s21_pow(x_1, y_1);
  printf("TRY - |%.20Lf|\nMYY - |%.20Lf|\n\n", sum_11, sum_21);
//       Если x_1 равно отрицательной бесконечности, а y_1 меньше 0 и не является нечетным целым числом, результат равен +0.
  printf("TEST_12\n");
  x_1 = -S21_INFINITY;
  y_1 = -2;
  sum_11 = pow(x_1, y_1);
  sum_21 = s21_pow(x_1, y_1);
  printf("TRY - |%.20Lf|\nMYY - |%.20Lf|\n\n", sum_11, sum_21);

  x_1 = -S21_INFINITY;
  y_1 = -5457234758;
  sum_11 = pow(x_1, y_1);
  sum_21 = s21_pow(x_1, y_1);
  printf("TRY - |%.20Lf|\nMYY - |%.20Lf|\n\n", sum_11, sum_21);
//       Если x_1 — отрицательная бесконечность, а y_1 — нечетное целое число, большее 0, результатом будет отрицательная бесконечность.
  printf("TEST_13\n");
  x_1 = -S21_INFINITY;
  y_1 =  12345;
  sum_11 = pow(x_1, y_1);
  sum_21 = s21_pow(x_1, y_1);
  printf("TRY - |%.20Lf|\nMYY - |%.20Lf|\n\n", sum_11, sum_21);


  printf("TEST_13\n");
  x_1 = -S21_INFINITY;
  y_1 =  1;
  sum_11 = pow(x_1, y_1);
  sum_21 = s21_pow(x_1, y_1);
  printf("TRY - |%.20Lf|\nMYY - |%.20Lf|\n\n", sum_11, sum_21);
//       Если x_1 равно отрицательной бесконечности, а y_1 больше 0 и не является нечетным целым числом, результатом будет положительная бесконечность.
  printf("TEST_14\n");
  x_1 = -S21_INFINITY;
  y_1 =  123452;
  sum_11 = pow(x_1, y_1);
  sum_21 = s21_pow(x_1, y_1);
  printf("TRY - |%.20Lf|\nMYY - |%.20Lf|\n\n", sum_11, sum_21);

  x_1 = -S21_INFINITY;
  y_1 =  22;
  sum_11 = pow(x_1, y_1);
  sum_21 = s21_pow(x_1, y_1);
  printf("TRY - |%.20Lf|\nMYY - |%.20Lf|\n\n", sum_11, sum_21);
//       Если x_1 равно положительной бесконечности, а y_1 меньше 0, результат равен +0.
  printf("TEST_15\n");
  x_1 = S21_INFINITY;
  y_1 =  -1;
  sum_11 = pow(x_1, y_1);
  sum_21 = s21_pow(x_1, y_1);
  printf("TRY - |%.20Lf|\nMYY - |%.20Lf|\n\n", sum_11, sum_21);

  x_1 = S21_INFINITY;
  y_1 =  -0.1;
  sum_11 = pow(x_1, y_1);
  sum_21 = s21_pow(x_1, y_1);
  printf("TRY - |%.20Lf|\nMYY - |%.20Lf|\n\n", sum_11, sum_21);
//       Если x_1 равно положительной бесконечности, а y_1 больше 0, результатом будет положительная бесконечность.
  printf("TEST_15\n");
  x_1 = S21_INFINITY;
  y_1 =  1;
  sum_11 = pow(x_1, y_1);
  sum_21 = s21_pow(x_1, y_1);
  printf("TRY - |%.20Lf|\nMYY - |%.20Lf|\n\n", sum_11, sum_21);

  x_1 = S21_INFINITY;
  y_1 =  0.00004545;
  sum_11 = pow(x_1, y_1);
  sum_21 = s21_pow(x_1, y_1);
  printf("TRY - |%.20Lf|\nMYY - |%.20Lf|\n\n", sum_11, sum_21);
//       Если x_1 равно +0 или -0, а y_1 является нечетным целым числом меньше 0, возникает ошибка полюса и возвращается HUGE_VAL, HUGE_VALF или HUGE_VALL с тем же знаком, что и x_1.
  printf("TEST_16\n");
  x_1 = +0.f;
  y_1 =  -1;
  sum_11 = pow(x_1, y_1);
  sum_21 = s21_pow(x_1, y_1);
  printf("TRY - |%.20Lf|\nMYY - |%.20Lf|\n\n", sum_11, sum_21);

  x_1 = +0.f;
  y_1 =  -123543;
  sum_11 = pow(x_1, y_1);
  sum_21 = s21_pow(x_1, y_1);
  printf("TRY - |%.20Lf|\nMYY - |%.20Lf|\n\n", sum_11, sum_21);

  x_1 = -0.f;
  y_1 =  -1;
  sum_11 = pow(x_1, y_1);
  sum_21 = s21_pow(x_1, y_1);
  printf("TRY - |%.20Lf|\nMYY - |%.20Lf|\n\n", sum_11, sum_21);

  x_1 = -0.f;
  y_1 =  -123543;
  sum_11 = pow(x_1, y_1);
  sum_21 = s21_pow(x_1, y_1);
  printf("TRY - |%.20Lf|\nMYY - |%.20Lf|\n\n", sum_11, sum_21);
//       Если x_1 равно +0 или -0, а y_1 меньше 0 и не является нечетным целым числом, возникает ошибка полюса и возвращается +HUGE_VAL, +HUGE_VALF или +HUGE_VALL.
  printf("TEST_17\n");
  x_1 = +0.f;
  y_1 =  -2;
  sum_11 = pow(x_1, y_1);
  sum_21 = s21_pow(x_1, y_1);
  printf("TRY - |%.20Lf|\nMYY - |%.20Lf|\n\n", sum_11, sum_21);

  x_1 = -0.f;
  y_1 =  -2567654;
  sum_11 = pow(x_1, y_1);
  sum_21 = s21_pow(x_1, y_1);
  printf("TRY - |%.20Lf|\nMYY - |%.20Lf|\n\n", sum_11, sum_21);

  x_1 = -0.f;
  y_1 =  -2;
  sum_11 = pow(x_1, y_1);
  sum_21 = s21_pow(x_1, y_1);
  printf("TRY - |%.20Lf|\nMYY - |%.20Lf|\n\n", sum_11, sum_21);

  x_1 = +0.f;
  y_1 =  -2567654;
  sum_11 = pow(x_1, y_1);
  sum_21 = s21_pow(x_1, y_1);
  printf("TRY - |%.20Lf|\nMYY - |%.20Lf|\n\n", sum_11, sum_21);
//ОШИБКИ
//       См. math_error(7) для получения информации о том, как определить, произошла ли ошибка при вызове этих функций.
//
//       Могут возникнуть следующие ошибки:
//
//       Ошибка домена: x_1 отрицательное, а y_1 конечное нецелое число
//              errno имеет значение EDOM. Возникает недопустимое исключение с плавающей запятой (FE_INVALID).
//
//       Ошибка полюса: x_1 равно нулю, а y_1 отрицательно.
//              errno имеет значение ERANGE (но см. ОШИБКИ). Возникает исключение деления на ноль с плавающей запятой (FE_DIVBYZERO).
//
//       Ошибка диапазона: результат переполняется
//              errno имеет значение ERANGE. Возникает исключение переполнения с плавающей запятой (FE_OVERFLOW).
//
//       Ошибка диапазона: результат занижен
//              errno имеет значение ERANGE. Возникает исключение потери значимости с плавающей запятой (FE_UNDERFLOW).
  printf("TEST_18\n");
  x_1 = +0.f;
  y_1 =  -2.5546545;
  sum_11 = pow(x_1, y_1);
  sum_21 = s21_pow(x_1, y_1);
  printf("TRY - |%.20Lf|\nMYY - |%.20Lf|\n\n", sum_11, sum_21);

  x_1 = -0.f;
  y_1 =  -2.5546545;
  sum_11 = pow(x_1, y_1);
  sum_21 = s21_pow(x_1, y_1);
  printf("TRY - |%.20Lf|\nMYY - |%.20Lf|\n\n", sum_11, sum_21);

  x_1 = -23456;
  y_1 =  -2.5546545;
  sum_11 = pow(x_1, y_1);
  sum_21 = s21_pow(x_1, y_1);
  printf("TRY - |%.20Lf|\nMYY - |%.20Lf|\n\n", sum_11, sum_21);

  x_1 = -0.02020;
  y_1 =  -2;
  sum_11 = pow(x_1, y_1);
  sum_21 = s21_pow(x_1, y_1);
  printf("TRY - |%.20Lf|\nMYY - |%.20Lf|\n\n", sum_11, sum_21);

  long long int i_min = 0;
  long long int j_min = -9;
  long long int i_max = 8765.55645;
  long long int j_max = 0;
  check_fun(TST_POW, 0, i_min, j_min, i_max, j_max);

  x_1 = 123456;
  y_1 =  -0.2;
  sum_11 = pow(x_1, y_1);
  sum_21 = s21_pow(x_1, y_1);
  printf("TRY - |%.20Lf|\nMYY - |%.20Lf|\n\n", sum_11, sum_21);


  //не работает
  printf("TEST_POW_1\n");
  x_1 = 0.5;
  y_1 =  S21_INFINITY;
  sum_11 = pow(x_1, y_1);
  sum_21 = s21_pow(x_1, y_1);
  printf("TRY - |%.20Lf|\nMYY - |%.20Lf|\n\n", sum_11, sum_21);

  printf("TEST_POW_2\n");
  x_1 = S21_NEGATIVE_INFINITY;
  y_1 =  3;
  sum_11 = pow(x_1, y_1);
  sum_21 = s21_pow(x_1, y_1);
  printf("TRY - |%.20Lf|\nMYY - |%.20Lf|\n\n", sum_11, sum_21);

  printf("TEST_POW_3\n");
  x_1 = 3;
  y_1 = -0;
  sum_11 = pow(x_1, y_1);
  sum_21 = s21_pow(x_1, y_1);
  printf("TRY - |%.20Lf|\nMYY - |%.20Lf|\n\n", sum_11, sum_21);

  printf("TEST_POW_4\n");
  x_1 = S21_NAN;
  y_1 = 0;
  sum_11 = pow(x_1, y_1);
  sum_21 = s21_pow(x_1, y_1);
  printf("TRY - |%.20Lf|\nMYY - |%.20Lf|\n\n", sum_11, sum_21);

  printf("TEST_POW_5\n");
  x_1 = S21_NAN;
  y_1 = 3;
  sum_11 = pow(x_1, y_1);
  sum_21 = s21_pow(x_1, y_1);
  printf("TRY - |%.20Lf|\nMYY - |%.20Lf|\n\n", sum_11, sum_21);

  printf("TEST_POW_6\n");
  x_1 = S21_NAN;
  y_1 = -0;
  sum_11 = pow(x_1, y_1);
  sum_21 = s21_pow(x_1, y_1);
  printf("TRY - |%.20Lf|\nMYY - |%.20Lf|\n\n", sum_11, sum_21);

  printf("TEST_POW_7\n");
  x_1 = +0.f;
  y_1 = S21_INFINITY;
  sum_11 = pow(x_1, y_1);
  sum_21 = s21_pow(x_1, y_1);
  printf("TRY - |%.20Lf|\nMYY - |%.20Lf|\n\n", sum_11, sum_21);

  printf("TEST_POW_8\n");
  x_1 = S21_INFINITY;
  y_1 = +0;
  sum_11 = pow(x_1, y_1);
  sum_21 = s21_pow(x_1, y_1);
  printf("TRY - |%.20Lf|\nMYY - |%.20Lf|\n\n", sum_11, sum_21);

  printf("TEST_POW_9\n");
  x_1 = S21_INFINITY;
  y_1 = 0;
  sum_11 = pow(x_1, y_1);
  sum_21 = s21_pow(x_1, y_1);
  printf("TRY - |%.20Lf|\nMYY - |%.20Lf|\n\n", sum_11, sum_21);

  printf("TEST_LOG_1\n");
  x_1 = 0;
  sum_11 = log(x_1);
  sum_21 = s21_log(x_1);
  printf("TRY - |%.20Lf|\nMYY - |%.20Lf|\n\n", sum_11, sum_21);

  printf("TEST_EXP_1\n");
  x_1 = 1234;
  y_1 = 0;
  sum_11 = exp(x_1);
  sum_21 = s21_exp(x_1);
  printf("TRY - |%.20Lf|\nMYY - |%.20Lf|\n\n", sum_11, sum_21);
  return 0;
}