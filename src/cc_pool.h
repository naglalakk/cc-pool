#ifndef CC_POOL_H
#define CC_POOL_H

#define BLOCK_SIZE 12000

#include <stddef.h>

typedef struct {
    char *next;
    char *end;
    size_t block_size;
    size_t mem_left;
} CC_BLOCK;

typedef struct cc_pool {
    CC_BLOCK *block;
    struct cc_pool *next;
} CC_POOL;


CC_BLOCK *cc_block_create(size_t size);
size_t cc_block_available(CC_BLOCK *b);
CC_POOL *cc_pool_init(size_t size);
void *_cc_pool_alloc(CC_BLOCK *b, size_t size);
void *cc_pool_alloc(CC_POOL *pool, size_t size);
void cc_pool_destroy(CC_POOL *pool);

#endif
