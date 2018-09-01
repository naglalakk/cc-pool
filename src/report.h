#ifndef REPORT_H
#define REPORT_H

#include "cc_pool.h"

char *int_to_s(int x);
size_t get_pool_block_size(CC_POOL *pool);
void generate_report(CC_POOL *pool);

#endif 
