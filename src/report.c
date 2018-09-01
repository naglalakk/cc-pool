#include <stdio.h>
#include <stdlib.h>
#include "Ctables.h"

#include "cc_pool.h"
#include "report.h"

char *int_to_s(int x) {
    const int buf = 20;
    char *str = malloc(sizeof(char *) * buf);
    sprintf(str, "%d", x);
    return str;
}

size_t get_pool_block_size(CC_POOL *pool) {
    size_t i = 0;
    while(pool != NULL) {
	i++;
	pool = pool -> next;
    }

    return i;
}

void generate_report(CC_POOL *pool) {
    size_t num_blocks = get_pool_block_size(pool);
    size_t row = 0;
    int ops[MAX_OPS] = {FREELY, NOCOLOR, CENTER, NONE};
    printf("num_blocks is: %zd\n", num_blocks);
    table_t *report_table = initialize_table(ops, num_blocks + 1, 4);
    add_freely(report_table, row, 0, "Block ID");
    add_freely(report_table, row, 1, "Memory used");
    add_freely(report_table, row, 2, "Memory free");
    add_freely(report_table, row, 3, "Total Memory");
    row++;

    while(pool != NULL) {
	if(pool -> block) {
	    add_freely(report_table, row, 0, int_to_s(row));
	    add_freely(
		report_table, 
		row, 
		1, 
		int_to_s(
		    (pool -> block -> block_size) - (pool -> block -> mem_left)
		)
	    );
	    add_freely(
		report_table,
		row,
		2,
		int_to_s(
		    pool -> block -> mem_left
		)
	    );
	    add_freely(
		report_table,
		row,
		3,
		int_to_s(
		    pool -> block -> block_size 
		)
	    );
	    row++;
	    pool = pool -> next;
	}
    }

    print(report_table);
    free_table(report_table);
}
