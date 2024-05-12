#ifndef FISHING_H
#define FISHING_H

#include "../../playerdata/player.h"

typedef struct {
    char name[50];
    int exp;
    int level;
} RawFish;  // Removed the redundant rawfish field in the struct

// Raw Fish Items
RawFish create_raw_shrimp();
RawFish create_raw_trout();
RawFish create_raw_lobster();
RawFish create_raw_shark();

// Fishing functions
RawFish fish_shrimp(int player_level);
RawFish fish_trout(int player_level);
RawFish fish_lobster(int player_level);
RawFish fish_shark(int player_level);

#endif // FISHING_H
