#include "src/cc_pool.h"
#include "src/report.h"
#include <stdio.h>
#include <stddef.h>


typedef struct {
    char *str;
}TYPE_1;

typedef struct {
    char *str;
}TYPE_2;

int main(int argc, char *argv[])
{
    CC_POOL *pool = cc_pool_init(0);
    printf("sizeof(TYPE_1) is: %zd\n", sizeof(TYPE_1));
    TYPE_1 *typeBuffer1 = cc_pool_alloc(pool, sizeof(TYPE_1) * 1000);
    typeBuffer1[999].str = "yellow";
    printf("typeBuffer1[999].str is: %s\n", typeBuffer1[999].str);
    printf("pool -> block -> mem_left is: %zd\n", pool -> block -> mem_left);

    TYPE_2 *typeBuffer2 = cc_pool_alloc(pool, sizeof(TYPE_2) * 1000);
    typeBuffer2[999].str = "yellow";
    printf("typeBuffer2[999].str is: %s\n", typeBuffer2[999].str);
    printf("typeBuffer1[999].str is: %s\n", typeBuffer1[999].str);

    generate_report(pool);

    cc_pool_destroy(pool);
    return 0;
}
