#include <stdio.h>
#include <stdlib.h>

#include "cc_pool.h"

CC_BLOCK *cc_block_create(size_t size) {
    if(!size) {
        size = BLOCK_SIZE;
    }
    CC_BLOCK *b = (CC_BLOCK *) malloc(sizeof(CC_BLOCK) + size);
    b -> next = (char *) &b[1];
    b -> end = b -> next + size;
    b -> block_size = size;
    b -> mem_left = size;
    return b;
}

size_t cc_block_available(CC_BLOCK *b) {
    return b -> end - b -> next;
}

CC_POOL *cc_pool_init(size_t size) {
    if(size == 0) {
	size = BLOCK_SIZE;
    }

    CC_POOL *p = malloc(sizeof(CC_POOL));
    p -> block = cc_block_create(size);
    p -> next = NULL;

    return p;
}

void *_cc_pool_alloc(CC_BLOCK *b, size_t size) {

    if(b -> mem_left < size) {
	return NULL;
    }

    void *mem = (void*) b -> next;
    b -> next += size;
    b -> mem_left = cc_block_available(b);
    return mem;
}

void *cc_pool_alloc(CC_POOL *pool, size_t size) {
    CC_POOL *current = pool;
    CC_POOL *tmp;

    while(current != NULL) {
	if(current -> block -> mem_left >= size) {
	    return _cc_pool_alloc(current -> block, size);
	}
	tmp = current;
	current = current -> next;
    }

    // block does not exist, create and add to pool list
    CC_BLOCK *new_block = cc_block_create(size + BLOCK_SIZE);
    tmp -> next = malloc(sizeof(CC_POOL));
    tmp -> next -> block = new_block;
    tmp -> next -> next = NULL;

    return _cc_pool_alloc(new_block, size);
}

void cc_pool_destroy(CC_POOL *pool) {
    while(pool != NULL) {
	CC_POOL *tmp = pool;
	pool = pool -> next;
	free(tmp -> block);
	free(tmp);
    }
}
