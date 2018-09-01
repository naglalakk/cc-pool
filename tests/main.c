#include "munit/munit.h"

#include "test_cc_pool.h"

static MunitSuite test_suites[] = {
    { "/cc_pool", cc_pool_tests, NULL, 1, 0 }
};

static const MunitSuite main_suite = {
  "cc-process-coverage tests", /* name */
  NULL, /* tests */
  test_suites,
  1, /* iterations */
  MUNIT_SUITE_OPTION_NONE /* options */
};

int main (int argc, const char* argv[]) {
  return munit_suite_main(&main_suite, NULL, argc, *argv);
}

