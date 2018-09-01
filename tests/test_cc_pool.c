#include "munit/munit.h"
#include "../src/cc_pool.h"

static MunitResult test_cc_pool_create(const MunitParameter params[], void* fixture) {
    CC_POOL *pool = cc_pool_init(0);
    cc_pool_destroy(pool);
    return MUNIT_OK;
}


MunitTest cc_pool_tests[] = {
  {
    "/test_cc_pool_create", /* name */
    test_cc_pool_create, /* test */
    NULL, /* setup */
    NULL, /* tear_down */
    MUNIT_TEST_OPTION_NONE, /* options */
    NULL /* parameters */
  },
  /* Mark the end of the array with an entry where the test
   * function is NULL */
  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

