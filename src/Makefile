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

OBJECTS = my_log.o\
			my_pow.o\
			my_sqrt.o\
			my_exp.o\
			my_cos.o\
			my_sin.o\
			my_tan.o\
			my_fmod.o\
			my_abs.o\
			my_fabs.o\
			my_acos.o\
			my_asin.o\
			my_atan.o\
			my_ceil.o\
			my_floor.o

SOURSES = my_log.c\
			my_pow.c\
			my_sqrt.c\
			my_exp.c\
			my_cos.c\
			my_sin.c\
			my_tan.c\
			my_fmod.c\
			my_abs.c\
			my_fabs.c\
			my_acos.c\
			my_asin.c\
			my_atan.c\
			my_ceil.c\
			my_floor.c

.PHONY: all clear.a clear.o clear_test clean test my_math.a linters cppcheck leaks gcov_report

default: all

all: clean my_math.a test gcov_report

clean: clear.a clear.o clear_test
	rm -rf report *.gcno *.gcda

clear.o:
	rm -rf *.o $(BI)*.o
clear.a:
	rm -rf *.a
clear_test:
	rm -rf test/tests.c build/tests

# STATICLIB_________________________________STATICLIB
my_math.a:
	$(GCC) -c $(SOURSES)
	ar rcs my_math.a $(OBJECTS)
	ranlib my_math.a
	cp my_math.a libmy_math.a
# STATICLIB_________________________________STATICLIB


# TEST_AND_REPORT_____________________TEST_AND_REPORT
debug_fun.o:
	$(GCC) -c -o $(BI)debug_fun.o debug_fun/debug_fun.c

my_test: my_math.a debug_fun.o
	$(GCC) -c -o $(BI)test_fun.o $(TST)test_fun.c
	$(GCC) $(BI)test_fun.o $(BI)debug_fun.o libmy_math.a $(FLAGS) -o $(BI)test_fun
	$(BI)./test_fun

tests.c:
	checkmk $(TST)tests.check> $(TST)tests.c

test: tests.c my_math.a debug_fun.o
	$(GCC) -c -o $(BI)tests.o $(TST)tests.c
	$(GCC) $(BI)tests.o $(BI)debug_fun.o libmy_math.a $(FLAGS) -o $(BI)tests
	$(BI)./tests

gcov_report: tests.c my_math.a debug_fun.o
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
