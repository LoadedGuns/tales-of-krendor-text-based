#ifndef GOBLIN_H
#define GOBLIN_H

#include "../../playerdata/player.h"

typedef struct {
    int health;
    int power;
    int armor;
} Goblin;

typedef struct {
    int gold;
} Goblin_Drop_Table;

extern Goblin goblin;

void goblin_drop(Goblin_Drop_Table *drop_table);

#endif // GOBLIN_H
