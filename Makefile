CFLAGS = -g
COVERAGE_FLAGS = -fprofile-arcs -ftest-coverage
TESTS = tests/main.c tests/test_cc_pool.c
TEST_SRC = src/cc_pool.c
TEST_DEPS = tests/munit/munit.c

test:
	gcc -o $@ $(CFLAGS)  $(TESTS) $(TEST_SRC) $(TEST_DEPS) $(COVERAGE_FLAGS)

clean:
	rm -rf a.out test *.gcda *.gcno test.dSYM profile *.dSYM test_* *.o
