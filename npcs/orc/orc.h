#ifndef ORC_H
#define ORC_H

#include "../../playerdata/player.h"

typedef struct {
    int health;
    int power;
    int armor;
} Orc;

typedef struct {
    int gold;
} Orc_Drop_Table;

extern Orc orc;

void orc_drop(Orc_Drop_Table *drop_table);

#endif // ORC_H
