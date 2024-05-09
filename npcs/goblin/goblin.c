#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "goblin.h"

void goblin_drop(Goblin_Drop_Table *drop_table) {
    int min_gold = 5;
    int max_gold = 20;
    drop_table->gold = min_gold + rand() % (max_gold - min_gold + 1);
    printf("Goblin dropped %d gold!\n", drop_table->gold);
}
