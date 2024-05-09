#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "orc.h"

void orc_drop(Orc_Drop_Table *drop_table) {
    int min_gold = 10;
    int max_gold = 50;
    drop_table->gold = min_gold + rand() % (max_gold - min_gold + 1);
    printf("Orc dropped %d gold!\n", drop_table->gold);
}
