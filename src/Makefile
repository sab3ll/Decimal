CORE=$(shell uname -s | tr '[:upper:]' '[:lower:]')

CLANG_MODE=-i

CC=gcc
CFFLAGS=-Wall -Wextra -Werror -std=c11
DEBUG=-g

OPEN_CMD=open

ifdef CORE
	ifeq ($(CORE), linux)
		CHECKFLAGS=-pthread -lcheck_pic -lrt -lm -lsubunit
		OPEN_CMD=xdg-open
	endif

	ifeq ($(CORE), darwin)
		CHECKFLAGS=$(shell pkg-config --cflags --libs check)
		OPEN_CMD=open
	endif
endif

GLFLAGS=--coverage
GCOVFLAGS=-fprofile-arcs -ftest-coverage

SOURCE_FILES=*/*.c *.c *.h
CLANG_PATH=../materials/linters/

CLANG_COPY=cp $(CLANG_PATH).clang-format .clang-format
CLANG_REMOVE=rm .clang-format

s21_decimal.a: s21_decimal.o
	ar r s21_decimal.a *.o

s21_decimal.o:
	$(CC) $(CFFLAGS) ./lib/*.c -c

s21_decimal.a_debug:
	$(CC) $(CFFLAGS) $(DEBUG) ./lib/*.c -c
	ar r s21_decimal.a *.o

all: clean s21_decimal.a test

clean: clean_all

clean_common:
	rm -rf *.o
	rm -rf *.gch
	rm -rf *.a
	rm -rf *.gcda
	rm -rf *.gcno

clean_tests:
	rm -rf tests/output
	rm -rf tests/report
	rm -rf tests.info

clean_dev:
	rm -rf sandbox
	rm -rf valgrind
	rm -rf valgrind-out.txt

clean_all: clean_common clean_tests clean_dev

test: build_tests run_tests clean_tests

build_tests: clean_all s21_decimal.a
	mkdir tests/output

	# Main functions
	$(CC) $(GLFLAGS) $(GCOVFLAGS) lib/s21_add.c tests/s21_add_test.c -L. s21_decimal.a $(CHECKFLAGS) -o ./tests/output/s21_add_test
	$(CC) $(GLFLAGS) $(GCOVFLAGS) lib/s21_sub.c tests/s21_sub_test.c -L. s21_decimal.a $(CHECKFLAGS) -o ./tests/output/s21_sub_test
	$(CC) $(GLFLAGS) $(GCOVFLAGS) lib/s21_mul.c tests/s21_mul_test.c -L. s21_decimal.a $(CHECKFLAGS) -o ./tests/output/s21_mul_test
	$(CC) $(GLFLAGS) $(GCOVFLAGS) lib/s21_div.c tests/s21_div_test.c -L. s21_decimal.a $(CHECKFLAGS) -o ./tests/output/s21_div_test
	$(CC) $(GLFLAGS) $(GCOVFLAGS) lib/s21_is_less.c tests/s21_is_less_test.c -L. s21_decimal.a $(CHECKFLAGS) -o ./tests/output/s21_is_less_test
	$(CC) $(GLFLAGS) $(GCOVFLAGS) lib/s21_is_less_or_equal.c tests/s21_is_less_or_equal_test.c -L. s21_decimal.a $(CHECKFLAGS) -o ./tests/output/s21_is_less_or_equal_test
	$(CC) $(GLFLAGS) $(GCOVFLAGS) lib/s21_is_greater.c tests/s21_is_greater_test.c -L. s21_decimal.a $(CHECKFLAGS) -o ./tests/output/s21_is_greater_test
	$(CC) $(GLFLAGS) $(GCOVFLAGS) lib/s21_is_greater_or_equal.c tests/s21_is_greater_or_equal_test.c -L. s21_decimal.a $(CHECKFLAGS) -o ./tests/output/s21_is_greater_or_equal_test
	$(CC) $(GLFLAGS) $(GCOVFLAGS) lib/s21_is_equal.c tests/s21_is_equal_test.c -L. s21_decimal.a $(CHECKFLAGS) -o ./tests/output/s21_is_equal_test
	$(CC) $(GLFLAGS) $(GCOVFLAGS) lib/s21_is_not_equal.c tests/s21_is_not_equal_test.c -L. s21_decimal.a $(CHECKFLAGS) -o ./tests/output/s21_is_not_equal_test
	$(CC) $(GLFLAGS) $(GCOVFLAGS) lib/s21_from_int_to_decimal.c tests/s21_from_int_to_decimal_test.c -L. s21_decimal.a $(CHECKFLAGS) -o ./tests/output/s21_from_int_to_decimal_test
	$(CC) $(GLFLAGS) $(GCOVFLAGS) lib/s21_from_float_to_decimal.c tests/s21_from_float_to_decimal_test.c -L. s21_decimal.a $(CHECKFLAGS) -o ./tests/output/s21_from_float_to_decimal_test
	$(CC) $(GLFLAGS) $(GCOVFLAGS) lib/s21_from_decimal_to_int.c tests/s21_from_decimal_to_int_test.c -L. s21_decimal.a $(CHECKFLAGS) -o ./tests/output/s21_from_decimal_to_int_test
	$(CC) $(GLFLAGS) $(GCOVFLAGS) lib/s21_from_decimal_to_float.c  tests/s21_from_decimal_to_float_test.c -L. s21_decimal.a $(CHECKFLAGS) -o ./tests/output/s21_from_decimal_to_float_test
	$(CC) $(GLFLAGS) $(GCOVFLAGS) lib/s21_floor.c tests/s21_floor_test.c -L. s21_decimal.a $(CHECKFLAGS) -o ./tests/output/s21_floor_test
	$(CC) $(GLFLAGS) $(GCOVFLAGS) lib/s21_round.c tests/s21_round_test.c -L. s21_decimal.a $(CHECKFLAGS) -o ./tests/output/s21_round_test
	$(CC) $(GLFLAGS) $(GCOVFLAGS) lib/s21_truncate.c  tests/s21_truncate_test.c -L. s21_decimal.a $(CHECKFLAGS) -o ./tests/output/s21_truncate_test
	$(CC) $(GLFLAGS) $(GCOVFLAGS) lib/s21_negate.c tests/s21_negate_test.c -L. s21_decimal.a $(CHECKFLAGS) -o ./tests/output/s21_negate_test

run_tests:
	# Main functions
	tests/output/s21_add_test
	tests/output/s21_sub_test
	tests/output/s21_mul_test
	tests/output/s21_div_test
	tests/output/s21_is_less_test
	tests/output/s21_is_less_or_equal_test
	tests/output/s21_is_greater_test
	tests/output/s21_is_greater_or_equal_test
	tests/output/s21_is_equal_test
	tests/output/s21_is_not_equal_test
	tests/output/s21_from_int_to_decimal_test
	tests/output/s21_from_float_to_decimal_test
	tests/output/s21_from_decimal_to_int_test
	tests/output/s21_from_decimal_to_float_test
	tests/output/s21_floor_test
	tests/output/s21_round_test
	tests/output/s21_truncate_test
	tests/output/s21_negate_test

gcov_report: clean_all test run_tests
	lcov -o tests.info -c -d .
	genhtml -o tests/report tests.info
	$(OPEN_CMD) tests/report/index.html

rebuild: clean all

clang:
	$(CLANG_COPY) && clang-format $(CLANG_MODE) $(SOURCE_FILES) && $(CLANG_REMOVE)

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem --force *.h *.c ./lib/*.c ./tests/*.c

sandbox.o:
	$(CC) $(CFFLAGS) $(DEBUG) ./sandbox.c -c

sandbox: clean
	clear
	make sandbox.o
	make s21_decimal.a_debug
	$(CC) $(CFFLAGS) $(DEBUG) -o sandbox sandbox.o -L. s21_decimal.a -lm

prod:
	mv sandbox.c sandbox.txt
	mv valgrind.c valgrind.txt

dev:
	mv sandbox.txt sandbox.c
	mv valgrind.txt valgrind.c

valgrind.o:
	$(CC) $(CFFLAGS) $(DEBUG) ./valgrind.c -c

valgrind_tests: clean_dev
	clear
	make valgrind.o
	make s21_decimal.a_debug
	$(CC) $(CFFLAGS) $(DEBUG) -o valgrind valgrind.o -L. s21_decimal.a -lm

valgrind: valgrind_tests
	valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --track-origins=yes ./valgrind

valgrind_deep: valgrind_tests
	valgrind --leak-check=full --tool=memcheck --leak-check=full --show-reachable=yes --leak-resolution=high --track-origins=yes --show-leak-kinds=all --verbose ./valgrind

valgrind_log: valgrind_tests
	valgrind --leak-check=full --tool=memcheck --leak-check=full --show-reachable=yes --leak-resolution=high --track-origins=yes --show-leak-kinds=all --verbose --log-file=valgrind-out.txt ./valgrind

leaks: clean_dev valgrind_tests
	leaks -atExit -- ./valgrind | grep LEAK:

verter:
	cd ../materials/build && bash run.sh
	cd ../../

s: sandbox
	./sandbox

t: clean_all
	clear
	make build_tests
	make run_tests
	make clean_all

g: gcov_report

v: valgrind

vd: valgrind_deep

vl: valgrind_log

c: clean_all
	make clang
	clear
