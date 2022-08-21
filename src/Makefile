GCC = gcc -D_GNU_SOURCE -std=c11 -Wall -Werror -Wextra

TST = test/
BI = build/
UNAME := $(shell uname)


GCOV = -fprofile-arcs -ftest-coverage
FLAGS = -lcheck

ifeq ($(UNAME),Darwin)
    FLAGS = -lcheck
endif

ifeq ($(UNAME),Linux)
    FLAGS = -lcheck -lcheck_pic -lpthread -lrt -lm -lsubunit
endif

OBJECTS = s21_log.o\
			s21_pow.o\
			s21_sqrt.o\
			s21_exp.o\
			s21_cos.o\
			s21_sin.o\
			s21_tan.o\
			s21_fmod.o\
			s21_abs.o\
			s21_fabs.o\
			s21_acos.o\
			s21_asin.o\
			s21_atan.o\
			s21_ceil.o\
			s21_floor.o

SOURSES = s21_log.c\
			s21_pow.c\
			s21_sqrt.c\
			s21_exp.c\
			s21_cos.c\
			s21_sin.c\
			s21_tan.c\
			s21_fmod.c\
			s21_abs.c\
			s21_fabs.c\
			s21_acos.c\
			s21_asin.c\
			s21_atan.c\
			s21_ceil.c\
			s21_floor.c

.PHONY: all clear.a clear.o clear_test clean test s21_math.a linters cppcheck leaks gcov_report

default: all

all: clean s21_math.a test gcov_report

clean: clear.a clear.o clear_test
	rm -rf report *.gcno *.gcda

clear.o:
	rm -rf *.o $(BI)*.o
clear.a:
	rm -rf *.a
clear_test:
	rm -rf test/tests.c build/tests

# STATICLIB_________________________________STATICLIB
s21_math.a:
	$(GCC) -c $(SOURSES)
	ar rcs s21_math.a $(OBJECTS)
	ranlib s21_math.a
	cp s21_math.a libs21_math.a
# STATICLIB_________________________________STATICLIB


# TEST_AND_REPORT_____________________TEST_AND_REPORT
debug_fun.o:
	$(GCC) -c -o $(BI)debug_fun.o debug_fun/debug_fun.c

my_test: s21_math.a debug_fun.o
	$(GCC) -c -o $(BI)test_fun.o $(TST)test_fun.c
	$(GCC) $(BI)test_fun.o $(BI)debug_fun.o libs21_math.a $(FLAGS) -o $(BI)test_fun
	$(BI)./test_fun

tests.c:
	checkmk $(TST)tests.check> $(TST)tests.c

test: tests.c s21_math.a debug_fun.o
	$(GCC) -c -o $(BI)tests.o $(TST)tests.c
	$(GCC) $(BI)tests.o $(BI)debug_fun.o libs21_math.a $(FLAGS) -o $(BI)tests
	$(BI)./tests

gcov_report: tests.c s21_math.a debug_fun.o
	@gcc -c -o $(BI)tests.o $(TST)tests.c
	@gcc $(GCOV)  $(BI)tests.o $(BI)debug_fun.o $(FLAGS) $(SOURSES) -o tests
	@./tests
	@lcov -t "tests" -o tests.info -c -d .
	@genhtml -o report tests.info
	@rm -rf ./*.gcno ./*.gcda ./tests.* tests
# TEST_AND_REPORT_____________________TEST_AND_REPORT

leaks: clean test
	CK_FORK=no leaks -atExit -- $(BI)./tests

linters:
	python3 ../materials/linters/cpplint.py --extensions=c *.c *.h debug_fun/*.c debug_fun/*.h

cppcheck:
	cppcheck --enable=all --check-config --suppress=missingIncludeSystem *.c *.h test/*.c debug_fun/*.c debug_fun/*.h
