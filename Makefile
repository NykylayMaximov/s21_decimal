CFLAGS = -Wall -Werror -Wextra
GCOV_FLAGS = -fprofile-arcs -ftest-coverage
CHECK_FLAGS = -lm -lcheck -lsubunit
ALL_FLAGS = $(CFLAGS) $(GCOV_FLAGS) $(CHECK_FLAGS)
C_FILES = $(wildcard *.c ./simple_function/*.c)
O_FILES = $(C_FILES:.c=.o)
C_TEST_FILES = $(wildcard ./tests/*.c)
C_TEST2_FILES = $(wildcard ./tests2/*.c)
C_TEST3_FILES = $(wildcard ./tests3/*.c)
C_TEST5_FILES = $(wildcard ./tests5/*.c)


all: s21_decimal.a test gcov_report

s21_decimal.a: $(O_FILES)
	ar rc s21_decimal.a $(O_FILES) 

test: clean
	gcc $(CFLAGS) $(C_TEST_FILES) $(C_FILES) -o test $(CHECK_FLAGS) -g
	./test

gcov_report:
	rm -rf *.gcno *.gcda report info_report html_report
	gcc -o report $(C_FILES) $(C_TEST_FILES) $(ALL_FLAGS) 
	./report
	geninfo *.gcda *.gcno -b . -o info_report 
	genhtml info_report -o html_report
	firefox html_report/index.html

clean:
	rm -rf $(O_FILES) *.a *.o test *.gcno *.gcda report info_report html_report

mytest: clean
	gcc $(CFLAGS) mytest/mytest.c $(C_FILES) -o test $(CHECK_FLAGS) -g
	./test

test2: clean
	gcc $(CFLAGS) $(C_TEST2_FILES) $(C_FILES) -o test $(CHECK_FLAGS) -g
	./test

test3: clean
	gcc $(CFLAGS) $(C_TEST3_FILES) $(C_FILES) -o test $(CHECK_FLAGS) -g
	./test

test5: clean
	gcc $(CFLAGS) $(C_TEST5_FILES) $(C_FILES) -o test $(CHECK_FLAGS) -g
	./test